#include "gestion.h"

void ClicAccueil(int *page, Balle *tab) // gestion clic page d'accueil
{
    if (etatBoutonSouris() == GaucheAppuye)
    {
        if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
        {
            termineBoucleEvenements();
        }
        if (abscisseSouris() > 5 * largeurFenetre() / 16 && abscisseSouris() < 11 * largeurFenetre() / 16 && ordonneeSouris() > 16 * hauteurFenetre() / 24 && ordonneeSouris() < 19 * hauteurFenetre() / 24)
        {
            for (int i = 0; i < MAX_BALLE; i++)
            {
                tab[i].vx *= 4;
                tab[i].vy *= 4;
            }
            *page = 1;
        }
        if (abscisseSouris() > 11 * largeurFenetre() / 32 && abscisseSouris() < 21 * largeurFenetre() / 32 && ordonneeSouris() > 11 * hauteurFenetre() / 24 && ordonneeSouris() < 14 * hauteurFenetre() / 24)
        {
            *page = 2;
        }
    }
}

void ClicJeu(int *page, Balle *tab)
{
    if (etatBoutonSouris() == GaucheAppuye)
    {
        if (abscisseSouris() > 9 * largeurFenetre() / 32 && abscisseSouris() < 24 * largeurFenetre() / 32 && ordonneeSouris() > 16 * hauteurFenetre() / 24 && ordonneeSouris() < 19 * hauteurFenetre() / 24)
        {
            //*page = joueur contre joueur
        }
        if (abscisseSouris() > 9 * largeurFenetre() / 32 && abscisseSouris() < 24 * largeurFenetre() / 32 && ordonneeSouris() > hauteurFenetre() / 2 && ordonneeSouris() < 15 * hauteurFenetre() / 24)
        {
            //*page = page jeu contre IA
        }
        if (abscisseSouris() > 9 * largeurFenetre() / 32 && abscisseSouris() < 24 * largeurFenetre() / 32 && ordonneeSouris() > hauteurFenetre() / 3 && ordonneeSouris() < 11 * hauteurFenetre() / 24)
        {
            //*page = page entrainement
        }
        if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
        {
            for (int i = 0; i < MAX_BALLE; i++)
            {
                tab[i].vx /= 4;
                tab[i].vy /= 4;
            }
            *page = 0;
        }
    }
}

void ClicRegles(int *page, Balle *tab)
{
    if (etatBoutonSouris() == GaucheAppuye)
    {
        if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
        {
            *page = 0;
        }
    }
}
