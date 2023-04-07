%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int nb_ligne=1,nb_colonne=1;
int yyerror(char* msg)
{printf("-----------------------------------------------------\n");
printf("Erreur syntaxique dans la ligne : %d colonne : %d\n",nb_ligne,nb_colonne);
return 0;
}
%}
%union{
  int integer; 
  char*  charactere;
  float flottant;
  char* boolean;
}
%token token_import token_numpy token_matplotlib.pyplot
%token token_if token_else token_while token_for token_in token_range
%token token_int token_float token_char token_bool token_as
%token token_and token_or token_not
%token <integer> token_constEntiere
%token <flottant> token_constFlottante
%token <charactere> token_CHAR
%token <boolean> token_constBool
%token token_IDF
%token token_ParOuvrante token_ParFermante token_CrochOuvrante token_CrochFermante
%token token_virgule token_Deux_Points token_Pourcentage
%token token_plus token_moins token_fois token_divise 
%token token_superieurEgal token_superieur token_inferieurEgal token_inferieur token_egal token_different
%token token_affectation