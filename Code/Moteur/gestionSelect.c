#include "moteur.h"

void selectBouton(Select *const select, const int x1, const int x2, const int y1, const int y2)
{
    if (x1 < X_SOURIS < x2 && y1 < Y_SOURIS < y2) // Si on survole le bouton la bordure s'agrandit
        select->largeur = L_SELECT_ON;
}

void selectRouage(Select *const select, const int x, const int y, const int r)
{
    if (abs(abscisseSouris() - x) < r && abs(ordonneeSouris() - y) < r)
        select->largeur = L_SELECT_ON;
}

void selectPause(Select *const select)
{
    selectBouton(&select[0], 35 * Ux, 65 * Ux, 55 * Uy, 65 * Uy); // Select du bouton Reprendre
    selectBouton(&select[1], 35 * Ux, 65 * Ux, 42 * Uy, 52 * Uy); // Select du bouton Rejouer
    selectBouton(&select[3], 35 * Ux, 65 * Ux, 29 * Uy, 39 * Uy); // Select du bouton Mutateur
    selectBouton(&select[2], 35 * Ux, 65 * Ux, 15 * Uy, 25 * Uy); // Select du bouton Quitter
}

void selectUsers(Select *const select)
{
    for (int i = 0; i < NB_USERS; i++)
    {
        selectBouton(&select[i], 2 * Ux + 20 * (i % 5) * Ux, 18 * Ux + 20 * (i % 5) * Ux, 56 * Uy - 35 * floor(i / 5) * Uy, 83 * Uy - 35 * floor(i / 5) * Uy);             // Select du User correspondant
        selectBouton(&select[i + NB_USERS], 15 * Ux + 20 * (i % 5) * Ux, 18 * Ux + 20 * (i % 5) * Ux, 56 * Uy - 35 * floor(i / 5) * Uy, 60 * Uy - 35 * floor(i / 5) * Uy); // Select du bouton supprimer correspondant
    }
    selectBouton(&select[id_IA], 42 * Ux, 58 * Ux, 85 * Uy, 95 * Uy); // Select du bouton IA
    selectBouton(&select[48], 30 * Ux, 70 * Ux, 5 * Uy, 15 * Uy);     // Select du bouton Jouer
    selectBouton(&select[49], 75 * Ux, 95 * Ux, 5 * Uy, 15 * Uy);     // Select du bouton Retour
}

void selectMutateur(Select *const select, const Options option)
{
    for (int i = 25; i < 34; i++)
        couleurSelect(&select[i], 255, 255, 255);
    selectBouton(&select[25], 33 * Ux, 43 * Ux, 10 * Uy, 18 * Uy); // Select du bouton S
    selectBouton(&select[26], 45 * Ux, 55 * Ux, 10 * Uy, 18 * Uy); // Select du bouton M
    selectBouton(&select[27], 57 * Ux, 67 * Ux, 10 * Uy, 18 * Uy); // Select du bouton L
    couleurSelect(&select[25 + option.raquette], 0, 0, 255);       // Couleur Bleu pour la raquette selectionnée
    if (option.mode == ContreLaMontre)
    { // Select des boutons pour changer le timer
        selectBouton(&select[28], 74 * Ux, 78 * Ux, 30 * Uy, 33 * Uy);
        selectBouton(&select[29], 82 * Ux, 86 * Ux, 30 * Uy, 33 * Uy);
        selectBouton(&select[30], 86 * Ux, 90 * Ux, 30 * Uy, 33 * Uy);
        selectBouton(&select[31], 74 * Ux, 78 * Ux, 17 * Uy, 20 * Uy);
        selectBouton(&select[32], 82 * Ux, 86 * Ux, 17 * Uy, 20 * Uy);
        selectBouton(&select[33], 86 * Ux, 90 * Ux, 17 * Uy, 20 * Uy);
    }
    else if (option.mode == BattleRoyal)
    { // Select du bouton pour changer le nombre de vie
        selectBouton(&select[28], 76 * Ux, 79 * Ux, 19 * Uy, 22 * Uy);
        selectBouton(&select[29], 83 * Ux, 86 * Ux, 19 * Uy, 22 * Uy);
    }
}