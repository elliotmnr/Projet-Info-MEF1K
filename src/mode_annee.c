#include "mode_annee.h"

Chainon* ajouter_id(Chainon* liste, int nombre){
    if(liste == NULL){
        Chainon* nouveau = malloc(sizeof(Chainon));
        if(nouveau == NULL) {
            printf("Erreur allocation Chainon MODE_YEAR\n");
            exit(4);
        }
        nouveau->suivant = NULL;
        nouveau->id_collision = nombre;
        return nouveau;
    }
    Chainon* nouveau = malloc(sizeof(Chainon));
    if(nouveau == NULL) {
        printf("Erreur allocation Chainon MODE_YEAR\n");
        exit(4);
    }
    nouveau->suivant = liste;
    nouveau->id_collision = nombre;
    return nouveau;
}

int existe(Chainon* liste, int nombre) {
    if(liste == NULL){
        return 0;
    }
    Chainon* temp = liste;
    while(temp != NULL && temp->id_collision != nombre){
        temp = temp->suivant;
    }
    if(temp !=NULL){
        return 1;
    }
    return 0;
}


void initialisation_tab(Annee tab[20]){
    for(int i=0; i<20 ; i++){
            tab[i].annee = i+2005;
            tab[i].total_accident = 0;
            tab[i].total_indemne = 0;
            tab[i].total_mort = 0;
            tab[i].total_blesse_grave = 0;
            tab[i].total_blesse_leger = 0;
            for(int j = 0; j<1000; j++){
                tab[i].liste_id[j] = NULL;
            }
        }
}


void remplir_tableau(FILE* fichier, Annee tab[20]){
    int c;
    int indice;
    Ligne ligne;
    while((c = fgetc(fichier)) != '\n' && c != EOF){
    }
    while(fscanf(fichier,"%d;%d;%*d;%*d;%*d;%d;%*d;%*d;%*d", &(ligne.annee), &(ligne.id_collision), &(ligne.severite)) == 3){
        if(ligne.annee < 2005 || ligne.annee > 2024){
            continue;
        }
        indice = ligne.id_collision % 1000;
        if(indice < 0){
            indice += 1000;
        }
        if(existe(tab[ligne.annee-2005].liste_id[indice], ligne.id_collision)==0){
            tab[ligne.annee-2005].liste_id[indice] = ajouter_id(tab[ligne.annee-2005].liste_id[indice], ligne.id_collision);
            tab[ligne.annee-2005].total_accident++;
        }
        if(ligne.severite == 1){
            tab[ligne.annee-2005].total_indemne++;
        }
        else if(ligne.severite == 2){
            tab[ligne.annee-2005].total_mort++;
        }
        else if(ligne.severite == 3){
            tab[ligne.annee-2005].total_blesse_grave++;
        }
        else if(ligne.severite == 4){
            tab[ligne.annee-2005].total_blesse_leger++;
        }
    }
}

int choix_annee(){
    int annee = 0;
    int verif;
    do {
        printf("Choisissez une annee (2005-2024) : ");
        verif = scanf("%d", &annee);
        vide_buffer();
        if(verif != 1 || annee < 2005 || annee > 2024){
            printf("Annee invalide.\n");
        }
    } while(verif != 1 || annee < 2005 || annee > 2024);
    return annee;
}

void afficher_stats(Annee tab[20], int annee){
    int indice = annee - 2005;
    int accidents = tab[indice].total_accident;
    int indemnes = tab[indice].total_indemne;
    int morts = tab[indice].total_mort;
    int grave = tab[indice].total_blesse_grave;
    int leger = tab[indice].total_blesse_leger;
    printf("En %d, Il y a eu :\n- %d accidents \n- %d indemnes \n- %d tues \n- %d blesses graves \n- %d blesses leger\n \n", annee , accidents , indemnes, morts, grave , leger);
}


