#ifndef MODE_ANNEE_H
#define MODE_ANNEE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


typedef struct Chainon{
    int id_collision;
    struct Chainon* suivant;
}Chainon;

typedef struct{
    int annee;
    int total_accident;
    int total_indemne;
    int total_mort;
    int total_blesse_grave;
    int total_blesse_leger;
    Chainon* liste_id;
}Annee;

typedef struct Ligne{
    int annee;
    int id_collision;
    int severite;
}Ligne;

Chainon* ajouter_id(Chainon* liste, int nombre);
int existe(Chainon* liste, int nombre);
void initialisation_tab(Annee tab[20]);
void remplir_tableau(FILE* fichier, Annee tab[20]);
int choix_annee();
void afficher_stats(Annee tab[20], int annee);
void vide_buffer();
#endif