#include "controleur.h"

void gestion(int *page, Gestion gestion) //gestion affichage pages
{
    switch (*page)
    {
    case 0:
        gestion.f1();
        break;
    case 1:
        gestion.f2();
        break;
    case 2:
        gestion.f3();
        break;
    }
}

Gestion fAffiche(){
    return (Gestion){AfficheAccueil,AfficheJeu,AfficheRegles};
}

Gestion fClavier(){
    return (Gestion){NULL,NULL,NULL};
}

Gestion fClick(){
    return (Gestion){ClicAccueil,ClicJeu,ClicRegles};
}