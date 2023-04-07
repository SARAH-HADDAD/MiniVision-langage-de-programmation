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
%token <charactere> token_constChar
%token <boolean> token_constBool
%token token_IDF
%token token_ParOuvrante token_ParFermante token_CrochOuvrante token_CrochFermante
%token token_virgule token_Deux_Points 
%token token_plus token_moins token_fois token_divise token_Pourcentage
%token token_superieurEgal token_superieur token_inferieurEgal token_inferieur token_egal token_different
%token token_affectation
%token token_indentation
%start program

%%
S:   PROGRAM {printf("prog syntaxiquement correct");YYACCEPT;}

PROGRAM : LISTE_IMPORT LISTE_DECLARATION LISTE_INSTRUCTION ;
LISTE_IMPORT: IMPORT LISTE_IMPORT | /*vide*/;
LISTE_DECLARATION : DECLARATION LISTE_DECLARATION | /*vide*/;
LISTE_INSTRUCTION : INSTRUCTION LISTE_INSTRUCTION | /*vide*/;
IMPORT : token_import module_name | token_import module_name token_as token_IDF  {printf("import syntaxiquement correct");};
module_name: token_numpy | token_matplotlib.pyplot
DECLARATION : DECLARATION_SIMPLE | DECLARATION_TABLEAU;
DECLARATION_SIMPLE : token_IDF token_affectation EXPRESSION |TYPE token_IDF token_affectation EXPRESSION | TYPE token_IDF;
DECLARATION_TABLEAU : TYPE token_IDF token_CrochOuvrante token_constEntiere token_CrochFermante 
//| TYPE token_IDF token_CrochOuvrante token_constEntiere token_CrochFermante token_affectation token_CrochOuvrante LISTE_EXPRESSION token_CrochFermante
;
TYPE : token_int | token_float | token_char | token_bool;
INSTRUCTION : AFFECTATION | IF | WHILE | FOR;
AFFECTATION : token_IDF token_affectation EXPRESSION;
IF : token_if token_ParOuvrante CONDITION token_ParFermante token_Deux_Points LISTE_INSTRUCTION  ELSE;
ELSE : token_else token_Deux_Points LISTE_INSTRUCTION  | /*vide*/;
WHILE : token_while token_ParOuvrante CONDITION token_ParFermante token_Deux_Points LISTE_INSTRUCTION ;
FOR : token_for token_IDF token_in token_range token_ParOuvrante token_constEntiere token_virgule token_constEntiere token_ParFermante token_Deux_Points LISTE_INSTRUCTION 
| token_for token_IDF token_in token_IDF token_Deux_Points LISTE_INSTRUCTION
;
CONDITION : EXPRESSION COMPARATEUR EXPRESSION | EXPRESSION COMPARATEUR EXPRESSION LOGIQUE CONDITION|token_constBool|token_IDF;
//logiques and, or , not
LOGIQUE : token_and | token_or | token_not;
COMPARATEUR : token_superieurEgal | token_superieur | token_inferieurEgal | token_inferieur | token_egal | token_different;
EXPRESSION : TERME EXPRESSION_PRIME;
EXPRESSION_PRIME : token_plus TERME EXPRESSION_PRIME | token_moins TERME EXPRESSION_PRIME | /*vide*/;
TERME : FACTEUR TERME_PRIME;
TERME_PRIME : token_fois FACTEUR TERME_PRIME | token_divise FACTEUR TERME_PRIME | /*vide*/;
FACTEUR : token_ParOuvrante EXPRESSION token_ParFermante | token_constEntiere | token_constFlottante | token_constChar | token_IDF;
%%
int main(int argc, char** argv)
{
  if(argc>1)
  {
    yyin=fopen(argv[1],"r");
    if(yyin==NULL)
    {
      printf("Erreur d'ouverture du fichier %s",argv[1]);
        return 1;
    }
    }
    else
    {
      printf("Erreur d'ouverture du fichier %s",argv[1]);
      return 1;
    }
    yyparse();
    fclose(yyin);
    return 0;
}




