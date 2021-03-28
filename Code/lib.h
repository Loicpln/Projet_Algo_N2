#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
//#include <Fmod/fmod.h>
//#include <SDL/SDL.h>
//#include <SDL/SDL_mixer.h>
#include "./GfxLib/GfxLib.h"
#include "./GfxLib/BmpLib.h"
#include "./GfxLib/ESLib.h"

#define LargeurFenetre 800
#define HauteurFenetre 600

#define MAX_X largeurFenetre()
#define MAX_Y hauteurFenetre()
#define MID_X largeurFenetre() / 2
#define MID_Y hauteurFenetre() / 2
#define Ux largeurFenetre() / 100
#define Uy hauteurFenetre() / 100
#define X_SOURIS abscisseSouris() && abscisseSouris()
#define Y_SOURIS ordonneeSouris() && ordonneeSouris()
#define MIN_X_PLATEAU 3 * Ux
#define MAX_X_PLATEAU 97 * Ux
#define MIN_Y_PLATEAU 3 * Uy
#define MAX_Y_PLATEAU 82 * Uy

#define r_Rouage 25

#define CC_BLANC couleurCourante(255, 255, 255)
#define CC_NOIR couleurCourante(0, 0, 0)

#define EPAISSEUR_1 epaisseurDeTrait(1)
#define EPAISSEUR_2 epaisseurDeTrait(2)
#define EPAISSEUR_3 epaisseurDeTrait(3)
#define EPAISSEUR_TITRE epaisseurDeTrait(8)

#define LARG_RAQUETTE 10
#define LONG_RAQUETTE 100
#define V_RAQUETTE 15
#define X_RAQUETTE_LEFT MIN_X_PLATEAU + 2 * Ux
#define X_RAQUETTE_RIGHT MAX_X_PLATEAU - 2 * Ux

#define V_BALLE (rand() % 2) ? 5 : -5
#define VH_BALLE 0.1
#define R_BALLE 10
#define MAX_BALLE 50

#define NB_JOUEUR 2
#define NB_USERS 10

#define L_SELECT 5
#define NB_SELECT 50

#define GRILLE                                        \
    for (int i = 1; i < 100; i++)                     \
    {                                                 \
        char a[10] = "";                              \
        CC_BLANC;                                     \
        EPAISSEUR_1;                                  \
        sprintf(a, "%d", i);                          \
        afficheChaine(a, 5, Ux / 2 + i * Ux, Uy / 2); \
        afficheChaine(a, 5, Ux / 2, Uy / 2 + i * Uy); \
        ligne(i *Ux, Uy, i *Ux, 100 * Uy);            \
        ligne(Ux, i *Uy, 100 * Ux, i * Uy);           \
    }

#define DIGIT_0 \
    (Digit) { true, true, true, false, true, true, true }
#define DIGIT_1 \
    (Digit) { false, false, true, false, false, true, false }
#define DIGIT_2 \
    (Digit) { true, false, true, true, true, false, true }
#define DIGIT_3 \
    (Digit) { true, false, true, true, false, true, true }
#define DIGIT_4 \
    (Digit) { false, true, true, true, false, true, false }
#define DIGIT_5 \
    (Digit) { true, true, false, true, false, true, true }
#define DIGIT_6 \
    (Digit) { true, true, false, true, true, true, true }
#define DIGIT_7 \
    (Digit) { true, false, true, false, false, true, false }
#define DIGIT_8 \
    (Digit) { true, true, true, true, true, true, true }
#define DIGIT_9 \
    (Digit) { true, true, true, true, false, true, true }
#define DIGIT_ERROR \
    (Digit) { true, true, false, true, true, false, true }

#define Acceuil 1
#define Regles 2
#define Menu 3
#define Selection_Joueurs 4
#define Jeu_Joueurs 5
#define Selection_IA 6
#define Jeu_IA 7
#define Entrainement 8

#ifndef STRUCT
#define STRUCT

// bool haut |bool hautGauche |bool hautDroite |bool milieu |bool basGauche |bool basDroite |bool bas
typedef struct
{
    bool haut;
    bool hautGauche;
    bool hautDroite;
    bool milieu;
    bool basGauche;
    bool basDroite;
    bool bas;
} Digit;

// float x |float y |float r |float vx |float vy |float v0
typedef struct
{
    float x;
    float y;
    float r;
    float vx;
    float vy;
    float v0;
} Balle;

// float longueur |float largeur |float x |float y |float vy |char up |char down
typedef struct
{
    float longueur;
    float largeur;
    float x;
    float y;
    float vy;
    char up;
    char down;
} Raquette;

typedef struct User User;
// char pseudo[25] |int nbGame |int nbWin |int nbLose |User *userSuivant
struct User
{
    int id;
    char pseudo[15];
    int nbGame;
    int nbWin;
    int nbLose;
    User *userSuivant;
};
typedef struct
{
    User *premier;
} Users;
typedef struct
{
    int largeur;
    int couleur[3];
} Select;
// int numero |bool pause |int select[NB_SELECT]
typedef struct
{
    int numero;
    bool pause;
    Select select[NB_SELECT];
} Page;

// int score |User *user |Raquette raquette
typedef struct
{
    int score;
    User *user;
    Raquette raquette;
} Joueur;

typedef struct
{
} Options;

// Page page |Balle balle[MAX_BALLE] |Balle balleJeu |Joueur joueurs[NB_JOUEUR] |User *users
typedef struct
{
    Page page;
    Balle balle[MAX_BALLE];
    Balle balleJeu;
    Joueur joueurs[NB_JOUEUR];
    Users *users;
    //Options option;
    char newPseudo[15];
} Data;

#endif