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
void couleurSelect(Select *const select,int i, int R, int V, int B){
	select[i].couleur[0] = R;
	select[i].couleur[1] = V;
	select[i].couleur[2] = B;
}

void selectPause(Select *const select)
{
	resetSelect(select);
	if (abscisseSouris() > 7 * largeurFenetre() / 20 && abscisseSouris() < 13 * largeurFenetre() / 20 && ordonneeSouris() > 11 * hauteurFenetre() / 20 && ordonneeSouris() < 13 * hauteurFenetre() / 20)
		select[0].largeur = 5;
	else if (abscisseSouris() > 7 * largeurFenetre() / 20 && abscisseSouris() < 13 * largeurFenetre() / 20 && ordonneeSouris() > 7 * hauteurFenetre() / 20 && ordonneeSouris() < 9 * hauteurFenetre() / 20)
		select[1].largeur = 5;
	else if (abscisseSouris() > 7 * largeurFenetre() / 20 && abscisseSouris() < 13 * largeurFenetre() / 20 && ordonneeSouris() > 3 * hauteurFenetre() / 20 && ordonneeSouris() < 5 * hauteurFenetre() / 20)
		select[2].largeur = 5;
}

void selectSelection(Select *const select)
{
	resetSelect(select);
	if (abscisseSouris() > largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 && ordonneeSouris() > 99 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 99 * hauteurFenetre() / 120)
		select[0].largeur = 5;
	else if (abscisseSouris() > largeurFenetre() / 30 + 6 * largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 + 6 * largeurFenetre() / 30 && ordonneeSouris() > 99 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 99 * hauteurFenetre() / 120)
		select[1].largeur = 5;
	else if (abscisseSouris() > largeurFenetre() / 30 + 12 * largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 + 12 * largeurFenetre() / 30 && ordonneeSouris() > 99 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 99 * hauteurFenetre() / 120)
		select[2].largeur = 5;
	else if (abscisseSouris() > largeurFenetre() / 30 + 18 * largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 + 18 * largeurFenetre() / 30 && ordonneeSouris() > 99 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 99 * hauteurFenetre() / 120)
		select[3].largeur = 5;
	else if (abscisseSouris() > largeurFenetre() / 30 + 24 * largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 + 24 * largeurFenetre() / 30 && ordonneeSouris() > 99 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 99 * hauteurFenetre() / 120)
		select[4].largeur = 5;
	else if (abscisseSouris() > largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 && ordonneeSouris() > 59 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 59 * hauteurFenetre() / 120)
		select[5].largeur = 5;
	else if (abscisseSouris() > largeurFenetre() / 30 + 6 * largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 + 6 * largeurFenetre() / 30 && ordonneeSouris() > 59 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 59 * hauteurFenetre() / 120)
		select[6].largeur = 5;
	else if (abscisseSouris() > largeurFenetre() / 30 + 12 * largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 + 12 * largeurFenetre() / 30 && ordonneeSouris() > 59 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 59 * hauteurFenetre() / 120)
		select[7].largeur = 5;
	else if (abscisseSouris() > largeurFenetre() / 30 + 18 * largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 + 18 * largeurFenetre() / 30 && ordonneeSouris() > 59 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 59 * hauteurFenetre() / 120)
		select[8].largeur = 5;
	else if (abscisseSouris() > largeurFenetre() / 30 + 24 * largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 + 24 * largeurFenetre() / 30 && ordonneeSouris() > 59 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 59 * hauteurFenetre() / 120)
		select[9].largeur = 5;
	else if (abscisseSouris() > 5 * largeurFenetre() / 16 && abscisseSouris() < 11 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
		select[10].largeur = 5;
	else if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
		select[11].largeur = 5;
}
void clicUsers(Joueur *const joueur, User *const users)
{
	if (abscisseSouris() > largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 && ordonneeSouris() > 99 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 99 * hauteurFenetre() / 120)
		joueur->user = rechercheUser(users, 0);
	else if (abscisseSouris() > largeurFenetre() / 30 + 6 * largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 + 6 * largeurFenetre() / 30 && ordonneeSouris() > 99 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 99 * hauteurFenetre() / 120)
		joueur->user = rechercheUser(users, 1);
	else if (abscisseSouris() > largeurFenetre() / 30 + 12 * largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 + 12 * largeurFenetre() / 30 && ordonneeSouris() > 99 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 99 * hauteurFenetre() / 120)
		joueur->user = rechercheUser(users, 2);
	else if (abscisseSouris() > largeurFenetre() / 30 + 18 * largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 + 18 * largeurFenetre() / 30 && ordonneeSouris() > 99 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 99 * hauteurFenetre() / 120)
		joueur->user = rechercheUser(users, 3);
	else if (abscisseSouris() > largeurFenetre() / 30 + 24 * largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 + 24 * largeurFenetre() / 30 && ordonneeSouris() > 99 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 99 * hauteurFenetre() / 120)
		joueur->user = rechercheUser(users, 4);
	else if (abscisseSouris() > largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 && ordonneeSouris() > 59 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 59 * hauteurFenetre() / 120)
		joueur->user = rechercheUser(users, 5);
	else if (abscisseSouris() > largeurFenetre() / 30 + 6 * largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 + 6 * largeurFenetre() / 30 && ordonneeSouris() > 59 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 59 * hauteurFenetre() / 120)
		joueur->user = rechercheUser(users, 6);
	else if (abscisseSouris() > largeurFenetre() / 30 + 12 * largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 + 12 * largeurFenetre() / 30 && ordonneeSouris() > 59 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 59 * hauteurFenetre() / 120)
		joueur->user = rechercheUser(users, 7);
	else if (abscisseSouris() > largeurFenetre() / 30 + 18 * largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 + 18 * largeurFenetre() / 30 && ordonneeSouris() > 59 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 59 * hauteurFenetre() / 120)
		joueur->user = rechercheUser(users, 8);
	else if (abscisseSouris() > largeurFenetre() / 30 + 24 * largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 + 24 * largeurFenetre() / 30 && ordonneeSouris() > 59 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 59 * hauteurFenetre() / 120)
		joueur->user = rechercheUser(users, 9);
}

void resetJoueurs(Joueur * const joueur)
{
	for (int i = 0; i < NB_JOUEUR; i++)
		joueur[i].user = NULL;
}
void resetRaquette(Joueur * const joueur)
{
	for (int i = 0; i < NB_JOUEUR; i++)
		joueur[i].raquette = (i % 2) ? initRaquetteD() : initRaquetteG();
}
void resetScore(Joueur * const joueur)
{
	for (int i = 0; i < NB_JOUEUR; i++)
        joueur[i].score = initScore();
}
void touchePause(Page *const page)
{
	if (caractereClavier() == 'g' || caractereClavier() == 'G')
		page->pause = (page->pause) ? false : true;
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
void nombre(bool *const digit, const int score)
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
void hitbox(Balle *const balle, const Raquette *const raquette)
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
			;
			balle->vx = -balle->v0;
		}
		balle->x = MID_X;
		balle->y = (MAX_Y_PLATEAU - MIN_Y_PLATEAU) / 2;
		balle->vy = 0.1;
	}
}

void IA(Balle *const balle, Raquette *const raquette)
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