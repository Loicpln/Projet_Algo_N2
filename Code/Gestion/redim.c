#include "gestion.h"

void RedimAccueil(Data *const data) //Affichage page d'accueil
{
    for (int i = 0; i < MAX_BALLE; i++)
        redimBalle(data->balle + i);
}

void RedimMenu(Data *const data)
{
    for (int i = 0; i < MAX_BALLE; i++)
        redimBalle(data->balle + i);
}

void RedimRegles(Data *const data) {}

void RedimSelection(Data *const data) {}

void RedimJeu(Data *const data)
{
    for (int i = 0; i < NB_JOUEUR; i++)
        redimRaquette(&data->joueurs[i].raquette, i);
}

void RedimJeuIA(Data *const data)
{
    for (int i = 0; i < NB_JOUEUR; i++)
        redimRaquette(&data->joueurs[i].raquette, i);
}

void RedimEntrainement(Data *const data)
{
    redimRaquette(&data->joueurs[0].raquette, 0);
}