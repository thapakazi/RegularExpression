import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class RegularExplab1 {

	public static void main(String argc[]) {
		String exp1 = "(0|1)*|0*1*";
		CharSequence testStr = "010101010101010101010";

		// Pattern matching
		Pattern pattern = Pattern.compile(exp1);
		Matcher matcher = pattern.matcher(testStr);

		System.out.println("Defined Regular expression:  " + exp1);
		if (matcher.matches()) {
			System.out.println("The string " + testStr
					+ " matches with the expression!!!\n");
		} else {
			System.out
					.println("The string "
							+ testStr
							+ "  does not matches with the regular expression defined.\n");
		}
		/************************************************************************************/

		// Pattern matching for second expression

		String exp2 = "(a*b*|(def)+|a*d+e)+";
		CharSequence testStr2 = "aaabbdefdefaaaaadde";
		pattern = Pattern.compile(exp2);
		matcher = pattern.matcher(testStr2);

		System.out.println("Defined Regular expression:  " + exp2);
		if (matcher.matches()) {
			System.out.println("The string " + testStr2
					+ " matches with the expression!!!\n");
		} else {
			System.out
					.println("The string "
							+ testStr2
							+ "  does not matches with the regular expression defined.\n");
		}
		/************************************************************************************/
		// Pattern matching for 3rd exp
		String exp3 = "((a|b)*(c|d)*)+|ab*c*d";
		CharSequence testStr3 = "abaaaaaabacccccccccccdacd";

		pattern = Pattern.compile(exp3);
		matcher = pattern.matcher(testStr3);

		System.out.println("Defined Regular expression:  " + exp3);
		if (matcher.matches()) {
			System.out.println("The string " + testStr3
					+ " matches with the expression!!!");
		} else {
			System.out
					.println("The string "
							+ testStr3
							+ "  does not matches with the regular expression defined.");
		}

	}
}