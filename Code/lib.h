#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include "./GfxLib/GfxLib.h"
#include "./GfxLib/BmpLib.h"
#include "./GfxLib/ESLib.h"
#include "./Fmod/fmod.h"

#define LargeurFenetre 800
#define HauteurFenetre 600
#define MAX_PLATEAU 99 * hauteurFenetre() / 120
#define MIN_PLATEAU hauteurFenetre() / 60

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
} Balle;

typedef struct
{
    float longueur;
    float largeur;
    float centre;
    float vc;
    bool side;
} Raquette;

typedef struct
{
    int page[DIM_PAGE];
    Balle balle[MAX_BALLE];
    Raquette raquette[NB_RAQUETTE];
} Data;

#endif