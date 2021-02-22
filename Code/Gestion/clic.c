#include "gestion.h"

void ClicAccueil(Data *data) // gestion clic page d'accueil
{
    if (etatBoutonSouris() == GaucheAppuye)
    {
        if (abscisseSouris() > 5 * largeurFenetre() / 16 && abscisseSouris() < 11 * largeurFenetre() / 16 && ordonneeSouris() > 16 * hauteurFenetre() / 24 && ordonneeSouris() < 19 * hauteurFenetre() / 24)
        {
            for (int i = 0; i < MAX_BALLE; i++)
            {
                accelereBalle(data->balle + i, 2);
            }
            data->page->numero = 3;
        }
        if (abscisseSouris() > 11 * largeurFenetre() / 32 && abscisseSouris() < 21 * largeurFenetre() / 32 && ordonneeSouris() > 11 * hauteurFenetre() / 24 && ordonneeSouris() < 14 * hauteurFenetre() / 24)
        {
            data->page->numero = 2;
        }
        if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
        {
            termineBoucleEvenements();
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
            data->page->numero = 4;
            initRaquettes(data->raquette);
            initBalleJeu(data->balleJeu);
            initScore(data->score);
        }
        if (abscisseSouris() > 9 * largeurFenetre() / 32 && abscisseSouris() < 24 * largeurFenetre() / 32 && ordonneeSouris() > hauteurFenetre() / 2 && ordonneeSouris() < 15 * hauteurFenetre() / 24)
        {
            //*page = page jeu contre IA
            data->page->numero = 6;
            initRaquettes(data->raquette);
            initBalleJeu(data->balleJeu);
            initScore(data->score);
        }
        if (abscisseSouris() > 9 * largeurFenetre() / 32 && abscisseSouris() < 24 * largeurFenetre() / 32 && ordonneeSouris() > hauteurFenetre() / 3 && ordonneeSouris() < 11 * hauteurFenetre() / 24)
        {
            //*page = page entrainement
            data->page->numero = 8;
            initRaquettes(data->raquette);
            initBalleJeu(data->balleJeu);
            initScore(data->score);
        }
        if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
        {
            for (int i = 0; i < MAX_BALLE; i++)
            {
                accelereBalle(data->balle + i, 0.5);
            }
            initPages(data->page);
            data->page->numero = 1;
        }
    }
}

void ClicRegles(Data *data)
{
    if (etatBoutonSouris() == GaucheAppuye)
    {
        if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
        {
            data->page->numero = 1;
        }
    }
}

void ClicSelection(Data *data)
{
    if (etatBoutonSouris() == GaucheAppuye)
    {
        if (abscisseSouris() > 5 * largeurFenetre() / 16 && abscisseSouris() < 11 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
        {
            data->page->numero = 5;
        }
        else if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
        {
            data->page->numero = 3;
        }
    }
}

void ClicSelectionIA(Data *data)
{
    if (etatBoutonSouris() == GaucheAppuye)
    {
        if (abscisseSouris() > 5 * largeurFenetre() / 16 && abscisseSouris() < 11 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
        {
            data->page->numero = 7;
        }
        else if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
        {
            data->page->numero = 3;
        }
    }
}

void ClicJeu(Data *data)
{
    if (etatBoutonSouris() == GaucheAppuye)
    {
        if (!data->page->pause)
        {
            if (abs(abscisseSouris() - 7 * largeurFenetre() / 8) < largeurFenetre() / 30 && abs(ordonneeSouris() - 29 * hauteurFenetre() / 32) < largeurFenetre() / 30)
            {
                data->page->pause = true;
            }
        }
        else
        {
            if (abscisseSouris() > 7 * largeurFenetre() / 20 && abscisseSouris() < 13 * largeurFenetre() / 20 && ordonneeSouris() > 11 * hauteurFenetre() / 20 && ordonneeSouris() < 13 * hauteurFenetre() / 20)
            {
                data->page->pause = false;
            }
            if (abscisseSouris() > 7 * largeurFenetre() / 20 && abscisseSouris() < 13 * largeurFenetre() / 20 && ordonneeSouris() > 7 * hauteurFenetre() / 20 && ordonneeSouris() < 9 * hauteurFenetre() / 20)
            {
                data->page->pause = false;
                initBalleJeu(data->balleJeu);
                initScore(data->score);
                initRaquettes(data->raquette);
            }
            if (abscisseSouris() > 7 * largeurFenetre() / 20 && abscisseSouris() < 13 * largeurFenetre() / 20 && ordonneeSouris() > 3 * hauteurFenetre() / 20 && ordonneeSouris() < 5 * hauteurFenetre() / 20)
            {
                data->page->pause = false;
                data->page->numero = 3;
            }
        }
    }
}

void ClicJeuIA(Data *data)
{
    if (etatBoutonSouris() == GaucheAppuye)
    {
        if (!data->page->pause)
        {
            if (abs(abscisseSouris() - 7 * largeurFenetre() / 8) < largeurFenetre() / 30 && abs(ordonneeSouris() - 29 * hauteurFenetre() / 32) < largeurFenetre() / 30)
            {
                data->page->pause = true;
            }
        }
        else
        {
            if (abscisseSouris() > 7 * largeurFenetre() / 20 && abscisseSouris() < 13 * largeurFenetre() / 20 && ordonneeSouris() > 11 * hauteurFenetre() / 20 && ordonneeSouris() < 13 * hauteurFenetre() / 20)
            {
                data->page->pause = false;
            }
            if (abscisseSouris() > 7 * largeurFenetre() / 20 && abscisseSouris() < 13 * largeurFenetre() / 20 && ordonneeSouris() > 7 * hauteurFenetre() / 20 && ordonneeSouris() < 9 * hauteurFenetre() / 20)
            {
                data->page->pause = false;
                initBalleJeu(data->balleJeu);
                initScore(data->score);
                initRaquettes(data->raquette);
            }
            if (abscisseSouris() > 7 * largeurFenetre() / 20 && abscisseSouris() < 13 * largeurFenetre() / 20 && ordonneeSouris() > 3 * hauteurFenetre() / 20 && ordonneeSouris() < 5 * hauteurFenetre() / 20)
            {
                data->page->pause = false;
                data->page->numero = 3;
            }
        }
    }
}

void ClicEntrainement(Data *data)
{
    if (etatBoutonSouris() == GaucheAppuye)
    {
        if (!data->page->pause)
        {
            if (abs(abscisseSouris() - 7 * largeurFenetre() / 8) < largeurFenetre() / 30 && abs(ordonneeSouris() - 29 * hauteurFenetre() / 32) < largeurFenetre() / 30)
            {
                data->page->pause = true;
            }
        }
        else
        {
            if (abscisseSouris() > 7 * largeurFenetre() / 20 && abscisseSouris() < 13 * largeurFenetre() / 20 && ordonneeSouris() > 11 * hauteurFenetre() / 20 && ordonneeSouris() < 13 * hauteurFenetre() / 20)
            {
                data->page->pause = false;
            }
            if (abscisseSouris() > 7 * largeurFenetre() / 20 && abscisseSouris() < 13 * largeurFenetre() / 20 && ordonneeSouris() > 7 * hauteurFenetre() / 20 && ordonneeSouris() < 9 * hauteurFenetre() / 20)
            {
                data->page->pause = false;
                initBalleJeu(data->balleJeu);
                initRaquettes(data->raquette);
            }
            if (abscisseSouris() > 7 * largeurFenetre() / 20 && abscisseSouris() < 13 * largeurFenetre() / 20 && ordonneeSouris() > 3 * hauteurFenetre() / 20 && ordonneeSouris() < 5 * hauteurFenetre() / 20)
            {
                data->page->pause = false;
                data->page->numero = 3;
            }
        }
    }
}
