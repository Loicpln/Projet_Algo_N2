#include "gestion.h"

void TempoAccueil(Data *data)
{
	for (int i = 0; i < MAX_BALLE; i++)
	{
		rebond(data->balle + i, 0, 0, largeurFenetre(), hauteurFenetre());
		mouvementBalle(data->balle + i);
	}
	if (abscisseSouris() > 5 * largeurFenetre() / 16 && abscisseSouris() < 11 * largeurFenetre() / 16 && ordonneeSouris() > 16 * hauteurFenetre() / 24 && ordonneeSouris() < 19 * hauteurFenetre() / 24)
	{
		initSelect(data->page->select);
		data->page->select[0] = 5;
	}
	else if (abscisseSouris() > 11 * largeurFenetre() / 32 && abscisseSouris() < 21 * largeurFenetre() / 32 && ordonneeSouris() > 11 * hauteurFenetre() / 24 && ordonneeSouris() < 14 * hauteurFenetre() / 24)
	{
		initSelect(data->page->select);
		data->page->select[1] = 5;
	}
	else if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
	{
		initSelect(data->page->select);
		data->page->select[2] = 5;
	}
	else
		initSelect(data->page->select);
}

void TempoMenu(Data *data)
{
	for (int i = 0; i < MAX_BALLE; i++)
	{
		rebond(data->balle + i, 0, 0, largeurFenetre(), hauteurFenetre());
		mouvementBalle(data->balle + i);
	}
	if (abscisseSouris() > 9 * largeurFenetre() / 32 && abscisseSouris() < 24 * largeurFenetre() / 32 && ordonneeSouris() > 16 * hauteurFenetre() / 24 && ordonneeSouris() < 19 * hauteurFenetre() / 24)
	{
		initSelect(data->page->select);
		data->page->select[0] = 5;
	}
	else if (abscisseSouris() > 9 * largeurFenetre() / 32 && abscisseSouris() < 24 * largeurFenetre() / 32 && ordonneeSouris() > hauteurFenetre() / 2 && ordonneeSouris() < 15 * hauteurFenetre() / 24)
	{
		initSelect(data->page->select);
		data->page->select[1] = 5;
	}
	else if (abscisseSouris() > 9 * largeurFenetre() / 32 && abscisseSouris() < 24 * largeurFenetre() / 32 && ordonneeSouris() > hauteurFenetre() / 3 && ordonneeSouris() < 11 * hauteurFenetre() / 24)
	{
		initSelect(data->page->select);
		data->page->select[2] = 5;
	}
	else if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
	{
		initSelect(data->page->select);
		data->page->select[3] = 5;
	}
	else
		initSelect(data->page->select);
}

void TempoRegles(Data *data)
{
	if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
	{
		initSelect(data->page->select);
		data->page->select[0] = 5;
	}
	else
		initSelect(data->page->select);
}
void TempoJeu(Data *data)
{
	if (!data->page->pause)
	{
		mouvementBalle(data->balleJeu);
		for (int i = 0; i < NB_RAQUETTE; i++)
			hitbox(data->balleJeu, data->raquette + i);
		rebond(data->balleJeu, 0, MIN_Y_PLATEAU, largeurFenetre(), MAX_Y_PLATEAU);
		but(data->balleJeu, data->score);
	}
	else
		selectPause(data->page->select);
}
void TempoJeuIA(Data *data)
{
	if (!data->page->pause)
	{
		mouvementBalle(data->balleJeu);
		for (int i = 0; i < NB_RAQUETTE; i++)
			hitbox(data->balleJeu, data->raquette + i);
		rebond(data->balleJeu, 0, MIN_Y_PLATEAU, largeurFenetre(), MAX_Y_PLATEAU);
		but(data->balleJeu, data->score);
		IA(data->balleJeu, data->raquette + 1);
	}
	else
		selectPause(data->page->select);
}
void TempoEntrainement(Data *data)
{
	if (!data->page->pause)
	{
		mouvementBalle(data->balleJeu);
		hitbox(data->balleJeu, data->raquette);
		rebond(data->balleJeu, 0, MIN_Y_PLATEAU, MAX_X_PLATEAU, MAX_Y_PLATEAU);
		but(data->balleJeu, data->score);
	}
	else
		selectPause(data->page->select);
}
