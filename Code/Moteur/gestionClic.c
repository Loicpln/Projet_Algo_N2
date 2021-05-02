#include "moteur.h"
//Gestion du clic sur les rouages (parametres)
void clicRouage(Page *const page, const int x, const int y, const int r)
{
    if (abs(abscisseSouris() - x) < r && abs(ordonneeSouris() - y) < r)
        page->pause = (page->pause == true) ? false : true;
}
//Gestion du clic sur les users
void clicUsers(Joueur *const joueur, const Joueur autre, Users *const users)
{
    const User *tmp = users->premier;
    for (int i = 0; tmp != NULL; i++, tmp = tmp->userSuivant)
        if (2 * Ux + 20 * (i % 5) * Ux < X_SOURIS < 18 * Ux + 20 * (i % 5) * Ux && 56 * Uy - 35 * floor(i / 5) * Uy < Y_SOURIS < 83 * Uy - 35 * floor(i / 5) * Uy)
        {
            if (autre.user == NULL)
                joueur->user = rechercheUser(users, i);
            else if (rechercheUser(users, i)->id != autre.user->id)
                joueur->user = rechercheUser(users, i);
        }
    if (42 * Ux < X_SOURIS < 58 * Ux && 85 * Uy < Y_SOURIS < 95 * Uy)
        joueur->user = creeUser(id_IA, "IA", -1, -1, -1);
}
//Gestion du clic de suppression des utilisateurs
void clicSupprUsers(Joueur *const joueur, Users *users)
{
    const User *tmp = users->premier;
    for (int i = 0; tmp != NULL; i++, tmp = tmp->userSuivant)
        if (15 * Ux + 20 * (i % 5) * Ux < X_SOURIS < 18 * Ux + 20 * (i % 5) * Ux && 56 * Uy - 35 * floor(i / 5) * Uy < Y_SOURIS < 60 * Uy - 35 * floor(i / 5) * Uy)
        {
            users = supprimeDansUsers(users, i);
            joueur[0].user = NULL;
            joueur[1].user = NULL;
        }
}
//Gestino du clic sur le bouton d'ajout des utilisateurs
void clicAddUsers(Page *const page)
{
    if (87 * Ux < X_SOURIS < 95 * Ux && 85 * Uy < Y_SOURIS < 95 * Uy)
        page->pause = (page->pause == 2) ? false : 2;
}
//Gestino du clic sur le bouton pause
void clicPause(Data *const data)
{
    if (35 * Ux < X_SOURIS < 65 * Ux && 55 * Uy < Y_SOURIS < 65 * Uy)
        data->page.pause = false;
    if (35 * Ux < X_SOURIS < 65 * Ux && 42 * Uy < Y_SOURIS < 52 * Uy)
    {
        data->page.pause = false;
        resetRaquette(data->joueurs, data->option);
        resetBalle(&data->balleJeu, data->option);
        resetScore(data->joueurs);
        resetTimer(data->timer, data->option);
    }

    if (35 * Ux < X_SOURIS < 65 * Ux && 29 * Uy < Y_SOURIS < 39 * Uy)
    {
        data->page.pause = 2;
        resetRaquette(data->joueurs, data->option);
        resetBalle(&data->balleJeu, data->option);
    }

    if (35 * Ux < X_SOURIS < 65 * Ux && 15 * Uy < Y_SOURIS < 25 * Uy)
    {
        data->page.pause = false;
        data->page.numero = Menu;
        data->option = initOptions();
        resetBalle(&data->balleJeu, data->option);
        resetUsers(data->joueurs);
        resetRaquette(data->joueurs, data->option);
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

        if (33 * Ux < X_SOURIS < 43 * Ux && 10 * Uy < Y_SOURIS < 18 * Uy)
            data->option.raquette = 0;
        else if (45 * Ux < X_SOURIS < 55 * Ux && 10 * Uy < Y_SOURIS < 18 * Uy)
            data->option.raquette = 1;
        else if (57 * Ux < X_SOURIS < 67 * Ux && 10 * Uy < Y_SOURIS < 18 * Uy)
            data->option.raquette = 2;
    }
    resetBalle(&data->balleJeu, data->option);
    resetRaquette(data->joueurs, data->option);
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
