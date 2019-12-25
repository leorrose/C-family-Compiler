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
node *mknode(char *token, int count, ...);
int yywrap();
int yyerror(char *err);
node *combineNodes(char *token, node *one, node *two);
void printTree(node *tree, int tab);
void printTabs(int a);
void freeTree(node *tree);
func *mkfunc(char *name, int type, int numOfArgs, int *args);
int numOfArgs(node *node);
int* argumentRep(node *node);
int getTypeVal(char *string);
var *mkvar(char *name, int type);
table *mktable(table *upperEnv);
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
void evalExp(node *tree, table* stable);
void quitProgram(node *tree);
int* getFuncArgsTypes(char* name, table *env);
bool checkVarExist(table *env, char *id);
bool funcCallCheck(node* tree, table *env);
int getFuncNumOfArgs(char* name, table *env);
int getVarType(table *env, char *id);


#line 138 "y.tab.c" /* yacc.c:339  */

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
#line 75 "parser.y" /* yacc.c:355  */

	char *string;
	struct node *node;

#line 256 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 273 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   427

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  207

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
       0,   117,   117,   121,   122,   126,   127,   133,   137,   141,
     142,   143,   147,   151,   152,   156,   157,   158,   159,   163,
     164,   165,   166,   167,   168,   174,   175,   176,   177,   178,
     179,   185,   186,   190,   194,   195,   196,   197,   201,   202,
     206,   207,   213,   214,   218,   219,   220,   221,   222,   223,
     229,   230,   231,   232,   236,   239,   242,   245,   250,   251,
     252,   253,   256,   257,   263,   264,   270,   271,   272,   279,
     280,   283,   284,   285,   291,   294,   295,   296,   302,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     332,   333,   334,   335,   338
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
  "type_list", "param", "body", "declarations", "primitive_val",
  "declaration", "primitive_declaration", "declaration_parameters",
  "string_declaration", "string_parameters", "nested_statements", "stmt",
  "assign", "primitive_assign", "index_assign", "string_assign",
  "pointer_assign", "code_block", "declaration_no_function", "conditions",
  "loops", "multi_assign", "update", "procedure_func_call",
  "expression_list", "return", "expression", "unary_op", "epsilon", YY_NULLPTR
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

#define YYPACT_NINF -150

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-150)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,    17,    38,    15,  -150,  -150,  -150,    13,    44,  -150,
    -150,     6,    14,    78,    78,    47,    45,    43,  -150,    59,
      61,  -150,    62,    78,    67,    47,   102,  -150,   102,  -150,
      81,    75,    76,    86,   115,   178,    87,    93,     9,    32,
      25,    25,    89,   140,    25,  -150,  -150,   140,    91,  -150,
    -150,  -150,  -150,  -150,  -150,  -150,    92,    97,  -150,    90,
      99,   103,   105,   178,   178,   100,   114,  -150,  -150,  -150,
    -150,  -150,   116,  -150,  -150,  -150,  -150,  -150,    24,   178,
     121,  -150,  -150,   361,   178,   152,   143,   153,   178,   178,
      18,   124,   119,   125,  -150,  -150,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,  -150,   178,  -150,    81,   305,   319,   144,
     126,   129,     0,   130,   131,   133,   178,   333,   127,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   361,   141,   178,  -150,   361,   151,   274,  -150,   206,
    -150,  -150,  -150,   155,  -150,   220,  -150,   140,   140,   178,
     100,   178,   114,  -150,   114,   178,   240,  -150,  -150,    -6,
      -6,  -150,  -150,   375,   402,    60,    60,    60,    60,   402,
     389,   178,   361,  -150,   178,   176,  -150,   179,   193,  -150,
    -150,   288,  -150,  -150,   254,  -150,   347,  -150,   178,   166,
     140,   167,  -150,   159,   361,  -150,  -150,    46,  -150,   165,
    -150,   191,   197,   140,  -150,  -150,  -150
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     3,     5,     6,     0,     0,     1,
       4,     0,     0,   104,   104,     0,     0,    10,    11,     0,
      14,    12,     0,   104,     0,     0,   104,     9,   104,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
      22,    24,     0,    16,    20,    31,    17,    42,     0,    50,
      51,    52,    53,    45,    46,    47,     0,     0,    18,     0,
       0,     0,    39,     0,     0,     0,     0,    30,   100,   101,
     103,   102,     0,    25,    26,    27,    28,    29,    93,     0,
       0,    92,    94,    78,     0,     0,     0,     0,   104,     0,
      63,     0,     0,     0,    21,    23,     7,    15,    19,    43,
      44,    48,    49,     8,     0,    32,     0,     0,     0,     0,
      70,     0,    36,     0,    37,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    91,     0,     0,    56,    54,     0,    76,    77,     0,
      62,    60,    59,     0,    61,     0,    38,     0,     0,     0,
       0,     0,     0,    33,     0,     0,     0,    96,    95,    79,
      80,    81,    82,    83,    85,    87,    88,    89,    90,    86,
      84,     0,    57,    74,   104,     0,    58,    40,    64,    66,
      69,     0,    34,    35,     0,    99,     0,    75,     0,     0,
       0,     0,    98,     0,    55,    41,    65,     0,    73,     0,
      67,     0,     0,     0,    71,    72,    68
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,  -150,   212,    23,    79,    10,  -150,   194,   188,
      30,  -150,   -35,  -150,   -94,   112,  -150,   -33,  -139,  -150,
     -50,  -150,  -150,  -150,   184,   142,  -150,  -150,  -149,  -150,
     -26,    65,  -150,   -32,  -150,   -21
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    40,    41,    16,    17,    21,    42,
      43,    81,    44,    45,   113,    61,    62,    46,    47,    48,
      49,    50,    51,    52,    53,    92,    54,    55,   111,   199,
      82,   136,    57,   135,    84,    18
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      56,   180,    56,    83,    90,    58,    91,    58,   178,   179,
      97,   121,   122,    56,    99,   110,   114,    56,    93,   149,
       7,    56,    30,     5,    19,     1,     5,    34,    87,    30,
       8,   107,   108,    27,    34,     1,    30,    31,     9,    32,
      33,    34,   198,    35,   152,    13,    36,   117,    88,    11,
      37,   196,   131,    14,    89,    90,   137,   139,   182,   143,
     183,   201,   202,    88,   206,   149,    56,   138,    38,   116,
      94,    95,   145,    39,    98,   119,   120,   121,   122,     6,
      12,    15,     6,    20,   156,    22,    23,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,    24,
     110,   172,   114,    26,   114,    25,    30,    31,    28,    32,
      33,    34,     1,    35,    63,    64,    36,    60,    66,   181,
      37,    56,    56,   184,    31,    65,    32,    33,    39,    86,
      35,    96,   103,    36,   100,   101,   109,    37,    38,   186,
     102,   110,   137,    39,   104,    31,   105,    32,    33,   106,
     112,    35,   115,   138,    36,    38,   194,   118,    37,   132,
      39,   142,   133,   149,    56,    67,   141,   144,    68,    69,
     150,    70,   151,   153,   158,   154,    38,    56,   155,    71,
     171,    39,    72,    73,    74,    75,    76,    77,   134,    78,
      67,   173,    79,    68,    69,   188,    70,   176,   189,   190,
      80,   195,   200,   197,    71,   203,   204,    72,    73,    74,
      75,    76,    77,   205,    78,    10,    59,    79,   146,    29,
      85,   119,   120,   121,   122,    80,   123,   124,   125,   126,
     127,   128,   140,   129,   130,   119,   120,   121,   122,   187,
     123,   124,   125,   126,   127,   128,     0,   129,   130,     0,
       0,     0,   175,     0,     0,   119,   120,   121,   122,     0,
     123,   124,   125,   126,   127,   128,   177,   129,   130,   119,
     120,   121,   122,     0,   123,   124,   125,   126,   127,   128,
       0,   129,   130,     0,     0,     0,   185,     0,     0,   119,
     120,   121,   122,     0,   123,   124,   125,   126,   127,   128,
     192,   129,   130,   119,   120,   121,   122,     0,   123,   124,
     125,   126,   127,   128,     0,   129,   130,     0,   174,     0,
     119,   120,   121,   122,     0,   123,   124,   125,   126,   127,
     128,   191,   129,   130,   119,   120,   121,   122,     0,   123,
     124,   125,   126,   127,   128,   147,   129,   130,   119,   120,
     121,   122,     0,   123,   124,   125,   126,   127,   128,   148,
     129,   130,   119,   120,   121,   122,     0,   123,   124,   125,
     126,   127,   128,   157,   129,   130,   119,   120,   121,   122,
       0,   123,   124,   125,   126,   127,   128,   193,   129,   130,
     119,   120,   121,   122,     0,     0,   124,   125,   126,   127,
     128,     0,   129,   130,   119,   120,   121,   122,     0,     0,
     124,   125,   126,   127,   128,     0,   129,   119,   120,   121,
     122,     0,     0,     0,   125,   126,   127,   128
};

static const yytype_int16 yycheck[] =
{
      26,   150,    28,    35,    39,    26,    39,    28,   147,   148,
      43,    17,    18,    39,    47,    65,    66,    43,    39,    19,
       3,    47,     4,     0,    14,    10,     3,     9,    19,     4,
      13,    63,    64,    23,     9,    10,     4,     5,     0,     7,
       8,     9,   191,    11,    44,    39,    14,    79,    39,    36,
      18,   190,    84,    39,    45,    90,    88,    89,   152,    92,
     154,    15,    16,    39,   203,    19,    92,    88,    36,    45,
      40,    41,   104,    41,    44,    15,    16,    17,    18,     0,
      36,     3,     3,    36,   116,    40,    43,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    40,
     150,   133,   152,    41,   154,    44,     4,     5,    41,     7,
       8,     9,    10,    11,    39,    39,    14,    36,     3,   151,
      18,   147,   148,   155,     5,    39,     7,     8,    41,    36,
      11,    42,    42,    14,    43,    43,    36,    18,    36,   171,
      43,   191,   174,    41,    45,     5,    43,     7,     8,    44,
      36,    11,    36,   174,    14,    36,   188,    36,    18,     7,
      41,    42,    19,    19,   190,    12,    42,    42,    15,    16,
      44,    18,    43,    43,    47,    44,    36,   203,    45,    26,
      39,    41,    29,    30,    31,    32,    33,    34,    35,    36,
      12,    40,    39,    15,    16,    19,    18,    42,    19,     6,
      47,    35,    43,    36,    26,    40,    15,    29,    30,    31,
      32,    33,    34,    16,    36,     3,    28,    39,   106,    25,
      36,    15,    16,    17,    18,    47,    20,    21,    22,    23,
      24,    25,    90,    27,    28,    15,    16,    17,    18,   174,
      20,    21,    22,    23,    24,    25,    -1,    27,    28,    -1,
      -1,    -1,    46,    -1,    -1,    15,    16,    17,    18,    -1,
      20,    21,    22,    23,    24,    25,    46,    27,    28,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    24,    25,
      -1,    27,    28,    -1,    -1,    -1,    46,    -1,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    24,    25,
      46,    27,    28,    15,    16,    17,    18,    -1,    20,    21,
      22,    23,    24,    25,    -1,    27,    28,    -1,    44,    -1,
      15,    16,    17,    18,    -1,    20,    21,    22,    23,    24,
      25,    43,    27,    28,    15,    16,    17,    18,    -1,    20,
      21,    22,    23,    24,    25,    40,    27,    28,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    24,    25,    40,
      27,    28,    15,    16,    17,    18,    -1,    20,    21,    22,
      23,    24,    25,    40,    27,    28,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    24,    25,    40,    27,    28,
      15,    16,    17,    18,    -1,    -1,    21,    22,    23,    24,
      25,    -1,    27,    28,    15,    16,    17,    18,    -1,    -1,
      21,    22,    23,    24,    25,    -1,    27,    15,    16,    17,
      18,    -1,    -1,    -1,    22,    23,    24,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    49,    50,    51,    52,    53,     3,    13,     0,
      51,    36,    36,    39,    39,     3,    54,    55,    83,    54,
      36,    56,    40,    43,    40,    44,    41,    54,    41,    56,
       4,     5,     7,     8,     9,    11,    14,    18,    36,    41,
      52,    53,    57,    58,    60,    61,    65,    66,    67,    68,
      69,    70,    71,    72,    74,    75,    78,    80,    83,    57,
      36,    63,    64,    39,    39,    39,     3,    12,    15,    16,
      18,    26,    29,    30,    31,    32,    33,    34,    36,    39,
      47,    59,    78,    81,    82,    72,    36,    19,    39,    45,
      60,    65,    73,    83,    58,    58,    42,    65,    58,    65,
      43,    43,    43,    42,    45,    43,    44,    81,    81,    36,
      68,    76,    36,    62,    68,    36,    45,    81,    36,    15,
      16,    17,    18,    20,    21,    22,    23,    24,    25,    27,
      28,    81,     7,    19,    35,    81,    79,    81,    83,    81,
      73,    42,    42,    65,    42,    81,    63,    40,    40,    19,
      44,    43,    44,    43,    44,    45,    81,    40,    47,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    39,    81,    40,    44,    46,    42,    46,    66,    66,
      76,    81,    62,    62,    81,    46,    81,    79,    19,    19,
       6,    43,    46,    40,    81,    35,    66,    36,    76,    77,
      43,    15,    16,    40,    15,    16,    66
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    52,    53,    54,
      54,    54,    55,    56,    56,    57,    57,    57,    57,    58,
      58,    58,    58,    58,    58,    59,    59,    59,    59,    59,
      59,    60,    60,    61,    62,    62,    62,    62,    63,    63,
      64,    64,    65,    65,    66,    66,    66,    66,    66,    66,
      67,    67,    67,    67,    68,    69,    70,    71,    72,    72,
      72,    72,    73,    73,    74,    74,    75,    75,    75,    76,
      76,    77,    77,    77,    78,    79,    79,    79,    80,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      82,    82,    82,    82,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     9,     9,     3,
       1,     1,     2,     3,     1,     2,     1,     1,     1,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     3,     3,     1,     1,     3,     1,
       4,     6,     1,     2,     2,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     3,     6,     3,     4,     4,     3,
       3,     3,     2,     1,     5,     7,     5,     7,     9,     3,
       1,     3,     3,     1,     4,     3,     1,     1,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     1,     1,     1,     3,     3,     2,     5,     4,
       1,     1,     1,     1,     0
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
#line 117 "parser.y" /* yacc.c:1646  */
    { startSemantics((yyvsp[0].node)); printTree((yyvsp[0].node),0); freeTree((yyvsp[0].node));}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 121 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("CODE",1, (yyvsp[0].node)); }
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 122 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("CODE",(yyvsp[-1].node), mknode("CODE",1,(yyvsp[0].node))); }
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 126 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 127 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 133 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("FUNCTION",4,mknode((yyvsp[-6].string),0),(yyvsp[-4].node),mknode("TYPE",1,mknode((yyvsp[-7].string),0)),(yyvsp[-1].node)); }
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 137 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("FUNCTION",4,mknode((yyvsp[-6].string),0),(yyvsp[-4].node),mknode("TYPE",1,mknode("VOID",0)),(yyvsp[-1].node));}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("ARGS",(yyvsp[-2].node),(yyvsp[0].node)); }
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 143 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("ARGS",1,mknode("NONE",0)); }
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0].node)->token = strdup((yyvsp[-1].string)); (yyval.node) = mknode("ARGS",1, (yyvsp[0].node)); }
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("ARGS", mknode((yyvsp[-2].string),0), (yyvsp[0].node)); }
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 152 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("ARGS",1,mknode((yyvsp[0].string),0)); }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("BODY",(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 157 "parser.y" /* yacc.c:1646  */
    { free((yyvsp[0].node)->token); (yyvsp[0].node)->token=strdup("BODY"); (yyval.node)=(yyvsp[0].node); }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 158 "parser.y" /* yacc.c:1646  */
    { free((yyvsp[0].node)->token); (yyvsp[0].node)->token =strdup("BODY"); (yyval.node)=(yyvsp[0].node); }
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 159 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("BODY",1,mknode("NONE",0)); }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 163 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("BODY",mknode("BODY",1,(yyvsp[-1].node)),(yyvsp[0].node)); }
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 164 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("BODY",1,(yyvsp[0].node)); }
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 165 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("BODY",mknode("BODY",1,(yyvsp[-1].node)),(yyvsp[0].node)); }
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 166 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("BODY",1,(yyvsp[0].node)); }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 167 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("BODY",mknode("BODY",1,(yyvsp[-1].node)),(yyvsp[0].node)); }
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 168 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("BODY",1,(yyvsp[0].node)); }
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 174 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("bool",1,mknode((yyvsp[0].string),0)); }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 175 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("char",1,mknode((yyvsp[0].string),0)); }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 176 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("int",1,mknode((yyvsp[0].string),0)); }
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("int",1,mknode((yyvsp[0].string),0)); }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 178 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("real",1,mknode((yyvsp[0].string),0)); }
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("null",1,mknode("0",0)); }
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 185 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 186 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 190 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("VAR", mknode("VAR",1,mknode((yyvsp[-2].string),0)), (yyvsp[-1].node)); }
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 194 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("VAR", mknode("VAR",1,mknode((yyvsp[-2].string),0)), (yyvsp[0].node)); }
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 195 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("VAR", mknode("ASS",1,(yyvsp[-2].node)) ,(yyvsp[0].node)); }
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 196 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[0].string),0); }
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 197 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("ASS",1,(yyvsp[0].node)); }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 201 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("STRING", (yyvsp[-2].node), (yyvsp[0].node));}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 202 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 206 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("STRING",1,mknode((yyvsp[-3].string),1,(yyvsp[-1].node))); }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 207 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("STRING",1,mknode((yyvsp[-1].string),3,mknode((yyvsp[-5].string),0),(yyvsp[-3].node),mknode((yyvsp[0].string),0))); }
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 213 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("stmt",1,(yyvsp[0].node)); }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 214 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("Statments", mknode("stmt",1,(yyvsp[-1].node)),(yyvsp[0].node));}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 218 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 219 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 220 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 221 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 223 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 229 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 230 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 231 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 232 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 236 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2, mknode((yyvsp[-2].string),0), (yyvsp[0].node)); }
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 239 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),3,mknode((yyvsp[-5].string),0),(yyvsp[-3].node),(yyvsp[0].node)); }
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 242 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,mknode((yyvsp[-2].string),0),mknode((yyvsp[0].string),0)); }
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 245 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string), 1 , mknode("POINTER", 2, mknode((yyvsp[-2].string),0), (yyvsp[0].node),0)); }
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 250 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("BLOCK",(yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 251 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 252 "parser.y" /* yacc.c:1646  */
    {free((yyvsp[-1].node)->token); (yyvsp[-1].node)-> token = strdup("BLOCK"); (yyval.node) = (yyvsp[-1].node); }
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 253 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("BLOCK",1,mknode("NONE",0)); }
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 256 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("BLOCK", mknode("BLOCK",1,(yyvsp[-1].node)), (yyvsp[0].node));}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 257 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("BLOCK", 1, (yyvsp[0].node));}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 263 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("IF", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 264 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("IF-ELSE", 3, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 270 "parser.y" /* yacc.c:1646  */
    { (yyval.node) =	mknode("WHILE", 2, (yyvsp[-2].node) , (yyvsp[0].node)); }
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 271 "parser.y" /* yacc.c:1646  */
    { (yyval.node) =	mknode("DO-WHILE", 2, (yyvsp[-2].node), (yyvsp[-5].node)); }
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 272 "parser.y" /* yacc.c:1646  */
    { 
																					free((yyvsp[-6].node)->token); (yyvsp[-6].node)->token = strdup("INIT");
																					(yyval.node) = mknode("FOR",4,(yyvsp[-6].node),mknode("COND",1,(yyvsp[-4].node)),(yyvsp[-2].node), (yyvsp[0].node));
																				}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 279 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("ass", mknode("ass",1,(yyvsp[-2].node)),(yyvsp[0].node)); }
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 280 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("ass",1,(yyvsp[0].node)); }
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 283 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("UPDATE",1,mknode("=",1, mknode("+", 2, mknode((yyvsp[-2].string),0), mknode("1",0)))); }
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 284 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("UPDATE",1,mknode("=",1, mknode("-", 2, mknode((yyvsp[-2].string),0), mknode("1",0)))); }
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 285 "parser.y" /* yacc.c:1646  */
    { free((yyvsp[0].node)->token); (yyvsp[0].node)-> token = strdup("UPDATE"); (yyval.node) = (yyvsp[0].node); }
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 291 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("FUNC-CALL", mknode((yyvsp[-3].string),0), (yyvsp[-1].node)); }
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 294 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("paramters",mknode("param",1,(yyvsp[-2].node)), (yyvsp[0].node));}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 295 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("paramters",1,(yyvsp[0].node)); }
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 296 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("NONE",0); }
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 302 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("RET",1,(yyvsp[0].node)); }
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 308 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 309 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 310 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 311 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 312 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 313 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 314 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 315 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 316 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 317 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 318 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 319 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 320 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),1,(yyvsp[0].node));}
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 321 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 322 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[0].string),0); }
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 323 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 324 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("STR_LEN",1,mknode((yyvsp[-1].string),0)); }
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 325 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 326 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("ADDRESS-OF",1,mknode((yyvsp[0].string),0)); }
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 327 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("ADDRESS-OF",2,mknode((yyvsp[-3].string),0),(yyvsp[-1].node));}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 328 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-3].string),1,(yyvsp[-1].node)); }
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 332 "parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 333 "parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 334 "parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 335 "parser.y" /* yacc.c:1646  */
    { (yyval.string) = "POINTER";}
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2151 "y.tab.c" /* yacc.c:1646  */
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
#line 340 "parser.y" /* yacc.c:1906  */



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
			if (checkDupVar(stable, tree->subNodes[i]->token))
				addVar(stable, mkvar(tree->subNodes[i]->token, type));
			else {
				printf("Error: Duplicate variable name - %s\n", tree->subNodes[i]->token);
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

table *mktable(table *upperEnv) {
	table *newtable = (table*)malloc(sizeof(table));
	newtable->upperEnv = upperEnv;
	newtable->functions = NULL;
	newtable->variables = NULL;
	newtable->returnType = -1;
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
	table *global = mktable(NULL);
	checkTree(tree, global,tree);
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
				
			else if (!strcmp(subTree->subNodes[2]->subNodes[0]->token, "VOID")) {
				printf("Error: main type can only be void\n");
				quitProgram(tree);
			}

			else if (numOfArgs(subTree->subNodes[1]) != 0) {
				printf("Error: main cannot have arguments\n");
				quitProgram(tree);
			}
		}
		else if (checkDupFunc(env, subTree->subNodes[0]->token)) {
			func *func = mkfunc(subTree->subNodes[0]->token, getTypeVal(subTree->subNodes[2]->subNodes[0]->token), numOfArgs(subTree->subNodes[1]), argumentRep(subTree->subNodes[1]));
			addFunc(env, func);
			table *newEnv = mktable(env);
			insertArgs(newEnv, (subTree->subNodes[1]), tree);
			checkTree(subTree->subNodes[3], newEnv, tree);
			free(newEnv);
		}
		else {
			printf("Error: Duplicate function name - %s\n", subTree->subNodes[0]->token);
			quitProgram(tree);
		}
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
		evalExp(subTree->subNodes[0], env);
		checkTree(subTree->subNodes[1],env, tree);
	}

	//if-else
	else if (!strcmp(subTree->token, "IF-ELSE")) {
		evalExp(subTree->subNodes[0], env);
		checkTree(subTree->subNodes[1], env, tree);
		checkTree(subTree->subNodes[2], env, tree);
	}
	//while
	else if (!strcmp(subTree->token, "WHILE")) {
		evalExp(subTree->subNodes[0], env);
		checkTree(subTree->subNodes[1], env, tree);
	}
	//do while
	else if (!strcmp(subTree->token, "DO-WHILE")) {
		evalExp(subTree->subNodes[0], env);
		checkTree(subTree->subNodes[1], env, tree);
	}
	//for
	else if (!strcmp(subTree->token, "FOR")) {
		for (int i = 0; i < subTree->numOfSubNodes; i++) {
			checkTree(subTree->subNodes[i], env, tree);
		}
	}
	//for-init
	else if (!strcmp(subTree->token, "INIT")) {
		for (int i = 0; i < subTree->numOfSubNodes; i++) {
			evalExp(subTree->subNodes[i], env);
		}
	}
	//for-condition
	else if (!strcmp(subTree->token, "COND")) {
		evalExp(subTree->subNodes[0], env);
	}
	//for-update
	else if (!strcmp(subTree->token, "UPDATE")) {
		for (int i = 0; i < subTree->numOfSubNodes; i++) {
			evalExp(subTree->subNodes[i],env);
		}
	}
	//function call
	else if (!strcmp(subTree->token, "FUNC-CALL")) {
		if (!funcCallCheck(subTree, env)) {
			quitProgram(tree);
		}
	}

	printTable(env);
	printf("---------\n");
}

void evalExp(node *tree, table* stable) {
	return ;
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
	exit(1);
}

bool funcCallCheck(node* tree, table *env) {
	if (checkFuncExist(env, tree->subNodes[0]->token)) {
		printf("Error: calling function %s that does not exist\n", tree->subNodes[0]->token);
		return false;
	}
	else if (getFuncNumOfArgs(tree->subNodes[0]->token, env) != tree->numOfSubNodes - 1) {
		printf("Error: number of arguments does not match calling function %s\n", tree->subNodes[0]->token);
		return false;
	}
	for(int i=1; i<tree->numOfSubNodes;i++){
		if (!checkVarExist(env, tree->subNodes[i]->token)) {
			printf("Error: variable %s does not exist\n", tree->subNodes[i]->token);
			return false;
		}
	}
	int *args = getFuncArgsTypes(tree->subNodes[0]->token, env);
	for (int i = 1; i < tree->numOfSubNodes; i++) {
		if (getVarType(env, tree->subNodes[i]->token) != args[i-1]) {
			printf("Error: variable %s does not match expected type\n", tree->subNodes[i]->token);
			return false;
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


