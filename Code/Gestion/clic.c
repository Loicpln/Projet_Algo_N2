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
        if(data->page.pause)
            ClicMutateur(data);
        else if (!data->page.pause)
        {
            clicUsers(data->joueurs, data->joueurs[1], data->users);
            clicSupprUsers(data->joueurs, data->users);
            if (30 * Ux < X_SOURIS < 70 * Ux && 5 * Uy < Y_SOURIS < 15 * Uy)
                if (data->joueurs[0].user != NULL && data->joueurs[1].user != NULL)
                {
                    data->page.numero = Jeu;
                    data->balleJeu.v0 = V_BALLE * data->option.triangle1 / 257.f;
                    data->balleJeu.r = R_BALLE * data->option.triangle2 / 257.f + 8.f;
                    //resetRaquette(data->joueurs);
                    data->balleJeu.vx = data->balleJeu.v0;
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
        if (data->page.pause)
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
                resetRaquette(data->joueurs);
                resetScore(data->joueurs);
            }
            if (30 * Ux < X_SOURIS < 70 * Ux && 5 * Uy < Y_SOURIS < 15 * Uy)
            {
                data->page.numero = Menu;
                resetUsers(data->joueurs);
                resetRaquette(data->joueurs);
                resetScore(data->joueurs);
            }
        }
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
   
        if (abscisseSouris() >= (1.5 * largeurFenetre() / 14) && abscisseSouris() <= (2.83 * largeurFenetre() / 12) && ordonneeSouris() >= (hauteurFenetre() / 12) && ordonneeSouris() <= (1 * hauteurFenetre() / 6))
        {
            data->joueurs[0].raquette.longueur = 2 * LONG_RAQUETTE / 3;
            data->joueurs[1].raquette.longueur = 2 * LONG_RAQUETTE / 3;
        }
        else if ((abscisseSouris() >= (2.83 * largeurFenetre() / 12) && abscisseSouris() <= (4.425 * largeurFenetre() / 12) && ordonneeSouris() >= (hauteurFenetre() / 12) && ordonneeSouris() <= (1 * hauteurFenetre() / 6)))
        {
            data->joueurs[0].raquette.longueur = LONG_RAQUETTE;
            data->joueurs[1].raquette.longueur = LONG_RAQUETTE;
        }
        else if ((abscisseSouris() >= (4.425 * largeurFenetre() / 12) && abscisseSouris() <= (7 * largeurFenetre() / 14) && ordonneeSouris() >= (hauteurFenetre() / 12) && ordonneeSouris() <= (1 * hauteurFenetre() / 6)))
        {
            data->joueurs[0].raquette.longueur = 3 * LONG_RAQUETTE / 2;
            data->joueurs[1].raquette.longueur = 3 * LONG_RAQUETTE / 2;
        }
        
                    printf("%f\n",data->option.triangle1);
    }
    //data->balleJeu.vx=V_BALLETEST*data->option.triangle1/100;
}

// FONCTION MODIFICATION POSITION CURSEUR GAUCHE
float modifTriangle1(float triangle)
{
        if (abscisseSouris() >= (1.5 * largeurFenetre() / 14) && abscisseSouris() <= (6 * largeurFenetre() / 14) && ordonneeSouris() >= (6 * hauteurFenetre() / 12) && ordonneeSouris() <= (6.1 * hauteurFenetre() / 12))
        {
            triangle = abscisseSouris() - absBar1;
        }
    return triangle;
}

// FONCTION MODIFICATION POSITION CURSEUR DROITE
float modifTriangle2(float triangle)
{
        if (abscisseSouris() >= (8 * largeurFenetre() / 14) && abscisseSouris() <= (12.5 * largeurFenetre() / 14) && ordonneeSouris() >= (6 * hauteurFenetre() / 12) && ordonneeSouris() <= (6.1 * hauteurFenetre() / 12))
        {
            triangle = abscisseSouris() - absBar2;
        }
        //triangle = triangle*100/318;
    return triangle;
}