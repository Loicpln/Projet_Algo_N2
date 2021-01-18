#include "controleur.h"

void gestionPage(int *page) //gestion affichage pages
{
    switch (*page)
    {
    case 0:
        pageAccueil();
        break;
    case 1:
        pageJeu();
        break;
    case 2:
        pageRegles(page);
        break;
    }
}

void gestionClic(int *page) //gestion clic toute l'appli
{
    switch (*page)
    {
    case 0:
        gereClicAccueil(page);
        break;
    case 1:
        gereClicJeu(page);
        break;
    case 2:
        gereClicRegles(page);
        break;
    }
}

