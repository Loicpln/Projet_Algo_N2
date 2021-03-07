#include "gestion.h"

void TempoAccueil(Data * const data)
{
	for (int i = 0; i < MAX_BALLE; i++)
	{
		rebond(data->balle + i, 0, 0, largeurFenetre(), hauteurFenetre());
		mouvementBalle(data->balle + i);
	}
	if (abscisseSouris() > 5 * largeurFenetre() / 16 && abscisseSouris() < 11 * largeurFenetre() / 16 && ordonneeSouris() > 16 * hauteurFenetre() / 24 && ordonneeSouris() < 19 * hauteurFenetre() / 24)
	{
		initSelect(data->page.select);
		data->page.select[0] = 5;
	}
	else if (abscisseSouris() > 11 * largeurFenetre() / 32 && abscisseSouris() < 21 * largeurFenetre() / 32 && ordonneeSouris() > 11 * hauteurFenetre() / 24 && ordonneeSouris() < 14 * hauteurFenetre() / 24)
	{
		initSelect(data->page.select);
		data->page.select[1] = 5;
	}
	else if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
	{
		initSelect(data->page.select);
		data->page.select[2] = 5;
	}
	else
		initSelect(data->page.select);
}

void TempoMenu(Data * const data)
{
	for (int i = 0; i < MAX_BALLE; i++)
	{
		rebond(data->balle + i, 0, 0, largeurFenetre(), hauteurFenetre());
		mouvementBalle(data->balle + i);
	}
	if (abscisseSouris() > 9 * largeurFenetre() / 32 && abscisseSouris() < 24 * largeurFenetre() / 32 && ordonneeSouris() > 16 * hauteurFenetre() / 24 && ordonneeSouris() < 19 * hauteurFenetre() / 24)
	{
		initSelect(data->page.select);
		data->page.select[0] = 5;
	}
	else if (abscisseSouris() > 9 * largeurFenetre() / 32 && abscisseSouris() < 24 * largeurFenetre() / 32 && ordonneeSouris() > hauteurFenetre() / 2 && ordonneeSouris() < 15 * hauteurFenetre() / 24)
	{
		initSelect(data->page.select);
		data->page.select[1] = 5;
	}
	else if (abscisseSouris() > 9 * largeurFenetre() / 32 && abscisseSouris() < 24 * largeurFenetre() / 32 && ordonneeSouris() > hauteurFenetre() / 3 && ordonneeSouris() < 11 * hauteurFenetre() / 24)
	{
		initSelect(data->page.select);
		data->page.select[2] = 5;
	}
	else if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
	{
		initSelect(data->page.select);
		data->page.select[3] = 5;
	}
	else
		initSelect(data->page.select);
}

void TempoRegles(Data * const data)
{
	if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
	{
		initSelect(data->page.select);
		data->page.select[0] = 5;
	}
	else
		initSelect(data->page.select);
}

void TempoSelection(Data * const data)
{
	if (abscisseSouris() > largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 && ordonneeSouris() > 99 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 99 * hauteurFenetre() / 120)
	{
		initSelect(data->page.select);
		data->page.select[0] = 5;
	}
	else if (abscisseSouris() > largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 && ordonneeSouris() > 59 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 59 * hauteurFenetre() / 120)
	{
		initSelect(data->page.select);
		data->page.select[1] = 5;
	}
	else if (abscisseSouris() > largeurFenetre() / 30 + 6 * largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 + 6 * largeurFenetre() / 30 && ordonneeSouris() > 99 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 99 * hauteurFenetre() / 120)
	{
		initSelect(data->page.select);
		data->page.select[2] = 5;
	}
	else if (abscisseSouris() > largeurFenetre() / 30 + 6 * largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 + 6 * largeurFenetre() / 30 && ordonneeSouris() > 59 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 59 * hauteurFenetre() / 120)
	{
		initSelect(data->page.select);
		data->page.select[3] = 5;
	}
	else if (abscisseSouris() > largeurFenetre() / 30 + 12 * largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 + 12 * largeurFenetre() / 30 && ordonneeSouris() > 99 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 99 * hauteurFenetre() / 120)
	{
		initSelect(data->page.select);
		data->page.select[4] = 5;
	}
	else if (abscisseSouris() > largeurFenetre() / 30 + 12 * largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 + 12 * largeurFenetre() / 30 && ordonneeSouris() > 59 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 59 * hauteurFenetre() / 120)
	{
		initSelect(data->page.select);
		data->page.select[5] = 5;
	}
	else if (abscisseSouris() > largeurFenetre() / 30 + 18 * largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 + 18 * largeurFenetre() / 30 && ordonneeSouris() > 99 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 99 * hauteurFenetre() / 120)
	{
		initSelect(data->page.select);
		data->page.select[6] = 5;
	}
	else if (abscisseSouris() > largeurFenetre() / 30 + 18 * largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 + 18 * largeurFenetre() / 30 && ordonneeSouris() > 59 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 59 * hauteurFenetre() / 120)
	{
		initSelect(data->page.select);
		data->page.select[7] = 5;
	}
	else if (abscisseSouris() > largeurFenetre() / 30 + 24 * largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 + 24 * largeurFenetre() / 30 && ordonneeSouris() > 99 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 99 * hauteurFenetre() / 120)
	{
		initSelect(data->page.select);
		data->page.select[8] = 5;
	}
	else if (abscisseSouris() > largeurFenetre() / 30 + 24 * largeurFenetre() / 30 && abscisseSouris() < 5 * largeurFenetre() / 30 + 24 * largeurFenetre() / 30 && ordonneeSouris() > 59 * hauteurFenetre() / 120 - 8 * hauteurFenetre() / 30 && ordonneeSouris() < 59 * hauteurFenetre() / 120)
	{
		initSelect(data->page.select);
		data->page.select[9] = 5;
	}
	else if (abscisseSouris() > 5 * largeurFenetre() / 16 && abscisseSouris() < 11 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
	{
		initSelect(data->page.select);
		data->page.select[10] = 5;
	}
	else if (abscisseSouris() > 3 * largeurFenetre() / 4 && abscisseSouris() < 15 * largeurFenetre() / 16 && ordonneeSouris() > hauteurFenetre() / 12 && ordonneeSouris() < hauteurFenetre() / 6)
	{
		initSelect(data->page.select);
		data->page.select[11] = 5;
	}
	else
		initSelect(data->page.select);
}
void TempoJeu(Data * const data)
{
	if (!data->page.pause)
	{
		mouvementBalle(&data->balleJeu);
		for (int i = 0; i < NB_RAQUETTE; i++)
			hitbox(&data->balleJeu, data->raquette + i);
		rebond(&data->balleJeu, 0, MIN_Y_PLATEAU, largeurFenetre(), MAX_Y_PLATEAU);
		but(&data->balleJeu, data->score);
	}
	else
		selectPause(data->page.select);
}
void TempoJeuIA(Data * const data)
{
	if (!data->page.pause)
	{
		mouvementBalle(&data->balleJeu);
		for (int i = 0; i < NB_RAQUETTE; i++)
			hitbox(&data->balleJeu, data->raquette + i);
		rebond(&data->balleJeu, 0, MIN_Y_PLATEAU, largeurFenetre(), MAX_Y_PLATEAU);
		but(&data->balleJeu, data->score);
		IA(&data->balleJeu, data->raquette + 1);
	}
	else
		selectPause(data->page.select);
}
void TempoEntrainement(Data * const data)
{
	if (!data->page.pause)
	{
		mouvementBalle(&data->balleJeu);
		hitbox(&data->balleJeu, data->raquette);
		rebond(&data->balleJeu, 0, MIN_Y_PLATEAU, MAX_X_PLATEAU, MAX_Y_PLATEAU);
		but(&data->balleJeu, data->score);
	}
	else
		selectPause(data->page.select);
}
