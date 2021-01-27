#include "moteur.h"

void mouvementBalle(Balle *balle)
{
	balle->x += balle->vx;
	balle->y += balle->vy;
}

void rebond(Balle *balle, int min_x, int min_y, int max_x, int max_y)
{
	if (balle->x - balle->r < min_x || balle->x + balle->r > max_x)
		balle->vx = -balle->vx;
	if (balle->y - balle->r < min_y || balle->y + balle->r > max_y)
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
void nombre(int score, bool digit[])
{
	switch (score)
	{
	case 0:
		digit[0] = true;
		digit[1] = true;
		digit[2] = true;
		digit[3] = false;
		digit[4] = true;
		digit[5] = true;
		digit[6] = true;
		break;
	case 1:
		digit[0] = false;
		digit[1] = false;
		digit[2] = true;
		digit[3] = false;
		digit[4] = false;
		digit[5] = true;
		digit[6] = false;
		break;
	case 2:
		digit[0] = true;
		digit[1] = false;
		digit[2] = true;
		digit[3] = true;
		digit[4] = true;
		digit[5] = false;
		digit[6] = true;
		break;
	case 3:
		digit[0] = true;
		digit[1] = false;
		digit[2] = true;
		digit[3] = true;
		digit[4] = false;
		digit[5] = true;
		digit[6] = true;
		break;
	case 4:
		digit[0] = false;
		digit[1] = true;
		digit[2] = true;
		digit[3] = true;
		digit[4] = false;
		digit[5] = true;
		digit[6] = false;
		break;
	case 5:
		digit[0] = true;
		digit[1] = true;
		digit[2] = false;
		digit[3] = true;
		digit[4] = false;
		digit[5] = true;
		digit[6] = true;
		break;
	case 6:
		digit[0] = true;
		digit[1] = true;
		digit[2] = false;
		digit[3] = true;
		digit[4] = true;
		digit[5] = true;
		digit[6] = true;
		break;
	case 7:
		digit[0] = true;
		digit[1] = false;
		digit[2] = true;
		digit[3] = false;
		digit[4] = false;
		digit[5] = true;
		digit[6] = false;
		break;
	case 8:
		digit[0] = true;
		digit[1] = true;
		digit[2] = true;
		digit[3] = true;
		digit[4] = true;
		digit[5] = true;
		digit[6] = true;
		break;
	case 9:
		digit[0] = true;
		digit[1] = true;
		digit[2] = true;
		digit[3] = true;
		digit[4] = false;
		digit[5] = true;
		digit[6] = true;
		break;
	}
}
void hitbox(Balle *balle, Raquette *raquette)
{

	if ((raquette->side) ? balle->x - balle->r <= largeurFenetre() / 30 + 10 + raquette->largeur / 2 && balle->y < raquette->centre + raquette->longueur / 2 && balle->y > raquette->centre - raquette->longueur / 2 : balle->x + balle->r >= 29 * largeurFenetre() / 30 - 10 - raquette->largeur / 2 && balle->y < raquette->centre + raquette->longueur / 2 && balle->y > raquette->centre - raquette->longueur / 2)
	{
		balle->vx = -balle->vx;
		balle->vy = balle->vy;
	}
}