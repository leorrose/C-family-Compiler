%{
	#include <string.h>
	#include <stdlib.h>
	#include <stdio.h> 
	#include "y.tab.h"
%}

%%
	/* Types */
"bool"|"char"|"int"|"real"|"string"|"int"[\*]|"char"[\*]|"real"[\*]	{yylval.string = strdup(yytext); return VALTYPE;}
	
	/* condition */
"if"	{return IF;}
"else"	{return ELSE;}
"while"	{return WHILE;}
"do"    {return DO;}

	/* loops */
"for"	{return FOR;}

	/* assignment */
"var"	{return VAR;}

	/*function and procedures */
"function"	{return FUNCTION;}
"return"	{return RETURN;}
"null"	{return NULLP;}
"void"	{return VOID;}

	/* operators */
"&&"|"/"|"="|"=="|">"|">="|"<"|"<="|"-"|"!"|"!="|"||"|[\+]|[\*]|"&"	{yylval.string = strdup(yytext); return OP;}
"true"	{yylval.intVal=1; return BOOLVAL;}
"false"	{yylval.intVal=0; return BOOLVAL;}
'.' {yylval.charVal =yytext[1]; return CHARVAL;}
[a-zA-z][a-zA-z"_"0-9]*	{yylval.string=strdup(yytext); return ID;}

%%
