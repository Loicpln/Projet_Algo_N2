#include "controleur.h"

void gestion(int *page, int *xBalle, int *yBalle, int *vxBalle, int *vyBalle, Gestion gestion) //gestion affichage pages
{
    switch (*page)
    {
    case 0:
        gestion.f1();
        couleurCourante(255, 0, 0);
        for (int i = 0; i < MAX; ++i)
            cercle(xBalle[i], yBalle[i], 10);
        break;
    case 1:
        gestion.f2();
        couleurCourante(rand() % 255, rand() % 255, rand() % 255);
        for (int i = 0; i < MAX; ++i)
		{
			xBalle[i] = largeurFenetre() * valeurAleatoire();
			yBalle[i] = hauteurFenetre() * valeurAleatoire();
			vxBalle[i] = 20;
			vyBalle[i] = 20;
		}
        for (int i = 0; i < MAX; ++i)
            cercle(xBalle[i], yBalle[i], 10);
        break;
    case 2:
        gestion.f3();
        break;
    }
}

Gestion fAffiche()
{
    return (Gestion){AfficheAccueil, AfficheJeu, AfficheRegles};
}

Gestion fClavier()
{
    return (Gestion){NULL, NULL, NULL};
}

Gestion fClick()
{
    return (Gestion){ClicAccueil, ClicJeu, ClicRegles};
}