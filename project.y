%{
#include <stdio.h>
#include <stdlib.h>
#include "lex.yy.c"
void yyerror();
int yywrap();
%}

%token BOOL CHAR INT REAL STRING INTP CHARP REALP IF ELSE WHILE FOR VAR FUNCTION RETURN NULLP VOID DO  
%token AND DIV ASGN EQ GREATER GE LOWER LE MINUS NOT NE OR PLUS MUL


%%
program:
	program | 
	;
%%

void main(){
        yyparse();
}
void yyerror(){
        printf("error");
}
int yywrap(){
	return 0;
}
