#ifndef __GRAPHIQUE__
#define __GRAPHIQUE__

    #include"aide.h"

    /*=================  Amélioration Prioritaire : Déplacement suite à évènements clavier  ==============*/

    /*Cette fonction prend une 'touche' du clavier, une option 'wbreaker_opt' et un niveau en entrée
     et renvoie 0 si le personnage n'a pas atteint la destination du niveau et 1 sinon

     Elle permet également les changement dans la structure du niveau selon l'évènement clavier
     */
    int evenement(int touche, char wbreaker_opt ,Niveau *niv);


#endif