#include "gestion.h"

void AfficheAccueil(Data *const data)
{
    couleurCourante(255, 0, 0);
    for (int i = 0; i < MAX_BALLE; i++)
        cercle(data->balle[i].x, data->balle[i].y, data->balle[i].r);

    bouton(data->page.select[0], 5 * largeurFenetre() / 16, 16 * hauteurFenetre() / 24, 11 * largeurFenetre() / 16, 19 * hauteurFenetre() / 24);
    bouton(data->page.select[1], 11 * largeurFenetre() / 32, 11 * hauteurFenetre() / 24, 21 * largeurFenetre() / 32, 14 * hauteurFenetre() / 24);
    bouton(data->page.select[2], 3 * largeurFenetre() / 4, hauteurFenetre() / 12, 15 * largeurFenetre() / 16, hauteurFenetre() / 6);
    couleurCourante(data->page.select[2].couleur[0], data->page.select[2].couleur[1], data->page.select[2].couleur[2]);
    epaisseurDeTrait(3);
    CC_BLANC;
    afficheChaine("Jouer", 60, 13 * largeurFenetre() / 32, 83 * hauteurFenetre() / 120);
    afficheChaine("Reglement", 40, 3 * largeurFenetre() / 8, hauteurFenetre() / 2);
    afficheChaine("Quitter", 30, 31 * largeurFenetre() / 40, hauteurFenetre() / 10);
}
void AfficheMenu(Data *const data)
{
    couleurCourante(rand() % 255, rand() % 255, rand() % 255);
    for (int i = 0; i < MAX_BALLE; i++)
        cercle(data->balle[i].x, data->balle[i].y, data->balle[i].r);

    bouton(data->page.select[0], 9 * largeurFenetre() / 32, 16 * hauteurFenetre() / 24, 24 * largeurFenetre() / 32, 19 * hauteurFenetre() / 24); //JcJ
    couleurCourante(data->page.select[1].couleur[0], data->page.select[1].couleur[1], data->page.select[1].couleur[2]);
    bouton(data->page.select[1], 9 * largeurFenetre() / 32, hauteurFenetre() / 2, 24 * largeurFenetre() / 32, 15 * hauteurFenetre() / 24); //contreIA
    bouton(data->page.select[2], 9 * largeurFenetre() / 32, hauteurFenetre() / 3, 24 * largeurFenetre() / 32, 11 * hauteurFenetre() / 24); //entrainement
    bouton(data->page.select[3], 3 * largeurFenetre() / 4, hauteurFenetre() / 12, 15 * largeurFenetre() / 16, hauteurFenetre() / 6);       //Quitter
    epaisseurDeTrait(3);
    CC_BLANC;
    afficheChaine("Joueur contre joueur", 30, 5 * largeurFenetre() / 16, 17 * hauteurFenetre() / 24);
    afficheChaine("Jouer contre IA", 30, 5 * largeurFenetre() / 16, 13 * hauteurFenetre() / 24);
    afficheChaine("Entrainement", 30, 5 * largeurFenetre() / 16, 9 * hauteurFenetre() / 24);
    afficheChaine("Retour", 30, 31 * largeurFenetre() / 40, hauteurFenetre() / 10);
    couleurCourante(rand() % 255, rand() % 255, rand() % 255);
    epaisseurDeTrait(8);
    afficheChaine("PONG", 60, 13 * largeurFenetre() / 32, 21 * hauteurFenetre() / 24);
}
void AfficheRegles(Data *const data)
{
    epaisseurDeTrait(3);
    bouton(data->page.select[0], 2 * largeurFenetre() / 8, 9 * hauteurFenetre() / 12, 3 * largeurFenetre() / 4, 11 * hauteurFenetre() / 12); //titre                                                             //titre
    bouton(data->page.select[1], 3 * largeurFenetre() / 4, hauteurFenetre() / 12, 15 * largeurFenetre() / 16, hauteurFenetre() / 6);         //Retour
    epaisseurDeTrait(2);
    CC_BLANC;
    afficheChaine("Retour", 30, 31 * largeurFenetre() / 40, hauteurFenetre() / 10);
    afficheChaine("Reglement", 60, 5 * largeurFenetre() / 16, 19 * hauteurFenetre() / 24);
    afficheChaine("Le concept original de pong est une simulation simpliste ", 20, largeurFenetre() / 10, 7 * hauteurFenetre() / 12);
    afficheChaine("de tennis de table, les deux joueurs se passent la balle ", 20, largeurFenetre() / 10, 6 * hauteurFenetre() / 12);
    afficheChaine("a l'aide de raquettes, le joueur ayant le plus de points", 20, largeurFenetre() / 10, 5 * hauteurFenetre() / 12);
    afficheChaine("gagne la partie.", 20, largeurFenetre() / 10, 4 * hauteurFenetre() / 12);
}
void AfficheSelection(Data *const data)
{
    afficheUsers(data->page.select, data->users);
    bouton(data->page.select[10], 5 * largeurFenetre() / 16, hauteurFenetre() / 12, 11 * largeurFenetre() / 16, hauteurFenetre() / 6);
    bouton(data->page.select[11], 3 * largeurFenetre() / 4, hauteurFenetre() / 12, 15 * largeurFenetre() / 16, hauteurFenetre() / 6);
    epaisseurDeTrait(2);
    CC_BLANC;
    afficheChaine("Jouer", 30, 18 * largeurFenetre() / 40, hauteurFenetre() / 10);
    afficheChaine("Retour", 30, 31 * largeurFenetre() / 40, hauteurFenetre() / 10);
}
void AfficheJeu(Data *const data)
{
    CC_BLANC;
    epaisseurDeTrait(8);
    afficheChaine("PONG", 95, 5 * largeurFenetre() / 16 + 1, 20.5 * hauteurFenetre() / 24 + 1);
    int teinte = (data->page.pause) ? 150 : 255;
    rouage(7 * largeurFenetre() / 8, 29 * hauteurFenetre() / 32, largeurFenetre() / 30);
    plateau(teinte);
    for (int i = 0; i < NB_JOUEUR; i++)
        raquette(data->joueurs[i].raquette, teinte);
    score(data->joueurs[0].score, MID_X - 7 * largeurFenetre() / 100, MAX_Y_PLATEAU - hauteurFenetre() / 15);
    score(data->joueurs[1].score, MID_X + 11 * largeurFenetre() / 100, MAX_Y_PLATEAU - hauteurFenetre() / 15);
    balle(data->balleJeu, teinte);
    if (data->page.pause)
        affichePause(data->page.select);
}
void AfficheEntrainement(Data *const data)
{
    CC_BLANC;
    epaisseurDeTrait(8);
    afficheChaine("PONG", 95, 5 * largeurFenetre() / 16 + 1, 20.5 * hauteurFenetre() / 24 + 1);
    rouage(7 * largeurFenetre() / 8, 29 * hauteurFenetre() / 32, largeurFenetre() / 30);
    int teinte = (data->page.pause) ? 150 : 255;
    plateau(teinte);
    raquette(data->joueurs[0].raquette, teinte);
    balle(data->balleJeu, teinte);
    if (data->page.pause)
        affichePause(data->page.select);
}