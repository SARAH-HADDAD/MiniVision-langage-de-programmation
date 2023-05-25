#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Quad {
    char* Op;
    char* Op1;
    char* Op2;
    char* T;
    int QC;
    struct Quad* Suivant;
} Quad;

void InsertQuad(Quad** ListQuad, const char* Op, const char* Op1, const char* Op2, const char* T, int QC) {
    Quad* nouveau = (Quad* )malloc(sizeof(Quad));
    if (nouveau == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    Quad* tete = *ListQuad;
    Quad* prec = NULL;

    nouveau->Op = strdup(Op);
    nouveau->Op1 = strdup(Op1);
    nouveau->Op2 = strdup(Op2);
    nouveau->T = strdup(T);
    nouveau->QC = QC;
    nouveau->Suivant = NULL;

    if (tete == NULL) {
        *ListQuad = nouveau;
    } else {
        while (tete != NULL) {
            prec = tete;
            tete = tete->Suivant;
        }
        prec->Suivant = nouveau;
    }
}
void MaJ(Quad** ListQuad , int QC , int Address)	{

Quad* tete = *ListQuad;
char T[254] = { } ;
	
	while (tete != NULL) {
	if(tete->QC == QC) break;
	else tete = tete->Suivant;
			     }
	sprintf(T,"%d",Address);
	tete->Op1=strdup(T);

							}
void AffichageQuad(Quad* ListQuad) 		{

Quad* tete = ListQuad;
	if (tete == NULL) printf("Pas de quadruplets.\n");
	else {  while(tete != NULL)     {
		printf("\n%d-(%s,%s,%s,%s)\n",tete->QC,tete->Op,tete->Op1,tete->Op2,tete->T);
		tete = tete->Suivant ;	}
	     }
						}

void supprimer(Quad** ListQuad,int QC)	
{
	Quad *p,*prec,*q;
	
	if(*ListQuad!=NULL)
	{
		if((*ListQuad)->QC==QC) //le premier element 
		{ p=*ListQuad;
		  *ListQuad=(*ListQuad)->Suivant;
		  free(p);
		 
		}
		else //les autres 
		{
		  prec= *ListQuad;
		  p=(*ListQuad)->Suivant;
		  while(p!=NULL)
		  { if(p->QC==QC)
		    {
		      prec->Suivant=p->Suivant;
		      free(p);
		      break;
		    }
		    prec=p;
		    p=p->Suivant;
		  }
		  
		}
	}

	
}                            