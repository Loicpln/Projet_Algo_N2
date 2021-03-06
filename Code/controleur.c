#include "controleur.h"

void gestion(Data *data, const Gestion gestion) //gestion affichage pages
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
    case 7:
        gestion.f7(data);
        break;
    case 8:
        gestion.f8(data);
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
    data.users = chargeUsersDepuisFichier();
    return data;
}

const Gestion fTempo() { return (const Gestion){TempoAccueil, TempoRegles, TempoMenu, TempoSelection, TempoJeu, TempoSelection, TempoJeuIA, TempoEntrainement}; }
const Gestion fAffiche() { return (const Gestion){AfficheAccueil, AfficheRegles, AfficheMenu, AfficheSelection, AfficheJeu, AfficheSelection, AfficheJeuIA, AfficheEntrainement}; }
const Gestion fClavier() { return (const Gestion){ClavierAccueil, ClavierRegles, ClavierMenu, ClavierSelection, ClavierJeu, ClavierSelection, ClavierJeuIA, ClavierEntrainement}; }
const Gestion fClic() { return (const Gestion){ClicAccueil, ClicRegles, ClicMenu, ClicSelection, ClicJeu, ClicSelectionIA, ClicJeuIA, ClicEntrainement}; }
const Gestion fRedim() { return (const Gestion){RedimAccueil, RedimRegles, RedimMenu, RedimSelection, RedimJeu, RedimSelection, RedimJeuIA, RedimEntrainement}; }
