#include "gestion.h"

void TempoAccueil(Data *const data)
{
	resetSelect(data->page.select);
	if (abscisseSouris() > 5 * largeurFenetre() / 16 && abscisseSouris() < 11 * largeurFenetre() / 16 && ordonneeSouris() > 16 * hauteurFenetre() / 24 && ordonneeSouris() < 19 * hauteurFenetre() / 24)
		data->page.select[0].largeur = 5;
	else if (abscisseSouris() > 11 * largeurFenetre() / 32 && abscisseSouris() < 21 * largeurFenetre() / 32 && ordonneeSouris() > 11 * hauteurFenetre() / 24 && ordonneeSouris() < 14 * hauteurFenetre() / 24)
		data->page.select[1].largeur = 5;
	else if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
		data->page.select[2].largeur = 5;

	for (int i = 0; i < MAX_BALLE; i++)
	{
		rebond(data->balle + i, 0, 0, largeurFenetre(), hauteurFenetre());
		mouvementBalle(data->balle + i);
	}
}

void TempoMenu(Data *const data)
{
	resetSelect(data->page.select);
	if (abscisseSouris() > 9 * largeurFenetre() / 32 && abscisseSouris() < 24 * largeurFenetre() / 32 && ordonneeSouris() > 16 * hauteurFenetre() / 24 && ordonneeSouris() < 19 * hauteurFenetre() / 24)
		data->page.select[0].largeur = 5;
	else if (abscisseSouris() > 9 * largeurFenetre() / 32 && abscisseSouris() < 24 * largeurFenetre() / 32 && ordonneeSouris() > hauteurFenetre() / 2 && ordonneeSouris() < 15 * hauteurFenetre() / 24)
		data->page.select[1].largeur = 5;
	else if (abscisseSouris() > 9 * largeurFenetre() / 32 && abscisseSouris() < 24 * largeurFenetre() / 32 && ordonneeSouris() > hauteurFenetre() / 3 && ordonneeSouris() < 11 * hauteurFenetre() / 24)
		data->page.select[2].largeur = 5;
	else if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
		data->page.select[3].largeur = 5;

	for (int i = 0; i < MAX_BALLE; i++)
	{
		rebond(data->balle + i, 0, 0, largeurFenetre(), hauteurFenetre());
		mouvementBalle(data->balle + i);
	}
	for (int i = 0; i < NB_SELECT; i++)
		couleurSelect(data->page.select, i, rand() % 256, rand() % 256, rand() % 256);
}

void TempoRegles(Data *const data)
{
	resetSelect(data->page.select);
	if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
		data->page.select[1].largeur = 5;
}

void TempoSelection(Data *const data)
{
	selectSelection(data->page.select);
	if (data->joueurs[1].user != NULL)
		couleurSelect(data->page.select, data->joueurs[1].user->id, 255, 0, 0);
	if (data->joueurs[0].user != NULL)
		couleurSelect(data->page.select, data->joueurs[0].user->id, 0, 0, 255);
}
void TempoJeu(Data *const data)
{
	if (!data->page.pause)
	{
		mouvementBalle(&data->balleJeu);
		for (int i = 0; i < NB_JOUEUR; i++)
			hitbox(&data->balleJeu, &data->joueurs[i].raquette);
		rebond(&data->balleJeu, 0, MIN_Y_PLATEAU, largeurFenetre(), MAX_Y_PLATEAU);
		but(&data->balleJeu, data->joueurs);
	}
	else
		selectPause(data->page.select);
}
void TempoJeuIA(Data *const data)
{
	if (!data->page.pause)
	{
		mouvementBalle(&data->balleJeu);
		for (int i = 0; i < NB_JOUEUR; i++)
			hitbox(&data->balleJeu, &data->joueurs[i].raquette);
		rebond(&data->balleJeu, 0, MIN_Y_PLATEAU, largeurFenetre(), MAX_Y_PLATEAU);
		but(&data->balleJeu, data->joueurs);
		IA(&data->balleJeu, &data->joueurs[1].raquette);
	}
	else
		selectPause(data->page.select);
}
void TempoEntrainement(Data *const data)
{
	if (!data->page.pause)
	{
		mouvementBalle(&data->balleJeu);
		hitbox(&data->balleJeu, &data->joueurs[0].raquette);
		rebond(&data->balleJeu, 0, MIN_Y_PLATEAU, MAX_X_PLATEAU, MAX_Y_PLATEAU);
		but(&data->balleJeu, data->joueurs);
	}
	else
		selectPause(data->page.select);
}
