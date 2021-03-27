#include "gestion.h"

void TempoAccueil(Data *const data)
{
	selectAcceuil(data->page.select);
	for (int i = 0; i < MAX_BALLE; i++)
	{
		rebond(data->balle + i, 0, 0, MAX_X, MAX_Y);
		mouvementBalle(data->balle + i);
	}
}

void TempoMenu(Data *const data)
{
	selectMenu(data->page.select);
	for (int i = 0; i < MAX_BALLE; i++)
	{
		rebond(data->balle + i, 0, 0, MAX_X, MAX_Y);
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
	enregistreUsersFichier(data->users);
}
void TempoJeu(Data *const data)
{
	if (!data->page.pause)
	{
		mouvementBalle(&data->balleJeu);
		for (int i = 0; i < NB_JOUEUR; i++)
			hitbox(&data->balleJeu, &data->joueurs[i].raquette);
		rebond(&data->balleJeu, -MAX_X, MIN_Y_PLATEAU, 2 * MAX_X, MAX_Y_PLATEAU);
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
		rebond(&data->balleJeu, -MAX_X, MIN_Y_PLATEAU, 2 * MAX_X, MAX_Y_PLATEAU);
		but(&data->balleJeu, data->joueurs);
		IA(&data->joueurs[1].raquette, &data->balleJeu);
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
		rebond(&data->balleJeu, -MAX_X, MIN_Y_PLATEAU, MAX_X_PLATEAU, MAX_Y_PLATEAU);
		but(&data->balleJeu, data->joueurs);
	}
	else
		selectPause(data->page.select);
}
