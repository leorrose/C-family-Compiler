%{
	#include <string.h>
	#include <stdlib.h>
	#include <stdio.h> 
	#include "y.tab.h"
%}
%%
"bool"|"char"|"int"|"real"|"string"|"int"[\*]|"char"[\*]|"real"[\*]	{/*yylval = yytext; return VALTYPE;*/ printf("%s", yytext);}
"if"	{/* return IF; */ printf("IF\n");}
"else"	{/*return ELSE;*/ printf("ELSE;*/ \n");}
"while"	{/*return WHILE;*/ printf("WHILE;*/ \n");}
"for"	{/*return FOR;*/ printf("FOR\n");}
"var"	{/*return VAR;*/ printf("VAR\n");}
"function"	{/*return FUNCTION;*/ printf("FUNCTION\n");}
"return"	{/*return RETURN;*/ printf("RETURN\n");}
"null"	{/*return NULLP;*/ printf("NULLP\n");}
"void"	{/*return VOID;*/ printf("VOID\n");}
"do"	{/*return DO;*/ printf("DO\n");}
"&&"|"/"|"="|"=="|">"|">="|"<"|"<="|"-"|"!"|"!="|"||"|[\+]|[\*]|"&"	{/*yylval = yytext; return OP;*/ printf("%s", yytext);}
"true"	{/*yylval=true; return BOOLVAL*/ printf("true");}
"false"	{/*yylval=false; return BOOLVAL*/ printf("false");}
'.' {/*yylval =yytext[0]; return CHARVAL*/  printf("%c", yytext[0]);}
[1-9][0-9]* | [0] |	{/*yylval = atoi(yytext); return INTVAL*/ printf("%d", atoi(yytext))};
%%
