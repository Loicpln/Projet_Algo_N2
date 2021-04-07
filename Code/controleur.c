#include "controleur.h"

void gestion(Data *const data, const Gestion type)
{
    switch (data->page.numero)
    {
    case 1:
        type.f1(data);
        break;
    case 2:
        type.f2(data);
        break;
    case 3:
        type.f3(data);
        break;
    case 4:
        type.f4(data);
        break;
    case 5:
        type.f5(data);
        break;
    case 6:
        type.f6(data);
        break;
    }
}

void F_NULL() {}

const Gestion fTempo() { return (const Gestion){TempoAccueil, TempoRegles, TempoMenu, TempoSelection, TempoJeu, TempoEntrainement}; }
const Gestion fAffiche() { return (const Gestion){AfficheAccueil, AfficheRegles, AfficheMenu, AfficheSelection, AfficheJeu, AfficheEntrainement}; }
const Gestion fClavier() { return (const Gestion){F_NULL, F_NULL, F_NULL, ClavierSelect, ClavierJeu, ClavierEntrainement}; }
const Gestion fClic() { return (const Gestion){ClicAccueil, ClicRegles, ClicMenu, ClicSelection, ClicJeu, ClicJeu}; }