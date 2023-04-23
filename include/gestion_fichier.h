#ifndef __GESTION_FICHIER__
#define __GESTION_FICHIER__

#include "aide.h"

    /*Cette fonction permet l'ecriture du 'niveau' dans le fichier stdout*/
    void affiche_Niveau(Niveau* niveau);

    /*Cette fonction permet l'affichage ecrit dans le fichier stdout de l'objet 'obj_courant'*/
    void affiche_element(Objet obj_courant);

    /*Cette fonction permet l'affichage dans le fichier stdout, de l'usage du jeu*/
    void usage(int entier);

    /*Cette fonction permet l'affichage de fin d epartie correspondant
    dans le fichier stdout*/
    void affiche_fin_partie(int type_fin);


    /*================  Représente l'amélioration de la gestion des niveaux par fichiers  ========================*/

    /*Cette fonction renvoie une type Niveau du niveau construit à l'aide
    des données du fichier de nom 'filename'*/
    Niveau* file_to_level(char * filename);


#endif



