%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "Quad.h"

int nb_ligne=1,nb_colonne=1;
int QC=0,cpt=1;
//Quad* Qdr=NULL;
void initialization();
void afficher();
//void insererTYPE();
//char *GetType();
//void InsertValChaine();
//char *GetValChaine();
//int Declaration();
int yylex(void);
void yyerror (const char *str) {fprintf (stderr, "error: %s\n", str);}
int yywrap(void);
%}
%union{
  int integer; 
  char* charactere;
  float flottant;
  char* str;
}
%token token_import <str> token_numpy <str> token_matplotlib
%token token_if token_else token_while token_for token_in token_range token_as
%token token_int token_float token_char token_bool 
%token token_and token_or token_not
%token <integer> token_constEntiere
%token <flottant> token_constFlottante
%token <charactere> token_constChar
%token <str> token_constBool
%token <str> token_constString
%token <str> token_idf
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
S: PROGRAM {printf("The program is syntactically correct\n");YYACCEPT;}

PROGRAM : LISTE_IMPORT LIST_DECLARATION LIST_INST;

LISTE_IMPORT:  LISTE_IMPORT IMPORT| /*vide*/;

IMPORT : token_import module_name NEWLINES
|token_import token_numpy token_as token_idf NEWLINES
/*{
InsertValChaine($4, $2);
insererTYPE($4,"STRING");
}
|token_import token_matplotlib token_as token_idf NEWLINES
{
InsertValChaine($4, $2);
insererTYPE($4,"STRING");
}*/;

module_name: token_numpy | token_matplotlib; 

LIST_DECLARATION :  LIST_DECLARATION DECLARATION_TABLEAU| /*vide*/;

DECLARATION_TABLEAU : token_idf token_affectation token_CrochOuvrante LIST_EXPRESSION token_CrochFermante NEWLINES
|token_idf token_affectation token_CrochOuvrante  token_CrochFermante NEWLINES
|token_idf token_affectation token_CrochOuvrante LIST_TABLEAU token_CrochFermante NEWLINES
|token_idf token_affectation token_idf token_Point token_array token_ParOuvrante token_CrochOuvrante LIST_TABLEAU token_CrochFermante token_ParFermante NEWLINES
/*{// vérifier si idf est déclaré comme ça import numpy as idf
if(strcmp(GetValChaine($3),"numpy")!=0){
//printf("la valeur de idf :%s \n",GetValChaine($1));  
printf("ERREUR SÉMANTIQUE: ERROR IN ARRAY DECLARATION\n");
exit(0);
}}*/;      

LIST_EXPRESSION: EXPRESSION | EXPRESSION token_virgule LIST_EXPRESSION ;

LIST_TABLEAU: token_CrochOuvrante LIST_EXPRESSION token_CrochFermante token_virgule LIST_TABLEAU 
| token_CrochOuvrante LIST_EXPRESSION token_CrochFermante;

LIST_INST:INSTRUCTION LIST_INST | INSTRUCTION NEWLINES LIST_INST | /*vide*/;

INSTRUCTION : AFFECTATION | BOUCLE_FOR1|BOUCLE_FOR2|BOUCLE_WHILE |IF_ELSE_STATEMENT | PLTSHOW | PLTIMSHOW;

PLTSHOW:token_idf token_Point token_show token_ParOuvrante token_ParFermante
/*{// vérifier si idf est déclaré comme ça import matplotlib.pyplot as idf
if(strcmp(GetValChaine($1),"matplotlib.pyplot")!=0){
//printf("la valeur de idf :%s \n",GetValChaine($1));  
printf("ERREUR SÉMANTIQUE: ERROR IN FUNCTION WRITING\n");
exit(0);
}
}*/
;  

PLTIMSHOW:token_idf token_Point token_imshow token_ParOuvrante token_idf token_virgule token_idf token_affectation token_constString token_ParFermante
/*{// vérifier si idf est déclaré comme ça import matplotlib.pyplot as $1
if(strcmp(GetValChaine($1),"matplotlib.pyplot")!=0){
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
printf("la declaration de 5 est %d\n",Declaration($5));
if(Declaration($5)==0){
printf("ERREUR SÉMANTIQUE: ERROR IN FUNCTION PARAMETERS\n");
printf("ERREUR SÉMANTIQUE: THE USAGE OF AN UNDECLARED IDENTIFIER WITHOUT A VALUE\n");
exit(0);
}

  //printf("la fonction est correct\n");
  //printf(" $7 = %s $9 = %s \n",$7, $9);
  // vérifier si $7 est cmap
  if(strcmp($7,"cmap")!=0){
    printf("ERREUR SÉMANTIQUE: ERROR IN FUNCTION PARAMETERS\n");
    exit(0);
  }
  InsertValChaine($7, $9);
  insererTYPE($7,"STRING");

}
}*/
;

AFFECTATION : token_idf token_affectation E;

E: E token_plus T| E token_moins T| T;
T: T token_fois F| T token_divise F| T token_Pourcentage F| F;
F: token_ParOuvrante E token_ParFermante| token_constEntiere| token_constFlottante| token_idf;


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




