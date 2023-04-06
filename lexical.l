%{
#include <stdio.h>
#include <stdlib.h>
int nb_colonne= 1,nb_ligne=1;
%}
lettre [a-z]
chiffre [0-9]
IDF [A-Z]({lettre}|{chiffre})*
COMMENT "#"([^"\n"])*"!"
INT	[+-]{chiffre}+|{chiffre}+
FLOAT [+-]({chiffre}+"."{chiffre}+)|({chiffre}+"."{chiffre}+)
CHAR ['][^'][']
BOOL "true"|"false"
%%
import {printf("\n MotCle_import reconnu \n"); nb_colonne += yyleng; 
//return (token_MotCle_import);
}
numpy {printf("\n Identificateur reconnu : %s \n", yytext); nb_colonne += yyleng; 
//return (token_Identificateur);
}
"matplotlib.pyplot" {printf("\n Identificateur reconnu : %s \n", yytext); nb_colonne += yyleng; 
//return (token_Identificateur);
}
if {printf("\n MotCle_if reconnu \n"); nb_colonne += yyleng; //return (token_MotCle_if);
}
else {printf("\n MotCle_else reconnu \n"); nb_colonne += yyleng; /*return (token_MotCle_else);*/}
while {printf("\n MotCle_while reconnu \n"); nb_colonne += yyleng; /*return (token_MotCle_while);*/}
for {printf("\n MotCle_for reconnu \n"); nb_colonne += yyleng; /*return (token_MotCle_for);*/}
in {printf("\n MotCle_in reconnu \n"); nb_colonne += yyleng; /*return (token_MotCle_in);*/}
range {printf("\n MotCle_range reconnu \n"); nb_colonne += yyleng; /*return (token_MotCle_range);*/}
int {printf("\n MotCle_int reconnu \n"); nb_colonne += yyleng; /*return (token_MotCle_int);*/}
float {printf("\n MotCle_float reconnu \n"); nb_colonne += yyleng; /*return (token_MotCle_float);*/}
char {printf("\n MotCle_char reconnu \n"); nb_colonne += yyleng; /*return (token_MotCle_char);*/}
bool {printf("\n MotCle_bool reconnu \n"); nb_colonne += yyleng; /*return (token_MotCle_bool);*/}
as {printf("\n MotCle_as reconnu \n"); nb_colonne += yyleng;}
and			{ printf("Operateur logique: and\n"); nb_colonne += yyleng; }
or			{ printf("Operateur logique: or\n"); nb_colonne += yyleng;}
not			{ printf("Operateur logique: not\n"); nb_colonne += yyleng;}
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
