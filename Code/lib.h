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

#define MID_X largeurFenetre() / 2
#define MID_Y hauteurFenetre() / 2

#define MIN_X_PLATEAU largeurFenetre() / 30
#define MAX_X_PLATEAU 29 * largeurFenetre() / 30
#define MIN_Y_PLATEAU hauteurFenetre() / 60
#define MAX_Y_PLATEAU 99 * hauteurFenetre() / 120

#define CC_BLANC couleurCourante(255, 255, 255)
#define CC_NOIR couleurCourante(0, 0, 0)

#define LARG_RAQUETTE 10
#define LONG_RAQUETTE 100
#define V_RAQUETTE 15
#define X_RAQUETTE_LEFT MIN_X_PLATEAU + 10
#define X_RAQUETTE_RIGHT MAX_X_PLATEAU - 10

#define V_BALLE (rand() % 2) ? 5 : -5
#define VH_BALLE 0.1
#define R_BALLE 10
#define MAX_BALLE 50

#define NB_JOUEUR 2

#define L_SELECT 5
#define NB_SELECT 50

#define ZERO_DIGIT \
    (Digit) { true, true, true, false, true, true, true }
#define UN_DIGIT \
    (Digit) { false, false, true, false, false, true, false }
#define DEUX_DIGIT \
    (Digit) { true, false, true, true, true, false, true }
#define TROIS_DIGIT \
    (Digit) { true, false, true, true, false, true, true }
#define QUATRE_DIGIT \
    (Digit) { false, true, true, true, false, true, false }
#define CINQ_DIGIT \
    (Digit) { true, true, false, true, false, true, true }
#define SIX_DIGIT \
    (Digit) { true, true, false, true, true, true, true }
#define SEPT_DIGIT \
    (Digit) { true, false, true, false, false, true, false }
#define HUIT_DIGIT \
    (Digit) { true, true, true, true, true, true, true }
#define NEUF_DIGIT \
    (Digit) { true, true, true, true, false, true, true }
#define ERREUR_DIGIT \
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
    char pseudo[25];
    int nbGame;
    int nbWin;
    int nbLose;
    User *userSuivant;
};
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
    User *users;
    //Options option;
} Data;

#endif