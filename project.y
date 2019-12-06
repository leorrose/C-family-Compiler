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


%token <string> VALTYPE STRING IF ELSE WHILE FOR VAR FUNCTION RETURN NULLP VOID DO
%token <string> PLUS MINUS DIV MUL ASS
%token <string> AND EQ G GE L LE NOT NOTEQ OR ADDRESS
%token <string> BOOLVAL CHARVAL DECIMALINTVAL HEXINTVAL REALVAL STRINGVAL ID


%type <node> program cmd function procedure parameter_list param Pbody Fbody Fdec all_func_body
%type <node> declaration primitive_declaration declaration_parameters string_declaration string_parameters 
%type <node> primitive_val assign primitive_assign index_assign string_assign 
%type <node> expression
%type <string> unary_op

%start	initial


%left ASS
%left AND
%left OR
%left EQ NOTEQ
%left G GE L LE
%left PLUS MINUS
%left MUL DIV
%right ADDRESS UNARY

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
        |declaration			{$$ = mknode("BODY",1,$1);}
        |function all_func_body		{$$ = combineNodes("BODY",$1,$2);}
        |function			{$$ = mknode("BODY",1,$1);}
        |procedure all_func_body	{$$ = combineNodes("BODY",$1,$2);}
        |procedure			{$$ = mknode("BODY",1,$1);}
	|assign all_func_body		{$$ = combineNodes("BODY",mknode("BODY",1,$1),$2);}
	|assign				{$$ = mknode("BODY",1,$1);}
	|epsilon			{$$ = mknode("BODY",1,mknode("NONE",0));}
	;
/*--------------------------------------------Values-------------------------------------------------------------------*/

primitive_val:
	BOOLVAL		{$$ = mknode($1,0);}
	|CHARVAL	{$$ = mknode($1,0);}
	|DECIMALINTVAL	{$$ = mknode($1,0);}
	|HEXINTVAL	{$$ = mknode($1,0);}
	|REALVAL	{$$ = mknode($1,0);}
	|NULLP		{$$ = mknode($1,0);}
	;

/*---------------------------------------Variable Declarations-----------------------------------------------------------*/	

declaration:
	primitive_declaration				{ $$ = $1; }
	|string_declaration				{ $$ = $1; }	
	;

primitive_declaration:
	VAR VALTYPE declaration_parameters ';'		{ $$ = combineNodes("VAR", mknode("VAR",1,mknode($2,0)), $3);}
	;

declaration_parameters:
	ID ',' declaration_parameters			{ $$ = combineNodes("VAR", mknode("VAR",1,mknode($1,0)), $3);}
	|primitive_assign ',' declaration_parameters	{ $$ = combineNodes("VAR", mknode("ASS",1,$1) ,$3);}
	|ID						{ $$ = mknode($1,0); }
	|primitive_assign				{ $$ = mknode("ASS",1,$1); }
	;

string_declaration:
	string_parameters ',' string_declaration			{ $$ = combineNodes("STRING", mknode("STRING",1,mknode($1,0)), $3);}
	|string_parameters						{ $$ = $1;}
        ;

string_parameters:
	ID '[' expression ']'						{ $$ = mknode($1,1,mknode($3,0)); }
	|ID '[' expression ']' ASS STRINGVAL				{ $$ = mknode($5,3,mknode($1,0),$3,mknode($6,0)); }
	;

/*-------------------------------------------Statments--------------------------------------------------------------------*/
assign:
	primitive_assign ';'			{$$ = $1;}
	|index_assign ';'			{$$ = $1;}
	|string_assign ';'			{$$ = $1;}
	;

primitive_assign:
        ID ASS expression			{$$ = mknode($2,2, mknode($1,0), $3);}
        ;
index_assign:
	ID '[' expression ']' ASS expression	{ $$ = mknode($5,3,mknode($1,0),$3,$6);}
	;	
string_assign:
	ID ASS STRINGVAL			{$$ = mknode($2,2,mknode($1,0),mknode($3,0));}
	;

/*-----------------------------------------expresion--------------------------------------------------------------------*/

expression:
	expression PLUS expression		{ $$ = mknode($2,2,$1,$3);}	
	|expression MINUS expression		{ $$ = mknode($2,2,$1,$3);}
	|expression DIV expression		{ $$ = mknode($2,2,$1,$3);}
	|expression MUL expression		{ $$ = mknode($2,2,$1,$3);}
	|expression AND expression		{ $$ = mknode($2,2,$1,$3);}
	|expression OR expression		{ $$ = mknode($2,2,$1,$3);}
	|expression EQ expression		{ $$ = mknode($2,2,$1,$3);}
	|expression NOTEQ expression		{ $$ = mknode($2,2,$1,$3);}
	|expression G expression		{ $$ = mknode($2,2,$1,$3);}	
	|expression GE expression		{ $$ = mknode($2,2,$1,$3);}
	|expression L expression		{ $$ = mknode($2,2,$1,$3);}
	|expression LE expression		{ $$ = mknode($2,2,$1,$3);}
	|expression NOT expression		{ $$ = mknode($2,2,$1,$3);}
	|unary_op expression %prec UNARY	{ $$ = mknode($1,1,$2);}
	|primitive_val				{ $$ = $1;}
	|ID					{ $$ = mknode($1,0);}
	;
unary_op:
	PLUS	{$$ = $1;}
	|MINUS	{$$ = $1;}
	|NOT	{$$ = $1;}
	;
epsilon: ;


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
