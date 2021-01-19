#include "controleur.h"

void gestion(int *page, Balle *tab, Gestion gestion) //gestion affichage pages
{
    switch (*page)
    {
    case 0:
        gestion.f1(page,tab);
        break;
    case 1:
        gestion.f2(page,tab);
        break;
    case 2:
        gestion.f3(page,tab);
        break;
    }
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