%{
#define YYDEBUG 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "lex.yy.c"
int yyerror();
int yywrap();
typedef struct node
{
	char *token;
	int numOfSubNodes;
	struct node **subNodes;
}node;

node *mknode (char *token,int count,...);
node *combineNodes(char *token,node *one,node *two);
void printTree(node *tree, int tab);
void printTabs(int a);
%}


%union
{
	char *string;
	int intVal;
	char charVal;
	struct node *node;
}


%token VALTYPE IF ELSE WHILE FOR VAR FUNCTION RETURN NULLP VOID DO
%token PLUS MINUS DIV MUL ASS
%token AND EQ G GE L LE NOT NOTEQ OR ADDRESS
%token BOOLVAL CHARVAL DECIMALINTVAL HEXINTVAL REALVAL STRINGVAL ID

%type <node> program cmd declaration names
%type <string> VALTYPE ID 
%start	initial



%%
initial:
	program {printf("ok");printTree($1,0);}
program:
	cmd	{$$ = mknode("CODE",1, $1);} 
	|program cmd    {$$ = combineNodes("CODE",$1, $2);}
	;
cmd:	declaration	{$$ = $1;}
	;
declaration:
	VAR VALTYPE names ';'	{$$ = combineNodes("VAR", mknode("VAR",1,$2), $3);}
	;
names:
	ID ',' names	{$$ = combineNodes("VAR",mknode($1,0),$3);}
	|ID	{$$ = mknode($1,0);}
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
	newnode->token = _strdup(token);
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
	newnode->token = _strdup(token);
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
			free(one);
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
			free(two);
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
	free(tree);
}

void printTabs(int a){ 
	int j = 0;
	for (j; j < a; j++) {
		printf("\t");
	}
}
