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


void gestionPage(int *page);
void pageAccueil();
void gereClic(int *page);
void gereClicAccueil(int *page);
void gereClicJeu();
void gereClicRegles();
void pageJeu();
void pageRegles();