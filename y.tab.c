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
#line 1 "project.y" /* yacc.c:339  */


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


#line 91 "y.tab.c" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    UNARY = 292
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
#define UNARY 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 28 "project.y" /* yacc.c:355  */

	char *string;
	struct node *node;

#line 210 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 227 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   352

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

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
      38,    39,     2,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,    46,    41,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    65,    65,    67,    68,    70,    71,    77,    84,    88,
      89,    90,    93,    97,    98,   102,   103,   104,   105,   109,
     110,   111,   112,   113,   114,   120,   121,   122,   123,   124,
     125,   131,   132,   136,   140,   141,   142,   143,   147,   148,
     152,   153,   158,   159,   162,   163,   164,   165,   166,   167,
     173,   174,   175,   179,   182,   185,   190,   191,   192,   193,
     199,   200,   206,   207,   212,   215,   216,   217,   222,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   248,   249,   250,
     252
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
  "HEXINTVAL", "REALVAL", "STRINGVAL", "ID", "UNARY", "'('", "')'", "'{'",
  "'}'", "';'", "','", "'['", "']'", "'|'", "$accept", "initial",
  "program", "cmd", "function", "procedure", "parameter_list", "type_list",
  "param", "body", "declarations", "primitive_val", "declaration",
  "primitive_declaration", "declaration_parameters", "string_declaration",
  "string_parameters", "nested_statements", "stmt", "assign",
  "primitive_assign", "index_assign", "string_assign", "code_block",
  "conditions", "loops", "procedure_func_call", "expression_list",
  "return", "expression", "unary_op", "epsilon", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,    40,    41,
     123,   125,    59,    44,    91,    93,   124
};
# endif

#define YYPACT_NINF -129

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-129)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,     5,    20,     3,  -129,  -129,  -129,   -11,    -5,  -129,
    -129,     0,     7,    40,    40,    22,    10,    26,  -129,    30,
      21,  -129,    45,    40,    49,    22,    25,  -129,    25,  -129,
      55,    58,    62,   100,   144,    64,     2,    83,    13,    13,
      67,   102,    13,  -129,  -129,   102,    68,  -129,  -129,  -129,
    -129,  -129,  -129,    69,    70,  -129,    73,    71,    75,    78,
     144,   144,    86,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,    87,    90,  -129,  -129,   285,   144,   120,   119,
     144,   144,    88,    92,    95,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,   144,  -129,    55,   225,   245,
     -10,    99,    94,    97,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   114,   106,  -129,
     285,   107,   211,  -129,   171,  -129,   116,  -129,  -129,   185,
    -129,   102,   102,   144,    86,  -129,    86,  -129,    24,    24,
     114,   114,   299,   326,    37,    37,    37,    37,   285,   326,
     313,   144,  -129,   144,   128,  -129,   129,   152,  -129,  -129,
    -129,   265,  -129,   144,   126,   102,   121,   285,  -129,  -129,
    -129
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     3,     5,     6,     0,     0,     1,
       4,     0,     0,    90,    90,     0,     0,    10,    11,     0,
      14,    12,     0,     0,     0,     0,    90,     9,    90,    13,
       0,     0,     0,     0,     0,     0,     0,    90,    22,    24,
       0,    16,    20,    31,    17,    42,     0,    50,    51,    52,
      45,    46,    47,     0,     0,    18,     0,     0,     0,    39,
       0,     0,     0,    30,    87,    88,    89,    25,    26,    27,
      28,    29,    84,     0,    83,    85,    68,     0,     0,     0,
      90,     0,     0,     0,     0,    21,    23,     7,    15,    19,
      43,    44,    48,    49,     8,     0,    32,     0,     0,     0,
      36,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,     0,    55,
      53,     0,    66,    67,     0,    57,     0,    58,    59,     0,
      38,     0,     0,     0,     0,    33,     0,    86,    69,    70,
      71,    72,    73,    75,    77,    78,    79,    80,    81,    76,
      74,     0,    64,    90,     0,    56,    40,    60,    62,    34,
      35,     0,    65,     0,     0,     0,     0,    54,    41,    61,
      63
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,  -129,   159,    57,    98,   150,   143,   142,   140,
      28,  -129,   132,  -129,  -110,    74,  -129,   -31,  -128,  -129,
     -50,  -129,  -129,   137,  -129,  -129,   -26,    29,  -129,   -33,
    -129,   -21
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    38,    39,    16,    17,    21,    40,
      41,    74,    42,    43,   101,    58,    59,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    75,   121,    54,   120,
      77,    18
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      53,    76,    53,   157,   158,    55,    83,    55,     7,   133,
      88,    53,   102,     1,    90,    53,    84,    30,     8,    53,
       9,    79,    33,     1,   159,    11,   160,    98,    99,    30,
      31,    12,    32,   134,    33,     1,    34,   169,    13,    35,
      80,   106,   107,    15,   117,    14,    81,   122,   124,    22,
     114,   126,   104,   105,   106,   107,    53,     5,    20,   123,
       5,    36,   129,   114,    25,    37,    85,    86,    23,    24,
      89,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   102,    26,   102,    30,    31,    28,
      32,    57,    33,    31,    34,    32,    60,    35,     6,    34,
      61,     6,    35,    62,    37,    53,    53,    31,    87,    32,
      91,    92,    93,    34,    94,    95,    35,    96,   161,    36,
     122,    97,   100,    37,    36,    80,   103,   118,    37,   125,
     167,    63,   123,   127,    64,    65,   128,   136,    36,    53,
     114,   135,    37,   137,   151,    66,   152,   163,   164,    67,
      68,    69,    70,    71,   119,    72,    63,   155,   165,    64,
      65,   168,    10,   170,    19,    73,    27,    29,    56,    82,
      66,   130,    78,     0,    67,    68,    69,    70,    71,     0,
      72,     0,   162,     0,     0,     0,   104,   105,   106,   107,
      73,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     104,   105,   106,   107,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,     0,   154,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     156,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     104,   105,   106,   107,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   153,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   131,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   132,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   166,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   104,   105,   106,   107,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   104,   105,
     106,   107,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   104,   105,   106,   107,     0,     0,     0,   110,   111,
     112,   113,   114
};

static const yytype_int16 yycheck[] =
{
      26,    34,    28,   131,   132,    26,    37,    28,     3,    19,
      41,    37,    62,    10,    45,    41,    37,     4,    13,    45,
       0,    19,     9,    10,   134,    36,   136,    60,    61,     4,
       5,    36,     7,    43,     9,    10,    11,   165,    38,    14,
      38,    17,    18,     3,    77,    38,    44,    80,    81,    39,
      26,    82,    15,    16,    17,    18,    82,     0,    36,    80,
       3,    36,    95,    26,    43,    40,    38,    39,    42,    39,
      42,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   134,    40,   136,     4,     5,    40,
       7,    36,     9,     5,    11,     7,    38,    14,     0,    11,
      38,     3,    14,     3,    40,   131,   132,     5,    41,     7,
      42,    42,    42,    11,    41,    44,    14,    42,   151,    36,
     153,    43,    36,    40,    36,    38,    36,     7,    40,    41,
     163,    12,   153,    41,    15,    16,    41,    43,    36,   165,
      26,    42,    40,    46,    38,    26,    39,    19,    19,    30,
      31,    32,    33,    34,    35,    36,    12,    41,     6,    15,
      16,    35,     3,    42,    14,    46,    23,    25,    28,    37,
      26,    97,    35,    -1,    30,    31,    32,    33,    34,    -1,
      36,    -1,   153,    -1,    -1,    -1,    15,    16,    17,    18,
      46,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      15,    16,    17,    18,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      45,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      15,    16,    17,    18,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    43,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    39,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    39,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    39,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    15,    16,    17,    18,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    15,    16,
      17,    18,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    15,    16,    17,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    48,    49,    50,    51,    52,     3,    13,     0,
      50,    36,    36,    38,    38,     3,    53,    54,    78,    53,
      36,    55,    39,    42,    39,    43,    40,    54,    40,    55,
       4,     5,     7,     9,    11,    14,    36,    40,    51,    52,
      56,    57,    59,    60,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    75,    78,    56,    36,    62,    63,
      38,    38,     3,    12,    15,    16,    26,    30,    31,    32,
      33,    34,    36,    46,    58,    73,    76,    77,    70,    19,
      38,    44,    59,    64,    78,    57,    57,    41,    64,    57,
      64,    42,    42,    42,    41,    44,    42,    43,    76,    76,
      36,    61,    67,    36,    15,    16,    17,    18,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    76,     7,    35,
      76,    74,    76,    78,    76,    41,    64,    41,    41,    76,
      62,    39,    39,    19,    43,    42,    43,    46,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    38,    39,    43,    45,    41,    45,    65,    65,    61,
      61,    76,    74,    19,    19,     6,    39,    76,    35,    65,
      42
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    52,    53,
      53,    53,    54,    55,    55,    56,    56,    56,    56,    57,
      57,    57,    57,    57,    57,    58,    58,    58,    58,    58,
      58,    59,    59,    60,    61,    61,    61,    61,    62,    62,
      63,    63,    64,    64,    65,    65,    65,    65,    65,    65,
      66,    66,    66,    67,    68,    69,    70,    70,    70,    70,
      71,    71,    72,    72,    73,    74,    74,    74,    75,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    77,    77,    77,
      78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     9,     9,     3,
       1,     1,     2,     3,     1,     2,     1,     1,     1,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     3,     3,     1,     1,     3,     1,
       4,     6,     1,     2,     2,     1,     1,     1,     2,     2,
       1,     1,     1,     3,     6,     3,     4,     3,     3,     3,
       5,     7,     5,     7,     4,     3,     1,     1,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     1,     1,     3,     1,     1,     1,
       0
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
#line 65 "project.y" /* yacc.c:1646  */
    { printTree((yyvsp[0].node),0); }
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 67 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("CODE",1, (yyvsp[0].node)); }
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 68 "project.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("CODE",(yyvsp[-1].node), mknode("CODE",1,(yyvsp[0].node))); }
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 70 "project.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 71 "project.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 77 "project.y" /* yacc.c:1646  */
    { 
										char *string =(char*)malloc((6+strlen((yyvsp[-7].string))) * sizeof(char));
										strcat(string,"TYPE "); 
										(yyval.node) = mknode("FUNCTION",4,mknode((yyvsp[-6].string),0),(yyvsp[-4].node),mknode(strcat(string,(yyvsp[-7].string)),0),(yyvsp[-1].node)); 
									}
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 84 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("FUNCTION",4,mknode((yyvsp[-6].string),0),(yyvsp[-4].node),mknode("TYPE VOID",0),(yyvsp[-1].node));}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 88 "project.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("ARGS",(yyvsp[-2].node),(yyvsp[0].node)); }
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 89 "project.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 90 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("ARGS",1,mknode("NONE",0)); }
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 93 "project.y" /* yacc.c:1646  */
    { (yyvsp[0].node)->token = strdup((yyvsp[-1].string)); (yyval.node) = mknode("ARGS",1, (yyvsp[0].node)); }
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 97 "project.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("ARGS", mknode((yyvsp[-2].string),0), (yyvsp[0].node)); }
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 98 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("ARGS",1,mknode((yyvsp[0].string),0)); }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 102 "project.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("BODY",(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 103 "project.y" /* yacc.c:1646  */
    { (yyvsp[0].node)->token =strdup("BODY"); (yyval.node)=(yyvsp[0].node); }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 104 "project.y" /* yacc.c:1646  */
    { (yyvsp[0].node)->token =strdup("BODY"); (yyval.node)=(yyvsp[0].node); }
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 105 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("BODY",1,mknode("NONE",0)); }
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 109 "project.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("BODY",mknode("BODY",1,(yyvsp[-1].node)),(yyvsp[0].node)); }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 110 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("BODY",1,(yyvsp[0].node)); }
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 111 "project.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("BODY",(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 112 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("BODY",1,(yyvsp[0].node)); }
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 113 "project.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("BODY",(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 114 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("BODY",1,(yyvsp[0].node)); }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 120 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[0].string),0); }
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 121 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[0].string),0); }
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 122 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[0].string),0); }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 123 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[0].string),0); }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 124 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[0].string),0); }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 125 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("NULL",0); }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 131 "project.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 132 "project.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 136 "project.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("VAR", mknode("VAR",1,mknode((yyvsp[-2].string),0)), (yyvsp[-1].node)); }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 140 "project.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("VAR", mknode("VAR",1,mknode((yyvsp[-2].string),0)), (yyvsp[0].node)); }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 141 "project.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("VAR", mknode("ASS",1,(yyvsp[-2].node)) ,(yyvsp[0].node)); }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 142 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[0].string),0); }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 143 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("ASS",1,(yyvsp[0].node)); }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 147 "project.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("STRING", mknode("STRING",1,(yyvsp[-2].node)), mknode("STRING",1,(yyvsp[0].node))); }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 148 "project.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 152 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-3].string),1,(yyvsp[-1].node)); }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 153 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),3,mknode((yyvsp[-5].string),0),(yyvsp[-3].node),mknode((yyvsp[0].string),0)); }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 158 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("stmt",1,(yyvsp[0].node)); }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 159 "project.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("Statments", mknode("stmt",1,(yyvsp[-1].node)),(yyvsp[0].node));}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 162 "project.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 163 "project.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 164 "project.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 165 "project.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 166 "project.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 167 "project.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 173 "project.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 174 "project.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 175 "project.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 179 "project.y" /* yacc.c:1646  */
    {(yyval.node) = mknode((yyvsp[-1].string),2, mknode((yyvsp[-2].string),0), (yyvsp[0].node)); }
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 182 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),3,mknode((yyvsp[-5].string),0),(yyvsp[-3].node),(yyvsp[0].node));}
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 185 "project.y" /* yacc.c:1646  */
    {(yyval.node) = mknode((yyvsp[-1].string),2,mknode((yyvsp[-2].string),0),mknode((yyvsp[0].string),0));}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 190 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("BLOCK",2, (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 191 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("BLOCK",1,(yyvsp[-1].node)); }
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 192 "project.y" /* yacc.c:1646  */
    { (yyvsp[-1].node)-> token = strdup("BLOCK"); (yyval.node) = (yyvsp[-1].node); }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 193 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("BLOCK",1,mknode("NONE",0)); }
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 199 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("IF", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 200 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("IF-ELSE", 3, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 206 "project.y" /* yacc.c:1646  */
    { (yyval.node) =	mknode("WHILE", 2, (yyvsp[-2].node) , (yyvsp[0].node)); }
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 207 "project.y" /* yacc.c:1646  */
    { (yyval.node) =	mknode("DO-WHILE", 2, (yyvsp[-2].node), (yyvsp[-5].node)); }
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 212 "project.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("FUNC_CALL", mknode((yyvsp[-3].string),0), (yyvsp[-1].node)); }
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 215 "project.y" /* yacc.c:1646  */
    { (yyval.node) = combineNodes("paramters", (yyvsp[-2].node), (yyvsp[0].node));}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 216 "project.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 217 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("NONE",0);}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 222 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("RET",1,(yyvsp[0].node)); }
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 228 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 229 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 230 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 231 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 232 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 233 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 234 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 235 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 236 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 237 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 238 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 239 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 240 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 241 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[-1].string),1,(yyvsp[0].node));}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 242 "project.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 243 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode((yyvsp[0].string),0); }
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 244 "project.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 245 "project.y" /* yacc.c:1646  */
    { (yyval.node) = mknode("STR_LEN",1,mknode((yyvsp[-1].string),0)); }
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 248 "project.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 249 "project.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 250 "project.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1995 "y.tab.c" /* yacc.c:1646  */
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
#line 255 "project.y" /* yacc.c:1906  */






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
//		free(one);
	}

	if (two->numOfSubNodes == 0) {
		newnode->subNodes[j] = two;
		j++;
	}
	else {
		for (i = 0, j; i < two->numOfSubNodes; i++, j++) {
			newnode->subNodes[j] = two->subNodes[i];
		}
//		free(two);
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
