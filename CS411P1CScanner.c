#include <stdio,>
#include <"CS411P1Header.h">

extern int yylex();
extern int yylineno;
extern char* yytext;

char *names[] = {NULL, "_boolean", "_break", "_class", "_double", "_else", "_extends", "_false", "_for", "_if", "_implements",
                 "_int", "_interface", "_newarray", "_println", "_readln", "_return", "_string", "_void", "_while", "_plus", 
                 "_minus", "_multiplication", "_division", "_mod", "_less", "_lessequal", "_greater", "_greaterequal", "_equal",
                 "_notequal", "_and", "_or", "_not", "_assignop", "_simicolon", "_comma", "_period", "_leftparen", "_rightparen",
                 "_leftbracket", "_rightbracket", "_leftbrace", "_rightbrace", "_intconstant", "_doubleconstatnt", "_stringconstant",
                 "_booleanconstant", "_id"};

int main(void)
{

   int ntoken, vtoken;
   ntoken = yylex();
   while(ntoken){
      printf("%d\n", ntoken);
      ntoken = yylex();
   }
   return 0;
}