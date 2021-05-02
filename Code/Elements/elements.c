#include "elements.h"

void bouton(const Select select, const int xBasGauche, const int yBasGauche, const int xHautDroite, const int yHautDroite)
{
    couleurCourante(select.couleur[0], select.couleur[1], select.couleur[2]);
    rectangle(xBasGauche, yBasGauche, xHautDroite, yHautDroite);
    CC_NOIR;
    rectangle(xBasGauche + select.largeur, yBasGauche + select.largeur, xHautDroite - select.largeur, yHautDroite - select.largeur);
}

void rouage(const Select select, const int x, const int y, const int r)
{
    epaisseurDeTrait(10);
    couleurCourante(select.couleur[0], select.couleur[1], select.couleur[2]);
    ligne(x - r, y, x + r, y);
    ligne(x - sqrt(2) * r / 2, y - sqrt(2) * r / 2, x + sqrt(2) * r / 2, y + sqrt(2) * r / 2);
    ligne(x, y - r, x, y + r);
    ligne(x - sqrt(2) * r / 2, y + sqrt(2) * r / 2, x + sqrt(2) * r / 2, y - sqrt(2) * r / 2);
    cercle(x, y, 6 * r / 7 - select.largeur / 2);
    couleurCourante(0, 0, 0);
    cercle(x, y, r / 3 + select.largeur / 2);
}

void plus(const int xBasGauche, const int yBasGauche, const int xHautDroite, const int yHautDroite)
{
    EPAISSEUR_TITRE;
    ligne((xBasGauche + xHautDroite) / 2, yBasGauche, (xBasGauche + xHautDroite) / 2, yHautDroite);
    ligne(xBasGauche, (yBasGauche + yHautDroite) / 2, xHautDroite, (yBasGauche + yHautDroite) / 2);
}

void plateau(const int teinte)
{
    couleurCourante(teinte, teinte, teinte);
    rectangle(MIN_X_PLATEAU - Ux, MIN_Y_PLATEAU - Ux, MAX_X_PLATEAU + Ux, MAX_Y_PLATEAU + Ux);
    CC_NOIR;
    rectangle(MIN_X_PLATEAU, MIN_Y_PLATEAU, MAX_X_PLATEAU, MAX_Y_PLATEAU);
    couleurCourante(teinte, teinte, teinte);
    EPAISSEUR_3;
    for (int i = 0; i < 8; i++)
        ligne(MID_X, 82 * Uy - 10 * i * Uy, MID_X, 73 * Uy - 10 * i * Uy);
}

void coeur(const int x, const int y, const float r)
{
    couleurCourante(255, 0, 0);
    rectangle(x - r / 2, y - r / 2, x + r / 2, y);
    cercle(x - r / 2, y, r / 2);
    cercle(x + r / 2, y, r / 2);
    triangle(x, y - r, x - (1 + M_SQRT1_2) * r / 2, y - M_SQRT1_2 * r / 2, x + (1 + M_SQRT1_2) * r / 2, y - M_SQRT1_2 * r / 2);
}

void affichePause(const Select *const select)
{
    CC_BLANC;
    EPAISSEUR_3;
    ligne(30 * Ux, 10 * Uy, 30 * Ux, 70 * Uy);
    ligne(30 * Ux, 70 * Uy, 70 * Ux, 70 * Uy);
    ligne(70 * Ux, 70 * Uy, 70 * Ux, 10 * Uy);
    ligne(70 * Ux, 10 * Uy, 30 * Ux, 10 * Uy);
    bouton(select[0], 35 * Ux, 55 * Uy, 65 * Ux, 65 * Uy);
    bouton(select[1], 35 * Ux, 42 * Uy, 65 * Ux, 52 * Uy);
    bouton(select[3], 35 * Ux, 29 * Uy, 65 * Ux, 39 * Uy);
    bouton(select[2], 35 * Ux, 15 * Uy, 65 * Ux, 25 * Uy);
    CC_BLANC;
    afficheChaine("Reprendre", 30, 41 * Ux, 58 * Uy);
    afficheChaine("Rejouer", 30, 43 * Ux, 45 * Uy);
    afficheChaine("Mutateur", 30, 42 * Ux, 32 * Uy);
    afficheChaine("Quitter", 30, 44 * Ux, 18 * Uy);
}

void zoneText(const Select *const select, const char chaine[])
{
    bouton(select[46], 30 * Ux, 45 * Uy, 70 * Ux, 55 * Uy);
    EPAISSEUR_2;
    CC_BLANC;
    afficheChaine(chaine, 30, MID_X - strlen(chaine) * Ux, 48 * Uy);
}

void raquette(const Raquette raquette, const int teinte)
{
    couleurCourante(teinte, teinte, teinte);
    rectangle(raquette.x - raquette.largeur / 2, raquette.y + raquette.longueur / 2, raquette.x + raquette.largeur / 2, raquette.y - raquette.longueur / 2);
}

void balle(const Balle balleJeu, const int teinte)
{
    couleurCourante(teinte, teinte, teinte);
    cercle(balleJeu.x, balleJeu.y, balleJeu.r);
}

void score(const int score, const int x, const int y)
{
    Digit digit[2] = {nombre(score - 10 * floor(score / 10)), nombre(floor(score / 10))};
    for (int i = 0; i < 2; i++)
        afficheDigit(digit[i], x - 4 * i * Ux, y);
}

void timer(const int temps[], const int x, const int y)
{
    Digit minutes = nombre(temps[0]);
    Digit secondes[2] = {nombre(floor(temps[1] / 10)), nombre(temps[1] - 10 * floor(temps[1] / 10))};
    CC_BLANC;
    cercle(x, y + Uy, 3);
    cercle(x, y - Uy, 3);
    afficheDigit(minutes, x - 4 * Ux, y);
    for (int i = 1; i < 3; i++)
        afficheDigit(secondes[i - 1], x + 4 * i * Ux, y);
}

void afficheDigit(const Digit digit, const int x, const int y)
{
    epaisseurDeTrait(5);
    (digit.hautGauche) ? CC_BLANC : CC_NOIR;
    ligne(x - Ux, y + 2 * Ux, x - Ux, y);
    (digit.hautDroite) ? CC_BLANC : CC_NOIR;
    ligne(x + Ux, y, x + Ux, y + 2 * Ux);
    (digit.basGauche) ? CC_BLANC : CC_NOIR;
    ligne(x - Ux, y, x - Ux, y - 2 * Ux);
    (digit.basDroite) ? CC_BLANC : CC_NOIR;
    ligne(x + Ux, y, x + Ux, y - 2 * Ux);
    (digit.haut) ? CC_BLANC : CC_NOIR;
    ligne(x - Ux, y + 2 * Ux, x + Ux, y + 2 * Ux);
    (digit.milieu) ? CC_BLANC : CC_NOIR;
    ligne(x - Ux, y, x + Ux, y);
    (digit.bas) ? CC_BLANC : CC_NOIR;
    ligne(x - Ux, y - 2 * Ux, x + Ux, y - 2 * Ux);
}

void afficheUsers(const Select *const select, const Users *const users, const int teinte)
{
    char Game[10] = "", Win[10] = "", Lose[10] = "";
    const User *tmp = users->premier;
    for (int i = 0; tmp != NULL; i++, tmp = tmp->userSuivant)
    {
        sprintf(Game, "G %d", tmp->nbGame);
        sprintf(Win, "W %d", tmp->nbWin);
        sprintf(Lose, "L %d", tmp->nbLose);
        bouton(select[i], 2 * Ux + 20 * (i % 5) * Ux, 56 * Uy - 35 * floor(i / 5) * Uy, 18 * Ux + 20 * (i % 5) * Ux, 83 * Uy - 35 * floor(i / 5) * Uy);
        bouton(select[i + NB_USERS], 15 * Ux + 20 * (i % 5) * Ux, 56 * Uy - 35 * floor(i / 5) * Uy, 18 * Ux + 20 * (i % 5) * Ux, 60 * Uy - 35 * floor(i / 5) * Uy);
        EPAISSEUR_2;
        couleurCourante(teinte, teinte, teinte);
        afficheChaine(tmp->pseudo, 40 - 10 * floor(strlen(tmp->pseudo) / 5), 4 * Ux + 20 * (i % 5) * Ux, 75 * Uy - 35 * floor(i / 5) * Uy);
        ligne(16 * Ux + 20 * (i % 5) * Ux, 57 * Uy - 35 * floor(i / 5) * Uy, 17 * Ux + 20 * (i % 5) * Ux, 59 * Uy - 35 * floor(i / 5) * Uy);
        ligne(16 * Ux + 20 * (i % 5) * Ux, 59 * Uy - 35 * floor(i / 5) * Uy, 17 * Ux + 20 * (i % 5) * Ux, 57 * Uy - 35 * floor(i / 5) * Uy);
        afficheChaine(Game, 20, 4 * Ux + 20 * (i % 5) * Ux, 70 * Uy - 35 * floor(i / 5) * Uy);
        afficheChaine(Win, 20, 4 * Ux + 20 * (i % 5) * Ux, 65 * Uy - 35 * floor(i / 5) * Uy);
        afficheChaine(Lose, 20, 4 * Ux + 20 * (i % 5) * Ux, 60 * Uy - 35 * floor(i / 5) * Uy);
    }
}

// sous traitance
void AfficheMutateur(Data *const data)
{
    // TEXTE MUTATEUR
    couleurCourante(0, 0, 0);
    bouton(data->page.select[35], 5 * Ux, 5 * Uy, 95 * Ux, MAX_Y);
    couleurCourante(255, 255, 255);
    cercle(data->balleJeu.x, data->balleJeu.y, data->balleJeu.r);
    for (int i = 0; i < NB_JOUEUR; i++)
        raquette(data->joueurs[i].raquette, 255);
    epaisseurDeTrait(6);
    afficheChaine("MUTATEUR", 60, 30 * Ux, 80 * Uy);

    // RECTANGLE VITESSE BALLE
    couleurCourante(140, 20, 20);
    rectangle(10 * Ux, 75 * Uy, 42 * Ux, 62 * Uy);
    epaisseurDeTrait(3);
    couleurCourante(255, 190, 180);
    afficheChaine("Vitesse balle", 30, 12 * Ux, 67 * Uy);

    //RECTANGLE TAILLE BALLE
    couleurCourante(140, 20, 20);
    rectangle(58 * Ux, 75 * Uy, 90 * Ux, 62 * Uy);
    epaisseurDeTrait(3);
    couleurCourante(255, 190, 180);
    afficheChaine("Taille balle", 30, 64 * Ux, 67 * Uy);

    // RECTANGLE TAILLE RAQUETTE
    couleurCourante(140, 20, 20);
    rectangle(34 * Ux, 35 * Uy, 66 * Ux, 22 * Uy);
    epaisseurDeTrait(3);
    couleurCourante(255, 190, 180);
    afficheChaine("Taille raquette", 30, 37 * Ux, 26 * Uy);

    // RECTANGLE S M L
    couleurCourante(190, 70, 70);
    rectangle(33 * Ux, 18 * Uy, 43 * Ux, 10 * Uy);
    rectangle(45 * Ux, 18 * Uy, 55 * Ux, 10 * Uy);
    rectangle(57 * Ux, 18 * Uy, 67 * Ux, 10 * Uy);

    bouton(data->page.select[25], 33 * Ux, 10 * Uy, 43 * Ux, 18 * Uy);
    bouton(data->page.select[26], 45 * Ux, 10 * Uy, 55 * Ux, 18 * Uy);
    bouton(data->page.select[27], 57 * Ux, 10 * Uy, 67 * Ux, 18 * Uy);

    // FONCTION AFFICHAGE DES SLIDERS

    couleurCourante(255, 190, 180);
    afficheChaine("S", 30, 37 * Ux, 12 * Uy);

    couleurCourante(255, 190, 180);
    afficheChaine("M", 30, 49 * Ux, 12 * Uy);

    couleurCourante(255, 190, 180);
    afficheChaine("L", 30, 61 * Ux, 12 * Uy);

    couleurCourante(168, 168, 168);
    rectangle(absBar1, 55 * Uy, 42 * Ux, 53 * Uy);

    couleurCourante(168, 168, 168);
    rectangle(absBar2, 55 * Uy, 90 * Ux, 53 * Uy);
    couleurCourante(255, 0, 0);

    // FONCTION AFFICHAGE CURSEUR GAUCHE

    triangle(8 * Ux + data->option.triangle1, 58 * Uy, 10 * Ux + data->option.triangle1, 55 * Uy, 12 * Ux + data->option.triangle1, 58 * Uy);

    // FONCTION AFFICHAGE CURSEUR DROITE

    triangle(56 * Ux + data->option.triangle2, 58 * Uy, 58 * Ux + data->option.triangle2, 55 * Uy, 60 * Ux + data->option.triangle2, 58 * Uy);
}