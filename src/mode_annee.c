#include "mode_annee.h"


void initialisation_tab(Annee tab[20]){
    for(int i=0; i<20 ; i++){
            tab[i].annee = i+2005;
            tab[i].total_accident = 0;
            tab[i].total_indemne = 0;
            tab[i].total_mort = 0;
            tab[i].total_blesse_grave = 0;
            tab[i].total_blesse_leger = 0;
            }
}



void remplir_tableau(FILE* fichier, Annee tab[20]){
    int c;
    int indice;
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(4);
    }
    Ligne ligne;
    while((c = fgetc(fichier)) != '\n' && c != EOF){
    }
    while(fscanf(fichier,"%d;%d;%*d;%*d;%*d;%d;%*d;%*d;%*d", &(ligne.annee), &(ligne.id_collision), &(ligne.severite)) == 3){
        indice = ligne.annee-2005;
        if(ligne.annee < 2005 || ligne.annee > 2024){
            continue;
        }
        if(tab[indice].total_accident < ligne.id_collision){  //On cherche le max des idientifiants par année.
            tab[indice].total_accident = ligne.id_collision;
        }
        if(ligne.severite == 1){
            tab[indice].total_indemne++;
        }
        else if(ligne.severite == 2){
            tab[indice].total_mort++;
        }
        else if(ligne.severite == 3){
            tab[indice].total_blesse_grave++;
        }
        else if(ligne.severite == 4){
            tab[indice].total_blesse_leger++;
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


