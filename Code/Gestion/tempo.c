#include "gestion.h"

void TempoAccueil(Data *const data)
{
    resetSelect(data->page.select);
	selectAcceuil(data->page.select);
	for (int i = 0; i < NB_BALLE; i++)
	{
		rebond(data->balle + i, 0, 0, MAX_X, MAX_Y);
		mouvementBalle(data->balle + i);
	}
}

void TempoMenu(Data *const data)
{
    resetSelect(data->page.select);
	selectMenu(data->page.select);
	for (int i = 0; i < NB_BALLE; i++)
	{
		rebond(data->balle + i, 0, 0, MAX_X, MAX_Y);
		mouvementBalle(data->balle + i);
	}
	for (int i = 0; i < NB_SELECT; i++)
		couleurSelect(data->page.select + i, rand() % 256, rand() % 256, rand() % 256);
}

void TempoRegles(Data *const data)
{
    resetSelect(data->page.select);
	selectRegles(data->page.select);
}

void TempoSelection(Data *const data)
{
	int teinte = (data->page.pause) ? 150 : 255;
    resetSelect(data->page.select);
	for (int i = 0; i < NB_SELECT; i++)
		couleurSelect(data->page.select + i, teinte, teinte, teinte);
	if (!data->page.pause)
	{
		strcpy(data->newPseudo, "");
		selectSelection(data->page.select);
		enregistreUsersFichier(data->users);
	}
	else
	{
		couleurSelect(&data->page.select[46], 255, 255, 255);
		couleurSelect(&data->page.select[47], 0, 255, 0);
	}
	selectAddUsers(data->page.select);
	if (data->joueurs[0].user != NULL)
	{
		couleurSelect(data->page.select + data->joueurs[0].user->id, 0, 0, teinte);
		couleurSelect(data->page.select + data->joueurs[0].user->id + NB_USERS, 0, 0, teinte);
	}
	if (data->joueurs[1].user != NULL)
	{
		couleurSelect(data->page.select + data->joueurs[1].user->id, teinte, 0, 0);
		couleurSelect(data->page.select + data->joueurs[1].user->id + NB_USERS, teinte, 0, 0);
	}
}

void TempoJeu(Data *const data)
{
    resetSelect(data->page.select);
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
	selectRouage(data->page.select);
}

void TempoJeuIA(Data *const data)
{
    resetSelect(data->page.select);
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
	selectRouage(data->page.select);
}

void TempoEntrainement(Data *const data)
{
    resetSelect(data->page.select);
	if (!data->page.pause)
	{
		mouvementBalle(&data->balleJeu);
		hitbox(&data->balleJeu, &data->joueurs[0].raquette);
		rebond(&data->balleJeu, -MAX_X, MIN_Y_PLATEAU, MAX_X_PLATEAU, MAX_Y_PLATEAU);
		but(&data->balleJeu, data->joueurs);
	}
	else
		selectPause(data->page.select);
	selectRouage(data->page.select);
}