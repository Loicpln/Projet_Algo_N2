#include "jeu.h"

void pageJeu()
{
    couleurCourante(255, 255, 255);
    rectangle(9 * largeurFenetre() / 32, 16 * hauteurFenetre() / 24, 24 * largeurFenetre() / 32, 19 * hauteurFenetre() / 24); //JcJ
    rectangle(9 * largeurFenetre() / 32, hauteurFenetre() / 2, 24 * largeurFenetre() / 32, 15 * hauteurFenetre() / 24);       //contreIA
    rectangle(9 * largeurFenetre() / 32, hauteurFenetre() / 3, 24 * largeurFenetre() / 32, 11 * hauteurFenetre() / 24);       //entrainement
    rectangle(3 * largeurFenetre() / 4, hauteurFenetre() / 12, 15 * largeurFenetre() / 16, hauteurFenetre() / 6);             //Quitter

    couleurCourante(0, 0, 0);
    rectangle(9 * largeurFenetre() / 32 + 1, 2 * hauteurFenetre() / 3 + 1, 24 * largeurFenetre() / 32 - 1, 19 * hauteurFenetre() / 24 - 1); //JcJ
    rectangle(9 * largeurFenetre() / 32 + 1, hauteurFenetre() / 2 + 1, 24 * largeurFenetre() / 32 - 1, 15 * hauteurFenetre() / 24 - 1);     //contreIA
    rectangle(9 * largeurFenetre() / 32 + 1, hauteurFenetre() / 3 + 1, 24 * largeurFenetre() / 32 - 1, 11 * hauteurFenetre() / 24 - 1);     //entrainement
    rectangle(3 * largeurFenetre() / 4 + 1, hauteurFenetre() / 12 + 1, 15 * largeurFenetre() / 16 - 1, hauteurFenetre() / 6 - 1);           //Quitter

    couleurCourante(255, 255, 255);
    afficheChaine("Joueur contre joueur", 30, 5 * largeurFenetre() / 16, 17 * hauteurFenetre() / 24);
    afficheChaine("Jouer contre IA", 30, 5 * largeurFenetre() / 16, 13 * hauteurFenetre() / 24);
    afficheChaine("Entrainement", 30, 5 * largeurFenetre() / 16, 9 * hauteurFenetre()/24);
    afficheChaine("Retour", 30, 31 * largeurFenetre() / 40, hauteurFenetre() / 10);
}

void gereClicJeu(int * page)
{
    if (abscisseSouris() > 9 * largeurFenetre() / 32 && abscisseSouris() < 24 * largeurFenetre() / 32 && ordonneeSouris() > 16 * hauteurFenetre() / 24 && ordonneeSouris() < 19 * hauteurFenetre() / 24)
    {
        //*page = joueur contre joueur
    }
    if(abscisseSouris() > 9 * largeurFenetre() / 32 && abscisseSouris() < 24 * largeurFenetre() / 32 && ordonneeSouris() > hauteurFenetre() / 2 && ordonneeSouris() < 15 * hauteurFenetre() / 24)
    {
        //*page = page jeu contre IA
    }
    if(abscisseSouris() > 9 * largeurFenetre() / 32 && abscisseSouris() < 24 * largeurFenetre() / 32 && ordonneeSouris() > hauteurFenetre() / 3 && ordonneeSouris() < 11 * hauteurFenetre() / 24)
    {
        //*page = page entrainement
    }
    if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
    {
        *page = 0;
    }
}
