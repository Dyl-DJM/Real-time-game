#ifndef __TAS__
#define __TAS__
#include "aide.h"
#include "temps.h"

    /*Cette fonction permet la construction du Tas*/
    Tas* construit_Tas(Niveau * niveau);

    /*Cette fonction permet l'execution de l'evenement e du 'tas' dans le 'niveau'*/
    void execute_evenement(Evenement e, Tas* tas, Niveau* niveau);


    /*Cette fonction permet l'allocation dynamique et le renvoie d'une structure tas de taille 'capacite'*/
    Tas * malloc_Tas (unsigned capacite);


    /*Fonction de libération mémoire du 'tas'*/
    void free_Tas(Tas *tas);


    /*Cette fonction renvoie true sit un evenemnt du 'tas' est prêt et false sinon*/
    bool un_evenement_est_pret(Tas *tas);

    /*Cette fonction renvoie l'indice du noeud fils du noeud 'indice' dans le tas 'tas'*/
    int Fils(Tas tas, unsigned int indice);


    /*Cette fonction permet les différents echanges entres noeuds, afin de garder la structure de tas*/
    void echange_tas(Tas *tas, unsigned int indice, Evenement val);


    /*Cette fonction extrait et renvoie l'evenement minimum du 'tas'*/
    Evenement ote_minimum(Tas *tas);


    /*Cette fonction permet l'ajout de l'évènement 'n' dans le tas 'tas'*/
    void ajoute_evenement(Tas *tas, Evenement n);


    /*Cette fonction permet l'affichage du 'tas'*/
    void affiche_Tas(Tas *tas);

#endif
