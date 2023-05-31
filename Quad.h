#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Quad
{
	char *Operateur;
	char *opd1;
	char *opd2;
	char *temp;
	int QC;
	struct Quad *Suivant;
} Quad;

void InsertQuad(Quad **ListQuad, const char *Operateur, const char *opd1, const char *opd2, const char *temp, int QC)
{
	Quad *new = (Quad *)malloc(sizeof(Quad));
	if (new == NULL)
	{
		printf("Error: Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}

	Quad *tete = *ListQuad;
	Quad *prec = NULL;

	new->Operateur = strdup(Operateur);
	new->opd1 = strdup(opd1);
	new->opd2 = strdup(opd2);
	new->temp = strdup(temp);
	new->QC = QC;
	new->Suivant = NULL;

	if (tete == NULL)
	{
		*ListQuad = new;
	}
	else
	{
		while (tete != NULL)
		{
			prec = tete;
			tete = tete->Suivant;
		}
		prec->Suivant = new;
	}
}
void MaJ(Quad **ListQuad, int QC, int Address)
{

	Quad *tete = *ListQuad;
	char temp[254] = {};

	while (tete != NULL)
	{
		if (tete->QC == QC)
			break;
		else
			tete = tete->Suivant;
	}
	sprintf(temp, "%d", Address);
	tete->opd1 = strdup(temp);
}
void AffichageQuad(Quad *ListQuad)
{

	Quad *tete = ListQuad;
	if (tete == NULL)
		printf("Pas de quadruplets.\n");
	else
	{
		while (tete != NULL)
		{
			printf("\n%d-(%s,%s,%s,%s)\n", tete->QC, tete->Operateur, tete->opd1, tete->opd2, tete->temp);
			tete = tete->Suivant;
		}
	}
}

void supprimer(Quad **ListQuad, int QC)
{
	Quad *p, *prec, *q;

	if (*ListQuad != NULL)
	{
		if ((*ListQuad)->QC == QC) // le premier element
		{
			p = *ListQuad;
			*ListQuad = (*ListQuad)->Suivant;
			free(p);
		}
		else // les autres
		{
			prec = *ListQuad;
			p = (*ListQuad)->Suivant;
			while (p != NULL)
			{
				if (p->QC == QC)
				{
					prec->Suivant = p->Suivant;
					free(p);
					break;
				}
				prec = p;
				p = p->Suivant;
			}
		}
	}
}

void optimiser(Quad **ListQuad)
{
	Quad *tete = *ListQuad;
	Quad *p = tete;
	char temporaire[10];
	char expression[10];

	while (p != NULL)
	{
		if (strcmp(p->Operateur, "=") == 0 && strcmp(p->opd1, p->temp) == 0)
		{
			// Supprimer le quadruplet où une variable est affectée à elle-même
			supprimer(&tete, p->QC);
		}
		else if (strcmp(p->Operateur, "=") == 0)
		{
			// Propagation de la copie
			strcpy(temporaire, p->temp);
			strcpy(expression, p->opd1);

			// Parcourir les quadruplets suivants pour remplacer les occurrences de la variable
			Quad *q = p->Suivant;
			while (q != NULL)
			{
				if (strcmp(q->opd1, expression) == 0)
				{
					// 	remplacer opd1 par temporaire
					strcpy(q->opd1, temporaire);
				}
				if (strcmp(q->opd2, expression) == 0)
				{
					// 	remplacer opd2 par temporaire
					strcpy(q->opd2, temporaire);
				}
				q = q->Suivant;
			}
		}

		p = p->Suivant;
	}

	*ListQuad = tete;
}
