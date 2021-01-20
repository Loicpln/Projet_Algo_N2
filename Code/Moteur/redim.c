#include "../controleur.h"

void RedimAccueil(Data *data) //Affichage page d'accueil
{
    for (int i = 0; i < MAX_BALLE; i++)
    {
        if (data->balle[i].x >= largeurFenetre())
            data->balle[i].x = largeurFenetre() - 1;
        if (data->balle[i].y >= hauteurFenetre())
            data->balle[i].y = hauteurFenetre() - 1;
    }
}

void RedimJeu(Data *data)
{
    for (int i = 0; i < MAX_BALLE; i++)
    {
        if (data->balle[i].x >= largeurFenetre())
            data->balle[i].x = largeurFenetre() - 1;
        if (data->balle[i].y >= hauteurFenetre())
            data->balle[i].y = hauteurFenetre() - 1;
    }
}

void RedimRegles(Data *data)
{
}

void RedimMenu(Data *data)
{
}