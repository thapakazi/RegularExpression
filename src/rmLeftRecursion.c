/*************Authors:
milans.thapa78@gmail.com--<Milan Thapa>
shalil9130@gmail.com--<Shalil Awaley>
*/

#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define SIZE 20
#define CHUNK_SZ 10

//count '|' symbols
int count=0;

//chunking the input into jagged array
char **chunking(char *inputStr){
  int i,j;

 
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
    while(*ptr!='|'&&*ptr!='\0')
      {
	str[i][j]=*ptr;
	
	//	printf("j:%d %c\n",j,*ptr);
	ptr++;
	j++;
      }
    str[i][j]='\0';
    ptr++;
    //    printf("i:%d %c\n",i,*ptr);
  }
  //print the chunks in the array created
  printf("\n***So after chunking the input, we get\n");
  for(i=0;i<count+1;i++)
    {
      for(j=0;j<CHUNK_SZ;j++)
	printf("\t%c",str[i][j]);
      printf("\n");
    }
  return str;
}

//check left recursion and adjust the string as required.
int checkLeftRecursion(char *inputStr){

  int i,j;
  char *ptr=inputStr+3;
  //extract the first character of input Eg. S=>Sab|b , extract S to check it with other chunks
  char non_terminal=*inputStr;
  //chunk out all the strings first seperated by '|' symbol
  char ** chunkedStr=chunking(inputStr+3);
  
  char** t=malloc(count*sizeof(char*));
  char** nt=malloc(count*sizeof(char*));
  
  int id_t=0,id_nt=0; // index for t and nt
  for(i=0,j=0;i<count+1;i++){
    ptr=&chunkedStr[i][0];

    
    if(non_terminal== *ptr)
      {
	//	printf("found the left recursion at i = %c\n",*ptr);
	nt[id_nt]=malloc(CHUNK_SZ*sizeof(char));
	//printf("found the left recursion at i = %d\n",i);
	int j = 0;
	ptr +=1;
	while(*ptr!='\0'){
	  nt[id_nt][j]=*ptr;
	  j++;
	  ptr++;
	}
	//t[id_t][j]=non_terminal;
	//	t[id_t][j+1]='\'';
	nt[id_nt][j+1]='\0';
	id_nt++;
      
	//extractSubStr(chunkedStr,&nt,0);
      }
    
    else{
      //printf("found beta terms for i = %d",i);
      t[id_t]=malloc(CHUNK_SZ*sizeof (char));
      int j = 0;
      while(*ptr!='\0'){
	t[id_t][j]=*ptr;
	j++;
	ptr++;
      }
      id_t++;
      
    }
  }
  //print the terms
  printf("\nThe required expression is:\n");
  //print the beta terms
  printf("%c=> ",non_terminal);
  for(i=0;i<id_t;i++){
    printf("%s%c'",t[i],non_terminal);
    if ( i+1 != id_t) printf("|");
    
  }

  //print the alpha terms
  printf("\n%c'=> ",non_terminal);
  for(i=0;i<id_nt;i++){
    printf("%s%c'",nt[i],non_terminal);
    printf("|"); 
  }
  printf("E");
  
}

//main function
void main () {
	
  char **str;
  char non_terminal;
  char beta,alpha;                        
  char production[SIZE];
	
  printf("Enter the grammer:<length limit 20>\n");
  printf("The grammer must be formated as: S=>Sabc|x0z|Sega|hello|world\n");
  scanf("%s",production);
  non_terminal=production[0];
  str=checkLeftRecursion(production);  
    
}
