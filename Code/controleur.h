#include "lib.h"
#include "./Affichage/gestion.h"

#define LargeurFenetre 800
#define HauteurFenetre 600

#define MAX 10

typedef struct Gestion{
    void(*f1)();
    void(*f2)();
    void(*f3)();
}Gestion;

void gestion(int *page, int *xBalle, int *yBalle, int *vxBalle, int *vyBalle, Gestion gestion);

Gestion fAffiche();
Gestion fClavier();
Gestion fClick();