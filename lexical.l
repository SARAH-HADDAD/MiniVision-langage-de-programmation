%{
#include <stdio.h>
#include <stdlib.h>
#include "syntax.tab.h"
extern int nb_colonne, nb_ligne;
extern YYSTYPE yylval ;
%}
chiffre [0-9]
IDF [a-zA-Z_][a-zA-Z0-9_]*
COMMENT ^#[^\n]*\n
INT [-+]?{chiffre}+
FLOAT [+-]({chiffre}+"."{chiffre}+)|({chiffre}+"."{chiffre}+)
CHAR ['][^'][']
BOOL "true"|"false"
Tab [\t]
%%
import {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);  
  printf("MotCle_import reconnu \n");
  nb_colonne += yyleng;
  return (token_import);
}
numpy {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);     
  printf("Mc_numpy reconnu : %s \n", yytext);
  nb_colonne += yyleng;
  return (token_numpy);
}
"matplotlib.pyplot" {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);    
  printf("Mc_matplotlib.pyplot reconnu : %s \n", yytext);
  nb_colonne += yyleng;
  return (token_matplotlib);
}
if {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);   
  printf("MotCle_if reconnu \n");
  nb_colonne += yyleng;
  return (token_if);
}
else {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);   
  printf("MotCle_else reconnu \n");
  nb_colonne += yyleng;
   return (token_else); 
}
while {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne); 
  printf("MotCle_while reconnu \n");
  nb_colonne += yyleng;
   return (token_while); 
}
for {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);
  printf("MotCle_for reconnu \n");
  nb_colonne += yyleng;
   return (token_for); 
}
in {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);
  printf("MotCle_in reconnu \n");
  nb_colonne += yyleng;
   return (token_in); 
}
range {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);
  printf("MotCle_range reconnu \n");
  nb_colonne += yyleng;
   return (token_range); 
}
int {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);
  printf("MotCle_int reconnu \n");
  nb_colonne += yyleng;
   return (token_int); 
}
float {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne); 
  printf("MotCle_float reconnu \n");
  nb_colonne += yyleng;
   return (token_float); 
}
char {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);   
  printf("MotCle_char reconnu \n");
  nb_colonne += yyleng;
   return (token_char); 
}
bool {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne); 
  printf("MotCle_bool reconnu \n");
  nb_colonne += yyleng;
   return (token_bool); 
}
as {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne); 
  printf("MotCle_as reconnu \n");
  nb_colonne += yyleng;
   return (token_as); 
}
and {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne); 
  printf("Operateur logique: and\n");
  nb_colonne += yyleng;
   return (token_and); 
}
or {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne); 
  printf("Operateur logique: or\n");
  nb_colonne += yyleng;
   return (token_or); 
}
not {
  printf("nb_ligne=%d, nb_colonne=%d : ", nb_ligne, nb_colonne);
  printf("Operateur logique: not\n");
  nb_colonne += yyleng;
   return (token_not); 
}
{INT} {
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);
    printf("Constante entiere: %s\n", yytext); 
    nb_colonne += yyleng;
     return (token_constEntiere); 
}
{FLOAT} { 
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);
    printf("Constante flottante: %s\n", yytext); 
    nb_colonne += yyleng;
     return (token_constFlottante); 
}
{CHAR} {
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne); 
    printf("Constante char: %s\n", yytext);
    nb_colonne += yyleng;
     return (token_constChar); 
}
{BOOL} {
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne); 
    printf("Constante bool: %s\n", yytext); 
    nb_colonne += yyleng;
     return (token_constBool); 
}
"." {
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);
    printf("Point reconnu \n"); 
    nb_colonne += yyleng;   
    return (token_Point);
}
"(" {
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);
    printf("Sep_ParOuvrante reconnu \n"); 
    nb_colonne += yyleng;   
    return (token_ParOuvrante);
}
")" {
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);
    printf("Sep_ParFermante reconnu \n"); 
    nb_colonne += yyleng;   
    return (token_ParFermante);
}
"[" {
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);
    printf("Sep_CrochOuvrante reconnu \n"); 
    nb_colonne += yyleng; 
    return (token_CrochOuvrante);
}
"]" {
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);
    printf("Sep_CrochFermante reconnu \n"); 
    nb_colonne += yyleng; 
    return (token_CrochFermante);
    }
"," {
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);
    printf("Sep_virgule reconnu \n"); 
    nb_colonne += yyleng;       
    return (token_virgule);
    }
":" {
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne); 
    printf("Sep_Deux_Points reconnu \n"); 
    nb_colonne += yyleng;   
    return (token_Deux_Points);
    }
"%" {
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);
    printf("Sep_Pourcentage reconnu \n"); 
    nb_colonne += yyleng;   
    return (token_Pourcentage);
    }
"+" { 
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);
    printf("Operateur arithmetique: +\n"); 
    nb_colonne += yyleng; 
    return (token_plus);
    }
"-"	{
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne); 
    printf("Operateur arithmetique: -\n"); 
    nb_colonne += yyleng;
    return (token_moins);
    }
"*" { 
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);
    printf("Operateur arithmetique: *\n"); 
    nb_colonne += yyleng;
    return (token_fois);
    }
"/" { 
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);
    printf("Operateur arithmetique: /\n"); 
    nb_colonne += yyleng;
    return (token_divise);
    }
">=" { 
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);
    printf("Operateur de comparaison: >=\n"); 
    nb_colonne += yyleng;
    return (token_superieurEgal);
    }
">"	{ 
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);
    printf("Operateur de comparaison: >\n"); 
    nb_colonne += yyleng;
    return (token_superieur);
    }
"<=" { 
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);
    printf("Operateur de comparaison: <=\n"); 
    nb_colonne += yyleng;
    return (token_inferieurEgal);
    }
"<" {
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne); 
    printf("Operateur de comparaison: <\n"); 
    nb_colonne += yyleng;
    return (token_inferieur);
    }
"==" {
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne); 
    printf("Operateur de comparaison: ==\n"); 
    nb_colonne += yyleng;
    return (token_egal);
    }
"!=" {
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne); 
    printf("Operateur de comparaison: !=\n"); 
    nb_colonne += yyleng;
    return (token_different);
    }
"=" {
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);
    printf("Operateur d'affectation: =\n"); 
    nb_colonne += yyleng;
    return (token_affectation);
    }
{IDF} { 
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);
    if(strlen(yytext)>8){
        printf("Erreur: Identificateur trop long\n");
        //exit(1);
        }
        else{
            printf("Idf reconnue : %s \n",yytext);
            nb_colonne += yyleng;
            return (token_idf);
            } }
{COMMENT} {
    printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);
    printf("Commentaire: %s\n", yytext);
    nb_colonne+=strlen(yytext);
}
{Tab} { 
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);   
  nb_colonne += yyleng; 	
  printf ("indentation \n");
  return token_indentation;
}
" " {nb_colonne=nb_colonne+ strlen(yytext);}
"\n" {nb_ligne++; nb_colonne=1;}
. {
    print("----------------------------------------------------------------------------------\n");
    printf("erreur lexical dans la ligne : %d colonne :%d  : %s\n",nb_ligne,nb_colonne,yytext);
    print("----------------------------------------------------------------------------------\n");
    nb_colonne=nb_colonne+ strlen(yytext);
    //exit(1);
}
%%