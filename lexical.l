%{
#include <stdio.h>
#include <stdlib.h>
extern int nb_col= 1,nb_ligne=1;
%}
IDF		"[A-Z][a-z0-9]{0,7}"
COMMENT		"\\#.*"
INT	"-?[0-9]+"
FLOAT	"-?[0-9]+\\.[0-9]+"
CHAR	"'[a-zA-Z]'"
BOOL	"true|false"
%%
import {printf("\n MotCle_import reconnu \n"); nb_col += yyleng; return (token_MotCle_import);}
numpy {printf("\n Identificateur reconnu : %s \n", yytext); nb_col += yyleng; return (token_Identificateur);}
matplotlib.pyplot {printf("\n Identificateur reconnu : %s \n", yytext); nb_col += yyleng; return (token_Identificateur);}
if {printf("\n MotCle_if reconnu \n"); nb_col += yyleng; return (token_MotCle_if);}
else {printf("\n MotCle_else reconnu \n"); nb_col += yyleng; return (token_MotCle_else);}
while {printf("\n MotCle_while reconnu \n"); nb_col += yyleng; return (token_MotCle_while);}
for {printf("\n MotCle_for reconnu \n"); nb_col += yyleng; return (token_MotCle_for);}
in {printf("\n MotCle_in reconnu \n"); nb_col += yyleng; return (token_MotCle_in);}
range {printf("\n MotCle_range reconnu \n"); nb_col += yyleng; return (token_MotCle_range);}
int {printf("\n MotCle_int reconnu \n"); nb_col += yyleng; return (token_MotCle_int);}
float {printf("\n MotCle_float reconnu \n"); nb_col += yyleng; return (token_MotCle_float);}
char {printf("\n MotCle_char reconnu \n"); nb_col += yyleng; return (token_MotCle_char);}
bool {printf("\n MotCle_bool reconnu \n"); nb_col += yyleng; return (token_MotCle_bool);}
"("                          {printf("\n Sep_ParOuvrante reconnu \n"); nb_col += yyleng;   return (token_ParOuvrante);}
")"                          {printf("\n Sep_ParFermante reconnu \n"); nb_col += yyleng;   return (token_ParFermante);}
"["                          {printf("\n Sep_CrochOuvrante reconnu \n"); nb_col += yyleng; return (token_CrochOuvrante);}
"]"                          {printf("\n Sep_CrochFermante reconnu \n"); nb_col += yyleng; return (token_CrochFermante);}
","                          {printf("\n Sep_virgule reconnu \n"); nb_col += yyleng;       return (token_virgule);}
":"                          {printf("\n Sep_Deux_Points reconnu \n"); nb_col += yyleng;   return (token_Deux_Points);}
"%"                          {printf("\n Sep_Pourcentage reconnu \n"); nb_col += yyleng;   return (token_Pourcentage);}
"+"			{ printf("Operateur arithmetique: +\n"); }
"-"			{ printf("Operateur arithmetique: -\n"); }
"*"			{ printf("Operateur arithmetique: *\n"); }
"/"			{ printf("Operateur arithmetique: /\n"); }
and			{ printf("Operateur logique: and\n"); }
or			{ printf("Operateur logique: or\n"); }
not			{ printf("Operateur logique: not\n"); }
">="			{ printf("Operateur de comparaison: >=\n"); }
">"			{ printf("Operateur de comparaison: >\n"); }
"<="			{ printf("Operateur de comparaison: <=\n"); }
"<"			{ printf("Operateur de comparaison: <\n"); }
"=="			{ printf("Operateur de comparaison: ==\n"); }
"!="			{ printf("Operateur de comparaison: !=\n"); }
{INT}		{ printf("Constante entiere: %s\n", yytext); }
{FLOAT}		{ printf("Constante flottante: %s\n", yytext); }
{CHAR}		{ printf("Constante char: %s\n", yytext); }
{BOOL}		{ printf("Constante bool: %s\n", yytext); }
{IDF}		{ //Un IDF ne doit pas contenir plus de 8 caractères
if(strlen(yytext)>8) {
printf("Erreur: Identificateur trop long\n");
//exit(1);
}
else
printf("Identificateur: %s\n", yytext); }
{COMMENT} {nb_col+=strlen(yytext); 	    printf("commentaire\n"); nb_ligne++;}
%%

int main() {
    yylex();
    return 0;
}
