#include "moteur.h"

//Ensemble des fonctions de calcul

void mouvementBalle(Balle *const balle)
{
	balle->x += balle->vx;
	balle->y += balle->vy;
}

void rebond(Balle *const balle, const float min_x, const float min_y, const float max_x, const float max_y)
{
	// Inverse la vitesse de la balle selon le bord
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

void ecrire(char *newPseudo)
{
	char a[15] = "";
	if (caractereClavier() == 8 && strcmp(newPseudo, "")) // Suppression du dernier caractère
	{
		strncpy(a, newPseudo, strlen(newPseudo) - 1);
		strcat(a, "\0");
		strcpy(newPseudo, a);
	}
	else if (caractereClavier() > 31)
		for (int i = 0; i < 15; i++)// Cherche la fin de la chaine
			if (newPseudo[i] == '\0')
			{
				newPseudo[i] = caractereClavier(); // Ajoute en fin de chaine le dernier caractère saisi
				newPseudo[i + 1] = '\0';
				break;
			}
}

void touches(Raquette *const raquette)
{
	if (caractereClavier() == raquette->up || caractereClavier() == raquette->up - 32) // Si le caractère ou sa majuscule est tappée alors on monte la raquette
		up(raquette);
	else if (caractereClavier() == raquette->down || caractereClavier() == raquette->down - 32) // Si le caractère ou sa majuscule est tappée alors on descend la raquette
		down(raquette);
}

void up(Raquette *const raquette)
{
	if (raquette->y + raquette->vy + raquette->longueur / 2 >= MAX_Y_PLATEAU) // Limite pour monter la raquette
		raquette->y = MAX_Y_PLATEAU - raquette->longueur / 2;
	else if (raquette->y + raquette->longueur / 2 <= MAX_Y_PLATEAU)
		raquette->y += raquette->vy;
}

void down(Raquette *const raquette)
{
	if (raquette->y - raquette->vy - raquette->longueur / 2 <= MIN_Y_PLATEAU) // Limite pour descendre la raquette
		raquette->y = MIN_Y_PLATEAU + raquette->longueur / 2;
	else if (raquette->y - raquette->longueur / 2 >= MIN_Y_PLATEAU)
		raquette->y -= raquette->vy;
}

Digit nombre(const int score)
{
	//Chaque digit est créé dans "lib.h" (Ctrl + clic droit sur les DIGIT pour emmener au fichier sur VSC)
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
	for (float i = 0.f; i < 2 * M_PI; i += 0.01f) // Pour toute la circonference de la balle
		if (raquette->x - raquette->largeur / 2 - balle->vx < X_BALLE < raquette->x + raquette->largeur / 2 - balle->vx &&
			raquette->y - raquette->longueur / 2 - raquette->vy < Y_BALLE < raquette->y + raquette->longueur / 2 + raquette->vy) // Si la balle rentre en contact avec la raquette
		{
			if (balle->x + balle->vx > raquette->x + raquette->largeur / 2 ||
				balle->x + balle->vx < raquette->x - raquette->largeur / 2) // Si c'est par la gauche ou la droite
			{
				balle->vx = -cosf(M_PI / 4 * (balle->y - raquette->y) / (raquette->longueur / 2)) * balle->v0 * signe(balle->vx);	  // calcul pour gerer le rebond selon l'axe x et la position entre la balle et la raquette (Angle max Pi/4)
				balle->vy = sinf(M_PI / 4 * fabsf(balle->y - raquette->y) / (raquette->longueur / 2)) * balle->v0 * signe(balle->vy); // calcul pour gerer le rebond selon l'axe y et la position entre la balle et la raquette (Angle max Pi/4)
			}
			else // Si c'est par le haut ou le bas
			{
				balle->vx = sinf(M_PI / 4 * fabsf(balle->x - raquette->x) / (raquette->largeur / 2)) * balle->v0 * signe(balle->vx); // calcul pour gerer le rebond selon l'axe x et la position entre la balle et la raquette (Angle max Pi/4)
				balle->vy = -cosf(M_PI / 4 * (balle->x - raquette->x) / (raquette->largeur / 2)) * balle->v0 * signe(balle->vy);	 // calcul pour gerer le rebond selon l'axe y et la position entre la balle et la raquette (Angle max Pi/4)
			}
			// La vitesse de la balle ne dois pas etre nulle sinon elle ne pourras plus etre modifiée par la suite
			if (balle->vx == 0)
				balle->vx = VH_BALLE;
			if (balle->vy == 0)
				balle->vy = VH_BALLE;
			break;
		}
}

void but(Balle *const balle, Joueur *const joueur)
{
	if (balle->x + balle->r < MIN_X_PLATEAU || balle->x - balle->r > MAX_X_PLATEAU)
	{
		if (balle->x < MIN_X_PLATEAU) // But pour le coté gauche
		{
			joueur[1].score++;
			balle->vx = balle->v0;
		}
		if (balle->x > MAX_X_PLATEAU) // But pour le coté droit
		{
			joueur[0].score++;
			balle->vx = -balle->v0;
		}
		//Réinitialisation de la balle
		balle->x = MID_X;
		balle->y = (MAX_Y_PLATEAU + MIN_Y_PLATEAU) / 2;
		balle->vy = VH_BALLE;
	}
}

void jeu(Data *const data)
{
	mouvementBalle(&data->balleJeu);
	for (int i = 0; i < NB_JOUEUR; i++)
	{
		// On regarde la hitbox pour les 2 raquettes
		hitbox(&data->balleJeu, &data->joueurs[i].raquette);
		if (data->joueurs[i].user->id == id_IA) // Si l'utilisateur est l'IA
			IA(&data->joueurs[i].raquette, &data->balleJeu, (i) ? Droite : Gauche);
	}
	rebond(&data->balleJeu, -MAX_X, MIN_Y_PLATEAU, 2 * MAX_X, MAX_Y_PLATEAU); // Gère le rebond avec la bordure
	but(&data->balleJeu, data->joueurs);									  // Vérifie si il y a un but
	if (data->option.mode == ContreLaMontre)
	{
		decompte(data->timer);
		if (data->timer[0] == 0 && data->timer[1] == 0) // Si il n'y a plus de temps
		{
			data->page.numero = Resultats;
			resetBalle(&data->balleJeu, data->option);
			resetRaquette(data->joueurs, data->option);
			resetTimer(data->timer, data->option);
			if (data->joueurs[0].score > data->joueurs[1].score)
			{
				data->joueurs[0].user->nbWin++;
				data->joueurs[1].user->nbLose++;
			}
			else if (data->joueurs[0].score < data->joueurs[1].score)
			{
				data->joueurs[1].user->nbWin++;
				data->joueurs[0].user->nbLose++;
			}
			data->joueurs[0].user->nbGame++;
			data->joueurs[1].user->nbGame++;
		}
	}
	else if (data->joueurs[0].score == data->option.nbButs || data->joueurs[1].score == data->option.nbButs) // Si un des deux joueurs n'ont plus de vie
	{
		data->page.numero = Resultats;
		resetRaquette(data->joueurs, data->option);
		resetBalle(&data->balleJeu, data->option);
		if (data->joueurs[0].score > data->joueurs[1].score)
		{
			data->joueurs[0].user->nbWin++;
			data->joueurs[1].user->nbLose++;
		}
		else if (data->joueurs[0].score < data->joueurs[1].score)
		{
			data->joueurs[1].user->nbWin++;
			data->joueurs[0].user->nbLose++;
		}
		data->joueurs[0].user->nbGame++;
		data->joueurs[1].user->nbGame++;
	}
}

void decompte(int *temps)
{
	static int tmp = 0;
	if (++tmp == 1000 / RafraichissementFenetre) // Chaques secondes
	{
		if (temps[1] == 0)
		{
			temps[1] = 59;
			temps[0]--; // Décremente une minute
		}
		else
			temps[1]--; // Décremente une seconde
		tmp = 0;
	}
}

void IA(Raquette *const raquette, const Balle *const balle, const bool side)
{
	float x = balle->x, y = balle->y, vy = balle->vy;
	if ((side) ? (balle->vx > 0) : (balle->vx < 0)) // Si la balle va vers la raquette
	{
		while ((side) ? (x < raquette->x - raquette->largeur / 2) : (x > raquette->x + raquette->largeur / 2)) // Prévoit les positions de la balle
		{
			x += balle->vx;
			if (y < MIN_Y_PLATEAU || MAX_Y_PLATEAU < y)
				vy = -vy;
			y += vy;
		}
		if (raquette->y >= MIN_Y_PLATEAU + raquette->longueur / 2 && raquette->y <= MAX_Y_PLATEAU - raquette->longueur / 2) // Déplace la raquette jusqu'à la position de la balle
		{
			if (y > raquette->y)
				raquette->y++;
			if (y < raquette->y)
				raquette->y--;
		}
	}
	else // Si la balle a l'opposée de la raquette
	{
		// Repositionne la raquette au milieu
		if ((MIN_Y_PLATEAU + MAX_Y_PLATEAU) / 2 > raquette->y)
			raquette->y++;
		if ((MIN_Y_PLATEAU + MAX_Y_PLATEAU) / 2 < raquette->y)
			raquette->y--;
	}
}