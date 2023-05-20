#include "functii_temaaaa.h"

void verif_citire(FILE *fis)
{
    if (fis == NULL)
        printf("Fisierul nu a putut fi deschis! \n");
    else
        printf("Fisierul a fost deschis cu succes! \n");
}

void citire_echipa(Echipa **head, FILE *fisier_input, FILE *fisier_output)
{
    char nume_echipa_buffer[lungime_max];
    int j;
    *head=(Echipa *) malloc(sizeof(Echipa));
    Membri *head_copy_membri= (*head)->head_membri;
    fscanf(fisier_input, "%d ",&((*head)->nr_membri));
    fgets(nume_echipa_buffer, lungime_max - 1, fisier_input);
    nume_echipa_buffer[strlen(nume_echipa_buffer)] = '\0';
    (*head)->nume_echipa=(char *)malloc(strlen(nume_echipa_buffer)*sizeof(char));
    strcpy((*head)->nume_echipa, nume_echipa_buffer);
    // fprintf(fisier_output, "%s",(*head)->nume_echipa);
    for(j=0; j<(*head)->nr_membri; j++)
        {
            citire_membri(&(head_copy_membri), fisier_input, fisier_output);
            addAtBeginning_Membri(&((*head)->head_membri), head_copy_membri);
        }
    (*head)->next_echipa = NULL;
    // fprintf(fisier_output, "\n");
}

void citire_membri(Membri **head_membri, FILE *fisier_input, FILE *fisier_output)
{
    char nume_membru_buffer[lungime_max], prenume_membru_buffer[lungime_max];
    *head_membri=(Membri *)malloc(sizeof(Membri));
    fscanf(fisier_input, "%s %s %d", nume_membru_buffer, prenume_membru_buffer, &((*head_membri)->scor_membru));
    nume_membru_buffer[strlen(nume_membru_buffer)] = '\0';
    prenume_membru_buffer[strlen(prenume_membru_buffer)] = '\0';
    // fprintf(fisier_output, "%s %s %d\n", nume_membru_buffer, prenume_membru_buffer, (*head_membri)->scor_membru);
    (*head_membri)->next_membru = NULL;

}

void addAtBeginning_Membri(Membri **head, Membri *newNode)
{
    newNode->next_membru = *head;
    *head = newNode;
}

void addAtBeginning_Echipa(Echipa **head, Echipa *newNode)
{
    newNode->next_echipa = *head;
    *head = newNode;
}

void afisare_nume_echipe(Echipa **head, FILE *fisier_output)
{
        fprintf(fisier_output, "%s", (*head)->nume_echipa);
        *head= (*head)->next_echipa;
}