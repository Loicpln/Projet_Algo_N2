#include "regles.h"

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

void gereClicRegles(int *page)
{
    if(abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
    {
        *page = 0;
    }
}
