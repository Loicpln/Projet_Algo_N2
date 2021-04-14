#include "./Gestion/gestion.h"

typedef struct
{
    //Page 1
    void (*f1)(Data * const);
    //Page 2
    void (*f2)(Data * const);
    //Page 3
    void (*f3)(Data * const);
    //Page 4
    void (*f4)(Data * const);
    //Page 5
    void (*f5)(Data * const);
    //Page 6
    void (*f6)(Data * const);
    //Page 7
    void (*f7)(Data * const);
} Gestion;

//fonction nulle
void FNULL();

//gestion des pages selon type
void gestion(Data *const data, const Gestion type);
//renvoie toutes les fonctions pour le case Temporisation
const Gestion fTempo();
//renvoie toutes les fonctions pour le case Affichage
const Gestion fAffiche();
//renvoie toutes les fonctions pour le case Clavier
const Gestion fClavier();
//renvoie toutes les fonctions pour le case BoutonSouris
const Gestion fClic();