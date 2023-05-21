#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define lungime_max 64

typedef struct Membri
{
    char *nume_membru, *prenume_membru;
    int scor_membru;
    struct Membri *next_membru;
}Membri;

typedef struct Echipa
{
    int nr_membri;
    char *nume_echipa;
    int scor_echipa;
    struct Membri *head_membri;
    struct Echipa *next_echipa;
}Echipa;

void verif_citire(FILE *);

void citire_echipa(Echipa **, FILE *, FILE *);

void citire_membri(Membri **, FILE *, FILE *, int *);

void addAtBeginning_Membri(Membri **, Membri *);

void addAtBeginning_Echipa(Echipa **, Echipa *);

void afisare_nume_echipe(Echipa **, FILE *);

int gasire_limita_echipe(int );

void scoatere_echipe(Echipa **, int , FILE *);

void aflare_minim(Echipa *, int *, FILE *);