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
     token_int = 268,
     token_float = 269,
     token_char = 270,
     token_bool = 271,
     token_and = 272,
     token_or = 273,
     token_not = 274,
     token_constEntiere = 275,
     token_constFlottante = 276,
     token_constChar = 277,
     token_constBool = 278,
     token_constString = 279,
     token_idf = 280,
     token_ParOuvrante = 281,
     token_ParFermante = 282,
     token_CrochOuvrante = 283,
     token_CrochFermante = 284,
     token_virgule = 285,
     token_Deux_Points = 286,
     token_plus = 287,
     token_moins = 288,
     token_fois = 289,
     token_divise = 290,
     token_Pourcentage = 291,
     token_superieurEgal = 292,
     token_superieur = 293,
     token_inferieurEgal = 294,
     token_inferieur = 295,
     token_egal = 296,
     token_different = 297,
     token_affectation = 298,
     token_Point = 299,
     token_indentation = 300,
     token_newline = 301,
     token_shape = 302,
     token_show = 303,
     token_axis = 304,
     token_array = 305,
     token_imshow = 306
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
#define token_int 268
#define token_float 269
#define token_char 270
#define token_bool 271
#define token_and 272
#define token_or 273
#define token_not 274
#define token_constEntiere 275
#define token_constFlottante 276
#define token_constChar 277
#define token_constBool 278
#define token_constString 279
#define token_idf 280
#define token_ParOuvrante 281
#define token_ParFermante 282
#define token_CrochOuvrante 283
#define token_CrochFermante 284
#define token_virgule 285
#define token_Deux_Points 286
#define token_plus 287
#define token_moins 288
#define token_fois 289
#define token_divise 290
#define token_Pourcentage 291
#define token_superieurEgal 292
#define token_superieur 293
#define token_inferieurEgal 294
#define token_inferieur 295
#define token_egal 296
#define token_different 297
#define token_affectation 298
#define token_Point 299
#define token_indentation 300
#define token_newline 301
#define token_shape 302
#define token_show 303
#define token_axis 304
#define token_array 305
#define token_imshow 306




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 29 "syntax.y"
{
  int integer; 
  char* charactere;
  float flottant;
  char* str;
}
/* Line 1529 of yacc.c.  */
#line 158 "syntax.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

