#include "gestion.h"

void RedimAccueil(Data *data) //Affichage page d'accueil
{
    for (int i = 0; i < MAX_BALLE; i++)
    {
        redimBalle(data->balle + i);
    }
}

void RedimMenu(Data *data)
{
    for (int i = 0; i < MAX_BALLE; i++)
    {
        redimBalle(data->balle + i);
    }
}

void RedimRegles(Data *data)
{
}

void RedimSelection(Data *data)
{
}

void RedimJeu(Data *data)
{
    for (int i = 0; i < NB_RAQUETTE; i++)
    {
        redimRaquette(data->raquette + i, i);
    }
}

void RedimJeuIA(Data *data)
{
    for (int i = 0; i < NB_RAQUETTE; i++)
    {
        redimRaquette(data->raquette + i, i);
    }
}

void RedimEntrainement(Data *data)
{
    redimRaquette(data->raquette, 0);
}