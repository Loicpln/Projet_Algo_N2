#include "moteur.h"

void mouvementBalle(Balle *const balle)
{
	balle->x += balle->vx;
	balle->y += balle->vy;
}

void rebond(Balle *const balle, const int min_x, const int min_y, const int max_x, const int max_y)
{
	if (balle->x - balle->r < min_x || balle->x + balle->r > max_x)
		balle->vx = -balle->vx;
	if (balle->y - balle->r < min_y || balle->y + balle->r > max_y)
		balle->vy = -balle->vy;
}

void accelereBalle(Balle *const balle, const float facteur)
{
	balle->vx *= facteur;
	balle->vy *= facteur;
}

void couleurSelect(Select *const select, const int R, const int V, const int B)
{
	select->couleur[0] = R;
	select->couleur[1] = V;
	select->couleur[2] = B;
}

void touchePause(Page *const page)
{
	if (caractereClavier() == 'g' || caractereClavier() == 'G')
		page->pause = (page->pause) ? false : true;
}

void ecrire(char newPseudo[])
{
	char a[15] = "";
	if ((caractereClavier() == 8) && (strcmp(newPseudo, "") != 0))
	{
		strncpy(a, newPseudo, strlen(newPseudo) - 1);
		strcat(a, "\0");
		strcpy(newPseudo, a);
	}
	else if (caractereClavier() > 31)
		for (int i = 0; i < 15; i++)
			if (newPseudo[i] == '\0')
			{
				newPseudo[i] = caractereClavier();
				newPseudo[i + 1] = '\0';
				break;
			}
}

void touches(Raquette *const raquette)
{
	if (caractereClavier() == raquette->up)
		up(raquette);
	else if (caractereClavier() == raquette->down)
		down(raquette);
}

void up(Raquette *const raquette)
{
	if (raquette->y + raquette->vy + raquette->longueur / 2 >= MAX_Y_PLATEAU)
		raquette->y = MAX_Y_PLATEAU - raquette->longueur / 2;
	else if (raquette->y + raquette->longueur / 2 <= MAX_Y_PLATEAU)
		raquette->y += raquette->vy;
}

void down(Raquette *const raquette)
{
	if (raquette->y - raquette->vy - raquette->longueur / 2 <= MIN_Y_PLATEAU)
		raquette->y = MIN_Y_PLATEAU + raquette->longueur / 2;
	else if (raquette->y - raquette->longueur / 2 >= MIN_Y_PLATEAU)
		raquette->y -= raquette->vy;
}

Digit nombre(const int score)
{
	switch (score)
	{
	case 0:
		return DIGIT_0;
	case 1:
		return DIGIT_1;
	case 2:
		return DIGIT_2;
	case 3:
		return DIGIT_3;
	case 4:
		return DIGIT_4;
	case 5:
		return DIGIT_5;
	case 6:
		return DIGIT_6;
	case 7:
		return DIGIT_7;
	case 8:
		return DIGIT_8;
	case 9:
		return DIGIT_9;
	default:
		return DIGIT_ERROR;
	}
}

int signe(const float val) { return val / fabsf(val); }

void hitbox(Balle *const balle, const Raquette *const raquette)
{
	for (float i = 0.f; i < 2 * M_PI; i += 0.01f)
		if (raquette->x - raquette->largeur / 2 - cosf(i) * balle->r < X_BALLE < raquette->x + raquette->largeur / 2 - cosf(i) * balle->r &&
			raquette->y - raquette->longueur / 2 - sinf(i) * balle->r < Y_BALLE < raquette->y + raquette->longueur / 2 - sinf(i) * balle->r)
		{
			if (balle->x >= raquette->x + raquette->largeur / 2 || balle->x <= raquette->x - raquette->largeur / 2)
			{
				balle->vx = -cosf(M_PI / 4 * (balle->y - raquette->y) / (raquette->longueur / 2)) * balle->v0 * signe(balle->vx);
				balle->vy = sinf(M_PI / 4 * fabsf(balle->y - raquette->y) / (raquette->longueur / 2)) * balle->v0 * signe(balle->vy);
			}
			else if (balle->y >= raquette->y + raquette->longueur / 2 || balle->y <= raquette->y - raquette->longueur / 2)
			{
				balle->vx = sinf(M_PI / 4 * fabsf(balle->x - raquette->x) / (raquette->largeur / 2)) * balle->v0 * signe(balle->vx);
				balle->vy = -cosf(M_PI / 4 * (balle->x - raquette->x) / (raquette->largeur / 2)) * balle->v0 * signe(balle->vy);
			}
			else
			{
				balle->vx = M_SQRT1_2 * balle->v0 * signe(balle->vx);
				balle->vy = -M_SQRT1_2 * balle->v0 * signe(balle->vy);
				for (int i = 0; i < 3; i++)
					mouvementBalle(balle);
			}
			mouvementBalle(balle);
			break;
		}
}

void but(Balle *const balle, Joueur *const joueur)
{
	if (balle->x + balle->r < MIN_X_PLATEAU || balle->x - balle->r > MAX_X_PLATEAU)
	{
		if (balle->x < MIN_X_PLATEAU)
		{
			joueur[1].score++;
			balle->vx = balle->v0;
		}
		if (balle->x > MAX_X_PLATEAU)
		{
			joueur[0].score++;
			balle->vx = -balle->v0;
		}
		balle->x = MID_X;
		balle->y = (MAX_Y_PLATEAU + MIN_Y_PLATEAU) / 2;
		balle->vy = VH_BALLE;
	}
}

void IA(Raquette *const raquette, const Balle *const balle)
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
				if (y > raquette->y)
					raquette->y++;
				if (y < raquette->y)
					raquette->y--;
			}
		}
		else
		{
			if ((MIN_Y_PLATEAU + MAX_Y_PLATEAU) / 2 > raquette->y)
				raquette->y++;
			if ((MIN_Y_PLATEAU + MAX_Y_PLATEAU) / 2 < raquette->y)
				raquette->y--;
		}
	}
}