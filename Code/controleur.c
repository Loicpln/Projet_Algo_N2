#include "controleur.h"

void gestion(Data *data, Gestion gestion) //gestion affichage pages
{
    switch (data->page->numero)
    {
    case 1:
        gestion.f1(data);
        break;
    case 2:
        gestion.f2(data);
        break;
    case 3:
        gestion.f3(data);
        break;
    case 4:
        gestion.f4(data);
        break;
    case 5:
        gestion.f5(data);
        break;
    case 6:
        gestion.f6(data);
        break;
    }
}

Data init()
{
    Data data;
    initPages(data.page);
    initBallesAccueil(data.balle);
    initRaquettes(data.raquette);
    initBalleJeu(data.balleJeu);
    initScore(data.score);
    return data;
}

Gestion fTempo() { return (Gestion){TempoAccueil, TempoRegles, TempoMenu, TempoJeu, TempoJeuIA, TempoEntrainement}; }
Gestion fAffiche() { return (Gestion){AfficheAccueil, AfficheRegles, AfficheMenu, AfficheJeu, AfficheJeuIA, AfficheEntrainement}; }
Gestion fClavier() { return (Gestion){ClavierAccueil, ClavierRegles, ClavierMenu, ClavierJeu, ClavierJeuIA, ClavierEntrainement}; }
Gestion fClic() { return (Gestion){ClicAccueil, ClicRegles, ClicMenu, ClicJeu, ClicJeuIA, ClicEntrainement}; }
Gestion fRedim() { return (Gestion){RedimAccueil, RedimRegles, RedimMenu, RedimJeu, RedimJeuIA, RedimEntrainement}; }
