#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
//#include <Fmod/fmod.h>
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
#define NB_RAQUETTE 2
#define DIM_PAGE 5

#ifndef STRUCT
#define STRUCT

typedef struct
{
    float x;
    float y;
    float r;
    float vx;
    float vy;
    float v0;
} Balle;

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

typedef struct
{
    int page[DIM_PAGE];
    Balle balle[MAX_BALLE];
    Raquette raquette[NB_RAQUETTE];
    Balle balleJeu[1];
    int score[2];
    User user;
} Data;

typedef struct
{
    char pseudo[25];
    int nbGame;
    int nbWinGames;
    int nbLoseGames;
    int ratioWin;
    User userSuivant;
} User;

#endif