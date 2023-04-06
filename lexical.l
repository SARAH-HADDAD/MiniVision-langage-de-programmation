%{
#include <stdio.h>
#include <stdlib.h>
int nb_colonne = 1, nb_ligne = 1;
%}
lettre [a-z]
chiffre [0-9]
IDF [A-Z]({lettre}|{chiffre})*
COMMENT ^#[^\n]*\n
INT [+-]{chiffre}+|{chiffre}+
FLOAT [+-]({chiffre}+"."{chiffre}+)|({chiffre}+"."{chiffre}+)
CHAR ['][^'][']
BOOL "true"|"false"
%%
import {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);  
  printf("MotCle_import reconnu \n");
  nb_colonne += yyleng;
  // return (token_import);
}
numpy {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);     
  printf("Mc_numpy reconnu : %s \n", yytext);
  nb_colonne += yyleng;
  // return (token_numpy);
}
"matplotlib.pyplot" {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);    
  printf("Mc_matplotlib.pyplot reconnu : %s \n", yytext);
  nb_colonne += yyleng;
  // return (token_matplotlib.pyplot;
}
if {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);   
  printf("MotCle_if reconnu \n");
  nb_colonne += yyleng;
  // return (token_if);
}
else {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);   
  printf("MotCle_else reconnu \n");
  nb_colonne += yyleng;
  /* return (token_else); */
}
while {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne); 
  printf("MotCle_while reconnu \n");
  nb_colonne += yyleng;
  /* return (token_while); */
}
for {
  printf("nb_ligne=%d, nb_colonne=%d : ", nb_ligne, nb_colonne);
  printf("MotCle_for reconnu \n");
  nb_colonne += yyleng;
  /* return (token_for); */
}
in {
  printf("nb_ligne=%d, nb_colonne=%d : ", nb_ligne, nb_colonne);
  printf("MotCle_in reconnu \n");
  nb_colonne += yyleng;
  /* return (token_in); */
}
range {
  printf("nb_ligne=%d, nb_colonne=%d : ", nb_ligne, nb_colonne);
  printf("MotCle_range reconnu \n");
  nb_colonne += yyleng;
  /* return (token_range); */
}
int {
  printf("nb_ligne=%d, nb_colonne=%d : ", nb_ligne, nb_colonne);
  printf("MotCle_int reconnu \n");
  nb_colonne += yyleng;
  /* return (token_int); */
}
float {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne); 
  printf("MotCle_float reconnu \n");
  nb_colonne += yyleng;
  /* return (token_float); */
}
char {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne);   
  printf("MotCle_char reconnu \n");
  nb_colonne += yyleng;
  /* return (token_char); */
}
bool {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne); 
  printf("MotCle_bool reconnu \n");
  nb_colonne += yyleng;
  /* return (token_bool); */
}
as {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne); 
  printf("MotCle_as reconnu \n");
  nb_colonne += yyleng;
}
and {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne); 
  printf("Operateur logique: and\n");
  nb_colonne += yyleng;
}
or {
  printf("ligne=%d, colonne=%d : ", nb_ligne, nb_colonne); 
  printf("Operateur logique: or\n");
  nb_colonne += yyleng;
}
not {
  printf("nb_ligne=%d, nb_colonne=%d : ", nb_ligne, nb_colonne);
  printf("Operateur logique: not\n");
  nb_colonne += yyleng;
}
{INT}		{ printf("Constante entiere: %s\n", yytext); nb_colonne += yyleng;}
{FLOAT}		{ printf("Constante flottante: %s\n", yytext); nb_colonne += yyleng;}
{CHAR}		{ printf("Constante char: %s\n", yytext); nb_colonne += yyleng;}
{BOOL}		{ printf("Constante bool: %s\n", yytext); nb_colonne += yyleng;}
"("                          {printf("\n Sep_ParOuvrante reconnu \n"); nb_colonne += yyleng;   /*return (token_ParOuvrante);*/}
")"                          {printf("\n Sep_ParFermante reconnu \n"); nb_colonne += yyleng;   /*return (token_ParFermante);*/}
"["                          {printf("\n Sep_CrochOuvrante reconnu \n"); nb_colonne += yyleng; /*return (token_CrochOuvrante);*/}
"]"                          {printf("\n Sep_CrochFermante reconnu \n"); nb_colonne += yyleng; /*return (token_CrochFermante);*/}
","                          {printf("\n Sep_virgule reconnu \n"); nb_colonne += yyleng;       /*return (token_virgule);*/}
":"                          {printf("\n Sep_Deux_Points reconnu \n"); nb_colonne += yyleng;   /*return (token_Deux_Points);*/}
"%"                          {printf("\n Sep_Pourcentage reconnu \n"); nb_colonne += yyleng;   /*return (token_Pourcentage);*/}
"+"			{ printf("Operateur arithmetique: +\n"); nb_colonne += yyleng; }
"-"			{ printf("Operateur arithmetique: -\n"); nb_colonne += yyleng;}
"*"			{ printf("Operateur arithmetique: *\n"); nb_colonne += yyleng;}
"/"			{ printf("Operateur arithmetique: /\n"); nb_colonne += yyleng;}
">="			{ printf("Operateur de comparaison: >=\n"); nb_colonne += yyleng;}
">"			{ printf("Operateur de comparaison: >\n"); nb_colonne += yyleng;}
"<="			{ printf("Operateur de comparaison: <=\n"); nb_colonne += yyleng;}
"<"			{ printf("Operateur de comparaison: <\n"); nb_colonne += yyleng;}
"=="			{ printf("Operateur de comparaison: ==\n"); nb_colonne += yyleng;}
"!="			{ printf("Operateur de comparaison: !=\n"); nb_colonne += yyleng;}
"="			{ printf("Operateur d'affectation: =\n"); nb_colonne += yyleng;}
{IDF}		{ //Un IDF ne doit pas contenir plus de 8 caractères
if(strlen(yytext)>8) {
printf("Erreur: Identificateur trop long\n");
//exit(1);
}
else
printf("l entite lexical idf est reconnue %s \n",yytext); }
{COMMENT} {nb_colonne+=strlen(yytext); 	    printf("commentaire\n"); nb_ligne++;}
[ \t]                        {nb_colonne=nb_colonne+ strlen(yytext);}
"\n" {nb_ligne++; nb_colonne=1;}
. {printf("erreur lexical dans la ligne : %d colonne :%d  \n",nb_ligne,nb_colonne); nb_colonne=nb_colonne+ strlen(yytext);}
%%
int main() {
    yylex();
    return 0;
}
