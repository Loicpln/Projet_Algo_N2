#include "moteur.h"

void selectBouton(Select *const select, const int x1, const int x2, const int y1, const int y2)
{
    if (x1 < X_SOURIS < x2 && y1 < Y_SOURIS < y2)
        select->largeur = L_SELECT;
}

void selectRouage(Select *const select, const int x, const int y, const int r)
{
    if (abs(abscisseSouris() - x) < r && abs(ordonneeSouris() - y) < r)
        select->largeur = L_SELECT;
}

void selectPause(Select *const select)
{
    selectBouton(&select[0], 35 * Ux, 65 * Ux, 55 * Uy, 65 * Uy);
    selectBouton(&select[1], 35 * Ux, 65 * Ux, 42 * Uy, 52 * Uy);
    selectBouton(&select[3], 35 * Ux, 65 * Ux, 29 * Uy, 39 * Uy);
    selectBouton(&select[2], 35 * Ux, 65 * Ux, 15 * Uy, 25 * Uy);
    
}



void selectUsers(Select *const select)
{
    for (int i = 0; i < NB_USERS; i++)
    {
        selectBouton(&select[i], 2 * Ux + 20 * (i % 5) * Ux, 18 * Ux + 20 * (i % 5) * Ux, 56 * Uy - 35 * floor(i / 5) * Uy, 83 * Uy - 35 * floor(i / 5) * Uy);
        selectBouton(&select[i + NB_USERS], 15 * Ux + 20 * (i % 5) * Ux, 18 * Ux + 20 * (i % 5) * Ux, 56 * Uy - 35 * floor(i / 5) * Uy, 60 * Uy - 35 * floor(i / 5) * Uy);
    }
    selectBouton(&select[id_IA], 42 * Ux, 58 * Ux, 85 * Uy, 95 * Uy);
    selectBouton(&select[48], 30 * Ux, 70 * Ux, 5 * Uy, 15 * Uy);
    selectBouton(&select[49], 75 * Ux, 95 * Ux, 5 * Uy, 15 * Uy);
}