#include "controleur.h"

void gestion(int *page, void(*f1)() ,void(*f2)() ,void(*f3)()) //gestion affichage pages
{
    switch (*page)
    {
    case 0:
        f1();
        break;
    case 1:
        f2();
        break;
    case 2:
        f3();
        break;
    }
}