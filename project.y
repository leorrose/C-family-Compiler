%{
#include <stdio.h>
#include <stdlib.h>
#include "lex.yy.c"
void yyerror();
int yywrap();
%}

%token VALTYPE IF ELSE WHILE FOR VAR FUNCTION RETURN NULLP VOID DO  
%token OP
%token BOOLVAL CHARVAL INTVAL REALVAL STRINGVAL ID
%union
{
	char *string;
	int intVal;
	char charVal;
}

%%
program:
	cmd 
	|program cmd
	;
cmd:	declaration
	;
declaration: VAR VALTYPE ID {printf("declaration");}
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
