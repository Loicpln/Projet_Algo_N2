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
    rectangle(MIN_X_PLATEAU - MIN_X_PLATEAU / 3, MIN_Y_PLATEAU - MIN_X_PLATEAU / 3, MAX_X_PLATEAU + MIN_X_PLATEAU / 3, MAX_Y_PLATEAU + MIN_X_PLATEAU / 3);
    CC_NOIR;
    rectangle(MIN_X_PLATEAU, MIN_Y_PLATEAU, MAX_X_PLATEAU, MAX_Y_PLATEAU);
    couleurCourante(teinte, teinte, teinte);
    epaisseurDeTrait(3);
    for (int i = 0; i < 10; i++)
        ligne(MID_X, 100 * hauteurFenetre() / 120 - 10 * i * hauteurFenetre() / 120, MID_X, 91 * hauteurFenetre() / 120 - 10 * i * hauteurFenetre() / 120);
}
void affichePause(const Select *const select)
{
    CC_BLANC;
    epaisseurDeTrait(3);
    ligne(3 * largeurFenetre() / 10, hauteurFenetre() / 10, 3 * largeurFenetre() / 10, 7 * hauteurFenetre() / 10);
    ligne(3 * largeurFenetre() / 10, 7 * hauteurFenetre() / 10, 7 * largeurFenetre() / 10, 7 * hauteurFenetre() / 10);
    ligne(7 * largeurFenetre() / 10, 7 * hauteurFenetre() / 10, 7 * largeurFenetre() / 10, hauteurFenetre() / 10);
    ligne(7 * largeurFenetre() / 10, hauteurFenetre() / 10, 3 * largeurFenetre() / 10, hauteurFenetre() / 10);
    bouton(select[0], 7 * largeurFenetre() / 20, 11 * hauteurFenetre() / 20, 13 * largeurFenetre() / 20, 13 * hauteurFenetre() / 20);
    bouton(select[1], 7 * largeurFenetre() / 20, 7 * hauteurFenetre() / 20, 13 * largeurFenetre() / 20, 9 * hauteurFenetre() / 20);
    bouton(select[2], 7 * largeurFenetre() / 20, 3 * hauteurFenetre() / 20, 13 * largeurFenetre() / 20, 5 * hauteurFenetre() / 20);
    CC_BLANC;
    afficheChaine("Reprendre", 30, 5 * MID_X / 6, 23 * hauteurFenetre() / 40);
    afficheChaine("Rejouer", 30, 21 * MID_X / 24, 15 * hauteurFenetre() / 40);
    afficheChaine("Quitter", 30, 21 * MID_X / 24, 7 * hauteurFenetre() / 40);
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
        afficheDigit(digit[i], x - i * largeurFenetre() / 25, y);
}

void afficheDigit(const Digit digit, const int x, const int y)
{
    epaisseurDeTrait(5);
    (digit.hautGauche) ? CC_BLANC : CC_NOIR;
    ligne(x - largeurFenetre() / 100, y + largeurFenetre() / 50, x - largeurFenetre() / 100, y);
    (digit.hautDroite) ? CC_BLANC : CC_NOIR;
    ligne(x + largeurFenetre() / 100, y, x + largeurFenetre() / 100, y + largeurFenetre() / 50);
    (digit.basGauche) ? CC_BLANC : CC_NOIR;
    ligne(x - largeurFenetre() / 100, y, x - largeurFenetre() / 100, y - largeurFenetre() / 50);
    (digit.basDroite) ? CC_BLANC : CC_NOIR;
    ligne(x + largeurFenetre() / 100, y, x + largeurFenetre() / 100, y - largeurFenetre() / 50);
    (digit.haut) ? CC_BLANC : CC_NOIR;
    ligne(x - largeurFenetre() / 100, y + largeurFenetre() / 50, x + largeurFenetre() / 100, y + largeurFenetre() / 50);
    (digit.milieu) ? CC_BLANC : CC_NOIR;
    ligne(x - largeurFenetre() / 100, y, x + largeurFenetre() / 100, y);
    (digit.bas) ? CC_BLANC : CC_NOIR;
    ligne(x - largeurFenetre() / 100, y - largeurFenetre() / 50, x + largeurFenetre() / 100, y - largeurFenetre() / 50);
}

void afficheUsers(const Select *const select, const User *const maUsers)
{
    if (maUsers != NULL)
    {
        char Game[10] = "", Win[10] = "", Lose[10] = "";
        const User *tmp = maUsers;
        for (int i = 0; tmp != NULL; i++, tmp = tmp->userSuivant)
        {
            sprintf(Game, "G %d", tmp->nbWin);
            sprintf(Win, "W %d", tmp->nbWin);
            sprintf(Lose, "L %d", tmp->nbLose);
            bouton(select[i], largeurFenetre() / 30 + 6 * (i % 5) * largeurFenetre() / 30, 67 * hauteurFenetre() / 120 - 40 * floor(i / 5) * hauteurFenetre() / 120, 5 * largeurFenetre() / 30 + 6 * (i % 5) * largeurFenetre() / 30, 99 * hauteurFenetre() / 120 - 40 * floor(i / 5) * hauteurFenetre() / 120);
            CC_BLANC;
            epaisseurDeTrait(3);
            afficheChaine(tmp->pseudo, 25, largeurFenetre() / 30 + 20 + 6 * (i % 5) * largeurFenetre() / 30, 90 * hauteurFenetre() / 120 - 40 * floor(i / 5) * hauteurFenetre() / 120);
            epaisseurDeTrait(2);
            afficheChaine(Game, 20, largeurFenetre() / 30 + 20 + 6 * (i % 5) * largeurFenetre() / 30, 85 * hauteurFenetre() / 120 - 40 * floor(i / 5) * hauteurFenetre() / 120);
            afficheChaine(Win, 20, largeurFenetre() / 30 + 20 + 6 * (i % 5) * largeurFenetre() / 30, 80 * hauteurFenetre() / 120 - 40 * floor(i / 5) * hauteurFenetre() / 120);
            afficheChaine(Lose, 20, largeurFenetre() / 30 + 20 + 6 * (i % 5) * largeurFenetre() / 30, 75 * hauteurFenetre() / 120 - 40 * floor(i / 5) * hauteurFenetre() / 120);
        }
    }
}