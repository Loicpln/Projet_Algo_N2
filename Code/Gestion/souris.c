#include "gestion.h"

void ClicAccueil(Data *data) // gestion clic page d'accueil
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
                accelereBalle(data->balle + i, 4);
            }
            data->page[0] = 1;
        }
        if (abscisseSouris() > 11 * largeurFenetre() / 32 && abscisseSouris() < 21 * largeurFenetre() / 32 && ordonneeSouris() > 11 * hauteurFenetre() / 24 && ordonneeSouris() < 14 * hauteurFenetre() / 24)
        {
            data->page[0] = 2;
        }
    }
}

void ClicMenu(Data *data)
{
    if (etatBoutonSouris() == GaucheAppuye)
    {
        if (abscisseSouris() > 9 * largeurFenetre() / 32 && abscisseSouris() < 24 * largeurFenetre() / 32 && ordonneeSouris() > 16 * hauteurFenetre() / 24 && ordonneeSouris() < 19 * hauteurFenetre() / 24)
        {
            //*page = joueur contre joueur
            data->page[1] = 1;
        }
        if (abscisseSouris() > 9 * largeurFenetre() / 32 && abscisseSouris() < 24 * largeurFenetre() / 32 && ordonneeSouris() > hauteurFenetre() / 2 && ordonneeSouris() < 15 * hauteurFenetre() / 24)
        {
            //*page = page jeu contre IA
            data->page[1] = 2;
        }
        if (abscisseSouris() > 9 * largeurFenetre() / 32 && abscisseSouris() < 24 * largeurFenetre() / 32 && ordonneeSouris() > hauteurFenetre() / 3 && ordonneeSouris() < 11 * hauteurFenetre() / 24)
        {
            //*page = page entrainement
            data->page[1] = 3;
            data->balleJeu->x = MID_X;
            data->balleJeu->y = (MAX_Y_PLATEAU - MIN_Y_PLATEAU) / 2;
            data->balleJeu->r = 7;
            data->balleJeu->v0 = 5;
            data->balleJeu->vx = data->balleJeu->v0;
            data->balleJeu->vy = 0.1;
        }
        if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
        {
            for (int i = 0; i < MAX_BALLE; i++)
            {
                accelereBalle(data->balle + i, 0.25);
            }
            data->page[0] = 0;
        }
    }
}

void ClicRegles(Data *data)
{
    if (etatBoutonSouris() == GaucheAppuye)
    {
        if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
        {
            data->page[0] = 0;
        }
    }
}

void ClicJeu(Data *data)
{
    if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
    {
        data->page[1] = 0;
    }
}

void ClicEntrainement(Data *data)
{
    if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
    {
        data->page[1] = 0;
    }
}
