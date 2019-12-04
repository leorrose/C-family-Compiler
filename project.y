%{

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "lex.yy.c"
void yyerror();
int yywrap();
typedef struct node
{
	char *token;
	int numOfSubNodes;
	struct *subNodes;
}node;
node *mknode (char *token,int count,...);
node *combineNodes(char *token,*node one,*node two);

%}


%union
{
	char *string;
	int intVal;
	char charVal;
	node *node;
}


%token VALTYPE IF ELSE WHILE FOR VAR FUNCTION RETURN NULLP VOID DO
%token PLUS MINUS DIV MUL ASS
%token AND EQ G GE L LE NOT NOTEQ OR ADDRESS
%token BOOLVAL CHARVAL DECIMALINTVAL HEXINTVAL REALVAL STRINGVAL ID

%type <node> program cmd function procedure 





%%
program:
	cmd {$$ = mknode("CODE",1, $1);}
	|program cmd {$$ = combineNodes("CODE",$1, $2);} 
	;
cmd:	declaration {$$ = $1}
	;
declaration:
	VAR VALTYPE names ";" {$$ = combineNodes("VAR", mknode("VAR",1,$2), $3);}
	;
names:
	ID "," names {$$ = combineNodes("VAR",mknode($1,0),$3);}
	|ID {$$ = mknode($1,0);}
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
node *mknode (char *token, int count, ...){
	va_list nodes;
	int j;
	
	node *newnode=(node*)malloc(sizeof(node));
	newnode->string = strdup(token);
	newnode->numOfSubNodes = count;
	if(count > 0){
		newnode->subNodes = (node**)malloc(sizeof(node*) * count);
	
		va_start(nodes, count);
		for(j=0; j<count;j++){
			newnode->subNodes[j] = va_arg(nodes, j);
		}
		va_end(nodes);
	}
	else{
		newnode->subNodes = null;
	}		
	return newnode; 
}


node *combineNodes(char *token,*node one,*node two){
	int i,j;

	node *newnode=(node*)malloc(sizeof(node));
	newnode->string = strdup(token);		
	newnode->numOfSubNodes = one->numOfSubNodes + two->numOfSubNodes;
	newnode->subNodes = (node**)malloc(sizeof(node*) * newnode->numOfSubNodes);

	for(j=0; j < one->numOfSubNodes; j++){
		newnode->subNodes[j] =  one-> subNodes[j]	
	}
	for(i=0,j; i<two->numOfSubNodes; i++, j++){
		newnode->subNodes[j] =  two-> subNodes[i]
	}
	
	return newnode;
}
