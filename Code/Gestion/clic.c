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
        clicRouage(&data->page, 9 * Ux, 90 * Uy, r_Rouage);
        clicAddUsers(&data->page);
        if (data->page.pause)
            ClicMutateur(data);
        else if (!data->page.pause)
        {
            clicUsers(data->joueurs, data->joueurs[1], data->users);
            clicSupprUsers(data->joueurs, data->users);
            if (30 * Ux < X_SOURIS < 70 * Ux && 5 * Uy < Y_SOURIS < 15 * Uy)
                if (data->joueurs[0].user != NULL && data->joueurs[1].user != NULL)
                {
                    data->page.numero = Jeu;
                    resetBalle(&data->balleJeu, &data->option);
                    resetTimer(data->timer, data->option);
                }
            if (75 * Ux < X_SOURIS < 95 * Ux && 5 * Uy < Y_SOURIS < 15 * Uy)
            {
                data->page.numero = Menu;
                resetUsers(data->joueurs);
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

        if (data->page.pause == 2)
        {
            ClicMutateur(data);
            clicRouage(&data->page, 88 * Ux, 90 * Uy, r_Rouage);
        }
        else if (data->page.pause)
            clicPause(data);
    }
}

void ClicResultats(Data *const data)
{
    if (etatBoutonSouris() == GaucheAppuye)
    {
        clicRouage(&data->page, 12 * Ux, 90 * Uy, r_Rouage);
        if (!data->page.pause)
        {
            if (30 * Ux < X_SOURIS < 70 * Ux && 20 * Uy < Y_SOURIS < 30 * Uy)
            {
                data->page.numero = Jeu;
                data->joueurs[0].raquette.y = (MAX_Y_PLATEAU + MIN_Y_PLATEAU) / 2;
                data->joueurs[1].raquette.y = (MAX_Y_PLATEAU + MIN_Y_PLATEAU) / 2;
                resetBalle(&data->balleJeu, &data->option);
                resetRaquette(data->joueurs);
                resetScore(data->joueurs);
            }
            if (30 * Ux < X_SOURIS < 70 * Ux && 5 * Uy < Y_SOURIS < 15 * Uy)
            {
                data->page.numero = Menu;
                resetUsers(data->joueurs);
                resetBalle(&data->balleJeu, &data->option);
                resetRaquette(data->joueurs);
                resetScore(data->joueurs);
            }
        }
    }
}

void clicPause(Data *const data)
{
    if (35 * Ux < X_SOURIS < 65 * Ux && 55 * Uy < Y_SOURIS < 65 * Uy)
        data->page.pause = false;
    if (35 * Ux < X_SOURIS < 65 * Ux && 42 * Uy < Y_SOURIS < 52 * Uy)
    {
        data->page.pause = false;
        data->joueurs[0].raquette.y = (MAX_Y_PLATEAU + MIN_Y_PLATEAU) / 2;
        data->joueurs[1].raquette.y = (MAX_Y_PLATEAU + MIN_Y_PLATEAU) / 2;
        resetBalle(&data->balleJeu, &data->option);
        resetScore(data->joueurs);
        resetTimer(data->timer, data->option);
    }

    if (35 * Ux < X_SOURIS < 65 * Ux && 29 * Uy < Y_SOURIS < 39 * Uy)
    {
        data->page.pause = 2;

    }

    if (35 * Ux < X_SOURIS < 65 * Ux && 15 * Uy < Y_SOURIS < 25 * Uy)
    {
        data->page.pause = false;
        data->page.numero = Menu;
        resetBalle(&data->balleJeu, &data->option);
        resetUsers(data->joueurs);
        resetRaquette(data->joueurs);
        resetScore(data->joueurs);
        resetTimer(data->timer, data->option);
    }
}

//sous traitance
void ClicMutateur(Data *const data)
{
    // SELECTION TAILLE RAQUETTE ET RENVOI VALEUR (1 = S, 2 = M, 3 = L)

    if (etatBoutonSouris() == GaucheAppuye)
    {
        data->option.triangle1 = modifTriangle1(data->option.triangle1); // CHOIX VITESSE BALLE ET RENVOI % (0 VITESSE MINIMALE, 100 VITESSE MAXIMALE)
        data->option.triangle2 = modifTriangle2(data->option.triangle2); // CHOIX TAILLE BALLE ET RENVOI % (0 TAILLE MINIMALE, 100 TAILLE MAXIMALE)

        if (abscisseSouris() >= 33 * Ux && abscisseSouris() <= 43 * Ux && ordonneeSouris() >= 10 * Uy && ordonneeSouris() <= 18 * Uy)
        {

            data->joueurs[0].raquette.longueur = 2 * LONG_RAQUETTE / 3;
            data->joueurs[1].raquette.longueur = 2 * LONG_RAQUETTE / 3;
            
        }
        else if (abscisseSouris() >= 45 * Ux && abscisseSouris() <= 55 * Ux && ordonneeSouris() >= 10 * Uy && ordonneeSouris() <= 18 * Uy)
        {
            data->joueurs[0].raquette.longueur = LONG_RAQUETTE;
            data->joueurs[1].raquette.longueur = LONG_RAQUETTE;
            
            
        }
        else if ((abscisseSouris() >= 57 * Ux && abscisseSouris() <= 67 * Ux && ordonneeSouris() >= 10 * Uy && ordonneeSouris() <= 18 * Uy))
        {
            data->joueurs[0].raquette.longueur = 3 * LONG_RAQUETTE / 2;
            data->joueurs[1].raquette.longueur = 3 * LONG_RAQUETTE / 2;
            
        }
    }
    resetBalle(&data->balleJeu, &data->option);
}

// FONCTION MODIFICATION POSITION CURSEUR GAUCHE
float modifTriangle1(float triangle)
{
    if (abscisseSouris() >= absBar1 && abscisseSouris() <= 42 * Ux && ordonneeSouris() >= 53 * Uy && ordonneeSouris() <= 55 * Uy)
    {
        triangle = abscisseSouris() - absBar1;
    }
    return triangle;
}

// FONCTION MODIFICATION POSITION CURSEUR DROITE
float modifTriangle2(float triangle)
{
    if (abscisseSouris() >= absBar2 && abscisseSouris() <= 90 * Ux && ordonneeSouris() >= 53 * Uy && ordonneeSouris() <= 55 * Uy)
    {
        triangle = abscisseSouris() - absBar2;
    }
    //triangle = triangle*100/318;
    return triangle;
}
