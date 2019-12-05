/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
    IF = 259,
    ELSE = 260,
    WHILE = 261,
    FOR = 262,
    VAR = 263,
    FUNCTION = 264,
    RETURN = 265,
    NULLP = 266,
    VOID = 267,
    DO = 268,
    PLUS = 269,
    MINUS = 270,
    DIV = 271,
    MUL = 272,
    ASS = 273,
    AND = 274,
    EQ = 275,
    G = 276,
    GE = 277,
    L = 278,
    LE = 279,
    NOT = 280,
    NOTEQ = 281,
    OR = 282,
    ADDRESS = 283,
    BOOLVAL = 284,
    CHARVAL = 285,
    DECIMALINTVAL = 286,
    HEXINTVAL = 287,
    REALVAL = 288,
    STRINGVAL = 289,
    ID = 290
  };
#endif
/* Tokens.  */
#define VALTYPE 258
#define IF 259
#define ELSE 260
#define WHILE 261
#define FOR 262
#define VAR 263
#define FUNCTION 264
#define RETURN 265
#define NULLP 266
#define VOID 267
#define DO 268
#define PLUS 269
#define MINUS 270
#define DIV 271
#define MUL 272
#define ASS 273
#define AND 274
#define EQ 275
#define G 276
#define GE 277
#define L 278
#define LE 279
#define NOT 280
#define NOTEQ 281
#define OR 282
#define ADDRESS 283
#define BOOLVAL 284
#define CHARVAL 285
#define DECIMALINTVAL 286
#define HEXINTVAL 287
#define REALVAL 288
#define STRINGVAL 289
#define ID 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "project.y" /* yacc.c:1909  */

	char *string;
	int intVal;
	char charVal;
	struct node *node;

#line 131 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
