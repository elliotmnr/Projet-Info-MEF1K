#include "mode_annee.h"


void vide_buffer(){
    while(getchar()!='\n'){
    }
}

int main(int argc,char *argv[]){
    if(argc != 3){
        printf("Utilisation : %s <fichier>\n", argv[0]);
        return 1;
    }

    FILE* fichier = NULL;
    fichier =  fopen(argv[2],"r");
    if(fichier == NULL){
        printf("Erreur d'ouverture du fichier\n");
        exit(1);
    }

    //MODE YEAR DATA

    if(strcmp(argv[1],"YEAR_DATA") == 0){ //J'ai remplacé "MODE YEAR" par "YEAR_DATA" (Elliot)
        int annee ;
        annee = choix_annee();
        Annee tab[20];
        initialisation_tab(tab);
        remplir_tableau(fichier, tab);
        afficher_stats(tab,annee);
    }

    // MODE AGE DATA
    /*
    else if (strcmp(argv[1], "AGE_DATA") == 0) {
        Chainon* liste = NULL;
        liste = remplir_liste(fichier, liste);
    }
    
    
    else {
        printf("Mode inconnu : %s\n", argv[1]);
        fclose(fichier);
        return 0;
    }
    */
    fclose(fichier);
    return 0;
}
