/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */


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

typedef struct TAC {
	char* var;
	char* code;
	char* truel;
	char* falsel;
}TAC;

/* global variables */
typedef enum bool{ false,true } bool;
int numOfmains = 0;
int varIndex = 0;
int labelIndex = 0;

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

/* 3AC */
TAC* to3AC(node *tree);
TAC* Exp3AC(node *tree);
char* getNewVarLabel();
int calcFuncCallBytes(node *tree);
char* getNewLabel();
TAC* get3acCond(node* tree, char* l1, char* l2);
TAC* get3acSimpleCond(node* tree, char* l1, char* l2);
int isBoolOp(char *token);


#line 176 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VALTYPE = 258,
    STRING = 259,
    IF = 260,
    ELSE = 261,
    WHILE = 262,
    FOR = 263,
    VAR = 264,
    FUNCTION = 265,
    RETURN = 266,
    NULLP = 267,
    VOID = 268,
    DO = 269,
    PLUS = 270,
    MINUS = 271,
    DIV = 272,
    MUL = 273,
    ASS = 274,
    AND = 275,
    EQ = 276,
    G = 277,
    GE = 278,
    L = 279,
    LE = 280,
    NOT = 281,
    NOTEQ = 282,
    OR = 283,
    ADDRESS = 284,
    BOOLVAL = 285,
    CHARVAL = 286,
    DECIMALINTVAL = 287,
    HEXINTVAL = 288,
    REALVAL = 289,
    STRINGVAL = 290,
    ID = 291,
    LOWER_THEN_ELSE = 292,
    UNARY = 293
  };
#endif
/* Tokens.  */
#define VALTYPE 258
#define STRING 259
#define IF 260
#define ELSE 261
#define WHILE 262
#define FOR 263
#define VAR 264
#define FUNCTION 265
#define RETURN 266
#define NULLP 267
#define VOID 268
#define DO 269
#define PLUS 270
#define MINUS 271
#define DIV 272
#define MUL 273
#define ASS 274
#define AND 275
#define EQ 276
#define G 277
#define GE 278
#define L 279
#define LE 280
#define NOT 281
#define NOTEQ 282
#define OR 283
#define ADDRESS 284
#define BOOLVAL 285
#define CHARVAL 286
#define DECIMALINTVAL 287
#define HEXINTVAL 288
#define REALVAL 289
#define STRINGVAL 290
#define ID 291
#define LOWER_THEN_ELSE 292
#define UNARY 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 113 "parser.y" /* yacc.c:355  */

	char *string;
	struct node *node;

#line 294 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 311 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   445

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  215

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      39,    40,     2,     2,    44,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,    47,    42,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   155,   155,   159,   160,   164,   165,   171,   175,   179,
     180,   184,   185,   189,   193,   194,   198,   199,   203,   204,
     205,   206,   210,   211,   212,   213,   214,   215,   221,   222,
     223,   224,   225,   226,   232,   233,   237,   241,   242,   243,
     244,   248,   249,   253,   254,   260,   261,   265,   266,   270,
     271,   272,   273,   274,   275,   281,   282,   283,   284,   288,
     291,   294,   297,   302,   303,   304,   305,   308,   309,   315,
     316,   322,   323,   324,   331,   332,   335,   336,   337,   343,
     346,   347,   348,   354,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   384,   385,   386,   387,   390
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VALTYPE", "STRING", "IF", "ELSE",
  "WHILE", "FOR", "VAR", "FUNCTION", "RETURN", "NULLP", "VOID", "DO",
  "PLUS", "MINUS", "DIV", "MUL", "ASS", "AND", "EQ", "G", "GE", "L", "LE",
  "NOT", "NOTEQ", "OR", "ADDRESS", "BOOLVAL", "CHARVAL", "DECIMALINTVAL",
  "HEXINTVAL", "REALVAL", "STRINGVAL", "ID", "LOWER_THEN_ELSE", "UNARY",
  "'('", "')'", "'{'", "'}'", "';'", "','", "'['", "']'", "'|'", "$accept",
  "initial", "program", "cmd", "function", "procedure", "parameter_list",
  "parameter_list_no_empty", "type_list", "param", "func_body",
  "proc_body", "declarations", "primitive_val", "declaration",
  "primitive_declaration", "declaration_parameters", "string_declaration",
  "string_parameters", "nested_statements_with_return",
  "nested_statements", "stmt", "assign", "primitive_assign",
  "index_assign", "string_assign", "pointer_assign", "code_block",
  "declaration_no_function", "conditions", "loops", "multi_assign",
  "update", "procedure_func_call", "expression_list", "return",
  "expression", "unary_op", "epsilon", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,    40,
      41,   123,   125,    59,    44,    91,    93,   124
};
# endif

#define YYPACT_NINF -154

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-154)))

#define YYTABLE_NINF -47

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,     9,    43,     0,  -154,  -154,  -154,    -6,    16,  -154,
    -154,    14,    22,    59,    59,    31,    29,  -154,    36,  -154,
      48,    66,  -154,    39,    59,    75,    31,    40,  -154,    40,
    -154,    87,    85,    88,    94,   123,   210,    95,    99,   -11,
     134,    28,    28,    98,   171,    28,  -154,  -154,   171,   101,
    -154,  -154,  -154,  -154,  -154,  -154,  -154,   104,   106,   109,
     171,  -154,   171,   112,  -154,    92,   113,   102,   210,   210,
     124,   127,  -154,  -154,  -154,  -154,  -154,   128,  -154,  -154,
    -154,  -154,  -154,    18,   210,   130,  -154,  -154,    69,   210,
     151,   150,   185,   210,   210,    10,   131,   154,   135,  -154,
    -154,  -154,  -154,  -154,  -154,  -154,  -154,   138,  -154,  -154,
    -154,  -154,   210,  -154,    87,   337,   351,   162,   139,   143,
      -8,   145,   147,   148,   210,   365,   152,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,    69,
     153,   210,  -154,    69,   158,   306,  -154,   238,  -154,  -154,
    -154,   160,  -154,   252,  -154,   171,   171,   210,   124,   210,
     127,  -154,   127,   210,   272,  -154,  -154,    24,    24,  -154,
    -154,   393,   420,   103,   103,   103,   103,   420,   407,   210,
      69,  -154,   210,   175,  -154,   186,   198,  -154,  -154,   320,
    -154,  -154,   286,  -154,   379,  -154,   210,   173,   171,   170,
    -154,   166,    69,  -154,  -154,    58,  -154,   183,  -154,   195,
     197,   171,  -154,  -154,  -154
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     3,     5,     6,     0,     0,     1,
       4,     0,     0,   109,   109,     0,     0,     9,    12,    10,
       0,    15,    13,     0,     0,     0,     0,     0,    11,   109,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,    25,    27,     0,     0,    23,    34,    17,     0,     0,
      55,    56,    57,    58,    50,    51,    52,     0,     0,     0,
      19,    20,    47,     0,    21,     0,     0,    42,     0,     0,
       0,     0,    33,   105,   106,   108,   107,     0,    28,    29,
      30,    31,    32,    98,     0,     0,    97,    99,    83,     0,
       0,     0,     0,   109,     0,    68,     0,     0,     0,    24,
      26,     7,    16,    22,    45,    49,    53,    54,     8,    18,
      48,    54,     0,    35,     0,     0,     0,     0,    75,     0,
      39,     0,    40,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
       0,     0,    61,    59,     0,    81,    82,     0,    67,    65,
      64,     0,    66,     0,    41,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,   101,   100,    84,    85,    86,
      87,    88,    90,    92,    93,    94,    95,    91,    89,     0,
      62,    79,   109,     0,    63,    43,    69,    71,    74,     0,
      37,    38,     0,   104,     0,    80,     0,     0,     0,     0,
     103,     0,    60,    44,    70,     0,    78,     0,    72,     0,
       0,     0,    76,    77,    73
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -154,  -154,  -154,   224,   111,   122,   215,   206,  -154,   205,
    -154,  -154,    30,  -154,   -39,  -154,  -144,   119,  -154,    34,
     -31,   -24,  -154,   -45,  -154,  -154,  -154,   200,   140,  -154,
    -154,  -153,  -154,   -27,    52,   -21,   -29,  -154,   -25
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    41,    42,    16,    17,    18,    22,
      43,    59,    44,    86,    45,    46,   121,    66,    67,    47,
      61,    62,    49,    50,    51,    52,    53,    54,    97,    55,
      56,   119,   207,    87,   144,    63,   143,    89,    19
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,    95,    57,    48,    64,   188,    58,    88,    92,    96,
       1,   157,     7,    57,    31,    98,   190,    57,   191,    35,
      48,    57,     8,    58,    48,   118,   122,    58,    93,   109,
      11,   110,    31,    57,    94,    57,   160,    35,     1,   115,
     116,   129,   130,     9,    31,    32,   206,    33,    34,    35,
       1,    36,    12,    13,    37,   125,    95,    93,    38,    60,
     139,    14,    15,   124,   145,   147,   151,    21,   146,    23,
      57,    99,   100,   209,   210,   103,    39,   157,   102,    24,
      27,    40,   104,   153,   127,   128,   129,   130,    25,   131,
     132,   133,   134,   135,   136,   164,   137,   138,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
      26,     5,   180,   118,     5,   122,    29,   122,   127,   128,
     129,   130,     6,    65,    68,     6,    71,    69,    57,    57,
     189,   186,   187,    70,   192,    91,    40,   112,    31,    32,
     101,    33,    34,    35,   105,    36,   114,   106,    37,   107,
     194,   108,    38,   145,   118,   111,   113,   146,   140,    32,
     117,    33,    34,   120,   123,    36,   126,   202,    37,   141,
      39,    57,    38,   149,   204,    40,    32,   152,    33,    34,
     -46,   157,    36,   158,    57,    37,   159,   214,   161,    38,
      39,   162,   179,   163,   196,    40,   150,    72,   181,   166,
      73,    74,   184,    75,   198,   197,   205,    39,   203,   208,
     212,    76,    40,   213,    77,    78,    79,    80,    81,    82,
     142,    83,    72,   211,    84,    73,    74,    10,    75,    20,
      28,    30,    85,   154,   195,   148,    76,    90,     0,    77,
      78,    79,    80,    81,    82,     0,    83,     0,     0,    84,
       0,     0,     0,   127,   128,   129,   130,    85,   131,   132,
     133,   134,   135,   136,     0,   137,   138,   127,   128,   129,
     130,     0,   131,   132,   133,   134,   135,   136,     0,   137,
     138,     0,     0,     0,   183,     0,     0,   127,   128,   129,
     130,     0,   131,   132,   133,   134,   135,   136,   185,   137,
     138,   127,   128,   129,   130,     0,   131,   132,   133,   134,
     135,   136,     0,   137,   138,     0,     0,     0,   193,     0,
       0,   127,   128,   129,   130,     0,   131,   132,   133,   134,
     135,   136,   200,   137,   138,   127,   128,   129,   130,     0,
     131,   132,   133,   134,   135,   136,     0,   137,   138,     0,
     182,     0,   127,   128,   129,   130,     0,   131,   132,   133,
     134,   135,   136,   199,   137,   138,   127,   128,   129,   130,
       0,   131,   132,   133,   134,   135,   136,   155,   137,   138,
     127,   128,   129,   130,     0,   131,   132,   133,   134,   135,
     136,   156,   137,   138,   127,   128,   129,   130,     0,   131,
     132,   133,   134,   135,   136,   165,   137,   138,   127,   128,
     129,   130,     0,     0,   132,   133,   134,   135,   136,   201,
     137,   138,   127,   128,   129,   130,     0,     0,   132,   133,
     134,   135,   136,     0,   137,   127,   128,   129,   130,     0,
       0,     0,   133,   134,   135,   136
};

static const yytype_int16 yycheck[] =
{
      27,    40,    29,    27,    29,   158,    27,    36,    19,    40,
      10,    19,     3,    40,     4,    40,   160,    44,   162,     9,
      44,    48,    13,    44,    48,    70,    71,    48,    39,    60,
      36,    62,     4,    60,    45,    62,    44,     9,    10,    68,
      69,    17,    18,     0,     4,     5,   199,     7,     8,     9,
      10,    11,    36,    39,    14,    84,    95,    39,    18,    29,
      89,    39,     3,    45,    93,    94,    97,    36,    93,    40,
      97,    41,    42,    15,    16,    45,    36,    19,    44,    43,
      41,    41,    48,   112,    15,    16,    17,    18,    40,    20,
      21,    22,    23,    24,    25,   124,    27,    28,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
      44,     0,   141,   158,     3,   160,    41,   162,    15,    16,
      17,    18,     0,    36,    39,     3,     3,    39,   155,   156,
     159,   155,   156,    39,   163,    36,    41,    45,     4,     5,
      42,     7,     8,     9,    43,    11,    44,    43,    14,    43,
     179,    42,    18,   182,   199,    43,    43,   182,     7,     5,
      36,     7,     8,    36,    36,    11,    36,   196,    14,    19,
      36,   198,    18,    42,   198,    41,     5,    42,     7,     8,
      42,    19,    11,    44,   211,    14,    43,   211,    43,    18,
      36,    44,    39,    45,    19,    41,    42,    12,    40,    47,
      15,    16,    42,    18,     6,    19,    36,    36,    35,    43,
      15,    26,    41,    16,    29,    30,    31,    32,    33,    34,
      35,    36,    12,    40,    39,    15,    16,     3,    18,    14,
      24,    26,    47,   114,   182,    95,    26,    37,    -1,    29,
      30,    31,    32,    33,    34,    -1,    36,    -1,    -1,    39,
      -1,    -1,    -1,    15,    16,    17,    18,    47,    20,    21,
      22,    23,    24,    25,    -1,    27,    28,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    24,    25,    -1,    27,
      28,    -1,    -1,    -1,    46,    -1,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    24,    25,    46,    27,
      28,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      24,    25,    -1,    27,    28,    -1,    -1,    -1,    46,    -1,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      24,    25,    46,    27,    28,    15,    16,    17,    18,    -1,
      20,    21,    22,    23,    24,    25,    -1,    27,    28,    -1,
      44,    -1,    15,    16,    17,    18,    -1,    20,    21,    22,
      23,    24,    25,    43,    27,    28,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    24,    25,    40,    27,    28,
      15,    16,    17,    18,    -1,    20,    21,    22,    23,    24,
      25,    40,    27,    28,    15,    16,    17,    18,    -1,    20,
      21,    22,    23,    24,    25,    40,    27,    28,    15,    16,
      17,    18,    -1,    -1,    21,    22,    23,    24,    25,    40,
      27,    28,    15,    16,    17,    18,    -1,    -1,    21,    22,
      23,    24,    25,    -1,    27,    15,    16,    17,    18,    -1,
      -1,    -1,    22,    23,    24,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    49,    50,    51,    52,    53,     3,    13,     0,
      51,    36,    36,    39,    39,     3,    54,    55,    56,    86,
      54,    36,    57,    40,    43,    40,    44,    41,    55,    41,
      57,     4,     5,     7,     8,     9,    11,    14,    18,    36,
      41,    52,    53,    58,    60,    62,    63,    67,    69,    70,
      71,    72,    73,    74,    75,    77,    78,    81,    83,    59,
      60,    68,    69,    83,    86,    36,    65,    66,    39,    39,
      39,     3,    12,    15,    16,    18,    26,    29,    30,    31,
      32,    33,    34,    36,    39,    47,    61,    81,    84,    85,
      75,    36,    19,    39,    45,    62,    68,    76,    86,    60,
      60,    42,    67,    60,    67,    43,    43,    43,    42,    68,
      68,    43,    45,    43,    44,    84,    84,    36,    71,    79,
      36,    64,    71,    36,    45,    84,    36,    15,    16,    17,
      18,    20,    21,    22,    23,    24,    25,    27,    28,    84,
       7,    19,    35,    84,    82,    84,    86,    84,    76,    42,
      42,    68,    42,    84,    65,    40,    40,    19,    44,    43,
      44,    43,    44,    45,    84,    40,    47,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    39,
      84,    40,    44,    46,    42,    46,    69,    69,    79,    84,
      64,    64,    84,    46,    84,    82,    19,    19,     6,    43,
      46,    40,    84,    35,    69,    36,    79,    80,    43,    15,
      16,    40,    15,    16,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    52,    53,    54,
      54,    55,    55,    56,    57,    57,    58,    58,    59,    59,
      59,    59,    60,    60,    60,    60,    60,    60,    61,    61,
      61,    61,    61,    61,    62,    62,    63,    64,    64,    64,
      64,    65,    65,    66,    66,    67,    67,    68,    68,    69,
      69,    69,    69,    69,    69,    70,    70,    70,    70,    71,
      72,    73,    74,    75,    75,    75,    75,    76,    76,    77,
      77,    78,    78,    78,    79,    79,    80,    80,    80,    81,
      82,    82,    82,    83,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    85,    85,    85,    85,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     9,     9,     1,
       1,     3,     1,     2,     3,     1,     2,     1,     2,     1,
       1,     1,     2,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     3,     1,
       1,     3,     1,     4,     6,     2,     2,     1,     2,     2,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     3,
       6,     3,     4,     4,     3,     3,     3,     2,     1,     5,
       7,     5,     7,     9,     3,     1,     3,     3,     1,     4,
       3,     1,     1,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     1,     1,     1,
       3,     3,     2,     5,     4,     1,     1,     1,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 155 "parser.y" /* yacc.c:1646  */
    {  startSemantics((yyvsp[0].node)); printTree((yyvsp[0].node),0); to3AC((yyvsp[0].node)); freeTree((yyvsp[0].node));}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 159 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("CODE",1, (yyvsp[0].node)); }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("CODE",(yyvsp[-1].node), mknode("CODE",1,(yyvsp[0].node))); }
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 164 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 165 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 171 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("FUNCTION",4,mknode((yyvsp[-6].string),0),(yyvsp[-4].node),mknode("TYPE",1,mknode((yyvsp[-7].string),0)),(yyvsp[-1].node)); }
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 175 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("FUNCTION",4,mknode((yyvsp[-6].string),0),(yyvsp[-4].node),mknode("TYPE",1,mknode("VOID",0)),(yyvsp[-1].node));}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 180 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("ARGS",1,mknode("NONE",0)); }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 184 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("ARGS",(yyvsp[-2].node),(yyvsp[0].node)); }
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 185 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 189 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0].node)->token = strdup((yyvsp[-1].string)); (yyval.node) = mknode("ARGS",1, (yyvsp[0].node)); }
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 193 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("ARGS", mknode((yyvsp[-2].string),0), (yyvsp[0].node)); }
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 194 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("ARGS",1,mknode((yyvsp[0].string),0)); }
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 198 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("BODY",(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 199 "parser.y" /* yacc.c:1646  */
    { free((yyvsp[0].node)->token); (yyvsp[0].node)->token =strdup("BODY"); (yyval.node)=(yyvsp[0].node); }
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 203 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("BODY",(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 204 "parser.y" /* yacc.c:1646  */
    { free((yyvsp[0].node)->token); (yyvsp[0].node)->token=strdup("BODY"); (yyval.node)=(yyvsp[0].node); }
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 205 "parser.y" /* yacc.c:1646  */
    { free((yyvsp[0].node)->token); (yyvsp[0].node)->token =strdup("BODY"); (yyval.node)=(yyvsp[0].node); }
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 206 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("BODY",1,mknode("NONE",0)); }
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 210 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("BODY",mknode("BODY",1,(yyvsp[-1].node)),(yyvsp[0].node)); }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 211 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("BODY",1,(yyvsp[0].node)); }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("BODY",mknode("BODY",1,(yyvsp[-1].node)),(yyvsp[0].node)); }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 213 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("BODY",1,(yyvsp[0].node)); }
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 214 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("BODY",mknode("BODY",1,(yyvsp[-1].node)),(yyvsp[0].node)); }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 215 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("BODY",1,(yyvsp[0].node)); }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 221 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("bool",1,mknode((yyvsp[0].string),0)); }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("char",1,mknode((yyvsp[0].string),0)); }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 223 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("int",1,mknode((yyvsp[0].string),0)); }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 224 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("int",1,mknode((yyvsp[0].string),0)); }
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 225 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("real",1,mknode((yyvsp[0].string),0)); }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 226 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("null",1,mknode("0",0)); }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 232 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 233 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 237 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("VAR", mknode("VAR",1,mknode((yyvsp[-2].string),0)), (yyvsp[-1].node)); }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 241 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("VAR", mknode("VAR",1,mknode((yyvsp[-2].string),0)), (yyvsp[0].node)); }
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 242 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("VAR", mknode("ASS",1,(yyvsp[-2].node)) ,(yyvsp[0].node)); }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 243 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[0].string),0); }
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 244 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("ASS",1,(yyvsp[0].node)); }
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 248 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("STRING", (yyvsp[-2].node), (yyvsp[0].node));}
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 249 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 253 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("STRING",1,mknode((yyvsp[-3].string),1,(yyvsp[-1].node))); }
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 254 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("STRING",1,mknode((yyvsp[-1].string),2,mknode((yyvsp[-5].string),1,(yyvsp[-3].node)),mknode((yyvsp[0].string),0))); }
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 260 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("Statments", mknode("stmt",1,(yyvsp[-1].node)),(yyvsp[0].node));}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 261 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("stmt",1,(yyvsp[-1].node));}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 265 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("stmt",1,(yyvsp[0].node)); }
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 266 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("Statments", mknode("stmt",1,(yyvsp[-1].node)),(yyvsp[0].node));}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 270 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 271 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 272 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 273 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 274 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 275 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 281 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 282 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 283 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 284 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 288 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2, mknode((yyvsp[-2].string),0), (yyvsp[0].node)); }
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 291 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,mknode((yyvsp[-5].string),1,(yyvsp[-3].node)),(yyvsp[0].node)); }
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 294 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,mknode((yyvsp[-2].string),0),mknode((yyvsp[0].string),0)); }
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 297 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string), 2 , mknode("POINTER", 1, mknode((yyvsp[-2].string),0)), (yyvsp[0].node)); }
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 302 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("BLOCK",(yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 303 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 304 "parser.y" /* yacc.c:1646  */
    {free((yyvsp[-1].node)->token); (yyvsp[-1].node)-> token = strdup("BLOCK"); (yyval.node) = (yyvsp[-1].node); }
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 305 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("BLOCK",1,mknode("NONE",0)); }
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 308 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("BLOCK", mknode("BLOCK",1,(yyvsp[-1].node)), (yyvsp[0].node));}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 309 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("BLOCK", 1, (yyvsp[0].node));}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 315 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("IF", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 316 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("IF-ELSE", 3, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 322 "parser.y" /* yacc.c:1646  */
    { (yyval.node) =	mknode("WHILE", 2, (yyvsp[-2].node) , (yyvsp[0].node)); }
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 323 "parser.y" /* yacc.c:1646  */
    { (yyval.node) =	mknode("DO-WHILE", 2, (yyvsp[-2].node), (yyvsp[-5].node)); }
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 324 "parser.y" /* yacc.c:1646  */
    { 
																					free((yyvsp[-6].node)->token); (yyvsp[-6].node)->token = strdup("INIT");
																					(yyval.node) = mknode("FOR",4,(yyvsp[-6].node),mknode("COND",1,(yyvsp[-4].node)),(yyvsp[-2].node), (yyvsp[0].node));
																				}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 331 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("ass", mknode("ass",1,(yyvsp[-2].node)),(yyvsp[0].node)); }
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 332 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("ass",1,(yyvsp[0].node)); }
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 335 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("UPDATE",1,mknode("=",2, mknode((yyvsp[-2].string),0), mknode("+", 2, mknode((yyvsp[-2].string),0), mknode("int",1, mknode("1",0))))); }
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 336 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("UPDATE",1,mknode("=",2, mknode((yyvsp[-2].string),0), mknode("-", 2, mknode((yyvsp[-2].string),0), mknode("int",1,mknode("1",0))))); }
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 337 "parser.y" /* yacc.c:1646  */
    { free((yyvsp[0].node)->token); (yyvsp[0].node)-> token = strdup("UPDATE"); (yyval.node) = (yyvsp[0].node); }
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 343 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("FUNC-CALL", mknode((yyvsp[-3].string),0), (yyvsp[-1].node)); }
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 346 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("paramters",mknode("param",1,(yyvsp[-2].node)), (yyvsp[0].node));}
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 347 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("paramters",1,(yyvsp[0].node)); }
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 348 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("NONE",0); }
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 354 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("RET",1,(yyvsp[0].node)); }
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 360 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 361 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 362 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 363 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 364 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 365 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 366 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 367 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 368 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 369 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 370 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 371 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 372 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),1,(yyvsp[0].node));}
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 373 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 374 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[0].string),0); }
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 375 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 376 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("STR-LEN",1,mknode((yyvsp[-1].string),0)); }
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 377 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 378 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("ADDRESS-OF",1,mknode((yyvsp[0].string),0)); }
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 379 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("ADDRESS-OF",1,mknode((yyvsp[-3].string),1,(yyvsp[-1].node)));}
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 380 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-3].string),1,(yyvsp[-1].node)); }
#line 2200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 384 "parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 385 "parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 386 "parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 2218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 387 "parser.y" /* yacc.c:1646  */
    { (yyval.string) = "POINTER";}
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2228 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 392 "parser.y" /* yacc.c:1906  */



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
		/* if left side is pointer */
		if (!strcmp(subTree->subNodes[0]->token, "POINTER")) {
			if (!checkVarExist(env, subTree->subNodes[0]->subNodes[0]->token)) {
				printf("Error: Variable used before declaration - %s\n", subTree->subNodes[0]->subNodes[0]->token);
				quitProgram(tree, env);
			}
			/* if left side is pointer and right is null */
			if(evalExp(subTree->subNodes[1], env, tree) == 8 && (getVarType(env, subTree->subNodes[0]->token)==4 || getVarType(env, subTree->subNodes[0]->token)==5 || getVarType(env, subTree->subNodes[0]->token)==6))
				return;
			if(getVarType(env, subTree->subNodes[0]->subNodes[0]->token) == 4 && evalExp(subTree->subNodes[1], env, tree) != 1){
				printf("Error: Incompatible assignment - *%s\n", subTree->subNodes[0]->subNodes[0]->token);
				quitProgram(tree, env);
			}
			if(getVarType(env, subTree->subNodes[0]->subNodes[0]->token) == 5 && evalExp(subTree->subNodes[1], env, tree) != 3){
				printf("Error: Incompatible assignment - *%s\n", subTree->subNodes[0]->subNodes[0]->token);
				quitProgram(tree, env);
			}
			if(getVarType(env, subTree->subNodes[0]->subNodes[0]->token) == 6 && evalExp(subTree->subNodes[1], env, tree) != 2){
				printf("Error: Incompatible assignment - *%s\n", subTree->subNodes[0]->subNodes[0]->token);
				quitProgram(tree, env);
			}
			return;
		}

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


/*---------------------------------------------------3AC----------------------------------------------------------*/
TAC* to3AC(node *tree) {
	/* function to check turn tree to 3AC
		tree: full parsing tree
	*/

	/* if tree is nothing than no semantic errors */
	if (tree == NULL) {
		return NULL;
	}

	/* node with the value CODE means glogal environment
	*/
	else if (!strcmp(tree->token, "CODE")) {
		for (int i = 0; i < tree->numOfSubNodes; i++) {
			to3AC(tree->subNodes[i]);
		}
		return NULL;
	}

	/* node with the value FUNCTION
	*/
	else if (!strcmp(tree->token, "FUNCTION")) {
		printf("%s:\n",tree->subNodes[0]->token);
		printf("\t\tBeginFunc\n");
		TAC* temp = to3AC(tree->subNodes[3]);
		printf("%s",temp->code);
		printf("\t\tEndFunc\n");
	}
	
	/* node with the value BLOCK
	*/
	else if (!strcmp(tree->token, "BLOCK")) {
		TAC* e1;
		TAC* node = (TAC*)malloc(sizeof(TAC) * 1);
		/* add each code in block to node */
		for (int i = 0; i < tree->numOfSubNodes; i++) {
			e1 = to3AC(tree->subNodes[i]);
			
			/* if frist node */
			if(i == 0){
				node->code = (char*)malloc(sizeof(char) * (strlen(e1->code) + 1));
				strcpy(node->code ,e1->code);
			}
			/* else realloc */
			else{
				node->code = (char*)realloc(node->code, sizeof(char) * (strlen(node->code) + strlen(e1->code) + 1));
				strcat(node->code ,e1->code);
			}
		}
		return node;
	}

	/* node with the value BODY
	*/
	else if (!strcmp(tree->token, "BODY")) {
		TAC* e1;
		TAC* node = (TAC*)malloc(sizeof(TAC) * 1);

		/* add each code in body to node */
		for (int i = 0; i < tree->numOfSubNodes; i++) {
			e1 = to3AC(tree->subNodes[i]);
			
			/* if frist node */
			if(i == 0){
				node->code = (char*)malloc(sizeof(char) * (strlen(e1->code) + 1));
				strcpy(node->code ,e1->code);
			}
			/* else realloc */
			else{
				node->code = (char*)realloc(node->code, sizeof(char) * (strlen(node->code) + strlen(e1->code) + 1));
				strcat(node->code ,e1->code);
			}
		}
		return node;
	}

	/* node with the value VAR
	*/
	else if (!strcmp(tree->token, "VAR")) {
		TAC* node = (TAC*)malloc(sizeof(TAC) * 1);
		int flag = 1;

		/* add each variable to node */
		for (int i = 1; i < tree->numOfSubNodes; i++) {
			/* variable with assign */
			if (tree->subNodes[i]->subNodes != NULL) {
				TAC *e1 = Exp3AC(tree->subNodes[i]->subNodes[1]);

				/* create tx = e1.var*/
				char *code = (char*)malloc(sizeof(char) * (strlen(tree->subNodes[i]->subNodes[0]->token) + strlen(e1->var) + strlen("\t\tt = \n") + 1));
				sprintf(code,"\t\t%s = %s\n", tree->subNodes[i]->subNodes[0]->token, e1->var);

				/* add code and e1.code to node */

				if(i == 1 || flag==1){
					node->code = (char*)malloc(sizeof(char) * (strlen(code) + strlen(e1->code) + 1));
					strcpy(node->code, e1->code);
					strcat(node->code, code);
				}
				else{
					node->code = (char*)realloc(node->code,sizeof(char) * (strlen(node->code) + strlen(code)  + strlen(e1->code) + 1));
					strcat(node->code, e1->code);
					strcat(node->code, code);
				}
				flag = 0;
			}
		}
		if( flag ){
			node->code = strdup("");
		}
		return node;
	}

	/* node with the value STRING
	*/
	else if (!strcmp(tree->token, "STRING")) {
		TAC* node = (TAC*)malloc(sizeof(TAC) * 1);
		int flag = 1;
		for (int i = 0; i < tree->numOfSubNodes; i++) {
			/* variable with assign */
			if (!strcmp(tree->subNodes[i]->token, "=")){
				char *label = getNewVarLabel();
				char *var = (char*)malloc(sizeof(char) * (strlen(label) + 2));
				sprintf(var, "t%s", label);

				char* code1 = (char*)malloc(sizeof(char) * (strlen(var) + strlen(tree->subNodes[i]->subNodes[1]->token) + strlen("\t\t = \n") + 1));
				sprintf(code1,"\t\t%s = %s\n",var,tree->subNodes[i]->subNodes[1]->token);

				char* code2 = (char*)malloc(sizeof(char) * (strlen(var) + strlen(tree->subNodes[i]->subNodes[0]->token) + strlen("\t\t = \n") + 1));
				sprintf(code2,"\t\t%s = %s\n",tree->subNodes[i]->subNodes[0]->token,var);

				if(i==0 || flag==1){
					node->code = (char*)malloc(sizeof(char) * (strlen(code1) + strlen(code2) + 1));
					strcpy(node->code, code1);
					strcat(node->code, code2);
				}
				else{
					node->code = (char*)realloc(node->code, sizeof(char) * (strlen(node->code) + strlen(code1) + strlen(code2) + 1));
					strcat(node->code, code1);
					strcat(node->code, code2);
				}
				flag = 0;
			}
		}
		if( flag ){
			node->code = strdup("");
		}
		return node;
	}

	/* node with the value IF
	*/
	else if (!strcmp(tree->token, "IF")) {
		/* get true label */
		char* currentLabel1 = getNewLabel();

		/* eavl block of if */
		TAC *e1 = to3AC(tree->subNodes[1]);

		/* get false label*/
		char* currentLabel2 = getNewLabel();

		TAC* cond;
		/*eavl condition */
		if(tree->subNodes[0]->numOfSubNodes!=0 && isBoolOp(tree->subNodes[0]->subNodes[0]->token)){
			cond = get3acCond(tree->subNodes[0], currentLabel1, currentLabel2);
		}
		else{
			cond = get3acSimpleCond(tree->subNodes[0], currentLabel1, currentLabel2);
		}

		
		TAC* node = (TAC*)malloc(sizeof(TAC) * 1);
		node->code = (char*)malloc(sizeof(char) * (strlen(cond->code) + strlen(":") * 2 + strlen(currentLabel1)  + strlen(e1->code) +  strlen(currentLabel2) + 1));
		sprintf(node->code, "%s%s:%s%s:", cond->code,currentLabel1,e1->code,currentLabel2);

		return node;
	}

	/* node with the value IF-ELSE
	*/
	else if (!strcmp(tree->token, "IF-ELSE")) {
		/* get true label */
		char* currentLabel1 = getNewLabel();

		/* eavl block of if */
		TAC *e1 = to3AC(tree->subNodes[1]);
		TAC *e2 = to3AC(tree->subNodes[2]);

		/* get false label*/
		char* currentLabel2 = getNewLabel();

		TAC* cond;
		/*eavl condition */
		if(tree->subNodes[0]->numOfSubNodes!=0 && isBoolOp(tree->subNodes[0]->subNodes[0]->token)){
			cond = get3acCond(tree->subNodes[0], currentLabel1, currentLabel2);
		}
		else{
			cond = get3acSimpleCond(tree->subNodes[0], currentLabel1, currentLabel2);
		}

		
		TAC* node = (TAC*)malloc(sizeof(TAC) * 1);
		node->code = (char*)malloc(sizeof(char) * (strlen(cond->code) + strlen(":") * 2 + strlen(currentLabel1)  + strlen(e1->code) + strlen(e2->code) + strlen(currentLabel2) + 1));
		sprintf(node->code, "%s%s:%s%s:%s", cond->code,currentLabel1,e1->code,currentLabel2,e2->code);

		return node;
	}
	
	/* node with the value WHILE
	*/
	else if (!strcmp(tree->token, "WHILE")) {

		/* get true label */
		char* currentLabel1 = getNewLabel();
		char* currentLabel2 = getNewLabel();

		/* eavl block of if */
		TAC *e1 = to3AC(tree->subNodes[1]);

		/* get false label*/
		char* currentLabel3 = getNewLabel();

		TAC* cond;
		/*eavl condition */
		if(tree->subNodes[0]->numOfSubNodes!=0 && isBoolOp(tree->subNodes[0]->subNodes[0]->token)){
			cond = get3acCond(tree->subNodes[0], currentLabel2, currentLabel3);
		}
		else{
			cond = get3acSimpleCond(tree->subNodes[0], currentLabel2, currentLabel3);
		}

		
		TAC* node = (TAC*)malloc(sizeof(TAC) * 1);
		node->code = (char*)malloc(sizeof(char) * (strlen(cond->code) + strlen(":") * 2 + strlen(currentLabel3)  + strlen(e1->code) + strlen(currentLabel1) *2 + strlen(currentLabel2) + 1));
		sprintf(node->code, "%s%s%s:%s\t\tgoto%s\n%s:",currentLabel1,cond->code,currentLabel2,e1->code,currentLabel1,currentLabel3);

		return node;
	}

	/* node with the value DO-WHILE
	*/
	else if (!strcmp(tree->token, "DO-WHILE")) {
		/* get true label */
		char* currentLabel1 = getNewLabel();
		char* currentLabel2 = getNewLabel();

		/* eavl block of if */
		TAC *e1 = to3AC(tree->subNodes[1]);

		/* get false label*/
		char* currentLabel3 = getNewLabel();

		TAC* cond;
		/*eavl condition */
		if(tree->subNodes[0]->numOfSubNodes!=0 && isBoolOp(tree->subNodes[0]->subNodes[0]->token)){
			cond = get3acCond(tree->subNodes[0], currentLabel2, currentLabel3);
		}
		else{
			cond = get3acSimpleCond(tree->subNodes[0], currentLabel2, currentLabel3);
		}

		
		TAC* node = (TAC*)malloc(sizeof(TAC) * 1);
		node->code = (char*)malloc(sizeof(char) * (strlen(cond->code) + strlen(":") * 2 + strlen(currentLabel3)  + strlen(e1->code)*2 + strlen(currentLabel1) *2 + strlen(currentLabel2) + 1));
		sprintf(node->code, "%s%s%s%s:%s\t\tgoto%s\n%s:",e1->code,currentLabel1,cond->code,currentLabel2,e1->code,currentLabel1,currentLabel3);

		return node;
	}

	/* node with the value FOR

	*/
	else if (!strcmp(tree->token, "FOR")) {
		/* get true label */
		char* currentLabel1 = getNewLabel();
		char* currentLabel2 = getNewLabel();

		/* eval init */
		TAC *e1 = to3AC(tree->subNodes[0]);

		/* eval block of for */
		TAC *e2 = to3AC(tree->subNodes[3]);

		/* eval update */
		TAC *e3 = to3AC(tree->subNodes[2]);

		/* get false label*/
		char* currentLabel3 = getNewLabel();

		TAC* cond;
		/*eavl condition */
		if(tree->subNodes[0]->numOfSubNodes!=0 && isBoolOp(tree->subNodes[0]->subNodes[0]->token)){
			cond = get3acCond(tree->subNodes[1]->subNodes[0], currentLabel2, currentLabel3);
		}
		else{
			cond = get3acSimpleCond(tree->subNodes[1]->subNodes[0], currentLabel2, currentLabel3);
		}

		
		TAC* node = (TAC*)malloc(sizeof(TAC) * 1);
		node->code = (char*)malloc(sizeof(char) * (strlen(cond->code) + strlen(":") * 3 + strlen("\t\t \n") + strlen(currentLabel3)  + strlen(e1->code)*2 + strlen(currentLabel1) *2 + strlen(currentLabel2) + 1 + strlen(e2->code) + strlen(e3->code)));
		sprintf(node->code, "%s%s:%s%s:%s%s\t\tgoto %s\n%s:",e1->code,currentLabel1,cond->code,currentLabel2,e2->code,e3->code,currentLabel1,currentLabel3);

		return node;
	}
	
	/* node with the value INIT
	*/
	else if (!strcmp(tree->token, "INIT")) {
		TAC* e1;
		TAC* node = (TAC*)malloc(sizeof(TAC) * 1);

		/* add each code in body to node */
		for (int i = 0; i < tree->numOfSubNodes; i++) {
			e1 = to3AC(tree->subNodes[i]);
			
			/* if frist node */
			if(i == 0){
				node->code = (char*)malloc(sizeof(char) * (strlen(e1->code) + 1));
				strcpy(node->code ,e1->code);
			}
			/* else realloc */
			else{
				node->code = (char*)realloc(node->code, sizeof(char) * (strlen(node->code) + strlen(e1->code) + 1));
				strcat(node->code ,e1->code);
			}
		}
		return node;
	}
	
	/* node with the value UPDATE
	*/
	else if (!strcmp(tree->token, "UPDATE")) {
		
		TAC* e1;
		TAC* node = (TAC*)malloc(sizeof(TAC) * 1);

		/* add each code in body to node */
		for (int i = 0; i < tree->numOfSubNodes; i++) {
			e1 = to3AC(tree->subNodes[i]);
			
			/* if frist node */
			if(i == 0){
				node->code = (char*)malloc(sizeof(char) * (strlen(e1->code) + 1));
				strcpy(node->code ,e1->code);
			}
			/* else realloc */
			else{
				node->code = (char*)realloc(node->code, sizeof(char) * (strlen(node->code) + strlen(e1->code) + 1));
				strcat(node->code ,e1->code);
			}
		}
		return node;
	}

	/* node with the value FUNC-CALL
	*/
	else if (!strcmp(tree->token, "FUNC-CALL")) {
		TAC* e1 = NULL;
		TAC* node = (TAC*)malloc(sizeof(TAC) * 1);
		int flag = 0;

		/* deal with all params of function call */
		for(int i=1; i<tree->numOfSubNodes; i++){
			/* eval param */
			e1 = Exp3AC(tree->subNodes[i]);

			/* if paramter is complex has e.code */
			if(tree->subNodes[i]->numOfSubNodes!=0){
				/* if first paramter malloc */
				if(i == 1){
					node->code = (char*)malloc(sizeof(char) * (strlen(e1->code) + 1));
					strcpy(node->code ,e1->code);
					flag = 1;
				}
				/* else realloc */
				else{
					node->code = (char*)realloc(node->code, sizeof(char) * (strlen(node->code) + strlen(e1->code) + 1));
					strcat(node->code ,e1->code);
				}
			}
			/* if paramter is simple and first paramte malloc */
			if(i == 1 && flag == 0){
				node->code = (char*)malloc(sizeof(char) * (strlen(e1->var) + strlen("\t\tPushParam \n") + 1 ));
			}
			/* else realloc */
			else{
				node->code = (char*)realloc(node->code, sizeof(char) * (strlen(node->code) + strlen(e1->var) + strlen("\t\tPushParam \n") + 1));
			}
			strcat(node->code, "\t\tPushParam ");
			strcat(node->code, e1->var);
			strcat(node->code,"\n");			
		}

		char *label = getNewVarLabel();
		char *var = (char*)malloc(sizeof(char) * (strlen(label) + 2));
		char *code = (char*)malloc(sizeof(char) * (strlen(label) + strlen(tree->subNodes[0]->token) + strlen("\t\t = LCall \n") + 1));
		/* create tx */
		strcpy(var, "t");
		strcat(var, label);
		/* create tx = LCall name */
		strcpy(code,"\t\t");
		strcat(code, var);
		strcat(code, " = ");
		strcat(code, "LCall ");
		strcat(code, tree->subNodes[0]->token);
		strcat(code, "\n");
		
		node -> var = strdup(var);
		node->code = (char*)realloc(node->code, sizeof(char) * (strlen(node->code) + strlen(code) + 1));
		strcat(node->code ,code);

		free(var);
		free(code);

		/* create popparams */
		code = (char*)malloc(sizeof(char) * (strlen(label) + strlen(tree->subNodes[0]->token) + strlen("\t\tPopParams 0\n") + 1));

		strcpy(code,"\t\tPopParams ");
		strcat(code, "0"); // need to calc
		strcat(code, "\n");
		
		node->code = (char*)realloc(node->code, sizeof(char) * (strlen(node->code) + strlen(code) + 1));
		strcat(node->code ,code);

		return node;
	}

	/* node with the value RET
	*/
	else if (!strcmp(tree->token, "RET")) {
		TAC* node = (TAC*)malloc(sizeof(TAC) * 1);
		TAC *e1 = Exp3AC(tree->subNodes[0]);

		if(tree->subNodes[0]->numOfSubNodes !=0){
			node->code = (char*)malloc(sizeof(char) * (strlen(e1->code) + 1));
			strcpy(node->code, e1->code);

			char* code =(char*)malloc(sizeof(char) * (strlen("\t\tReturn \n") + strlen(e1->var) + 1));
			sprintf(code,"\t\tReturn %s\n",e1->var);

			node->code = (char*)realloc(node->code, sizeof(char) * (strlen(node->code) + strlen(code) + 1));
			strcat(node->code, code);
			return node;
		}

		node->code = (char*)malloc(sizeof(char) * (strlen("\t\tReturn \n") + strlen(e1->var) + 1));
		sprintf(node->code, "\t\tReturn %s\n",  e1->var);
		return node;
	}

	/* node with the value =
	*/
	else if (!strcmp(tree->token, "=")) {
		TAC* node = (TAC*)malloc(sizeof(TAC) * 1);
		/* left side is pointer */
		if(!strcmp(tree->subNodes[0]->token, "POINTER")){
			TAC *e1 = Exp3AC(tree->subNodes[1]);

			node->code = (char*)malloc(sizeof(char) * (strlen(e1->code) + 1));
			strcpy(node->code, e1->code);

			char* code = (char*)malloc(sizeof(char) * (strlen(tree->subNodes[0]->subNodes[0]->token) + strlen(e1->var) + strlen("\t\t* = \n") + 1));
			sprintf(code, "\t\t*%s = %s\n",tree->subNodes[0]->subNodes[0]->token,e1->var);

			node->code = (char*)realloc(node->code, sizeof(char) * (strlen(node->code) + strlen(code) + 1));
			strcat(node->code, code);
			return node;
		}
		/* left side is string */
		else if(tree->subNodes[0]->numOfSubNodes !=0){
			TAC *e1 = Exp3AC(tree->subNodes[1]);

			char *label = getNewVarLabel();
			char *var = (char*)malloc(sizeof(char) * (strlen(label) + 1));
			char *var2 = (char*)malloc(sizeof(char) * (strlen(label) + 1));
			strcpy(var, "t");
			strcat(var, label);
			label = getNewVarLabel();
			strcpy(var2, "t");
			strcat(var2, label);

			char* code1 = (char*)malloc(sizeof(char) * (strlen(tree->subNodes[0]->token) + strlen(var) + strlen("\t\t = &\n") + 1));
			sprintf(code1, "\t\t%s = &%s\n",var, tree->subNodes[0]->token);

			char* code2 = (char*)malloc(sizeof(char) * (strlen(tree->subNodes[0]->token) + strlen(var2) + strlen("\t\t =  + \n") + 1));
			sprintf(code2, "\t\t%s = %s + %s\n",var2, var,tree->subNodes[0]->subNodes[0]->subNodes[0]->token);

			char* code3 = (char*)malloc(sizeof(char) * (strlen(var2) + strlen(e1->var) + strlen("\t\t* = \n") + 1));
			sprintf(code3, "\t\t*%s = %s\n",var2, e1->var);

			node->code = (char*)malloc(sizeof(char) * (strlen(code1) + strlen(code2) + strlen(code3) + strlen(e1->code) + 1));
			strcpy(node->code, e1->code);
			strcat(node->code, code1);
			strcat(node->code, code2);
			strcat(node->code, code3);
			return node;
		}
		/* left side is a simple var */
		else{
			TAC *e1 = Exp3AC(tree->subNodes[1]);
			char* code = (char*)malloc(sizeof(char) * (strlen(tree->subNodes[0]->token) + strlen(e1->var) + strlen("\t\t = \n") + 1));
			sprintf(code, "\t\t%s = %s\n",tree->subNodes[0]->token,e1->var);
			node->code = (char*)malloc(sizeof(char) * (strlen(code) + strlen(e1->code) + 1));
			if(tree->subNodes[1]->subNodes!=0)
				strcpy(node->code, e1->code);
			strcat(node->code, code);
			return node;
		}
	}
}

TAC* get3acSimpleCond(node* tree, char* l1, char* l2){
	if(isValue(tree->token) || isBoolOp(tree->token)){
		TAC* temp = Exp3AC(tree);
		char* code = (char*)malloc(sizeof(char) * (strlen(temp->code) + strlen(temp->var) + strlen(l2) + strlen("\t\tifz  goto \n") + 1));
		sprintf(code, "%s\t\tifz %s goto %s\n" ,temp->code, temp->var, l2);
		temp->code = strdup(code);
		return temp;
	}
	else{
		TAC* temp = (TAC*)malloc(sizeof(TAC) * 1);
		char *label = getNewVarLabel();
		char* var = (char*)malloc(sizeof(char)* (strlen(label) + 2));
		sprintf(var,"t%s",label);
		temp->code = (char*)malloc(sizeof(char) * (strlen(var) * 2 + strlen(tree->token) + strlen(l2) + strlen("\t\t = \t\t\nifz  goto \n") + 1));
		sprintf(temp->code, "\t\t%s = %s\n\t\tifz %s goto %s\n",var,tree->token ,var, l2);
		return temp;
	}
}


TAC* get3acCond(node* tree, char* l1, char* l2){
	TAC* node = (TAC*)malloc(sizeof(TAC) * 1);
	/* if condition is or */
	if(!strcmp(tree->token, "||")){
		TAC* left = get3acCond(tree->subNodes[0], l1, l2);
		char* code = strdup("");
		if(left != NULL && tree->subNodes[0]->numOfSubNodes!=0 && strcmp(tree->subNodes[0]->token,"&&") && strcmp(tree->subNodes[0]->token,"||")){
			code = (char*)malloc(sizeof(char) * (strlen(left->code) + strlen(left->var) + strlen(l1) + strlen("\t\tifnz  goto \n") + 1));
			sprintf(code,"%s\t\tifnz %s goto %s\n",left->code,left->var,l1);
		}
		else{
			code = strdup(left->code);
		}
		TAC* right = get3acCond(tree->subNodes[1], l1, l2);
		char* code2 = strdup("");
		if(right != NULL && tree->subNodes[1]->numOfSubNodes!=0 && strcmp(tree->subNodes[1]->token,"&&") && strcmp(tree->subNodes[1]->token,"||")){
			code2 = (char*)malloc(sizeof(char) * (strlen(right->code) + strlen(right->var) + strlen(l2) + strlen("\t\tifz  goto \n") + 1));
			sprintf(code2,"%s\t\tifz %s goto %s\n",right->code,right->var,l2);
		}
		else{
			code2 = strdup(right->code);
		}
		node-> code = (char*)malloc(sizeof(char) * (strlen(code) + strlen(code2) + 1));
		strcpy(node->code, code);
		strcat(node->code, code2);
		return node;
	}

	/* if condition is and */
	if(!strcmp(tree->token, "&&")){
		TAC* left = get3acCond(tree->subNodes[0], l1, l2);
		char* code = strdup("");
		if(left != NULL && tree->subNodes[0]->numOfSubNodes!=0 && strcmp(tree->subNodes[0]->token,"&&") && strcmp(tree->subNodes[0]->token,"||")){
			code = (char*)malloc(sizeof(char) * (strlen(left->code) + strlen(left->var) + strlen(l2) + strlen("%s\t\tifz  goto \n") + 1));
			sprintf(code,"%s\t\tifz %s goto %s\n",left->code,left->var,l2);
		}
		else{
			code = strdup(left->code);
		}
		TAC* right = get3acCond(tree->subNodes[1], l1, l2);
		char* code2 = strdup("");
		if(right != NULL && tree->subNodes[1]->numOfSubNodes!=0 && strcmp(tree->subNodes[1]->token,"&&") && strcmp(tree->subNodes[1]->token,"||")){
			code2 = (char*)malloc(sizeof(char) * (strlen(right->code) + strlen(right->var) + strlen(l2) + strlen("%s\t\tifz  goto \n") + 1));
			sprintf(code2,"%s\t\tifz %s goto %s\n",right->code,right->var,l2);
		}
		else{
			code2 = strdup(right->code);
		}
		node-> code = (char*)malloc(sizeof(char) * (strlen(code) + strlen(code2) + 1));
		strcpy(node->code, code);
		strcat(node->code, code2);
		return node;
	}
	return Exp3AC(tree);
}

TAC* Exp3AC(node *tree){
	/* if node token is + , - , * , / , &&, ||, ==, !=, > , <, >= , <= */
	if (!strcmp("+", tree->token) || !strcmp("-", tree->token) || !strcmp("*", tree->token) || !strcmp("/", tree->token)
	||!strcmp("&&", tree->token) || !strcmp("||", tree->token) || !strcmp("==", tree->token) || !strcmp("!=", tree->token)||
	!strcmp(">", tree->token) || !strcmp(">=", tree->token) || !strcmp("<", tree->token) || !strcmp("<=", tree->token)) {
		
		/* send right side to evaluate*/
		TAC* e2 = Exp3AC(tree->subNodes[1]);
		/* send left side to evaluate*/
		TAC* e1 = Exp3AC(tree->subNodes[0]);

		char *label = getNewVarLabel();
		char *var = (char*)malloc(sizeof(char) * (strlen(label) + 2));
		char *code = (char*)malloc(sizeof(char) * (strlen(label) + strlen(e1->var) + strlen(tree->token) + strlen(e2->var) + strlen("\t\tt = \n") + 1));
		/* create tx */
		strcpy(code,"\t\t");
		strcpy(var, "t");
		/* create tx = e1.var+e2.var */
		strcat(var, label);
		strcat(code, var);
		strcat(code, " = ");
		strcat(code, e1->var);
		strcat(code, tree->token);
		strcat(code, e2->var);
		strcat(code, "\n");

		/*  create node */
		TAC* node = (TAC*)malloc(sizeof(TAC) * 1);
		/* both sons are complex and have e.code */
		if(tree->subNodes[0]->numOfSubNodes!=0 && tree->subNodes[1]->numOfSubNodes!=0){
			node->code = (char*)malloc(sizeof(char) * (strlen(code) + strlen(e1->code) + strlen(e2->code) + 1));
			strcpy(node->code ,e2->code);
			strcat(node->code, e1->code);
			strcat(node->code, code);
		}
		/* one son is complex has e.code and one is simple */
		else if(tree->subNodes[0]->numOfSubNodes!=0){
			node->code = (char*)malloc(sizeof(char) * (strlen(code) + strlen(e1->code) + 1));
			strcpy(node->code, e1->code);
			strcat(node->code, code);
		}
		/* one son is complex has e.code and one is simple */
		else if(tree->subNodes[1]->numOfSubNodes!=0){
			node->code = (char*)malloc(sizeof(char) * (strlen(code) + strlen(e2->code) + 1));
			strcpy(node->code, e2->code);
			strcat(node->code, code);
		}
		/* both sons are simple */
		else{
			node->code = strdup(code);
		}
		node->var = strdup(var);
		node->truel = NULL;
		node->falsel = NULL;
		return node;
	}

	/* if node token is ! */
	if (!strcmp("!", tree->token)) {
		TAC* e1 = Exp3AC(tree->subNodes[0]);

		
		char *label = getNewVarLabel();
		char *var = (char*)malloc(sizeof(char) * (strlen(label) + 2));
		char *code = (char*)malloc(sizeof(char) * (strlen(label) + strlen(e1->var) + strlen("\t\tt = !\n") + 1));
		/* create tx */
		strcpy(var, "t");
		strcat(var, label);
		/* create tx = !e1.var*/
		strcpy(code,"\t\t");
		strcat(code, var);
		strcat(code, " = !");
		strcat(code, e1->var);
		strcat(code, "\n");

		TAC* node = (TAC*)malloc(sizeof(TAC) * 1);
		/* if son is complex has e.code */
		if(tree->subNodes[0]->numOfSubNodes!=0){
			node->code = (char*)malloc(sizeof(char) * (strlen(code) + strlen(e1->code) + 1));
			strcpy(node->code ,e1->code);
			strcat(node->code, code);
		}
		/* if son is is simple */
		else{
			node->code = strdup(code);
		}
		node->var = strdup(var);
		node->truel = NULL;
		node->falsel = NULL;
		return node;
	}

	/* if node token is POINTER */
	if (!strcmp("POINTER", tree->token)) {
		TAC* e1 = Exp3AC(tree->subNodes[0]);

		char *label = getNewVarLabel();
		char *var = (char*)malloc(sizeof(char) * (strlen(label) + 2));
		char *code = (char*)malloc(sizeof(char) * (strlen(label) + strlen(e1->var) + strlen("\t\tt = *\n") + 1));
		/* create tx */
		strcpy(var, "t");
		strcat(var, label);
		/* create tx = *e.var */
		strcpy(code,"\t\t");
		strcat(code, var);
		strcat(code, " = *");
		strcat(code, e1->var);
		strcat(code, "\n");

		TAC* node = (TAC*)malloc(sizeof(TAC) * 1);
		/* if node is not simple has e.code*/
		if(tree->subNodes[0]->numOfSubNodes!=0){
			node->code = (char*)malloc(sizeof(char) * (strlen(code) + strlen(e1->code) + 1));
			strcpy(node->code ,e1->code);
			strcat(node->code, code);
		}
		/* if node is simple */
		else{
			node->code = strdup(code);
		}
		node->var = strdup(var);
		node->truel = NULL;
		node->falsel = NULL;
		return node;
	}

	/* if node token is STR-LEN */
	if (!strcmp("STR-LEN", tree->token)) {
		TAC* e1 = Exp3AC(tree->subNodes[0]);

		char *label = getNewVarLabel();
		char *var = (char*)malloc(sizeof(char) * (strlen(label) + 2));
		char *code = (char*)malloc(sizeof(char) * (strlen(label) + strlen(e1->var) + strlen("\t\tt = ||\n") + 1));
		/* create tx */
		strcpy(var, "t");
		strcat(var, label);
		/* create tx = |e.var| */
		strcpy(code,"\t\t");
		strcat(code, var);
		strcat(code, " = |");
		strcat(code, e1->var);
		strcat(code, "|\n");

		TAC* node = (TAC*)malloc(sizeof(TAC) * 1);
		node->code = strdup(code);
		node->var = strdup(var);
		node->truel = NULL;
		node->falsel = NULL;
		return node;
	}
	
	/* if node token is ADDRESS-OF*/
	if (!strcmp("ADDRESS-OF", tree->token)) {
		TAC* e1 = Exp3AC(tree->subNodes[0]);

		char *label = getNewVarLabel();
		char *var = (char*)malloc(sizeof(char) * (strlen(label) + 2));
		char *code = (char*)malloc(sizeof(char) * (strlen(label) + strlen(e1->var) + strlen("\t\tt = &\n") + 1));
		/* create tx */
		strcpy(var, "t");
		strcat(var, label);
		/* create tx = &e.var */
		strcpy(code,"\t\t");
		strcat(code, var);
		strcat(code, " = &");
		strcat(code, e1->var);
		strcat(code, "\n");

		TAC* node = (TAC*)malloc(sizeof(TAC) * 1);
		/* if node is not simple has e.code*/
		if(tree->subNodes[0]->numOfSubNodes!=0){
			node->code = (char*)malloc(sizeof(char) * (strlen(code) + strlen(e1->code) + 1));
			strcpy(node->code ,e1->code);
			strcat(node->code, code);
		}
		/* if node is simple */
		else{
			node->code = strdup(code);
		}
		node->var = strdup(var);
		node->truel = NULL;
		node->falsel = NULL;
		return node;
	}

	/* if node token is FUNC-CALL*/
	if (!strcmp("FUNC-CALL", tree->token)) {
		TAC* e1 = NULL;
		TAC* node = (TAC*)malloc(sizeof(TAC) * 1);
		int flag = 0;

		/* deal with all params of function call */
		for(int i=1; i<tree->numOfSubNodes; i++){
			/* eval param */
			e1 = Exp3AC(tree->subNodes[i]);

			/* if paramter is complex has e.code */
			if(tree->subNodes[i]->numOfSubNodes!=0){
				/* if first paramter malloc */
				if(i == 1){
					node->code = (char*)malloc(sizeof(char) * (strlen(e1->code) + 1));
					strcpy(node->code ,e1->code);
					flag = 1;
				}
				/* else realloc */
				else{
					node->code = (char*)realloc(node->code, sizeof(char) * (strlen(node->code) + strlen(e1->code) + 1));
					strcat(node->code ,e1->code);
				}
			}
			/* if paramter is simple and first paramte malloc */
			if(i == 1 && flag == 0){
				node->code = (char*)malloc(sizeof(char) * (strlen(e1->var) + strlen("\t\tPushParam \n") + 1 ));
			}
			/* else realloc */
			else{
				node->code = (char*)realloc(node->code, sizeof(char) * (strlen(node->code) + strlen(e1->var) + strlen("\t\tPushParam \n") + 1));
			}
			strcat(node->code, "\t\tPushParam ");
			strcat(node->code, e1->var);
			strcat(node->code,"\n");			
		}

		char *label = getNewVarLabel();
		char *var = (char*)malloc(sizeof(char) * (strlen(label) + 2));
		char *code = (char*)malloc(sizeof(char) * (strlen(label) + strlen(tree->subNodes[0]->token) + strlen("\t\tt = LCall \n") + 1));
		/* create tx */
		strcpy(var, "t");
		strcat(var, label);
		/* create tx = LCall name */
		strcpy(code,"\t\t");
		strcat(code, var);
		strcat(code, " = ");
		strcat(code, "LCall ");
		strcat(code, tree->subNodes[0]->token);
		strcat(code, "\n");
		
		node -> var = strdup(var);
		node->code = (char*)realloc(node->code, sizeof(char) * (strlen(node->code) + strlen(code) + 1));
		strcat(node->code ,code);

		free(var);
		free(code);

		/* create popparams */
		code = (char*)malloc(sizeof(char) * (strlen(label) + strlen(tree->subNodes[0]->token) + strlen("\t\tPopParams 0\n") + 1));

		strcpy(code,"\t\tPopParams ");
		strcat(code, "0"); // need to calc
		strcat(code, "\n");
		
		node->code = (char*)realloc(node->code, sizeof(char) * (strlen(node->code) + strlen(code) + 1));
		strcat(node->code ,code);

		return node;
	}

	/* node can be variable or const */
	else {
		/* node is simple value */
		if(isValue(tree->token)){
			char *label = getNewVarLabel();
			char *var = (char*)malloc(sizeof(char) * (strlen(label) + 2));
			char *code = (char*)malloc(sizeof(char) * (strlen(label) + strlen(tree->subNodes[0]->token) + strlen("\t\tt = \n") + 1));
			/* create tx */
			strcpy(var, "t");
			strcat(var, label);
			/* create tx = value */
			strcpy(code,"\t\t");
			strcat(code, var);
			strcat(code, " = ");
			strcat(code, tree->subNodes[0]->token);
			strcat(code, "\n");

			TAC* node = (TAC*)malloc(sizeof(TAC) * 1);
			node->code = strdup(code);
			node->var = strdup(var);
			node->truel = NULL;
			node->falsel = NULL;
			return node;
		}
		/* node is str */
		if(tree->numOfSubNodes!=0){
			char *label = getNewVarLabel();
			char *var = (char*)malloc(sizeof(char) * (strlen(label) + 2));
			char *code = (char*)malloc(sizeof(char) * (strlen(label) + strlen(tree->token) + strlen("\t\tt = &\n") + 1));
			/* create tx */ 
			strcpy(var, "t");
			strcat(var, label);
			/* create tx = &str */
			strcpy(code,"\t\t");
			strcat(code, var);
			strcat(code, " = &");
			strcat(code, tree->token);
			strcat(code, "\n");

			char *label2 = getNewVarLabel();
			char *var2 = (char*)malloc(sizeof(char) * (strlen(label2) + 2));
			char *code2 = (char*)malloc(sizeof(char) * (strlen(label2) + strlen(tree->subNodes[0]->subNodes[0]->token) + strlen(var) + strlen("\t\tt = +\n") + 1));
			/* create tx */
			strcpy(var2, "t");
			strcat(var2, label2);
			/* create tx = ty + int */
			strcpy(code2,"\t\t");
			strcat(code2, var2);
			strcat(code2, " = ");
			strcat(code2, var);
			strcat(code2, "+");
			strcat(code2, tree->subNodes[0]->subNodes[0]->token);
			strcat(code2, "\n");
			
			TAC* node = (TAC*)malloc(sizeof(TAC) * 2);
			node->code = (char*)malloc(sizeof(char) * (strlen(code) + strlen(code2) + 1));
			strcpy(node->code, code);
			strcat(node->code, code2);
			node->var = strdup(var);
			node->truel = NULL;
			node->falsel = NULL;
			return node;
		}
		/* node is var */
		TAC* node = (TAC*)malloc(sizeof(TAC) * 1);
		node->code = strdup(tree->token);
		node->var = strdup(tree->token);
		node->truel = NULL;
		node->falsel = NULL;
		return node;
	}
}

char* getNewVarLabel(){
	char *str = (char*)malloc(sizeof(char) * 12 );
	sprintf(str, "%d", varIndex);
	varIndex += 1;
	return str;
}

char* getNewLabel(){
	char *str = (char*)malloc(sizeof(char) * 13 );
	sprintf(str, "L%d", labelIndex);
	labelIndex += 1;
	return str;
}

int calcFuncCallBytes(node *tree){
	return 0;
}

int isBoolOp(char *token){
	if (!strcmp("&&", token) || !strcmp("||", token) || !strcmp("==", token) || !strcmp("!=", token)|| !strcmp(">", token) || !strcmp(">=", token) || !strcmp("<", token) || !strcmp("<=", token)) {
		return 1;
	}
	return 0;

}




