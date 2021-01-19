#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include "./GfxLib/GfxLib.h"
#include "./GfxLib/BmpLib.h"
#include "./GfxLib/ESLib.h" 
#include "./Affichage/gestion.h"

#define LargeurFenetre 800
#define HauteurFenetre 600

typedef struct Gestion{
    void(*f1)();
    void(*f2)();
    void(*f3)();
}Gestion;

void gestion(int *page, Gestion gestion);

Gestion newAffiche();
Gestion newClavier();
Gestion newClick();