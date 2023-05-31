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
/* Line 1529 of yacc.c.  */
#line 150 "syntax.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

