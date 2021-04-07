#include "moteur.h"

void selectAcceuil(Select *const select)
{
    if (30 * Ux < X_SOURIS < 70 * Ux && 65 * Uy < Y_SOURIS < 80 * Uy)
        select[0].largeur = L_SELECT;
    if (35 * Ux < X_SOURIS < 65 * Ux && 45 * Uy < Y_SOURIS < 60 * Uy)
        select[1].largeur = L_SELECT;
    if (75 * Ux < X_SOURIS < 95 * Ux && 5 * Uy < Y_SOURIS < 15 * Uy)
        select[2].largeur = L_SELECT;
}

void selectMenu(Select *const select)
{
    if (25 * Ux < X_SOURIS < 75 * Ux && 67 * Uy < Y_SOURIS < 80 * Uy)
        select[0].largeur = L_SELECT;
    if (25 * Ux < X_SOURIS < 75 * Ux && 50 * Uy < Y_SOURIS < 63 * Uy)
        select[1].largeur = L_SELECT;
    if (25 * Ux < X_SOURIS < 75 * Ux && 33 * Uy < Y_SOURIS < 46 * Uy)
        select[2].largeur = L_SELECT;
    if (75 * Ux < X_SOURIS < 95 * Ux && 5 * Uy < Y_SOURIS < 15 * Uy)
        select[3].largeur = L_SELECT;
}

void selectRegles(Select *const select)
{
    if (75 * Ux < X_SOURIS < 95 * Ux && 5 * Uy < Y_SOURIS < 15 * Uy)
        select[0].largeur = L_SELECT;
}

void selectSelection(Select *const select)
{
    for (int i = 0; i < NB_USERS; i++)
    {
        if (2 * Ux + 20 * (i % 5) * Ux < X_SOURIS < 18 * Ux + 20 * (i % 5) * Ux && 56 * Uy - 35 * floor(i / 5) * Uy < Y_SOURIS < 83 * Uy - 35 * floor(i / 5) * Uy)
            select[i].largeur = L_SELECT;
        if (15 * Ux + 20 * (i % 5) * Ux < X_SOURIS < 18 * Ux + 20 * (i % 5) * Ux && 56 * Uy - 35 * floor(i / 5) * Uy < Y_SOURIS < 60 * Uy - 35 * floor(i / 5) * Uy)
            select[i + NB_USERS].largeur = L_SELECT;
    }
    if (42 * Ux < X_SOURIS < 58 * Ux && 85 * Uy < Y_SOURIS < 95 * Uy)
        select[45].largeur = L_SELECT;
    if (30 * Ux < X_SOURIS < 70 * Ux && 5 * Uy < Y_SOURIS < 15 * Uy)
        select[48].largeur = L_SELECT;
    if (75 * Ux < X_SOURIS < 95 * Ux && 5 * Uy < Y_SOURIS < 15 * Uy)
        select[49].largeur = L_SELECT;
}

void selectPause(Select *const select)
{
    if (35 * Ux < X_SOURIS < 65 * Ux && 55 * Uy < Y_SOURIS < 65 * Uy)
        select[0].largeur = L_SELECT;
    if (35 * Ux < X_SOURIS < 65 * Ux && 35 * Uy < Y_SOURIS < 45 * Uy)
        select[1].largeur = L_SELECT;
    if (35 * Ux < X_SOURIS < 65 * Ux && 15 * Uy < Y_SOURIS < 25 * Uy)
        select[2].largeur = L_SELECT;
}

void selectAddUsers(Select *const select)
{
    if (87 * Ux < X_SOURIS < 95 * Ux && 85 * Uy < Y_SOURIS < 95 * Uy)
        select[47].largeur = L_SELECT;
}

void selectRouage(Select *const select, const int mode)
{
    if (mode == ContreLaMontre)
    {
        if (abs(abscisseSouris() - 88 * Ux) < r_Rouage && abs(ordonneeSouris() - 90 * Uy) < r_Rouage)
            select[30].largeur = 3;
    }
    else if (abs(abscisseSouris() - MID_X) < r_Rouage && abs(ordonneeSouris() - 90 * Uy) < r_Rouage)
        select[30].largeur = 3;
}

void selectModeDeJeu(Select *const select)
{
    if (25 * Ux < X_SOURIS < 75 * Ux && 67 * Uy < Y_SOURIS < 80 * Uy)
        select[0].largeur = L_SELECT;
    if (25 * Ux < X_SOURIS < 75 * Ux && 50 * Uy < Y_SOURIS < 63 * Uy)
        select[1].largeur = L_SELECT;
    // if (25 * Ux < X_SOURIS < 75 * Ux && 33 * Uy < Y_SOURIS < 46 * Uy)
    //     select[2].largeur = L_SELECT;
}