#include "gestion.h"

void RedimAccueil(Data * const data) //Affichage page d'accueil
{
    for (int i = 0; i < MAX_BALLE; i++)
        redimBalle(data->balle + i);
}

void RedimMenu(Data * const data)
{
    for (int i = 0; i < MAX_BALLE; i++)
        redimBalle(data->balle + i);
}

void RedimRegles(Data * const data)
{
}

void RedimSelection(Data * const data)
{
}

void RedimJeu(Data * const data)
{
    for (int i = 0; i < NB_RAQUETTE; i++)
        redimRaquette(data->raquette + i, i);
}

void RedimJeuIA(Data * const data)
{
    for (int i = 0; i < NB_RAQUETTE; i++)
        redimRaquette(data->raquette + i, i);
}

void RedimEntrainement(Data * const data)
{
    redimRaquette(data->raquette, 0);
}