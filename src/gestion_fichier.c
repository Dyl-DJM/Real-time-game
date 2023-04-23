/* Auteurs : Arij   TOUAMI - Dylan DE JESUS
 * Date creation : 24-04-2021
 * Date modification : 21-05-2021*/

#include "../include/gestion_fichier.h"
#include<stdlib.h>
#include<stdio.h>


void affiche_Niveau(Niveau* niveau){
    unsigned int i, j;

    /*On parcourt le tableau à double dimension constituant la map*/
    for(i = 0; i < (niveau->taille).y ;i++){

        fprintf(stdout, "%d     ", (niveau->taille).y - i - 1);   /*Echelle ordonnee*/

        for(j = 0; j < (niveau->taille).x ;j++){
            affiche_element(niveau->objets[i][j]);      /*affichage dans stdout de l'objet courant*/
        }
        fprintf(stdout, "\n");
    }

    fprintf(stdout, "\n      ");

    for(i = 0; i < (niveau->taille).x ;i++){
        fprintf(stdout, "%d", i);           /*Echelle abscisse*/
    }
    fprintf(stdout, "\n\n");
}


void affiche_element(Objet obj_courant){
    int type;

    type = obj_courant.type;
    Deplacement* dep;

    dep = (Deplacement *) obj_courant.donnee_suppl;

    switch(type){

        case VIDE:{
            fprintf(stdout, " ");
            break;
        }
        case PROJECTILE:{

            if(dep->direction == HAUT)
                fprintf(stdout, "ʌ");

            if(dep->direction == DROITE)
                fprintf(stdout, ">");

            if(dep->direction == GAUCHE)
                fprintf(stdout, "<");

            if(dep->direction == BAS)
                fprintf(stdout, "v");
            break;
        }
        case LANCEUR:{
            fprintf(stdout, "O");
            break;
        }
        case PERSONNAGE:{
            fprintf(stdout, "P");
            break;
        }
        case MUR:{
            fprintf(stdout, "#");
            break;
        }
        case DESTINATION:{
            fprintf(stdout, "D");
            break;
        }
        default :{
            fprintf(stdout, "?");   /*Si jamais erreur dans la compréhension d'un type d'objet non déclaré*/
        }

    }

}


Niveau* file_to_level(char * filename){
    unsigned int i, j, presence_perso;
    int ordonnee, abscisse;
    char caractere;

    FILE* fichier;
    Objet objet;
    Niveau * niveau;
    Coordonnees dimension;

    ordonnee = 0;
    abscisse = 0;
    presence_perso = 0;

    /*Ouverture du fichier en lecture*/
    printf("%s ", filename);
    fichier = fopen(filename,"r");


    if(fichier == NULL){
        printf("PROBLEM");
        return NULL;
    }


    /*On récupère les valeurs d ela première ligne*/
    fscanf(fichier, "%d %d ", &ordonnee, &abscisse);

    /*Ces valeurs seront les dimensions du niveau*/
    dimension.y = abs(ordonnee);
    dimension.x = abs(abscisse);

    /*Les dimensions ne sont pas édéquates*/
    if(dimension.y < 2 && dimension.x < 2){
        return NULL;
    }

    niveau = malloc_Niveau(dimension);

    for(i = 0; i < dimension.y; i++){

        for(j = 0; j < dimension.x; j++){

            caractere = fgetc(fichier);

            switch(caractere){
                case '.':{
                    objet.type = VIDE;
                    objet.donnee_suppl = NULL;
                    break;
                }
                case 'P':{
                    if(presence_perso == 0){        /*Aucun personnage n'a déjà été enregistré*/
                        objet.type = PERSONNAGE;
                        objet.donnee_suppl = NULL;
                        niveau->coo_perso.x = j;
                        niveau->coo_perso.y = i;
                        presence_perso++;
                    }
                    else{
                        objet.type = VIDE;          /*Il existe déjà un personnage à cet emplacement on remplace par du vide*/
                        objet.donnee_suppl = NULL;
                    }
                    break;
                }
                case 'D':{
                    objet.type = DESTINATION;
                    objet.donnee_suppl = NULL;
                    break;
                }
                case '#':{
                    objet.type = MUR;
                    objet.donnee_suppl = NULL;
                    break;
                }
                case 'O':{
                    objet.type = LANCEUR;
                    objet.donnee_suppl = NULL;
                    break;
                }
            }
            /*L'objet ajouté est sauvegardé dans le niveau*/
            niveau->objets[i][j] = objet;

        }
        /*Saut de ligne, on le passe */
        fgetc(fichier);
    }

    /*Pas de personnage dans fichier*/
    if(presence_perso == 0)
        return NULL;

    return niveau;
}

void usage(int entier){
    /*RAJOUTER CAS OÙ L'UTILISATEUR APPELLE --USAGE*/
    /*Traitement des différents cas selon le mode*/
    switch(entier){
        case 0:{
            fprintf(stdout, "Votre ligne de commande doit être de la forme : ./tempsreel --option=<parametre>\n\n");
            break;
        }
        case 1:{
            fprintf(stdout, "\nUsage 1: tempsreels --test=<int>\n\n         Lance le jeu en temps réel au niveau exemple <int>  (Exemple -> ./tempsreel --test=0)\n\n");
            break;
        }
        case 2:{
            fprintf(stdout, "\nUsage 2: tempsreels --fichier=<nom fichier>\n\n         Lance le jeu en temps réel au niveau exemple formé à l'aide d'un fichier texte existant et conforme au format suggéré  (Exemple -> ./tempsreel --fichier=Fichiers_Niveaux/Niveau2.txt)\n\n");
            break;
        }
        case 3:{
            fprintf(stdout, "Fichier non formaté :  \n          -> Vérifier l'existence du fichier\n          -> Vérifier la présence du personnage dans la map\n          -> Vérifiez que les dimensions ne valent pas un carré de dimension inférieur ou égale à 2\n\n");
            break;
        }
        case 4:{
            fprintf(stdout, "Le Niveau soliciter n'existe pas\n\n");
            break;
        }
        case 5:{
            fprintf(stdout, "Il n'existe que deux niveaux du terminal : Niveau 0 et Niveau 1\n\n");
            break;
        }
        case 6:{
            fprintf(stdout, "-WallBreaker- en fin de ligne de commande permet de jouer avec l'option de repoussage de murs\n\n");
            break;
        }
    }
}


void affiche_fin_partie(int type_fin){

    /*Traitement des différents cas*/
    switch(type_fin){
        case 0:{
            fprintf(stdout,"\n    -- NIVEAU RÉUSSI --\n\n");
            break;
        }
        case 1:{
            fprintf(stdout,"\n   -- PARTIE QUITTÉE --\n\n");
            break;
        }
        case 2:{
            fprintf(stdout,"\n   -- GAME OVER --\n\n");
            break;
        }
        case 3:{
            fprintf(stdout,"\n   -- FICHIER NON RECONNU --\n\n");
            break;
        }
        case 4:{
            fprintf(stdout,"\n   -- GAME OVER --\n\n");
            break;
        }
    }
}

