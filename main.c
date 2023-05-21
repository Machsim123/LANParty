#include "functii_temaaaa.h"

int main()
{
    FILE *d, *r;
    int nr_echipe, i, j, n;
    Echipa *head, *headcopy;
    head= headcopy;
    d=fopen("input.txt","r+t");
    r=fopen("output.txt","w+t");
    // verif_citire(d);
    // verif_citire(r);
    fscanf(d,"%d\n",&nr_echipe);
    // printf("%d\n",nr_echipe);
    for(i=0; i<nr_echipe; i++)
        {
            citire_echipa(&headcopy, d, r);
            addAtBeginning_Echipa(&head, headcopy);
        }
    // fprintf(r, "%s", head->nume_echipa);
    // fprintf(r, "%s", (head->next_echipa)->nume_echipa);
    headcopy=head;
    // for(j=0; j<nr_echipe; j++)
    //     afisare_nume_echipe(&headcopy, r);
    n = gasire_limita_echipe(nr_echipe);
    // fprintf(r, "%d", n);
    scoatere_echipe(&head, n, r);


    return 0;
}