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