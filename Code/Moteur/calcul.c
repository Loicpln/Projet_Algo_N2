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
void selectAcceuil(Select *const select)
{
	resetSelect(select);
	if (30 * Ux < X_SOURIS < 70 * Ux && 65 * Uy < Y_SOURIS < 80 * Uy)
		select[0].largeur = L_SELECT;
	if (35 * Ux < X_SOURIS < 65 * Ux && 45 * Uy < Y_SOURIS < 60 * Uy)
		select[1].largeur = L_SELECT;
	if (75 * Ux < X_SOURIS < 95 * Ux && 5 * Uy < Y_SOURIS < 15 * Uy)
		select[2].largeur = L_SELECT;
}
void selectMenu(Select *const select)
{
	resetSelect(select);
	if (25 * Ux < X_SOURIS < 75 * Ux && 67 * Uy < Y_SOURIS < 79 * Uy)
		select[0].largeur = L_SELECT;
	if (25 * Ux < X_SOURIS < 75 * Ux && 50 * Uy < Y_SOURIS < 63 * Uy)
		select[1].largeur = L_SELECT;
	if (25 * Ux < X_SOURIS < 75 * Ux && 33 * Uy < Y_SOURIS < 46 * Uy)
		select[2].largeur = L_SELECT;
	if (75 * Ux < X_SOURIS < 95 * Ux && 5 * Uy < Y_SOURIS < 15 * Uy)
		select[3].largeur = L_SELECT;
}
void selectRegles(Select *const select)
{
	resetSelect(select);
	if (75 * Ux < X_SOURIS < 95 * Ux && 5 * Uy < Y_SOURIS < 15 * Uy)
		select[1].largeur = L_SELECT;
}
void selectPause(Select *const select)
{
	resetSelect(select);
	if (35 * Ux < X_SOURIS < 65 * Ux && 55 * Uy < Y_SOURIS < 65 * Uy)
		select[0].largeur = L_SELECT;
	if (35 * Ux < X_SOURIS < 65 * Ux && 35 * Uy < Y_SOURIS < 45 * Uy)
		select[1].largeur = L_SELECT;
	if (35 * Ux < X_SOURIS < 65 * Ux && 15 * Uy < Y_SOURIS < 25 * Uy)
		select[2].largeur = L_SELECT;
}
void clicPause(Data *const data)
{
	if (35 * Ux < X_SOURIS < 65 * Ux && 55 * Uy < Y_SOURIS < 65 * Uy)
		data->page.pause = false;
	if (35 * Ux < X_SOURIS < 65 * Ux && 35 * Uy < Y_SOURIS < 45 * Uy)
	{
		data->page.pause = false;
		data->balleJeu = initBalleJeu();
		resetRaquette(data->joueurs);
		resetScore(data->joueurs);
	}
	if (35 * Ux < X_SOURIS < 65 * Ux && 15 * Uy < Y_SOURIS < 25 * Uy)
	{
		data->page.pause = false;
		data->balleJeu = initBalleJeu();
		data->page.numero = Menu;
		resetJoueurs(data->joueurs);
		resetRaquette(data->joueurs);
		resetScore(data->joueurs);
	}
}
void clicRouage(Page *page)
{
	if (abs(abscisseSouris() - 88 * Ux) < r_Rouage && abs(ordonneeSouris() - 91 * Uy) < r_Rouage)
		page->pause = true;
}

void selectSelection(Select *const select)
{
	resetSelect(select);
	for (int i = 0; i < NB_USERS; i++)
	{
		if (2 * Ux + 20 * (i % 5) * Ux < X_SOURIS < 18 * Ux + 20 * (i % 5) * Ux && 56 * Uy - 35 * floor(i / 5) * Uy < Y_SOURIS < 83 * Uy - 35 * floor(i / 5) * Uy)
			select[i].largeur = L_SELECT;
		if (15 * Ux + 20 * (i % 5) * Ux < X_SOURIS < 18 * Ux + 20 * (i % 5) * Ux && 56 * Uy - 35 * floor(i / 5) * Uy < Y_SOURIS < 60 * Uy - 35 * floor(i / 5) * Uy)
			select[i + NB_USERS].largeur = L_SELECT;
	}
	if (30 * Ux < X_SOURIS < 70 * Ux && 5 * Uy < Y_SOURIS < 15 * Uy)
		select[48].largeur = L_SELECT;
	if (75 * Ux < X_SOURIS < 95 * Ux && 5 * Uy < Y_SOURIS < 15 * Uy)
		select[49].largeur = L_SELECT;
}
void clicUsers(Joueur *const joueur, Users *users)
{
	const User *tmp = users->premier;
	for (int i = 0; tmp != NULL; i++, tmp = tmp->userSuivant)
	{
		if (15 * Ux + 20 * (i % 5) * Ux < X_SOURIS < 18 * Ux + 20 * (i % 5) * Ux && 56 * Uy - 35 * floor(i / 5) * Uy < Y_SOURIS < 60 * Uy - 35 * floor(i / 5) * Uy)
		{
			if (rechercheUser(users, 0) != NULL)
				users = supprimeDansUsers(users, i);
		}
		else if (2 * Ux + 20 * (i % 5) * Ux < X_SOURIS < 18 * Ux + 20 * (i % 5) * Ux && 56 * Uy - 35 * floor(i / 5) * Uy < Y_SOURIS < 83 * Uy - 35 * floor(i / 5) * Uy)
		{
			if (rechercheUser(users, 0) != NULL)
				joueur->user = rechercheUser(users, i);
		}
	}
}

void resetJoueurs(Joueur *const joueur)
{
	for (int i = 0; i < NB_JOUEUR; i++)
		joueur[i].user = NULL;
}
void resetRaquette(Joueur *const joueur)
{
	for (int i = 0; i < NB_JOUEUR; i++)
		joueur[i].raquette = (i % 2) ? initRaquetteD() : initRaquetteG();
}
void resetScore(Joueur *const joueur)
{
	for (int i = 0; i < NB_JOUEUR; i++)
		joueur[i].score = initScore();
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
	else if(caractereClavier() > 31)
	{
		for (int i = 0; i < 15; i++)
		{
			if (newPseudo[i] == '\0')
			{
				newPseudo[i] = caractereClavier();
				newPseudo[i + 1] = '\0';
				break;
			}
		}
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
		if (balle->x + cosf(i) * balle->r <= raquette->x + raquette->largeur / 2 &&
			balle->x + cosf(i) * balle->r >= raquette->x - raquette->largeur / 2 &&
			balle->y + sinf(i) * balle->r <= raquette->y + raquette->longueur / 2 &&
			balle->y + sinf(i) * balle->r >= raquette->y - raquette->longueur / 2)
		{
			if (balle->x >= raquette->x + raquette->largeur / 2 || balle->x <= raquette->x - raquette->largeur / 2)
			{
				balle->x += balle->vx = -cosf(M_PI / 3 * (balle->y - raquette->y) / (raquette->longueur / 2)) * balle->v0 * signe(balle->vx);
				balle->y += balle->vy = sinf(M_PI / 3 * fabsf(balle->y - raquette->y) / (raquette->longueur / 2)) * balle->v0 * signe(balle->vy);
			}
			else
			{
				balle->x += balle->vx = sinf(M_PI / 3 * fabsf(balle->x - raquette->x) / (raquette->largeur / 2)) * balle->v0 * signe(balle->vx);
				balle->y += balle->vy = -cosf(M_PI / 3 * (balle->x - raquette->x) / (raquette->largeur / 2)) * balle->v0 * signe(balle->vy);
			}
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
		balle->y = (MAX_Y_PLATEAU - MIN_Y_PLATEAU) / 2;
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