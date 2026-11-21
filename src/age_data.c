#include "age_data.h"

Chainon* ajouter_age(Chainon* liste, int age) {
    Chainon* temp = liste;
    Chainon* precedent = NULL;
    while (temp != NULL && temp->age < age) {
        precedent = temp;
        temp = temp->suivant;
    }
    Chainon* nouveau = malloc(sizeof(Chainon));
    if (nouveau == NULL) {
        printf("Erreur allocation Chainon MODE_AGE\n");
        exit(4);
    }
    nouveau->age = age;
    nouveau->homme_conducteur = 0;
    nouveau->homme_passager = 0;
    nouveau->homme_pieton = 0;
    nouveau->femme_conducteur = 0;
    nouveau->femme_passager = 0;
    nouveau->femme_pieton = 0;
    nouveau->suivant = temp;
    if (precedent == NULL) {
        return nouveau;
    }
    precedent->suivant = nouveau;
    return liste;
}

int existe(Chainon* liste, int nombre) {
    if(liste == NULL){
        return 0;
    }
    Chainon* temp = liste;
    while(temp != NULL && temp->age != nombre){
        temp = temp->suivant;
    }
    if(temp !=NULL){
        return 1;
    }
    return 0;
}


void mettre_a_jour(Chainon* liste, int gender, int user_type, int age) {
    if (liste == NULL) {
        printf("Erreur dans mettre_a_jour AGE_DATA\n");
        exit(5);
    }
    Chainon* temp = liste;
    while (temp != NULL && temp->age < age) {
        temp = temp->suivant;
    }
    if (temp == NULL || temp->age != age) {
        printf("Age introuvable\n");
        exit(6);
    }
    if (gender == 1) {
        if (user_type == 1) {
            temp->homme_conducteur++;
        }
        else if (user_type == 2) {
            temp->homme_passager++;
        }
        else if (user_type == 3) {
            temp->homme_pieton++;
        }
    }
    else if (gender == 2) {
        if (user_type == 1) {
            temp->femme_conducteur++;
        }
        else if (user_type == 2) {
            temp->femme_passager++;
        }
        else if (user_type == 3) {
            temp->femme_pieton++;
        }
    }
}

Chainon* remplir_liste(FILE* fichier, Chainon* liste){
    int c;
    int indice;
    Ligne ligne;
    while((c = fgetc(fichier)) != '\n' && c != EOF){
    }
    while(fscanf(fichier,"%d;%*d;%*d;%*d;%d;%*d;%d;%d;%*d", &(ligne.annee), &(ligne.user_type), &(ligne.gender), &(ligne.birth)) == 4){
        int age = ligne.annee - ligne.birth;
        if(existe(liste, age) == 0){
            liste = ajouter_age(liste,age);
        }
        mettre_a_jour(liste,ligne.gender,ligne.user_type,age);
    }
    return liste;
}