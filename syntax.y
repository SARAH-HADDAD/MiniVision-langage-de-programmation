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

%%
S:   PROGRAM {printf("prog syntaxiquement correct\n");YYACCEPT;}
PROGRAM : LISTE_IMPORT LIST_DECLARATION {printf("prog syntaxiquement correct\n");};
LISTE_IMPORT: IMPORT LISTE_IMPORT | /*vide*/;
IMPORT : token_import module_name | token_import module_name token_as token_idf  {printf("import syntaxiquement correct\n");};
module_name: token_numpy | token_matplotlib 
LIST_DECLARATION : DECLARATION_VAR | DECLARATION_TABLEAU | /*vide*/;
DECLARATION_VAR : token_idf token_affectation EXPRESSION  {printf("declaration var syntaxiquement correct\n");};
// ma_liste = [1, 2, 3, 4, 5]
// img = [[255, 100, 50], [200, 150, 75], [100, 50, 25]]
DECLARATION_TABLEAU : token_idf token_affectation token_CrochOuvrante LIST_EXPRESSION token_CrochFermante
{printf("declaration tab syntaxiquement correct rule 1\n");};
|token_idf token_affectation token_CrochOuvrante  token_CrochFermante 
{printf("declaration tab syntaxiquement correct rule 2\n");};
|token_idf token_affectation token_CrochOuvrante LIST_TABLEAU token_CrochFermante      
{printf("declaration tab syntaxiquement correct rule 3\n");};
LIST_EXPRESSION: EXPRESSION | EXPRESSION token_virgule LIST_EXPRESSION 
{printf("test\n");}
;
LIST_TABLEAU: token_CrochOuvrante LIST_EXPRESSION token_CrochFermante token_virgule LIST_TABLEAU 
{printf("liste tableau");} 
| token_CrochOuvrante LIST_EXPRESSION token_CrochFermante
{printf("liste tableau");}
;
EXPRESSION: token_idf| token_constBool|token_constChar |token_constEntiere | token_constFlottante;
%%

int main(){
    yyparse(); // analyseur lexical
    yywrap(); // analyseur syntaxique
    return 0;}




