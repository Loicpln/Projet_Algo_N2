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
    case 7:
        type.f7(data);
        break;
    case 8:
        type.f8(data);
        break;
    case 9:
        type.f9(data);
        break;
    case 10:
        type.f10(data);
        break;
    }
}

void F_NULL() {}

const Gestion fTempo() { return (const Gestion){TempoAccueil, TempoRegles, TempoMenu, TempoSelection, TempoJeu, TempoSelection, TempoJeuIA, TempoEntrainement, TempoModeDeJeu, TempoModeDeJeu}; }
const Gestion fAffiche() { return (const Gestion){AfficheAccueil, AfficheRegles, AfficheMenu, AfficheSelection, AfficheJeu, AfficheSelection, AfficheJeu, AfficheEntrainement, AfficheModeDeJeu, AfficheModeDeJeu}; }
const Gestion fClavier() { return (const Gestion){F_NULL, F_NULL, F_NULL, ClavierSelect, ClavierJeu2J, ClavierSelect, ClavierJeu1J, ClavierJeu1J, F_NULL, F_NULL}; }
const Gestion fClic() { return (const Gestion){ClicAccueil, ClicRegles, ClicMenu, ClicSelection, ClicJeu, ClicSelectionIA, ClicJeu, ClicJeu, ClicModeDeJeu, ClicModeDeJeuIA}; }