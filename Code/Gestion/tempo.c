#include "gestion.h"

void TempoAccueil(Data *const data)
{
	selectAcceuil(data->page.select);
	for (int i = 0; i < MAX_BALLE; i++)
	{
		rebond(data->balle + i, 0, 0, largeurFenetre(), hauteurFenetre());
		mouvementBalle(data->balle + i);
	}
}

void TempoMenu(Data *const data)
{
	selectMenu(data->page.select);
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
	selectRegles(data->page.select);
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
		rebond(&data->balleJeu, -largeurFenetre(), MIN_Y_PLATEAU, 2 * largeurFenetre(), MAX_Y_PLATEAU);
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
		rebond(&data->balleJeu, -largeurFenetre(), MIN_Y_PLATEAU, 2 * largeurFenetre(), MAX_Y_PLATEAU);
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
		rebond(&data->balleJeu, -largeurFenetre(), MIN_Y_PLATEAU, MAX_X_PLATEAU, MAX_Y_PLATEAU);
		but(&data->balleJeu, data->joueurs);
	}
	else
		selectPause(data->page.select);
}
