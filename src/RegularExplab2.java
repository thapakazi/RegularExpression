import java.awt.SystemColor;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.NoSuchElementException;
import java.util.Scanner;



public class RegularExplab2
{
    private String[] keywords={"for", "while", "do", "int", "float", "char", "double", "static", "switch", "case", "import", "public", "private", "class", "protected", "return", "true", "false", "if", "try", "catch", "finally", "else" , "continue", "break"};
    Scanner input;
    private ArrayList<String> keywords_found;
    private ArrayList<Integer> digits_found;
    private ArrayList<String> identifiers_found;
    private ArrayList<Character> symbols_found;
    public RegularExplab2()
    {
    	keywords_found = new ArrayList<String>();
    	digits_found = new ArrayList<Integer>();
    	identifiers_found = new ArrayList<String>();
    	symbols_found = new ArrayList<Character>();
    }
    
    public Boolean isKeyword(String token)
    {
    	for ( String keyword : keywords)
    	{
    		if ( token.equals(keyword) ) 
			{
    			return true;
			}
    	}
    	return false;
    }
    
    public void start()
    {
    	
    	// opening file the user entered as the argument 
    	try{
    		input = new Scanner( new File( "./src/RegularExplab2.java" )); 
    	} catch (FileNotFoundException fileNotFoundException) {
    		System.err.println("Error opening file");
    		System.exit(0);
    	}
    	
    	String sentence;
		try{
			while ( input.hasNext() )
			{
				sentence = input.nextLine();
				String[] tokens = sentence.split(" ");
				
				for ( String token : tokens)
				{
					if ( isKeyword(token) )
					{
						keywords_found.add(token);
					}
					else
					{
						int i = 0;
						int digit = 0; 
						while ( i < token.length() && java.lang.Character.isDigit(token.charAt(i) ) )
						{
							digit += digit*10+ token.charAt(i);
							i++;
						}
						if ( i != 0 ) 
						{
							digits_found.add(digit);
						}
						else if (i ==token.length() )
						{
							continue;
						}
						for ( ; i < token.length(); i ++)
						{
							int start = i;
							while ( i < token.length() && java.lang.Character.isLetter(token.charAt(i) ))
							{
								i++;
							}
							//System.out.println("i = "+ i);
							if ( start < i && i <= token.length())
							{
								//int end =  i < token.length()? i: token.length();
								if  (start > 1 && java.lang.Character.isAlphabetic(token.charAt(start-1))) start--;
								String subtoken = token.substring(start, i);
								if ( isKeyword(subtoken))
									keywords_found.add(subtoken);
								else
									identifiers_found.add(subtoken);
							}
							if ( i < token.length() ) symbols_found.add(token.charAt(i));
							i++;
						}
					}
				}
			}
		} catch ( NoSuchElementException elementException) {
			System.err.println("File improperly formed.");
			input.close();
			System.exit(1);
		} catch (IllegalStateException stateException) {
			System.err.println("Error reading from file.");
			System.exit(1);
		}
		
		//output
		System.out.println("-------------------");
		System.out.println("keywords found");
		for ( String keyword : keywords_found)
		{
			System.out.print(keyword + " ");
		}
		System.out.println("");
		System.out.println("-------------------");
		System.out.println("identifiers found ");
		for ( String identifier : identifiers_found )
		{
			System.out.print(identifier +" ");
		}
		System.out.println("");
		System.out.println("-------------------");
		System.out.println("digits found");
		for ( int digit : digits_found)
		{
			System.out.print(digit + " ");
		}
		System.out.println("");
		System.out.println("-------------------");
		System.out.println("symbols found");
		for ( char symbol:symbols_found)
		{
			System.out.print(symbol + " ");
		}
		System.out.println("");
		System.out.println("-------------------");
    }
    
    public static void main(String[] args)
    {
    	//System.out.println();
    	new RegularExplab2().start();
    }
}