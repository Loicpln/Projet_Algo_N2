#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include "../GfxLib/GfxLib.h"
#include "../GfxLib/BmpLib.h"
#include "../GfxLib/ESLib.h" 

void pageAccueil();
void pageJeu();
void pageRegles();


void gereClicAccueil(int *page);
void gereClicJeu(int * page);
void gereClicRegles(int *page);