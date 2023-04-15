%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int nb_ligne=1,nb_colonne=1;

int yylex(void);
void yyerror (const char *str) {
    fprintf (stderr, "error: %s\n", str);
}
int yywrap(void);
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
%left token_not
%left token_and
%left token_or
%left token_inferieur token_inferieurEgal token_superieur token_superieurEgal token_egal token_different
%left token_ParOuvrante token_ParFermante
%left token_fois token_divise token_Pourcentage
%left token_plus token_moins
%left token_constEntiere token_constFlottante token_constChar token_constBool token_idf
%%
S: PROGRAM {printf("prog syntaxiquement correct\n");YYACCEPT;}

PROGRAM : LISTE_IMPORT LIST_DECLARATION INSTRUCTION;

LISTE_IMPORT:  LISTE_IMPORT IMPORT| /*vide*/;
IMPORT : token_import module_name 
| token_import module_name token_as token_idf;

module_name: token_numpy | token_matplotlib; 

LIST_DECLARATION :  LIST_DECLARATION DECLARATION_TABLEAU| /*vide*/;
DECLARATION_TABLEAU : token_idf token_affectation token_CrochOuvrante LIST_EXPRESSION token_CrochFermante
|token_idf token_affectation token_CrochOuvrante  token_CrochFermante 
|token_idf token_affectation token_CrochOuvrante LIST_TABLEAU token_CrochFermante      

LIST_EXPRESSION: EXPRESSION | EXPRESSION token_virgule LIST_EXPRESSION ;

LIST_TABLEAU: token_CrochOuvrante LIST_EXPRESSION token_CrochFermante token_virgule LIST_TABLEAU 
| token_CrochOuvrante LIST_EXPRESSION token_CrochFermante;
// INSTRUCTION :BOUCLE INSTRUCTION |AFFECTATION INSTRUCTION |ENTREES INSTRUCTION | Sortie INSTRUCTION |IF_STATEMENT INSTRUCTION| ;
INSTRUCTION : AFFECTATION INSTRUCTION| /*vide*/;
AFFECTATION : token_idf token_affectation EXPRESSION;

EXPRESSION: token_idf| token_constBool|token_constChar |token_constEntiere | token_constFlottante;

%%

int main(){
    yyparse(); // analyseur lexical
    yywrap(); // analyseur syntaxique
    return 0;}




