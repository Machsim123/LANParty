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
    nume_echipa_buffer[strlen(nume_echipa_buffer)-2] = '\0';
    if(nume_echipa_buffer[strlen(nume_echipa_buffer)-1]==' ')
        nume_echipa_buffer[strlen(nume_echipa_buffer)-1] = '\0';
    (*head)->nume_echipa=malloc(strlen(nume_echipa_buffer)*sizeof(char)+1*sizeof(char));
    strcpy((*head)->nume_echipa, nume_echipa_buffer);
    // fprintf(fisier_output, "%s",(*head)->nume_echipa);
    for(j=0; j<(*head)->nr_membri; j++)
        {
            citire_membri(&(head_copy_membri), fisier_input, fisier_output,&((*head)->scor_echipa));
            // fprintf(fisier_output, "%d\n", (*head)->scor_echipa);
            addAtBeginning_Membri(&((*head)->head_membri), head_copy_membri);
        }
    (*head)->scor_echipa/= (*head)->nr_membri;
    //fprintf(fisier_output, "%f\n", (*head)->scor_echipa);
    (*head)->next_echipa = NULL;
    // fprintf(fisier_output, "\n");
}

void citire_membri(Membri **head_membri, FILE *fisier_input, FILE *fisier_output, double *scor_echipa)
{
    char nume_membru_buffer[lungime_max], prenume_membru_buffer[lungime_max];
    *head_membri=(Membri *)malloc(sizeof(Membri));
    fscanf(fisier_input, "%s %s %d", nume_membru_buffer, prenume_membru_buffer, &((*head_membri)->scor_membru));
    nume_membru_buffer[strlen(nume_membru_buffer)] = '\0';
    prenume_membru_buffer[strlen(prenume_membru_buffer)] = '\0';

    // DE BAGAT BUFFEREKE IN NUME
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
        fprintf(fisier_output, "%s\n", (*head)->nume_echipa);
        *head= (*head)->next_echipa;
}

int gasire_limita_echipe(int nr_echipe)
{
    double i=0.0;
    while( (pow(2.0,i)) < nr_echipe)
        i = i + 1.0;
    i--;
    i = nr_echipe - pow(2.0, i);
    return ((int) i);
}

void scoatere_echipe(Echipa **head, int nr, FILE *fisier_output)
{
    // fprintf(fisier_output, "SUNT IN FCT!\n");
    double mini= 40000;
    Echipa *headcopy= (*head);
    // fprintf(fisier_output, "%d %s", headcopy->nr_membri, headcopy->nume_echipa);
    while(nr!=0)
        {
            // headcopy= (*head);
            aflare_minim(headcopy, &mini, fisier_output);

            fprintf(stdout, "mini=%f\n", mini);
            
            scoatere_efectiva(&headcopy, mini, fisier_output, &nr);
            // fprintf(fisier_output, "\n\n\n\n\n\n IESIM DIN WHILE!\n");
            // nr--;
        }
}

void aflare_minim(Echipa *head, double *mini, FILE *fisier_output)
{
    *mini = head->scor_echipa;
    head=head->next_echipa;
    while(head->next_echipa!=NULL)
    {
        //printf("%s\n",head->nume_echipa);
        if(head->scor_echipa < (*mini))
             *mini = head->scor_echipa;
        head=head->next_echipa;
        fprintf(fisier_output, "mini=%f\n", *mini);
    }
    // fprintf(fisier_output, "\n\n");
}

void scoatere_efectiva(Echipa **head, double mini, FILE *fisier_output, int *nr)
{
    Echipa *headcopy= *head;
    if(headcopy->scor_echipa == mini)
        while(headcopy->scor_echipa == mini && headcopy!=NULL && (*nr)!=0)
            {
                scoatere_prima_echipa(&headcopy, fisier_output);
                *nr = (*nr) -1;
                fprintf(fisier_output, "SUNT IN WHILE!\n");
            }
    // else fprintf(fisier_output, "N-AM FOST IN WHILE!\n");
    if(headcopy->next_echipa==NULL)
    {
        // fprintf(fisier_output,"SUNT NULL :(\n");
        return;
    }
    // fprintf(fisier_output,"INTRARE!\n");
    while((headcopy->next_echipa)->next_echipa!= NULL && (*nr)!=0)
        {
            if((headcopy->next_echipa)->scor_echipa == mini) 
                {
                    fprintf(fisier_output,"mini= %f; SMECHERIE \n", mini);
                    scoatere_echipa_mijloc(&headcopy, fisier_output);
                    *nr = (*nr) -1;
                }
            else headcopy= headcopy->next_echipa;
            // *nr= 0;
        }
    fprintf(fisier_output, "GATA TREABA!\n");
    // if((headcopy->next_echipa)->scor_echipa == mini && (*nr)!=0) 
    //     {
    //         fprintf(fisier_output,"ULTIMU E NULL:(\n");
    //         scoatere_ultima_echipa(&headcopy, fisier_output);
    //         *nr = (*nr) -1;
    //     }

}

void scoatere_prima_echipa(Echipa **head, FILE *fisier_output)
{
    fprintf(fisier_output, "SUNT IN SCOTI PRIMA ECHIPA!\n");
    Echipa *headcopy= (*head);
    *head= (*head)->next_echipa;
    // free(headcopy);
}

void scoatere_echipa_mijloc(Echipa **head, FILE *fisier_output)
{
    fprintf(fisier_output, "SUNT IN SCOTI V ECHIPA!\n");
    fprintf(fisier_output, "%s %f\n\n", (*head)->next_echipa->nume_echipa, (*head)->next_echipa->scor_echipa);
    // Echipa *headcopy= (*head)->next_echipa;
    // (*head)->next_echipa = ((*head)->next_echipa)->next_echipa;
    // free(headcopy);
}

void scoatere_ultima_echipa(Echipa **head, FILE *fisier_output)
{
    fprintf(fisier_output, "SUNT IN SCOTI ULTIMA ECHIPA!\n");
    Echipa *headcopy= (*head)->next_echipa;
    (*head)->next_echipa = NULL;
    // free(headcopy);
}