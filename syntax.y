%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int nb_ligne=1,nb_colonne=1;
void initialization();
void afficher();

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
  char* chaine;
}
%token token_import token_numpy token_matplotlib
%token token_if token_else token_while token_for token_in token_range token_as
%token token_int token_float token_char token_bool 
%token token_and token_or token_not
%token <integer> token_constEntiere
%token <flottant> token_constFlottante
%token <charactere> token_constChar
%token <boolean> token_constBool
%token <chaine> token_constString
%token token_idf
%token token_ParOuvrante token_ParFermante token_CrochOuvrante token_CrochFermante
%token token_virgule token_Deux_Points 
%token token_plus token_moins token_fois token_divise token_Pourcentage
%token token_superieurEgal token_superieur token_inferieurEgal token_inferieur token_egal token_different
%token token_affectation
%token token_Point
%token token_indentation token_newline
%token token_shape token_show token_axis token_array token_imshow
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

PROGRAM : LISTE_IMPORT LIST_DECLARATION LIST_INST;

LISTE_IMPORT:  LISTE_IMPORT IMPORT| /*vide*/;
IMPORT : token_import module_name NEWLINES
| token_import module_name token_as token_idf NEWLINES;

module_name: token_numpy | token_matplotlib; 

LIST_DECLARATION :  LIST_DECLARATION DECLARATION_TABLEAU| /*vide*/;
DECLARATION_TABLEAU : token_idf token_affectation token_CrochOuvrante LIST_EXPRESSION token_CrochFermante NEWLINES
|token_idf token_affectation token_CrochOuvrante  token_CrochFermante NEWLINES
|token_idf token_affectation token_CrochOuvrante LIST_TABLEAU token_CrochFermante NEWLINES| token_idf token_affectation token_idf token_Point token_array token_ParOuvrante token_CrochOuvrante LIST_TABLEAU token_CrochFermante token_ParFermante NEWLINES;      

LIST_EXPRESSION: EXPRESSION | EXPRESSION token_virgule LIST_EXPRESSION ;

LIST_TABLEAU: token_CrochOuvrante LIST_EXPRESSION token_CrochFermante token_virgule LIST_TABLEAU 
| token_CrochOuvrante LIST_EXPRESSION token_CrochFermante;

LIST_INST:INSTRUCTION LIST_INST | INSTRUCTION NEWLINES LIST_INST | /*vide*/;

INSTRUCTION : AFFECTATION | BOUCLE_FOR1|BOUCLE_FOR2|BOUCLE_WHILE |IF_ELSE_STATEMENT | PLTSHOW | PLTIMSHOW;

PLTSHOW:token_idf token_Point token_show token_ParOuvrante token_ParFermante;

PLTIMSHOW:token_idf token_Point token_imshow token_ParOuvrante token_idf token_virgule token_idf token_affectation token_constString token_ParFermante;

AFFECTATION : token_idf token_affectation EXPRESSION | token_idf token_affectation EXPRESSIONARITHMETIQUE;

BOUCLE_FOR1:token_for token_idf token_in token_range token_ParOuvrante EXPRESSION token_virgule EXPRESSION token_ParFermante token_Deux_Points token_newline LISTE_INSTRUCTION_BOUCLE
|token_for token_idf token_in token_range token_ParOuvrante EXPRESSION token_ParFermante token_Deux_Points token_newline LISTE_INSTRUCTION_BOUCLE;

BOUCLE_FOR2:token_for token_idf token_in token_idf token_Deux_Points token_newline LISTE_INSTRUCTION_BOUCLE;

BOUCLE_WHILE:token_while token_ParOuvrante CONDITION token_ParFermante token_Deux_Points token_newline LISTE_INSTRUCTION_BOUCLE;

IF_ELSE_STATEMENT:IF_CONDITION ELSE_CONDITION ;

IF_CONDITION:token_if token_ParOuvrante CONDITION token_ParFermante token_Deux_Points token_newline LISTE_INSTRUCTION_BOUCLE|token_if token_ParOuvrante CONDITION token_ParFermante token_Deux_Points INSTRUCTION token_newline;

ELSE_CONDITION:token_else token_Deux_Points token_newline LISTE_INSTRUCTION_BOUCLE|/*vide*/ {printf("else\n");};

LISTE_INSTRUCTION_BOUCLE: token_indentation INSTRUCTION token_newline LISTE_INSTRUCTION_BOUCLE| /*vide*/;
// | LISTE_INSTRUCTION_BOUCLE token_newline token_indentation INSTRUCTION token_newline;
EXPRESSION: token_idf| token_constBool|token_constChar |token_constEntiere | token_constFlottante;

OPERATEURSARITHMETIQUE: token_divise|token_fois|token_moins|token_plus|token_Pourcentage ;

EXPRESSIONARITHMETIQUE:EXPRESSION OPERATEURSARITHMETIQUE EXPRESSIONARITHMETIQUE
|EXPRESSION OPERATEURSARITHMETIQUE EXPRESSION
|token_ParOuvrante EXPRESSION OPERATEURSARITHMETIQUE EXPRESSION token_ParFermante
|token_ParOuvrante EXPRESSION OPERATEURSARITHMETIQUE EXPRESSIONARITHMETIQUE token_ParFermante
;

EXPRESSIONLOGIQUE: 
EXPRESSION OPERATEURLOGIQUE EXPRESSION| 
EXPRESSION OPERATEURLOGIQUE EXPRESSIONCOMPARAISON|
EXPRESSION OPERATEURLOGIQUE EXPRESSIONARITHMETIQUE|
EXPRESSIONCOMPARAISON OPERATEURLOGIQUE EXPRESSIONCOMPARAISON|
EXPRESSIONCOMPARAISON OPERATEURLOGIQUE EXPRESSION|
EXPRESSIONCOMPARAISON OPERATEURLOGIQUE EXPRESSIONARITHMETIQUE|
EXPRESSIONARITHMETIQUE  OPERATEURLOGIQUE EXPRESSIONCOMPARAISON|
EXPRESSIONARITHMETIQUE OPERATEURLOGIQUE EXPRESSION|
EXPRESSIONARITHMETIQUE OPERATEURLOGIQUE EXPRESSIONARITHMETIQUE|
EXPRESSIONLOGIQUE OPERATEURLOGIQUE token_ParOuvrante EXPRESSIONLOGIQUE token_ParFermante|
EXPRESSIONLOGIQUE OPERATEURLOGIQUE EXPRESSION|
EXPRESSIONLOGIQUE OPERATEURLOGIQUE EXPRESSIONARITHMETIQUE|
EXPRESSIONLOGIQUE OPERATEURLOGIQUE  EXPRESSIONCOMPARAISON|
token_ParOuvrante EXPRESSIONLOGIQUE token_ParFermante OPERATEURLOGIQUE EXPRESSIONLOGIQUE|
token_ParOuvrante EXPRESSIONLOGIQUE token_ParFermante OPERATEURLOGIQUE token_ParOuvrante EXPRESSIONLOGIQUE token_ParFermante
token_not EXPRESSION|
token_not EXPRESSIONLOGIQUE |
token_not token_ParOuvrante EXPRESSIONLOGIQUE token_ParFermante|
token_not EXPRESSIONCOMPARAISON|
token_not EXPRESSIONARITHMETIQUE;

OPERATEURLOGIQUE: token_and|token_or;

EXPRESSIONCOMPARAISON: EXPRESSION OPERATEURCOMPARAISON EXPRESSION
| EXPRESSION OPERATEURCOMPARAISON EXPRESSIONCOMPARAISON
| EXPRESSIONARITHMETIQUE OPERATEURCOMPARAISON EXPRESSIONCOMPARAISON
| EXPRESSIONARITHMETIQUE OPERATEURCOMPARAISON EXPRESSION
| EXPRESSIONARITHMETIQUE OPERATEURCOMPARAISON EXPRESSIONARITHMETIQUE
| token_ParOuvrante EXPRESSIONCOMPARAISON token_ParFermante
;
OPERATEURCOMPARAISON: token_inferieur| token_inferieurEgal| token_superieur| token_superieurEgal| token_egal| token_different;
CONDITION: EXPRESSIONCOMPARAISON| EXPRESSIONLOGIQUE|EXPRESSIONARITHMETIQUE;
// Y:EXPRESSIONARITHMETIQUE |EXPRESSION  ;

NEWLINES: token_newline| NEWLINES token_newline;
%%

int main(){
    initialization();
    yyparse(); // analyseur lexical
    yywrap(); // analyseur syntaxique
    afficher();
    return 0;}




