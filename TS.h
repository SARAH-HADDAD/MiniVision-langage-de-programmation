/****************CREATION DE LA TABLE DES SYMBOLES ******************/
/***Step 1: Definition des structures de données ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
   int state;
   char name[20];
   char code[20];
   char type[20];
   float val;
   char valCh[100];
    /* */
 } element;

typedef struct
{ 
   int state; 
   char name[40];
   char type[25];
} elt;


/** il y' aura 3 tableau un pour les separateur un autre pour les MC et le dernier pour les IDF et CST*/
element tab[1000];
elt tabsep[50],tabmc[40];
extern char sav[20];
char chaine1 [2] = "";

/***Step 2: initialisation de l'état des cases des tables des symbloles***/
/*0: la case est libre    1: la case est occupée*/

void initialisation()
{
  int i;
  for (i=0;i<1000;i++)
  {
  tab[i].state=0;
  strcpy(tab[i].type,chaine1);
  tab[i].val=0;
  }

  for (i=0;i<40;i++)
    {tabsep[i].state=0;
    tabmc[i].state=0;}

}


/***Step 3: insertion des entititées lexicales dans les tables des symboles ***/

void inserer (char entite[], char code[],char type[],float val,int i, int y)
{
  switch (y)
 { 
   case 0:/*insertion dans la table des IDF et CONST*/
      if(tab[i].state==0){
       tab[i].state=1;
       strcpy(tab[i].name,entite);
       strcpy(tab[i].code,code);
	     strcpy(tab[i].type,type);
	     tab[i].val=val;
      }
	   break;

   case 1:/*insertion dans la table des mots clés*/
       tabmc[i].state=1;
       strcpy(tabmc[i].name,entite);
       strcpy(tabmc[i].type,code);
       break; 
    
   case 2:/*insertion dans la table des séparateurs*/
      tabsep[i].state=1;
      strcpy(tabsep[i].name,entite);
      strcpy(tabsep[i].type,code);
      break;
 }

}

/***Step 4: La fonction Rechercher permet de verifier  si l'entité existe dèja dans la table des symboles */
void rechercher (char entite[], char code[],char type[],float val,int y)	
{

int j,i;

switch(y) 
  {
   case 0:/*verifier si la case dans la tables des IDF et CONST est libre*/
        for (i=0;((i<1000)&&(tab[i].state==1))&&(strcmp(entite,tab[i].name)!=0);i++)
        {}
        if(i<1000)
        { 
	        
			inserer(entite,code,type,val,i,0); 
	      
         }
        //else
          //printf("entité existe déjà\n");
        break;

   case 1:/*verifier si la case dans la tables des mots clés est libre*/
       
       for (i=0;((i<40)&&(tabmc[i].state==1))&&(strcmp(entite,tabmc[i].name)!=0);i++)
       {} 
        if(i<40)
          inserer(entite,code,type,val,i,1);
        //else
          //printf("entité existe déjà\n");
        break; 
    
   case 2:/*verifier si la case dans la tables des séparateurs est libre*/
         for (i=0;((i<40)&&(tabsep[i].state==1))&&(strcmp(entite,tabsep[i].name)!=0);i++)
         {}
        if(i<40)
         inserer(entite,code,type,val,i,2);
        //else
   	       //printf("entité existe déjà\n");
        break;
  }

}
/***Step 5 L'affichage du contenue de la table des symboles ***/

void afficher()
{int i;

printf("\n\n\t/***************\tTable des symboles IDF\t*************/\n\n");
printf("____________________________________________________________________\n");
printf("\t Nom_Entite |  Code_Entite   |  Type_Entite | Val_Entite\n");
printf("____________________________________________________________________\n");
  
for(i=0;i<1000;i++)
{ 
  
    if(tab[i].state==1)
      { if(strcmp(tab[i].type,"FLOAT")!=0 && strcmp(tab[i].type,"INTEGER")!=0 ){
         printf(" %18s |%15s | %12s | %s\n",tab[i].name,tab[i].code,tab[i].type,tab[i].valCh);}

         else{
           printf(" %18s |%15s | %12s | %12f\n",tab[i].name,tab[i].code,tab[i].type,tab[i].val);
         }

    
         
      }
}

 
printf("\n\n\t/***************\tTable des symboles mots clés\t*************/\n\n");

printf("___________________________________________________________\n");
printf("\t\t NomEntite             |  CodeEntite       | \n");
printf("___________________________________________________________\n");
  
for(i=0;i<40;i++)
    if(tabmc[i].state==1)
      { 
        printf("%27s            |    %12s   | \n",tabmc[i].name, tabmc[i].type);
               
      }

printf("\n\n\t/***************\tTable des symboles séparateurs\t*************/\n\n");

printf("_____________________________________\n");
printf("\t| NomEntite |  CodeEntite | \n");
printf("_____________________________________\n");
  
for(i=0;i<40;i++)
    if(tabsep[i].state==1)
      {
        switch (tabsep[i].name[0]) {
    case '\n':
        printf("\t|\t\\n  |%12s | \n",tabsep[i].type );
        break;
    case '\t':
        printf("\t|\t\\t  |%12s | \n",tabsep[i].type );
        break;
    default:
        printf("\t|%10s |%12s | \n",tabsep[i].name,tabsep[i].type );
        break;
}
 
    }
      
}