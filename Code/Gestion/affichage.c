#include "gestion.h"

void AfficheAccueil(Data *const data)
{
    couleurCourante(255, 0, 0);
    for (int i = 0; i < MAX_BALLE; i++)
        cercle(data->balle[i].x, data->balle[i].y, data->balle[i].r);

    epaisseurDeTrait(3);
    couleurCourante(data->page.select[0].couleur[0], data->page.select[0].couleur[1], data->page.select[0].couleur[2]);
    rectangle(
        5 * largeurFenetre() / 16, 16 * hauteurFenetre() / 24,
        11 * largeurFenetre() / 16, 19 * hauteurFenetre() / 24); //jouer
    couleurCourante(data->page.select[1].couleur[0], data->page.select[1].couleur[1], data->page.select[1].couleur[2]);
    rectangle(
        11 * largeurFenetre() / 32, 11 * hauteurFenetre() / 24,
        21 * largeurFenetre() / 32, 14 * hauteurFenetre() / 24); //reglement
    couleurCourante(data->page.select[2].couleur[0], data->page.select[2].couleur[1], data->page.select[2].couleur[2]);
    rectangle(
        3 * largeurFenetre() / 4, hauteurFenetre() / 12,
        15 * largeurFenetre() / 16, hauteurFenetre() / 6); //Quitter

    couleurCourante(0, 0, 0);
    rectangle(
        5 * largeurFenetre() / 16 + data->page.select[0].largeur, 2 * hauteurFenetre() / 3 + data->page.select[0].largeur,
        11 * largeurFenetre() / 16 - data->page.select[0].largeur, 19 * hauteurFenetre() / 24 - data->page.select[0].largeur); //jouer
    rectangle(
        11 * largeurFenetre() / 32 + data->page.select[1].largeur, 11 * hauteurFenetre() / 24 + data->page.select[1].largeur,
        21 * largeurFenetre() / 32 - data->page.select[1].largeur, 14 * hauteurFenetre() / 24 - data->page.select[1].largeur); //reglement
    rectangle(
        3 * largeurFenetre() / 4 + data->page.select[2].largeur, hauteurFenetre() / 12 + data->page.select[2].largeur,
        15 * largeurFenetre() / 16 - data->page.select[2].largeur, hauteurFenetre() / 6 - data->page.select[2].largeur); //Quitter

    couleurCourante(255, 255, 255);
    afficheChaine("Jouer", 60, 13 * largeurFenetre() / 32, 83 * hauteurFenetre() / 120);
    afficheChaine("Reglement", 40, 3 * largeurFenetre() / 8, hauteurFenetre() / 2);
    afficheChaine("Quitter", 30, 31 * largeurFenetre() / 40, hauteurFenetre() / 10);
}
void AfficheMenu(Data *const data)
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
        9 * largeurFenetre() / 32 + data->page.select[0].largeur, 2 * hauteurFenetre() / 3 + data->page.select[0].largeur,
        24 * largeurFenetre() / 32 - data->page.select[0].largeur, 19 * hauteurFenetre() / 24 - data->page.select[0].largeur); //JcJ
    rectangle(
        9 * largeurFenetre() / 32 + data->page.select[1].largeur, hauteurFenetre() / 2 + data->page.select[1].largeur,
        24 * largeurFenetre() / 32 - data->page.select[1].largeur, 15 * hauteurFenetre() / 24 - data->page.select[1].largeur); //contreIA
    rectangle(
        9 * largeurFenetre() / 32 + data->page.select[2].largeur, hauteurFenetre() / 3 + data->page.select[2].largeur,
        24 * largeurFenetre() / 32 - data->page.select[2].largeur, 11 * hauteurFenetre() / 24 - data->page.select[2].largeur); //entrainement
    rectangle(
        3 * largeurFenetre() / 4 + data->page.select[3].largeur, hauteurFenetre() / 12 + data->page.select[3].largeur,
        15 * largeurFenetre() / 16 - data->page.select[3].largeur, hauteurFenetre() / 6 - data->page.select[3].largeur); //Quitter
    couleurCourante(255, 255, 255);
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
    couleurCourante(255, 255, 255);
    rectangle(
        2 * largeurFenetre() / 8, 9 * hauteurFenetre() / 12,
        3 * largeurFenetre() / 4, 11 * hauteurFenetre() / 12); //titre
    couleurCourante(data->page.select[0].couleur[0], data->page.select[0].couleur[1], data->page.select[0].couleur[2]);
    rectangle(
        3 * largeurFenetre() / 4, hauteurFenetre() / 12,
        15 * largeurFenetre() / 16, hauteurFenetre() / 6); //Retour
    couleurCourante(0, 0, 0);
    rectangle(
        2 * largeurFenetre() / 8 + 1, 9 * hauteurFenetre() / 12 + 1,
        3 * largeurFenetre() / 4 - 1, 11 * hauteurFenetre() / 12 - 1); //titre
    rectangle(
        3 * largeurFenetre() / 4 + data->page.select[0].largeur, hauteurFenetre() / 12 + data->page.select[0].largeur,
        15 * largeurFenetre() / 16 - data->page.select[0].largeur, hauteurFenetre() / 6 - data->page.select[0].largeur); //Retour
    epaisseurDeTrait(2);
    couleurCourante(255, 255, 255);
    afficheChaine("Retour", 30, 31 * largeurFenetre() / 40, hauteurFenetre() / 10);
    afficheChaine("Reglement", 60, 5 * largeurFenetre() / 16, 19 * hauteurFenetre() / 24);
    afficheChaine("Le concept original de pong est une simulation simpliste ", 20, largeurFenetre() / 10, 7 * hauteurFenetre() / 12);
    afficheChaine("de tennis de table, les deux joueurs se passent la balle ", 20, largeurFenetre() / 10, 6 * hauteurFenetre() / 12);
    afficheChaine("a l'aide de raquettes, le joueur ayant le plus de points", 20, largeurFenetre() / 10, 5 * hauteurFenetre() / 12);
    afficheChaine("gagne la partie.", 20, largeurFenetre() / 10, 4 * hauteurFenetre() / 12);
}
void AfficheSelection(Data *const data)
{

    for (int i = 0; i < 5; i++)
    {
        couleurCourante(data->page.select[2 * i].couleur[0], data->page.select[2 * i].couleur[1], data->page.select[2 * i].couleur[2]);
        rectangle(
            largeurFenetre() / 30 + 6 * i * largeurFenetre() / 30, 99 * hauteurFenetre() / 120,
            5 * largeurFenetre() / 30 + 6 * i * largeurFenetre() / 30, 99 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30);
        couleurCourante(data->page.select[2 * i + 1].couleur[0], data->page.select[2 * i + 1].couleur[1], data->page.select[2 * i + 1].couleur[2]);
        rectangle(
            largeurFenetre() / 30 + 6 * i * largeurFenetre() / 30, 59 * hauteurFenetre() / 120,
            5 * largeurFenetre() / 30 + 6 * i * largeurFenetre() / 30, 59 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30);
    }
    couleurCourante(data->page.select[10].couleur[0],data->page.select[10].couleur[1],data->page.select[10].couleur[2]);
    rectangle(
        5 * largeurFenetre() / 16, hauteurFenetre() / 12,
        11 * largeurFenetre() / 16, hauteurFenetre() / 6);
    couleurCourante(data->page.select[11].couleur[0],data->page.select[11].couleur[1],data->page.select[11].couleur[2]);
    rectangle(
        3 * largeurFenetre() / 4, hauteurFenetre() / 12,
        15 * largeurFenetre() / 16, hauteurFenetre() / 6);
    couleurCourante(0, 0, 0);
    for (int i = 0; i < 5; i++)
    {
        rectangle(
            largeurFenetre() / 30 + 6 * i * largeurFenetre() / 30 + data->page.select[2 * i].largeur, 99 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 + data->page.select[2 * i].largeur,
            5 * largeurFenetre() / 30 + 6 * i * largeurFenetre() / 30 - data->page.select[2 * i].largeur, 99 * hauteurFenetre() / 120 - data->page.select[2 * i].largeur);
        rectangle(
            largeurFenetre() / 30 + 6 * i * largeurFenetre() / 30 + data->page.select[2 * i + 1].largeur, 59 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 + data->page.select[2 * i + 1].largeur,
            5 * largeurFenetre() / 30 + 6 * i * largeurFenetre() / 30 - data->page.select[2 * i + 1].largeur, 59 * hauteurFenetre() / 120 - data->page.select[2 * i + 1].largeur);
    }
    rectangle(
        5 * largeurFenetre() / 16 + data->page.select[10].largeur, hauteurFenetre() / 12 + data->page.select[10].largeur,
        11 * largeurFenetre() / 16 - data->page.select[10].largeur, hauteurFenetre() / 6 - data->page.select[10].largeur);
    rectangle(
        3 * largeurFenetre() / 4 + data->page.select[11].largeur, hauteurFenetre() / 12 + data->page.select[11].largeur,
        15 * largeurFenetre() / 16 - data->page.select[11].largeur, hauteurFenetre() / 6 - data->page.select[11].largeur);
    couleurCourante(255, 255, 255);
    afficheUsers(data->users);
    epaisseurDeTrait(2);
    afficheChaine("Jouer", 30, 18 * largeurFenetre() / 40, hauteurFenetre() / 10);
    afficheChaine("Retour", 30, 31 * largeurFenetre() / 40, hauteurFenetre() / 10);
}
void AfficheJeu(Data *const data)
{
    couleurCourante(255, 255, 255);
    epaisseurDeTrait(8);
    afficheChaine("PONG", 95, 5 * largeurFenetre() / 16 + 1, 20.5 * hauteurFenetre() / 24 + 1);
    rouage(7 * largeurFenetre() / 8, 29 * hauteurFenetre() / 32, largeurFenetre() / 30);
    int teinte = (data->page.pause) ? 150 : 255;
    plateau(teinte);
    for (int i = 0; i < NB_JOUEUR; i++)
    {
        raquette(data->joueurs[i].raquette, teinte);
        score(data->joueurs[i].score, i, teinte);
    }
    balle(data->balleJeu, teinte);
    if (data->page.pause)
        affichePause(data->page.select);
}
void AfficheJeuIA(Data *const data)
{
    couleurCourante(255, 255, 255);
    epaisseurDeTrait(8);
    afficheChaine("PONG", 95, 5 * largeurFenetre() / 16 + 1, 20.5 * hauteurFenetre() / 24 + 1);
    rouage(7 * largeurFenetre() / 8, 29 * hauteurFenetre() / 32, largeurFenetre() / 30);
    int teinte = (data->page.pause) ? 150 : 255;
    plateau(teinte);
    for (int i = 0; i < NB_JOUEUR; i++)
    {
        raquette(data->joueurs[i].raquette, teinte);
        score(data->joueurs[i].score, i, teinte);
    }
    balle(data->balleJeu, teinte);
    if (data->page.pause)
        affichePause(data->page.select);
}
void AfficheEntrainement(Data *const data)
{
    couleurCourante(255, 255, 255);
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