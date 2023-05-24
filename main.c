#include "functii_temaaaa.h"

int main(int argc, char *argv[])
{
    FILE *c, *d, *r;
    int nr_echipe, i, j, n;
    Echipa *head, *headcopy;
    c = fopen(argv[1], "r+t");
    d = fopen(argv[2], "r+t");
    r = fopen(argv[3], "w+t");
    
    verif_citire(c);
    verif_citire(d);
    verif_citire(r);

    int cerinte[5];
    for (i = 0; i < 5; i++)
    {
        fscanf(c, "%d", &(cerinte[i]));
    }
    
    fscanf(d, "%d\n", &nr_echipe);
    if (cerinte[0] == 1)
    {

        for (i = 0; i < nr_echipe; i++)
        {
            citire_echipa(&headcopy, d);
            addAtBeginning_Echipa(&head, headcopy);
        }
    }
    if (cerinte[1] == 1)
    {
       
        // headcopy= head;
        
        // n = gasire_limita_echipe(nr_echipe);

        // scoatere_echipe(&head, n);
        // nr_echipe-= n;
    }

    headcopy= head;

    for (j = 0; j < nr_echipe; j++)
        afisare_nume_echipe(&headcopy, r);
    if (cerinte[2] == 1)
    {   
        int k=1;
        headcopy= head;
        Queue *q;
        Meci *meci;
        Echipa *Echipa_unos, *Echipa_duos;
        Echipa *Winner;
        Winner=(Echipa*)malloc(sizeof(Echipa));
        Stiva_invingatori *stiva_invingatoriTop= NULL;
        Stiva_pierzatori *stiva_pierzatoriTop= NULL;
        meci=(Meci *)malloc(sizeof(Meci));
        q= createQueue();
        printf("%d\n",nr_echipe);
        for(j=0; j < (nr_echipe/2); j++)
        {
            enQueue(q, headcopy, headcopy->next_echipa);
            headcopy= (headcopy->next_echipa)->next_echipa;
        }
        fprintf(r, "\n--- ROUND NO: %d\n", k);
        for(j=0; j < (nr_echipe/2); j++)
        {
            meci= deQueue(q);
            fprintf(r, "%-33s-%33s\n", (meci->Echipa_1)->nume_echipa, (meci->Echipa_2)->nume_echipa);
            if(((meci->Echipa_1)->scor_echipa == (meci->Echipa_2)->scor_echipa) || ((meci->Echipa_1)->scor_echipa > (meci->Echipa_2)->scor_echipa))
            {
                push_invingatori(&stiva_invingatoriTop, meci->Echipa_1);
                push_pierzatori(&stiva_pierzatoriTop, meci->Echipa_2);
            }
            else 
            {
                push_invingatori(&stiva_invingatoriTop, meci->Echipa_2);
                push_pierzatori(&stiva_pierzatoriTop, meci->Echipa_1);
            }
        }
        nr_echipe/= 2;
        Stergere_Stiva_pierzatori(&stiva_pierzatoriTop);
        while(nr_echipe!= 1)
        {
            fprintf(r, "\nWINNERS OF ROUND NO:%d\n", k);
            for(j=0; j<(nr_echipe/2); j++)
            {
                Echipa_unos= pop_invingatori(&stiva_invingatoriTop);
                Echipa_duos= pop_invingatori(&stiva_invingatoriTop);
                enQueue(q, Echipa_unos, Echipa_duos);
                fprintf(r, "%-34s-  %.2f\n", Echipa_unos->nume_echipa, Echipa_unos->scor_echipa);
                fprintf(r, "%-34s-  %.2f\n", Echipa_duos->nume_echipa, Echipa_duos->scor_echipa);
            }
            k++;
            fprintf(r, "\n--- ROUND NO: %d\n", k);
            for(j=0; j < (nr_echipe/2); j++)
            {
                meci= deQueue(q);
                fprintf(r, "%-33s-%33s\n", (meci->Echipa_1)->nume_echipa, (meci->Echipa_2)->nume_echipa);
                if(((meci->Echipa_1)->scor_echipa == (meci->Echipa_2)->scor_echipa) || ((meci->Echipa_1)->scor_echipa > (meci->Echipa_2)->scor_echipa))
                {
                    push_invingatori(&stiva_invingatoriTop, meci->Echipa_1);
                    push_pierzatori(&stiva_pierzatoriTop, meci->Echipa_2);
                }
                else 
                {
                    push_invingatori(&stiva_invingatoriTop, meci->Echipa_2);
                    push_pierzatori(&stiva_pierzatoriTop, meci->Echipa_1);
                }
            }
            nr_echipe/= 2;
            Stergere_Stiva_pierzatori(&stiva_pierzatoriTop);
            k++;
        }
        Winner= pop_invingatori(&stiva_invingatoriTop);
        fprintf(r, "\nWINNERS OF ROUND NO:%d\n", k);
        fprintf(r, "%-34s-  %.2f\n", Winner->nume_echipa, Winner->scor_echipa);
        
        
    }
    if (cerinte[3] == 1)
    {
        ;
    }
    if (cerinte[4] == 1)
    {
        ;
    }
    headcopy = head;

    
    fclose(c);
    fclose(d);
    fclose(r);

    return 0;
}