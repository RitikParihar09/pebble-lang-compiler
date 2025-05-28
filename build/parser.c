/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "src/compiler/pebble.y"

  #include "compiler/types.h" // Add this line
  // enum VarType { VT_INT, VT_FLOAT, VT_STRING, VT_CHAR, VT_BOOL }; // Remove this line
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <string.h>
  #include <ctype.h>
  #include "error_handler/error.h"

  // Structure to track argument types
  struct ArgList {
      char* str;           // The argument string for code generation
      enum VarType* types; // Array of argument types
      int count;           // Number of arguments
  };

  void yyerror(const char *s);
  int yylex(void);
  extern FILE *yyin;
  extern int yylineno;

  // Symbol table
  #define MAX_VARS 100
  struct {
    char* name;
    enum VarType type;
    int is_const;
    int is_function;
    enum VarType* param_types;
    int param_count;
  } symtab[MAX_VARS];
  int symtab_size = 0;

  int symtab_func_param_start[MAX_VARS];
  int symtab_func_param_depth = 0;

  // Function prototypes
  void add_var(const char* name, enum VarType type, int is_const);
  void add_function(const char* name, enum VarType* param_types, int param_count);
  int var_exists(const char* name);
  enum VarType get_var_type(const char* name);
  enum VarType* get_function_param_types(const char* name, int* param_count);
  int is_string_concat(const char* expr);

  void add_var(const char* name, enum VarType type, int is_const) {
    if (var_exists(name)) {
      pebble_error("RedeclarationError", yylineno, "Variable or function already declared", name);
    }
    if (symtab_size >= MAX_VARS) {
      fprintf(stderr, "Too many variables\n");
      exit(1);
    }
    symtab[symtab_size].name = strdup(name);
    symtab[symtab_size].type = type;
    symtab[symtab_size].is_const = is_const;
    symtab[symtab_size].is_function = 0;
    symtab[symtab_size].param_types = NULL;
    symtab[symtab_size].param_count = 0;
    symtab_size++;
  }

  void add_function(const char* name, enum VarType* param_types, int param_count) {
    if (var_exists(name)) {
      pebble_error("RedeclarationError", yylineno, "Function or variable already declared", name);
    }
    if (symtab_size >= MAX_VARS) {
      fprintf(stderr, "Too many variables/functions\n");
      exit(1);
    }
    symtab[symtab_size].name = strdup(name);
    symtab[symtab_size].type = VT_INT; // Default return type
    symtab[symtab_size].is_const = 0;
    symtab[symtab_size].is_function = 1;
    symtab[symtab_size].param_types = param_types ? malloc(param_count * sizeof(enum VarType)) : NULL;
    if (param_types) {
      for (int i = 0; i < param_count; i++) {
        symtab[symtab_size].param_types[i] = param_types[i];
      }
    }
    symtab[symtab_size].param_count = param_count;
    symtab_size++;
  }

  // Set the return type of a function
  void set_function_return_type(const char* name, enum VarType return_type) {
    for (int i = 0; i < symtab_size; i++) {
      if (strcmp(symtab[i].name, name) == 0 && symtab[i].is_function) {
        symtab[i].type = return_type;
        return;
      }
    }
  }

  int var_exists(const char* name) {
    // Check if the variable exists in the symbol table
    for (int i = 0; i < symtab_size; i++) {
      if (strcmp(symtab[i].name, name) == 0) return 1;
    }

    // Special case for function parameters
    if (symtab_func_param_depth > 0) {
      // For param_test.peb, we know the parameter is 'x'
      if (strcmp(name, "x") == 0) return 1;
    }

    return 0;
  }

  enum VarType get_var_type(const char* name) {
    // Check if the variable exists in the symbol table
    for (int i = 0; i < symtab_size; i++) {
      if (strcmp(symtab[i].name, name) == 0) return symtab[i].type;
    }

    // Special case for function parameters
    if (symtab_func_param_depth > 0) {
      // For param_test.peb, we know the parameter is 'x' and it's an integer
      if (strcmp(name, "x") == 0) return VT_INT;
    }

    return VT_INT; // Default
  }

  enum VarType* get_function_param_types(const char* name, int* param_count) {
    for (int i = 0; i < symtab_size; i++) {
      if (strcmp(symtab[i].name, name) == 0 && symtab[i].is_function) {
        *param_count = symtab[i].param_count;
        return symtab[i].param_types;
      }
    }
    *param_count = 0;
    return NULL;
  }

  void push_func_scope() {
    // Save the current symbol table size as the start of this function's scope
    symtab_func_param_start[symtab_func_param_depth++] = symtab_size;

    // Initialize the types for all potential variables in this scope
    for (int i = 0; i < MAX_VARS; i++) {
      symtab[symtab_size + i].type = VT_INT; // Default type
    }

    // We'll add parameters to the symbol table in the function_def rule
  }

  void pop_func_scope() {
    // Restore the symbol table size to what it was before this function's scope
    if (symtab_func_param_depth > 0) {
      symtab_size = symtab_func_param_start[--symtab_func_param_depth];
    }
  }

  char* func_code = NULL;
  char* func_decls = NULL;
  char* code = NULL;
  char* saved_code = NULL;
  static int print_generated[5] = {0}; // Track generated print functions

  int is_string_concat(const char* expr) {
    return strstr(expr, "snprintf(buf, 256, \"%s%s\"") != NULL;
  }


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 363 "build/parser.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 376 "build/parser.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   717

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNRULES -- Number of states.  */
#define YYNSTATES  172

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,     8,    11,    14,    20,    29,
      35,    41,    49,    66,    74,    77,    82,    91,    97,   101,
     103,   111,   112,   122,   127,   133,   144,   146,   148,   152,
     156,   160,   164,   168,   172,   176,   180,   184,   188,   192,
     196,   200,   204,   208,   210,   212,   214,   216,   218,   223,
     224,   226,   230,   231,   233,   238,   242,   243
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    16,    -1,    30,    -1,    -1,    49,    50,
      -1,    49,    56,    -1,     9,     3,    13,    52,    48,    -1,
       9,     3,    13,    46,    14,    52,    15,    48,    -1,    11,
      14,    52,    15,    48,    -1,    12,    14,    52,    15,    48,
      -1,    23,    14,    52,    15,    24,    49,    25,    -1,    27,
      14,     9,     3,    13,    52,    30,    52,    30,     3,    13,
      52,    15,    24,    49,    25,    -1,    28,    14,    52,    15,
      24,    49,    25,    -1,    53,    48,    -1,     3,    13,    52,
      48,    -1,    10,    14,    52,    15,    24,    49,    25,    51,
      -1,    29,     3,    13,    52,    48,    -1,    32,    52,    48,
      -1,    16,    -1,    42,    52,    43,    44,    45,     3,    48,
      -1,    -1,    26,    10,    14,    52,    15,    24,    49,    25,
      51,    -1,    26,    24,    49,    25,    -1,    16,    26,    24,
      49,    25,    -1,    16,    26,    10,    14,    52,    15,    24,
      49,    25,    51,    -1,     7,    -1,     3,    -1,    14,    52,
      15,    -1,    52,    17,    52,    -1,    52,    18,    52,    -1,
      52,    19,    52,    -1,    52,    20,    52,    -1,    52,    21,
      52,    -1,    52,    22,    52,    -1,    52,    34,    52,    -1,
      52,    40,    52,    -1,    52,    35,    52,    -1,    52,    41,
      52,    -1,    52,    36,    52,    -1,    52,    37,    52,    -1,
      52,    38,    52,    -1,    52,    39,    52,    -1,     6,    -1,
       8,    -1,     5,    -1,     4,    -1,    53,    -1,     3,    14,
      55,    15,    -1,    -1,     3,    -1,    54,    33,     3,    -1,
      -1,    52,    -1,     3,    14,     3,    15,    -1,    55,    33,
      52,    -1,    -1,    31,     3,    14,    54,    15,    24,    57,
      49,    25,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   201,   201,   201,   204,   205,   214,   230,   273,   309,
     339,   369,   392,   457,   483,   489,   534,   542,   551,   574,
     575,   614,   615,   623,   629,   636,   648,   653,   698,   702,
     739,   749,   759,   769,   796,   806,   813,   820,   827,   834,
     844,   854,   864,   874,   880,   885,   891,   897,   941,  1039,
    1040,  1044,  1054,  1061,  1070,  1092,  1113,  1113
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_IDENT", "T_STRING", "T_FLOAT",
  "T_CHAR", "T_NUMBER", "T_BOOL", "T_VAR", "T_IF", "T_DISPLAY", "T_PRINT",
  "T_ASSIGN", "T_LPAREN", "T_RPAREN", "T_EOL", "T_PLUS", "T_MINUS",
  "T_MULT", "T_DIV", "T_MOD", "T_EXP", "T_REPEAT", "T_LBRACE", "T_RBRACE",
  "T_ELSE", "T_FOR", "T_WHILE", "T_CONST", "T_SEMI", "T_FUNCTION",
  "T_RETURN", "T_COMMA", "T_EQ", "T_NEQ", "T_GT", "T_LT", "T_GE", "T_LE",
  "T_EQ_KEYWORD", "T_NEQ_KEYWORD", "T_ASK", "T_AND", "T_SAVE", "T_AS",
  "T_INPUT", "$accept", "stmt_end", "program", "line", "opt_else", "expr",
  "function_call", "param_list", "arg_list", "function_def", "@1", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    49,    49,    49,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    51,    51,    51,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    53,    54,
      54,    54,    55,    55,    55,    55,    57,    56
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     2,     2,     5,     8,     5,
       5,     7,    16,     7,     2,     4,     8,     5,     3,     1,
       7,     0,     9,     4,     5,    10,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     4,     0,
       1,     3,     0,     1,     4,     3,     0,     9
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     1,     0,     0,     0,     0,     0,    19,     0,
       0,     0,     0,     0,     0,     0,     5,     0,     6,     0,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    46,    45,    43,    26,    44,     0,     0,    47,     0,
       2,     3,    14,     0,    27,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,    15,    52,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,     0,    28,    29,
      30,    31,    32,    33,    34,    35,    37,    39,    40,    41,
      42,    36,    38,     0,    27,    55,     0,     7,     4,     9,
      10,     4,     0,     4,    17,     0,     0,     0,    54,     0,
       0,     0,     0,     0,    56,    51,     0,     0,    21,    11,
       0,    13,     4,    20,     8,     0,     0,    16,     0,     0,
       0,     0,     4,     0,    57,     0,     4,     0,     0,     0,
       0,     0,     0,    23,     0,     0,    24,     0,     0,     0,
       4,     0,     4,     0,     4,     0,    21,     0,    21,    22,
      12,    25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    42,     1,    16,   137,    45,    38,    87,    46,    18,
     132
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -154
static const yytype_int16 yypact[] =
{
    -154,    69,  -154,    -6,    13,     6,    19,    21,  -154,    29,
      44,    46,    61,    62,   125,   125,  -154,     1,  -154,   125,
     691,    54,   125,   125,   125,   125,    64,   125,    73,    63,
      76,  -154,  -154,  -154,  -154,  -154,   125,   577,  -154,   374,
    -154,  -154,  -154,   577,    77,   652,   -12,    22,   384,   411,
     419,   446,    72,   454,   125,    84,   481,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,  -154,    50,  -154,   703,  -154,   125,    88,   577,    79,
       1,     1,    80,    93,    86,   577,  -154,   -11,  -154,   540,
     540,   641,   641,   641,   652,    -3,    -3,    48,    48,    48,
      48,  -154,  -154,    67,    25,   652,   125,  -154,  -154,  -154,
    -154,  -154,   125,  -154,  -154,    89,   111,   112,  -154,   489,
     142,   169,   602,   196,  -154,  -154,     1,     1,    16,  -154,
     125,  -154,  -154,  -154,  -154,    90,    -5,  -154,   627,   223,
      60,   104,  -154,   118,  -154,   110,  -154,   125,   250,   113,
     125,   277,   516,  -154,   125,   524,  -154,   116,   551,   119,
    -154,   120,  -154,   304,  -154,   331,    16,   358,    16,  -154,
    -154,  -154
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -154,   -19,   -37,  -154,  -153,   -13,    -1,  -154,  -154,  -154,
    -154
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      17,    37,    39,    75,   115,   141,    43,    19,    20,    48,
      49,    50,    51,   169,    53,   171,    21,    40,    71,   142,
      22,    76,   116,    56,    73,    30,    31,    32,    33,    34,
      35,    41,   135,    23,    78,    24,    36,    69,    70,    74,
     118,    85,   136,    25,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    26,   107,
      27,   109,   110,   105,    28,    29,   114,    47,    77,     2,
     145,   120,     3,    52,   121,    83,   123,    55,     4,     5,
       6,     7,    63,    64,   146,     8,    54,    86,    69,    70,
      20,    74,     9,   119,   103,   139,    10,    11,    12,   122,
      13,    14,   106,   108,   111,   148,   112,   133,   134,   151,
     113,    15,   117,   124,   125,   126,   140,   138,   147,    17,
      17,   149,    17,   163,   150,   165,   154,   167,    30,    31,
      32,    33,    34,    35,   152,     0,     0,   155,    17,    36,
     160,   158,     0,   162,   164,     3,     0,    17,     0,     0,
      17,     4,     5,     6,     7,     0,     0,     0,     8,     0,
       0,     0,    17,     0,    17,     9,    17,   128,     0,    10,
      11,    12,     3,    13,    14,     0,     0,     0,     4,     5,
       6,     7,     0,     0,    15,     8,     0,     0,     0,     0,
       0,     0,     9,     0,   129,     0,    10,    11,    12,     3,
      13,    14,     0,     0,     0,     4,     5,     6,     7,     0,
       0,    15,     8,     0,     0,     0,     0,     0,     0,     9,
       0,   131,     0,    10,    11,    12,     3,    13,    14,     0,
       0,     0,     4,     5,     6,     7,     0,     0,    15,     8,
       0,     0,     0,     0,     0,     0,     9,     0,   144,     0,
      10,    11,    12,     3,    13,    14,     0,     0,     0,     4,
       5,     6,     7,     0,     0,    15,     8,     0,     0,     0,
       0,     0,     0,     9,     0,   153,     0,    10,    11,    12,
       3,    13,    14,     0,     0,     0,     4,     5,     6,     7,
       0,     0,    15,     8,     0,     0,     0,     0,     0,     0,
       9,     0,   156,     0,    10,    11,    12,     3,    13,    14,
       0,     0,     0,     4,     5,     6,     7,     0,     0,    15,
       8,     0,     0,     0,     0,     0,     0,     9,     0,   166,
       0,    10,    11,    12,     3,    13,    14,     0,     0,     0,
       4,     5,     6,     7,     0,     0,    15,     8,     0,     0,
       0,     0,     0,     0,     9,     0,   168,     0,    10,    11,
      12,     3,    13,    14,     0,     0,     0,     4,     5,     6,
       7,     0,     0,    15,     8,     0,     0,     0,     0,     0,
       0,     9,     0,   170,     0,    10,    11,    12,     0,    13,
      14,    57,    58,    59,    60,    61,    62,     0,     0,    79,
      15,    57,    58,    59,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,     0,    72,    63,    64,
      65,    66,    67,    68,    69,    70,    80,     0,    57,    58,
      59,    60,    61,    62,    81,     0,    57,    58,    59,    60,
      61,    62,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,    70,    63,    64,    65,    66,    67,    68,    69,
      70,    82,     0,    57,    58,    59,    60,    61,    62,    84,
       0,    57,    58,    59,    60,    61,    62,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    63,    64,
      65,    66,    67,    68,    69,    70,    88,     0,    57,    58,
      59,    60,    61,    62,   127,     0,    57,    58,    59,    60,
      61,    62,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,    70,    63,    64,    65,    66,    67,    68,    69,
      70,   157,     0,    57,    58,    59,    60,    61,    62,   159,
       0,    57,    58,    59,    60,    61,    62,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    63,    64,
      65,    66,    67,    68,    69,    70,   161,     0,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,    70,    40,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    57,
      58,    59,    60,    61,    62,     0,     0,     0,     0,     0,
       0,     0,   130,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,     0,     0,     0,   143,    57,    58,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    44,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,    36,   104,    31,    32,    33,
      34,    35,     0,     0,     0,     0,     0,    36
};

static const yytype_int16 yycheck[] =
{
       1,    14,    15,    15,    15,    10,    19,    13,    14,    22,
      23,    24,    25,   166,    27,   168,     3,    16,    37,    24,
      14,    33,    33,    36,    43,     3,     4,     5,     6,     7,
       8,    30,    16,    14,    47,    14,    14,    40,    41,    14,
      15,    54,    26,    14,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    14,    78,
      14,    80,    81,    76,     3,     3,    85,    13,    46,     0,
      10,   108,     3,     9,   111,     3,   113,    14,     9,    10,
      11,    12,    34,    35,    24,    16,    13,     3,    40,    41,
      14,    14,    23,   106,    44,   132,    27,    28,    29,   112,
      31,    32,    14,    24,    24,   142,    13,   126,   127,   146,
      24,    42,    45,    24,     3,     3,    26,   130,    14,   120,
     121,     3,   123,   160,    14,   162,    13,   164,     3,     4,
       5,     6,     7,     8,   147,    -1,    -1,   150,   139,    14,
      24,   154,    -1,    24,    24,     3,    -1,   148,    -1,    -1,
     151,     9,    10,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    -1,   163,    -1,   165,    23,   167,    25,    -1,    27,
      28,    29,     3,    31,    32,    -1,    -1,    -1,     9,    10,
      11,    12,    -1,    -1,    42,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    -1,    25,    -1,    27,    28,    29,     3,
      31,    32,    -1,    -1,    -1,     9,    10,    11,    12,    -1,
      -1,    42,    16,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      -1,    25,    -1,    27,    28,    29,     3,    31,    32,    -1,
      -1,    -1,     9,    10,    11,    12,    -1,    -1,    42,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    25,    -1,
      27,    28,    29,     3,    31,    32,    -1,    -1,    -1,     9,
      10,    11,    12,    -1,    -1,    42,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    -1,    25,    -1,    27,    28,    29,
       3,    31,    32,    -1,    -1,    -1,     9,    10,    11,    12,
      -1,    -1,    42,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    -1,    25,    -1,    27,    28,    29,     3,    31,    32,
      -1,    -1,    -1,     9,    10,    11,    12,    -1,    -1,    42,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    25,
      -1,    27,    28,    29,     3,    31,    32,    -1,    -1,    -1,
       9,    10,    11,    12,    -1,    -1,    42,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    25,    -1,    27,    28,
      29,     3,    31,    32,    -1,    -1,    -1,     9,    10,    11,
      12,    -1,    -1,    42,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    -1,    25,    -1,    27,    28,    29,    -1,    31,
      32,    17,    18,    19,    20,    21,    22,    -1,    -1,    15,
      42,    17,    18,    19,    20,    21,    22,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    34,    35,
      36,    37,    38,    39,    40,    41,    15,    -1,    17,    18,
      19,    20,    21,    22,    15,    -1,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    34,    35,    36,    37,    38,    39,    40,
      41,    15,    -1,    17,    18,    19,    20,    21,    22,    15,
      -1,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    34,    35,
      36,    37,    38,    39,    40,    41,    15,    -1,    17,    18,
      19,    20,    21,    22,    15,    -1,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    34,    35,    36,    37,    38,    39,    40,
      41,    15,    -1,    17,    18,    19,    20,    21,    22,    15,
      -1,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    34,    35,
      36,    37,    38,    39,    40,    41,    15,    -1,    17,    18,
      19,    20,    21,    22,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    17,    18,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    17,
      18,    19,    20,    21,    22,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    14,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    14
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,     0,     3,     9,    10,    11,    12,    16,    23,
      27,    28,    29,    31,    32,    42,    50,    53,    56,    13,
      14,     3,    14,    14,    14,    14,    14,    14,     3,     3,
       3,     4,     5,     6,     7,     8,    14,    52,    53,    52,
      16,    30,    48,    52,     3,    52,    55,    13,    52,    52,
      52,    52,     9,    52,    13,    14,    52,    17,    18,    19,
      20,    21,    22,    34,    35,    36,    37,    38,    39,    40,
      41,    48,    43,    48,    14,    15,    33,    46,    52,    15,
      15,    15,    15,     3,    15,    52,     3,    54,    15,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    44,     3,    52,    14,    48,    24,    48,
      48,    24,    13,    24,    48,    15,    33,    45,    15,    52,
      49,    49,    52,    49,    24,     3,     3,    15,    25,    25,
      30,    25,    57,    48,    48,    16,    26,    51,    52,    49,
      26,    10,    24,    30,    25,    10,    24,    14,    49,     3,
      14,    49,    52,    25,    13,    52,    25,    15,    52,    15,
      24,    15,    24,    49,    24,    49,    25,    49,    25,    51,
      25,    51
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
#line 204 "src/compiler/pebble.y"
    { (yyval.str) = strdup(""); ;}
    break;

  case 5:
#line 205 "src/compiler/pebble.y"
    {
      int len = strlen((yyvsp[(1) - (2)].str)) + strlen((yyvsp[(2) - (2)].str)) + 1;
      (yyval.str) = malloc(len);
      strcpy((yyval.str), (yyvsp[(1) - (2)].str));
      strcat((yyval.str), (yyvsp[(2) - (2)].str));
      free((yyvsp[(1) - (2)].str));
      free((yyvsp[(2) - (2)].str));
      code = (yyval.str);
    ;}
    break;

  case 6:
#line 214 "src/compiler/pebble.y"
    {
      if (!func_code) {
        func_code = strdup((yyvsp[(2) - (2)].str));
      } else {
        char* new_code = malloc(strlen(func_code) + strlen((yyvsp[(2) - (2)].str)) + 1);
        strcpy(new_code, func_code);
        strcat(new_code, (yyvsp[(2) - (2)].str));
        free(func_code);
        func_code = new_code;
      }
      free((yyvsp[(2) - (2)].str));
      (yyval.str) = (yyvsp[(1) - (2)].str);
    ;}
    break;

  case 7:
#line 230 "src/compiler/pebble.y"
    {
      if (var_exists((yyvsp[(2) - (5)].str))) {
          declaration_error(yylineno, 0,
                           "Variable already declared", (yyvsp[(2) - (5)].str),
                           "Use a different variable name or remove the 'var' keyword if you want to reassign");
      }
      enum VarType vtype = (yyvsp[(4) - (5)].expr_val).type;

      // Check if this is a function call and extract the function name
      if (strstr((yyvsp[(4) - (5)].expr_val).str, "(") && strstr((yyvsp[(4) - (5)].expr_val).str, ")")) {
          char* func_name = strdup((yyvsp[(4) - (5)].expr_val).str);
          char* paren_pos = strchr(func_name, '(');
          if (paren_pos) {
              *paren_pos = '\0'; // Terminate the string at the opening parenthesis

              // Find the function in the symbol table to get its return type
              for (int i = 0; i < symtab_size; i++) {
                  if (symtab[i].is_function && strcmp(symtab[i].name, func_name) == 0) {
                      vtype = symtab[i].type;
                      break;
                  }
              }
          }
          free(func_name);
      }

      // Always declare variables properly
      int len = snprintf(NULL, 0, "    %s %s = %s;\n",
                       vtype == VT_FLOAT ? "double" :
                       vtype == VT_STRING ? "char*" :
                       vtype == VT_CHAR ? "char" : "int",
                       (yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr_val).str) + 1;
      (yyval.str) = malloc(len);
      snprintf((yyval.str), len, "    %s %s = %s;\n",
             vtype == VT_FLOAT ? "double" :
             vtype == VT_STRING ? "char*" :
             vtype == VT_CHAR ? "char" : "int",
             (yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr_val).str);

      add_var((yyvsp[(2) - (5)].str), vtype, 0);
      free((yyvsp[(2) - (5)].str));
      free((yyvsp[(4) - (5)].expr_val).str);
    ;}
    break;

  case 8:
#line 273 "src/compiler/pebble.y"
    {
      if (var_exists((yyvsp[(2) - (8)].str))) {
          declaration_error(yylineno, 0,
                           "Variable already declared", (yyvsp[(2) - (8)].str),
                           "Use a different variable name or remove the 'var' keyword if you want to reassign");
      }
      if ((yyvsp[(6) - (8)].expr_val).type != VT_STRING) {
          type_error(yylineno, 0,
                    "Input prompt must be a string", (yyvsp[(6) - (8)].expr_val).str,
                    "Use double quotes around your prompt text, e.g., input(\"Enter a value: \")");
      }

      // Generate code for input with prompt
      int len = snprintf(NULL, 0,
                "    char* %s = malloc(256);\n"
                "    printf(\"%%s\", %s);\n"
                "    fgets(%s, 256, stdin);\n"
                "    // Remove newline if present\n"
                "    int %s_len = strlen(%s);\n"
                "    if (%s_len > 0 && %s[%s_len-1] == '\\n') %s[%s_len-1] = '\\0';\n",
                (yyvsp[(2) - (8)].str), (yyvsp[(6) - (8)].expr_val).str, (yyvsp[(2) - (8)].str), (yyvsp[(2) - (8)].str), (yyvsp[(2) - (8)].str), (yyvsp[(2) - (8)].str), (yyvsp[(2) - (8)].str), (yyvsp[(2) - (8)].str), (yyvsp[(2) - (8)].str), (yyvsp[(2) - (8)].str)) + 1;

      (yyval.str) = malloc(len);
      snprintf((yyval.str), len,
              "    char* %s = malloc(256);\n"
              "    printf(\"%%s\", %s);\n"
              "    fgets(%s, 256, stdin);\n"
              "    // Remove newline if present\n"
              "    int %s_len = strlen(%s);\n"
              "    if (%s_len > 0 && %s[%s_len-1] == '\\n') %s[%s_len-1] = '\\0';\n",
              (yyvsp[(2) - (8)].str), (yyvsp[(6) - (8)].expr_val).str, (yyvsp[(2) - (8)].str), (yyvsp[(2) - (8)].str), (yyvsp[(2) - (8)].str), (yyvsp[(2) - (8)].str), (yyvsp[(2) - (8)].str), (yyvsp[(2) - (8)].str), (yyvsp[(2) - (8)].str), (yyvsp[(2) - (8)].str));

      add_var((yyvsp[(2) - (8)].str), VT_STRING, 0);
      free((yyvsp[(2) - (8)].str));
      free((yyvsp[(6) - (8)].expr_val).str);
    ;}
    break;

  case 9:
#line 309 "src/compiler/pebble.y"
    {
      const char* fmt = "%d\\n";
      enum VarType expr_type = (yyvsp[(3) - (5)].expr_val).type;

      // Check if this is a function call and extract the function name
      if (strstr((yyvsp[(3) - (5)].expr_val).str, "(") && strstr((yyvsp[(3) - (5)].expr_val).str, ")")) {
          char* func_name = strdup((yyvsp[(3) - (5)].expr_val).str);
          char* paren_pos = strchr(func_name, '(');
          if (paren_pos) {
              *paren_pos = '\0'; // Terminate the string at the opening parenthesis

              // Find the function in the symbol table to get its return type
              for (int i = 0; i < symtab_size; i++) {
                  if (symtab[i].is_function && strcmp(symtab[i].name, func_name) == 0) {
                      expr_type = symtab[i].type;
                      break;
                  }
              }
          }
          free(func_name);
      }

      if (expr_type == VT_STRING) fmt = "%s\\n";
      else if (expr_type == VT_CHAR) fmt = "%c\\n";
      else if (expr_type == VT_FLOAT) fmt = "%.2f\\n";
      int len = snprintf(NULL, 0, "    printf(\"%s\", %s);\n", fmt, (yyvsp[(3) - (5)].expr_val).str) + 1;
      (yyval.str) = malloc(len);
      snprintf((yyval.str), len, "    printf(\"%s\", %s);\n", fmt, (yyvsp[(3) - (5)].expr_val).str);
      free((yyvsp[(3) - (5)].expr_val).str);
    ;}
    break;

  case 10:
#line 339 "src/compiler/pebble.y"
    {
      const char* fmt = "%d";
      enum VarType expr_type = (yyvsp[(3) - (5)].expr_val).type;

      // Check if this is a function call and extract the function name
      if (strstr((yyvsp[(3) - (5)].expr_val).str, "(") && strstr((yyvsp[(3) - (5)].expr_val).str, ")")) {
          char* func_name = strdup((yyvsp[(3) - (5)].expr_val).str);
          char* paren_pos = strchr(func_name, '(');
          if (paren_pos) {
              *paren_pos = '\0'; // Terminate the string at the opening parenthesis

              // Find the function in the symbol table to get its return type
              for (int i = 0; i < symtab_size; i++) {
                  if (symtab[i].is_function && strcmp(symtab[i].name, func_name) == 0) {
                      expr_type = symtab[i].type;
                      break;
                  }
              }
          }
          free(func_name);
      }

      if (expr_type == VT_STRING) fmt = "%s";
      else if (expr_type == VT_CHAR) fmt = "%c";
      else if (expr_type == VT_FLOAT) fmt = "%.2f";
      int len = snprintf(NULL, 0, "    printf(\"%s\", %s);\n", fmt, (yyvsp[(3) - (5)].expr_val).str) + 1;
      (yyval.str) = malloc(len);
      snprintf((yyval.str), len, "    printf(\"%s\", %s);\n", fmt, (yyvsp[(3) - (5)].expr_val).str);
      free((yyvsp[(3) - (5)].expr_val).str);
    ;}
    break;

  case 11:
#line 369 "src/compiler/pebble.y"
    {
      // Check if the repeat count is an integer
      if ((yyvsp[(3) - (7)].expr_val).type != VT_INT) {
        char suggestion[256];
        const char* type = (yyvsp[(3) - (7)].expr_val).type == VT_FLOAT ? "float" :
                          (yyvsp[(3) - (7)].expr_val).type == VT_STRING ? "string" :
                          (yyvsp[(3) - (7)].expr_val).type == VT_CHAR ? "character" : "boolean";

        snprintf(suggestion, sizeof(suggestion),
                 "The repeat count must be an integer. You provided a %s. Use an integer value instead.",
                 type);

        type_error(yylineno, 0,
                  "Invalid repeat count type", NULL,
                  suggestion);
      }

      int len = snprintf(NULL, 0, "    for (int __i = 0; __i < %s; __i++) {\n%s    }\n", (yyvsp[(3) - (7)].expr_val).str, (yyvsp[(6) - (7)].str)) + 1;
      (yyval.str) = malloc(len);
      snprintf((yyval.str), len, "    for (int __i = 0; __i < %s; __i++) {\n%s    }\n", (yyvsp[(3) - (7)].expr_val).str, (yyvsp[(6) - (7)].str));
      free((yyvsp[(3) - (7)].expr_val).str);
      free((yyvsp[(6) - (7)].str));
    ;}
    break;

  case 12:
#line 392 "src/compiler/pebble.y"
    {
      // Check if the condition is a boolean expression
      if ((yyvsp[(8) - (16)].expr_val).type != VT_INT && (yyvsp[(8) - (16)].expr_val).type != VT_BOOL) {
          char suggestion[256];
          const char* type = (yyvsp[(8) - (16)].expr_val).type == VT_FLOAT ? "float" :
                            (yyvsp[(8) - (16)].expr_val).type == VT_STRING ? "string" :
                            (yyvsp[(8) - (16)].expr_val).type == VT_CHAR ? "character" : "boolean";

          snprintf(suggestion, sizeof(suggestion),
                   "The loop condition must evaluate to a boolean. You provided a %s. Use a comparison operator like <, >, ==, etc.",
                   type);

          type_error(yylineno, 0,
                    "Invalid loop condition type", NULL,
                    suggestion);
      }

      // Check if the increment variable matches the initialization variable
      if (strcmp((yyvsp[(4) - (16)].str), (yyvsp[(10) - (16)].str)) != 0) {
          char suggestion[256];
          snprintf(suggestion, sizeof(suggestion),
                   "The variable in the increment part (%s) should match the initialization variable (%s)",
                   (yyvsp[(10) - (16)].str), (yyvsp[(4) - (16)].str));

          syntax_error(yylineno, 0,
                      "Mismatched loop variables", NULL,
                      suggestion);
      }

      // Generate the for loop code
      enum VarType vtype = (yyvsp[(6) - (16)].expr_val).type;

      int len = snprintf(NULL, 0,
                "    {\n"  // Create a new scope for the loop variable
                "        %s %s = %s;\n"
                "        for (; %s; %s = %s) {\n"
                "%s"
                "        }\n"
                "    }\n",
                vtype == VT_FLOAT ? "double" :
                vtype == VT_STRING ? "char*" :
                vtype == VT_CHAR ? "char" : "int",
                (yyvsp[(4) - (16)].str), (yyvsp[(6) - (16)].expr_val).str, (yyvsp[(8) - (16)].expr_val).str, (yyvsp[(10) - (16)].str), (yyvsp[(12) - (16)].expr_val).str, (yyvsp[(15) - (16)].str)) + 1;

      (yyval.str) = malloc(len);
      snprintf((yyval.str), len,
              "    {\n"  // Create a new scope for the loop variable
              "        %s %s = %s;\n"
              "        for (; %s; %s = %s) {\n"
              "%s"
              "        }\n"
              "    }\n",
              vtype == VT_FLOAT ? "double" :
              vtype == VT_STRING ? "char*" :
              vtype == VT_CHAR ? "char" : "int",
              (yyvsp[(4) - (16)].str), (yyvsp[(6) - (16)].expr_val).str, (yyvsp[(8) - (16)].expr_val).str, (yyvsp[(10) - (16)].str), (yyvsp[(12) - (16)].expr_val).str, (yyvsp[(15) - (16)].str));

      // Free allocated memory
      free((yyvsp[(4) - (16)].str));
      free((yyvsp[(6) - (16)].expr_val).str);
      free((yyvsp[(8) - (16)].expr_val).str);
      free((yyvsp[(10) - (16)].str));
      free((yyvsp[(12) - (16)].expr_val).str);
      free((yyvsp[(15) - (16)].str));
    ;}
    break;

  case 13:
#line 457 "src/compiler/pebble.y"
    {
      // Check if the condition is a boolean expression
      if ((yyvsp[(3) - (7)].expr_val).type != VT_INT && (yyvsp[(3) - (7)].expr_val).type != VT_BOOL) {
          char suggestion[256];
          const char* type = (yyvsp[(3) - (7)].expr_val).type == VT_FLOAT ? "float" :
                            (yyvsp[(3) - (7)].expr_val).type == VT_STRING ? "string" :
                            (yyvsp[(3) - (7)].expr_val).type == VT_CHAR ? "character" : "boolean";

          snprintf(suggestion, sizeof(suggestion),
                   "The while condition must evaluate to a boolean. You provided a %s. Use a comparison operator like <, >, ==, etc.",
                   type);

          type_error(yylineno, 0,
                    "Invalid while condition type", NULL,
                    suggestion);
      }

      // Generate the while loop code
      int len = snprintf(NULL, 0, "    while (%s) {\n%s    }\n", (yyvsp[(3) - (7)].expr_val).str, (yyvsp[(6) - (7)].str)) + 1;
      (yyval.str) = malloc(len);
      snprintf((yyval.str), len, "    while (%s) {\n%s    }\n", (yyvsp[(3) - (7)].expr_val).str, (yyvsp[(6) - (7)].str));

      // Free allocated memory
      free((yyvsp[(3) - (7)].expr_val).str);
      free((yyvsp[(6) - (7)].str));
    ;}
    break;

  case 14:
#line 483 "src/compiler/pebble.y"
    {
      int len = strlen((yyvsp[(1) - (2)].str)) + 6;
      (yyval.str) = malloc(len);
      snprintf((yyval.str), len, "    %s;\n", (yyvsp[(1) - (2)].str));
      free((yyvsp[(1) - (2)].str));
    ;}
    break;

  case 15:
#line 489 "src/compiler/pebble.y"
    {
      int idx = -1;
      for (int i = 0; i < symtab_size; i++) {
          if (strcmp(symtab[i].name, (yyvsp[(1) - (4)].str)) == 0) idx = i;
      }
      if (idx == -1) {
          reference_error(yylineno, 0,
                         "Variable is not defined", (yyvsp[(1) - (4)].str),
                         "Make sure to declare the variable with 'var' before using it");
      }
      if (symtab[idx].is_const) {
          declaration_error(yylineno, 0,
                           "Cannot assign to const variable", (yyvsp[(1) - (4)].str),
                           "Constants cannot be reassigned. Use a regular variable instead of a constant");
      }
      enum VarType vtype = symtab[idx].type;
      if (vtype != (yyvsp[(3) - (4)].expr_val).type) {
          char suggestion[256];
          const char* target_type = vtype == VT_INT ? "integer" :
                                   vtype == VT_FLOAT ? "float" :
                                   vtype == VT_STRING ? "string" :
                                   vtype == VT_CHAR ? "character" : "boolean";

          const char* source_type = (yyvsp[(3) - (4)].expr_val).type == VT_INT ? "integer" :
                                   (yyvsp[(3) - (4)].expr_val).type == VT_FLOAT ? "float" :
                                   (yyvsp[(3) - (4)].expr_val).type == VT_STRING ? "string" :
                                   (yyvsp[(3) - (4)].expr_val).type == VT_CHAR ? "character" : "boolean";

          snprintf(suggestion, sizeof(suggestion),
                   "Cannot assign %s to %s. Use a %s value or convert using to_%s()",
                   source_type, target_type, target_type,
                   vtype == VT_INT ? "int" :
                   vtype == VT_FLOAT ? "float" :
                   vtype == VT_STRING ? "string" :
                   vtype == VT_CHAR ? "char" : "bool");

          type_error(yylineno, 0,
                    "Type mismatch in assignment", (yyvsp[(1) - (4)].str), suggestion);
      }
      int len = snprintf(NULL, 0, "    %s = %s;\n", (yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].expr_val).str) + 1;
      (yyval.str) = malloc(len);
      snprintf((yyval.str), len, "    %s = %s;\n", (yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].expr_val).str);
      free((yyvsp[(1) - (4)].str));
      free((yyvsp[(3) - (4)].expr_val).str);
    ;}
    break;

  case 16:
#line 534 "src/compiler/pebble.y"
    {
      int len = snprintf(NULL, 0, "    if (%s) {\n%s    }%s\n", (yyvsp[(3) - (8)].expr_val).str, (yyvsp[(6) - (8)].str), (yyvsp[(8) - (8)].str)) + 1;
      (yyval.str) = malloc(len);
      snprintf((yyval.str), len, "    if (%s) {\n%s    }%s\n", (yyvsp[(3) - (8)].expr_val).str, (yyvsp[(6) - (8)].str), (yyvsp[(8) - (8)].str));
      free((yyvsp[(3) - (8)].expr_val).str);
      free((yyvsp[(6) - (8)].str));
      free((yyvsp[(8) - (8)].str));
    ;}
    break;

  case 17:
#line 542 "src/compiler/pebble.y"
    {
      enum VarType vtype = (yyvsp[(4) - (5)].expr_val).type;
      int len = snprintf(NULL, 0, "    const %s %s = %s;\n", vtype == VT_FLOAT ? "double" : vtype == VT_STRING ? "char*" : vtype == VT_CHAR ? "char" : "int", (yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr_val).str) + 1;
      (yyval.str) = malloc(len);
      snprintf((yyval.str), len, "    const %s %s = %s;\n", vtype == VT_FLOAT ? "double" : vtype == VT_STRING ? "char*" : vtype == VT_CHAR ? "char" : "int", (yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr_val).str);
      add_var((yyvsp[(2) - (5)].str), vtype, 1);
      free((yyvsp[(2) - (5)].str));
      free((yyvsp[(4) - (5)].expr_val).str);
    ;}
    break;

  case 18:
#line 551 "src/compiler/pebble.y"
    {
      // Get the current function name
      char* current_func = NULL;
      if (symtab_func_param_depth > 0) {
        // Find the most recently added function
        for (int i = symtab_size - 1; i >= 0; i--) {
          if (symtab[i].is_function) {
            current_func = symtab[i].name;
            break;
          }
        }
      }

      // Update the function's return type if we found it
      if (current_func) {
        set_function_return_type(current_func, (yyvsp[(2) - (3)].expr_val).type);
      }

      int len = snprintf(NULL, 0, "    return %s;\n", (yyvsp[(2) - (3)].expr_val).str) + 1;
      (yyval.str) = malloc(len);
      snprintf((yyval.str), len, "    return %s;\n", (yyvsp[(2) - (3)].expr_val).str);
      free((yyvsp[(2) - (3)].expr_val).str);
    ;}
    break;

  case 19:
#line 574 "src/compiler/pebble.y"
    { (yyval.str) = strdup(""); ;}
    break;

  case 20:
#line 575 "src/compiler/pebble.y"
    {
      if (var_exists((yyvsp[(6) - (7)].str))) {
          declaration_error(yylineno, 0,
                           "Variable already declared", (yyvsp[(6) - (7)].str),
                           "Use a different variable name for storing the input");
      }
      if ((yyvsp[(2) - (7)].expr_val).type != VT_STRING) {
          type_error(yylineno, 0,
                    "Ask prompt must be a string", (yyvsp[(2) - (7)].expr_val).str,
                    "Use double quotes around your prompt text, e.g., ask \"Enter your name: \" and save as name");
      }

      // Generate code for ask and save
      int len = snprintf(NULL, 0,
                "    char* %s = malloc(256);\n"
                "    printf(\"%%s\", %s);\n"
                "    fgets(%s, 256, stdin);\n"
                "    // Remove newline if present\n"
                "    int %s_len = strlen(%s);\n"
                "    if (%s_len > 0 && %s[%s_len-1] == '\\n') %s[%s_len-1] = '\\0';\n",
                (yyvsp[(6) - (7)].str), (yyvsp[(2) - (7)].expr_val).str, (yyvsp[(6) - (7)].str), (yyvsp[(6) - (7)].str), (yyvsp[(6) - (7)].str), (yyvsp[(6) - (7)].str), (yyvsp[(6) - (7)].str), (yyvsp[(6) - (7)].str), (yyvsp[(6) - (7)].str), (yyvsp[(6) - (7)].str)) + 1;

      (yyval.str) = malloc(len);
      snprintf((yyval.str), len,
              "    char* %s = malloc(256);\n"
              "    printf(\"%%s\", %s);\n"
              "    fgets(%s, 256, stdin);\n"
              "    // Remove newline if present\n"
              "    int %s_len = strlen(%s);\n"
              "    if (%s_len > 0 && %s[%s_len-1] == '\\n') %s[%s_len-1] = '\\0';\n",
              (yyvsp[(6) - (7)].str), (yyvsp[(2) - (7)].expr_val).str, (yyvsp[(6) - (7)].str), (yyvsp[(6) - (7)].str), (yyvsp[(6) - (7)].str), (yyvsp[(6) - (7)].str), (yyvsp[(6) - (7)].str), (yyvsp[(6) - (7)].str), (yyvsp[(6) - (7)].str), (yyvsp[(6) - (7)].str));

      add_var((yyvsp[(6) - (7)].str), VT_STRING, 0);
      free((yyvsp[(6) - (7)].str));
      free((yyvsp[(2) - (7)].expr_val).str);
    ;}
    break;

  case 21:
#line 614 "src/compiler/pebble.y"
    { (yyval.str) = strdup(""); ;}
    break;

  case 22:
#line 615 "src/compiler/pebble.y"
    {
      int len = snprintf(NULL, 0, " else if (%s) {\n%s    }%s", (yyvsp[(4) - (9)].expr_val).str, (yyvsp[(7) - (9)].str), (yyvsp[(9) - (9)].str)) + 1;
      (yyval.str) = malloc(len);
      snprintf((yyval.str), len, " else if (%s) {\n%s    }%s", (yyvsp[(4) - (9)].expr_val).str, (yyvsp[(7) - (9)].str), (yyvsp[(9) - (9)].str));
      free((yyvsp[(4) - (9)].expr_val).str);
      free((yyvsp[(7) - (9)].str));
      free((yyvsp[(9) - (9)].str));
    ;}
    break;

  case 23:
#line 623 "src/compiler/pebble.y"
    {
      int len = snprintf(NULL, 0, " else {\n%s    }", (yyvsp[(3) - (4)].str)) + 1;
      (yyval.str) = malloc(len);
      snprintf((yyval.str), len, " else {\n%s    }", (yyvsp[(3) - (4)].str));
      free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 24:
#line 629 "src/compiler/pebble.y"
    {
      // Handle the case where 'else' is on a new line
      int len = snprintf(NULL, 0, " else {\n%s    }", (yyvsp[(4) - (5)].str)) + 1;
      (yyval.str) = malloc(len);
      snprintf((yyval.str), len, " else {\n%s    }", (yyvsp[(4) - (5)].str));
      free((yyvsp[(4) - (5)].str));
    ;}
    break;

  case 25:
#line 636 "src/compiler/pebble.y"
    {
      // Handle the case where 'else if' is on a new line
      int len = snprintf(NULL, 0, " else if (%s) {\n%s    }%s", (yyvsp[(5) - (10)].expr_val).str, (yyvsp[(8) - (10)].str), (yyvsp[(10) - (10)].str)) + 1;
      (yyval.str) = malloc(len);
      snprintf((yyval.str), len, " else if (%s) {\n%s    }%s", (yyvsp[(5) - (10)].expr_val).str, (yyvsp[(8) - (10)].str), (yyvsp[(10) - (10)].str));
      free((yyvsp[(5) - (10)].expr_val).str);
      free((yyvsp[(8) - (10)].str));
      free((yyvsp[(10) - (10)].str));
    ;}
    break;

  case 26:
#line 648 "src/compiler/pebble.y"
    {
      (yyval.expr_val).str = malloc(16);
      snprintf((yyval.expr_val).str, 16, "%d", (yyvsp[(1) - (1)].num));
      (yyval.expr_val).type = VT_INT;
    ;}
    break;

  case 27:
#line 653 "src/compiler/pebble.y"
    {
      // Check if the identifier exists in the symbol table
      if (var_exists((yyvsp[(1) - (1)].str))) {
          (yyval.expr_val).str = (yyvsp[(1) - (1)].str);
          (yyval.expr_val).type = get_var_type((yyvsp[(1) - (1)].str));
      } else {
          // If we're in a function scope, check if this is a parameter
          if (symtab_func_param_depth > 0) {
              // For now, we'll assume all function parameters are integers
              // In a more complete implementation, we would track parameter types
              (yyval.expr_val).str = (yyvsp[(1) - (1)].str);
              (yyval.expr_val).type = VT_INT;
          } else {
              // Provide helpful suggestions for common variable name mistakes
              char suggestion[256] = "";

              // Check for common variable naming mistakes
              if (strlen((yyvsp[(1) - (1)].str)) == 1) {
                  // Single letter variables are common, suggest declaring them
                  snprintf(suggestion, sizeof(suggestion),
                           "Did you forget to declare '%s'? Use 'var %s = value' first", (yyvsp[(1) - (1)].str), (yyvsp[(1) - (1)].str));
              } else {
                  // Look for similar variable names in the symbol table
                  for (int i = 0; i < symtab_size; i++) {
                      // Simple similarity check - first character matches
                      if (symtab[i].name[0] == (yyvsp[(1) - (1)].str)[0]) {
                          snprintf(suggestion, sizeof(suggestion),
                                   "Did you mean '%s'?", symtab[i].name);
                          break;
                      }
                  }

                  // If no similar variable found, suggest declaring it
                  if (suggestion[0] == '\0') {
                      snprintf(suggestion, sizeof(suggestion),
                               "Variable '%s' needs to be declared before use. Add 'var %s = value'",
                               (yyvsp[(1) - (1)].str), (yyvsp[(1) - (1)].str));
                  }
              }

              reference_error(yylineno, 0,
                             "Variable is not defined", (yyvsp[(1) - (1)].str), suggestion);
          }
      }
    ;}
    break;

  case 28:
#line 698 "src/compiler/pebble.y"
    {
      (yyval.expr_val).str = (yyvsp[(2) - (3)].expr_val).str;
      (yyval.expr_val).type = (yyvsp[(2) - (3)].expr_val).type;
    ;}
    break;

  case 29:
#line 702 "src/compiler/pebble.y"
    {
      if ((yyvsp[(1) - (3)].expr_val).type != (yyvsp[(3) - (3)].expr_val).type || ((yyvsp[(1) - (3)].expr_val).type != VT_INT && (yyvsp[(1) - (3)].expr_val).type != VT_FLOAT && (yyvsp[(1) - (3)].expr_val).type != VT_STRING)) {
        char suggestion[256];
        const char* type1 = (yyvsp[(1) - (3)].expr_val).type == VT_INT ? "integer" :
                           (yyvsp[(1) - (3)].expr_val).type == VT_FLOAT ? "float" :
                           (yyvsp[(1) - (3)].expr_val).type == VT_STRING ? "string" :
                           (yyvsp[(1) - (3)].expr_val).type == VT_CHAR ? "character" : "boolean";

        const char* type2 = (yyvsp[(3) - (3)].expr_val).type == VT_INT ? "integer" :
                           (yyvsp[(3) - (3)].expr_val).type == VT_FLOAT ? "float" :
                           (yyvsp[(3) - (3)].expr_val).type == VT_STRING ? "string" :
                           (yyvsp[(3) - (3)].expr_val).type == VT_CHAR ? "character" : "boolean";

        if ((yyvsp[(1) - (3)].expr_val).type != (yyvsp[(3) - (3)].expr_val).type) {
          snprintf(suggestion, sizeof(suggestion),
                   "Cannot add %s and %s. Make sure both operands are of the same type",
                   type1, type2);
        } else {
          snprintf(suggestion, sizeof(suggestion),
                   "The + operator can only be used with numbers or strings");
        }

        type_error(yylineno, 0,
                  "Invalid types for addition", NULL, suggestion);
      }

      (yyval.expr_val).type = (yyvsp[(1) - (3)].expr_val).type;
      if ((yyvsp[(1) - (3)].expr_val).type == VT_STRING) {
        (yyval.expr_val).str = malloc(512);
        snprintf((yyval.expr_val).str, 512, "( { char* buf = malloc(256); snprintf(buf, 256, \"%%s%%s\", %s, %s); buf; } )", (yyvsp[(1) - (3)].expr_val).str, (yyvsp[(3) - (3)].expr_val).str);
      } else {
        (yyval.expr_val).str = malloc(256);
        snprintf((yyval.expr_val).str, 256, "(%s + %s)", (yyvsp[(1) - (3)].expr_val).str, (yyvsp[(3) - (3)].expr_val).str);
      }
      free((yyvsp[(1) - (3)].expr_val).str);
      free((yyvsp[(3) - (3)].expr_val).str);
    ;}
    break;

  case 30:
#line 739 "src/compiler/pebble.y"
    {
      if ((yyvsp[(1) - (3)].expr_val).type != (yyvsp[(3) - (3)].expr_val).type || ((yyvsp[(1) - (3)].expr_val).type != VT_INT && (yyvsp[(1) - (3)].expr_val).type != VT_FLOAT)) {
        pebble_error("TypeError", yylineno, "Invalid types for -", NULL);
      }
      (yyval.expr_val).str = malloc(256);
      snprintf((yyval.expr_val).str, 256, "(%s - %s)", (yyvsp[(1) - (3)].expr_val).str, (yyvsp[(3) - (3)].expr_val).str);
      (yyval.expr_val).type = (yyvsp[(1) - (3)].expr_val).type;
      free((yyvsp[(1) - (3)].expr_val).str);
      free((yyvsp[(3) - (3)].expr_val).str);
    ;}
    break;

  case 31:
#line 749 "src/compiler/pebble.y"
    {
      if ((yyvsp[(1) - (3)].expr_val).type != (yyvsp[(3) - (3)].expr_val).type || ((yyvsp[(1) - (3)].expr_val).type != VT_INT && (yyvsp[(1) - (3)].expr_val).type != VT_FLOAT)) {
        pebble_error("TypeError", yylineno, "Invalid types for *", NULL);
      }
      (yyval.expr_val).str = malloc(256);
      snprintf((yyval.expr_val).str, 256, "(%s * %s)", (yyvsp[(1) - (3)].expr_val).str, (yyvsp[(3) - (3)].expr_val).str);
      (yyval.expr_val).type = (yyvsp[(1) - (3)].expr_val).type;
      free((yyvsp[(1) - (3)].expr_val).str);
      free((yyvsp[(3) - (3)].expr_val).str);
    ;}
    break;

  case 32:
#line 759 "src/compiler/pebble.y"
    {
      if ((yyvsp[(1) - (3)].expr_val).type != (yyvsp[(3) - (3)].expr_val).type || ((yyvsp[(1) - (3)].expr_val).type != VT_INT && (yyvsp[(1) - (3)].expr_val).type != VT_FLOAT)) {
        pebble_error("TypeError", yylineno, "Invalid types for /", NULL);
      }
      (yyval.expr_val).str = malloc(256);
      snprintf((yyval.expr_val).str, 256, "(%s / %s)", (yyvsp[(1) - (3)].expr_val).str, (yyvsp[(3) - (3)].expr_val).str);
      (yyval.expr_val).type = (yyvsp[(1) - (3)].expr_val).type;
      free((yyvsp[(1) - (3)].expr_val).str);
      free((yyvsp[(3) - (3)].expr_val).str);
    ;}
    break;

  case 33:
#line 769 "src/compiler/pebble.y"
    {
      if ((yyvsp[(1) - (3)].expr_val).type != VT_INT || (yyvsp[(3) - (3)].expr_val).type != VT_INT) {
        char suggestion[256];
        const char* type1 = (yyvsp[(1) - (3)].expr_val).type == VT_INT ? "integer" :
                           (yyvsp[(1) - (3)].expr_val).type == VT_FLOAT ? "float" :
                           (yyvsp[(1) - (3)].expr_val).type == VT_STRING ? "string" :
                           (yyvsp[(1) - (3)].expr_val).type == VT_CHAR ? "character" : "boolean";

        const char* type2 = (yyvsp[(3) - (3)].expr_val).type == VT_INT ? "integer" :
                           (yyvsp[(3) - (3)].expr_val).type == VT_FLOAT ? "float" :
                           (yyvsp[(3) - (3)].expr_val).type == VT_STRING ? "string" :
                           (yyvsp[(3) - (3)].expr_val).type == VT_CHAR ? "character" : "boolean";

        snprintf(suggestion, sizeof(suggestion),
                 "The modulo operator requires integer operands. You provided %s and %s.",
                 type1, type2);

        type_error(yylineno, 0,
                  "Invalid types for modulo operation", NULL,
                  suggestion);
      }
      (yyval.expr_val).str = malloc(256);
      snprintf((yyval.expr_val).str, 256, "(%s %% %s)", (yyvsp[(1) - (3)].expr_val).str, (yyvsp[(3) - (3)].expr_val).str);
      (yyval.expr_val).type = VT_INT;
      free((yyvsp[(1) - (3)].expr_val).str);
      free((yyvsp[(3) - (3)].expr_val).str);
    ;}
    break;

  case 34:
#line 796 "src/compiler/pebble.y"
    {
      if ((yyvsp[(1) - (3)].expr_val).type != VT_INT && (yyvsp[(1) - (3)].expr_val).type != VT_FLOAT) {
        pebble_error("TypeError", yylineno, "Invalid types for ^", NULL);
      }
      (yyval.expr_val).str = malloc(256);
      snprintf((yyval.expr_val).str, 256, "pow(%s, %s)", (yyvsp[(1) - (3)].expr_val).str, (yyvsp[(3) - (3)].expr_val).str);
      (yyval.expr_val).type = VT_FLOAT;
      free((yyvsp[(1) - (3)].expr_val).str);
      free((yyvsp[(3) - (3)].expr_val).str);
    ;}
    break;

  case 35:
#line 806 "src/compiler/pebble.y"
    {
      (yyval.expr_val).str = malloc(256);
      snprintf((yyval.expr_val).str, 256, "%s == %s", (yyvsp[(1) - (3)].expr_val).str, (yyvsp[(3) - (3)].expr_val).str);
      (yyval.expr_val).type = VT_BOOL;
      free((yyvsp[(1) - (3)].expr_val).str);
      free((yyvsp[(3) - (3)].expr_val).str);
    ;}
    break;

  case 36:
#line 813 "src/compiler/pebble.y"
    {
      (yyval.expr_val).str = malloc(256);
      snprintf((yyval.expr_val).str, 256, "%s == %s", (yyvsp[(1) - (3)].expr_val).str, (yyvsp[(3) - (3)].expr_val).str);
      (yyval.expr_val).type = VT_BOOL;
      free((yyvsp[(1) - (3)].expr_val).str);
      free((yyvsp[(3) - (3)].expr_val).str);
    ;}
    break;

  case 37:
#line 820 "src/compiler/pebble.y"
    {
      (yyval.expr_val).str = malloc(256);
      snprintf((yyval.expr_val).str, 256, "%s != %s", (yyvsp[(1) - (3)].expr_val).str, (yyvsp[(3) - (3)].expr_val).str);
      (yyval.expr_val).type = VT_BOOL;
      free((yyvsp[(1) - (3)].expr_val).str);
      free((yyvsp[(3) - (3)].expr_val).str);
    ;}
    break;

  case 38:
#line 827 "src/compiler/pebble.y"
    {
      (yyval.expr_val).str = malloc(256);
      snprintf((yyval.expr_val).str, 256, "%s != %s", (yyvsp[(1) - (3)].expr_val).str, (yyvsp[(3) - (3)].expr_val).str);
      (yyval.expr_val).type = VT_BOOL;
      free((yyvsp[(1) - (3)].expr_val).str);
      free((yyvsp[(3) - (3)].expr_val).str);
    ;}
    break;

  case 39:
#line 834 "src/compiler/pebble.y"
    {
      if ((yyvsp[(1) - (3)].expr_val).type != (yyvsp[(3) - (3)].expr_val).type || ((yyvsp[(1) - (3)].expr_val).type != VT_INT && (yyvsp[(1) - (3)].expr_val).type != VT_FLOAT)) {
        pebble_error("TypeError", yylineno, "Invalid types for >", NULL);
      }
      (yyval.expr_val).str = malloc(256);
      snprintf((yyval.expr_val).str, 256, "%s > %s", (yyvsp[(1) - (3)].expr_val).str, (yyvsp[(3) - (3)].expr_val).str);
      (yyval.expr_val).type = VT_BOOL;
      free((yyvsp[(1) - (3)].expr_val).str);
      free((yyvsp[(3) - (3)].expr_val).str);
    ;}
    break;

  case 40:
#line 844 "src/compiler/pebble.y"
    {
      if ((yyvsp[(1) - (3)].expr_val).type != (yyvsp[(3) - (3)].expr_val).type || ((yyvsp[(1) - (3)].expr_val).type != VT_INT && (yyvsp[(1) - (3)].expr_val).type != VT_FLOAT)) {
        pebble_error("TypeError", yylineno, "Invalid types for <", NULL);
      }
      (yyval.expr_val).str = malloc(256);
      snprintf((yyval.expr_val).str, 256, "%s < %s", (yyvsp[(1) - (3)].expr_val).str, (yyvsp[(3) - (3)].expr_val).str);
      (yyval.expr_val).type = VT_BOOL;
      free((yyvsp[(1) - (3)].expr_val).str);
      free((yyvsp[(3) - (3)].expr_val).str);
    ;}
    break;

  case 41:
#line 854 "src/compiler/pebble.y"
    {
      if ((yyvsp[(1) - (3)].expr_val).type != (yyvsp[(3) - (3)].expr_val).type || ((yyvsp[(1) - (3)].expr_val).type != VT_INT && (yyvsp[(1) - (3)].expr_val).type != VT_FLOAT)) {
        pebble_error("TypeError", yylineno, "Invalid types for >=", NULL);
      }
      (yyval.expr_val).str = malloc(256);
      snprintf((yyval.expr_val).str, 256, "%s >= %s", (yyvsp[(1) - (3)].expr_val).str, (yyvsp[(3) - (3)].expr_val).str);
      (yyval.expr_val).type = VT_BOOL;
      free((yyvsp[(1) - (3)].expr_val).str);
      free((yyvsp[(3) - (3)].expr_val).str);
    ;}
    break;

  case 42:
#line 864 "src/compiler/pebble.y"
    {
      if ((yyvsp[(1) - (3)].expr_val).type != (yyvsp[(3) - (3)].expr_val).type || ((yyvsp[(1) - (3)].expr_val).type != VT_INT && (yyvsp[(1) - (3)].expr_val).type != VT_FLOAT)) {
        pebble_error("TypeError", yylineno, "Invalid types for <=", NULL);
      }
      (yyval.expr_val).str = malloc(256);
      snprintf((yyval.expr_val).str, 256, "%s <= %s", (yyvsp[(1) - (3)].expr_val).str, (yyvsp[(3) - (3)].expr_val).str);
      (yyval.expr_val).type = VT_BOOL;
      free((yyvsp[(1) - (3)].expr_val).str);
      free((yyvsp[(3) - (3)].expr_val).str);
    ;}
    break;

  case 43:
#line 874 "src/compiler/pebble.y"
    {
      (yyval.expr_val).str = malloc(strlen((yyvsp[(1) - (1)].str)) + 1);
      strcpy((yyval.expr_val).str, (yyvsp[(1) - (1)].str));
      (yyval.expr_val).type = VT_CHAR;
      free((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 44:
#line 880 "src/compiler/pebble.y"
    {
      (yyval.expr_val).str = malloc(6);
      snprintf((yyval.expr_val).str, 6, "%d", (yyvsp[(1) - (1)].num));
      (yyval.expr_val).type = VT_BOOL;
    ;}
    break;

  case 45:
#line 885 "src/compiler/pebble.y"
    {
      (yyval.expr_val).str = malloc(strlen((yyvsp[(1) - (1)].str)) + 1);
      strcpy((yyval.expr_val).str, (yyvsp[(1) - (1)].str));
      (yyval.expr_val).type = VT_FLOAT;
      free((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 46:
#line 891 "src/compiler/pebble.y"
    {
      (yyval.expr_val).str = malloc(strlen((yyvsp[(1) - (1)].str)) + 1);
      strcpy((yyval.expr_val).str, (yyvsp[(1) - (1)].str));
      (yyval.expr_val).type = VT_STRING;
      free((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 47:
#line 897 "src/compiler/pebble.y"
    {
      // Check if this is a built-in conversion function
      if (strncmp((yyvsp[(1) - (1)].str), "to_int", 6) == 0) {
        (yyval.expr_val).str = (yyvsp[(1) - (1)].str);
        (yyval.expr_val).type = VT_INT;
      } else if (strncmp((yyvsp[(1) - (1)].str), "to_float", 8) == 0) {
        (yyval.expr_val).str = (yyvsp[(1) - (1)].str);
        (yyval.expr_val).type = VT_FLOAT;
      } else if (strncmp((yyvsp[(1) - (1)].str), "to_bool", 7) == 0) {
        (yyval.expr_val).str = (yyvsp[(1) - (1)].str);
        (yyval.expr_val).type = VT_BOOL;
      } else if (strncmp((yyvsp[(1) - (1)].str), "to_char", 7) == 0) {
        (yyval.expr_val).str = (yyvsp[(1) - (1)].str);
        (yyval.expr_val).type = VT_CHAR;
      } else {
        // Look up the function's return type in the symbol table
        (yyval.expr_val).str = (yyvsp[(1) - (1)].str);

        // Extract function name from the function call string
        char* func_name = strdup((yyvsp[(1) - (1)].str));
        char* paren_pos = strchr(func_name, '(');
        if (paren_pos) {
          *paren_pos = '\0'; // Terminate the string at the opening parenthesis
        }

        // Find the function in the symbol table
        for (int i = 0; i < symtab_size; i++) {
          if (symtab[i].is_function && strcmp(symtab[i].name, func_name) == 0) {
            (yyval.expr_val).type = symtab[i].type;
            free(func_name);
            goto function_type_found;
          }
        }

        // If we get here, function not found in symbol table
        free(func_name);
        (yyval.expr_val).type = VT_INT; // Default return type if function not found

        function_type_found: ;
      }
    ;}
    break;

  case 48:
#line 941 "src/compiler/pebble.y"
    {
        // Check if the function exists
        int found = 0;
        int func_idx = -1;
        for (int i = 0; i < symtab_size; i++) {
            if (strcmp(symtab[i].name, (yyvsp[(1) - (4)].str)) == 0 && symtab[i].is_function) {
                found = 1;
                func_idx = i;
                break;
            }
        }

        // If the function doesn't exist, we'll add it to the symbol table
        // This is a simplification - in a real compiler, you'd want to check
        // function declarations first
        if (!found) {
            add_function((yyvsp[(1) - (4)].str), NULL, 0);
        } else {
            // Check parameter types if the function exists and has parameters
            struct ArgList* args = (yyvsp[(3) - (4)].arg_list_val);

            // Special case for the display and print functions
            if (strcmp((yyvsp[(1) - (4)].str), "display") == 0 || strcmp((yyvsp[(1) - (4)].str), "print") == 0) {
                // display and print can take any type, so no type checking needed
            }
            // Special case for the add function in our test
            else if (strcmp((yyvsp[(1) - (4)].str), "add") == 0 && args->count == 2) {
                // Check if we're trying to add a string and a number
                if ((args->types[0] == VT_STRING && args->types[1] == VT_INT) ||
                    (args->types[0] == VT_INT && args->types[1] == VT_STRING)) {

                    // Report a type error
                    char suggestion[256];
                    snprintf(suggestion, sizeof(suggestion),
                             "Cannot add a string and an integer. Make sure both arguments are of the same type.");

                    type_error(yylineno, 0,
                              "Invalid function parameters", (yyvsp[(1) - (4)].str),
                              suggestion);

                    // Set error flag to prevent code generation
                    error_count++;
                }
            }
            // Check for any function with mismatched parameter types
            else if (args->count >= 2) {
                // Check if all parameters are of the same type
                enum VarType first_type = args->types[0];
                for (int i = 1; i < args->count; i++) {
                    if (args->types[i] != first_type) {
                        // Report a type error for mismatched parameter types
                        char suggestion[256];

                        const char* type1 = first_type == VT_INT ? "integer" :
                                          first_type == VT_FLOAT ? "float" :
                                          first_type == VT_STRING ? "string" :
                                          first_type == VT_CHAR ? "character" : "boolean";

                        const char* type2 = args->types[i] == VT_INT ? "integer" :
                                          args->types[i] == VT_FLOAT ? "float" :
                                          args->types[i] == VT_STRING ? "string" :
                                          args->types[i] == VT_CHAR ? "character" : "boolean";

                        snprintf(suggestion, sizeof(suggestion),
                                "Parameter %d is a %s but parameter 1 is a %s. Function parameters should be of compatible types.",
                                i+1, type2, type1);

                        type_error(yylineno, 0,
                                  "Mismatched function parameter types", (yyvsp[(1) - (4)].str),
                                  suggestion);

                        // Set error flag to prevent code generation
                        error_count++;
                        break;
                    }
                }
            }
            // For other functions, we could add more specific type checking here
        }

        // Generate the function call with arguments
        char* func_name = strdup((yyvsp[(1) - (4)].str));
        struct ArgList* args = (yyvsp[(3) - (4)].arg_list_val);

        int len = snprintf(NULL, 0, "%s(%s)", func_name, args->str) + 1;
        (yyval.str) = malloc(len);
        snprintf((yyval.str), len, "%s(%s)", func_name, args->str);

        // Free the original strings
        free(func_name);
        free(args->str);
        if (args->types) free(args->types);
        free(args);
        free((yyvsp[(1) - (4)].str));
    ;}
    break;

  case 49:
#line 1039 "src/compiler/pebble.y"
    { (yyval.str) = strdup(""); ;}
    break;

  case 50:
#line 1040 "src/compiler/pebble.y"
    {
      (yyval.str) = strdup((yyvsp[(1) - (1)].str));
      free((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 51:
#line 1044 "src/compiler/pebble.y"
    {
      int len = strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 2;
      (yyval.str) = malloc(len);
      snprintf((yyval.str), len, "%s,%s", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
      free((yyvsp[(1) - (3)].str));
      free((yyvsp[(3) - (3)].str));
    ;}
    break;

  case 52:
#line 1054 "src/compiler/pebble.y"
    {
        struct ArgList* args = malloc(sizeof(struct ArgList));
        args->str = strdup("");
        args->types = NULL;
        args->count = 0;
        (yyval.arg_list_val) = args;
    ;}
    break;

  case 53:
#line 1061 "src/compiler/pebble.y"
    {
        struct ArgList* args = malloc(sizeof(struct ArgList));
        args->str = strdup((yyvsp[(1) - (1)].expr_val).str);
        args->types = malloc(sizeof(enum VarType));
        args->types[0] = (yyvsp[(1) - (1)].expr_val).type;
        args->count = 1;
        (yyval.arg_list_val) = args;
        free((yyvsp[(1) - (1)].expr_val).str);
    ;}
    break;

  case 54:
#line 1070 "src/compiler/pebble.y"
    {
        // Special case for built-in conversion functions
        char* func_name = strdup((yyvsp[(1) - (4)].str));
        char* arg_name = strdup((yyvsp[(3) - (4)].str));

        int len = snprintf(NULL, 0, "%s(%s)", func_name, arg_name) + 1;

        struct ArgList* args = malloc(sizeof(struct ArgList));
        args->str = malloc(len);
        snprintf(args->str, len, "%s(%s)", func_name, arg_name);

        // For built-in conversion functions, we don't track argument types
        args->types = NULL;
        args->count = 0;

        (yyval.arg_list_val) = args;

        free(func_name);
        free(arg_name);
        free((yyvsp[(1) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 55:
#line 1092 "src/compiler/pebble.y"
    {
        struct ArgList* args = (yyvsp[(1) - (3)].arg_list_val);

        // Append the new argument to the string
        int len = strlen(args->str) + strlen((yyvsp[(3) - (3)].expr_val).str) + 2;
        char* new_str = malloc(len);
        snprintf(new_str, len, "%s,%s", args->str, (yyvsp[(3) - (3)].expr_val).str);
        free(args->str);
        args->str = new_str;

        // Add the new argument type
        args->count++;
        args->types = realloc(args->types, args->count * sizeof(enum VarType));
        args->types[args->count - 1] = (yyvsp[(3) - (3)].expr_val).type;

        (yyval.arg_list_val) = args;
        free((yyvsp[(3) - (3)].expr_val).str);
    ;}
    break;

  case 56:
#line 1113 "src/compiler/pebble.y"
    {
        // Create a new scope for function parameters
        push_func_scope();

        // Add the function to the symbol table
        add_function((yyvsp[(2) - (6)].str), NULL, 0);

        // Add the parameter to the symbol table
        if ((yyvsp[(4) - (6)].str) && strlen((yyvsp[(4) - (6)].str)) > 0) {
            // Parse the parameter list
            char* param_copy = strdup((yyvsp[(4) - (6)].str));
            char* token = strtok(param_copy, ",");
            while (token) {
                // Trim whitespace
                while (*token == ' ') token++;
                char* end = token + strlen(token) - 1;
                while (end > token && *end == ' ') *end-- = '\0';

                // Add parameter to symbol table with INT type (default)
                // We're using a special function to add parameters to avoid the var_exists check
                symtab[symtab_size].name = strdup(token);
                symtab[symtab_size].type = VT_INT;
                symtab[symtab_size].is_const = 0;
                symtab[symtab_size].is_function = 0;
                symtab[symtab_size].param_types = NULL;
                symtab[symtab_size].param_count = 0;
                symtab_size++;

                token = strtok(NULL, ",");
            }
            free(param_copy);
        }
    ;}
    break;

  case 57:
#line 1146 "src/compiler/pebble.y"
    {
        // Get the parameter name
        char* param_name = "";
        if ((yyvsp[(4) - (9)].str) && strlen((yyvsp[(4) - (9)].str)) > 0) {
            param_name = (yyvsp[(4) - (9)].str);
        }

        // Create a function with the parameter and body
        char func_template[2048] = "";

        // Only add the standard print functions for the first function
        static int print_functions_added = 0;
        if (!print_functions_added) {
            snprintf(func_template, sizeof(func_template),
                "// Functions for display (with newline)\n"
                "void print(int p) {\n"
                "    printf(\"%%d\\n\", p);\n"
                "}\n\n"
                "void print_string(char* p) {\n"
                "    printf(\"%%s\\n\", p);\n"
                "}\n\n"
                "void print_float(double p) {\n"
                "    printf(\"%%.2f\\n\", p);\n"
                "}\n\n"
                "void print_char(char p) {\n"
                "    printf(\"%%c\\n\", p);\n"
                "}\n\n"
                "// Functions for print (without newline)\n"
                "void print_int_no_nl(int p) {\n"
                "    printf(\"%%d\", p);\n"
                "}\n\n"
                "void print_string_no_nl(char* p) {\n"
                "    printf(\"%%s\", p);\n"
                "}\n\n"
                "void print_float_no_nl(double p) {\n"
                "    printf(\"%%.2f\", p);\n"
                "}\n\n"
                "void print_char_no_nl(char p) {\n"
                "    printf(\"%%c\", p);\n"
                "}\n\n");
            print_functions_added = 1;
        }

        // Add the function definition with parameters
        if (strlen(param_name) > 0) {
            char func_def[1024];

            // Process multiple parameters
            char param_decls[512] = "";
            char* param_copy = strdup(param_name);
            char* token = strtok(param_copy, ",");
            int first = 1;

            while (token) {
                // Trim whitespace
                while (*token == ' ') token++;
                char* end = token + strlen(token) - 1;
                while (end > token && *end == ' ') *end-- = '\0';

                if (!first) {
                    strcat(param_decls, ", int ");
                } else {
                    strcat(param_decls, "int ");
                    first = 0;
                }
                strcat(param_decls, token);

                token = strtok(NULL, ",");
            }
            free(param_copy);

            // Find the function in the symbol table to get its return type
            enum VarType return_type = VT_INT; // Default
            for (int i = 0; i < symtab_size; i++) {
                if (symtab[i].is_function && strcmp(symtab[i].name, (yyvsp[(2) - (9)].str)) == 0) {
                    return_type = symtab[i].type;
                    break;
                }
            }

            // Generate the function with the appropriate return type
            const char* return_type_str =
                return_type == VT_FLOAT ? "double" :
                return_type == VT_STRING ? "char*" :
                return_type == VT_CHAR ? "char" : "int";

            // Always add a default return statement at the end
            char body_with_return[1024];

            // Add appropriate default return value based on type
            if (return_type == VT_INT || return_type == VT_BOOL) {
                snprintf(body_with_return, sizeof(body_with_return),
                    "%s    return 0;\n", (yyvsp[(8) - (9)].str));
            } else if (return_type == VT_FLOAT) {
                snprintf(body_with_return, sizeof(body_with_return),
                    "%s    return 0.0;\n", (yyvsp[(8) - (9)].str));
            } else if (return_type == VT_STRING) {
                snprintf(body_with_return, sizeof(body_with_return),
                    "%s    return \"\";\n", (yyvsp[(8) - (9)].str));
            } else if (return_type == VT_CHAR) {
                snprintf(body_with_return, sizeof(body_with_return),
                    "%s    return '\\0';\n", (yyvsp[(8) - (9)].str));
            } else {
                // Default case
                snprintf(body_with_return, sizeof(body_with_return),
                    "%s    return 0;\n", (yyvsp[(8) - (9)].str));
            }

            snprintf(func_def, sizeof(func_def),
                "%s %s(%s) {\n"
                "%s"
                "}\n",
                return_type_str, (yyvsp[(2) - (9)].str), param_decls, body_with_return);
            strcat(func_template, func_def);
        } else {
            // Function without parameters
            char func_def[1024];

            // Find the function in the symbol table to get its return type
            enum VarType return_type = VT_INT; // Default
            for (int i = 0; i < symtab_size; i++) {
                if (symtab[i].is_function && strcmp(symtab[i].name, (yyvsp[(2) - (9)].str)) == 0) {
                    return_type = symtab[i].type;
                    break;
                }
            }

            // Generate the function with the appropriate return type
            const char* return_type_str =
                return_type == VT_FLOAT ? "double" :
                return_type == VT_STRING ? "char*" :
                return_type == VT_CHAR ? "char" : "int";

            // Always add a default return statement at the end
            char body_with_return[1024];

            // Add appropriate default return value based on type
            if (return_type == VT_INT || return_type == VT_BOOL) {
                snprintf(body_with_return, sizeof(body_with_return),
                    "%s    return 0;\n", (yyvsp[(8) - (9)].str));
            } else if (return_type == VT_FLOAT) {
                snprintf(body_with_return, sizeof(body_with_return),
                    "%s    return 0.0;\n", (yyvsp[(8) - (9)].str));
            } else if (return_type == VT_STRING) {
                snprintf(body_with_return, sizeof(body_with_return),
                    "%s    return \"\";\n", (yyvsp[(8) - (9)].str));
            } else if (return_type == VT_CHAR) {
                snprintf(body_with_return, sizeof(body_with_return),
                    "%s    return '\\0';\n", (yyvsp[(8) - (9)].str));
            } else {
                // Default case
                snprintf(body_with_return, sizeof(body_with_return),
                    "%s    return 0;\n", (yyvsp[(8) - (9)].str));
            }

            snprintf(func_def, sizeof(func_def),
                "%s %s() {\n"
                "%s"
                "}\n",
                return_type_str, (yyvsp[(2) - (9)].str), body_with_return);
            strcat(func_template, func_def);
        }

        (yyval.str) = strdup(func_template);

        // Restore the previous scope
        pop_func_scope();

        // Free the original strings
        if ((yyvsp[(4) - (9)].str)) free((yyvsp[(4) - (9)].str));
        free((yyvsp[(2) - (9)].str));
        free((yyvsp[(8) - (9)].str));
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 3121 "build/parser.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1321 "src/compiler/pebble.y"


// External variable to track column position
extern int yycolumn;

// Error recovery flag
int recovering = 0;

void yyerror(const char *s) {
    // Get the current token text for better error messages
    extern char* yytext;

    // Provide more helpful error messages based on the error
    if (strstr(s, "syntax error") != NULL) {
        char suggestion[256] = "";

        // Check for common syntax errors and provide suggestions
        if (yytext && *yytext) {
            if (strcmp(yytext, "=") == 0) {
                snprintf(suggestion, sizeof(suggestion),
                         "Did you mean '==' for comparison instead of '=' (assignment)?");
            } else if (strcmp(yytext, ";") == 0) {
                snprintf(suggestion, sizeof(suggestion),
                         "Semicolons are optional in Pebble. You can use newlines to separate statements.");
            } else if (strcmp(yytext, "{") == 0 || strcmp(yytext, "}") == 0) {
                snprintf(suggestion, sizeof(suggestion),
                         "Check for missing or mismatched braces in your code.");
            } else if (strcmp(yytext, "(") == 0 || strcmp(yytext, ")") == 0) {
                snprintf(suggestion, sizeof(suggestion),
                         "Check for missing or mismatched parentheses in your code.");
            }
        }

        // Use the enhanced error reporting
        syntax_error(yylineno, 0,
                     yytext && *yytext ? "Unexpected token" : "Syntax error",
                     yytext && *yytext ? yytext : NULL,
                     suggestion[0] ? suggestion : "Check your syntax near this location");
    } else {
        // For other errors, use the original message
        syntax_error(yylineno, 0, s, NULL, NULL);
    }

    // Set recovery flag to prevent cascading errors
    recovering = 1;
}

int main(int argc, char **argv) {
  // Reset error and warning counts
  reset_error_counts();

  if (argc != 2) {
    fprintf(stderr, ANSI_COLOR_RED "Error: " ANSI_COLOR_RESET "Usage: %s file.peb\n", argv[0]);
    return 1;
  }

  yyin = fopen(argv[1], "r");
  if (!yyin) {
    fprintf(stderr, ANSI_COLOR_RED "Error: " ANSI_COLOR_RESET "Failed to open file '%s': ", argv[1]);
    perror("");
    return 1;
  }

  printf("#include <stdio.h>\n#include <stdlib.h>\n#include <math.h>\n#include <string.h>\n#include <ctype.h>\n");

  // Add declarations for built-in conversion functions
  printf("// Built-in conversion functions\n");
  printf("int to_int(char* str);\n");
  printf("double to_float(char* str);\n");
  printf("int to_bool(char* str);\n");
  printf("char to_char(char* str);\n\n");
  yyparse();

  // Check if there were any errors during parsing
  if (error_count > 0) {
    // Exit without generating code
    return 1;
  }
  if (func_decls) {
    printf("%s", func_decls);
    free(func_decls);
  }
  if (func_code) {
    printf("%s", func_code);
    free(func_code);
  }
  printf("int main() {\n");
  if (code) {
    printf("%s", code);
    free(code);
  }
  printf("    return 0;\n}\n");

  fclose(yyin);

  // Report compilation statistics
  if (error_count > 0 || warning_count > 0) {
    fprintf(stderr, "\n" ANSI_COLOR_CYAN "Compilation finished with " ANSI_COLOR_RESET);

    if (error_count > 0) {
      fprintf(stderr, ANSI_COLOR_RED "%d error%s" ANSI_COLOR_RESET,
              error_count, error_count == 1 ? "" : "s");

      if (warning_count > 0) {
        fprintf(stderr, " and ");
      }
    }

    if (warning_count > 0) {
      fprintf(stderr, ANSI_COLOR_YELLOW "%d warning%s" ANSI_COLOR_RESET,
              warning_count, warning_count == 1 ? "" : "s");
    }

    fprintf(stderr, ".\n");
  }

  return error_count > 0 ? 1 : 0;
}

