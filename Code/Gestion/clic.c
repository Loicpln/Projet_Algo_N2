#include "gestion.h"

void ClicAccueil(Data *const data)
{
    if (etatBoutonSouris() == GaucheAppuye)
    {
        if (30 * Ux < X_SOURIS < 70 * Ux && 65 * Uy < Y_SOURIS < 80 * Uy)
        {
            for (int i = 0; i < NB_BALLE; i++)
                accelereBalle(data->balle + i, 2.f);
            data->page.numero = Menu;
        }
        if (35 * Ux < X_SOURIS < 65 * Ux && 45 * Uy < Y_SOURIS < 60 * Uy)
            data->page.numero = Regles;
        if (75 * Ux < X_SOURIS < 95 * Ux && 5 * Uy < Y_SOURIS < 15 * Uy)
            termineBoucleEvenements();
    }
}

void ClicMenu(Data *const data)
{
    if (etatBoutonSouris() == GaucheAppuye)
    {
        if (25 * Ux < X_SOURIS < 75 * Ux && 67 * Uy < Y_SOURIS < 79 * Uy)
        {
            data->option.mode = ContreLaMontre;
            data->page.numero = Selection;
        }
        if (25 * Ux < X_SOURIS < 75 * Ux && 50 * Uy < Y_SOURIS < 63 * Uy)
        {
            data->option.mode = BattleRoyal;
            data->page.numero = Selection;
        }
        if (25 * Ux < X_SOURIS < 75 * Ux && 33 * Uy < Y_SOURIS < 46 * Uy)
        {
            data->option.mode = Entrainement;
            data->page.numero = Entrainement;
        }
        if (75 * Ux < X_SOURIS < 95 * Ux && 5 * Uy < Y_SOURIS < 15 * Uy)
        {
            for (int i = 0; i < NB_BALLE; i++)
                accelereBalle(data->balle + i, 0.5f);
            data->page.numero = Acceuil;
        }
    }
}

void ClicRegles(Data *const data)
{
    if (etatBoutonSouris() == GaucheAppuye)
        if (75 * Ux < X_SOURIS < 95 * Ux && 5 * Uy < Y_SOURIS < 15 * Uy)
            data->page.numero = Acceuil;
}

void ClicSelection(Data *const data)
{
    if (etatBoutonSouris() == DroiteAppuye)
    {
        if (!data->page.pause)
            clicUsers(data->joueurs + 1, data->joueurs[0], data->users);
    }
    else if (etatBoutonSouris() == GaucheAppuye)
    {
        clicAddUsers(&data->page);
        if (!data->page.pause)
        {
            clicUsers(data->joueurs, data->joueurs[1], data->users);
            clicSupprUsers(data->joueurs, data->users);
            if (30 * Ux < X_SOURIS < 70 * Ux && 5 * Uy < Y_SOURIS < 15 * Uy)
                if (data->joueurs[0].user != NULL && data->joueurs[1].user != NULL)
                    data->page.numero = Jeu;
            if (75 * Ux < X_SOURIS < 95 * Ux && 5 * Uy < Y_SOURIS < 15 * Uy)
            {
                data->page.numero = Menu;
                resetJoueurs(data->joueurs);
            }
        }
    }
}

void ClicJeu(Data *const data)
{
    if (etatBoutonSouris() == GaucheAppuye)
    {
        if (data->option.mode == ContreLaMontre || data->option.mode == Entrainement)
            clicRouage(&data->page, 88 * Ux, 90 * Uy, r_Rouage);
        else
            clicRouage(&data->page, MID_X, 90 * Uy, r_Rouage);
        if (data->page.pause)
            clicPause(data);
    }
}
