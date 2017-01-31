#include <stdio.h>
#include"CS411P1Header.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

#define maxTransition 200

char *names[] = {NULL,"boolean","break","class","double","else","extends","false","for","if","implements",
                "int","interface","newarray","println","readln","return","string","void","while","plus", 
                "minus","multiplication","division","mod","less","lessequal","greater","greaterequal","equal",
                "notequal","and","or","not","assignop","semicolon","comma","period","leftparen","rightparen",
                "leftbracket","rightbracket","leftbrace","rightbrace","intconstant","doubleconstant","stringconstant",
                "booleanconstant","id"};


struct{
  int switchArr[52];
  char symbolArr[maxTransition];
  int nextArr[maxTransition];
} symbolTable;



void createSymbolTable(void){

  int i;
  for (i = 0 ; i < 52; i++){
    symbolTable.switchArr[i] = -1;
  }

  for (i = 0; i < maxTransition; i++){
    symbolTable.symbolArr[i] = '\0';
    symbolTable.nextArr[i] = -1;
  }
}

void printSymbolTable(void){
   int i;
   int j;
   int ptr = 0;
   int alphaA = 65;
   int limit = 20;

   //Print the Switch Table
   for (i = 0; i < 3; i++){
      printf("\t");

      if(i == 2){
        limit = 12;
      }
      for (j = 0; j < limit; j++, alphaA++){
        printf("%c\t", alphaA);
        if (alphaA == 90){
          alphaA = 96;
       }
      }
      printf("\n%s", "switch:");
      for (j = 0; j < limit; j++, ptr++){
        printf("\t%d", symbolTable.switchArr[ptr]);
      }
      printf("\n");
   }

   //Need to code the print table for Symbol/Next

}


//Need to create insert for Trie Table
void insertInSymbolTable(string identifier){
	
	char currentChar;
	int len = strlen(indetifier);
	int index;
	currentChar = identifier[0];
	index = currentChar - 65; 
	if (symbolTable.switchArr[index] == -1){ //Starting letter does not appear in symbol table.
    	symbolTable.switchArr[index] = maxTransition;
		for (int i=0; i<len; i++){
			currentChar = identifier[i];
			symbolTable.symbolArr[++maxTransition] = currentChar;
		}
		symbolTable.symbolArr[++maxTransition] = \0; //new end of table.
			
	}
	else if (symbolTable.switchArr[index] != -1){
		for (int i=0;i<len;i++){
		   int next = symbolTable.switchArr[index];
		   char nextLetter = symbolTable.switchArr[next];
		   if (nextLetter == indetifier[i]){
			   if (symbolTable.symbolArr[++next] != -1){
				   
			   }
		   }
		   else{
		}
		
		
	}
}

boolean searchSymbolTable(string input){
	boolean found = false;
	char currentChar = input[0];
	int index = currentChar - 65;
	int length = strlen(input);
	if (symbolTable.switchArr[index] == -1){
		found = false;
	}
	else{ //Found first letter. try to find remaining letters.
		for (int i=1;i<length;i++;){
			currentChar = input[i];
			char nextSymbol = symbolTable.symbolArr[index];
			if (nextSymbol == currentChar){
				index = index++;
			}
			else if (nextSymbol == '*'){
				index = symbolTable.nextArr[index];
			}
			else{
				found = false;
			}
		}
		if (symbolTable.symbolArr[index] == '*'){
			found = true;
		}
	}
	return found;
}


int main(void){

   createSymbolTable();

   printf("%s\n", "Translated text:");
   int ntoken, vtoken;
   ntoken = yylex();
   while(ntoken){
      printf("%s ", names[ntoken]);
      ntoken = yylex();
   }


   printf("\n\n%s\n", "Trie Table:");
   printSymbolTable();
   return 0;
}