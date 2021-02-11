#include "gestion.h"

void AfficheAccueil(Data *data) //Affichage page d'accueil
{
    couleurCourante(255, 0, 0);
    for (int i = 0; i < MAX_BALLE; i++)
        cercle(data->balle[i].x, data->balle[i].y, data->balle[i].r);

    epaisseurDeTrait(3);
    couleurCourante(255, 255, 255);
    rectangle(
        5 * largeurFenetre() / 16, 16 * hauteurFenetre() / 24,
        11 * largeurFenetre() / 16, 19 * hauteurFenetre() / 24); //jouer
    rectangle(
        11 * largeurFenetre() / 32, 11 * hauteurFenetre() / 24,
        21 * largeurFenetre() / 32, 14 * hauteurFenetre() / 24); //reglement
    rectangle(
        3 * largeurFenetre() / 4, hauteurFenetre() / 12,
        15 * largeurFenetre() / 16, hauteurFenetre() / 6); //Quitter

    couleurCourante(0, 0, 0);
    rectangle(
        5 * largeurFenetre() / 16 + data->page->select[0], 2 * hauteurFenetre() / 3 + data->page->select[0],
        11 * largeurFenetre() / 16 - data->page->select[0], 19 * hauteurFenetre() / 24 - data->page->select[0]); //jouer
    rectangle(
        11 * largeurFenetre() / 32 + data->page->select[1], 11 * hauteurFenetre() / 24 + data->page->select[1],
        21 * largeurFenetre() / 32 - data->page->select[1], 14 * hauteurFenetre() / 24 - data->page->select[1]); //reglement
    rectangle(
        3 * largeurFenetre() / 4 + data->page->select[2], hauteurFenetre() / 12 + data->page->select[2],
        15 * largeurFenetre() / 16 - data->page->select[2], hauteurFenetre() / 6 - data->page->select[2]); //Quitter

    couleurCourante(255, 255, 255);
    afficheChaine("Jouer", 60, 13 * largeurFenetre() / 32, 83 * hauteurFenetre() / 120);
    afficheChaine("Reglement", 40, 3 * largeurFenetre() / 8, hauteurFenetre() / 2);
    afficheChaine("Quitter", 30, 31 * largeurFenetre() / 40, hauteurFenetre() / 10);
}

void AfficheMenu(Data *data)
{
    couleurCourante(rand() % 255, rand() % 255, rand() % 255);
    for (int i = 0; i < MAX_BALLE; i++)
        cercle(data->balle[i].x, data->balle[i].y, data->balle[i].r);

    epaisseurDeTrait(3);
    couleurCourante(rand() % 255, rand() % 255, rand() % 255);
    rectangle(
        9 * largeurFenetre() / 32, 16 * hauteurFenetre() / 24,
        24 * largeurFenetre() / 32, 19 * hauteurFenetre() / 24); //JcJ
    rectangle(
        9 * largeurFenetre() / 32, hauteurFenetre() / 2,
        24 * largeurFenetre() / 32, 15 * hauteurFenetre() / 24); //contreIA
    rectangle(
        9 * largeurFenetre() / 32, hauteurFenetre() / 3,
        24 * largeurFenetre() / 32, 11 * hauteurFenetre() / 24); //entrainement
    rectangle(
        3 * largeurFenetre() / 4, hauteurFenetre() / 12,
        15 * largeurFenetre() / 16, hauteurFenetre() / 6); //Quitter

    couleurCourante(0, 0, 0);
    rectangle(
        9 * largeurFenetre() / 32 + data->page->select[0], 2 * hauteurFenetre() / 3 + data->page->select[0],
        24 * largeurFenetre() / 32 - data->page->select[0], 19 * hauteurFenetre() / 24 - data->page->select[0]); //JcJ
    rectangle(
        9 * largeurFenetre() / 32 + data->page->select[1], hauteurFenetre() / 2 + data->page->select[1],
        24 * largeurFenetre() / 32 - data->page->select[1], 15 * hauteurFenetre() / 24 - data->page->select[1]); //contreIA
    rectangle(
        9 * largeurFenetre() / 32 + data->page->select[2], hauteurFenetre() / 3 + data->page->select[2],
        24 * largeurFenetre() / 32 - data->page->select[2], 11 * hauteurFenetre() / 24 - data->page->select[2]); //entrainement
    rectangle(
        3 * largeurFenetre() / 4 + data->page->select[3], hauteurFenetre() / 12 + data->page->select[3],
        15 * largeurFenetre() / 16 - data->page->select[3], hauteurFenetre() / 6 - data->page->select[3]); //Quitter
    couleurCourante(255, 255, 255);
    afficheChaine("Joueur contre joueur", 30, 5 * largeurFenetre() / 16, 17 * hauteurFenetre() / 24);
    afficheChaine("Jouer contre IA", 30, 5 * largeurFenetre() / 16, 13 * hauteurFenetre() / 24);
    afficheChaine("Entrainement", 30, 5 * largeurFenetre() / 16, 9 * hauteurFenetre() / 24);
    afficheChaine("Retour", 30, 31 * largeurFenetre() / 40, hauteurFenetre() / 10);
    couleurCourante(rand() % 255, rand() % 255, rand() % 255);
    epaisseurDeTrait(8);
    afficheChaine("PONG", 60, 13 * largeurFenetre() / 32, 21 * hauteurFenetre() / 24);
}

void AfficheRegles(Data *data)
{
    epaisseurDeTrait(3);
    couleurCourante(255, 255, 255);
    rectangle(
        2 * largeurFenetre() / 8, 9 * hauteurFenetre() / 12,
        3 * largeurFenetre() / 4, 11 * hauteurFenetre() / 12); //titre
    rectangle(
        3 * largeurFenetre() / 4, hauteurFenetre() / 12,
        15 * largeurFenetre() / 16, hauteurFenetre() / 6); //Retour
    couleurCourante(0, 0, 0);
    rectangle(
        2 * largeurFenetre() / 8 + 1, 9 * hauteurFenetre() / 12 + 1,
        3 * largeurFenetre() / 4 - 1, 11 * hauteurFenetre() / 12 - 1); //titre
    rectangle(
        3 * largeurFenetre() / 4 + data->page->select[0], hauteurFenetre() / 12 + data->page->select[0],
        15 * largeurFenetre() / 16 - data->page->select[0], hauteurFenetre() / 6 - data->page->select[0]); //Retour
    epaisseurDeTrait(2);
    couleurCourante(255, 255, 255);
    afficheChaine("Retour", 30, 31 * largeurFenetre() / 40, hauteurFenetre() / 10);
    afficheChaine("Reglement", 60, 5 * largeurFenetre() / 16, 19 * hauteurFenetre() / 24);
    afficheChaine("Le concept original de pong est une simulation simpliste ", 20, largeurFenetre() / 10, 7 * hauteurFenetre() / 12);
    afficheChaine("de tennis de table, les deux joueurs se passent la balle ", 20, largeurFenetre() / 10, 6 * hauteurFenetre() / 12);
    afficheChaine("a l'aide de raquettes, le joueur ayant le plus de points", 20, largeurFenetre() / 10, 5 * hauteurFenetre() / 12);
    afficheChaine("gagne la partie.", 20, largeurFenetre() / 10, 4 * hauteurFenetre() / 12);
}
void AfficheJeu(Data *data)
{
    couleurCourante(255, 255, 255);
    epaisseurDeTrait(8);
    afficheChaine("PONG", 95, 5 * largeurFenetre() / 16 + 1, 20.5 * hauteurFenetre() / 24 + 1);
    int teinte = (data->page->pause) ? 150 : 255;
    plateau(teinte,data->page->select);
    for (int i = 0; i < NB_RAQUETTE; i++)
    {
        raquette(data->raquette[i], teinte);
        score(data->score[i], i, teinte);
    }
    balle(data->balleJeu, teinte);
    if (data->page->pause)
        affichePause(data->page->select);
}
void AfficheJeuIA(Data *data)
{
    couleurCourante(255, 255, 255);
    epaisseurDeTrait(8);
    afficheChaine("PONG", 95, 5 * largeurFenetre() / 16 + 1, 20.5 * hauteurFenetre() / 24 + 1);
    int teinte = (data->page->pause) ? 150 : 255;
    plateau(teinte,data->page->select);
    for (int i = 0; i < NB_RAQUETTE; i++)
    {
        raquette(data->raquette[i], teinte);
        score(data->score[i], i, teinte);
    }
    balle(data->balleJeu, teinte);
    if (data->page->pause)
        affichePause(data->page->select);
}
void AfficheEntrainement(Data *data)
{
    couleurCourante(255, 255, 255);
    epaisseurDeTrait(8);
    afficheChaine("PONG", 95, 5 * largeurFenetre() / 16 + 1, 20.5 * hauteurFenetre() / 24 + 1);
    int teinte = (data->page->pause) ? 150 : 255;
    plateau(teinte,data->page->select);
    raquette(data->raquette[0], teinte);
    balle(data->balleJeu, teinte);
    if (data->page->pause)
        affichePause(data->page->select);
}
void affichePause(int *select)
{
    couleurCourante(255, 255, 255);
    epaisseurDeTrait(3);
    ligne(3 * largeurFenetre() / 10, hauteurFenetre() / 10, 3 * largeurFenetre() / 10, 7 * hauteurFenetre() / 10);
    ligne(3 * largeurFenetre() / 10, 7 * hauteurFenetre() / 10, 7 * largeurFenetre() / 10, 7 * hauteurFenetre() / 10);
    ligne(7 * largeurFenetre() / 10, 7 * hauteurFenetre() / 10, 7 * largeurFenetre() / 10, hauteurFenetre() / 10);
    ligne(7 * largeurFenetre() / 10, hauteurFenetre() / 10, 3 * largeurFenetre() / 10, hauteurFenetre() / 10);
    rectangle(7 * largeurFenetre() / 20, 11 * hauteurFenetre() / 20, 13 * largeurFenetre() / 20, 13 * hauteurFenetre() / 20);
    rectangle(7 * largeurFenetre() / 20, 7 * hauteurFenetre() / 20, 13 * largeurFenetre() / 20, 9 * hauteurFenetre() / 20);
    rectangle(7 * largeurFenetre() / 20, 3 * hauteurFenetre() / 20, 13 * largeurFenetre() / 20, 5 * hauteurFenetre() / 20);
    couleurCourante(0, 0, 0);
    rectangle(7 * largeurFenetre() / 20 + select[0], 11 * hauteurFenetre() / 20 + select[0], 13 * largeurFenetre() / 20 - select[0], 13 * hauteurFenetre() / 20 - select[0]);
    rectangle(7 * largeurFenetre() / 20 + select[1], 7 * hauteurFenetre() / 20 + select[1], 13 * largeurFenetre() / 20 - select[1], 9 * hauteurFenetre() / 20 - select[1]);
    rectangle(7 * largeurFenetre() / 20 + select[2], 3 * hauteurFenetre() / 20 + select[2], 13 * largeurFenetre() / 20 - select[2], 5 * hauteurFenetre() / 20 - select[2]);
    couleurCourante(255, 255, 255);
    afficheChaine("Reprendre", 30, 5 * MID_X / 6, 23 * hauteurFenetre() / 40);
    afficheChaine("Rejouer", 30, 21 * MID_X / 24, 15 * hauteurFenetre() / 40);
    afficheChaine("Quitter", 30, 21 * MID_X / 24, 7 * hauteurFenetre() / 40);
}
void plateau(int teinte, int *select)
{
    couleurCourante(teinte, teinte, teinte);
    rectangle(
        largeurFenetre() / 40, MIN_Y_PLATEAU / 2,
        39 * largeurFenetre() / 40, MAX_Y_PLATEAU + MIN_Y_PLATEAU / 2);
    rectangle(3 * largeurFenetre() / 4, 5 * hauteurFenetre() / 6,15 * largeurFenetre() / 16 , 11 * hauteurFenetre() / 12);    
    couleurCourante(0, 0, 0);
    rectangle(
        MIN_X_PLATEAU, MIN_Y_PLATEAU,
        MAX_X_PLATEAU, MAX_Y_PLATEAU);
    rectangle(3 * largeurFenetre() / 4  + select[4], 5 * hauteurFenetre() / 6 + select[4], 15 * largeurFenetre() / 16  - select[4] , 11 * hauteurFenetre() / 12 - select[4]);
    couleurCourante(teinte, teinte, teinte);
    epaisseurDeTrait(3);
    afficheChaine("Pause", 30, 3 * largeurFenetre() / 4+30,  5 * hauteurFenetre() / 6+13);
    for (int i = 0; i < 10; i++)
        ligne(
            MID_X, 100 * hauteurFenetre() / 120 - 10 * i * hauteurFenetre() / 120,
            MID_X, 91 * hauteurFenetre() / 120 - 10 * i * hauteurFenetre() / 120);
}

void raquette(Raquette raquette, int teinte)
{
    couleurCourante(teinte, teinte, teinte);
    rectangle(
        raquette.x - raquette.largeur / 2, raquette.y + raquette.longueur / 2,
        raquette.x + raquette.largeur / 2, raquette.y - raquette.longueur / 2);
}

void balle(Balle *balleJeu, int teinte)
{
    couleurCourante(teinte, teinte, teinte);
    cercle(balleJeu->x, balleJeu->y, balleJeu->r);
}

void score(int score, bool side, int teinte)
{
    bool digit[2][7];
    nombre(score - 10 * floor(score / 10), digit[0]);
    nombre(floor(score / 10), digit[1]);
    epaisseurDeTrait(5);
    for (int i = 0; i < 2; i++)
        afficheDigit(digit[i], side, i, teinte);
}

void afficheDigit(bool *digit, bool side, int i, int teinte)
{
    //digit 2
    (digit[1]) ? couleurCourante(teinte, teinte, teinte) : couleurCourante(0, 0, 0);
    ligne(
        MID_X - i * largeurFenetre() / 25 + ((side) ? 6 * largeurFenetre() / 100 : -4 * largeurFenetre() / 100), 3 * hauteurFenetre() / 4 + largeurFenetre() / 50,
        MID_X - i * largeurFenetre() / 25 + ((side) ? 6 * largeurFenetre() / 100 : -4 * largeurFenetre() / 100), 3 * hauteurFenetre() / 4);
    //digit 3
    (digit[2]) ? couleurCourante(teinte, teinte, teinte) : couleurCourante(0, 0, 0);
    ligne(
        MID_X - i * largeurFenetre() / 25 + ((side) ? 8 * largeurFenetre() / 100 : -2 * largeurFenetre() / 100), 3 * hauteurFenetre() / 4,
        MID_X - i * largeurFenetre() / 25 + ((side) ? 8 * largeurFenetre() / 100 : -2 * largeurFenetre() / 100), 3 * hauteurFenetre() / 4 + largeurFenetre() / 50);
    //digit 5
    (digit[4]) ? couleurCourante(teinte, teinte, teinte) : couleurCourante(0, 0, 0);
    ligne(
        MID_X - i * largeurFenetre() / 25 + ((side) ? 6 * largeurFenetre() / 100 : -4 * largeurFenetre() / 100), 3 * hauteurFenetre() / 4,
        MID_X - i * largeurFenetre() / 25 + ((side) ? 6 * largeurFenetre() / 100 : -4 * largeurFenetre() / 100), 3 * hauteurFenetre() / 4 - largeurFenetre() / 50);
    //digit 6
    (digit[5]) ? couleurCourante(teinte, teinte, teinte) : couleurCourante(0, 0, 0);
    ligne(
        MID_X - i * largeurFenetre() / 25 + ((side) ? 8 * largeurFenetre() / 100 : -2 * largeurFenetre() / 100), 3 * hauteurFenetre() / 4,
        MID_X - i * largeurFenetre() / 25 + ((side) ? 8 * largeurFenetre() / 100 : -2 * largeurFenetre() / 100), 3 * hauteurFenetre() / 4 - largeurFenetre() / 50);
    //digit 1
    (digit[0]) ? couleurCourante(teinte, teinte, teinte) : couleurCourante(0, 0, 0);
    ligne(
        MID_X - i * largeurFenetre() / 25 + ((side) ? 6 * largeurFenetre() / 100 : -4 * largeurFenetre() / 100), 3 * hauteurFenetre() / 4 + largeurFenetre() / 50,
        MID_X - i * largeurFenetre() / 25 + ((side) ? 8 * largeurFenetre() / 100 : -2 * largeurFenetre() / 100), 3 * hauteurFenetre() / 4 + largeurFenetre() / 50);
    //digit 4
    (digit[3]) ? couleurCourante(teinte, teinte, teinte) : couleurCourante(0, 0, 0);
    ligne(
        MID_X - i * largeurFenetre() / 25 + ((side) ? 6 * largeurFenetre() / 100 : -4 * largeurFenetre() / 100), 3 * hauteurFenetre() / 4,
        MID_X - i * largeurFenetre() / 25 + ((side) ? 8 * largeurFenetre() / 100 : -2 * largeurFenetre() / 100), 3 * hauteurFenetre() / 4);
    //digit 7
    (digit[6]) ? couleurCourante(teinte, teinte, teinte) : couleurCourante(0, 0, 0);
    ligne(
        MID_X - i * largeurFenetre() / 25 + ((side) ? 6 * largeurFenetre() / 100 : -4 * largeurFenetre() / 100), 3 * hauteurFenetre() / 4 - largeurFenetre() / 50,
        MID_X - i * largeurFenetre() / 25 + ((side) ? 8 * largeurFenetre() / 100 : -2 * largeurFenetre() / 100), 3 * hauteurFenetre() / 4 - largeurFenetre() / 50);
}
