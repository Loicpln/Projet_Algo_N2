#include "gestion.h"

//Ensemble des fonctions de redimensionnement

void Redim(Data *const data)
{
    for (int i = 0; i < NB_BALLE; i++)
        redimBalle(data->balle + i);
    for (int i = 0; i < NB_JOUEUR; i++)
        redimRaquette(&data->joueurs[i].raquette, i);
}

void redimBalle(Balle *const balle)
{
    // Lors de la redimension la balle reste dans la zone de l'application
    if (balle->x >= largeurFenetre())
        balle->x = largeurFenetre() - balle->vx;
    if (balle->y >= hauteurFenetre())
        balle->y = hauteurFenetre() - balle->vy;
}

void redimRaquette(Raquette *const raquette, const int i)
{
    // Repositionne les raquette lors de la redimension
    if (raquette->y + raquette->longueur / 2 > MAX_Y_PLATEAU)
        raquette->y = MAX_Y_PLATEAU - raquette->longueur / 2;
    if (raquette->y - raquette->longueur / 2 < MIN_Y_PLATEAU)
        raquette->y = MIN_Y_PLATEAU + raquette->longueur / 2;
    raquette->x = (i % 2) ? X_RAQUETTE_RIGHT : X_RAQUETTE_LEFT;
}