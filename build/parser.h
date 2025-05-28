/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_IDENT = 258,
     T_STRING = 259,
     T_FLOAT = 260,
     T_CHAR = 261,
     T_NUMBER = 262,
     T_BOOL = 263,
     T_VAR = 264,
     T_IF = 265,
     T_DISPLAY = 266,
     T_PRINT = 267,
     T_ASSIGN = 268,
     T_LPAREN = 269,
     T_RPAREN = 270,
     T_EOL = 271,
     T_PLUS = 272,
     T_MINUS = 273,
     T_MULT = 274,
     T_DIV = 275,
     T_MOD = 276,
     T_EXP = 277,
     T_REPEAT = 278,
     T_LBRACE = 279,
     T_RBRACE = 280,
     T_ELSE = 281,
     T_FOR = 282,
     T_WHILE = 283,
     T_CONST = 284,
     T_SEMI = 285,
     T_FUNCTION = 286,
     T_RETURN = 287,
     T_COMMA = 288,
     T_EQ = 289,
     T_NEQ = 290,
     T_GT = 291,
     T_LT = 292,
     T_GE = 293,
     T_LE = 294,
     T_EQ_KEYWORD = 295,
     T_NEQ_KEYWORD = 296,
     T_ASK = 297,
     T_AND = 298,
     T_SAVE = 299,
     T_AS = 300,
     T_INPUT = 301
   };
#endif
/* Tokens.  */
#define T_IDENT 258
#define T_STRING 259
#define T_FLOAT 260
#define T_CHAR 261
#define T_NUMBER 262
#define T_BOOL 263
#define T_VAR 264
#define T_IF 265
#define T_DISPLAY 266
#define T_PRINT 267
#define T_ASSIGN 268
#define T_LPAREN 269
#define T_RPAREN 270
#define T_EOL 271
#define T_PLUS 272
#define T_MINUS 273
#define T_MULT 274
#define T_DIV 275
#define T_MOD 276
#define T_EXP 277
#define T_REPEAT 278
#define T_LBRACE 279
#define T_RBRACE 280
#define T_ELSE 281
#define T_FOR 282
#define T_WHILE 283
#define T_CONST 284
#define T_SEMI 285
#define T_FUNCTION 286
#define T_RETURN 287
#define T_COMMA 288
#define T_EQ 289
#define T_NEQ 290
#define T_GT 291
#define T_LT 292
#define T_GE 293
#define T_LE 294
#define T_EQ_KEYWORD 295
#define T_NEQ_KEYWORD 296
#define T_ASK 297
#define T_AND 298
#define T_SAVE 299
#define T_AS 300
#define T_INPUT 301




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 166 "src/compiler/pebble.y"
{
  int num;
  char* str;
  struct {
    char* str;
    enum VarType type;
  } expr_val;
  struct ArgList* arg_list_val;
}
/* Line 1529 of yacc.c.  */
#line 151 "build/parser.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

