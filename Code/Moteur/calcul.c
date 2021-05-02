#include "moteur.h"
//Mouvement de le balle
void mouvementBalle(Balle *const balle)
{
	balle->x += balle->vx;
	balle->y += balle->vy;
}
//Rebond de la balle
void rebond(Balle *const balle, const int min_x, const int min_y, const int max_x, const int max_y)
{
	if (balle->x - balle->r < min_x || balle->x + balle->r > max_x)
		balle->vx = -balle->vx;
	if (balle->y - balle->r < min_y || balle->y + balle->r > max_y)
		balle->vy = -balle->vy;
}
//Acceleration de la balle
void accelereBalle(Balle *const balle, const float facteur)
{
	balle->vx *= facteur;
	balle->vy *= facteur;
}
//Coloration des bordures de boutons
void couleurSelect(Select *const select, const int R, const int V, const int B)
{
	select->couleur[0] = R;
	select->couleur[1] = V;
	select->couleur[2] = B;
}
//Raccourci du menu pause
void touchePause(Page *const page)
{
	if (caractereClavier() == 'g' || caractereClavier() == 'G')
		page->pause = (page->pause) ? false : true;
}
//Ecriture du nouveau pseudo
void ecrire(char *newPseudo)
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
//mouvement de la raquette
void touches(Raquette *const raquette)
{
	if (caractereClavier() == raquette->up)
		up(raquette);
	else if (caractereClavier() == raquette->down)
		down(raquette);
}
//Si la touche pour up est séléctionne la raquette monte
void up(Raquette *const raquette)
{
	if (raquette->y + raquette->vy + raquette->longueur / 2 >= MAX_Y_PLATEAU)
		raquette->y = MAX_Y_PLATEAU - raquette->longueur / 2;
	else if (raquette->y + raquette->longueur / 2 <= MAX_Y_PLATEAU)
		raquette->y += raquette->vy;
}
//Si la touche pour down est séléctionne la raquette descend
void down(Raquette *const raquette)
{
	if (raquette->y - raquette->vy - raquette->longueur / 2 <= MIN_Y_PLATEAU)
		raquette->y = MIN_Y_PLATEAU + raquette->longueur / 2;
	else if (raquette->y - raquette->longueur / 2 >= MIN_Y_PLATEAU)
		raquette->y -= raquette->vy;
}
//Change un nombre 'int' en 'Digit'
Digit nombre(const int score)
{
	switch (score)
	{
	case 0:
		return DIGIT_0;//Chaque digit est créé dans "lib.h" (Ctrl + clic droit sur DIGIT_0 pour emmener au fichier sur VSC)
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
//Recupère le signe de la variable
int signe(const float val) { return val / fabsf(val); }
//Gère la hitbox entre la balle et la raquette
void hitbox(Balle *const balle, const Raquette *const raquette)
{
	for (float i = 0.f; i < 2 * M_PI; i += 0.01f)
		if (raquette->x - raquette->largeur / 2 - balle->vx < X_BALLE < raquette->x + raquette->largeur / 2 - balle->vx &&
			raquette->y - raquette->longueur / 2 - raquette->vy < Y_BALLE < raquette->y + raquette->longueur / 2 + raquette->vy)
		{
			if (balle->x + balle->vx > raquette->x + raquette->largeur / 2 || balle->x + balle->vx < raquette->x - raquette->largeur / 2)
			{
				balle->vx = -cosf(M_PI / 4 * (balle->y - raquette->y) / (raquette->longueur / 2)) * balle->v0 * signe(balle->vx);
				balle->vy = sinf(M_PI / 4 * fabsf(balle->y - raquette->y) / (raquette->longueur / 2)) * balle->v0 * signe(balle->vy);
			}
			else
			{
				balle->vx = sinf(M_PI / 4 * fabsf(balle->x - raquette->x) / (raquette->largeur / 2)) * balle->v0 * signe(balle->vx);
				balle->vy = -cosf(M_PI / 4 * (balle->x - raquette->x) / (raquette->largeur / 2)) * balle->v0 * signe(balle->vy);
			}
			if (balle->vx == 0)
				balle->vx = VH_BALLE;
			if (balle->vy == 0)
				balle->vy = VH_BALLE;
			break;
		}
}
//Gère si il y a un but selon le joueur
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
//Gère l'évènement de jeu
void jeu(Data *const data)
{
	mouvementBalle(&data->balleJeu);
	for (int i = 0; i < NB_JOUEUR; i++)
		hitbox(&data->balleJeu, &data->joueurs[i].raquette);
	if (data->joueurs[0].user->id == id_IA)
		IA(&data->joueurs[0].raquette, &data->balleJeu, Gauche);
	if (data->joueurs[1].user->id == id_IA)
		IA(&data->joueurs[1].raquette, &data->balleJeu, Droite);
	rebond(&data->balleJeu, -MAX_X, MIN_Y_PLATEAU, 2 * MAX_X, MAX_Y_PLATEAU);
	but(&data->balleJeu, data->joueurs);
	if (data->option.mode == ContreLaMontre)
	{
		decompte(data->timer);
		if (data->timer[0] == 0 && data->timer[1] == 0)
		{
			data->page.numero = Resultats;
			resetBalle(&data->balleJeu, data->option);
			resetRaquette(data->joueurs, data->option);
			resetTimer(data->timer, data->option);
		}
	}
	else if (data->joueurs[0].score == data->option.nbButs || data->joueurs[1].score == data->option.nbButs)
	{
		data->page.numero = Resultats;
		resetRaquette(data->joueurs, data->option);
		resetBalle(&data->balleJeu, data->option);
	}
}
//Fait le décompte chaque seconde du temps
void decompte(int *temps)
{
	static int tmp = 0;
	if (++tmp == 1000 / RafraichissementFenetre)
	{
		if (temps[1] == 0)
		{
			temps[1] = 59;
			temps[0]--;
		}
		else
			temps[1]--;
		tmp = 0;
	}
}
//Gère les calculs de l'IA pour déplacer la raquette
void IA(Raquette *const raquette, const Balle *const balle, const bool side)
{
	float x = balle->x, y = balle->y, vy = balle->vy;
	if ((side) ? (x < raquette->x) : (x > raquette->x))
	{
		if ((side) ? (balle->vx > 0) : (balle->vx < 0))
		{
			while ((side) ? (x < raquette->x - raquette->largeur / 2) : (x > raquette->x + raquette->largeur / 2))
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
