#include "moteur.h"

void mouvementBalle(Balle *balle)
{
	balle->x += balle->vx;
	balle->y += balle->vy;
}

void rebond(Balle *balle, int min_x, int min_y, int max_x, int max_y)
{
	if (balle->x < min_x || balle->x > max_x)
		balle->vx = -balle->vx;
	if (balle->y < min_y || balle->y > max_y)
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
	if (raquette->centre + raquette->longueur / 2 >= MAX_Y_PLATEAU)
		raquette->centre = MAX_Y_PLATEAU - raquette->longueur / 2;
	if (raquette->centre - raquette->longueur / 2 <= MIN_Y_PLATEAU)
		raquette->centre = MIN_Y_PLATEAU + raquette->longueur / 2;
}

void touches(Raquette *raquette)
{
	if (caractereClavier() == raquette->up)
	{
		up(raquette);
	}
	else if (caractereClavier() == raquette->down)
	{
		down(raquette);
	}
}

void up(Raquette *raquette)
{
	if (raquette->centre + raquette->vc + raquette->longueur / 2 >= MAX_Y_PLATEAU)
	{
		raquette->centre = MAX_Y_PLATEAU - raquette->longueur / 2;
	}
	else if (raquette->centre + raquette->longueur / 2 <= MAX_Y_PLATEAU)
	{
		raquette->centre += raquette->vc;
	}
}

void down(Raquette *raquette)
{
	if (raquette->centre - raquette->vc - raquette->longueur / 2 <= MIN_Y_PLATEAU)
	{
		raquette->centre = MIN_Y_PLATEAU + raquette->longueur / 2;
	}
	else if (raquette->centre - raquette->longueur / 2 >= MIN_Y_PLATEAU)
	{
		raquette->centre -= raquette->vc;
	}
}

void hitbox()
{
}