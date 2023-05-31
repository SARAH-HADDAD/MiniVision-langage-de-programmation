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
     token_import = 258,
     token_numpy = 259,
     token_matplotlib = 260,
     token_if = 261,
     token_else = 262,
     token_while = 263,
     token_for = 264,
     token_in = 265,
     token_range = 266,
     token_as = 267,
     token_and = 268,
     token_or = 269,
     token_not = 270,
     token_constEntiere = 271,
     token_constFlottante = 272,
     token_constChar = 273,
     token_constBool = 274,
     token_constString = 275,
     token_idf = 276,
     token_ParOuvrante = 277,
     token_ParFermante = 278,
     token_CrochOuvrante = 279,
     token_CrochFermante = 280,
     token_virgule = 281,
     token_Deux_Points = 282,
     token_plus = 283,
     token_moins = 284,
     token_fois = 285,
     token_divise = 286,
     token_Pourcentage = 287,
     token_superieurEgal = 288,
     token_superieur = 289,
     token_inferieurEgal = 290,
     token_inferieur = 291,
     token_egal = 292,
     token_different = 293,
     token_affectation = 294,
     token_Point = 295,
     token_indentation = 296,
     token_newline = 297,
     token_show = 298,
     token_array = 299,
     token_imshow = 300
   };
#endif
/* Tokens.  */
#define token_import 258
#define token_numpy 259
#define token_matplotlib 260
#define token_if 261
#define token_else 262
#define token_while 263
#define token_for 264
#define token_in 265
#define token_range 266
#define token_as 267
#define token_and 268
#define token_or 269
#define token_not 270
#define token_constEntiere 271
#define token_constFlottante 272
#define token_constChar 273
#define token_constBool 274
#define token_constString 275
#define token_idf 276
#define token_ParOuvrante 277
#define token_ParFermante 278
#define token_CrochOuvrante 279
#define token_CrochFermante 280
#define token_virgule 281
#define token_Deux_Points 282
#define token_plus 283
#define token_moins 284
#define token_fois 285
#define token_divise 286
#define token_Pourcentage 287
#define token_superieurEgal 288
#define token_superieur 289
#define token_inferieurEgal 290
#define token_inferieur 291
#define token_egal 292
#define token_different 293
#define token_affectation 294
#define token_Point 295
#define token_indentation 296
#define token_newline 297
#define token_show 298
#define token_array 299
#define token_imshow 300




/* Copy the first part of user declarations.  */
#line 1 "syntax.y"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Quad.h"

int nb_ligne=1,nb_colonne=1;
int QC=0,cpt=1,First=0 ;
int Prog_Ind=0,Pred_Ind=0;
Quad* Qdr=NULL;
char *T;
char Valeur[254] = { } ;
void initialization();
void afficher();
void insererTYPE();
char *GetType();
void InsertValChaine();
char *GetValChaine();
int Declaration();
int yylex(void);
void yyerror (const char *str) {fprintf (stderr, "error: %s\n", str);}
int yywrap(void);


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
#line 24 "syntax.y"
{
  int integer; 
  char* charactere;
  float flottant;
  char* str;
  struct 	{
    int Prog_Ind;
    int Pred_Ind;	
	} IF_Save;
}
/* Line 193 of yacc.c.  */
#line 221 "syntax.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 234 "syntax.tab.c"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   185

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNRULES -- Number of states.  */
#define YYNSTATES  163

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

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
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    12,    13,    17,    23,    29,
      31,    33,    36,    37,    44,    50,    57,    69,    71,    75,
      81,    85,    88,    92,    93,    95,    97,    99,   101,   103,
     105,   107,   113,   124,   128,   132,   136,   138,   142,   146,
     150,   152,   156,   158,   160,   162,   175,   186,   194,   202,
     205,   213,   221,   226,   227,   232,   233,   235,   237,   239,
     241,   243,   247,   250,   252,   254,   258,   260,   262,   264,
     266,   268,   270,   272,   274,   276
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,    49,    52,    56,    -1,    49,
      50,    -1,    -1,     3,    51,    77,    -1,     3,     4,    12,
      21,    77,    -1,     3,     5,    12,    21,    77,    -1,     4,
      -1,     5,    -1,    52,    53,    -1,    -1,    21,    39,    24,
      54,    25,    77,    -1,    21,    39,    24,    25,    77,    -1,
      21,    39,    24,    55,    25,    77,    -1,    21,    39,    21,
      40,    44,    22,    24,    55,    25,    23,    77,    -1,    71,
      -1,    71,    26,    54,    -1,    24,    54,    25,    26,    55,
      -1,    24,    54,    25,    -1,    57,    56,    -1,    57,    77,
      56,    -1,    -1,    60,    -1,    64,    -1,    65,    -1,    66,
      -1,    67,    -1,    58,    -1,    59,    -1,    21,    40,    43,
      22,    23,    -1,    21,    40,    45,    22,    21,    26,    21,
      39,    20,    23,    -1,    21,    39,    61,    -1,    61,    28,
      62,    -1,    61,    29,    62,    -1,    62,    -1,    62,    30,
      63,    -1,    62,    31,    63,    -1,    62,    32,    63,    -1,
      63,    -1,    22,    61,    23,    -1,    21,    -1,    17,    -1,
      16,    -1,     9,    21,    10,    11,    22,    71,    26,    71,
      23,    27,    42,    70,    -1,     9,    21,    10,    11,    22,
      71,    23,    27,    42,    70,    -1,     9,    21,    10,    21,
      27,    42,    70,    -1,     8,    22,    76,    23,    27,    42,
      70,    -1,    68,    69,    -1,     6,    22,    76,    23,    27,
      42,    70,    -1,     6,    22,    76,    23,    27,    57,    42,
      -1,     7,    27,    42,    70,    -1,    -1,    41,    57,    42,
      70,    -1,    -1,    21,    -1,    19,    -1,    18,    -1,    16,
      -1,    17,    -1,    61,    73,    61,    -1,    15,    72,    -1,
      13,    -1,    14,    -1,    61,    75,    61,    -1,    36,    -1,
      35,    -1,    34,    -1,    33,    -1,    37,    -1,    38,    -1,
      74,    -1,    72,    -1,    42,    -1,    77,    42,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    72,    72,    74,    76,    76,    78,    79,    84,    90,
      90,    92,    92,    94,    95,    96,    97,   109,   109,   111,
     112,   114,   114,   114,   116,   116,   116,   116,   116,   116,
     116,   118,   126,   159,   163,   169,   173,   174,   178,   182,
     186,   188,   189,   190,   194,   200,   201,   203,   205,   207,
     209,   210,   212,   212,   214,   214,   217,   218,   219,   220,
     221,   224,   225,   227,   227,   229,   243,   244,   245,   246,
     247,   248,   250,   250,   252,   252
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "token_import", "token_numpy",
  "token_matplotlib", "token_if", "token_else", "token_while", "token_for",
  "token_in", "token_range", "token_as", "token_and", "token_or",
  "token_not", "token_constEntiere", "token_constFlottante",
  "token_constChar", "token_constBool", "token_constString", "token_idf",
  "token_ParOuvrante", "token_ParFermante", "token_CrochOuvrante",
  "token_CrochFermante", "token_virgule", "token_Deux_Points",
  "token_plus", "token_moins", "token_fois", "token_divise",
  "token_Pourcentage", "token_superieurEgal", "token_superieur",
  "token_inferieurEgal", "token_inferieur", "token_egal",
  "token_different", "token_affectation", "token_Point",
  "token_indentation", "token_newline", "token_show", "token_array",
  "token_imshow", "$accept", "S", "PROGRAM", "LISTE_IMPORT", "IMPORT",
  "module_name", "LIST_DECLARATION", "DECLARATION_TABLEAU",
  "LIST_EXPRESSION", "LIST_TABLEAU", "LIST_INST", "INSTRUCTION", "PLTSHOW",
  "PLTIMSHOW", "AFFECTATION", "EXPRESSIONARITHMETIQUE", "T", "F",
  "BOUCLE_FOR1", "BOUCLE_FOR2", "BOUCLE_WHILE", "IF_ELSE_STATEMENT",
  "IF_CONDITION", "ELSE_CONDITION", "LISTE_INSTRUCTION_BOUCLE",
  "EXPRESSION", "EXPRESSIONLOGIQUE", "OPERATEURLOGIQUE",
  "EXPRESSIONCOMPARAISON", "OPERATEURCOMPARAISON", "CONDITION", "NEWLINES", 0
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
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    49,    49,    50,    50,    50,    51,
      51,    52,    52,    53,    53,    53,    53,    54,    54,    55,
      55,    56,    56,    56,    57,    57,    57,    57,    57,    57,
      57,    58,    59,    60,    61,    61,    61,    62,    62,    62,
      62,    63,    63,    63,    63,    64,    64,    65,    66,    67,
      68,    68,    69,    69,    70,    70,    71,    71,    71,    71,
      71,    72,    72,    73,    73,    74,    75,    75,    75,    75,
      75,    75,    76,    76,    77,    77
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     2,     0,     3,     5,     5,     1,
       1,     2,     0,     6,     5,     6,    11,     1,     3,     5,
       3,     2,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     5,    10,     3,     3,     3,     1,     3,     3,     3,
       1,     3,     1,     1,     1,    12,    10,     7,     7,     2,
       7,     7,     4,     0,     4,     0,     1,     1,     1,     1,
       1,     3,     2,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     2,    12,     1,     0,     4,    23,     9,    10,
       0,     0,     0,     0,     0,    11,     3,    23,    29,    30,
      24,    25,    26,    27,    28,    53,     0,     0,    74,     6,
       0,     0,     0,     0,     0,     0,    21,    23,     0,    49,
       0,     0,    75,     0,    44,    43,    42,     0,     0,    36,
      40,    73,    72,     0,     0,     0,    42,     0,    33,     0,
       0,     0,    22,     0,     7,     8,     0,    62,     0,    63,
      64,     0,     0,    69,    68,    67,    66,    70,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    59,
      60,    58,    57,    56,     0,     0,     0,     0,    17,     0,
       0,    55,    41,    34,    35,    61,    65,    37,    38,    39,
       0,     0,     0,     0,     0,     0,    14,     0,     0,     0,
      31,     0,     0,    52,    55,     0,    55,     0,    55,     0,
      20,    13,    15,    18,     0,     0,    50,    51,    48,     0,
       0,    47,     0,     0,     0,    55,     0,     0,     0,    19,
       0,    54,    55,     0,     0,     0,    46,     0,     0,    32,
      55,    16,    45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     3,     6,    10,     7,    15,    96,    97,
      16,    17,    18,    19,    20,    48,    49,    50,    21,    22,
      23,    24,    25,    39,   123,    98,    51,    79,    52,    80,
      53,    29
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -121
static const yytype_int16 yypact[] =
{
    -121,    44,  -121,    43,  -121,    16,  -121,    58,    53,    83,
      15,    77,    86,   102,    74,  -121,  -121,     1,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,   117,   104,   105,  -121,    85,
      81,    81,   118,    70,   -31,    76,  -121,    10,   103,  -121,
      15,    15,  -121,    81,  -121,  -121,  -121,    34,    25,    80,
    -121,  -121,  -121,   106,   108,    24,    92,    64,    89,   111,
     112,    34,  -121,    93,    85,    85,    13,  -121,    45,  -121,
    -121,    34,    34,  -121,  -121,  -121,  -121,  -121,  -121,    34,
      34,    34,    34,    34,   109,   110,   116,   113,    95,  -121,
    -121,  -121,  -121,  -121,    88,    15,   119,   120,   121,   123,
     122,   101,  -121,    80,    80,    89,    89,  -121,  -121,  -121,
      28,   107,    88,   114,   126,   125,    85,    15,    15,    88,
    -121,   127,    63,  -121,   101,   115,   101,    67,   101,   128,
     129,    85,    85,  -121,   130,   124,  -121,  -121,  -121,   131,
      88,  -121,   135,   135,   132,   101,   133,   137,   136,  -121,
     134,  -121,   101,   138,   139,   140,  -121,   141,    15,  -121,
     101,    85,  -121
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,   -91,   -23,
      -4,  -105,  -121,  -121,  -121,   -32,    50,    -6,  -121,  -121,
    -121,  -121,  -121,  -121,  -120,  -110,   142,  -121,  -121,  -121,
     143,   -17
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      37,    58,   127,   115,   136,   125,   138,    11,   141,    12,
      13,    66,    59,    36,    60,    68,    11,   135,    12,    13,
       8,     9,    35,    64,    65,   151,    69,    70,   133,    58,
     147,    35,   156,    62,    11,    86,    12,    13,    69,    70,
     162,    71,    72,    28,     4,    87,     5,   105,   106,    35,
      44,    45,    42,    71,    72,    46,    47,    28,    73,    74,
      75,    76,    77,    78,    11,    26,    12,    13,   102,    11,
     124,    12,    13,    71,    72,   107,   108,   109,   116,    14,
      89,    90,    91,    92,    35,    93,    44,    45,    94,    95,
     139,    56,    47,   140,    57,    27,    43,    44,    45,    30,
     131,   132,    46,    47,    89,    90,    91,    92,    31,    93,
      81,    82,    83,    33,    34,    61,    34,    71,    72,   148,
     149,   103,   104,    32,    38,    40,    41,    42,    55,    84,
      63,    85,    88,    99,   100,   101,   110,   111,   112,   114,
     113,   161,   122,   121,   117,   118,   120,   119,   129,   126,
     130,   144,   142,   134,   155,   143,   128,   137,   146,    94,
     153,   154,   158,   159,     0,   157,   145,     0,     0,     0,
       0,   150,     0,     0,    54,   152,     0,     0,     0,     0,
       0,     0,     0,   160,     0,    67
};

static const yytype_int16 yycheck[] =
{
      17,    33,   112,    94,   124,   110,   126,     6,   128,     8,
       9,    43,    43,    17,    45,    47,     6,   122,     8,     9,
       4,     5,    21,    40,    41,   145,    13,    14,   119,    61,
     140,    21,   152,    37,     6,    11,     8,     9,    13,    14,
     160,    28,    29,    42,     0,    21,     3,    79,    80,    21,
      16,    17,    42,    28,    29,    21,    22,    42,    33,    34,
      35,    36,    37,    38,     6,    12,     8,     9,    23,     6,
      42,     8,     9,    28,    29,    81,    82,    83,    95,    21,
      16,    17,    18,    19,    21,    21,    16,    17,    24,    25,
      23,    21,    22,    26,    24,    12,    15,    16,    17,    22,
     117,   118,    21,    22,    16,    17,    18,    19,    22,    21,
      30,    31,    32,    39,    40,    39,    40,    28,    29,   142,
     143,    71,    72,    21,     7,    21,    21,    42,    10,    23,
      27,    23,    40,    22,    22,    42,    27,    27,    22,    44,
      27,   158,    41,    21,    25,    25,    23,    26,    22,    42,
      25,    21,    24,    26,    20,    26,    42,    42,    27,    24,
      23,    25,    23,    23,    -1,    27,    42,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    31,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,    48,    49,     0,     3,    50,    52,     4,     5,
      51,     6,     8,     9,    21,    53,    56,    57,    58,    59,
      60,    64,    65,    66,    67,    68,    12,    12,    42,    77,
      22,    22,    21,    39,    40,    21,    56,    77,     7,    69,
      21,    21,    42,    15,    16,    17,    21,    22,    61,    62,
      63,    72,    74,    76,    76,    10,    21,    24,    61,    43,
      45,    39,    56,    27,    77,    77,    61,    72,    61,    13,
      14,    28,    29,    33,    34,    35,    36,    37,    38,    73,
      75,    30,    31,    32,    23,    23,    11,    21,    40,    16,
      17,    18,    19,    21,    24,    25,    54,    55,    71,    22,
      22,    42,    23,    62,    62,    61,    61,    63,    63,    63,
      27,    27,    22,    27,    44,    54,    77,    25,    25,    26,
      23,    21,    41,    70,    42,    57,    42,    71,    42,    22,
      25,    77,    77,    54,    26,    57,    70,    42,    70,    23,
      26,    70,    24,    26,    21,    42,    27,    71,    55,    55,
      39,    70,    42,    23,    25,    20,    70,    27,    23,    23,
      42,    77,    70
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
        case 2:
#line 72 "syntax.y"
    {printf("The program is syntactically correct\n");YYACCEPT;;}
    break;

  case 7:
#line 80 "syntax.y"
    {
InsertValChaine((yyvsp[(4) - (5)].str), (yyvsp[(2) - (5)].str));
insererTYPE((yyvsp[(4) - (5)].str),"STRING");
;}
    break;

  case 8:
#line 85 "syntax.y"
    {
InsertValChaine((yyvsp[(4) - (5)].str), (yyvsp[(2) - (5)].str));
insererTYPE((yyvsp[(4) - (5)].str),"STRING");
;}
    break;

  case 16:
#line 98 "syntax.y"
    {// vérifier si idf est déclaré comme ça import numpy as idf
if(strcmp(GetValChaine((yyvsp[(3) - (11)].str)),"numpy")!=0){
//printf("la valeur de idf :%s \n",GetValChaine($1));  
printf("ERREUR SÉMANTIQUE: ERROR IN NUMPY ARRAY DECLARATION\n");
exit(0);
}
else {
  insererTYPE((yyvsp[(1) - (11)].str),"INT");
}
;}
    break;

  case 31:
#line 119 "syntax.y"
    {// vérifier si idf est déclaré comme ça import matplotlib.pyplot as idf
if(strcmp(GetValChaine((yyvsp[(1) - (5)].str)),"matplotlib.pyplot")!=0){
//printf("la valeur de idf :%s \n",GetValChaine($1));  
printf("ERREUR SÉMANTIQUE: ERROR IN FUNCTION WRITING\n");
exit(0);
};}
    break;

  case 32:
#line 127 "syntax.y"
    {// vérifier si idf est déclaré comme ça import matplotlib.pyplot as $1
if(strcmp(GetValChaine((yyvsp[(1) - (10)].str)),"matplotlib.pyplot")!=0){
//printf("ERREUR SÉMANTIQUE:la valeur de idf :%s \n",GetValChaine($1));  
printf("ERREUR SÉMANTIQUE: ERROR IN FUNCTION WRITING\n");
exit(0);
}
else{
// Variable Usage: The compiler should verify that the variable img is declared
// to say that the variable is declared or not i have to check if the variable is in the table of symbol have a type wla value
// lsl to fix later ..

// like pour les élement ta3 np array lzm nvérifier ila de meme type apres rah ydi hadak le type l np array

// i have to fix this lzm ndir un type l np array 
// to fix later..  
// vérifier si $5 est déclaré

if(Declaration((yyvsp[(5) - (10)].str))==0){
  printf("ERREUR SÉMANTIQUE: ERROR IN FUNCTION PARAMETERS: USAGE OF NO DECLARED VARIABLE\n");
  exit(0);
}
  // vérifier si $7 est cmap
  if(strcmp((yyvsp[(7) - (10)].str),"cmap")!=0){
    printf("ERREUR SÉMANTIQUE: ERROR IN FUNCTION PARAMETERS\n");
    exit(0);
  }
  InsertValChaine((yyvsp[(7) - (10)].str), (yyvsp[(9) - (10)].str));
  insererTYPE((yyvsp[(7) - (10)].str),"STRING");
}
;}
    break;

  case 33:
#line 159 "syntax.y"
    { T=strdup((yyvsp[(1) - (3)].str)); 
      	       			InsertQuad(&Qdr,"=",(yyvsp[(3) - (3)].str)," ",T,QC);	
      	     		    QC++; ;}
    break;

  case 34:
#line 164 "syntax.y"
    {
						sprintf(Valeur,"T%d",cpt); T = strdup(Valeur); 
						InsertQuad(&Qdr,"+",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),T,QC); (yyval.str) = strdup(T);
						cpt++; QC++;     
					;}
    break;

  case 35:
#line 170 "syntax.y"
    { sprintf(Valeur,"T%d",cpt); T = strdup(Valeur); 
			     InsertQuad(&Qdr,"-",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),T,QC);(yyval.str) = strdup(T);
			     cpt++; QC++;;}
    break;

  case 36:
#line 173 "syntax.y"
    {(yyval.str)=strdup((yyvsp[(1) - (1)].str));;}
    break;

  case 37:
#line 175 "syntax.y"
    {sprintf(Valeur,"T%d",cpt); T = strdup(Valeur); 
			     InsertQuad(&Qdr,"*",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),T,QC);(yyval.str) = strdup(T);
			     cpt++; QC++;;}
    break;

  case 38:
#line 179 "syntax.y"
    {sprintf(Valeur,"T%d",cpt); T = strdup(Valeur); 
						InsertQuad(&Qdr,"/",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),T,QC); (yyval.str) = strdup(T);
						cpt++; QC++;    ;}
    break;

  case 39:
#line 183 "syntax.y"
    {sprintf(Valeur,"T%d",cpt); T = strdup(Valeur); 
						InsertQuad(&Qdr,"%",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),T,QC); (yyval.str) = strdup(T);
						cpt++; QC++;    ;}
    break;

  case 40:
#line 186 "syntax.y"
    {(yyval.str)=strdup((yyvsp[(1) - (1)].str));;}
    break;

  case 41:
#line 188 "syntax.y"
    {(yyval.str)=strdup((yyvsp[(2) - (3)].str));;}
    break;

  case 42:
#line 189 "syntax.y"
    { (yyval.str)=strdup((yyvsp[(1) - (1)].str)); ;}
    break;

  case 43:
#line 190 "syntax.y"
    { 
  sprintf(Valeur, "%f", (yyvsp[(1) - (1)].flottant)); 
  T = strdup(Valeur); 
  (yyval.str) = strdup(T);;}
    break;

  case 44:
#line 194 "syntax.y"
    { 
  sprintf(Valeur, "%d", (yyvsp[(1) - (1)].integer)); 
  T = strdup(Valeur); 
  (yyval.str) = strdup(T);;}
    break;

  case 53:
#line 212 "syntax.y"
    {printf("else\n");;}
    break;

  case 65:
#line 230 "syntax.y"
    { sprintf(Valeur,"T%d",cpt);T = strdup(Valeur);
					  InsertQuad(&Qdr,"-",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),T,QC);
					  QC++;
					  InsertQuad(&Qdr,(yyvsp[(2) - (3)].str)," "," ",T,QC);
            sprintf(Valeur, "%d", QC);  // Convert QC to a string representation
            (yyval.str) = strdup(Valeur);  // Assign the string to yyval.str
					  QC++;
					  cpt++;
					  

					;}
    break;

  case 66:
#line 243 "syntax.y"
    {(yyval.str)=strdup("BL"); ;}
    break;

  case 67:
#line 244 "syntax.y"
    {(yyval.str)=strdup("BLE"); ;}
    break;

  case 68:
#line 245 "syntax.y"
    {(yyval.str)=strdup("BG"); ;}
    break;

  case 69:
#line 246 "syntax.y"
    {(yyval.str)=strdup("BGE"); ;}
    break;

  case 70:
#line 247 "syntax.y"
    {(yyval.str)=strdup("BE"); ;}
    break;

  case 71:
#line 248 "syntax.y"
    {(yyval.str)=strdup("BNE"); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1794 "syntax.tab.c"
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


#line 253 "syntax.y"


int main(){
    initialization();
    yyparse(); // analyseur lexical
    yywrap(); // analyseur syntaxique
    afficher();
    printf("\n***** Les Quadruples avant optimisation ***\n");
    AffichageQuad(Qdr);
    SimplificationAlgebrique(&Qdr);
    optimiser(&Qdr);
    printf("\n***** Les Quadruples après optimisation ***\n");
    AffichageQuad(Qdr);
    return 0;}





