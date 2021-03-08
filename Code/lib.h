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
#define MAX_X_PLATEAU 29 * largeurFenetre() / 30
#define MIN_X_PLATEAU largeurFenetre() / 30
#define MAX_Y_PLATEAU 99 * hauteurFenetre() / 120
#define MIN_Y_PLATEAU hauteurFenetre() / 60

#define RAQUETTE_X_LEFT largeurFenetre() / 30 + 10
#define RAQUETTE_X_RIGHT 29 * largeurFenetre() / 30 - 10

#define MAX_BALLE 50
#define NB_JOUEUR 2
#define NB_SELECT 12

#ifndef STRUCT
#define STRUCT
// float x;
// float y;
// float r;
// float vx;
// float vy;
// float v0;
typedef struct
{
    float x;
    float y;
    float r;
    float vx;
    float vy;
    float v0;
} Balle;

// float longueur;
// float largeur;
// float x;
// float y;
// float vy;
// char up;
// char down;
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
// char pseudo[25];
// int nbGame;
// int nbWin;
// int nbLose;
// User *userSuivant;
struct User
{
    char pseudo[25];
    int nbGame;
    int nbWin;
    int nbLose;
    User *userSuivant;
};
// int numero;
// bool pause;
// int select[NB_SELECT];
typedef struct
{
    int numero;
    bool pause;
    int select[NB_SELECT];
} Page;

// int score;
// User *user;
// Raquette raquette;
typedef struct
{
    int score;
    User *user;
    Raquette raquette;
} Joueur;

typedef struct
{
} Options;

// Page page;
// Balle balle[MAX_BALLE];
// Balle balleJeu;
// Joueur joueurs[NB_JOUEUR];
// User *users;
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