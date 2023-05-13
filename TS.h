#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element
{
    int state;
    char name[20];
    char code[20];
    char type[20];
    float val;
    char valCh[100];
    struct element *next;
} element;

typedef struct separator_element
{
    int state;
    char name[40];
    char type[25];
    struct separator_element *next;
} separator_element;

typedef struct keyword_element
{
    int state;
    char name[40];
    char type[25];
    struct keyword_element *next;
} keyword_element;

element *table = NULL;
separator_element *separator_table = NULL;
keyword_element *keyword_table = NULL;

extern char sav[20];
char chaine1[2] = "";

// Step 2: Initialization of symbol table
// 0: the entry is free, 1: the entry is occupied
void initialization()
{
    table = NULL;
    separator_table = NULL;
    keyword_table = NULL;
}

// Step 3: Insert lexical entities into symbol tables
void inserer(char entite[], char code[], char type[], float val, int i, int y)
{
    switch (y)
    {
    case 0: // Insert into the IDF and CONST table
    {
        if (table == NULL)
        {
            table = (element *)malloc(sizeof(element));
            table->state = 1;
            strcpy(table->name, entite);
            strcpy(table->code, code);
            strcpy(table->type, type);
            table->val = val;
            table->next = NULL;
        }
        else
        {
            element *newElement = (element *)malloc(sizeof(element));
            newElement->state = 1;
            strcpy(newElement->name, entite);
            strcpy(newElement->code, code);
            strcpy(newElement->type, type);
            newElement->val = val;
            newElement->next = table;
            table = newElement;
        }
    }
    break;

    case 1: // Insert into the keyword table
    {
        keyword_element *newKeyword = (keyword_element *)malloc(sizeof(keyword_element));
        newKeyword->state = 1;
        strcpy(newKeyword->name, entite);
        strcpy(newKeyword->type, code);
        newKeyword->next = keyword_table;
        keyword_table = newKeyword;
    }
    break;

    case 2: // Insert into the separator table
    {
        separator_element *newSeparator = (separator_element *)malloc(sizeof(separator_element));
        newSeparator->state = 1;
        strcpy(newSeparator->name, entite);
        strcpy(newSeparator->type, code);
        newSeparator->next = separator_table;
        separator_table = newSeparator;
    }
    break;
    }
}

/***Step 4: La fonction Rechercher permet de verifier  si l'entité existe dèja dans la table des symboles */
void rechercher(char entite[], char code[], char type[], float val, int y)
{
    switch (y)
    {
    case 0: // verifier si la case dans les tables des IDF et CONST est libre
    {
        int j = 0;
        element *currElement = table;
        while (currElement != NULL && currElement->state == 1 && strcmp(entite, currElement->name) != 0)
        {
            currElement = currElement->next;
            j++;
        }

        if (currElement == NULL)
        {
            inserer(entite, code, type, val, j, 0);
        }
    }
    break;

    case 1: // verifier si la case dans les tables des mots clés est libre
    {
        int j = 0;
        keyword_element *currKeyword = keyword_table;
        while (currKeyword != NULL && currKeyword->state == 1 && strcmp(entite, currKeyword->name) != 0)
        {
            currKeyword = currKeyword->next;
            j++;
        }
        if (currKeyword == NULL)
        {
            inserer(entite, code, type, val, j, 1);
        }
    }
    break;

    case 2: // verifier si la case dans les tables des séparateurs est libre
    {
        int j = 0;
        separator_element *currSeparator = separator_table;
        while (currSeparator != NULL && currSeparator->state == 1 && strcmp(entite, currSeparator->name) != 0)
        {
            currSeparator = currSeparator->next;
            j++;
        }
        if (currSeparator == NULL)
        {
            inserer(entite, code, type, val, j, 2);
        }
    }
    break;
    }
}

void afficher()
{

    printf("\n\n\t/***************\tSymbol Table: IDF\t*************/\n\n");
    printf("____________________________________________________________________\n");
    printf("\t Nom_Entite |  Code_Entite   |  Type_Entite | Val_Entite\n");
    printf("____________________________________________________________________\n");

    element *currElement = table;
    while (currElement != NULL)
    {
        if (currElement->state == 1)
        {
            if (strcmp(currElement->type, "FLOAT") != 0 && strcmp(currElement->type, "INTEGER") != 0)
            {
                printf(" %18s |%15s | %12s | %s\n", currElement->name, currElement->code, currElement->type, currElement->valCh);
            }
            else
            {
                printf(" %18s |%15s | %12s | %12f\n", currElement->name, currElement->code, currElement->type, currElement->val);
            }
        }
        currElement = currElement->next;
    }

    printf("\n\n\t/***************\tSymbol Table: Keywords\t*************/\n\n");
    printf("___________________________________________________________\n");
    printf("\t\t NomEntite             |  CodeEntite       | \n");
    printf("___________________________________________________________\n");

    keyword_element *currKeyword = keyword_table;
    while (currKeyword != NULL)
    {
        if (currKeyword->state == 1)
        {
            printf("%27s            |    %12s   | \n", currKeyword->name, currKeyword->type);
        }
        currKeyword = currKeyword->next;
    }

    printf("\n\n\t/***************\tSymbol Table: Separators\t*************/\n\n");
    printf("_____________________________________\n");
    printf("\t| NomEntite |  CodeEntite | \n");
    printf("_____________________________________\n");

    separator_element *currSeparator = separator_table;
    while (currSeparator != NULL)
    {
        if (currSeparator->state == 1)
        {
            switch (currSeparator->name[0])
            {
            case '\n':
                printf("\t|\t\\n  |%12s | \n", currSeparator->type);
                break;
            case ' ':
                printf("\t|\t\\t  |%12s | \n", currSeparator->type);
                break;
            default:
                printf("\t|%10s |%12s | \n", currSeparator->name, currSeparator->type);
                break;
            }
        }
        currSeparator = currSeparator->next;
    }
}
void insererTYPE(char entite[], char type[])
{
    element *currElement = table;
    while (currElement != NULL)
    {
        if (strcmp(currElement->name, entite) == 0)
        {
            strcpy(currElement->type, type);
        }

        else
        {
            currElement = currElement->next;
        }
    }
}
char *GetType(char entite[])
{
    element *currElement = table;
    while (currElement != NULL)
    {
        if (strcmp(currElement->name, entite) == 0)
        {
            return currElement->type;
        }

        else
        {
            currElement = currElement->next;
        }
    }
    return " ";
}
void InsertValChaine(char entite[], char vall[])
{
    element *currElement = table;
    while (currElement != NULL)
    {
        if (strcmp(currElement->name, entite) == 0)
        {
            strcpy(currElement->valCh, vall);
        }

        else
        {
            currElement = currElement->next;
        }
    }
}