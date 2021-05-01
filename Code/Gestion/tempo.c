#include "gestion.h"

void TempoAccueil(Data *const data)
{
	resetSelect(data->page.select);
	selectBouton(&data->page.select[0], 30 * Ux, 70 * Ux, 65 * Uy, 80 * Uy);
	selectBouton(&data->page.select[1], 35 * Ux, 65 * Ux, 45 * Uy, 60 * Uy);
	selectBouton(&data->page.select[2], 75 * Ux, 95 * Ux, 5 * Uy, 15 * Uy);
	for (int i = 0; i < NB_BALLE; i++)
	{
		rebond(data->balle + i, 0, 0, MAX_X, MAX_Y);
		mouvementBalle(data->balle + i);
	}
}

void TempoMenu(Data *const data)
{
	resetSelect(data->page.select);
	selectBouton(&data->page.select[0], 25 * Ux, 75 * Ux, 67 * Uy, 80 * Uy);
	selectBouton(&data->page.select[1], 25 * Ux, 75 * Ux, 50 * Uy, 63 * Uy);
	selectBouton(&data->page.select[2], 25 * Ux, 75 * Ux, 33 * Uy, 46 * Uy);
	selectBouton(&data->page.select[3], 75 * Ux, 95 * Ux, 5 * Uy, 15 * Uy);
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
	selectBouton(&data->page.select[0], 75 * Ux, 95 * Ux, 5 * Uy, 15 * Uy);
}

void TempoSelection(Data *const data)
{
	int teinte = (data->page.pause == 2 || data->page.pause) ? 150 : 255;
	resetSelect(data->page.select);
	for (int i = 0; i < NB_SELECT; i++)
		couleurSelect(data->page.select + i, teinte, teinte, teinte);
	if (!data->page.pause)
	{
		strcpy(data->newPseudo, "");
		selectUsers(data->page.select);
		enregistreUsersFichier(data->users);
	}
	else if (data->page.pause == 2)
	{
		couleurSelect(&data->page.select[46], 255, 255, 255);
		couleurSelect(&data->page.select[47], 0, 255, 0);
	}
	else
		couleurSelect(&data->page.select[47], 255, 255, 255);
	couleurSelect(&data->page.select[id_Rouage], 255, 255, 255);
	selectRouage(&data->page.select[id_Rouage], 9 * Ux, 90 * Uy, r_Rouage);
	selectBouton(&data->page.select[47], 87 * Ux, 95 * Ux, 85 * Uy, 95 * Uy);
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
		jeu(data);
	else
		selectPause(data->page.select);
	if (data->option.mode == ContreLaMontre || data->option.mode == Entrainement)
		selectRouage(&data->page.select[id_Rouage], 88 * Ux, 90 * Uy, r_Rouage);
	else
		selectRouage(&data->page.select[id_Rouage], MID_X, 90 * Uy, r_Rouage);
	

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
	selectRouage(&data->page.select[id_Rouage], 88 * Ux, 90 * Uy, r_Rouage);
}

void TempoResultats(Data *const data)
{
	int teinte = (data->page.pause) ? 150 : 255;
	resetSelect(data->page.select);
	for (int i = 0; i < NB_SELECT; i++)
		couleurSelect(data->page.select + i, teinte, teinte, teinte);
	if (!data->page.pause)
	{
		selectBouton(&data->page.select[0], 30 * Ux, 70 * Ux, 20 * Uy, 30 * Uy);
		selectBouton(&data->page.select[1], 30 * Ux, 70 * Ux, 5 * Uy, 15 * Uy);
	}
	couleurSelect(&data->page.select[id_Rouage], 255, 255, 255);
	selectRouage(&data->page.select[id_Rouage], 12 * Ux, 90 * Uy, r_Rouage);
}