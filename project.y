%{

#define YYDEBUG 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "lex.yy.c"

typedef struct node
{
	char *token;
	int numOfSubNodes;
	struct node **subNodes;
}node;

int yyerror();
int yywrap();
node *mknode (char *token,int count,...);
node *combineNodes(char *token,node *one,node *two);
void printTree(node *tree, int tab);
void printTabs(int a);

%}


%union
{
	char *string;
	struct node *node;
}


%token VALTYPE STRING IF ELSE WHILE FOR VAR FUNCTION RETURN NULLP VOID DO
%token PLUS MINUS DIV MUL ASS
%token AND EQ G GE L LE NOT NOTEQ OR ADDRESS
%token BOOLVAL CHARVAL DECIMALINTVAL HEXINTVAL REALVAL STRINGVAL ID

%type <node> program cmd function procedure parameter_list param Pbody Fbody Fdec all_func_body
%type <node> declaration dect_param 
%type <node> primitive_val simple_assign
%type <string> VALTYPE ID NULLP BOOLVAL CHARVAL DECIMALINTVAL HEXINTVAL REALVAL STRINGVAL ASS 
%start	initial



%%
/*---------------------------------------start program-----------------------------------------------*/

initial:
	program {printTree($1,0);}
program:
	cmd	{$$ = mknode("CODE",1, $1);} 
	|program cmd    {$$ = combineNodes("CODE",$1, mknode("CODE",1,$2));}
	;
cmd:	function
	|procedure
	;

/*----------------------------------------Procedure And Functions---------------------------------------------------*/

function:
	FUNCTION VALTYPE ID '(' parameter_list ')' '{' Fbody '}'	{char *string =(char*)malloc((6+strlen($2)) * sizeof(char)); strcat(string,"TYPE "); $$ = mknode("FUNCTION",4,mknode($3,0),$5,mknode(strcat(string,$2),0),$8);}
	;
procedure:
	FUNCTION VOID ID '(' parameter_list ')' '{' Pbody '}'	{$$ = mknode("FUNCTION",4,mknode($3,0),$5,mknode("TYPE VOID",0),$8);}
	;
parameter_list:
	Fdec ';' Fdec	{$$ = combineNodes("ARGS",$1,$3);}
	|Fdec	{$$ = $1;}	
	|epsilon {$$ = mknode("ARGS",1,mknode("NONE",0));}
	;
Fdec:	VALTYPE	param {$2->token = strdup($1); $$ = mknode("ARGS",1, $2);}
	;
param:
	ID ',' param	{ $$ = combineNodes("ARGS", mknode($1,0), $3);}
	|ID	{$$ = mknode("ARGS",1,mknode($1,0));}
	;

Fbody:
	all_func_body 
	;
Pbody:	
	all_func_body
	;
all_func_body:
	declaration all_func_body       {$$ = combineNodes("BODY",mknode("BODY",1,$1),$2);}
        |declaration    {$$ = mknode("BODY",1,$1);}
        |function all_func_body {$$ = combineNodes("BODY",$1,$2);}
        |function       {$$ = mknode("BODY",1,$1);}
        |procedure all_func_body {$$ = combineNodes("BODY",$1,$2);}
        |procedure {$$ = mknode("BODY",1,$1);}
	|epsilon {$$ = mknode("BODY",1,mknode("NONE",0));}
	;
/*--------------------------------------------Values-------------------------------------------------------------------*/

primitive_val:
	BOOLVAL		{$$ = mknode($1,0);}
	|CHARVAL		{$$ = mknode($1,0);}
	|DECIMALINTVAL	{$$ = mknode($1,0);}
	|HEXINTVAL	{$$ = mknode($1,0);}
	|REALVAL		{$$ = mknode($1,0);}
	|STRINGVAL	{$$ = mknode($1,0);}
	|NULLP		{$$ = mknode($1,0);}


/*---------------------------------------Variable Declarations-----------------------------------------------------------*/	

declaration:
	VAR VALTYPE dect_param ';'	{$$ = combineNodes("VAR", mknode("VAR",1,mknode($2,0)), $3);}
	;

dect_param:
	ID ',' dect_param		{ $$ = combineNodes("VAR", mknode("VAR",1,mknode($1,0)), mknode("VAR",1,$3));}
	|simple_assign ',' dect_param	{ $$ = combineNodes("VAR", mknode("VAR",1,$1),$3);}
	|ID 				{ $$ = mknode($1,0); }
	|simple_assign 			{ $$ = mknode("ASS",1,$1); }
	;
epsilon: ;
	
/*-------------------------------------------Statments--------------------------------------------------------------------*/

simple_assign: 
	ID ASS primitive_val	{$$ = mknode("=",2, mknode($1,0), $3);}
	|ID ASS NULLP	{$$ = mknode("=",2, mknode($1,0), mknode($3,0));}
	;
%%





void main(){
	yydebug = 1;
        yyparse();
}
int yyerror(char *err){
        fprintf(stderr, "Error: %s at line %d\n",err, yylineno);
	fprintf(stderr, "does not accept '%s'\n",yytext);
	return 0;
}
int yywrap(){
	return 1;
}
node *mknode(char *token, int count, ...) {
	va_list nodes;
	int j;

	node *newnode = (node*)malloc(sizeof(node));
	newnode->token = strdup(token);
	newnode->numOfSubNodes = count;
	if (count > 0) {
		newnode->subNodes = (node**)malloc(sizeof(node*) * count);

		va_start(nodes, count);
		for (j = 0; j < count; j++) {
			newnode->subNodes[j] = va_arg(nodes, node *);
		}
		va_end(nodes);
	}
	else {
		newnode->subNodes = NULL;
	}
	return newnode;
}


node *combineNodes(char *token, node *one, node *two) {
	int i=0, j=0;

	node *newnode = (node*)malloc(sizeof(node));
	newnode->token = strdup(token);
	newnode->numOfSubNodes = one->numOfSubNodes + two->numOfSubNodes;
	newnode->subNodes = (node**)malloc(sizeof(node*) * newnode->numOfSubNodes);

	if (one->numOfSubNodes == 0) {
		newnode->numOfSubNodes += 1;
		newnode->subNodes[j] = one;
		j++;
	}
	else {
		for (j, i = 0; i < one->numOfSubNodes; j++, i++) {
			newnode->subNodes[j] = one->subNodes[i];
//			free(one);
		}
	}

	if (two->numOfSubNodes == 0) {
		newnode->numOfSubNodes += 1;
		newnode->subNodes[j] = two;
		j++;
	}
	else {
		for (i = 0, j; i < two->numOfSubNodes; i++, j++) {
			newnode->subNodes[j] = two->subNodes[i];
//			free(two);
		}
	}
	return newnode;
}

void printTree(node *tree, int tab) {
	if (tree == NULL)
		return;
	printTabs(tab);
	if (tree->numOfSubNodes != 0) {
		printf("(");
	}
	printf("%s \n", tree->token);

	int i = 0;
	for (i; i < tree->numOfSubNodes; i++) {
		printTree(tree->subNodes[i], tab + 1);
	}
	if (tree->numOfSubNodes != 0) {
		printTabs(tab);
		printf(")\n");
	}
//	free(tree);
}

void printTabs(int a){ 
	int j = 0;
	for (j; j < a; j++) {
		printf("\t");
	}
}
