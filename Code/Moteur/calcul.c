#include "moteur.h"

void mouvementBalle(Balle *balle)
{
	balle->x += balle->vx;
	balle->y += balle->vy;
}

void rebond(Balle *balle)
{
	if (balle->x < 0 || balle->x > largeurFenetre())
		balle->vx = -balle->vx;
	if (balle->y < 0 || balle->y > hauteurFenetre())
		balle->vy = -balle->vy;
}

void redimBalle(Balle *balle)
{
	if (balle->x >= largeurFenetre())
		balle->x = largeurFenetre() - 1;
	if (balle->y >= hauteurFenetre())
		balle->y = hauteurFenetre() - 1;
}

void accelereBalle(Balle *balle, float a)
{
	balle->vx *= a;
	balle->vy *= a;
}

void redimRaquette(Raquette *raquette)
{
	if (raquette->centre + raquette->longueur / 2 >= MAX_PLATEAU)
		raquette->centre = MAX_PLATEAU - raquette->longueur / 2;
	if (raquette->centre - raquette->longueur / 2 <= MIN_PLATEAU)
		raquette->centre = MIN_PLATEAU + raquette->longueur / 2;
}