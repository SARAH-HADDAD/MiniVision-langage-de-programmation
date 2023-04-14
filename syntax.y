%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int nb_ligne=1,nb_colonne=1;
%}
%union{
  int integer; 
  char*  charactere;
  float flottant;
  char* boolean;
}
%token token_import token_numpy token_matplotlib
%token token_if token_else token_while token_for token_in token_range
%token token_int token_float token_char token_bool token_as
%token token_and token_or token_not
%token <integer> token_constEntiere
%token <flottant> token_constFlottante
%token <charactere> token_constChar
%token <boolean> token_constBool
%token token_idf
%token token_ParOuvrante token_ParFermante token_CrochOuvrante token_CrochFermante
%token token_virgule token_Deux_Points 
%token token_plus token_moins token_fois token_divise token_Pourcentage
%token token_superieurEgal token_superieur token_inferieurEgal token_inferieur token_egal token_different
%token token_affectation
%token token_Point
%token token_indentation
%start S

%%
S:   PROGRAM {printf("prog syntaxiquement correct/n");YYACCEPT;}

PROGRAM : LISTE_IMPORT LISTE_DECLARATION LISTE_INSTRUCTION ;
LISTE_IMPORT: IMPORT LISTE_IMPORT | /*vide*/;
LISTE_DECLARATION : DECLARATION LISTE_DECLARATION | /*vide*/;
LISTE_INSTRUCTION : INSTRUCTION LISTE_INSTRUCTION | /*vide*/;
IMPORT : token_import module_name | token_import module_name token_as token_idf  {printf("import syntaxiquement correct/n");};
module_name: token_numpy | token_matplotlib 
DECLARATION : DECLARATION_VAR | DECLARATION_TABLEAU;
DECLARATION_VAR : token_idf token_affectation EXPRESSION ;
DECLARATION_TABLEAU : TYPE token_idf token_CrochOuvrante token_constEntiere token_CrochFermante 
//| TYPE token_idf token_CrochOuvrante token_constEntiere token_CrochFermante token_affectation token_CrochOuvrante LISTE_EXPRESSION token_CrochFermante
;
TYPE : token_int | token_float | token_char | token_bool;
INSTRUCTION : AFFECTATION | IF | WHILE | FOR;
AFFECTATION : token_idf token_affectation EXPRESSION;
IF : token_if token_ParOuvrante CONDITION token_ParFermante token_Deux_Points LISTE_INSTRUCTION  ELSE;
ELSE : token_else token_Deux_Points LISTE_INSTRUCTION  | /*vide*/;
WHILE : token_while token_ParOuvrante CONDITION token_ParFermante token_Deux_Points LISTE_INSTRUCTION ;
FOR : token_for token_idf token_in token_range token_ParOuvrante token_constEntiere token_virgule token_constEntiere token_ParFermante token_Deux_Points LISTE_INSTRUCTION 
| token_for token_idf token_in token_idf token_Deux_Points LISTE_INSTRUCTION
;
CONDITION : EXPRESSION COMPARATEUR EXPRESSION | EXPRESSION;
EXPRESSION : EXPRESSION_COMPARAISON | EXPRESSION_ARITHMETIQUE | token_constBool | AND | OR | NOT | token_not EXPRESSION | token_ParOuvrante EXPRESSION token_ParFermante ;
OR : EXPRESSION token_or EXPRESSION ;
AND : EXPRESSION token_and EXPRESSION ;
NOT : EXPRESSION token_not EXPRESSION ;
EXPRESSION_ARITHMETIQUE : token_idf | VAL | ADDITION | SUBSTRACTION | MULTIPLICATION | DIVITION | MODULO | token_plus EXPRESSION_ARITHMETIQUE | token_moins EXPRESSION_ARITHMETIQUE | token_ParOuvrante EXPRESSION_ARITHMETIQUE token_ParFermante;
ADDITION : EXPRESSION_ARITHMETIQUE token_plus EXPRESSION_ARITHMETIQUE;
SUBSTRACTION : EXPRESSION_ARITHMETIQUE token_moins EXPRESSION_ARITHMETIQUE;
MULTIPLICATION : EXPRESSION_ARITHMETIQUE token_fois EXPRESSION_ARITHMETIQUE;
DIVITION : EXPRESSION_ARITHMETIQUE token_divise EXPRESSION_ARITHMETIQUE;
MODULO : EXPRESSION_ARITHMETIQUE token_Pourcentage EXPRESSION_ARITHMETIQUE;
VAL : token_constEntiere | token_constFlottante | token_constChar | token_constBool;
EXPRESSION_COMPARAISON : EXPRESSION_ARITHMETIQUE COMPARATEUR EXPRESSION_ARITHMETIQUE | EXPRESSION_ARITHMETIQUE COMPARATEUR EXPRESSION_COMPARAISON 
						| EXPRESSION_ARITHMETIQUE COMPARATEUR token_bool | token_bool COMPARATEUR EXPRESSION_ARITHMETIQUE | token_bool COMPARATEUR token_bool	;
COMPARATEUR : token_superieurEgal | token_superieur | token_inferieurEgal | token_inferieur | token_egal | token_different;

%%

int main(){
    yyparse(); // analyseur lexical
    yywrap(); // analyseur syntaxique
    return 0;}




