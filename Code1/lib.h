#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include "./GfxLib/GfxLib.h"
#include "./GfxLib/BmpLib.h"
#include "./GfxLib/ESLib.h"

#define LargeurFenetre 800
#define HauteurFenetre 600

#define MAX_BALLE 20
#define nb_raquette 2
#define DIM_PAGE 5

#define ZERO {true, true, true, false, true, true, true}
#define UN {false, false, true, false, false, true, false}
#define DEUX {true, false, true, true, true, false, true}
#define TROIS {true, false, true, true, false, true, true}
#define QUATRE {false, true, true, true, false, true, false}
#define CINQ {true, true, false, true, false, true, true}
#define SIX {true, true, false, true, true, true, true}
#define SEPT {true, false, true, false, false, true, false}
#define HUIT {true, true, true, true, true, true, true}
#define NEUF {true, true, true, true, false, true, true}

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

} Raquette;

typedef struct
{
    int page[DIM_PAGE];
    Balle balle[MAX_BALLE];
    Raquette raquette[nb_raquette];
} Data;

#endif