#include "controleur.h"

void gestion(Data *data, Gestion gestion) //gestion affichage pages
{
    switch (*data->page)
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

Gestion fTempo()
{
    return (Gestion){TempoAccueil, TempoJeu, TempoRegles};
}

Gestion fAffiche()
{
    return (Gestion){AfficheAccueil, AfficheJeu, AfficheRegles};
}

Gestion fClavier()
{
    return (Gestion){NULL, NULL, NULL};
}

Gestion fClick()
{
    return (Gestion){ClicAccueil, ClicJeu, ClicRegles};
}