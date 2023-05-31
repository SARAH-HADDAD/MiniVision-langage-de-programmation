#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE_ONE 100
#define TABLE_SIZE_TWO 50
#

typedef struct element {
    int state;
    char name[20];
    char code[20];
    char type[20];
    float val;
    char valCh[100];
    struct element *next;
} element;

typedef struct separator_element {
    int state;
    char name[40];
    char type[25];
    struct separator_element *next;
} separator_element;

typedef struct keyword_element {
    int state;
    char name[40];
    char type[25];
    struct keyword_element *next;
} keyword_element;

element* table[TABLE_SIZE_ONE];
separator_element* separator_table[TABLE_SIZE_TWO];
keyword_element* keyword_table[TABLE_SIZE_TWO];

// Hash function
int hash1_function(const char* key) {
    unsigned long hash = 5381;
    int c;

    while ((c = *key++) != '\0') {
        hash = ((hash << 5) + hash) + c; // djb2 hash algorithm
    }

    return hash % TABLE_SIZE_ONE;
}
int hash2_function(char *chaine)
{
    int i = 0, nombreHache = 0;

    for (i = 0 ; chaine[i] != '\0' ; i++)
    {
        nombreHache += chaine[i];
    }
    nombreHache %= TABLE_SIZE_TWO;

    return nombreHache;
}

// Step 2: Initialization of symbol table
// 0: the entry is free, 1: the entry is occupied
void initialization() {
    for (int i = 0; i < TABLE_SIZE_ONE; i++) {
        table[i] = NULL;
    }
    for (int i = 0; i < TABLE_SIZE_TWO; i++) {
        separator_table[i] = NULL;
        keyword_table[i] = NULL;
    }
}

// Step 3: Insert lexical entities into symbol tables
void inserer(char entite[], char code[], char type[], float val, int y) {
    int hash;

    switch (y) {
        case 0: // Insert into the IDF and CONST table
        {
            hash = hash1_function(entite);

            if (table[hash] == NULL) {
                element* newElement = (element *)malloc(sizeof(element));
                if (newElement == NULL) {
                    printf("Memory allocation failed.\n");
                    return;
                }
                newElement->state = 1;
                strcpy(newElement->name, entite);
                strcpy(newElement->code, code);
                strcpy(newElement->type, type);
                newElement->val = val;
                newElement->valCh[0] = ' ';
                newElement->next = NULL;
                table[hash] = newElement;
                //printf("Inserted %s at table[%d]\n", entite, hash);
            } else {
                // we have a collision
                element* currElement = table[hash];
                while (currElement->next != NULL) {
                    currElement = currElement->next;
                }
                element* newElement = (element *)malloc(sizeof(element));
                if (newElement == NULL) {
                    printf("Memory allocation failed.\n");
                    return;
                }
                newElement->state = 1;
                strcpy(newElement->name, entite);
                strcpy(newElement->code, code);
                strcpy(newElement->type, type);
                newElement->val = val;
                newElement->valCh[0] = ' ';
                newElement->next = NULL;
                currElement->next = newElement;
                //printf("Inserted %s at table[%d] (collision)\n", entite, hash);
            }
        }
        break;

        case 1: // Insert into the keyword table
        {
            hash = hash2_function(entite);
            if (keyword_table[hash] == NULL) {
                keyword_element* newKeyword = (keyword_element *)malloc(sizeof(keyword_element));
                if (newKeyword == NULL) {
                    printf("Memory allocation failed.\n");
                    return;
                }
                newKeyword->state = 1;
                strcpy(newKeyword->name, entite);
                strcpy(newKeyword->type, code);
                newKeyword->next = NULL;
                keyword_table[hash] = newKeyword;
                //printf("Inserted %s at keyword_table[%d]\n", entite, hash);
            } else {
                keyword_element* currKeyword = keyword_table[hash];
                while (currKeyword->next != NULL) {
                    currKeyword = currKeyword->next;
                }
                keyword_element* newKeyword = (keyword_element *)malloc(sizeof(keyword_element));
                if (newKeyword == NULL) {
                    printf("Memory allocation failed.\n");
                    return;
                }
                newKeyword->state = 1;
                strcpy(newKeyword->name, entite);
                strcpy(newKeyword->type, code);
                newKeyword->next = NULL;
                currKeyword->next = newKeyword;
                //printf("Inserted %s at keyword_table[%d] (collision)\n", entite, hash);
            }
        }
        break;

        case 2: // Insert into the separator table
        {
            hash = hash2_function(entite);
            if (separator_table[hash] == NULL) {
                separator_element* newSeparator = (separator_element *)malloc(sizeof(separator_element));
                if (newSeparator == NULL) {
                    printf("Memory allocation failed.\n");
                    return;
                }
                newSeparator->state = 1;
                strcpy(newSeparator->name, entite);
                strcpy(newSeparator->type, code);
                newSeparator->next = NULL;
                separator_table[hash] = newSeparator;
                //printf("Inserted %s at separator_table[%d]\n", entite, hash);
            } else {
                separator_element* currSeparator = separator_table[hash];
                while (currSeparator->next != NULL) {
                    currSeparator = currSeparator->next;
                }
                separator_element* newSeparator = (separator_element *)malloc(sizeof(separator_element));
                if (newSeparator == NULL) {
                    printf("Memory allocation failed.\n");
                    return;
                }
                newSeparator->state = 1;
                strcpy(newSeparator->name, entite);
                strcpy(newSeparator->type, code);
                newSeparator->next = NULL;
                currSeparator->next = newSeparator;
                //printf("Inserted %s at separator_table[%d] (collision)\n", entite, hash);
            }
        }
        break;
    }
}
void rechercher(char entite[], char code[], char type[], float val, int y) {
    int hash;
    int trouve = 0;

    switch (y) {
        case 0: // Check if the entry in IDF and CONST tables is free
        {
            hash = hash1_function(entite);
            if (table[hash] == NULL) {
                inserer(entite, code, type, val, 0);
            } else {
                // Check if the entry at the hash index in IDF and CONST tables has the same entity
                element* currElement = table[hash];
                while (currElement != NULL) {
                    if (strcmp(currElement->name, entite) == 0) {
                        trouve = 1;
                        break;
                    }
                    currElement = currElement->next;
                }
                if (trouve == 0) {
                    inserer(entite, code, type, val, 0);
                }
            }
        }
        break;

        case 1: // Check if the entry in the keyword table is free
        {
            hash = hash2_function(entite);
            if (keyword_table[hash] == NULL) {
                inserer(entite, code, type, val, 1);
            } else {
                // Check if the entry at the hash index in the keyword table has the same entity
                keyword_element* currKeyword = keyword_table[hash];
                while (currKeyword != NULL) {
                    if (strcmp(currKeyword->name, entite) == 0) {
                        trouve = 1;
                        break;
                    }
                    currKeyword = currKeyword->next;
                }
                if (trouve == 0) {
                    inserer(entite, code, type, val, 1);
                }
            }
        }
        break;

        case 2: // Check if the entry in the separator table is free
        {
            hash = hash2_function(entite);
            if (separator_table[hash] == NULL) {
                inserer(entite, code, type, val, 2);
            } else {
                // Check if the entry at the hash index in the separator table has the same entity
                separator_element* currSeparator = separator_table[hash];
                while (currSeparator != NULL) {
                    if (strcmp(currSeparator->name, entite) == 0) {
                        trouve = 1;
                        break;
                    }
                    currSeparator = currSeparator->next;
                }
                if (trouve == 0) {
                    inserer(entite, code, type, val, 2);
                }
            }
        }
        break;
    }
}

void afficher() {
    printf("\n\n\t/***************\tSymbol Table: IDF\t*************/\n\n");
    printf("____________________________________________________________________\n");
    printf("\t Nom_Entite |  Code_Entite   |  Type_Entite | Val_Entite\n");
    printf("____________________________________________________________________\n");

    // Traverse the IDF table
    for (int i = 0; i < TABLE_SIZE_ONE; i++) {
        element* currElement = table[i];
        while (currElement != NULL) {
            if (currElement->state == 1) {
                if (strcmp(currElement->type, "FLOAT") != 0 && strcmp(currElement->type, "INTEGER") != 0) {
                    printf(" %18s |%15s | %12s | %s\n", currElement->name, currElement->code, currElement->type, currElement->valCh);
                } else {
                    printf(" %18s |%15s | %12s | %12f\n", currElement->name, currElement->code, currElement->type, currElement->val);
                }
            }
            currElement = currElement->next;
        }
    }

    printf("\n\n\t/***************\tSymbol Table: Keywords\t*************/\n\n");
    printf("___________________________________________________________\n");
    printf("\t\t NomEntite             |  CodeEntite       | \n");
    printf("___________________________________________________________\n");

    // Traverse the keyword table
    for (int i = 0; i < TABLE_SIZE_TWO; i++) {
        keyword_element* currKeyword = keyword_table[i];
        while (currKeyword != NULL) {
            if (currKeyword->state == 1) {
                printf("%27s            |    %12s   | \n", currKeyword->name, currKeyword->type);
            }
            currKeyword = currKeyword->next;
        }
    }

    printf("\n\n\t/***************\tSymbol Table: Separators\t*************/\n\n");
    printf("_____________________________________\n");
    printf("\t| NomEntite |  CodeEntite | \n");
    printf("_____________________________________\n");

    // Traverse the separator table
    for (int i = 0; i < TABLE_SIZE_TWO; i++) {
        separator_element* currSeparator = separator_table[i];
        while (currSeparator != NULL) {
            if (currSeparator->state == 1) {
                switch (currSeparator->name[0]) {
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
}

void insererTYPE(char entite[], char type[])
{
    int hash = hash1_function(entite);
    int trouve = 0;
    if (table[hash] != NULL) {
        element* currElement = table[hash];
        while (currElement != NULL && trouve == 0) {
            if (strcmp(currElement->name, entite) == 0) {
                trouve = 1;
                strcpy(currElement->type, type);
            }    
        }
    }
    else
    {
        printf("Erreur: %s n'existe pas dans la table des symboles\n", entite);
    }
}

char *GetType(char entite[])
{
    int hash = hash1_function(entite);
    if (table[hash] != NULL) {
        element* currElement = table[hash];
        while (currElement != NULL) {
            if (strcmp(currElement->name, entite) == 0) {
                return currElement->type;
            }    
        }
    }
    else
    {
        printf("Erreur: %s n'existe pas dans la table des symboles\n", entite);
    }
    return NULL;
}

void InsertValChaine(char entite[], char vall[])
{
    int hash = hash1_function(entite);
        int trouve = 0;
    if (table[hash] != NULL) {
        element* currElement = table[hash];
        while (currElement != NULL && trouve == 0) {
            if (strcmp(currElement->name, entite) == 0) {
                trouve = 1;
                strcpy(currElement->valCh, vall);
            }    
        }
    }
    else
    {
        printf("Erreur: %s n'existe pas dans la table des symboles\n", entite);
    }

}

char *GetValChaine(char entite[]){
    int hash = hash1_function(entite);
    if (table[hash] != NULL) {
        element* currElement = table[hash];
        while (currElement != NULL) {
            if (strcmp(currElement->name, entite) == 0) {
                return currElement->valCh;
            }    
        }
    }
    else
    {
        printf("Erreur: %s n'existe pas dans la table des symboles\n", entite);
    }
    return NULL;
}

int Declaration(char entite[]){
    int hash = hash1_function(entite);
    if (table[hash] != NULL) {
        element* currElement = table[hash];
        while (currElement != NULL) {
            if (strcmp(currElement->name, entite) == 0) {
                if (strcmp(currElement->type, " ") != 0) 
                {
                    return 1;
                }
                else
                {
                    return 0;
                }     
            }    
        }
    }
    else
    {
        return 0;
    }
    return 0;
}