#include "moteur.h"

void initPages(Page *page)
{
	page->numero = 1;
	page->pause = false;
	initSelect(page->select);
}
void initSelect(int *select)
{
	for (int i = 0; i <= NB_SELECT; i++)
		select[i] = 1;
}
void initBallesAccueil(Balle *balle)
{
	for (int i = 0; i < MAX_BALLE; i++)
	{
		balle[i].x = rand() % largeurFenetre();
		balle[i].y = rand() % hauteurFenetre();
		balle[i].r = 10;
		balle[i].v0 = 5;
		balle[i].vx = (rand() % 2) ? 5 : -5;
		balle[i].vy = (rand() % 2) ? 5 : -5;
	}
}
void initRaquettes(Raquette *raquette)
{
	for (int i = 0; i < NB_RAQUETTE; i++)
	{
		raquette[i].longueur = 100;
		raquette[i].largeur = 10;
		raquette[i].x = (i % 2) ? RAQUETTE_X_RIGHT : RAQUETTE_X_LEFT;
		raquette[i].y = (MAX_Y_PLATEAU + MIN_Y_PLATEAU) / 2;
		raquette[i].vy = 15;
		raquette[i].up = (i % 2) ? 'p' : 'a';
		raquette[i].down = (i % 2) ? 'm' : 'q';
	}
}
void initBalleJeu(Balle *balle)
{
	balle->x = MID_X;
	balle->y = (MAX_Y_PLATEAU - MIN_Y_PLATEAU) / 2;
	balle->r = 7;
	balle->v0 = 5;
	balle->vx = balle->v0;
	balle->vy = 0.1;
}

void initScore(int *score)
{
	for (int i = 0; i < 2; i++)
		score[i] = 0;
}

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

void selectPause(int *select)
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

void redimRaquette(Raquette *raquette, int i)
{
	if (raquette->y + raquette->longueur / 2 >= MAX_Y_PLATEAU)
		raquette->y = MAX_Y_PLATEAU - raquette->longueur / 2;
	if (raquette->y - raquette->longueur / 2 <= MIN_Y_PLATEAU)
		raquette->y = MIN_Y_PLATEAU + raquette->longueur / 2;
	raquette->x = (i % 2) ? RAQUETTE_X_RIGHT : RAQUETTE_X_LEFT;
}
void touchePause(Page *page)
{
	if (caractereClavier() == 'g' || caractereClavier() == 'G')
		page->pause = (page->pause) ? false : true;
}
void touches(Raquette *raquette)
{
	if (caractereClavier() == raquette->up)
		up(raquette);
	else if (caractereClavier() == raquette->down)
		down(raquette);
}

void up(Raquette *raquette)
{
	if (raquette->y + raquette->vy + raquette->longueur / 2 >= MAX_Y_PLATEAU)
		raquette->y = MAX_Y_PLATEAU - raquette->longueur / 2;
	else if (raquette->y + raquette->longueur / 2 <= MAX_Y_PLATEAU)
		raquette->y += raquette->vy;
}

void down(Raquette *raquette)
{
	if (raquette->y - raquette->vy - raquette->longueur / 2 <= MIN_Y_PLATEAU)
		raquette->y = MIN_Y_PLATEAU + raquette->longueur / 2;
	else if (raquette->y - raquette->longueur / 2 >= MIN_Y_PLATEAU)
		raquette->y -= raquette->vy;
}
void nombre(int score, bool *digit)
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

void but(Balle *balle, int *score)
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
			score[0]++;
			balle->vx = -balle->v0;
		}

		balle->x = MID_X;
		balle->y = (MAX_Y_PLATEAU - MIN_Y_PLATEAU) / 2;
		balle->vy = 0.1;
	}
}

void IA(Balle *balle, Raquette *raquette)
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