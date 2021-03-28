#include "moteur.h"

void clicPause(Data *const data)
{
    if (35 * Ux < X_SOURIS < 65 * Ux && 55 * Uy < Y_SOURIS < 65 * Uy)
        data->page.pause = false;
    if (35 * Ux < X_SOURIS < 65 * Ux && 35 * Uy < Y_SOURIS < 45 * Uy)
    {
        data->page.pause = false;
        data->balleJeu = initBalleJeu();
        resetRaquette(data->joueurs);
        resetScore(data->joueurs);
    }
    if (35 * Ux < X_SOURIS < 65 * Ux && 15 * Uy < Y_SOURIS < 25 * Uy)
    {
        data->page.pause = false;
        data->balleJeu = initBalleJeu();
        data->page.numero = Menu;
        resetJoueurs(data->joueurs);
        resetRaquette(data->joueurs);
        resetScore(data->joueurs);
    }
}

void clicUsers(Joueur *const joueur, Users *users)
{
    const User *tmp = users->premier;
    for (int i = 0; tmp != NULL; i++, tmp = tmp->userSuivant)
    {
        if (15 * Ux + 20 * (i % 5) * Ux < X_SOURIS < 18 * Ux + 20 * (i % 5) * Ux && 56 * Uy - 35 * floor(i / 5) * Uy < Y_SOURIS < 60 * Uy - 35 * floor(i / 5) * Uy)
        {
            if (rechercheUser(users, 0) != NULL)
                users = supprimeDansUsers(users, i);
        }
        else if (2 * Ux + 20 * (i % 5) * Ux < X_SOURIS < 18 * Ux + 20 * (i % 5) * Ux && 56 * Uy - 35 * floor(i / 5) * Uy < Y_SOURIS < 83 * Uy - 35 * floor(i / 5) * Uy)
        {
            if (rechercheUser(users, 0) != NULL)
                joueur->user = rechercheUser(users, i);
        }
    }
}

void clicRouage(Page *const page)
{
    if (abs(abscisseSouris() - 88 * Ux) < r_Rouage && abs(ordonneeSouris() - 91 * Uy) < r_Rouage)
        page->pause = (page->pause == true) ? false : true;
}

void clicAddUsers(Page *const page)
{
    if (87 * Ux < X_SOURIS < 95 * Ux && 85 * Uy < Y_SOURIS < 95 * Uy)
        page->pause = (page->pause == true) ? false : true;
}