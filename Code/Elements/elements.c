#include "elements.h"

void bouton(const Select select, const int xBasGauche, const int yBasGauche, const int xHautDroite, const int yHautDroite)
{
    couleurCourante(select.couleur[0], select.couleur[1], select.couleur[2]);
    rectangle(xBasGauche, yBasGauche, xHautDroite, yHautDroite);
    CC_NOIR;
    rectangle(xBasGauche + select.largeur, yBasGauche + select.largeur, xHautDroite - select.largeur, yHautDroite - select.largeur);
}

void rouage(const int x, const int y, const int r)
{
    couleurCourante(100, 100, 100);
    cercle(x, y, r);
    CC_BLANC;
    ligne(x - r + 5, y, x + r - 5, y);
    ligne(x - sqrt(2) * (r - 5) / 2, y - sqrt(2) * (r - 5) / 2, x + sqrt(2) * (r - 5) / 2, y + sqrt(2) * (r - 5) / 2);
    ligne(x, y - r + 5, x, y + r - 5);
    ligne(x - sqrt(2) * (r - 5) / 2, y + sqrt(2) * (r - 5) / 2, x + sqrt(2) * (r - 5) / 2, y - sqrt(2) * (r - 5) / 2);
    cercle(x, y, 11 * r / 16);
    couleurCourante(100, 100, 100);
    cercle(x, y, r / 4);
    CC_BLANC;
    cercle(x, y, r / 6);
}
void plateau(const int teinte)
{
    couleurCourante(teinte, teinte, teinte);
    rectangle(MIN_X_PLATEAU - Ux, MIN_Y_PLATEAU - Ux, MAX_X_PLATEAU + Ux, MAX_Y_PLATEAU + Ux);
    CC_NOIR;
    rectangle(MIN_X_PLATEAU, MIN_Y_PLATEAU, MAX_X_PLATEAU, MAX_Y_PLATEAU);
    couleurCourante(teinte, teinte, teinte);
    epaisseurDeTrait(3);
    for (int i = 0; i < 8; i++)
        ligne(MID_X, 82 * Uy - 10 * i * Uy, MID_X, 73 * Uy - 10 * i * Uy);
}
void affichePause(const Select *const select)
{
    CC_BLANC;
    epaisseurDeTrait(3);
    ligne(30 * Ux, 10 * Uy, 30 * Ux, 70 * Uy);
    ligne(30 * Ux, 70 * Uy, 70 * Ux, 70 * Uy);
    ligne(70 * Ux, 70 * Uy, 70 * Ux, 10 * Uy);
    ligne(70 * Ux, 10 * Uy, 30 * Ux, 10 * Uy);
    bouton(select[0], 35 * Ux, 55 * Uy, 65 * Ux, 65 * Uy);
    bouton(select[1], 35 * Ux, 35 * Uy, 65 * Ux, 45 * Uy);
    bouton(select[2], 35 * Ux, 15 * Uy, 65 * Ux, 25 * Uy);
    CC_BLANC;
    afficheChaine("Reprendre", 30, 41 * Ux, 58 * Uy);
    afficheChaine("Rejouer", 30, 43 * Ux, 38 * Uy);
    afficheChaine("Quitter", 30, 44 * Ux, 18 * Uy);
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

void afficheUsers(const Select *const select, const Users *const users)
{
    char Game[10] = "", Win[10] = "", Lose[10] = "";
    const User *tmp = users->premier;
    for (int i = 0; tmp != NULL; i++, tmp = tmp->userSuivant)
    {
        sprintf(Game, "G %d", tmp->nbWin);
        sprintf(Win, "W %d", tmp->nbWin);
        sprintf(Lose, "L %d", tmp->nbLose);
        bouton(select[i], 2 * Ux + 20 * (i % 5) * Ux, 56 * Uy - 35 * floor(i / 5) * Uy, 18 * Ux + 20 * (i % 5) * Ux, 83 * Uy - 35 * floor(i / 5) * Uy);
        bouton(select[i + NB_USERS], 15 * Ux + 20 * (i % 5) * Ux, 56 * Uy - 35 * floor(i / 5) * Uy, 18 * Ux + 20 * (i % 5) * Ux, 60 * Uy - 35 * floor(i / 5) * Uy);
        CC_BLANC;
        epaisseurDeTrait(3);
        afficheChaine(tmp->pseudo, 30, 4 * Ux + 20 * (i % 5) * Ux, 75 * Uy - 35 * floor(i / 5) * Uy);
        epaisseurDeTrait(2);
        ligne(16 * Ux + 20 * (i % 5) * Ux, 57 * Uy - 35 * floor(i / 5) * Uy, 17 * Ux + 20 * (i % 5) * Ux, 59 * Uy - 35 * floor(i / 5) * Uy);
        ligne(16 * Ux + 20 * (i % 5) * Ux, 59 * Uy - 35 * floor(i / 5) * Uy, 17 * Ux + 20 * (i % 5) * Ux, 57 * Uy - 35 * floor(i / 5) * Uy);
        afficheChaine(Game, 20, 4 * Ux + 20 * (i % 5) * Ux, 70 * Uy - 35 * floor(i / 5) * Uy);
        afficheChaine(Win, 20, 4 * Ux + 20 * (i % 5) * Ux, 65 * Uy - 35 * floor(i / 5) * Uy);
        afficheChaine(Lose, 20, 4 * Ux + 20 * (i % 5) * Ux, 60 * Uy - 35 * floor(i / 5) * Uy);
    }
}