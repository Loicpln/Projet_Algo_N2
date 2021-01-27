#include "gestion.h"

void AfficheAccueil(Data *data) //Affichage page d'accueil
{
    couleurCourante(255, 0, 0);
    for (int i = 0; i < MAX_BALLE; i++)
        cercle(data->balle[i].x, data->balle[i].y, data->balle[i].r);

    epaisseurDeTrait(3);
    couleurCourante(255, 255, 255);
    rectangle(
        3 * largeurFenetre() / 4, hauteurFenetre() / 12,
        15 * largeurFenetre() / 16, hauteurFenetre() / 6); //Quitter
    rectangle(
        5 * largeurFenetre() / 16, 16 * hauteurFenetre() / 24,
        11 * largeurFenetre() / 16, 19 * hauteurFenetre() / 24); //jouer
    rectangle(
        11 * largeurFenetre() / 32, 11 * hauteurFenetre() / 24,
        21 * largeurFenetre() / 32, 14 * hauteurFenetre() / 24); //reglement

    couleurCourante(0, 0, 0);
    rectangle(
        3 * largeurFenetre() / 4 + 1, hauteurFenetre() / 12 + 1,
        15 * largeurFenetre() / 16 - 1, hauteurFenetre() / 6 - 1); //Quitter
    rectangle(
        5 * largeurFenetre() / 16 + 1, 2 * hauteurFenetre() / 3 + 1,
        11 * largeurFenetre() / 16 - 1, 19 * hauteurFenetre() / 24 - 1); //jouer
    rectangle(
        11 * largeurFenetre() / 32 + 1, 11 * hauteurFenetre() / 24 + 1,
        21 * largeurFenetre() / 32 - 1, 14 * hauteurFenetre() / 24 - 1); //reglement

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
        9 * largeurFenetre() / 32 + 1, 2 * hauteurFenetre() / 3 + 1,
        24 * largeurFenetre() / 32 - 1, 19 * hauteurFenetre() / 24 - 1); //JcJ
    rectangle(
        9 * largeurFenetre() / 32 + 1, hauteurFenetre() / 2 + 1,
        24 * largeurFenetre() / 32 - 1, 15 * hauteurFenetre() / 24 - 1); //contreIA
    rectangle(
        9 * largeurFenetre() / 32 + 1, hauteurFenetre() / 3 + 1,
        24 * largeurFenetre() / 32 - 1, 11 * hauteurFenetre() / 24 - 1); //entrainement
    rectangle(
        3 * largeurFenetre() / 4 + 1, hauteurFenetre() / 12 + 1,
        15 * largeurFenetre() / 16 - 1, hauteurFenetre() / 6 - 1); //Quitter
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
        3 * largeurFenetre() / 4 + 1, hauteurFenetre() / 12 + 1,
        15 * largeurFenetre() / 16 - 1, hauteurFenetre() / 6 - 1); //Retour
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
    plateau();
    for (int i = 0; i < NB_RAQUETTE; i++)
        raquette(data->raquette[i]);
    score(data->score[0], true);
    score(data->score[1], false);
    balle(data->balleJeu);
}

void plateau()
{
    couleurCourante(255, 255, 255);
    rectangle(
        largeurFenetre() / 40, MIN_Y_PLATEAU / 2,
        39 * largeurFenetre() / 40, MAX_Y_PLATEAU + MIN_Y_PLATEAU / 2);
    couleurCourante(0, 0, 0);
    rectangle(
        MIN_X_PLATEAU, MIN_Y_PLATEAU,
        MAX_X_PLATEAU, MAX_Y_PLATEAU);
    couleurCourante(255, 255, 255);
    epaisseurDeTrait(3);
    for (int i = 0; i < 10; i++)
        ligne(
            MID_X, 100 * hauteurFenetre() / 120 - 10 * i * hauteurFenetre() / 120,
            MID_X, 91 * hauteurFenetre() / 120 - 10 * i * hauteurFenetre() / 120);
    epaisseurDeTrait(8);
    couleurCourante(255, 255, 255);
    afficheChaine("PONG", 95, 5 * largeurFenetre() / 16 + 1, 20.5 * hauteurFenetre() / 24 + 1);
}

void raquette(Raquette raquette)
{
    couleurCourante(255, 255, 255); // Raquette gauche
    rectangle(
        (raquette.side) ? largeurFenetre() / 30 + 10 - raquette.largeur / 2 : 29 * largeurFenetre() / 30 - 10 - raquette.largeur / 2,
        raquette.centre + raquette.longueur / 2,
        (raquette.side) ? largeurFenetre() / 30 + 10 + raquette.largeur / 2 : 29 * largeurFenetre() / 30 - 10 + raquette.largeur / 2,
        raquette.centre - raquette.longueur / 2);
}

void balle(Balle *balleJeu)
{
    couleurCourante(255, 255, 255);
    cercle(balleJeu->x, balleJeu->y, balleJeu->r);
}

void score(int score, bool side)
{
    bool dizaine[7];
    bool unite[7];
    nombre(floor(score / 10), dizaine);
    nombre(score - 10 * floor(score / 10), unite);
    couleurCourante(255, 255, 255);
    epaisseurDeTrait(5);
    //digit 2
    (dizaine[1]) ? couleurCourante(255, 255, 255) : couleurCourante(0, 0, 0);
    ligne(
        (side) ? MID_X - 8 * largeurFenetre() / 100 : MID_X + 2 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4 + largeurFenetre() / 50,
        (side) ? MID_X - 8 * largeurFenetre() / 100 : MID_X + 2 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4);
    //dizaine 3
    (dizaine[2]) ? couleurCourante(255, 255, 255) : couleurCourante(0, 0, 0);
    ligne(
        (side) ? MID_X - 6 * largeurFenetre() / 100 : MID_X + 4 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4,
        (side) ? MID_X - 6 * largeurFenetre() / 100 : MID_X + 4 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4 + largeurFenetre() / 50);
    //digit 5
    (dizaine[4]) ? couleurCourante(255, 255, 255) : couleurCourante(0, 0, 0);
    ligne(
        (side) ? MID_X - 8 * largeurFenetre() / 100 : MID_X + 2 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4,
        (side) ? MID_X - 8 * largeurFenetre() / 100 : MID_X + 2 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4 - largeurFenetre() / 50);
    //digit 6
    (dizaine[5]) ? couleurCourante(255, 255, 255) : couleurCourante(0, 0, 0);
    ligne(
        (side) ? MID_X - 6 * largeurFenetre() / 100 : MID_X + 4 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4,
        (side) ? MID_X - 6 * largeurFenetre() / 100 : MID_X + 4 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4 - largeurFenetre() / 50);
    //digit 1
    (dizaine[0]) ? couleurCourante(255, 255, 255) : couleurCourante(0, 0, 0);
    ligne(
        (side) ? MID_X - 8 * largeurFenetre() / 100 : MID_X + 4 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4 + largeurFenetre() / 50,
        (side) ? MID_X - 6 * largeurFenetre() / 100 : MID_X + 2 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4 + largeurFenetre() / 50);
    //dizaine 4
    (dizaine[3]) ? couleurCourante(255, 255, 255) : couleurCourante(0, 0, 0);
    ligne(
        (side) ? MID_X - 8 * largeurFenetre() / 100 : MID_X + 4 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4,
        (side) ? MID_X - 6 * largeurFenetre() / 100 : MID_X + 2 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4);
    //digit 7
    (dizaine[6]) ? couleurCourante(255, 255, 255) : couleurCourante(0, 0, 0);
    ligne(
        (side) ? MID_X - 8 * largeurFenetre() / 100 : MID_X + 4 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4 - largeurFenetre() / 50,
        (side) ? MID_X - 6 * largeurFenetre() / 100 : MID_X + 2 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4 - largeurFenetre() / 50);

    //digit 2
    (unite[1]) ? couleurCourante(255, 255, 255) : couleurCourante(0, 0, 0);
    ligne(
        (side) ? MID_X - 4 * largeurFenetre() / 100 : MID_X + 6 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4 + largeurFenetre() / 50,
        (side) ? MID_X - 4 * largeurFenetre() / 100 : MID_X + 6 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4);
    //digit 3
    (unite[2]) ? couleurCourante(255, 255, 255) : couleurCourante(0, 0, 0);
    ligne(
        (side) ? MID_X - 2 * largeurFenetre() / 100 : MID_X + 8 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4,
        (side) ? MID_X - 2 * largeurFenetre() / 100 : MID_X + 8 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4 + largeurFenetre() / 50);
    //digit 5
    (unite[4]) ? couleurCourante(255, 255, 255) : couleurCourante(0, 0, 0);
    ligne(
        (side) ? MID_X - 4 * largeurFenetre() / 100 : MID_X + 6 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4,
        (side) ? MID_X - 4 * largeurFenetre() / 100 : MID_X + 6 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4 - largeurFenetre() / 50);
    //digit 6
    (unite[5]) ? couleurCourante(255, 255, 255) : couleurCourante(0, 0, 0);
    ligne(
        (side) ? MID_X - 2 * largeurFenetre() / 100 : MID_X + 8 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4,
        (side) ? MID_X - 2 * largeurFenetre() / 100 : MID_X + 8 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4 - largeurFenetre() / 50);
    //digit 1
    (unite[0]) ? couleurCourante(255, 255, 255) : couleurCourante(0, 0, 0);
    ligne(
        (side) ? MID_X - 4 * largeurFenetre() / 100 : MID_X + 6 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4 + largeurFenetre() / 50,
        (side) ? MID_X - 2 * largeurFenetre() / 100 : MID_X + 8 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4 + largeurFenetre() / 50);
    //digit 4
    (unite[3]) ? couleurCourante(255, 255, 255) : couleurCourante(0, 0, 0);
    ligne(
        (side) ? MID_X - 4 * largeurFenetre() / 100 : MID_X + 6 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4,
        (side) ? MID_X - 2 * largeurFenetre() / 100 : MID_X + 8 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4);
    //digit 7
    (unite[6]) ? couleurCourante(255, 255, 255) : couleurCourante(0, 0, 0);
    ligne(
        (side) ? MID_X - 4 * largeurFenetre() / 100 : MID_X + 6 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4 - largeurFenetre() / 50,
        (side) ? MID_X - 2 * largeurFenetre() / 100 : MID_X + 8 * largeurFenetre() / 100, 3 * hauteurFenetre() / 4 - largeurFenetre() / 50);
}