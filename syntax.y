%{
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
%}
%union{
  int integer; 
  char* charactere;
  float flottant;
  char* str;
  struct 	{
    int Prog_Ind;
    int Pred_Ind;	
	} IF_Save;
}
%token token_import <str> token_numpy <str> token_matplotlib
%token token_if token_else token_while token_for token_in token_range token_as
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
%token token_show token_array token_imshow
%type <str> EXPRESSIONARITHMETIQUE
%type <str> F
%type <str> T
%type <str> token_plus
%type <str> token_moins
%type <str> token_fois
%type <str> token_divise
%type <str> token_Pourcentage
%type <str> EXPRESSIONCOMPARAISON
%type <str> OPERATEURCOMPARAISON
%type <IF_Save> token_if
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
{
InsertValChaine($4, $2);
insererTYPE($4,"STRING");
}
|token_import token_matplotlib token_as token_idf NEWLINES
{
InsertValChaine($4, $2);
insererTYPE($4,"STRING");
};

module_name: token_numpy | token_matplotlib; 

LIST_DECLARATION :  LIST_DECLARATION DECLARATION_TABLEAU| /*vide*/;

DECLARATION_TABLEAU : token_idf token_affectation token_CrochOuvrante LIST_EXPRESSION token_CrochFermante NEWLINES
|token_idf token_affectation token_CrochOuvrante  token_CrochFermante NEWLINES
|token_idf token_affectation token_CrochOuvrante LIST_TABLEAU token_CrochFermante NEWLINES
|token_idf token_affectation token_idf token_Point token_array token_ParOuvrante token_CrochOuvrante LIST_TABLEAU token_CrochFermante token_ParFermante NEWLINES
{// vérifier si idf est déclaré comme ça import numpy as idf
if(strcmp(GetValChaine($3),"numpy")!=0){
//printf("la valeur de idf :%s \n",GetValChaine($1));  
printf("ERREUR SÉMANTIQUE: ERROR IN NUMPY ARRAY DECLARATION\n");
exit(0);
}
else {
  insererTYPE($1,"INT");
}
};      

LIST_EXPRESSION: EXPRESSION | EXPRESSION token_virgule LIST_EXPRESSION ;

LIST_TABLEAU: token_CrochOuvrante LIST_EXPRESSION token_CrochFermante token_virgule LIST_TABLEAU 
| token_CrochOuvrante LIST_EXPRESSION token_CrochFermante;

LIST_INST:INSTRUCTION LIST_INST | INSTRUCTION NEWLINES LIST_INST | /*vide*/;

INSTRUCTION : AFFECTATION | BOUCLE_FOR1|BOUCLE_FOR2|BOUCLE_WHILE |IF_ELSE_STATEMENT | PLTSHOW | PLTIMSHOW;

PLTSHOW:token_idf token_Point token_show token_ParOuvrante token_ParFermante
{// vérifier si idf est déclaré comme ça import matplotlib.pyplot as idf
if(strcmp(GetValChaine($1),"matplotlib.pyplot")!=0){
//printf("la valeur de idf :%s \n",GetValChaine($1));  
printf("ERREUR SÉMANTIQUE: ERROR IN FUNCTION WRITING\n");
exit(0);
}};  

PLTIMSHOW:token_idf token_Point token_imshow token_ParOuvrante token_idf token_virgule token_idf token_affectation token_constString token_ParFermante
{// vérifier si idf est déclaré comme ça import matplotlib.pyplot as $1
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

if(Declaration($5)==0){
  printf("ERREUR SÉMANTIQUE: ERROR IN FUNCTION PARAMETERS: USAGE OF NO DECLARED VARIABLE\n");
  exit(0);
}
  // vérifier si $7 est cmap
  if(strcmp($7,"cmap")!=0){
    printf("ERREUR SÉMANTIQUE: ERROR IN FUNCTION PARAMETERS\n");
    exit(0);
  }
  InsertValChaine($7, $9);
  insererTYPE($7,"STRING");
}
}
;

AFFECTATION : token_idf token_affectation EXPRESSIONARITHMETIQUE 
{ T=strdup($1); 
      	       			InsertQuad(&Qdr,"=",$3," ",T,QC);	
      	     		    QC++; } ; 

EXPRESSIONARITHMETIQUE: EXPRESSIONARITHMETIQUE token_plus T
          {
						sprintf(Valeur,"T%d",cpt); T = strdup(Valeur); 
						InsertQuad(&Qdr,"+",$1,$3,T,QC); $$ = strdup(T);
						cpt++; QC++;     
					}
| EXPRESSIONARITHMETIQUE token_moins T
{ sprintf(Valeur,"T%d",cpt); T = strdup(Valeur); 
			     InsertQuad(&Qdr,"-",$1,$3,T,QC);$$ = strdup(T);
			     cpt++; QC++;}
| T{$$=strdup($1);};
T: T token_fois F
{sprintf(Valeur,"T%d",cpt); T = strdup(Valeur); 
			     InsertQuad(&Qdr,"*",$1,$3,T,QC);$$ = strdup(T);
			     cpt++; QC++;}
| T token_divise F
{sprintf(Valeur,"T%d",cpt); T = strdup(Valeur); 
						InsertQuad(&Qdr,"/",$1,$3,T,QC); $$ = strdup(T);
						cpt++; QC++;    }
| T token_Pourcentage F
{sprintf(Valeur,"T%d",cpt); T = strdup(Valeur); 
						InsertQuad(&Qdr,"%",$1,$3,T,QC); $$ = strdup(T);
						cpt++; QC++;    }
| F {$$=strdup($1);};
// InsertQuad(Quad** ListQuad, const char* Op, const char* Op1, const char* Op2, const char* T, int QC)
F: token_ParOuvrante EXPRESSIONARITHMETIQUE token_ParFermante {$$=strdup($2);}
| token_idf { $$=strdup($1); }
| token_constFlottante { 
  sprintf(Valeur, "%f", $1); 
  T = strdup(Valeur); 
  $$ = strdup(T);}  
| token_constEntiere { 
  sprintf(Valeur, "%d", $1); 
  T = strdup(Valeur); 
  $$ = strdup(T);}
;

BOUCLE_FOR1:token_for token_idf token_in token_range token_ParOuvrante EXPRESSION token_virgule EXPRESSION token_ParFermante token_Deux_Points token_newline LISTE_INSTRUCTION_BOUCLE
|token_for token_idf token_in token_range token_ParOuvrante EXPRESSION token_ParFermante token_Deux_Points token_newline LISTE_INSTRUCTION_BOUCLE;

BOUCLE_FOR2:token_for token_idf token_in token_idf token_Deux_Points token_newline LISTE_INSTRUCTION_BOUCLE;

BOUCLE_WHILE:token_while token_ParOuvrante CONDITION token_ParFermante token_Deux_Points token_newline LISTE_INSTRUCTION_BOUCLE;

IF_ELSE_STATEMENT:IF_CONDITION  ELSE_CONDITION ;

IF_CONDITION:token_if token_ParOuvrante CONDITION token_ParFermante token_Deux_Points token_newline LISTE_INSTRUCTION_BOUCLE
|token_if token_ParOuvrante CONDITION token_ParFermante token_Deux_Points INSTRUCTION token_newline;

ELSE_CONDITION:token_else token_Deux_Points token_newline LISTE_INSTRUCTION_BOUCLE|/*vide*/ {printf("else\n");};

LISTE_INSTRUCTION_BOUCLE: token_indentation INSTRUCTION token_newline LISTE_INSTRUCTION_BOUCLE| /*vide*/;
// | LISTE_INSTRUCTION_BOUCLE token_newline token_indentation INSTRUCTION token_newline;

EXPRESSION: token_idf
|token_constBool 
|token_constChar 
|token_constEntiere 
|token_constFlottante
;

EXPRESSIONLOGIQUE: EXPRESSIONARITHMETIQUE OPERATEURLOGIQUE EXPRESSIONARITHMETIQUE 
| token_not EXPRESSIONLOGIQUE;

OPERATEURLOGIQUE: token_and|token_or;

EXPRESSIONCOMPARAISON: EXPRESSIONARITHMETIQUE OPERATEURCOMPARAISON EXPRESSIONARITHMETIQUE
{ sprintf(Valeur,"T%d",cpt);T = strdup(Valeur);
					  InsertQuad(&Qdr,"-",$1,$3,T,QC);
					  QC++;
					  InsertQuad(&Qdr,$2," "," ",T,QC);
            sprintf(Valeur, "%d", QC);  // Convert QC to a string representation
            $$ = strdup(Valeur);  // Assign the string to yyval.str
					  QC++;
					  cpt++;
					  

					};;

OPERATEURCOMPARAISON: 
token_inferieur {$$=strdup("BL"); }
| token_inferieurEgal {$$=strdup("BLE"); }
| token_superieur {$$=strdup("BG"); }
| token_superieurEgal {$$=strdup("BGE"); }
| token_egal {$$=strdup("BE"); }
| token_different {$$=strdup("BNE"); };

CONDITION: EXPRESSIONCOMPARAISON | EXPRESSIONLOGIQUE;

NEWLINES: token_newline| NEWLINES token_newline;
%%

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




