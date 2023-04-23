/* Auteurs : Arij   TOUAMI - Dylan DE JESUS
 * Date creation : 24-04-2021
 * Date modification : 21-05-2021*/

#include "../include/Niveau.h"
#include <stdlib.h>


Niveau* niveauN(int niveau){

    Niveau * premier_niveau;
    Coordonnees initial;
    Objet ** objets;

    /*On défini un niveau de dimension 10, 5*/
    initial.x = 10;
    initial.y = 5;

    /*Allocation du tas*/
    premier_niveau = malloc_Niveau(initial);

    /*On met dans le tableau pour envoyer dans la fonction*/
    objets = premier_niveau->objets;

    /*Selon le niveau choisi la map*/
    switch(niveau){
        case 1 : {
            Map_Niveau_1(premier_niveau->taille, objets);
        }
        /*Posibilités de mettre d'autres map ici*/
    }

    premier_niveau->objets = objets;

    return premier_niveau;
}


Niveau* niveau0(){

    Niveau * premier_niveau;
    Coordonnees initial;
    Objet ** objets;

    /*Dimensions par défaut*/
    initial.x = 10;
    initial.y = 5;

    /*Allocation du niveau*/
    premier_niveau = malloc_Niveau(initial);

    objets = premier_niveau->objets;
    Map_Niveau_0(premier_niveau->taille, objets);   /*On modifie le tableau d'objets*/

    premier_niveau->objets = objets;

    return premier_niveau;
}


Niveau * malloc_Niveau(Coordonnees taille){
    unsigned int i;
    Coordonnees position;
    Objet ** objets = NULL;
    Niveau * tmp;

    position.x = 0;
    position.y = taille.y - 1;

    /*Allocation du tableau à double dimension*/
    objets = (Objet**) malloc(taille.y * sizeof(Objet));

    if(objets == NULL){
        return NULL;
    }

    for(i = 0;  i < taille.y ; i++){

        objets[i] = (Objet *) malloc(taille.x * sizeof(Objet));

        if(objets == NULL){
            return NULL;
        }
    }

    /*Allocation de la strcuture*/
    tmp = (Niveau *) malloc(sizeof(Niveau));

    if(NULL == tmp){
        return tmp;
    }

    tmp->taille = taille;       /*La taille du niveau est donnée en paramètre*/
    tmp->objets = objets;       /**/
    tmp->coo_perso = position;  /*On commence en (0,0)*/
    tmp->allure_perso = 250;    /*Vitesse 250 milisecondes par case*/
    tmp->depl_perso_autorise = true;

    return tmp;
}


void free_Niveau(Niveau *niv){
    /*int i;*/

    free(niv->objets);
    /*
    for(i = 0; (niv->objets + i) != NULL ;i++){
        free(niv->objets + i);
    }*/

    free(niv);
}


void Map_Niveau_0(Coordonnees taille, Objet ** tab){
    unsigned int i,j;
    Objet courant;
    Generation gen_lanceur;

    initialise_generation(&gen_lanceur);

    /*On parcourt les différentes lignes pour y remlir les objets correspondants*/
    for(i = 0; i < taille.y ; i++){

        for(j = 0; j < taille.x ;j++){

            if(i == 0){
                if(j == 0){
                    courant.type = LANCEUR;
                    courant.donnee_suppl = &gen_lanceur;
                    tab[i][j] = courant;
                }
                else{
                    courant.type = VIDE;
                    courant.donnee_suppl = NULL;
                    tab[i][j] = courant;
                }
            }

            if(i == 1){
                if(j == 7 || j == 9){
                    courant.type = VIDE;
                    courant.donnee_suppl = NULL;
                    tab[i][j] = courant;
                }
                else{
                    courant.type = MUR;
                    courant.donnee_suppl = NULL;
                    tab[i][j] = courant;
                }
            }

            if(i == 2){
                if(j == 8){
                    courant.type = MUR;
                    courant.donnee_suppl = NULL;
                    tab[i][j] = courant;
                }
                else{
                    courant.type = VIDE;
                    courant.donnee_suppl = NULL;
                    tab[i][j] = courant;
                }
            }

            if(i == 3){
                if(j == 6){
                    courant.type = LANCEUR;
                    courant.donnee_suppl = &gen_lanceur;
                    tab[i][j] = courant;
                }

                if(j == 8){
                    courant.type = MUR;
                    courant.donnee_suppl = NULL;
                    tab[i][j] = courant;
                }

                if(j != 6 && j != 8){
                    courant.type = VIDE;
                    courant.donnee_suppl = NULL;
                    tab[i][j] = courant;
                }
            }

            if(i == 4){
                if(j == 0){
                    courant.type = PERSONNAGE;
                    courant.donnee_suppl = NULL;
                    tab[i][j] = courant;
                }
                if(j == 8){
                    courant.type = MUR;
                    courant.donnee_suppl = NULL;
                    tab[i][j] = courant;
                }
                if(j == 9){
                    courant.type = DESTINATION;
                    courant.donnee_suppl = NULL;
                    tab[i][j] = courant;
                }
                if(j > 0 && j < 8){
                    courant.type = VIDE;
                    courant.donnee_suppl = NULL;
                    tab[i][j] = courant;
                }
            }
        }
    }
}



void Map_Niveau_1(Coordonnees taille, Objet ** tab){
    unsigned int i,j;
    Objet courant;
    Generation gen_lanceur;

    initialise_generation(&gen_lanceur);

    /*On parcourt les différentes lignes pour y remlir les objets correspondants*/
    for(i = 0; i < taille.y ; i++){

        for(j = 0; j < taille.x ;j++){

            if(i == 0){
                if(j == 0){
                    courant.type = LANCEUR;
                    courant.donnee_suppl = &gen_lanceur;
                    tab[i][j] = courant;
                }
                else{
                    courant.type = VIDE;
                    courant.donnee_suppl = NULL;
                    tab[i][j] = courant;
                }
            }

            if(i == 1){
                if(j == 8 || j == 7 || j == 6 || j == 5){
                    courant.type = MUR;
                    courant.donnee_suppl = NULL;
                    tab[i][j] = courant;
                }
                else{
                    courant.type = VIDE;
                    courant.donnee_suppl = NULL;
                    tab[i][j] = courant;
                }
            }

            if(i == 2){
                if(j == 1){
                    courant.type = LANCEUR;
                    courant.donnee_suppl = &gen_lanceur;
                    tab[i][j] = courant;
                }
                if(j == 8){
                    courant.type = MUR;
                    courant.donnee_suppl = &gen_lanceur;
                    tab[i][j] = courant;
                }
                if(j != 8 && j != 1){
                    courant.type = VIDE;
                    courant.donnee_suppl = NULL;
                    tab[i][j] = courant;
                }
            }

            if(i == 3){

                if(j == 8 || j == 7 || j == 0 || j == 2){
                    courant.type = MUR;
                    courant.donnee_suppl = NULL;
                    tab[i][j] = courant;
                }
                else{
                    courant.type = VIDE;
                    courant.donnee_suppl = NULL;
                    tab[i][j] = courant;
                }
            }

            if(i == 4){
                if(j == 0){
                    courant.type = PERSONNAGE;
                    courant.donnee_suppl = NULL;
                    tab[i][j] = courant;
                }
                if(j == 8 || j == 7){
                    courant.type = MUR;
                    courant.donnee_suppl = NULL;
                    tab[i][j] = courant;
                }
                if(j == 9){
                    courant.type = DESTINATION;
                    courant.donnee_suppl = NULL;
                    tab[i][j] = courant;
                }
                if(j > 0 && j < 8){
                    courant.type = VIDE;
                    courant.donnee_suppl = NULL;
                    tab[i][j] = courant;
                }
            }
        }
    }
}


void initialise_generation(Generation * gen_lanceur){
    gen_lanceur->intervalle = 1000;    /*1 seconde*/
    gen_lanceur->allure_proj = 300;    /*300 ms*/
}


int test_mort_perso(Niveau niveau){
    unsigned int i,j;

    for(i = 0; i < niveau.taille.y ; i++){

        for(j = 0; j < niveau.taille.x ; j++){

            if(niveau.objets[i][j].type == PERSONNAGE){     /*ON trouve un personnage donc il n'est pas mort*/
                return 0;
            }
        }
    }
    return 0;
}


