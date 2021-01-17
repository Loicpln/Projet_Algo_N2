#include "fonction.h"

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

void pageJeu()
{
}

void pageRegles(int *page)
{
    couleurCourante(255, 255, 255);
    rectangle(2 * largeurFenetre() / 8, 9 * hauteurFenetre() / 12, 3 * largeurFenetre() / 4, 11 * hauteurFenetre() / 12);
    rectangle(3 * largeurFenetre() / 4, hauteurFenetre() / 12, 15 * largeurFenetre() / 16, hauteurFenetre() / 6); //Retour
    couleurCourante(0, 0, 0);
    rectangle(2 * largeurFenetre() / 8 + 1, 9 * hauteurFenetre() / 12 + 1, 3 * largeurFenetre() / 4 - 1, 11 * hauteurFenetre() / 12 - 1);
    rectangle(3 * largeurFenetre() / 4 + 1, hauteurFenetre() / 12 + 1, 15 * largeurFenetre() / 16 - 1, hauteurFenetre() / 6 - 1); //Retour
    couleurCourante(255, 255, 255);
    afficheChaine("Retour", 30, 31 * largeurFenetre() / 40, hauteurFenetre() / 10);
    afficheChaine("Reglement", 60, 5 * largeurFenetre()/16, 19 * hauteurFenetre()/24);
    afficheChaine("Le concept original de pong est une simulation simpliste ", 20, largeurFenetre()/10, 7 * hauteurFenetre()/12);
    afficheChaine("de tennis de table, les deux joueurs se passent la balle ", 20, largeurFenetre()/10, 6 * hauteurFenetre()/12);
    afficheChaine("a l'aide de raquettes, le joueurs ayant le plus de points", 20, largeurFenetre()/10, 5 * hauteurFenetre()/12);
    afficheChaine("gagne la partie", 20, largeurFenetre()/10, 4 *hauteurFenetre()/12);
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

void gereClicJeu()
{
}

void gereClicRegles(int *page)
{
    if(abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
    {
        *page = 0;
    }
}
