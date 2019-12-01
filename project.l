%{
	#include <string.h>
	#include <stdlib.h>
	#include <stdio.h> 
	#include "y.tab.h"
%}

%%
	/* Types */
"bool"|"char"|"int"|"real"|"string"|"int"[\*]|"char"[\*]|"real"[\*]	{yylval.string = strdup(yytext); return VALTYPE;}
	
	/* Condition */
"if"	{return IF;}
"else"	{return ELSE;}
"while"	{return WHILE;}
"do"    {return DO;}

	/* Loops */
"for"	{return FOR;}

	/* Assignment */
"var"	{return VAR;}

	/*Function and procedures */
"function"	{return FUNCTION;}
"return"	{return RETURN;}
"null"	{return NULLP;}
"void"	{return VOID;}

	/* Arithmetic Operators */
\+ {return PLUS;}
\- {return MINUS}
\/ {return DIV}
\* {return MUL}
"=" {return ASS}
	/* Relational Operators */
"&&"|"=="|">"|">="|"<"|"<="|"!"|"!="|"||"||"&"	{yylval.string = strdup(yytext); return OP;}
	
	/* Values */
"true"	{yylval.intVal=1; return BOOLVAL;}
"false"	{yylval.intVal=0; return BOOLVAL;}
'.'	{yylval.charVal =yytext[1]; return CHARVAL;}
0|[1-9][0-9]*	{ yylval.string = strdup(yytext); return DECIMALINTVAL; };
0[xX][A-F0-9]+	{ yylval.string = strdup(yytext); return HEXINTVAL; };
[0-9]*[\.]?[0-9]+|[0-9]*[\.]?[0-9]+[eE][-+]?[0-9]+	{ yylval.string = strdup(yytext); return REALVAL; };
\"[^\"]*\"	{ yylval.string = strdup(yytext); return STRING_VAL; };
[a-zA-z][a-zA-z0-9_]*	{yylval.string=strdup(yytext); return ID;}
	
	/* Comments */
/\*[.]+\*/ ;

	/* Anything that doesnt match */
"."	{return yytext[0];}
%%
