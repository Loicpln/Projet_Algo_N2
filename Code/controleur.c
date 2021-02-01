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
    initBallesAccueil(data.balle);
    initRaquettes(data.raquette);
    initBalleJeu(data.balleJeu);
    initScore(data.score);
    return data;
}

Gestion fTempo() { return (Gestion){TempoAccueil, TempoMenu, TempoJeu, TempoJeuIA, TempoEntrainement, TempoRegles}; }
Gestion fAffiche() { return (Gestion){AfficheAccueil, AfficheMenu, AfficheJeu, AfficheJeuIA, AfficheEntrainement, AfficheRegles}; }
Gestion fClavier() { return (Gestion){ClavierAccueil, ClavierMenu, ClavierJeu, ClavierJeuIA, ClavierEntrainement, ClavierRegles}; }
Gestion fClic() { return (Gestion){ClicAccueil, ClicMenu, ClicJeu, ClicJeuIA, ClicEntrainement, ClicRegles}; }
Gestion fRedim() { return (Gestion){RedimAccueil, RedimMenu, RedimJeu, RedimJeuIA, RedimEntrainement, RedimRegles}; }
