%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "lex.yy.c"

/* struct for parsing tree node */
typedef struct node
{
	char *token;
	int numOfSubNodes;
	struct node **subNodes;
}node;

/* struct for symbol table function representation */
typedef struct func {
	char *name;
	int *args;
	int type;
	int numOfArgs;
}func;

/* struct for symbol table var representation */
typedef struct var {
	char *name;
	int type;
}var;

/* struct for symbol table */
typedef struct table {
	struct table *upperEnv;
	struct func **functions;
	int numOfFunction;
	struct var **variables;
	int numOfvariables;
	int returnType;
}table;

/* global variables */
typedef enum bool{ false,true } bool;
int numOfmains = 0;

/* parsing tree */
node *mknode(char *token, int count, ...);
int yywrap();
int yyerror(char *err);
node *mknode(char *token, int count, ...);
node *combineNodes(char *token, node *one, node *two);
void printTree(node *tree, int tab);
void printTabs(int a);
void freeTree(node *tree);

/* symbol table function representation */
func *mkfunc(char *name, int type, int numOfArgs, int *args);
int numOfArgs(node *node);
int* argumentRep(node *node);

/* symbol table var representation */
var *mkvar(char *name, int type);
table *mktable(table *upperEnv, int returnType);
void insertVar(table *stable, node *tree, node* fullTree);
void insertString(table *stable, node *tree, node* fullTree);
void insertArgs(table *stable, node *tree, node* fullTree);

/* semantic analysis*/
void addFunc(table *table, func *func);
void addVar(table *table, var *var);
void checkTree(node *subTree, table *env, node *tree);
bool checkDupFunc(table *table, char *name);
bool checkDupVar(table *table, char *name);
void startSemantics(node *node);
void printTable(table *table);
bool checkFuncExist(table *env, char *name);
int evalExp(node *subTree, table* stable, node *tree);
void quitProgram(node *tree, table *env);
int* getFuncArgsTypes(char* name, table *env);
bool checkVarExist(table *env, char *id);
bool funcCallCheck(node* tree, table *env);
int getFuncNumOfArgs(char* name, table *env);
int getVarType(table *env, char *id);
bool checkReturnVal(node *subTree, table *env, node* tree);
int getFuncType(table *env, char *name);
bool isValue(char *id);
void freeTable(table *env);
void freeAllTables(table *env);
int getTypeVal(char *string);

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
%type <node> function procedure parameter_list parameter_list_no_empty type_list param func_body proc_body declarations
%type <node> primitive_val
%type <node> declaration primitive_declaration declaration_parameters string_declaration string_parameters 
%type <node> nested_statements_with_return nested_statements stmt code_block declaration_no_function conditions loops multi_assign update procedure_func_call expression_list return
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
	FUNCTION VALTYPE ID '(' parameter_list ')' '{' func_body '}'					{ $$ = mknode("FUNCTION",4,mknode($3,0),$5,mknode("TYPE",1,mknode($2,0)),$8); }
	;

procedure:
	FUNCTION VOID ID '(' parameter_list ')' '{' proc_body '}'					{ $$ = mknode("FUNCTION",4,mknode($3,0),$5,mknode("TYPE",1,mknode("VOID",0)),$8);}
	;

parameter_list:
	parameter_list_no_empty							{ $$ = $1;}
	|epsilon										{ $$ = mknode("ARGS",1,mknode("NONE",0)); }
	;

parameter_list_no_empty:
	type_list ';' parameter_list_no_empty			{ $$ = combineNodes("ARGS",$1,$3); }
	|type_list										{ $$ = $1;}
	;

type_list:	
	VALTYPE	param									{ $2->token = strdup($1); $$ = mknode("ARGS",1, $2); }
	;

param:
	ID ',' param									{ $$ = combineNodes("ARGS", mknode($1,0), $3); }
	|ID												{ $$ = mknode("ARGS",1,mknode($1,0)); }
	;

func_body:
	declarations nested_statements_with_return	{ $$ = combineNodes("BODY",$1,$2); }
	|nested_statements_with_return				{ free($1->token); $1->token =strdup("BODY"); $$=$1; }
	;

proc_body:
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

nested_statements_with_return:
	stmt nested_statements_with_return						{ $$ = combineNodes("Statments", mknode("stmt",1,$1),$2);}
	|return ';'												{ $$ = mknode("stmt",1,$1);}
	;

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
	#if YYDEBUG
        yydebug = 1;
    #endif
    yyparse();
}

/* function for parsing errors */
int yyerror(char *err){
	fflush(stdout);
    fprintf(stderr, "Error: %s at line %d\n",err, yylineno);
	fprintf(stderr, "does not accept '%s'\n",yytext);
	return 0;
}
int yywrap(){
	return 1;
}
/* function to crete a parsing tree node */
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

/* fnuction to combine two nodes under father node */
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

/* function to print tree recursively */
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
/* function to print a tabs */
void printTabs(int a) {
	for (a; a > 0; a--) {
		printf("\t");
	}
}

/* function to print tree recursively */
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

/* function to make a symbol table representation of function */ 
func *mkfunc(char *name, int type, int numOfArgs, int *args) {
	func *newfunc = (func*)malloc(sizeof(func));
	newfunc->name = strdup(name);
	newfunc->type = type; //int representation of type
	newfunc->numOfArgs = numOfArgs; 
	newfunc->args = args; // list of int representation of argument (int x,y => [2,2])
	return newfunc;
}

/* function to get number of args from node with token ARGS */
int numOfArgs(node *tree) {
	int numOfArgs = 0;
	for (int i = 0; i < tree->numOfSubNodes; i++)
		numOfArgs += tree->subNodes[i]->numOfSubNodes;
	return numOfArgs;
}

/* function to get list of int representation of argument from node with token ARGS */
int *argumentRep(node *tree) {
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

/* function to get int representation string type */
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
	else if (strcmp(string, "VOID") == 0)
		return -1;
}
/*--------------------------------------------------------------create variable representation----------------------------------------------*/

/* function to make a symbol table representation of variable */
var *mkvar(char *name, int type) {
	var *newvar = (var*)malloc(sizeof(var));
	newvar->name = strdup(name);
	newvar->type = type;
	return newvar;
}

/* function to add node with token VAR to symbol table */
void insertVar(table *stable, node *tree, node* fullTree) {
	int type = getTypeVal(tree->subNodes[0]->token); //get type of variable
	for (int i = 1; i < tree->numOfSubNodes; i++) {
		/* variable with no assign */
		if (tree->subNodes[i]->subNodes == NULL) {
			/* check var wasnt declared already */
			if (checkDupVar(stable, tree->subNodes[i]->token)) 
				addVar(stable, mkvar(tree->subNodes[i]->token, type)); //add var to symbol table
			/* var was declared already */
			else {
				printf("Error: Duplicate variable name - %s\n", tree->subNodes[i]->token);
				quitProgram(fullTree, stable);
			}
		}
		/* variable with assign */
		else {
			/* if left side type is not as right side type */
			if (type != evalExp(tree->subNodes[i]->subNodes[1], stable, tree)) {
				printf("Error: Incompatible assignment - %s\n", tree->subNodes[i]->subNodes[0]->token);
				quitProgram(tree, stable);
			}
			/* check var wasnt declared already */
			if (checkDupVar(stable, tree->subNodes[i]->subNodes[0]->token))
				addVar(stable, mkvar(tree->subNodes[i]->subNodes[0]->token, type));
			/* var was declared already */
			else {
				printf("Error: Duplicate variable name - %s\n", tree->subNodes[i]->subNodes[0]->token);
				quitProgram(fullTree, stable);
			}

		}
	}
}

/* function to add node with token STRING to symbol table */
void insertString(table *stable, node *tree, node* fullTree) {
	int type = getTypeVal(tree->token);
	for (int i = 0; i < tree->numOfSubNodes; i++) {
		/* variable with assign */
		if (strcmp("=", tree->subNodes[i]->token) == 0) {
			/* if index is not int */
			if(tree->subNodes[i]->subNodes[0]->numOfSubNodes !=0 && evalExp( tree->subNodes[i]->subNodes[0]->subNodes[0], stable, tree) != 2 ){
				printf("Error: %s Index must be int\n", tree->subNodes[0]->subNodes[0]->token);
				quitProgram(tree, stable);
			}
			/* check string wasnt declared already */
			if (checkDupVar(stable, tree->subNodes[i]->subNodes[0]->token))
				addVar(stable, mkvar(tree->subNodes[i]->subNodes[0]->token, type));
			/* string was declared already */
			else {
				printf("Error: Duplicate variable name - %s\n", tree->subNodes[i]->subNodes[0]->token);
				quitProgram(fullTree, stable);
			}
		}
		/* variable with no assign */
		else {
			/* if index is not int */
			if(tree->subNodes[i]->numOfSubNodes !=0 && evalExp( tree->subNodes[i]->subNodes[0], stable, tree) != 2 ){
				printf("Error: %s Index must be int\n", tree->subNodes[i]->token);
				quitProgram(tree, stable);
			}
			/* check string wasnt declared already */
			if (checkDupVar(stable, tree->subNodes[i]->token))
				addVar(stable, mkvar(tree->subNodes[i]->token, type));
			/* string was declared already */
			else {
				printf("Error: Duplicate variable name - %s\n", tree->subNodes[i]->token);
				quitProgram(fullTree, stable);
			}
		}
	}
}

/* function to add node with token ARGS to symbol table */
void insertArgs(table *stable, node *tree, node* fullTree) {
	for (int i = 0; i < tree->numOfSubNodes; i++) {
		int type = getTypeVal(tree->subNodes[i]->token);
		for (int j = 0; j < tree->subNodes[i]->numOfSubNodes; j++) {
			/* check var wasnt declared already */
			if (checkDupVar(stable, tree->subNodes[i]->subNodes[j]->token))
				addVar(stable, mkvar(tree->subNodes[i]->subNodes[j]->token, type));
			/* var was declared already */
			else {
				printf("Error: Duplicate variable name - %s\n", tree->subNodes[i]->subNodes[j]->token);
				quitProgram(fullTree, stable);
			}
		}
	}
}

/*------------------------------------------------Build Envirments---------------------------------------------------------*/

/* function to make a symbol table */
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

/* function to add function representation to a symbol table */
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

/* function to add variable representation to a symbol table */
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
	/* function to strart semantic check 
		tree: parsing tree
	*/

	/* create global environment with no upper environment*/
	table *global = mktable(NULL,-1);

	/* send parsing tree to semantic check */
	checkTree(tree, global,tree);

	/* check if parsing tree has no main */
	if(numOfmains==0){
		printf("Error: no main function\n");
		quitProgram(tree, global);
	}
}

void checkTree(node *subTree , table *env, node *tree) {
	/* function to check each node in parsing tree for semantic errors 
		tree: full parsing tree
		subTree: partial parsing tree that we are currently working on
		env: are symbol table (environment)
	*/

	/* if tree is nothing than no semantic errors */
	if (subTree == NULL) {
		return;
	}

	/* node with the value CODE means glogal environment
		need to send each function to semantic check
	*/
	else if (!strcmp(subTree->token, "CODE")) {
		for (int i = 0; i < subTree->numOfSubNodes; i++) {
			checkTree(subTree->subNodes[i], env, tree);
		}
	}

	/* node with the value FUNCTION
		need to check for dupliacte name in environment, open new environment and add function argument
		to environment. also we need to check all main limitations
	*/
	else if (!strcmp(subTree->token, "FUNCTION")) {
		/* if function id is main */
		if (!strcmp(subTree->subNodes[0]->token,"main")) {
			/* check dupliacte main */
			if (!checkFuncExist(env,"main")) {
				printf("Error: main can only used once\n");
				quitProgram(tree, env);
			}
			/* check main has type void */	
			else if (strcmp(subTree->subNodes[2]->subNodes[0]->token, "VOID")) {
				printf("Error: main type can only be void\n");
				quitProgram(tree, env);
			}
			/* check main has no arguments */
			else if (numOfArgs(subTree->subNodes[1]) != 0) {
				printf("Error: main cannot have arguments\n");
				quitProgram(tree, env);
			}

			/* add to main count to check main exist */
			numOfmains += 1;
		}
		/* if not main check dupliate function name */ 
		else if (!checkDupFunc(env, subTree->subNodes[0]->token)){
			printf("Error: Duplicate function name - %s\n", subTree->subNodes[0]->token);
			quitProgram(tree, env);
		}
		/* create new environment for function code and send function body for semantic check after recursive return 
			delete function environment and continue with current environment
		*/	
		func *func = mkfunc(subTree->subNodes[0]->token, getTypeVal(subTree->subNodes[2]->subNodes[0]->token), numOfArgs(subTree->subNodes[1]), argumentRep(subTree->subNodes[1]));
		addFunc(env, func);
		table *newEnv = mktable(env, getTypeVal(subTree->subNodes[2]->subNodes[0]->token));
		insertArgs(newEnv, (subTree->subNodes[1]), tree);
		checkTree(subTree->subNodes[3], newEnv, tree);
		freeTable(newEnv);
	}
	
	/* node with the value BLOCK
		need to open new environment and check block code with new environment.
		after recursive return delete block environment and continue with current environment.
	*/
	else if (!strcmp(subTree->token, "BLOCK")) {
		table *newEnv = mktable(env, 8);
		for (int i = 0; i < subTree->numOfSubNodes; i++) {
			checkTree(subTree->subNodes[i], newEnv, tree);
		}
		freeTable(newEnv);
	}

	/* node with the value BODY
		need to check BODY code with current environment.
	*/
	else if (!strcmp(subTree->token, "BODY")) {
		for (int i = 0; i < subTree->numOfSubNodes; i++) {
			checkTree(subTree->subNodes[i], env, tree);
		}
	}

	/* node with the value VAR
		need to insert variable to current environment.
	*/
	else if (!strcmp(subTree->token, "VAR")) {
		insertVar(env, subTree, tree);
	}

	/* node with the value VAR
		need to insert string to current environment.
	*/
	else if (!strcmp(subTree->token, "STRING")) {
		insertString(env, subTree, tree);
	}

	/* node with the value IF
		need to check if condition is bool and send code to check semantic tree.
	*/
	else if (!strcmp(subTree->token, "IF")) {
		if (evalExp(subTree->subNodes[0], env, tree) != 0) {
			printf("Error: Incompatible expression in \"if\" expected bool\n");
			quitProgram(tree, env);
		}
		checkTree(subTree->subNodes[1], env, tree);
	}

	/* node with the value IF-ELSE
		need to check if condition is bool and send if code and else code to check semantic tree.
	*/
	else if (!strcmp(subTree->token, "IF-ELSE")) {
		if (evalExp(subTree->subNodes[0], env, tree) != 0) {
			printf("Error: Incompatible expression in \"if-else\" expected bool\n");
			quitProgram(tree, env);
		}
		checkTree(subTree->subNodes[1], env, tree);
		checkTree(subTree->subNodes[2], env, tree);
	}
	
	/* node with the value WHILE
		need to check if condition is bool and send while code check semantic tree.
	*/
	else if (!strcmp(subTree->token, "WHILE")) {
		if (evalExp(subTree->subNodes[0], env, tree) != 0) {
			printf("Error: Incompatible expression in \"while\" expected bool\n");
			quitProgram(tree, env);
		}
		checkTree(subTree->subNodes[1], env, tree);
	}

	/* node with the value DO-WHILE
		need to check if condition is bool and send do-while code check semantic tree.
	*/
	else if (!strcmp(subTree->token, "DO-WHILE")) {
		if (evalExp(subTree->subNodes[0], env, tree) != 0) {
			printf("Error: Incompatible expression in \"do while\" expected bool\n");
			quitProgram(tree, env);
		}
		checkTree(subTree->subNodes[1], env, tree);
	}

	/* node with the value FOR
		need to send each element from for loop to check semantic tree.
	*/
	else if (!strcmp(subTree->token, "FOR")) {
		for (int i = 0; i < subTree->numOfSubNodes; i++)
			checkTree(subTree->subNodes[i], env, tree);
	}
	
	/* node with the value INIT
		need to send each element from for init to check semantic tree.
	*/
	else if (!strcmp(subTree->token, "INIT")) {
		for (int i = 0; i < subTree->numOfSubNodes; i++) {
			checkTree(subTree->subNodes[i], env, tree);
		}
	}

	/* node with the value COND
		need to check for condition is bool.
	*/
	else if (!strcmp(subTree->token, "COND")) {
		if (evalExp(subTree->subNodes[0], env, tree) != 0) {
			printf("Error: Incompatible expression in \"for\" expected bool\n");
			quitProgram(tree, env);
		}
	}
	
	/* node with the value UPDATE
		need to send each element from for update to check semantic tree.
	*/
	else if (!strcmp(subTree->token, "UPDATE")) {
		for (int i = 0; i < subTree->numOfSubNodes; i++) {
			checkTree(subTree->subNodes[i],env,tree);
		}
	}

	/* node with the value FUNC-CALL
		need to check function call semantics with help from funcCallCheck function.
	*/
	else if (!strcmp(subTree->token, "FUNC-CALL")) {
		if (!funcCallCheck(subTree, env)) {
			quitProgram(tree, env);
		}
	}

	/* node with the value RET
		need to check return semantics with help from checkReturnValk function.
	*/
	else if (!strcmp(subTree->token, "RET")) {
		if (!checkReturnVal(subTree, env,tree)) {
			printf("Error: Incompatible return type\n");
			quitProgram(tree, env);
		}
	}

	/* node with the value =
		need to check 
	*/
	else if (!strcmp(subTree->token, "=")) {
		/* if left side of = doesnt exsist */
		if (!checkVarExist(env, subTree->subNodes[0]->token)) {
			printf("Error: Variable used before declaration - %s\n", subTree->subNodes[0]->token);
			quitProgram(tree, env);
		}

		/* if left side is pointer and right is null */
		if(evalExp(subTree->subNodes[1], env, tree) == 8 && (getVarType(env, subTree->subNodes[0]->token)==4 || getVarType(env, subTree->subNodes[0]->token)==5 || getVarType(env, subTree->subNodes[0]->token)==6))
			return;
		
		/* if left side is string */
		if(getVarType(env, subTree->subNodes[0]->token) == 7){
			/* if index is not int */
			if(subTree->subNodes[0]->numOfSubNodes !=0 && evalExp(subTree->subNodes[0]->subNodes[0], env, tree) != 2 ){
				printf("Error: %s Index must be int\n", subTree->subNodes[0]->token);
				quitProgram(tree,env);
			}
			/* if left side str index and index is int str and right side is char example: str[0] = 'c' */
			if(subTree->subNodes[0]->numOfSubNodes !=0 && evalExp(subTree->subNodes[0]->subNodes[0], env, tree) == 2 && evalExp(subTree->subNodes[1], env, tree) == 1)
				return;
		}

		/* if left side is not string and trying to index*/
		if(getVarType(env, subTree->subNodes[0]->token) != 7 && subTree->subNodes[0]->numOfSubNodes!=0){
			printf("Error: %s has no Index operator\n", subTree->subNodes[0]->token);
			quitProgram(tree, env);
		}
		/* if left side type is not as right side type */
		if (getVarType(env, subTree->subNodes[0]->token) != evalExp(subTree->subNodes[1], env, tree)) {
			printf("Error: Incompatible assignment - %s\n", subTree->subNodes[0]->token);
			quitProgram(tree, env);
		}	
	}
	
	//del at end
	else {
		printf("%s\n", subTree->token);
	}
}

/* function to evaluate expression type */
int evalExp(node *subTree, table* stable, node *tree) {
	/* if node token is + , - with pointer */
	if(!strcmp("+", subTree->token) || !strcmp("-", subTree->token)){
		int type1 = evalExp(subTree->subNodes[0], stable, tree); /* first node type */
		int type2 = evalExp(subTree->subNodes[1], stable, tree); /* second node type */

		/* check pointer and int  */
		if( type1 >= 4 && type1 <= 7 && type2 == 2){
			return type1;
		}

		/* check pointer and int  */
		if( type2 >= 4 && type2 <= 7 && type1 == 2){
			return type2;
		}
	}

	/* if node token is + , - , * , / */
	if (!strcmp("+", subTree->token) || !strcmp("-", subTree->token) || !strcmp("*", subTree->token) || !strcmp("/", subTree->token)) {
		int type1 = evalExp(subTree->subNodes[0], stable, tree); /* first node type */
		int type2 = evalExp(subTree->subNodes[1], stable, tree); /* second node type */

		/* check if type1 is real or int */
		if (type1 == 2 || type1 == 3) {
			/* check if type1 is real or int */
			if (type2 == 2 || type2 == 3) {
				/* if both types are int int = 2 2+2 = 4  return int = 2 */ 
				if (type1 + type2 == 4)
					return 2;
				/* if one type is int and second is real return real = 3 */ 
				else
					return 3;
			}
			/* type2 is not real or int*/
			else {
				printf("Error: unsupported operand types %s\n", subTree->token);
				quitProgram(tree, stable);
			}
		}
		/* type1 is not real or int*/
		else {
			printf("Error: unsupported operand types %s\n", subTree->token);
			quitProgram(tree, stable);
		}
	}

	/* if node token is && || */
	if (!strcmp("&&", subTree->token) || !strcmp("||", subTree->token)) {
		int type1 = evalExp(subTree->subNodes[0], stable, tree); /* first node type */
		int type2 = evalExp(subTree->subNodes[1], stable, tree); /* second node type */

		/* check if type1 or type2 is not bool */
		if (type1 != 0 || type2 != 0) {
			printf("Error: unsupported operand types %s\n", subTree->token);
			quitProgram(tree, stable);
		}
		/* return bool */
		return 0;
	}

	/* if node token is == != */
	if (!strcmp("==", subTree->token) || !strcmp("!=", subTree->token)) {
		int type1 = evalExp(subTree->subNodes[0], stable, tree); /* first node type */
		int type2 = evalExp(subTree->subNodes[1], stable, tree); /* second node type */
		/* check if type1 and type2 same type and comparable */
		if (type1 == type2 && type2 <= 6 && type2>=0 ) 
			return 0;
		/* type1 and type2 not the same type or not comparable */
		else {
			printf("Error: unsupported operand types %s\n", subTree->token);
			quitProgram(tree, stable);
		}
	}

	/* if node token is > >= <= < */
	if (!strcmp(">", subTree->token) || !strcmp(">=", subTree->token) || !strcmp("<", subTree->token) || !strcmp("<=", subTree->token)) {
		int type1 = evalExp(subTree->subNodes[0], stable, tree); /* first node type */
		int type2 = evalExp(subTree->subNodes[1], stable, tree); /* second node type */
		/* check if type1 is real or int */
		if (type1 == 2 || type1 == 3) {
			/* check if type1 is real or int */
			if (type2 == 2 || type2 == 3) {
				/* return bool */
				return 0;
			}
			/* type2 is not real or int*/
			else {
				printf("Error: unsupported operand types %s\n", subTree->token);
				quitProgram(tree, stable);
			}
		}
		/* type1 is not real or int*/
		else {
			printf("Error: unsupported operand types %s\n", subTree->token);
			quitProgram(tree, stable);
		}
	}

	/* if node token is ! */
	if (!strcmp("!", subTree->token)) {
		int type1 = evalExp(subTree->subNodes[0], stable, tree); /* first node type */
		/* check if type1 is not bool */
		if (type1 != 0) {
			printf("Error: unsupported operand types %s\n", subTree->token);
			quitProgram(tree, stable);
		}
		/*return bool */
		return 0;
	}

	/* if node token is STR-LEN */
	if (!strcmp("STR-LEN", subTree->token)) {
		/* if variable is not string - no len */
		if (getVarType(stable, subTree->subNodes[0]->token) != 7) {
			printf("Error: unsupported operand types | str |\n");
			quitProgram(tree, stable);
		}
		/* return int */
		return 2;
	}

	/* if node token is POINTER - acsse to pointer */
	if (!strcmp("POINTER", subTree->token)) {
		int type1 = evalExp(subTree->subNodes[0], stable, tree); /* first node type */
		
		/* type is char* */
		if (type1==4)
			/* return char */
			return 1;
		
		/* type is real* */
		if(type1==5)
			/* return real */
			return 3;
		
		/* type is int* */
		if(type1==6)
			/* return int */
			return 2;

		/*not a pointer */
		else {
			printf("Error: unsupported operand types %s\n", subTree->token);
			quitProgram(tree, stable);
		}
	}

	/* if node token is ADDRESS-OF*/
	if (!strcmp("ADDRESS-OF", subTree->token)) {
		int type1 = evalExp(subTree->subNodes[0], stable, tree); /* first node type */

		/* type is char* */
		if (type1 == 1 ) {
			/* return char* */
			return 4;
		}

		/* type is int */
		else if (type1 == 2) {
			/* return int* */
			return 6;
		}

		/* type is real */
		else if (type1 == 3) {
			/* return real* */
			return 5;
		}

		/* if type is not addres compatable */
		else {
			printf("Error: unsupported operand types %s\n", subTree->token);
			quitProgram(tree, stable);
		}

	}

	/* if node token is FUNC-CALL*/
	if (!strcmp("FUNC-CALL", subTree->token)) {
		/* check func call is correct */
		if (!funcCallCheck(subTree, stable)) {
			quitProgram(tree, stable);
		}
		/* return function type */ 
		return getFuncType(stable, subTree->subNodes[0]->token);
	}

	/* node can be variable or const */
	else {
		/* if node is types 0-6 or null = 8 */
		if ((getVarType(stable, subTree->token) <= 6 && getVarType(stable, subTree->token)>=0) || getVarType(stable, subTree->token) == 8){
			/* if node has attemp to index */
			if(subTree->numOfSubNodes!=0 && subTree->subNodes[0] != NULL  && !isValue(subTree->token)){
				printf("Error: %s has no Index operator\n", subTree->token);
				quitProgram(tree, stable);
			}
			/* return var type */
			return getVarType(stable, subTree->token);
		}

		/* if node is string */
		else if (getVarType(stable, subTree->token) == 7) {
			/* if string has index */
			if(subTree -> numOfSubNodes != 0){
				/* check index is int */
				if (evalExp(subTree->subNodes[0], stable, tree) != 2) {
					printf("Error:  %s Index must be int\n", subTree->subNodes[0]->token);
					quitProgram(tree, stable);
				}
				/* return char = 1 */
				return 1;
			}
			/* return string = 7 */
			return 7;
		}
		/* variable doesnt exist */
		else {
			printf("Error: variable %s does not exist\n", subTree->token);
			quitProgram(tree, stable);
		}	
	}
}


/* function to function exist already */
bool checkDupFunc(table *stable, char *name) {
	for (int i = 0; i < stable->numOfFunction; i++) {
		/* function exist */
		if (!strcmp(stable->functions[i]->name, name)) {
			return false;
		}
	}
	/* function doesnt exist */
	return true;
}

/* function to var exist already */
bool checkDupVar(table *stable, char *name) {
	for (int i = 0; i < stable->numOfvariables; i++) {
		/* var exist */
		if (!strcmp(stable->variables[i]->name, name)) {
			return false;
		}
	}
	/* var doesnt exist */
	return true;
}

/* function check if function exist */
bool checkFuncExist(table *env, char *name) {
	/* search function in environments */
	table *temp = env;
	while (temp != NULL) {
		/* if function exist */
		if (!checkDupFunc(temp, name))
			return false;
		temp = temp->upperEnv;
	}
	/* if function doesnt exist */
	return true;
}

/* function to quit program and free memory if not valid */
void quitProgram(node *tree, table *env) {
	freeTree(tree);
	freeAllTables(env);
	getchar();
	exit(1);
}

/* function to to check semantics of node with FUNC-CALL */
bool funcCallCheck(node* tree, table *env) {
	/* check if function name exist */
	if (checkFuncExist(env, tree->subNodes[0]->token)) {
		printf("Error: calling function %s that does not exist\n", tree->subNodes[0]->token);
		return false;
	}
	/* check number of arfument in call is correct */
	int numOfarguments = tree->numOfSubNodes;
	for(int i=0; i<tree->numOfSubNodes; i++){
		if(!strcmp("NONE", tree->subNodes[i]->token))
			numOfarguments -= 1;
	}
	if (getFuncNumOfArgs(tree->subNodes[0]->token, env) != numOfarguments - 1) {
		printf("Error: number of arguments does not match calling function %s\n", tree->subNodes[0]->token);
		return false;
	}

	/* check if all function call argument exist or are values */
	for(int i=1; i<tree->numOfSubNodes;i++){
		if(strcmp("NONE",tree->subNodes[i]->token) !=0 ){
			if (!checkVarExist(env, tree->subNodes[i]->token)) {
				printf("Error: variable %s does not exist\n", tree->subNodes[i]->token);
				return false;
			}	
		}
	}
	/* check if all function call argument are correct type to function */
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

/* function to to get function number of args - function exist */
int getFuncNumOfArgs(char* name, table *env) {
	/* search function  number of args in environments */
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

/* function to to get function args representation list - function exist */
int* getFuncArgsTypes(char* name, table *env) {
	/* search function representation list in environments */
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

/* function to to get function type or -1 if doesnt exist*/
int getFuncType(table *env, char *name) {
	/* search function type in environments */
	table *temp = env;
	while (temp != NULL) {
		for (int i = 0; i < temp->numOfFunction; i++) {
			if (!strcmp(name, temp->functions[i]->name)) {
				return temp->functions[i]->type;
			}
		}
		temp = temp->upperEnv;
	}
	/* function doesnt exsist */
	return -1;
}

/* function to to get variable type or -1 if doesnt exist*/
int getVarType(table *env, char *id) {
	/* is value */
	if (isValue(id))
		return getTypeVal(id);

	/* search variable type in environments */
	table *temp = env;
	while (temp != NULL) {
		for (int i = 0; i < temp->numOfvariables; i++) {
			if (!strcmp(id, temp->variables[i]->name)) {
				return temp->variables[i]->type;
			}
		}
		temp = temp->upperEnv;
	}
	/* variable doesnt exsist */
	return -1;
}

/* function to check if string is value*/
bool isValue(char *id){
	/* is value */
	if (!strcmp("bool", id) || !strcmp("char", id) || !strcmp("int", id) || !strcmp("real", id) || !strcmp("null", id)) {
		return true;
	}
	/* not value */
	return false;
}

/* function to check if variable exist in environment */
bool checkVarExist(table *env, char *id) {
	/*
		env: environment
		id: variable name
	*/
	/* if variable is value */
	if (isValue(id))
		return true;

	/* check variable exist in environments */
	table *temp = env;
	while (temp != NULL) {
		for (int i = 0; i < temp->numOfvariables; i++) {
			/* variable exist in environments */
			if (!strcmp(id, temp->variables[i]->name)) {
				return true;
			}
		}
		/* go to upper environment */
		temp = temp->upperEnv;
	}
	/* variable does not exist in environments */
	return false;
}

/* function to check return type of node with token RET is correct by the environment return type */
bool checkReturnVal(node *subTree, table *env, node* tree) {
	/*
		subTree : node with token RET
		tree : full parsing tree
		env: symbol table (environment)
	*/
	/* if environment type of return is a type */
	if (env->returnType <= 6 && env->returnType >= 0) {
		/* if return type is not the same as environment */ 
		if (evalExp(subTree->subNodes[0], env, tree) != env->returnType) {
			return false;
		}
	}
	/* if environment return type is at upper environment */
	if (env->returnType == 8) {
		/* if there is a upper environment */
		if (env->upperEnv != NULL)
			return checkReturnVal(subTree, env->upperEnv, tree);
		/* return with no need for return - false */
		else
			return false;
	}
	/* if in global environment no need for return - false */
	if (env->returnType == -1) {
		return false;
	}
}

/*function to free table */
void freeTable(table *env){
	if(env == NULL ){
		return ;
	}
	/*free functions */
	for(int i=0; i< env->numOfFunction; i++){
		free(env->functions[i]->name);
		free(env->functions[i]->args);
		free(env->functions[i]);
	}
	free(env->functions);

	/*free fvariables */
	for(int i=0; i< env->numOfvariables; i++){
		free(env->variables[i]->name);
		free(env->variables[i]);
	}
	free(env->variables);

	/* free table */
	free(env);
}

/*function to free all tables */
void freeAllTables(table *env){
	table *temp = NULL;
	while(env != NULL){
		temp = env->upperEnv;
		freeTable(env);
		env = temp;
	}
}
