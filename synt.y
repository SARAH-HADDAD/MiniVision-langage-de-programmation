%{
  #include <stdio.h>
  #include <stdlib.h>

  int nb_lignes; 
  int col;
  int i, j;
  int cpt_param;
  char* sauvIdf[100];
  char* sign_form[100];
  char* list_param_e_s[100];
  
%}

%union 
{ 
    int entier; 
    char* str;
    char car;
    float reel;
    int boolean;
}

%token mc_idfDiv mc_dataDiv mc_pgmId mc_workStgSec mc_prcDiv mc_stpRun
%token <str>mc_int <str>mc_float <str>mc_char <str>mc_str <str>mc_cst
%token mc_or mc_and mc_not
%token mc_if mc_else mc_end mc_move mc_to mc_acc mc_disp
%token mc_G mc_GE mc_L mc_LE mc_EQ mc_DI
%token mc_line mc_size
%token <str>idf <car>cstChar <str>cstStr <entier>cstInt <reel>cstReel
%token point sep dpts vrg eq parOuv parFerm divi plus moins adr multi

%left plus moins
%left multi divi
%left mc_and
%left mc_or
%left mc_G mc_GE mc_L mc_LE mc_EQ mc_DI

%type<reel> expression
%type<str> type_cst

%start S
%%
S: PGM PGM_END 
    {printf ("\n\nProgramme syntaxiquement correcte\n\n"); YYACCEPT;}
;
PGM_END: mc_stpRun
;
PGM: identification_division data_divsion procedure_divsion
;
identification_division: mc_idfDiv point mc_pgmId point idf point
;
data_divsion: mc_dataDiv point working_storage_section
;
procedure_divsion: mc_prcDiv point instruction_list
;
working_storage_section: mc_workStgSec point declaration_list
;
declaration_list: declaration declaration_list
                | declaration
;
declaration: variable_list type point
           | const_declaration
;
type: mc_int {
        for(j=0; j<i; j++){
          if(doubleDeclaration(sauvIdf[j]) == 0 ){
              insererTYPE(sauvIdf[j], "INTEGER");
          } 
          else printf("\nErreur semantique %d:%d - %s: variable deja declaree.", nb_lignes, col, sauvIdf[j]);
        }
        i = 0;
    }
    | mc_float {
        for(j=0; j<i; j++){
          if(doubleDeclaration(sauvIdf[j]) == 0 ){
              insererTYPE(sauvIdf[j], "FLOAT");
          } 
          else printf("\nErreur semantique %d:%d - %s: variable deja declaree.", nb_lignes, col, sauvIdf[j]);
           
        }
        i = 0;
    }
    | mc_char {
        for(j=0; j<i; j++){
          if(doubleDeclaration(sauvIdf[j]) == 0 ){
              insererTYPE(sauvIdf[j], "CHAR");
          } 
          else printf("\nErreur semantique %d:%d - %s: variable deja declaree.", nb_lignes, col, sauvIdf[j]);
        }
        i = 0;
    }
    | mc_str {
        for(j=0; j<i; j++){
          if(doubleDeclaration(sauvIdf[j]) == 0 ){
              insererTYPE(sauvIdf[j], "STRING");
          } 
          else printf("\nErreur semantique %d:%d - %s: variable deja declaree.", nb_lignes, col, sauvIdf[j]);
           
        }
        i = 0;
    }
;
const_declaration: mc_cst idf type_cst point {
                   if(doubleDeclaration($2) != 0) printf("\nErreur semantique %d:%d - %s: Variable deja declaree.\n", nb_lignes, col, $1);
                   else{ 
                     insererTYPE($2, $3);
                     setConst($2);
                   }
                   ;
                  }
                 | mc_cst idf eq cstInt point {
                   if(doubleDeclaration($2) != 0) printf("\nErreur semantique %d:%d - %s: Variable deja declaree.\n", nb_lignes, col, $1);
                   else{
                     insererTYPE($2, "INTEGER");
                     char* temp;
                     sprintf(temp, "%d", $4);
                     updateValue($2, temp);
                     setConst($2);
                   }
                 }
                 | mc_cst idf eq cstReel point {
                   if(doubleDeclaration($2) != 0) printf("\nErreur semantique %d:%d - %s: Variable deja declaree.\n", nb_lignes, col, $1);
                   else{
                     insererTYPE($2, "FLOAT");
                     char* temp;
                     sprintf(temp, "%f", $4);
                     updateValue($2, temp);
                     setConst($2);
                   }
                 }
                 | mc_cst idf eq cstChar point {
                   if(doubleDeclaration($2) != 0) printf("\nErreur semantique %d:%d - %s: Variable deja declaree.\n", nb_lignes, col, $1);
                   else{
                     insererTYPE($2, "CHAR");
                     char* temp;
                     sprintf(temp, "%c", $4);
                     updateValue($2, temp);
                     setConst($2);
                   }
                 }
                 | mc_cst idf eq cstStr point {
                   if(doubleDeclaration($2) != 0) printf("\nErreur semantique %d:%d - %s: Variable deja declaree.\n", nb_lignes, col, $1);
                   else{
                     insererTYPE($2, "STRING");
                     updateValue($2, $4);
                     setConst($2);
                   }
                 }
;
type_cst: mc_int { $$ = strdup("INTEGER"); }
        | mc_float { $$ = strdup("FLOAT"); }
        | mc_str { $$ = strdup("STRING"); }
        | mc_char { $$ = strdup("CHAR"); }
;
variable_list: variable sep variable_list
             | variable
;
variable: idf {
              sauvIdf[i] = strdup($1); 
              i++;
            }
        | idf mc_line cstInt vrg mc_size cstInt {
            if($3 < 0 || $6 < 0 ) printf("\nErreur semantique %d:%d, la taille de tableau doit etre positive.\n");
            else {sauvIdf[i] = strdup($1); i++;}
          }
;
instruction_list: instruction instruction_list
                |
;
instruction: affectation
           | entree
           | sortie
           | if_condition
           | move_instruction
;
affectation: idf eq expression point {
                if(doubleDeclaration($1) == 0) printf("\nErreur semantique %d:%d - %s: Variable non declaree.\n", nb_lignes, col, $1);
                else if(cmpType($1, "STRING") == 0 || cmpType($1, "CHAR") == 0) printf("\nErreur semantique %d:%d: Types incompatibles.\n", nb_lignes, col);
                else if(isConst($1) && isInitialized($1)) printf("\nErreur semantique %d:%d: (%s) Constante deja initialisee.\n", nb_lignes, col, $1);
                else{
                  char* temp;
                  if(cmpType($1, "INTEGER") == 0) sprintf(temp, "%d", (int) $3);
                  if(cmpType($1, "FLOAT") == 0) sprintf(temp, "%f", $3);
                  updateValue($1, temp);
                }
              }
            | idf eq cstChar point {
              if(doubleDeclaration($1) == 0) printf("\nErreur semantique %d:%d - %s: Variable non declaree.\n", nb_lignes, col, $1);
              else if(isConst($1) && isInitialized($1)) printf("\nErreur semantique %d:%d: (%s) Constante deja initialisee.\n", nb_lignes, col, $1);
              else if(cmpType($1, "CHAR") == 0) {
                char temp[2];
                temp[0] = $3;
                updateValue($1, temp);
              }
              else printf("\nErreur semantique %d:%d: Types incompatibles.\n", nb_lignes, col);
            }
            | idf eq cstStr point {
              if(doubleDeclaration($1) == 0) printf("\nErreur semantique %d:%d - %s: Variable non declaree.\n", nb_lignes, col, $1);
              else if(isConst($1) && isInitialized($1)) printf("\nErreur semantique %d:%d: (%s) Constante deja initialisee.\n", nb_lignes, col, $1);
              else if(cmpType($1, "STRING") == 0){
                updateValue($1, $3);
              }
              else printf("\nErreur semantique %d:%d: Types incompatibles.\n", nb_lignes, col);
            }
;
expression: expression multi expression { $$=$1*$3; }
            | expression divi expression { 
                if($3 != 0) $$=$1/$3; 
                else printf("\nErreur semantique %d:%d, Division sur zero.\n", nb_lignes, col); 
              }
            | expression plus expression { $$=$1+$3; }
            | expression moins expression { $$=$1-$3; }
            | parOuv expression parFerm { $$=$2; }
            | cstInt { $$=$1; }
            | cstReel { $$=$1; }
            | idf {
              if(doubleDeclaration($1) == 0) printf("\nErreur semantique %d:%d - %s: Variable non declaree.\n", nb_lignes, col, $1);
              else if(cmpType($1, "STRING") == 0 || cmpType($1, "CHAR") == 0) printf("\nErreur semantique %d:%d: (%s) Types incompatibles.\n", nb_lignes, col, $1);
              else if(!isInitialized($1)) printf("\nErreur semantique %d:%d: (%s) Variable non initialisee.\n", nb_lignes, col, $1);
              else{
                char* temp;
                sprintf(temp,"%s", (char*) getValue($1));
                if(cmpType($1, "INTEGER") == 0) $$ = atoi(temp);
                if(cmpType($1, "FLOAT") == 0) $$ = atof(temp);
              }
            }
;
entree: mc_acc parOuv cstStr dpts adr idf parFerm point {
                    int c = 0;
                    i = 0;
                    char* temp = "";

                    for(c = 0; c<strlen($3); c++){
                      if($3[c] == '$') {temp = "INTEGER"; break;}
                      if($3[c] == '%') {temp = "FLOAT"; break;}
                      if($3[c] == '#') {temp = "STRING"; break;}
                      if($3[c] == '&') {temp = "CHAR"; break;}
                    }

                    if(cmpType($6, temp) != 0) printf("\nErreur semantique %d:%d, (%s) types incompatibles.\n", nb_lignes, col, $6);
                  
                }
;
sortie: mc_disp parOuv cstStr dpts list_param_s parFerm point {
                    int c = 0;
                    i = 0;
                    for(c = 0; c<strlen($3); c++){
                      if($3[c] == '$') {sign_form[i] = "INTEGER"; i++;}
                      if($3[c] == '%') {sign_form[i] = "FLOAT"; i++;}
                      if($3[c] == '#') {sign_form[i] = "STRING"; i++;}
                      if($3[c] == '&') {sign_form[i] = "CHAR"; i++;}
                    }

                    if(i != cpt_param) printf("\nErreur semantique %d:%d, le nombre d'arguments ne corrsepond pas a la chaine formatee.\n", nb_lignes, col);
                    else{
                      for(c = 0; c<i; c++){
                        if(cmpType(list_param_e_s[i-c-1], sign_form[c]) != 0) printf("\nErreur semantique %d:%d, (%s) types incompatibles.\n", nb_lignes, col, list_param_e_s[i-c-1]);
                      }
                    }
                    cpt_param = 0;
                }
            | mc_disp parOuv cstStr parFerm point {
                int c;
                for(c = 0; c<strlen($3); c++){
                      if($3[c] == '$' || $3[c] == '%' || $3[c] == '#' || $3[c] == '&') {
                        printf("\nErreur semantique %d:%d, Manque d'arguments.\n", nb_lignes, col);
                        break;
                      }
                    }
            }
;
list_param_s: idf sep list_param_s {
                if(doubleDeclaration($1) == 0) printf("\nErreur semantique %d:%d - %s: Variable non declaree.", nb_lignes, col, $1);
                else if(!isInitialized($1)) printf("\nErreur semantique %d:%d: (%s) Variable non initialisee.\n", nb_lignes, col, $1);
                else{
                  list_param_e_s[cpt_param] = strdup($1);
                  cpt_param++;
                }
              }
            | idf {
                if(doubleDeclaration($1) == 0) printf("\nErreur semantique %d:%d - %s: Variable non declaree.", nb_lignes, col, $1);
                else if(!isInitialized($1)) printf("\nErreur semantique %d:%d: (%s) Variable non initialisee.\n", nb_lignes, col, $1);
                else{
                  list_param_e_s[cpt_param] = strdup($1);
                  cpt_param++;
                }
              }
;
if_condition: mc_if parOuv expression_bool parFerm dpts instruction_list mc_end
            | mc_if parOuv expression_bool parFerm dpts instruction_list mc_else dpts instruction_list mc_end
;
expression_bool : expression_bool mc_and expression_bool
                | expression_bool mc_or expression_bool
                | parOuv expression_bool parFerm
                | comparaison
                | mc_not parOuv expression_bool parFerm
;
comparaison: expression mc_G expression
           | expression mc_GE expression
           | expression mc_L expression
           | expression mc_LE expression
           | expression mc_EQ expression
           | expression mc_DI expression
;
move_instruction: mc_move move_op mc_to move_op instruction_list mc_end
;
move_op: idf {
                if(doubleDeclaration($1) == 0) printf("\nErreur semantique %d:%d - %s: Variable non declaree.", nb_lignes, col, $1);
                else if(!isInitialized($1)) printf("\nErreur semantique %d:%d: (%s) Variable non initialisee.\n", nb_lignes, col, $1); 
                else if(cmpType($1, "INTEGER") != 0) printf("\nErreur semantique %d:%d - %s: Operande de MOVE invalide.", nb_lignes, col, $1);
              }
       | cstInt
;
%%
main()
{
  nb_lignes = 1; 
  col = 1;
  i =0;
  cpt_param = 0;

  initialisation();
  yyparse();
  afficher();
}
yywrap()
{}
yyerror (char*msg)
{
   printf("\nErreur syntaxique a la ligne %d et a la colonne %d", nb_lignes, col);
}