#include "gestion.h"

void AfficheAccueil(Data *const data)
{
    couleurCourante(255, 0, 0);
    for (int i = 0; i < MAX_BALLE; i++)
        cercle(data->balle[i].x, data->balle[i].y, data->balle[i].r);

    bouton(data->page.select[0], 30 * Ux, 65 * Uy, 70 * Ux, 80 * Uy);
    bouton(data->page.select[1], 35 * Ux, 45 * Uy, 65 * Ux, 60 * Uy);
    bouton(data->page.select[2], 75 * Ux, 5 * Uy, 95 * Ux, 15 * Uy);
    epaisseurDeTrait(3);
    CC_BLANC;
    afficheChaine("Jouer", 60, 40 * Ux, 68 * Uy);
    afficheChaine("Reglement", 40, 38 * Ux, 50 * Uy);
    afficheChaine("Quitter", 30, 79 * Ux, 8 * Uy);
}
void AfficheMenu(Data *const data)
{
    epaisseurDeTrait(8);
    couleurCourante(rand() % 255, rand() % 255, rand() % 255);
    afficheChaine("PONG", 60, 41 * Ux, 87 * Uy);
    for (int i = 0; i < MAX_BALLE; i++)
        cercle(data->balle[i].x, data->balle[i].y, data->balle[i].r);

    bouton(data->page.select[0], 25 * Ux, 67 * Uy, 75 * Ux, 79 * Uy); //JcJ
    bouton(data->page.select[1], 25 * Ux, 50 * Uy, 75 * Ux, 63 * Uy); //contreIA
    bouton(data->page.select[2], 25 * Ux, 33 * Uy, 75 * Ux, 46 * Uy); //entrainement
    bouton(data->page.select[3], 75 * Ux, 5 * Uy, 95 * Ux, 15 * Uy);  //Quitter
    epaisseurDeTrait(3);
    CC_BLANC;
    afficheChaine("Joueur contre joueur", 30, 30 * Ux, 71 * Uy);
    afficheChaine("Jouer contre IA", 30, 30 * Ux, 54 * Uy);
    afficheChaine("Entrainement", 30, 30 * Ux, 37 * Uy);
    afficheChaine("Retour", 30, 79 * Ux, 8 * Uy);
}
void AfficheRegles(Data *const data)
{
    epaisseurDeTrait(3);
    bouton(data->page.select[0], 25 * Ux, 75 * Uy, 75 * Ux, 92 * Uy); //titre                                                             //titre
    bouton(data->page.select[1], 75 * Ux, 5 * Uy, 95 * Ux, 15 * Uy);
    epaisseurDeTrait(2);
    CC_BLANC;
    afficheChaine("Reglement", 60, 31 * Ux, 79 * Uy);
    afficheChaine("Le concept original de pong est une simulation simpliste ", 20, 10 * Ux, 58 * Uy);
    afficheChaine("de tennis de table, les deux joueurs se passent la balle ", 20, 10 * Ux, 50 * Uy);
    afficheChaine("a l'aide de raquettes, le joueur ayant le plus de points", 20, 10 * Ux, 42 * Uy);
    afficheChaine("gagne la partie.", 20, 10 * Ux, 34 * Uy);
    afficheChaine("Retour", 30, 79 * Ux, 8 * Uy);
}
void AfficheSelection(Data *const data)
{
    afficheUsers(data->page.select, data->users);
    bouton(data->page.select[10], 30 * Ux, 5 * Uy, 70 * Ux, 15 * Uy); //titre
    bouton(data->page.select[11], 75 * Ux, 5 * Uy, 95 * Ux, 15 * Uy);
    epaisseurDeTrait(2);
    CC_BLANC;
    afficheChaine("Jouer", 30, 45 * Ux, 8 * Uy);
    afficheChaine("Retour", 30, 79 * Ux, 8 * Uy);
}
void AfficheJeu(Data *const data)
{
    CC_BLANC;
    epaisseurDeTrait(8);
    afficheChaine("PONG", 95, 31 * Ux, 85 * Uy);
    int teinte = (data->page.pause) ? 150 : 255;
    rouage(88 * Ux, 91 * Uy, r_Rouage);
    plateau(teinte);
    for (int i = 0; i < NB_JOUEUR; i++)
        raquette(data->joueurs[i].raquette, teinte);
    score(data->joueurs[0].score, 43 * Ux, 76 * Uy);
    score(data->joueurs[1].score, 61 * Ux, 76 * Uy);
    balle(data->balleJeu, teinte);
    if (data->page.pause)
        affichePause(data->page.select);
}
void AfficheEntrainement(Data *const data)
{
    CC_BLANC;
    epaisseurDeTrait(8);
    afficheChaine("PONG", 95, 31 * Ux, 85 * Uy);
    rouage(88 * Ux, 91 * Uy, r_Rouage);
    int teinte = (data->page.pause) ? 150 : 255;
    plateau(teinte);
    raquette(data->joueurs[0].raquette, teinte);
    balle(data->balleJeu, teinte);
    if (data->page.pause)
        affichePause(data->page.select);
}