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
#define RafraichissementFenetre 20

#define MAX_X largeurFenetre()
#define MAX_Y hauteurFenetre()
#define MID_X largeurFenetre() / 2
#define MID_Y hauteurFenetre() / 2
#define Ux largeurFenetre() / 100
#define Uy hauteurFenetre() / 100
#define X_BALLE balle->x + cosf(i) * balle->r && balle->x + cosf(i) * balle->r
#define Y_BALLE balle->y + sinf(i) * balle->r && balle->y + sinf(i) * balle->r
#define X_SOURIS abscisseSouris() && abscisseSouris()
#define Y_SOURIS ordonneeSouris() && ordonneeSouris()
#define MIN_X_PLATEAU 3 * Ux
#define MAX_X_PLATEAU 97 * Ux
#define MIN_Y_PLATEAU 3 * Uy
#define MAX_Y_PLATEAU 82 * Uy

#define r_Rouage 3 * Ux

#define CC_BLANC couleurCourante(255, 255, 255)
#define CC_NOIR couleurCourante(0, 0, 0)

#define EPAISSEUR_1 epaisseurDeTrait(1)
#define EPAISSEUR_2 epaisseurDeTrait(2)
#define EPAISSEUR_3 epaisseurDeTrait(3)
#define EPAISSEUR_TITRE epaisseurDeTrait(8)

#define LARG_RAQUETTE Ux
#define LONG_RAQUETTE 17 * Uy
#define V_RAQUETTE 3 * Uy
#define X_RAQUETTE_LEFT MIN_X_PLATEAU + 2 * Ux
#define X_RAQUETTE_RIGHT MAX_X_PLATEAU - 2 * Ux

#define Gauche false
#define Droite true

#define V_ACCEUIL rand() % 2 ? 5.f : -5.f
#define V_BALLE 10.f
#define VH_BALLE 0.00001
#define R_ACCEUIL 10
#define R_BALLE 20
#define NB_BALLE 50

#define NB_JOUEUR 2
#define NB_USERS 10

#define L_SELECT_OFF 1
#define L_SELECT_ON 5
#define NB_SELECT 50
//OUTIL D'AFFICHAGE D'UNE GRILLE POUR FACILITER LES MESURES
#define GRILLE                               \
    for (int i = 1; i < 100; i++)            \
    {                                        \
        char a[10] = "";                     \
        CC_BLANC;                            \
        EPAISSEUR_1;                         \
        sprintf(a, "%d", i);                 \
        afficheChaine(a, 5, i *Ux, Uy / 2);  \
        afficheChaine(a, 5, Ux / 2, i * Uy); \
        ligne(i *Ux, 0, i *Ux, 100 * Uy);    \
        ligne(0, i *Uy, 100 * Ux, i * Uy);   \
    }
//METHODE D'AFFICHAGE DU SCORE
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

#define ContreLaMontre 0
#define BattleRoyal 1

#define Deux_Min \
    {            \
        2, 0     \
    }
#define NBVIES 5

#define id_IA 20
#define id_Rouage 45

#define Acceuil 1
#define Regles 2
#define Menu 3
#define Selection 4
#define Jeu 5
#define Entrainement 6
#define Resultats 7

//sous-traitance
#define absBar1 10 * Ux
#define absBar2 58 * Ux

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
// int id |char pseudo[15] |int nbGame |int nbWin |int nbLose |User *userSuivant
struct User
{
    int id;
    char pseudo[15];
    int nbGame;
    int nbWin;
    int nbLose;
    User *userSuivant;
};
// User *premier
typedef struct
{
    User *premier;
} Users;
// int largeur |int couleur[3]
typedef struct
{
    int largeur;
    int couleur[3];
} Select;
// int numero |bool pause |Select select[NB_SELECT]
typedef struct
{
    int numero;
    int pause;
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
    int mode;
    int temps[2];
    int nbButs;
    float triangle1;
    float triangle2;
    int raquette;
} Options;

// Page page |Balle balle[MAX_BALLE] |Balle balleJeu |Joueur joueurs[NB_JOUEUR] |User *users |char newPseudo[15]
typedef struct
{
    Page page;
    Balle balle[NB_BALLE];
    Balle balleJeu;
    Joueur joueurs[NB_JOUEUR];
    Users *users;
    Options option;
    int timer[2];
    char newPseudo[15];

} Data;

#endif