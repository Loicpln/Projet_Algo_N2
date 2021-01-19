#include "./Affichage/gestion.h"

typedef struct {
    void(*f1)();
    void(*f2)();
    void(*f3)();
}Gestion;

void gestion(int *page, Balle *tab, Gestion gestion);

Gestion fAffiche();
Gestion fClavier();
Gestion fClick();

