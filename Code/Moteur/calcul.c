#include "moteur.h"

void mouvementBalle(Balle * const balle)
{
	balle->x += balle->vx;
	balle->y += balle->vy;
}

void rebond(Balle * const balle, const int min_x, const int min_y, const int max_x, const int max_y)
{
	if (balle->x - balle->r < min_x || balle->x + balle->r > max_x)
		balle->vx = -balle->vx;
	if (balle->y - balle->r < min_y || balle->y + balle->r > max_y)
		balle->vy = -balle->vy;
}

void redimBalle(Balle * const balle)
{
	if (balle->x >= largeurFenetre())
		balle->x = largeurFenetre() - 1;
	if (balle->y >= hauteurFenetre())
		balle->y = hauteurFenetre() - 1;
}

void accelereBalle(Balle * const balle, const float a)
{
	balle->vx *= a;
	balle->vy *= a;
}

void selectPause(int * const select)
{
	if (abscisseSouris() > 7 * largeurFenetre() / 20 && abscisseSouris() < 13 * largeurFenetre() / 20 && ordonneeSouris() > 11 * hauteurFenetre() / 20 && ordonneeSouris() < 13 * hauteurFenetre() / 20)
	{
		initSelect(select);
		select[0] = 5;
	}
	else if (abscisseSouris() > 7 * largeurFenetre() / 20 && abscisseSouris() < 13 * largeurFenetre() / 20 && ordonneeSouris() > 7 * hauteurFenetre() / 20 && ordonneeSouris() < 9 * hauteurFenetre() / 20)
	{
		initSelect(select);
		select[1] = 5;
	}
	else if (abscisseSouris() > 7 * largeurFenetre() / 20 && abscisseSouris() < 13 * largeurFenetre() / 20 && ordonneeSouris() > 3 * hauteurFenetre() / 20 && ordonneeSouris() < 5 * hauteurFenetre() / 20)
	{
		initSelect(select);
		select[2] = 5;
	}
	else
		initSelect(select);
}

void redimRaquette(Raquette * const raquette, const int i)
{
	if (raquette->y + raquette->longueur / 2 >= MAX_Y_PLATEAU)
		raquette->y = MAX_Y_PLATEAU - raquette->longueur / 2;
	if (raquette->y - raquette->longueur / 2 <= MIN_Y_PLATEAU)
		raquette->y = MIN_Y_PLATEAU + raquette->longueur / 2;
	raquette->x = (i % 2) ? RAQUETTE_X_RIGHT : RAQUETTE_X_LEFT;
}
void touchePause(Page * const page)
{
	if (caractereClavier() == 'g' || caractereClavier() == 'G')
		page->pause = (page->pause) ? false : true;
}
void touches(Raquette * const raquette)
{
	if (caractereClavier() == raquette->up)
		up(raquette);
	else if (caractereClavier() == raquette->down)
		down(raquette);
}

void up(Raquette * const raquette)
{
	if (raquette->y + raquette->vy + raquette->longueur / 2 >= MAX_Y_PLATEAU)
		raquette->y = MAX_Y_PLATEAU - raquette->longueur / 2;
	else if (raquette->y + raquette->longueur / 2 <= MAX_Y_PLATEAU)
		raquette->y += raquette->vy;
}

void down(Raquette * const raquette)
{
	if (raquette->y - raquette->vy - raquette->longueur / 2 <= MIN_Y_PLATEAU)
		raquette->y = MIN_Y_PLATEAU + raquette->longueur / 2;
	else if (raquette->y - raquette->longueur / 2 >= MIN_Y_PLATEAU)
		raquette->y -= raquette->vy;
}
void nombre(bool * const digit, const int score)
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
void hitbox(Balle * const balle, const Raquette * const raquette)
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
				balle->vx = -cosf(M_PI / 3 * (balle->y - raquette->y) / (raquette->longueur / 2)) * balle->v0 * (balle->vx / fabsf(balle->vx));
				balle->vy = fabsf(sinf(M_PI / 3 * (balle->y - raquette->y) / (raquette->longueur / 2))) * balle->v0 * (balle->vy / fabsf(balle->vy));
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

void but(Balle * const balle, int * const score)
{
	if (balle->x + balle->r < MIN_X_PLATEAU || balle->x - balle->r > MAX_X_PLATEAU)
	{
		if (balle->x < MIN_X_PLATEAU)
		{
			score[1]++;
			balle->vx = balle->v0;
		}

		if (balle->x > MAX_X_PLATEAU)
		{
			score[0]++;;
			balle->vx = -balle->v0;
		}

		balle->x = MID_X;
		balle->y = (MAX_Y_PLATEAU - MIN_Y_PLATEAU) / 2;
		balle->vy = 0.1;
	}
}

void IA(Balle * const balle, Raquette * const raquette)
{
	float x = balle->x, y = balle->y, vy = balle->vy;
	if (x < raquette->x)
	{
		if (balle->vx > 0)
		{
			while (x < raquette->x - raquette->largeur / 2)
			{
				x += balle->vx;
				if (y < MIN_Y_PLATEAU || MAX_Y_PLATEAU < y)
					vy = -vy;
				y += vy;
			}

			if (raquette->y >= MIN_Y_PLATEAU + raquette->longueur / 2 && raquette->y <= MAX_Y_PLATEAU - raquette->longueur / 2)
			{
				if (y < raquette->y)
					raquette->y--;

				if (y > raquette->y)
					raquette->y++;
			}
		}
		else
		{
			if ((MIN_Y_PLATEAU + MAX_Y_PLATEAU) / 2 < raquette->y)
				raquette->y--;

			if ((MIN_Y_PLATEAU + MAX_Y_PLATEAU) / 2 > raquette->y)
				raquette->y++;
		}
	}
}