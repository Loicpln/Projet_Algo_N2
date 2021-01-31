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

void redimRaquette(Raquette *raquette, int i)
{
	if (raquette->y + raquette->longueur / 2 >= MAX_Y_PLATEAU)
		raquette->y = MAX_Y_PLATEAU - raquette->longueur / 2;
	if (raquette->y - raquette->longueur / 2 <= MIN_Y_PLATEAU)
		raquette->y = MIN_Y_PLATEAU + raquette->longueur / 2;
	raquette->x = (i % 2) ? RAQUETTE_X_LEFT : RAQUETTE_X_RIGHT;
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
	if (raquette->y + raquette->vy + raquette->longueur / 2 >= MAX_Y_PLATEAU)
	{
		raquette->y = MAX_Y_PLATEAU - raquette->longueur / 2;
	}
	else if (raquette->y + raquette->longueur / 2 <= MAX_Y_PLATEAU)
	{
		raquette->y += raquette->vy;
	}
}

void down(Raquette *raquette)
{
	if (raquette->y - raquette->vy - raquette->longueur / 2 <= MIN_Y_PLATEAU)
	{
		raquette->y = MIN_Y_PLATEAU + raquette->longueur / 2;
	}
	else if (raquette->y - raquette->longueur / 2 >= MIN_Y_PLATEAU)
	{
		raquette->y -= raquette->vy;
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
	for (float i = 0; i < 2 * M_PI; i = i + 0.01)
	{
		if (balle->x + cosf(i) * balle->r <= raquette->x + raquette->largeur / 2 && balle->x + cosf(i) * balle->r >= raquette->x - raquette->largeur / 2 &&
			balle->y + sinf(i) * balle->r <= raquette->y + raquette->longueur / 2 && balle->y + sinf(i) * balle->r >= raquette->y - raquette->longueur / 2)
		{
			if (
				(balle->x >= raquette->x + raquette->largeur / 2 || balle->x <= raquette->x - raquette->largeur / 2) &&
				balle->y <= raquette->y + raquette->longueur / 2 &&
				balle->y >= raquette->y - raquette->longueur / 2)
			{
				balle->vx = -cosf(M_PI_4 * (balle->y - raquette->y) / (raquette->longueur / 2)) * balle->v0 * (balle->vx / fabsf(balle->vx));
				balle->vy = fabsf(sinf(M_PI_4 * (balle->y - raquette->y) / (raquette->longueur / 2))) * balle->v0 * (balle->vy / fabsf(balle->vy));
			}
			else if (
				(balle->y >= raquette->y + raquette->longueur / 2 || balle->y <= raquette->y - raquette->longueur / 2) &&
				balle->x <= raquette->x + raquette->largeur / 2 &&
				balle->x >= raquette->x - raquette->largeur / 2)
				balle->vy = -balle->vy;
			else
			{
				balle->vx = -balle->vx;
				balle->vy = -balle->vy;
			}
			balle->x += balle->vx;
			balle->y += balle->vy;
		}
	}
}

void but(Balle *balle, int score[])
{
	bool coteBut;
	if (balle->x - balle->r < MIN_X_PLATEAU || balle->x + balle->r > MAX_X_PLATEAU)
	{
		if (balle->x - balle->r < MIN_X_PLATEAU)
		{
			score[1] += 1;
			coteBut = true;
		}

		if (balle->x + balle->r > MAX_X_PLATEAU)
		{
			score[0] += 1;
			coteBut = false;
		}
				
		balle->x = MID_X;
		balle->y = (MAX_Y_PLATEAU - MIN_Y_PLATEAU) / 2;
		balle->r = 7;
		balle->v0 = 7;
		balle->vx = (coteBut) ? 5 : -5;
		balle->vy = 0.0001;
		
	}
}