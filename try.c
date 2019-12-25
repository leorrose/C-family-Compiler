#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct node
{
	char *token;
	int numOfSubNodes;
	struct node **subNodes;
}node;

typedef struct func {
	char *name;
	int *args;
	char *type;
	int numOfArgs;
}func;

typedef struct var {
	char *name;
	int type;
}var;

typedef struct table {
	struct table *upperEnv;
	struct func **functions;
	int numOfFunction;
	struct var **variables;
	int numOfvariables;
	int returnType;	
}table;

typedef enum bool {false,true} bool;
int yyerror();
int yywrap();
node *mknode (char *token,int count,...);
node *combineNodes(char *token,node *one,node *two);
void printTree(node *tree, int tab);
void printTabs(int a);
void freeTree(node *tree);
func *mkfunc(char *name, char *type,int numOfArgs, int *args);
int numOfArgs(node *node);
int* argumentRep(node *node);
int getTypeVal(char *string);
var *mkvar(char *name, int type);
table *mktable(table *upperEnv);
void insertVar(table *table, node *node);
void insertString(table *table ,node *node);
void insertArgs(table *table, node *node);
void addFunc(table *table, func *func);
void addVar(table *table, var *var);
void checkTree(node *node, table *env);
bool checkDupFunc(table *table, char *name);
bool checkDupVar(table *table, char *name);
void startSemantics(node *node);


void main(){
    node *node = mknode("CODE",1,mknode("FUNCTION",4,mknode("func2",0),mknode("ARGS",1,mknode("int",3,mknoed("a",0),mknode("b",0),mknode("c",0))),mknode("TYPE",1,mknode("int",0)),(mknode("BODY",0))));
    startSemantics(node);
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

	// if one of the nodes is a leaf there is no sons to combine we need to combine itself
	if(one->numOfSubNodes == 0)
		newnode->numOfSubNodes += 1;
	if(two->numOfSubNodes == 0) 
                newnode->numOfSubNodes += 1;

	newnode->subNodes = (node**)malloc(sizeof(node*) * newnode->numOfSubNodes);

	if (one->numOfSubNodes == 0) {
		newnode->subNodes[j] = one;
		j++;
	}
	else {
		for (j, i = 0; i < one->numOfSubNodes; j++, i++) {
			newnode->subNodes[j] = one->subNodes[i];
		}
		free(one);
	}

	if (two->numOfSubNodes == 0) {
		newnode->subNodes[j] = two;
		j++;
	}
	else {
		for (i = 0, j; i < two->numOfSubNodes; i++, j++) {
			newnode->subNodes[j] = two->subNodes[i];
		}
		free(two);
	}
	return newnode;
}

void printTree(node *tree, int tab) {
	if (!tree)
		return;
	printTabs(tab);
	if (tree->numOfSubNodes != 0) {
		printf("(");
	}
	printf("%s \n", tree->token);

	for (int i = 0 ; i < tree->numOfSubNodes; i++) {
		printTree(tree->subNodes[i], tab + 1);
	}

	if (tree->numOfSubNodes != 0) {
		printTabs(tab);
		printf(")\n");
	}
}

void printTabs(int a){ 
	for (a; a > 0 ; a--) {
		printf("\t");
	}
}

void freeTree(node *tree){
	if(!tree)
		return;
	for (int i=0 ; i < tree->numOfSubNodes; i++) {
		freeTree(tree->subNodes[i]);
	}
	if(tree->token)
		free(tree->token);
	free(tree);
}

/*-------------------------------------------------------------semantic----------------------------------------------------------------------*/
/*-------------------------------------------------------------create functions representation-----------------------------------------------*/
func *mkfunc(char *name, char *type,int numOfArgs, int *args) {
	// args = [Bool=0,Char=1,int=2,real=3,Char*=4,real*=5,int*=6] example : [0,0,1,1,5]
	func *newfunc= (func*)malloc(sizeof(func));
	newfunc->name = strdup(name);
	newfunc->type = strdup(type);
	newfunc->numOfArgs = numOfArgs;
	newfunc->args = args;
	return newfunc;
} 

int numOfArgs(node *node){
	// node Args
	int numOfArgs = 0;
	for(int i=0; i< node->numOfSubNodes; i++)
		numOfArgs += node->subNodes[i]->numOfSubNodes;
	return numOfArgs;																						
}

int *argumentRep(node *node){
	// node Args
	int *args =(int*)malloc(numOfArgs(node) * sizeof(int));
	int k=0;
	for(int i=0; i < node->numOfSubNodes; i++) {
		for(int j=0; j < node->subNodes[i]->numOfSubNodes; j++){
			args[k] = getTypeVal(node->subNodes[i]->token);
			k++;
		}
	}
	return args;
}

int getTypeVal(char *string){
	if(strcmp(string,"bool") == 0) 
		return 0;
	else if(strcmp(string,"char") == 0) 
		return 1;
	else if(strcmp(string,"int") == 0) 
		return 2;
	else if(strcmp(string,"real") == 0) 
		return 3;
	else if(strcmp(string,"char*") == 0) 
		return 4;
	else if(strcmp(string,"real*") == 0) 
		return 5;
	else if(strcmp(string,"int*") == 0) 
		return 6;
	else if(strcmp(string,"STRING") == 0) 
		return 7;
	return -1;
}
/*--------------------------------------------------------------create variable representation----------------------------------------------*/																
var *mkvar(char *name, int type) {
	var *newvar= (var*)malloc(sizeof(var));
	newvar->name = strdup(name);
	newvar->type = type;
	return newvar;
}

void insertVar(table *table, node *node){
	int type = getTypeVal(node -> subNodes[0] -> token);
	for(int i=1; i< node->numOfSubNodes; i++){
		if(node->subNodes[i]->subNodes == NULL){
			if(checkDupVar(table,node->subNodes[i]->token))
				addVar(table, mkvar(node->subNodes[i]->token,type));
			else
				printf("Error: Duplicate variable name - %s\n",node->subNodes[i]->token);
		}
		else{
			if(checkDupVar(table,node -> subNodes[i] -> subNodes[0] -> token))
				addVar(table,mkvar(node -> subNodes[i] -> subNodes[0] -> token, type));
			else
				printf("Error: Duplicate variable name - %s\n",node -> subNodes[i] -> subNodes[0] -> token);
			
		}
	}
}
void insertString(table *table, node *node){
	int type = getTypeVal(node -> token);
	for(int i=0; i< node->numOfSubNodes; i++){

		if (strcmp("=", node->subNodes[i]->token) == 0){
			if(checkDupVar(table,node->subNodes[i]->token))
				addVar(table, mkvar(node->subNodes[i]->token,type));
			else
				printf("Error: Duplicate variable name - %s\n",node->subNodes[i]->token);
		}	
		else{
			if(checkDupVar(table, node -> subNodes[i] -> token))
				addVar(table,mkvar(node -> subNodes[i] -> token, type));
			else
				printf("Error: Duplicate variable name - %s\n",node -> subNodes[i] -> token);
		}
	}
}

void insertArgs(table *table, node *node){
	// node Args
	for(int i=0; i< node->numOfSubNodes; i++){
		int type = getTypeVal(node ->subNodes[i]-> token);
		for(int j=0; j<node->subNodes[i]->numOfSubNodes; j++){
			addVar(table,mkvar(node->subNodes[i]->subNodes[j]->token,type));
		}	
	}
}

/*------------------------------------------------Build Envirments---------------------------------------------------------*/

table *mktable(table *upperEnv) {
	table *newtable= (table*)malloc(sizeof(table));
	newtable -> upperEnv = upperEnv;
	newtable -> functions = NULL;
	newtable -> variables = NULL;
	newtable -> returnType = -1;
	newtable -> numOfFunction = 0;
	newtable -> numOfvariables = 0;
	return newtable;
}

void addFunc(table *table, func *func){
	struct func **functions;
	functions = (struct func**)malloc((table->numOfFunction + 1) * sizeof(struct func*));
	for(int i=0; i< table->numOfFunction; i++){
		functions[i] = table->functions[i];
	}
	functions[table->numOfFunction] = func;
	free(table->functions);
	table->functions = functions;
	table->numOfFunction+=1;
}

void addVar(table *table, var *var){
	struct var **variables = (struct var**)malloc((table->numOfvariables + 1) * sizeof(struct var*));
	for(int i=0; i< table->numOfvariables; i++){
		variables[i] = table->variables[i];
	}
	variables[table->numOfvariables] = var;
	free(table->variables);
	table->variables = variables;
	table->numOfvariables += 1;
}

void printTable(table *table){
	if(table==NULL)
		printf("NONE");
	printf("%d",table->numOfFunction);
	for(int i=0; i<table->numOfFunction; i++){
		printf("%s,%s,%d\n",table->functions[i]->name,table->functions[i]->type,table->functions[i]->numOfArgs);
	}
	for(int i=0; i<table->numOfvariables; i++){
		printf("NewVar: %s, %d\n",table->variables[i]->name,table->variables[i]->type);
	}
}

/*-------------------------------------------------------------------------------------------------------------------------*/

void startSemantics(node *node){
	table *global = mktable(NULL);
	checkTree(node, global);
}

void checkTree(node *node, table *env){
	if (node == NULL){
		return;
	}

	// global functions
	if(!strcmp(node->token,"CODE")){
		for(int i=0; i < node->numOfSubNodes; i++){
			checkTree(node->subNodes[i],env);
		}
	}
	// function
	if(!strcmp(node->token,"FUNCTION")){
		if(checkDupFunc(env,node->subNodes[0]->token)){
			printf("Error: Duplicate function name - %s",node->subNodes[0]->token);
		}
		else{
			func *func = mkfunc(node->subNodes[0]->token,node->subNodes[2]->token,numOfArgs(node->subNodes[1]),argumentRep(node->subNodes[1]));
			addFunc(env,func);
			table *newEnv = mktable(env);
			insertArgs(newEnv,(node->subNodes[1]));
			checkTree(node->subNodes[3],newEnv);
			free(newEnv);
		}
	}
	// function body
	if(!strcmp(node->token,"BODY")){
		for(int i=0; i<node->numOfSubNodes; i++){
			checkTree(node->subNodes[i],env);
		}
	}

	//var
	if(!strcmp(node->token,"VAR")){
		insertVar(env,node);
	}

	//string
	if(!strcmp(node->token,"STRING")){
		insertString(env,node);
	}
}

bool checkDupFunc(table *table, char *name){
	for(int i=0; i<table->numOfFunction; i++){
		if(!strcmp(table->functions[i]->name,name)){
			return true;
		}
		return false;
	}
}

bool checkDupVar(table *table, char *name){
	for(int i=0; i<table->numOfvariables; i++){
		if(!strcmp(table->variables[i]->name,name)){
			return true;
		}
		return false;
	}
}