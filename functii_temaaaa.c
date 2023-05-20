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
            citire_membri(&(head_copy_membri), fisier_input, fisier_output,&((*head)->scor_echipa));
            // fprintf(fisier_output, "%d\n", (*head)->scor_echipa);
            addAtBeginning_Membri(&((*head)->head_membri), head_copy_membri);
        }
    (*head)->next_echipa = NULL;
    // fprintf(fisier_output, "\n");
}

void citire_membri(Membri **head_membri, FILE *fisier_input, FILE *fisier_output, int *scor_echipa)
{
    char nume_membru_buffer[lungime_max], prenume_membru_buffer[lungime_max];
    *head_membri=(Membri *)malloc(sizeof(Membri));
    fscanf(fisier_input, "%s %s %d", nume_membru_buffer, prenume_membru_buffer, &((*head_membri)->scor_membru));
    nume_membru_buffer[strlen(nume_membru_buffer)] = '\0';
    prenume_membru_buffer[strlen(prenume_membru_buffer)] = '\0';
    // fprintf(fisier_output, "%s %s %d\n", nume_membru_buffer, prenume_membru_buffer, (*head_membri)->scor_membru);
    (*head_membri)->next_membru = NULL;
    *scor_echipa += (*head_membri)->scor_membru;

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

int gasire_limita_echipe(int nr_echipe)
{
    double i=0.0;
    while( (pow(2.0,i)) < nr_echipe)
        i = i + 1.0;
    return ((int) i-1);
}

void eliminare_echipe(Echipa **head, int nr, FILE *fisier_output)
{
    int mini= 40000;
    Echipa **headcopy=**head;
    while(nr!= 0)
        {
            mini= aflare_minim(*headcopy, fisier_output);
            eliminare_partial(&headcopy, &nr, mini, fisier_output);
            nr=0;
        }
}

int aflare_minim(Echipa *head, FILE *fisier_output)
{
    int mini= head->scor_echipa, j=0;
    head= head->next_echipa;
    fprintf(fisier_output, "%d\n", mini);
    while(head->next_echipa!=NULL)
    {
        if(head->scor_echipa < mini) mini= head->scor_echipa;
        fprintf(fisier_output, "%d\n", mini);
        head= head->next_echipa;
        fprintf(fisier_output, "%d\n", j++);
        fprintf(fisier_output, "%d\n", mini);
    }
    fprintf(fisier_output, "%d\n", mini);
    return mini;
}

void eliminare_partial(Echipa **head, int *nr, int mini, FILE *fisier_output)
{
    Echipa *headcopy= *head;
    if(headcopy->scor_echipa == mini)
     eliminare_prima_structura(head);
    while(headcopy->next_echipa!= NULL)
        if((headcopy->next_echipa)->scor_echipa == mini)
            eliminare_structura_oarecare(&headcopy);
                else headcopy = headcopy->next_echipa;
}

void eliminare_prima_structura(Echipa **head)
{
    Echipa *headcopy = *head;
    *head=(*head)->next_echipa;
    free(headcopy);
}

void eliminare_structura_oarecare(Echipa **head)
{
    Echipa *headcopy = *head;
    (*head)->next_echipa= ((*head)->next_echipa)->next_echipa;
    free(headcopy->next_echipa);
}

// void afisare_echipe(Echipa **head, FILE *fisier_output)
// {
//     fprintf("%d %s%d\n", (*head)->nr_membri, (*head)->nume_echipa, (*head)->scor_echipa);
//     afisare_membri((*head)->head_membri, fisier_output);
//     fprintf("\n\n");
// }

// void afisare_membri(Membri *head, FILE *fisier_output)
// {
//     fprintf("%s %s %d",head->nume_membru, head->prenume_membru, head->scor_membru);
// }