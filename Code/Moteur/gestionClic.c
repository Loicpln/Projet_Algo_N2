#include "moteur.h"

void clicRouage(Page *const page, const int x, const int y, const int r)
{
    if (abs(abscisseSouris() - x) < r && abs(ordonneeSouris() - y) < r)
        page->pause = (page->pause == true) ? false : true;
}


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

void clicAddUsers(Page *const page)
{
    if (87 * Ux < X_SOURIS < 95 * Ux && 85 * Uy < Y_SOURIS < 95 * Uy)
        page->pause = (page->pause == 2) ? false : 2;
}

