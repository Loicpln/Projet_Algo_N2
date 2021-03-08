#include "elements.h"

void rouage(const int x, const int y, const int r)
{
    couleurCourante(100, 100, 100);
    cercle(x, y, r);
    couleurCourante(255, 255, 255);
    ligne(x - r + 5, y, x + r - 5, y);
    ligne(x - sqrt(2) * (r - 5) / 2, y - sqrt(2) * (r - 5) / 2, x + sqrt(2) * (r - 5) / 2, y + sqrt(2) * (r - 5) / 2);
    ligne(x, y - r + 5, x, y + r - 5);
    ligne(x - sqrt(2) * (r - 5) / 2, y + sqrt(2) * (r - 5) / 2, x + sqrt(2) * (r - 5) / 2, y - sqrt(2) * (r - 5) / 2);
    cercle(x, y, 11 * r / 16);
    couleurCourante(100, 100, 100);
    cercle(x, y, r / 4);
    couleurCourante(255, 255, 255);
    cercle(x, y, r / 6);
}
void plateau(const int teinte)
{
    couleurCourante(teinte, teinte, teinte);
    rectangle(
        largeurFenetre() / 40, MIN_Y_PLATEAU / 2,
        39 * largeurFenetre() / 40, MAX_Y_PLATEAU + MIN_Y_PLATEAU / 2);
    couleurCourante(0, 0, 0);
    rectangle(
        MIN_X_PLATEAU, MIN_Y_PLATEAU,
        MAX_X_PLATEAU, MAX_Y_PLATEAU);
    couleurCourante(teinte, teinte, teinte);
    epaisseurDeTrait(3);
    for (int i = 0; i < 10; i++)
        ligne(
            MID_X, 100 * hauteurFenetre() / 120 - 10 * i * hauteurFenetre() / 120,
            MID_X, 91 * hauteurFenetre() / 120 - 10 * i * hauteurFenetre() / 120);
}
void affichePause(const int *const select)
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

void raquette(const Raquette raquette, const int teinte)
{
    couleurCourante(teinte, teinte, teinte);
    rectangle(
        raquette.x - raquette.largeur / 2, raquette.y + raquette.longueur / 2,
        raquette.x + raquette.largeur / 2, raquette.y - raquette.longueur / 2);
}

void balle(const Balle balleJeu, const int teinte)
{
    couleurCourante(teinte, teinte, teinte);
    cercle(balleJeu.x, balleJeu.y, balleJeu.r);
}

void score(const int score, const bool side, const int teinte)
{
    bool digit[2][7];
    nombre(digit[0], score - 10 * floor(score / 10));
    nombre(digit[1], floor(score / 10));
    epaisseurDeTrait(5);
    for (int i = 0; i < 2; i++)
        afficheDigit(digit[i], side, i, teinte);
}

void afficheDigit(const bool *const digit, const bool side, const int i, const int teinte)
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

void afficheUsers(const User *maUsers)
{
    if (maUsers != NULL)
    {
        int i = 0;
        char Game[10] = "", Win[10] = "", Lose[10] = "";
        const User *tmp = maUsers;
        while (tmp != NULL)
        {
            sprintf(Game, "G %d", tmp->nbWin);
            sprintf(Win, "W %d", tmp->nbWin);
            sprintf(Lose, "L %d", tmp->nbLose);
            if (largeurFenetre() / 30 + 20 + 6 * i * largeurFenetre() / 30 < largeurFenetre())
            {
                epaisseurDeTrait(3);
                afficheChaine(tmp->pseudo, 25, largeurFenetre() / 30 + 20 + 6 * i * largeurFenetre() / 30, 90 * hauteurFenetre() / 120);
                epaisseurDeTrait(2);
                afficheChaine(Game, 20, largeurFenetre() / 30 + 20 + 6 * i * largeurFenetre() / 30, 85 * hauteurFenetre() / 120);
                afficheChaine(Win, 20, largeurFenetre() / 30 + 20 + 6 * i * largeurFenetre() / 30, 80 * hauteurFenetre() / 120);
                afficheChaine(Lose, 20, largeurFenetre() / 30 + 20 + 6 * i * largeurFenetre() / 30, 75 * hauteurFenetre() / 120);
            }
            else
            {
                epaisseurDeTrait(3);
                afficheChaine(tmp->pseudo, 25, largeurFenetre() / 30 + 20 + 6 * (i - 5) * largeurFenetre() / 30, 50 * hauteurFenetre() / 120);
                epaisseurDeTrait(2);
                afficheChaine(Game, 20, largeurFenetre() / 30 + 20 + 6 * (i - 5) * largeurFenetre() / 30, 45 * hauteurFenetre() / 120);
                afficheChaine(Win, 20, largeurFenetre() / 30 + 20 + 6 * (i - 5) * largeurFenetre() / 30, 40 * hauteurFenetre() / 120);
                afficheChaine(Lose, 20, largeurFenetre() / 30 + 20 + 6 * (i - 5) * largeurFenetre() / 30, 35 * hauteurFenetre() / 120);
            }
            tmp = tmp->userSuivant;
            i++;
        }
    }
}