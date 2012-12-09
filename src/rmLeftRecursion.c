/*************Authors:
milans.thapa78@gmail.com--<Milan Thapa>
shalilawal@gmail.com--<Shalil Awaley>
 */

#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define SIZE 20
#define CHUNK_SZ 10

char **chunking(char *inputStr){
  int i,j;

  //count | symbols
  int count=0;
  char * ptr=inputStr;
  while(*ptr!='\0'){
    if(*ptr=='|')
      count++;
    ptr++;
  }

  //  printf("Number of pipes '|' counted :%d\n",count);

  //create string array--jagged--2D
  char ** str= malloc(count*sizeof(char*));
  ptr= inputStr;
  
  for(i=0;i<count+1;i++){
    str[i]=malloc(CHUNK_SZ*sizeof(char));
    j=0;
    //for(j=0;j<CHUNK_SZ;j++){
    while(*ptr!='|'&&*ptr!='\0')
      {
	str[i][j]=*ptr;
	//	printf("j:%d %c\n",j,*ptr);
	ptr++;
	j++;
	
      }
    ptr++;
    //    printf("i:%d %c\n",i,*ptr);
    
  }
  
 
  //print the chunks in the array created
  printf("\n***So after chunking the input, we get\n");
  for(i=0;i<count+1;i++)
    {
      for(j=0;j<CHUNK_SZ;j++)
	printf("%c\t",str[i][j]);
      printf("\n");
    }
  return str;
}

//check left recursion
int checkLeftRecursion(char *inputStr){

  //chunk out all the strings first seperated by '|' symbol
  char ** chunkedStr=chunking(inputStr);
  
}


//main function
void main () {
	
  char **str;
  char non_terminal;
  char beta,alpha;                        
  char production[SIZE];
  
  int index=3; /* starting of the string following "->" */

	
  printf("Enter the grammer:<length limit 20>\n");
  printf("The grammer must be formated as: abc|xY0z|RAm|haude\n");
  scanf("%s",production);
  non_terminal=production[0];
  
  str=chunking(production);
  
	/*
	    if(non_terminal==production[index]) {
		alpha=production[index+1];
		printf("Grammar is left recursive.\n");
	
		while(production[index]!=0 && production[index]!='|')
		index++;
	
		if(production[index]!=0) {
			beta=production[index+1];
			printf("Grammar without left recursion:\n");
			printf("%c->%c%c\'",non_terminal,beta,non_terminal);
			printf("\n%c\'->%c%c\'|E\n",non_terminal,alpha,non_terminal);
		}
		else 
			printf("Grammar can't be reduced\n");
	    }
	    else {
		printf("Grammar is not left recursive.\n");
	    }
	*/
	  
	}
