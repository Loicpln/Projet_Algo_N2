#include <stdlib.h>
#include <stdio.h>
#include "./tpGfx/GfxLib.h"
#include "./tpGfx/BmpLib.h"
#include "./tpGfx/ESLib.h"
#define LargeurFenetre 1000
#define HauteurFenetre 800
#define absBar1 1.5 * largeurFenetre() / 14
#define absBar2 8 * largeurFenetre() / 14


// INITIALISATION DES VARIABLES
int valTailleRaq;
int triangle1;
int triangle2;


// DEFINITION DES FONCTIONS
void gestionEvenement(EvenementGfx evenement);

void afficheMutateur();
void traceSlider();
void TraceTriangle1(int Triangle);
void TraceTriangle2(int Triangle);

int modifTriangle1(int triangle);
int modifTriangle2(int triangle);
int clicTailleRaq();
void retour();
