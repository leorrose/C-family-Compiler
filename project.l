%{
	#include <string.h>
	#include <stdlib.h>
	#include <stdio.h> 
	#include "y.tab.h"
%}
%%
"bool"	{return BOOL;}
"char"	{return CHAR;}
"int"	{return INT;}
"real"	{return REAL;}
"string"	{return STRING;}
"int*"	{return INTP;}
"char*"	{return CHARP;}
"real*"	{return REALP;}
"if"	{return IF;}
"else"	{return ELSE;}
"while"	{return WHILE;}
"for"	{return FOR;}
"var"	{return VAR;}
"function"	{return FUNCTION;}
"return"	{return RETURN;}
"null"	{return NULLP;}
"void"	{return VOID;}
"do"	{return DO;}
"&&"	{return AND;}
"/"	{return DIV;}
"="	{return	ASGN;}
"=="	{return EQ;}
">"	{return GREATER;}
">="	{return GE;}
"<"	{return LOWER;}
"<="	{return LE;}
"-"	{return MINUS;}
"!"	{return NOT;}
"!="	{return NE;}
"||"	{return OR;}
"+"	{return PLUS;}
"*"	{return MUL;}
"true"	{yylval=true; return BOOLVAL}
"false"	{yylval=false; return BOOLVAL}
'.' {yylval =yytext[0]; return CHARVAL}
[1-9][0-9]* | [0] |	{yylval = atoi(yytext); return INTVAL};
//real	{yylval = atoi(yytexy); return REALVAL;}
//string	{yylval = yytext; return STRINGVAL;}
//identifer	{yylval = yytext; return ID;}
//&identifer	{yylval}
//*identifer	{}

%%
