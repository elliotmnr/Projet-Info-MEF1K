#include "mode_annee.h"


void vide_buffer(){
    while(getchar()!='\n'){
    }
}

int main(int argc,char *argv[]){
    if(argc != 3){
        printf("Utilisation : %d fichier\n", argc);
        return 1;
    }
    FILE* fichier = NULL;
    fichier =  fopen(argv[2],"r");
    if(fichier == NULL){
        printf("Erreur d'ouverture du fichier\n");
        exit(1);
    }

    //MODE YEAR DATA

    if(strcmp(argv[1],"MODE_YEAR") == 0){
        int annee ;
        annee = choix_annee();
        Annee tab[20];
        initialisation_tab(tab);
        remplir_tableau(fichier, tab);
        afficher_stats(tab,annee);
    }

    rewind(fichier);
    

    fclose(fichier);
    return 0;
}