#ifndef AGE_DATA
#define AGE_DATA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct Chainon{
    int age;

    int homme_conducteur;
    int homme_passager;
    int homme_pieton;

    int femme_conducteur;
    int femme_passager;
    int femme_pieton;

    struct Chainon* suivant;
}Chainon;

typedef struct Ligne{
    int annee;
    int birth;
    int user_type;
    int gender;
}Ligne;

#endif