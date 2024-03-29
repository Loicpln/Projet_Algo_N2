#include "moteur.h"

//Ensemble des fonctions de clic

void clicRouage(Page *const page, const int x, const int y, const int r)
{
    if (abs(abscisseSouris() - x) < r && abs(ordonneeSouris() - y) < r) // Si le clic est dans le rouage
        page->pause = (page->pause == true) ? false : true;
}

void clicUsers(Joueur *const joueur, const Joueur autre, Users *const users)
{
    const User *tmp = users->premier;
    for (int i = 0; tmp != NULL; i++, tmp = tmp->userSuivant)                                                                                                      // Pour tous les users
        if (2 * Ux + 20 * (i % 5) * Ux < X_SOURIS < 18 * Ux + 20 * (i % 5) * Ux && 56 * Uy - 35 * floor(i / 5) * Uy < Y_SOURIS < 83 * Uy - 35 * floor(i / 5) * Uy) // Si on clic dans la zone de l'utilisateur correspondant
            if (autre.user == NULL || rechercheUser(users, i)->id != autre.user->id)
                joueur->user = rechercheUser(users, i);
    if (42 * Ux < X_SOURIS < 58 * Ux && 85 * Uy < Y_SOURIS < 95 * Uy) // Si on clique sur l'IA
        joueur->user = creeUser(id_IA, "IA", 0, 0, 0);
}

void clicSupprUsers(Joueur *const joueur, Users *users)
{
    const User *tmp = users->premier;
    for (int i = 0; tmp != NULL; i++, tmp = tmp->userSuivant)// Pour tous les users
        if (15 * Ux + 20 * (i % 5) * Ux < X_SOURIS < 18 * Ux + 20 * (i % 5) * Ux && 56 * Uy - 35 * floor(i / 5) * Uy < Y_SOURIS < 60 * Uy - 35 * floor(i / 5) * Uy)// Si on clic dans la zone de suppression de l'utilisateur correspondant
        {
            users = supprimeDansUsers(users, i);
            for (int i = 0; i < NB_JOUEUR; i++) // On reinitialise tous les joueurs
                joueur[i].user = NULL;
        }
}

void clicAddUsers(Page *const page)
{
    if (87 * Ux < X_SOURIS < 95 * Ux && 85 * Uy < Y_SOURIS < 95 * Uy) // Si on clique sur l'ajout des users
        page->pause = (page->pause == 2) ? false : 2;
}

void clicPause(Data *const data)
{
    if (35 * Ux < X_SOURIS < 65 * Ux && 55 * Uy < Y_SOURIS < 65 * Uy) // Si on clique sur Reprendre
        data->page.pause = false;
    if (35 * Ux < X_SOURIS < 65 * Ux && 42 * Uy < Y_SOURIS < 52 * Uy) // Si on clique sur Rejouer
    {
        data->page.pause = false;
        resetRaquette(data->joueurs, data->option);
        resetBalle(&data->balleJeu, data->option);
        resetScore(data->joueurs);
        resetTimer(data->timer, data->option);
    }

    if (35 * Ux < X_SOURIS < 65 * Ux && 29 * Uy < Y_SOURIS < 39 * Uy) // Si on clique sur Mutateur
    {
        data->page.pause = 2;
        resetRaquette(data->joueurs, data->option);
        resetBalle(&data->balleJeu, data->option);
    }

    if (35 * Ux < X_SOURIS < 65 * Ux && 15 * Uy < Y_SOURIS < 25 * Uy) // Si on clique sur Quitter
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
        data->option.v0 = modifTriangle1(data->option.v0); // CHOIX VITESSE BALLE ET RENVOI % (0 VITESSE MINIMALE, 100 VITESSE MAXIMALE)
        data->option.r = modifTriangle2(data->option.r); // CHOIX TAILLE BALLE ET RENVOI % (0 TAILLE MINIMALE, 100 TAILLE MAXIMALE)

        if (33 * Ux < X_SOURIS < 43 * Ux && 10 * Uy < Y_SOURIS < 18 * Uy)
            data->option.raquette = 0;
        else if (45 * Ux < X_SOURIS < 55 * Ux && 10 * Uy < Y_SOURIS < 18 * Uy)
            data->option.raquette = 1;
        else if (57 * Ux < X_SOURIS < 67 * Ux && 10 * Uy < Y_SOURIS < 18 * Uy)
            data->option.raquette = 2;
        if (data->page.numero != Jeu)
        {
            if (data->option.mode == ContreLaMontre)
            {

                if (74 * Ux < X_SOURIS < 78 * Ux && 30 * Uy < Y_SOURIS < 33 * Uy)
                    if (data->option.temps[0] < 9)
                        data->option.temps[0]++;
                if (82 * Ux < X_SOURIS < 86 * Ux && 30 * Uy < Y_SOURIS < 33 * Uy)
                    if (data->option.temps[1] < 50)
                        data->option.temps[1] += 10;
                if (86 * Ux < X_SOURIS < 90 * Ux && 30 * Uy < Y_SOURIS < 33 * Uy)
                    if (data->option.temps[1] < 59)
                        data->option.temps[1]++;
                if (74 * Ux < X_SOURIS < 78 * Ux && 17 * Uy < Y_SOURIS < 20 * Uy)
                    if (0 < data->option.temps[0])
                        data->option.temps[0]--;
                if (82 * Ux < X_SOURIS < 86 * Ux && 17 * Uy < Y_SOURIS < 20 * Uy)
                    if (0 < data->option.temps[1])
                        data->option.temps[1] -= 10;
                if (86 * Ux < X_SOURIS < 90 * Ux && 17 * Uy < Y_SOURIS < 20 * Uy)
                    if (0 < data->option.temps[1])
                        data->option.temps[1]--;
            }
            else if (data->option.mode == BattleRoyal)
            {
                if (76 * Ux < X_SOURIS < 79 * Ux && 19 * Uy < Y_SOURIS < 22 * Uy)
                    if (1 < data->option.nbButs)
                        data->option.nbButs--;
                if (83 * Ux < X_SOURIS < 86 * Ux && 19 * Uy < Y_SOURIS < 22 * Uy)
                    if (data->option.nbButs < 10)
                        data->option.nbButs++;
            }
        }
        resetBalle(&data->balleJeu, data->option);
        resetRaquette(data->joueurs, data->option);
    }
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