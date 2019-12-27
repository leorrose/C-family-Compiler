%{

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

typedef struct func {
	char *name;
	int *args;
	int type;
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


typedef enum bool{ false,true } bool;
int numOfmains = 0;
node *mknode(char *token, int count, ...);
int yywrap();
int yyerror(char *err);
node *mknode(char *token, int count, ...);
node *combineNodes(char *token, node *one, node *two);
void printTree(node *tree, int tab);
void printTabs(int a);
void freeTree(node *tree);
func *mkfunc(char *name, int type, int numOfArgs, int *args);
int numOfArgs(node *node);
int* argumentRep(node *node);
int getTypeVal(char *string);
var *mkvar(char *name, int type);
table *mktable(table *upperEnv, int returnType);
void insertVar(table *stable, node *tree, node* fullTree);
void insertString(table *stable, node *tree, node* fullTree);
void insertArgs(table *stable, node *tree, node* fullTree);
void addFunc(table *table, func *func);
void addVar(table *table, var *var);
void checkTree(node *subTree, table *env, node *tree);
bool checkDupFunc(table *table, char *name);
bool checkDupVar(table *table, char *name);
void startSemantics(node *node);
void printTable(table *table);
bool checkFuncExist(table *env, char *name);
int evalExp(node *subTree, table* stable, node *tree);
void quitProgram(node *tree);
int* getFuncArgsTypes(char* name, table *env);
bool checkVarExist(table *env, char *id);
bool funcCallCheck(node* tree, table *env);
int getFuncNumOfArgs(char* name, table *env);
int getVarType(table *env, char *id);
bool checkReturnVal(node *subTree, table *env, node* tree);
int getFuncType(table *env, char *name);
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


%type <node> program cmd 
%type <node> function procedure parameter_list type_list param body declarations
%type <node> primitive_val
%type <node> declaration primitive_declaration declaration_parameters string_declaration string_parameters 
%type <node> nested_statements stmt code_block declaration_no_function conditions loops multi_assign update procedure_func_call expression_list return
%type <node> assign primitive_assign index_assign string_assign  pointer_assign
%type <node> expression
%type <string> unary_op

%start	initial

%nonassoc LOWER_THEN_ELSE
%nonassoc ELSE

%right UNARY
%left ASS
%left AND
%left OR
%left EQ NOTEQ
%left G GE L LE
%left PLUS MINUS
%left MUL DIV
%right ADDRESS 


/*-----------------------------------------------------START OF RULES--------------------------------------------------------------------*/

%%
/*---------------------------------------start program--------------------------------------------------------------*/

initial:
	program							{  startSemantics($1); printTree($1,0); freeTree($1);}
	;

program:
	cmd								{ $$ = mknode("CODE",1, $1); } 
	|program cmd					{ $$ = combineNodes("CODE",$1, mknode("CODE",1,$2)); }
	;

cmd:	
	function						{ $$ = $1;}
	|procedure						{ $$ = $1;}
	;

/*----------------------------------------Procedure And Functions---------------------------------------------------*/

function:
	FUNCTION VALTYPE ID '(' parameter_list ')' '{' body '}'					{ $$ = mknode("FUNCTION",4,mknode($3,0),$5,mknode("TYPE",1,mknode($2,0)),$8); }
	;

procedure:
	FUNCTION VOID ID '(' parameter_list ')' '{' body '}'					{ $$ = mknode("FUNCTION",4,mknode($3,0),$5,mknode("TYPE",1,mknode("VOID",0)),$8);}
	;

parameter_list:
	type_list ';' parameter_list					{ $$ = combineNodes("ARGS",$1,$3); }
	|type_list										{ $$ = $1;}	
	|epsilon										{ $$ = mknode("ARGS",1,mknode("NONE",0)); }
	;

type_list:	
	VALTYPE	param									{ $2->token = strdup($1); $$ = mknode("ARGS",1, $2); }
	;

param:
	ID ',' param									{ $$ = combineNodes("ARGS", mknode($1,0), $3); }
	|ID												{ $$ = mknode("ARGS",1,mknode($1,0)); }
	;

body:
	declarations nested_statements				{ $$ = combineNodes("BODY",$1,$2); }
    |declarations								{ free($1->token); $1->token=strdup("BODY"); $$=$1; }
	|nested_statements							{ free($1->token); $1->token =strdup("BODY"); $$=$1; }
	|epsilon									{ $$ = mknode("BODY",1,mknode("NONE",0)); }
	;

declarations:
	declaration declarations					{ $$ = combineNodes("BODY",mknode("BODY",1,$1),$2); }
	|declaration								{ $$ = mknode("BODY",1,$1); }
	|function declarations						{ $$ = combineNodes("BODY",mknode("BODY",1,$1),$2); }
    |function									{ $$ = mknode("BODY",1,$1); }
    |procedure declarations						{ $$ = combineNodes("BODY",mknode("BODY",1,$1),$2); }
    |procedure									{ $$ = mknode("BODY",1,$1); }
	;

/*--------------------------------------------Values-------------------------------------------------------------------*/

primitive_val:
	BOOLVAL										{ $$ = mknode("bool",1,mknode($1,0)); }
	|CHARVAL									{ $$ = mknode("char",1,mknode($1,0)); }
	|DECIMALINTVAL								{ $$ = mknode("int",1,mknode($1,0)); }
	|HEXINTVAL									{ $$ = mknode("int",1,mknode($1,0)); }
	|REALVAL									{ $$ = mknode("real",1,mknode($1,0)); }
	|NULLP										{ $$ = mknode("null",1,mknode("0",0)); }
	;

/*---------------------------------------Variable Declarations-----------------------------------------------------------*/	

declaration:
	primitive_declaration									{ $$ = $1; }
	|STRING string_declaration ';'							{ $$ = $2; }	
	;

primitive_declaration:
	VAR VALTYPE declaration_parameters ';'					{ $$ = combineNodes("VAR", mknode("VAR",1,mknode($2,0)), $3); }
	;

declaration_parameters:
	ID ',' declaration_parameters							{ $$ = combineNodes("VAR", mknode("VAR",1,mknode($1,0)), $3); }
	|primitive_assign ',' declaration_parameters			{ $$ = combineNodes("VAR", mknode("ASS",1,$1) ,$3); }
	|ID														{ $$ = mknode($1,0); }
	|primitive_assign										{ $$ = mknode("ASS",1,$1); }
	;

string_declaration:
	string_parameters ',' string_declaration				{ $$ = combineNodes("STRING", $1, $3);}
	|string_parameters										{ $$ = $1;}
    ;

string_parameters:
	ID '[' expression ']'									{ $$ = mknode("STRING",1,mknode($1,1,$3)); }
	|ID '[' expression ']' ASS STRINGVAL					{ $$ = mknode("STRING",1,mknode($5,2,mknode($1,1,$3),mknode($6,0))); }
	;

/*-------------------------------------------Statments--------------------------------------------------------------------*/

nested_statements:
	stmt													{ $$ = mknode("stmt",1,$1); }
	|stmt nested_statements									{ $$ = combineNodes("Statments", mknode("stmt",1,$1),$2);}
	;

stmt:	
	assign ';'												{ $$ = $1; }
	|code_block												{ $$ = $1; }
	|conditions												{ $$ = $1; }
	|loops													{ $$ = $1; }
	|procedure_func_call ';'								{ $$ = $1; }
	|return ';'												{ $$ = $1; }
	;

/*---------------------------------------Assignment----------------------------------------------------------------------*/

assign:
	primitive_assign										{ $$ = $1; }
	|index_assign											{ $$ = $1; }
	|string_assign											{ $$ = $1; }
	|pointer_assign											{ $$ = $1; }
	;

primitive_assign:
    ID ASS expression										{ $$ = mknode($2,2, mknode($1,0), $3); }
    ;
index_assign:
	ID '[' expression ']' ASS expression					{ $$ = mknode($5,2,mknode($1,1,$3),$6); }
	;	
string_assign:
	ID ASS STRINGVAL										{ $$ = mknode($2,2,mknode($1,0),mknode($3,0)); }
	;
pointer_assign:
	MUL ID ASS expression									{ $$ = mknode($3, 1 , mknode("POINTER", 2, mknode($2,0), $4,0)); }
	;
/*----------------------------------------Code Block--------------------------------------------------------------------*/

code_block:
	'{' declaration_no_function nested_statements '}'					{ $$ = combineNodes("BLOCK",$2, $3); }
	|'{' declaration_no_function '}'									{ $$ = $2; }
	|'{' nested_statements '}'											{free($2->token); $2-> token = strdup("BLOCK"); $$ = $2; }
	|'{' epsilon '}'													{ $$ = mknode("BLOCK",1,mknode("NONE",0)); }
	;
declaration_no_function:
	declaration declaration_no_function									{ $$ = combineNodes("BLOCK", mknode("BLOCK",1,$1), $2);}
	|declaration														{ $$ = mknode("BLOCK", 1, $1);}
	;

/*----------------------------------------Conditions--------------------------------------------------------------------*/

conditions:
	IF '(' expression ')' stmt %prec LOWER_THEN_ELSE		{ $$ = mknode("IF", 2, $3, $5); }
	|IF '(' expression ')' stmt ELSE stmt					{ $$ = mknode("IF-ELSE", 3, $3, $5, $7);}
	;

/*-----------------------------------------loops------------------------------------------------------------------------*/

loops: 
	WHILE '(' expression ')' stmt												{ $$ =	mknode("WHILE", 2, $3 , $5); } 
	|DO code_block WHILE '(' expression ')' ';'									{ $$ =	mknode("DO-WHILE", 2, $5, $2); }
	|FOR '(' multi_assign ';' expression ';' update ')'	stmt					{ 
																					free($3->token); $3->token = strdup("INIT");
																					$$ = mknode("FOR",4,$3,mknode("COND",1,$5),$7, $9);
																				}
	;

multi_assign:
	primitive_assign ',' multi_assign						{ $$ = combineNodes("ass", mknode("ass",1,$1),$3); }
	|primitive_assign										{ $$ = mknode("ass",1,$1); }
	;
update:
	ID PLUS PLUS											{ $$ = mknode("UPDATE",1,mknode("=",2, mknode($1,0), mknode("+", 2, mknode($1,0), mknode("int",1, mknode("1",0))))); }
	| ID MINUS MINUS										{ $$ = mknode("UPDATE",1,mknode("=",2, mknode($1,0), mknode("-", 2, mknode($1,0), mknode("int",1,mknode("1",0))))); }		
	| multi_assign											{ free($1->token); $1-> token = strdup("UPDATE"); $$ = $1; }
	;

/*-----------------------------------------procedure/function calls-----------------------------------------------------*/

procedure_func_call:
	ID '(' expression_list ')'								{ $$ = combineNodes("FUNC-CALL", mknode($1,0), $3); }
	;
expression_list:
	expression ',' expression_list							{ $$ = combineNodes("paramters",mknode("param",1,$1), $3);}
	|expression												{ $$ = mknode("paramters",1,$1); }
	|epsilon												{ $$ = mknode("NONE",0); }
	;

/*-----------------------------------------Return-----------------------------------------------------------------------*/

return:
	RETURN expression										{ $$ = mknode("RET",1,$2); }
	;

/*-----------------------------------------expression--------------------------------------------------------------------*/

expression:
	expression PLUS expression              				{ $$ = mknode($2,2,$1,$3); }
	|expression MINUS expression               				{ $$ = mknode($2,2,$1,$3); }
	|expression DIV expression								{ $$ = mknode($2,2,$1,$3); }
	|expression MUL expression								{ $$ = mknode($2,2,$1,$3); }
	|expression AND expression								{ $$ = mknode($2,2,$1,$3); }
	|expression OR expression								{ $$ = mknode($2,2,$1,$3); }
	|expression EQ expression								{ $$ = mknode($2,2,$1,$3); }
	|expression NOTEQ expression							{ $$ = mknode($2,2,$1,$3); }
	|expression G expression								{ $$ = mknode($2,2,$1,$3); }	
	|expression GE expression								{ $$ = mknode($2,2,$1,$3); }
	|expression L expression								{ $$ = mknode($2,2,$1,$3); }
	|expression LE expression								{ $$ = mknode($2,2,$1,$3); }
	|unary_op expression %prec UNARY						{ $$ = mknode($1,1,$2);}
	|primitive_val											{ $$ = $1; }
	|ID														{ $$ = mknode($1,0); }
	|procedure_func_call									{ $$ = $1;}
	| '|' ID '|'											{ $$ = mknode("STR-LEN",1,mknode($2,0)); }
	| '(' expression ')'									{ $$ = $2; }
	| ADDRESS ID											{ $$ = mknode("ADDRESS-OF",1,mknode($2,0)); }
	| ADDRESS ID '[' expression ']'							{ $$ = mknode("ADDRESS-OF",1,mknode($2,1,$4));}
	| ID '[' expression ']'									{ $$ = mknode($1,1,$3); }
	;

unary_op:
	PLUS													{ $$ = $1; }
	|MINUS													{ $$ = $1; }
	|NOT													{ $$ = $1; }
	|MUL													{ $$ = "POINTER";}
	;

epsilon: ;

%%


/*-----------------------------------------------------END OF RULES--------------------------------------------------------------------*/


void main(){
    yyparse();
}
int yyerror(char *err){
	fflush(stdout);
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
	int i = 0, j = 0;

	node *newnode = (node*)malloc(sizeof(node));
	newnode->token = strdup(token);
	newnode->numOfSubNodes = one->numOfSubNodes + two->numOfSubNodes;

	// if one of the nodes is a leaf there is no sons to combine we need to combine itself
	if (one->numOfSubNodes == 0)
		newnode->numOfSubNodes += 1;
	if (two->numOfSubNodes == 0)
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

	for (int i = 0; i < tree->numOfSubNodes; i++) {
		printTree(tree->subNodes[i], tab + 1);
	}

	if (tree->numOfSubNodes != 0) {
		printTabs(tab);
		printf(")\n");
	}
}

void printTabs(int a) {
	for (a; a > 0; a--) {
		printf("\t");
	}
}

void freeTree(node *tree) {
	if (!tree)
		return;
	for (int i = 0; i < tree->numOfSubNodes; i++) {
		freeTree(tree->subNodes[i]);
	}
	if (tree->token)
		free(tree->token);
	free(tree);
}

/*-------------------------------------------------------------semantic----------------------------------------------------------------------*/
/*-------------------------------------------------------------create functions representation-----------------------------------------------*/
func *mkfunc(char *name, int type, int numOfArgs, int *args) {
	// args = [Bool=0,Char=1,int=2,real=3,Char*=4,real*=5,int*=6] example : [0,0,1,1,5]
	func *newfunc = (func*)malloc(sizeof(func));
	newfunc->name = strdup(name);
	newfunc->type = type;
	newfunc->numOfArgs = numOfArgs;
	newfunc->args = args;
	return newfunc;
}

int numOfArgs(node *tree) {
	// node Args
	int numOfArgs = 0;
	for (int i = 0; i < tree->numOfSubNodes; i++)
		numOfArgs += tree->subNodes[i]->numOfSubNodes;
	return numOfArgs;
}

int *argumentRep(node *tree) {
	// node Args
	int *args = (int*)malloc(numOfArgs(tree) * sizeof(int));
	int k = 0;
	for (int i = 0; i < tree->numOfSubNodes; i++) {
		for (int j = 0; j < tree->subNodes[i]->numOfSubNodes; j++) {
			args[k] = getTypeVal(tree->subNodes[i]->token);
			k++;
		}
	}
	return args;
}

int getTypeVal(char *string) {
	if (strcmp(string, "bool") == 0)
		return 0;
	else if (strcmp(string, "char") == 0)
		return 1;
	else if (strcmp(string, "int") == 0)
		return 2;
	else if (strcmp(string, "real") == 0)
		return 3;
	else if (strcmp(string, "char*") == 0)
		return 4;
	else if (strcmp(string, "real*") == 0)
		return 5;
	else if (strcmp(string, "int*") == 0)
		return 6;
	else if (strcmp(string, "STRING") == 0)
		return 7;
	else if (strcmp(string, "null") == 0)
		return 8;
}
/*--------------------------------------------------------------create variable representation----------------------------------------------*/
var *mkvar(char *name, int type) {
	var *newvar = (var*)malloc(sizeof(var));
	newvar->name = strdup(name);
	newvar->type = type;
	return newvar;
}

void insertVar(table *stable, node *tree, node* fullTree) {
	int type = getTypeVal(tree->subNodes[0]->token);
	for (int i = 1; i < tree->numOfSubNodes; i++) {
		if (tree->subNodes[i]->subNodes == NULL) {
			if (checkDupVar(stable, tree->subNodes[i]->token))
				addVar(stable, mkvar(tree->subNodes[i]->token, type));
			else {
				printf("Error: Duplicate variable name - %s\n", tree->subNodes[i]->token);
				quitProgram(fullTree);
			}
		}
		else {
			if (checkDupVar(stable, tree->subNodes[i]->subNodes[0]->token))
				addVar(stable, mkvar(tree->subNodes[i]->subNodes[0]->token, type));
			else {
				printf("Error: Duplicate variable name - %s\n", tree->subNodes[i]->subNodes[0]->token);
				quitProgram(fullTree);
			}

		}
	}
}
void insertString(table *stable, node *tree, node* fullTree) {
	int type = getTypeVal(tree->token);
	for (int i = 0; i < tree->numOfSubNodes; i++) {

		if (strcmp("=", tree->subNodes[i]->token) == 0) {
			if (checkDupVar(stable, tree->subNodes[i]->subNodes[0]->token))
				addVar(stable, mkvar(tree->subNodes[i]->subNodes[0]->token, type));
			else {
				printf("Error: Duplicate variable name - %s\n", tree->subNodes[i]->subNodes[0]->token);
				quitProgram(fullTree);
			}
		}
		else {
			if (checkDupVar(stable, tree->subNodes[i]->token))
				addVar(stable, mkvar(tree->subNodes[i]->token, type));
			else {
				printf("Error: Duplicate variable name - %s\n", tree->subNodes[i]->token);
				quitProgram(fullTree);
			}
		}
	}
}

void insertArgs(table *stable, node *tree, node* fullTree) {
	// node Args
	for (int i = 0; i < tree->numOfSubNodes; i++) {
		int type = getTypeVal(tree->subNodes[i]->token);
		for (int j = 0; j < tree->subNodes[i]->numOfSubNodes; j++) {
			if (checkDupVar(stable, tree->subNodes[i]->subNodes[j]->token))
				addVar(stable, mkvar(tree->subNodes[i]->subNodes[j]->token, type));
			else {
				printf("Error: Duplicate variable name - %s\n", tree->subNodes[i]->subNodes[j]->token);
				quitProgram(fullTree);
			}
		}
	}
}

/*------------------------------------------------Build Envirments---------------------------------------------------------*/

table *mktable(table *upperEnv, int returnType) {
	table *newtable = (table*)malloc(sizeof(table));
	newtable->upperEnv = upperEnv;
	newtable->functions = NULL;
	newtable->variables = NULL;
	newtable->returnType = returnType; // -1 no return, 0-7 types, 8 go up and check return  
	newtable->numOfFunction = 0;
	newtable->numOfvariables = 0;
	return newtable;
}

void addFunc(table *stable, func *funcAdd) {
	func **functions;
	functions = (struct func**)malloc((stable->numOfFunction + 1) * sizeof(struct func*));
	for (int i = 0; i < stable->numOfFunction; i++) {
		functions[i] = stable->functions[i];
	}
	functions[stable->numOfFunction] = funcAdd;
	free(stable->functions);
	stable->functions = functions;
	stable->numOfFunction += 1;
}

void addVar(table *table, var *varAdd) {
	var **variables = (struct var**)malloc((table->numOfvariables + 1) * sizeof(struct var*));
	for (int i = 0; i < table->numOfvariables; i++) {
		variables[i] = table->variables[i];
	}
	variables[table->numOfvariables] = varAdd;
	free(table->variables);
	table->variables = variables;
	table->numOfvariables += 1;
}

/*-------------------------------------------------------------------------------------------------------------------------*/

void startSemantics(node *tree) {
	table *global = mktable(NULL,-1);
	checkTree(tree, global,tree);
	if(numOfmains==0){
		printf("Error: no main function\n");
		quitProgram(tree);
	}
}

void checkTree(node *subTree , table *env, node *tree) {
	if (subTree == NULL) {
		return;
	}

	// global functions
	else if (!strcmp(subTree->token, "CODE")) {
		for (int i = 0; i < subTree->numOfSubNodes; i++) {
			checkTree(subTree->subNodes[i], env, tree);
		}
	}
	// function
	else if (!strcmp(subTree->token, "FUNCTION")) {
		if (!strcmp(subTree->subNodes[0]->token,"main")) {
			if (!checkFuncExist(env,"main")) {
				printf("Error: main can only used once\n");
				quitProgram(tree);
			}
				
			else if (strcmp(subTree->subNodes[2]->subNodes[0]->token, "VOID")) {
				printf("Error: main type can only be void\n");
				quitProgram(tree);
			}

			else if (numOfArgs(subTree->subNodes[1]) != 0) {
				printf("Error: main cannot have arguments\n");
				quitProgram(tree);
			}
			else {
				func *func = mkfunc(subTree->subNodes[0]->token, getTypeVal(subTree->subNodes[2]->subNodes[0]->token), numOfArgs(subTree->subNodes[1]), argumentRep(subTree->subNodes[1]));
				addFunc(env, func);
				table *newEnv = mktable(env, getTypeVal(subTree->subNodes[2]->subNodes[0]->token));
				insertArgs(newEnv, (subTree->subNodes[1]), tree);
				checkTree(subTree->subNodes[3], newEnv, tree);
				free(newEnv);
				numOfmains += 1;
			}
		}
		else if (checkDupFunc(env, subTree->subNodes[0]->token)) {
			func *func = mkfunc(subTree->subNodes[0]->token, getTypeVal(subTree->subNodes[2]->subNodes[0]->token), numOfArgs(subTree->subNodes[1]), argumentRep(subTree->subNodes[1]));
			addFunc(env, func);
			table *newEnv = mktable(env, getTypeVal(subTree->subNodes[2]->subNodes[0]->token));
			insertArgs(newEnv, (subTree->subNodes[1]), tree);
			checkTree(subTree->subNodes[3], newEnv, tree);
			free(newEnv);
		}
		else {
			printf("Error: Duplicate function name - %s\n", subTree->subNodes[0]->token);
			quitProgram(tree);
		}
	}
	
	//block
	else if (!strcmp(subTree->token, "BLOCK")) {
		table *newEnv = mktable(env, 8);
		for (int i = 0; i < subTree->numOfSubNodes; i++) {
			checkTree(subTree->subNodes[i], newEnv, tree);
		}
		free(newEnv);
	}

	// function body
	else if (!strcmp(subTree->token, "BODY")) {
		for (int i = 0; i < subTree->numOfSubNodes; i++) {
			checkTree(subTree->subNodes[i], env, tree);
		}
	}

	//var
	else if (!strcmp(subTree->token, "VAR")) {
		insertVar(env, subTree, tree);
	}

	//string
	else if (!strcmp(subTree->token, "STRING")) {
		insertString(env, subTree, tree);
	}

	//if
	else if (!strcmp(subTree->token, "IF")) {
		if (evalExp(subTree->subNodes[0], env, tree) != 0) {
			printf("Error: Incompatible expression in \"if\" expected bool\n");
			quitProgram(tree);
		}
		checkTree(subTree->subNodes[1], env, tree);
	}

	//if-else
	else if (!strcmp(subTree->token, "IF-ELSE")) {
		if (evalExp(subTree->subNodes[0], env, tree) != 0) {
			printf("Error: Incompatible expression in \"if-else\" expected bool\n");
			quitProgram(tree);
		}
		checkTree(subTree->subNodes[1], env, tree);
		checkTree(subTree->subNodes[2], env, tree);
	}
	//while
	else if (!strcmp(subTree->token, "WHILE")) {
		if (evalExp(subTree->subNodes[0], env, tree) != 0) {
			printf("Error: Incompatible expression in \"while\" expected bool\n");
			quitProgram(tree);
		}
		checkTree(subTree->subNodes[1], env, tree);
	}
	//do while
	else if (!strcmp(subTree->token, "DO-WHILE")) {
		if (evalExp(subTree->subNodes[0], env, tree) != 0) {
			printf("Error: Incompatible expression in \"do while\" expected bool\n");
			quitProgram(tree);
		}
		checkTree(subTree->subNodes[1], env, tree);
	}
	//for
	else if (!strcmp(subTree->token, "FOR")) {
		for (int i = 0; i < subTree->numOfSubNodes-1; i++) {
			checkTree(subTree->subNodes[i], env, tree);
		}
		checkTree(subTree->subNodes[subTree->numOfSubNodes - 1], env, tree);
	}
	//for-init
	else if (!strcmp(subTree->token, "INIT")) {
		for (int i = 0; i < subTree->numOfSubNodes; i++) {
			checkTree(subTree->subNodes[i], env, tree);
		}
	}
	//for-condition
	else if (!strcmp(subTree->token, "COND")) {
		if (evalExp(subTree->subNodes[0], env, tree) != 0) {
			printf("Error: Incompatible expression in \"for\" expected bool\n");
			quitProgram(tree);
		}
	}
	//for-update
	else if (!strcmp(subTree->token, "UPDATE")) {
		for (int i = 0; i < subTree->numOfSubNodes; i++) {
			checkTree(subTree->subNodes[i],env,tree);
		}
	}
	//function call
	else if (!strcmp(subTree->token, "FUNC-CALL")) {
		if (!funcCallCheck(subTree, env)) {
			quitProgram(tree);
		}
	}

	//return
	else if (!strcmp(subTree->token, "RET")) {
		if (!checkReturnVal(subTree, env,tree)) {
			printf("Error: Incompatible return type\n");
			quitProgram(tree);
		}
		evalExp(subTree->subNodes[0], env, tree);
	}

	//assignment
	else if (!strcmp(subTree->token, "=")) {
		if (!checkVarExist(env, subTree->subNodes[0]->token)) {
			printf("Error: Variable used before declaration - %s\n", subTree->subNodes[0]->token);
			quitProgram(tree);
		}
		if(evalExp(subTree->subNodes[1], env, tree) == 8 && (getVarType(env, subTree->subNodes[0]->token)==4 || getVarType(env, subTree->subNodes[0]->token)==5 || getVarType(env, subTree->subNodes[0]->token)==6))
			return;

		if(getVarType(env, subTree->subNodes[0]->token) == 7){
			if(subTree->subNodes[0]->numOfSubNodes !=0 && evalExp(subTree->subNodes[0]->subNodes[0], env, tree) == 2 && evalExp(subTree->subNodes[1], env, tree) == 1)
				return;
		}
		if (getVarType(env, subTree->subNodes[0]->token) != evalExp(subTree->subNodes[1], env, tree)) {
			printf("Error: Incompatible assignment - %s\n", subTree->subNodes[0]->token);
			quitProgram(tree);
		}	
	}
	
	//del at end
	else {
		printf("%s\n", subTree->token);
	}

	printTable(env);
	printf("---------\n");
}

//return type of exp
int evalExp(node *subTree, table* stable, node *tree) {
	if (!strcmp("+", subTree->token) || !strcmp("-", subTree->token) || !strcmp("*", subTree->token) || !strcmp("/", subTree->token)) {
		int type1 = evalExp(subTree->subNodes[0], stable, tree);
		int type2 = evalExp(subTree->subNodes[1], stable, tree);
		if (type1 == 2 || type1 == 3) {
			if (type2 == 2 || type2 == 3) {
				if (type1 + type2 == 4) // int = 2; 2+2 = 4;
					return 2;
				else
					return 3;
			}
			else {
				printf("Error: unsupported operand types %s\n", subTree->token);
				quitProgram(tree);
			}
		}
		else {
			printf("Error: unsupported operand types %s\n", subTree->token);
			quitProgram(tree);
		}
	}
	if (!strcmp("&&", subTree->token) || !strcmp("||", subTree->token)) {
		int type1 = evalExp(subTree->subNodes[0], stable, tree);
		int type2 = evalExp(subTree->subNodes[1], stable, tree);
		if (type1 != 0 || type2 != 0) {
			printf("Error: unsupported operand types %s\n", subTree->token);
			quitProgram(tree);
		}
		return 0;
	}
	if (!strcmp("==", subTree->token) || !strcmp("!=", subTree->token)) {
		int type1 = evalExp(subTree->subNodes[0], stable, tree);
		int type2 = evalExp(subTree->subNodes[1], stable, tree);
		if (type1 == 0 && type2 == 0) 
			return 0;
		else if (type1 == 1 && type2 == 1)
			return 0;
		else if (type1 == 2 && type2 == 2)
			return 0;
		else if (type1 == 3 && type2 == 3)
			return 0;
		else if (type1 == 4 && type2 == 4)
			return 0;
		else if (type1 == 5 && type2 == 5)
			return 0;
		else if (type1 == 6 && type2 == 6)
			return 0;
		else {
			printf("Error: unsupported operand types %s\n", subTree->token);
			quitProgram(tree);
		}
	}
	if (!strcmp(">", subTree->token) || !strcmp(">=", subTree->token) || !strcmp("<", subTree->token) || !strcmp("<=", subTree->token)) {
		int type1 = evalExp(subTree->subNodes[0], stable, tree);
		int type2 = evalExp(subTree->subNodes[1], stable, tree);
		if (type1 == 2 || type1 == 3) {
			if (type2 == 2 || type2 == 3) {
				return 0;
			}
			else {
				printf("Error: unsupported operand types %s\n", subTree->token);
				quitProgram(tree);
			}
		}
		else {
			printf("Error: unsupported operand types %s\n", subTree->token);
			quitProgram(tree);
		}
	}
	if (!strcmp("!", subTree->token)) {
		int type1 = evalExp(subTree->subNodes[0], stable, tree);
		if (type1 != 0) {
			printf("Error: unsupported operand types %s\n", subTree->token);
			quitProgram(tree);
		}
		return 0;
	}
	if (!strcmp("STR-LEN", subTree->token)) {
		if (getVarType(stable, subTree->subNodes[0]->token) != 7) {
			printf("Error: unsupported operand types | str |\n");
			quitProgram(tree);
		}
		return 2;
	}
	if (!strcmp("POINTER", subTree->token)) {
		int type1 = evalExp(subTree->subNodes[0], stable, tree);
		if (type1 == 4 || type1==5 || type1==6) {
			return type1;
		}
		else {
			printf("Error: unsupported operand types %s\n", subTree->token);
			quitProgram(tree);
		}
	}
	if (!strcmp("ADDRESS-OF", subTree->token)) {
		int type1 = evalExp(subTree->subNodes[0], stable, tree);
		printf("%d\n",type1);
		if (type1 == 1 ) {
			return 4;
		}
		else if (type1 == 2) {
			return 6;
		}
		else if (type1 == 3) {
			return 5;
		}
		else if (type1 == 7) {
			printf("%d\n",evalExp(subTree->subNodes[0], stable, tree));
			if (evalExp(subTree->subNodes[0], stable, tree)!= 1) {
				printf("Error: unsupported operand types %s\n", subTree->token);
				quitProgram(tree);
			}
			return 4;
		}
		else {
			printf("Error: unsupported operand types %s\n", subTree->token);
			quitProgram(tree);
		}
		return 0;
	}
	if (!strcmp("FUNC-CALL", subTree->token)) {
		if (!funcCallCheck(subTree, stable)) {
			quitProgram(tree);
		}
		return getFuncType(stable, subTree->subNodes[0]->token);
	}
	else {
		if ((getVarType(stable, subTree->token) <= 6 && getVarType(stable, subTree->token)>=0) || getVarType(stable, subTree->token) == 8)
			return getVarType(stable, subTree->token);
		else if (getVarType(stable, subTree->token) == 7) {
			if(subTree -> numOfSubNodes != 0){
				if (evalExp(subTree->subNodes[0], stable, tree) != 2) {
					printf("Error:  %s Index must be int\n", subTree->subNodes[0]->token);
					quitProgram(tree);
				}
				return 1;
			}
			return 7;
		}
		else {
			printf("Error: variable %s does not exist\n", subTree->token);
			quitProgram(tree);
		}	
	}
}


bool checkDupFunc(table *stable, char *name) {
	for (int i = 0; i < stable->numOfFunction; i++) {
		if (!strcmp(stable->functions[i]->name, name)) {
			return false;
		}
	}
	return true;
}

bool checkDupVar(table *stable, char *name) {
	for (int i = 0; i < stable->numOfvariables; i++) {
		if (!strcmp(stable->variables[i]->name, name)) {
			return false;
		}
	}
	return true;
}

bool checkFuncExist(table *env, char *name) {
	table *temp = env;
	while (temp != NULL) {
		if (!checkDupFunc(temp, name))
			return false;
		temp = temp->upperEnv;
	}
	return true;
}

void quitProgram(node *tree) {
	freeTree(tree);
	getchar();
	exit(1);
}

bool funcCallCheck(node* tree, table *env) {
	if (checkFuncExist(env, tree->subNodes[0]->token)) {
		printf("Error: calling function %s that does not exist\n", tree->subNodes[0]->token);
		return false;
	}
	int numOfarguments = tree->numOfSubNodes;
	for(int i=0; i<tree->numOfSubNodes; i++){
		if(!strcmp("NONE", tree->subNodes[i]->token))
			numOfarguments -= 1;
	}
	if (getFuncNumOfArgs(tree->subNodes[0]->token, env) != numOfarguments - 1) {
		printf("%d\n",getFuncNumOfArgs(tree->subNodes[0]->token, env));
		printf("%d\n",tree->numOfSubNodes);
		printf("Error: number of arguments does not match calling function %s\n", tree->subNodes[0]->token);
		return false;
	}
	for(int i=1; i<tree->numOfSubNodes;i++){
		if(strcmp("NONE",tree->subNodes[i]->token) !=0 ){
			if (!checkVarExist(env, tree->subNodes[i]->token)) {
				printf("Error: variable %s does not exist\n", tree->subNodes[i]->token);
				return false;
			}	
		}
	}
	int *args = getFuncArgsTypes(tree->subNodes[0]->token, env);
	for (int i = 1; i < tree->numOfSubNodes; i++) {
		if(strcmp("NONE",tree->subNodes[i]->token) != 0){
			if (getVarType(env, tree->subNodes[i]->token) != args[i-1]) {
				printf("Error: variable %s does not match expected type\n", tree->subNodes[i]->token);
				return false;
			}
		}
	}
}

int getFuncNumOfArgs(char* name, table *env) {
	table *temp = env;
	while (temp != NULL) {
		for (int i = 0; i < temp->numOfFunction; i++) {
			if (!strcmp(name, temp->functions[i]->name)) {
				return temp->functions[i]->numOfArgs;
			}
		}
		temp = temp->upperEnv;
	}
}

int* getFuncArgsTypes(char* name, table *env) {
	table *temp = env;
	while (temp != NULL) {
		for (int i = 0; i < temp->numOfFunction; i++) {
			if (!strcmp(name, temp->functions[i]->name)) {
				return temp->functions[i]->args;
			}
		}
		temp = temp->upperEnv;
	}
}

int getFuncType(table *env, char *name) {
	table *temp = env;
	while (temp != NULL) {
		for (int i = 0; i < temp->numOfFunction; i++) {
			if (!strcmp(name, temp->functions[i]->name)) {
				return temp->functions[i]->type;
			}
		}
		temp = temp->upperEnv;
	}
	return -1;
}

int getVarType(table *env, char *id) {
	if (!strcmp("bool", id) || !strcmp("char", id) || !strcmp("int", id) || !strcmp("real", id) || !strcmp("null", id)) {
		return getTypeVal(id);
	}
	table *temp = env;
	while (temp != NULL) {
		for (int i = 0; i < temp->numOfvariables; i++) {
			if (!strcmp(id, temp->variables[i]->name)) {
				return temp->variables[i]->type;
			}
		}
		temp = temp->upperEnv;
	}
	return -1;
}

bool checkVarExist(table *env, char *id) {
	if (!strcmp("bool", id) || !strcmp("char", id) || !strcmp("int", id) || !strcmp("real", id) || !strcmp("null", id)) {
		return true;
	}
	table *temp = env;
	while (temp != NULL) {
		for (int i = 0; i < temp->numOfvariables; i++) {
			if (!strcmp(id, temp->variables[i]->name)) {
				return true;
			}
		}
		temp = temp->upperEnv;
	}
	return false;
}

bool checkReturnVal(node *subTree, table *env, node* tree) {
	if (env->returnType <= 6 && env->returnType >= 0) {
		if (evalExp(subTree->subNodes[0], env, tree) != env->returnType) {
			return false;
		}
	}
	if (env->returnType == 8) {
		if (env->upperEnv != NULL)
			return checkReturnVal(subTree, env->upperEnv, tree);
		else
			return false;
	}
	if (env->returnType == -1) {
		return false;
	}
}

void printTable(table *table) {
	printf("Functions:\n");
	for (int i = 0; i < table->numOfFunction; i++) {
		printf("%s %d %d ", table->functions[i]->name, table->functions[i]->type, table->functions[i]->numOfArgs);
		printf("[");
		for (int j = 0; j < table->functions[i]->numOfArgs; j++) {
			printf("%d ", table->functions[i]->args[j]);
		}
		printf("]\n");
	}
	printf("Variables:\n");
	for (int i = 0; i < table->numOfvariables; i++) {
		printf("%s %d\n", table->variables[i]->name, table->variables[i]->type);
	}
}


