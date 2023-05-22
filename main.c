#include "functii_temaaaa.h"

int main(int argc, char *argv[])
{
    FILE *c, *d, *r;
    int nr_echipe, i, j, n;
    Echipa *head, *headcopy;
    // head = headcopy;
    c = fopen(argv[1], "r+t");
    d = fopen(argv[2], "r+t");
    r = fopen(argv[3], "w+t");
    int cerinte[5];
    for (i = 0; i < 5; i++)
    {
        fscanf(c, "%d", &(cerinte[i]));
    }
    //verif_citire(c);
    verif_citire(d);
    verif_citire(r);
    // printf("%d\n",nr_echipe);
        fscanf(d, "%d\n", &nr_echipe);
    if (cerinte[0] == 1)
    {

        for (i = 0; i < nr_echipe; i++)
        {
            citire_echipa(&headcopy, d, r);
            addAtBeginning_Echipa(&head, headcopy);
        }
        // headcopy = head;
        // while(headcopy->next_echipa->next_echipa!=NULL)
        //     headcopy=headcopy->next_echipa;
        //     if(headcopy->next_echipa == NULL)printf("PENIS");
        // // free(headcopy->next_echipa);
        // headcopy->next_echipa = NULL;
        // printf("\n\nrrrr %s \n\n\n",headcopy->nume_echipa);
    }
    if (cerinte[1] == 1)
    {
       
        headcopy= head;
        
        n = gasire_limita_echipe(nr_echipe);
        //fprintf(stdout, "%d", n);
        scoatere_echipe(&head, n, r);
        nr_echipe-= n;
        // printf("IESIT EFECTIV\n");
    }
    // headcopy= head;
    for (j = 0; j < nr_echipe; j++)
        afisare_nume_echipe(&headcopy, r);
        
    if (cerinte[2] == 1)
    {
        ;
    }
    if (cerinte[3] == 1)
    {
        ;
    }
    if (cerinte[4] == 1)
    {
        ;
    }
    // fprintf(r, "%s", head->nume_echipa);
    // fprintf(r, "%s", (head->next_echipa)->nume_echipa);
    headcopy = head;

    
    fclose(c);
    fclose(d);
    fclose(r);

    return 0;
}