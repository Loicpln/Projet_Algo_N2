#include "controleur.h"

void init(Data *data)
{
    for (int i = 0; i < DIM_PAGE; i++)
    {
        data->page[i] = 0;
    }
    for (int i = 0; i < MAX_BALLE; i++)
    {
        data->balle[i].x = largeurFenetre() * valeurAleatoire();
        data->balle[i].y = hauteurFenetre() * valeurAleatoire();
        data->balle[i].r = 10;
        data->balle[i].vx = -5;
        data->balle[i].vy = -5;
        if (rand() % 2)
            data->balle[i].vx = fabsf(data->balle[i].vx);

        if (rand() % 2)
            data->balle[i].vy = fabsf(data->balle[i].vy);
    }
}

void gestion(Data *data, Gestion gestion) //gestion affichage pages
{
    switch (data->page[0])
    {
    case 0:
        gestion.f1(data);
        break;
    case 1:
        gestion.f2(data);
        break;
    case 2:
        gestion.f3(data);
        break;
    }
}

Gestion fTempo() { return (Gestion){TempoAccueil, TempoJeu, TempoRegles}; }
Gestion fAffiche() { return (Gestion){AfficheAccueil, AfficheJeu, AfficheRegles}; }
Gestion fClavier() { return (Gestion){ClavierAccueil, ClavierJeu, ClavierRegles}; }
Gestion fClic() { return (Gestion){ClicAccueil, ClicJeu, ClicRegles}; }
Gestion fRedim() { return (Gestion){RedimAccueil, RedimJeu, RedimRegles}; }