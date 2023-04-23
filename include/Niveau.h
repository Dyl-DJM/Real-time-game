#ifndef __NIVEAU__
#define __NIVEAU__

    #include "aide.h"

    /*Cette fonction permet la création et le renvoie d'un niveau selon l'entier 'niveau'*/
    Niveau* niveauN(int niveau);

    /*Permet l'a création du niveau 0, la fonction renvoie un niveau*/
    Niveau* niveau0();

    /*Cette fonction renvoie le Niveau de dimension 'taille'*/
    Niveau * malloc_Niveau(Coordonnees taille);

    /*Fonction de libération du niveau 'niv'*/
    void free_Niveau(Niveau *niv);

    /*Fonction permettant la construction de la map du niveau 0, en remplissante le tableau 'tab' de taille 'taille'*/
    void Map_Niveau_0(Coordonnees taille, Objet ** tab);

    /*Fonction permettant la construction de la map du niveau 1, en remplissante le tableau 'tab' de taille 'taille'*/
    void Map_Niveau_1(Coordonnees taille, Objet ** tab);

    /*Cette fonction permet l'initialisation d'un objet lanceur*/
    void initialise_generation(Generation * gen_lanceur);

    /*Cette fonction renvoie 1 si aucun perosnnage n'est présent dans 'niveau' et 0 sinon*/
    int test_mort_perso(Niveau niveau);

#endif