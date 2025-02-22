#include "functii_tema.h"

void verif_citire(FILE *fis)
{
    if (fis == NULL)
        printf("Fisierul nu a putut fi deschis! \n");
    //else
        // printf("Fisierul a fost deschis cu succes! \n");
}

void citire_echipa(Echipa **head, FILE *fisier_input)
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
    (*head)->nume_echipa=(char *)malloc(strlen(nume_echipa_buffer)*sizeof(char)+1*sizeof(char));
    strcpy((*head)->nume_echipa, nume_echipa_buffer);

    for(j=0; j<(*head)->nr_membri; j++)
        {
            citire_membri(&(head_copy_membri), fisier_input, &((*head)->scor_echipa));
            addAtBeginning_Membri(&((*head)->head_membri), head_copy_membri);
        }

    (*head)->scor_echipa/= (*head)->nr_membri;
    (*head)->next_echipa = NULL;

    // free(head_copy_membri);
}

void citire_membri(Membri **head_membri, FILE *fisier_input, double *scor_echipa)
{
    char nume_membru_buffer[lungime_max], prenume_membru_buffer[lungime_max];
    *head_membri=(Membri *)malloc(sizeof(Membri));

    fscanf(fisier_input, "%s %s %d", nume_membru_buffer, prenume_membru_buffer, &((*head_membri)->scor_membru));

    nume_membru_buffer[strlen(nume_membru_buffer)] = '\0';
    prenume_membru_buffer[strlen(prenume_membru_buffer)] = '\0';
    (*head_membri)->nume_membru=(char *)malloc(strlen(nume_membru_buffer)*sizeof(char)+1*sizeof(char));
    (*head_membri)->prenume_membru=(char *)malloc(strlen(prenume_membru_buffer)*sizeof(char)+1*sizeof(char));
    strcpy((*head_membri)->nume_membru, nume_membru_buffer);
    strcpy((*head_membri)->prenume_membru, prenume_membru_buffer);

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

void scoatere_echipe(Echipa **head, int nr)
{
    double mini= 40000;
    Echipa *headcopy= (Echipa*) malloc(sizeof(Echipa));
    headcopy= (*head);
    while(nr!=0)
        {
            headcopy= (*head);
            aflare_minim(headcopy, &mini);

            scoatere_echipa(head, mini);

            nr--;
            // headcopy= (*head);
        }
    // *head= headcopy;
}

void aflare_minim(Echipa *head, double *mini)
{
    *mini = head->scor_echipa;
    head=head->next_echipa;
    while(head->next_echipa!=NULL)
    {
        if(head->scor_echipa < (*mini))
             *mini = head->scor_echipa;
        head=head->next_echipa;
    }
}

void scoatere_echipa(Echipa **head, double mini)
{
    Echipa *headcopy= (*head), *head_free;

    if((*head)->scor_echipa == mini)
        {   
            *head= (*head)->next_echipa;
            return ;
        }
    while(headcopy->next_echipa->scor_echipa!= mini && headcopy->next_echipa->next_echipa!= NULL)  
        headcopy= headcopy->next_echipa;
    if(headcopy->next_echipa->scor_echipa== mini)
        {   
            head_free=headcopy->next_echipa;
            headcopy->next_echipa= headcopy->next_echipa->next_echipa;
        }
    
    free(head_free);
}

Queue* createQueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL)
        return NULL;

    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enQueue(Queue *q, Echipa *Echipa_uno, Echipa *Echipa_dos)
{
    // printf("SUNT IN enQUEUE\n");
	Meci* newNode=(Meci*)malloc(sizeof(Meci));
	newNode->Echipa_1= (Echipa *)malloc(sizeof(Echipa));
    newNode->Echipa_1= Echipa_uno;
    newNode->Echipa_2= (Echipa *)malloc(sizeof(Echipa));
    newNode->Echipa_2= Echipa_dos;
	newNode->next_meci=NULL;
	if (q->rear==NULL) q->rear=newNode;
	else
        {
		    (q->rear)->next_meci=newNode;
		    (q->rear)=newNode;
	    }
	if (q->front==NULL) q->front=q->rear; 
}
 
Meci *deQueue(Queue *q) 
{  
    Meci *aux;
	
	aux=q->front;
	q->front=(q->front)->next_meci;
	return aux;
}

int isEmpty_cozi(Queue*q)
{
	return (q->front==NULL);
}

void push_invingatori(Stiva_invingatori **top, Echipa *invingator)
{
    Stiva_invingatori *newNode=(Stiva_invingatori*)malloc(sizeof(Stiva_invingatori));
    newNode->Invingator=  (Echipa*)malloc(sizeof(Echipa));
    newNode->Invingator= invingator;
    newNode->next_invingator= *top;
    *top= newNode;
}

void push_pierzatori(Stiva_pierzatori **top, Echipa *pierzator)
{
    Stiva_pierzatori *newNode=(Stiva_pierzatori*)malloc(sizeof(Stiva_pierzatori));
    newNode->Pierzator= (Echipa*)malloc(sizeof(Echipa));
    newNode->Pierzator= pierzator;
    newNode->next_pierzator= *top;
    *top= newNode;
}

Echipa *pop_invingatori(Stiva_invingatori **top)
{
    Stiva_invingatori *temp= (*top);
    Echipa *aux= temp->Invingator;
    *top= (*top)->next_invingator;
    free(temp);
    return aux;
}

Echipa *pop_pierzatori(Stiva_pierzatori **top)
{
    Stiva_pierzatori *temp= (*top);
    Echipa *aux= temp->Pierzator;
    *top= (*top)->next_pierzator;
    free(temp);
    return aux;
}

void Stergere_Stiva_pierzatori(Stiva_pierzatori **top)
{
    Stiva_pierzatori *temp;
    while((*top)!=NULL)
    {
        temp=(*top);
        *top= (*top)->next_pierzator;
        free(temp);
    }
}

void marire_punctaj_echipa(Echipa **head)
{
    Echipa *headcopy= (*head);
    int i;
    for(i=0; i< (headcopy->nr_membri) ; i++)
        marire_punctaj_membru(&(headcopy->head_membri));
    headcopy->scor_echipa+= 1;
    // *head= headcopy;
}

void marire_punctaj_membru(Membri **head)
{
    Membri *headcopy= (*head);
    headcopy->scor_membru+= 1;
    headcopy= headcopy->next_membru;
    // *head= headcopy;
}
