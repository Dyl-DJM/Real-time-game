/* Auteurs : Arij   TOUAMI - Dylan DE JESUS
 * Date creation : 24-04-2021
 * Date modification : 21-05-2021*/

#include "../include/graphique.h"
#include <stdlib.h>

int evenement(int touche, char wbreaker_opt ,Niveau *niv){
    unsigned int move, etat_partie;
    char direction;

    Coordonnees position, ancienne_position;    /*On crée deux coordonnées liées au personnage*/
    Objet perso, vide, mur;     /*Les objets qui seront amenés à être déplacés*/


    /*Initialisation des différents objets*/

    perso.type = PERSONNAGE;
    perso.donnee_suppl = NULL;

    vide.type = VIDE;
    vide.donnee_suppl = NULL;

    mur.type = MUR;
    mur.donnee_suppl = NULL;

    move = 0;
    etat_partie = 0;
    direction = '\0';

    /*La position est celle du personnage dans le niveau*/
    position = niv->coo_perso;
    ancienne_position = position;


    /*Traitement selon la touche pressée*/
    switch(touche){

        case 122:{      /*TOUCHE --> Z*/
            if(position.y > 0){
                position.y = position.y - 1;
                move++;
                if(position.y > 0){
                    if(niv->objets[position.y - 1][position.x].type != DESTINATION && niv->objets[position.y - 1][position.x].type != LANCEUR && niv->objets[position.y - 1][position.x].type != MUR){
                        direction = 'N';
                    }
                }
            }
            break;
        }

        case 113:{      /*TOUCHE --> Q*/
            if(position.x > 0){
                position.x = position.x - 1;
                move++;
                if(position.x > 0){
                    if(niv->objets[position.y][position.x - 1].type != DESTINATION && niv->objets[position.y][position.x - 1].type != LANCEUR && niv->objets[position.y][position.x - 1].type != MUR){
                        direction = 'O';
                    }
                }
            }
            break;
        }

        case 115:{      /*TOUCHE --> S*/
            if(position.y < niv->taille.y - 1){
                position.y = position.y + 1;
                move++;
                if(position.y < niv->taille.y - 1){
                    if(niv->objets[position.y + 1][position.x].type != DESTINATION && niv->objets[position.y + 1][position.x].type != LANCEUR && niv->objets[position.y + 1][position.x].type != MUR){
                        direction = 'S';
                    }
                }
            }
            break;
        }

        case 100:{      /*TOUCHE --> D*/
            if(position.x < niv->taille.x - 1){
                position.x = position.x + 1;
                move++;
                if(position.x < niv->taille.x - 1){
                    if(niv->objets[position.y][position.x + 1].type != DESTINATION && niv->objets[position.y][position.x + 1].type != LANCEUR && niv->objets[position.y][position.x + 1].type != MUR){
                        direction = 'E';
                    }
                }
            }
            break;
        }
    }

    /*Si le mouvement a pu s'effectuer et que la case pointée par le déplacement n'est pas un lanceur*/

    if(move != 0 && niv->objets[position.y][position.x].type != LANCEUR){

        /*Si la case pointée n'est pas un mur*/
        if(niv->objets[position.y][position.x].type != MUR){

            /*Si la case pointée es tla destination on incrémente l'état de partie
            pour signifier qu'elle est terminée*/
            if(niv->objets[position.y][position.x].type == DESTINATION){
                etat_partie++;
            }

            /*On met le personnage à la case pointée et on efface son ancienne position*/
            niv->objets[position.y][position.x] = perso;
            niv->objets[ancienne_position.y][ancienne_position.x] = vide;

            /*Actualisation coordonnée perso*/
            niv->coo_perso = position;
        }

        /*Si la case pointée est un mur mais que l'option WallBreaker est activée on continue*/
        if(niv->objets[position.y][position.x].type == MUR && wbreaker_opt == 'o'){

            /*Si le repoussage de mur est possible*/
            if(direction != '\0'){

                /*ON déplace le personnage*/
                niv->objets[position.y][position.x] = perso;
                niv->objets[ancienne_position.y][ancienne_position.x] = vide;

                niv->coo_perso = position;

                /*Selon la direction de repoussement
                on change les coordonnées*/
                switch(direction){
                    case 'N':{
                        position.y = position.y - 1;
                        break;
                    }
                    case 'O':{
                        position.x = position.x - 1;
                        break;
                    }
                    case 'S':{
                        position.y = position.y + 1;
                        break;
                    }
                    case 'E':{
                        position.x = position.x + 1;
                        break;
                    }
                }

                /*Nouvelle coordonnées du mur repoussé*/
                niv->objets[position.y][position.x] = mur;
            }
        }
    }

    return etat_partie;
}
