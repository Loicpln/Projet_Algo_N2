#include "controleur.h"

void gestion(Data *data, Gestion gestion) //gestion affichage pages
{
    switch (data->page[0])
    {
    case 0:
        gestion.f1(data);
        break;
    case 1:
        switch (data->page[1])
        {
        case 0:
            gestion.f2(data);
            break;

        case 1:
            gestion.f3(data);
            break;

        case 2:
            gestion.f4(data);
            break;

        case 3:
            gestion.f5(data);
            break;
        }
        break;

    case 2:
        gestion.f6(data);
        break;
    }
}

Data init()
{
    Data data;
    for (int i = 0; i < DIM_PAGE; i++)
    {
        data.page[i] = 0;
    }
    for (int i = 0; i < MAX_BALLE; i++)
    {
        data.balle[i].x = largeurFenetre() * valeurAleatoire();
        data.balle[i].y = hauteurFenetre() * valeurAleatoire();
        data.balle[i].r = 10;
        data.balle[i].vx = (rand() % 2) ? 5 : -5;
        data.balle[i].vy = (rand() % 2) ? 5 : -5;
    }
    for (int i = 0; i < NB_RAQUETTE; i++)
    {
        data.raquette[i].longueur = 100;
        data.raquette[i].largeur = 10;
        data.raquette[i].centre = (hauteurFenetre() / 60 + 99 * hauteurFenetre() / 120) / 2;
        data.raquette[i].vc = 35;
        data.raquette[i].side = (i % 2) ? false : true;
    }
    data.balleJeu->x = 400;
    data.balleJeu->y = (MAX_Y_PLATEAU - MIN_Y_PLATEAU) / 2;
    data.balleJeu->r = 7;
    data.balleJeu->vx = 5;
    data.balleJeu->vy = 5;
    return data;
}

Gestion fTempo() { return (Gestion){TempoAccueil, TempoMenu, TempoJeu, NULL, NULL, TempoRegles}; }
Gestion fAffiche() { return (Gestion){AfficheAccueil, AfficheMenu, AfficheJeu, NULL, NULL, AfficheRegles}; }
Gestion fClavier() { return (Gestion){ClavierAccueil, ClavierMenu, ClavierJeu, NULL, NULL, ClavierRegles}; }
Gestion fClic() { return (Gestion){ClicAccueil, ClicMenu, ClicJeu, NULL, NULL, ClicRegles}; }
Gestion fRedim() { return (Gestion){RedimAccueil, RedimMenu, RedimJeu, NULL, NULL, RedimRegles}; }
