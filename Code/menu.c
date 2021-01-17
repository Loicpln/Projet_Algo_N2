#include "menu.h"

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

void pageAccueil() //Affichage page d'accueil
{
    couleurCourante(255, 255, 255);
    rectangle(3 * largeurFenetre() / 4, hauteurFenetre() / 12, 15 * largeurFenetre() / 16, hauteurFenetre() / 6);              //Quitter
    rectangle(5 * largeurFenetre() / 16, 16 * hauteurFenetre() / 24, 11 * largeurFenetre() / 16, 19 * hauteurFenetre() / 24);  //jouer
    rectangle(11 * largeurFenetre() / 32, 11 * hauteurFenetre() / 24, 21 * largeurFenetre() / 32, 14 * hauteurFenetre() / 24); //reglement
    couleurCourante(0, 0, 0);
    rectangle(3 * largeurFenetre() / 4 + 1, hauteurFenetre() / 12 + 1, 15 * largeurFenetre() / 16 - 1, hauteurFenetre() / 6 - 1);              //Quitter
    rectangle(5 * largeurFenetre() / 16 + 1, 2 * hauteurFenetre() / 3 + 1, 11 * largeurFenetre() / 16 - 1, 19 * hauteurFenetre() / 24 - 1);    //jouer
    rectangle(11 * largeurFenetre() / 32 + 1, 11 * hauteurFenetre() / 24 + 1, 21 * largeurFenetre() / 32 - 1, 14 * hauteurFenetre() / 24 - 1); //reglement
    couleurCourante(255, 255, 255);
    afficheChaine("Jouer", 60, 13 * largeurFenetre() / 32, 83 * hauteurFenetre() / 120);
    afficheChaine("Reglement", 40, 3 * largeurFenetre() / 8, hauteurFenetre() / 2);
    afficheChaine("Quitter", 30, 31 * largeurFenetre() / 40, hauteurFenetre() / 10);
}

void gereClic(int *page) //gestion clic toute l'appli
{
    switch (*page)
    {
    case 0:
        gereClicAccueil(page);
        break;
    case 1:
        gereClicJeu();
        break;
    case 2:
        gereClicRegles(page);
        break;
    }
}

void gereClicAccueil(int *page) // gestion clic page d'accueil
{
    if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
    {
        termineBoucleEvenements();
    }
    if (abscisseSouris() > 5 * largeurFenetre() / 16 && abscisseSouris() < 11 * largeurFenetre() / 16 && ordonneeSouris() > 16 * hauteurFenetre() / 24 && ordonneeSouris() < 19 * hauteurFenetre() / 24)
    {
        *page = 1;
    }
    if (abscisseSouris() > 11 * largeurFenetre() / 32 && abscisseSouris() < 21 * largeurFenetre() / 32 && ordonneeSouris() > 11 * hauteurFenetre() / 24 && ordonneeSouris() < 14 * hauteurFenetre() / 24)
    {
        *page = 2;
    }
}