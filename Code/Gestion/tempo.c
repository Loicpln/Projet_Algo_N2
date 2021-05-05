#include "gestion.h"

//Ensemble des fonctions de temporisation

void TempoAccueil(Data *const data)
{
	resetSelect(data->page.select);
	selectBouton(&data->page.select[0], 30 * Ux, 70 * Ux, 65 * Uy, 80 * Uy); // Select du bouton Jouer
	selectBouton(&data->page.select[1], 35 * Ux, 65 * Ux, 45 * Uy, 60 * Uy); // Select du bouton Reglement
	selectBouton(&data->page.select[2], 75 * Ux, 95 * Ux, 5 * Uy, 15 * Uy);	 // Select du bouton Retour
	for (int i = 0; i < NB_BALLE; i++)
	{
		rebond(data->balle + i, 0, 0, MAX_X, MAX_Y);
		mouvementBalle(data->balle + i);
	}
}

void TempoMenu(Data *const data)
{
	resetSelect(data->page.select);
	selectBouton(&data->page.select[0], 25 * Ux, 75 * Ux, 67 * Uy, 80 * Uy); // Select du bouton Contre la montre
	selectBouton(&data->page.select[1], 25 * Ux, 75 * Ux, 50 * Uy, 63 * Uy); // Select du bouton Battle royal
	selectBouton(&data->page.select[2], 25 * Ux, 75 * Ux, 33 * Uy, 46 * Uy); // Select du bouton Entrainement
	selectBouton(&data->page.select[3], 75 * Ux, 95 * Ux, 5 * Uy, 15 * Uy);	 // Select du bouton Retour
	for (int i = 0; i < NB_BALLE; i++)
	{
		rebond(data->balle + i, 0, 0, MAX_X, MAX_Y);
		mouvementBalle(data->balle + i);
	}
	for (int i = 0; i < NB_SELECT; i++)
		couleurSelect(data->page.select + i, rand() % 255, rand() % 255, rand() % 255);
}

void TempoRegles(Data *const data)
{
	resetSelect(data->page.select);
	selectBouton(&data->page.select[0], 75 * Ux, 95 * Ux, 5 * Uy, 15 * Uy); // Select du bouton Retour
}

void TempoSelection(Data *const data)
{
	int teinte = (data->page.pause) ? 150 : 255;
	resetSelect(data->page.select);
	for (int i = 0; i < NB_SELECT; i++) // Met toutes les bordures Gris si il y a une pause, Blanc sinon
		couleurSelect(data->page.select + i, teinte, teinte, teinte);
	if (!data->page.pause)
	{
		strcpy(data->newPseudo, "");
		selectUsers(data->page.select);
		enregistreUsersFichier(data->users);
	}
	else if (data->page.pause == 2) // Ajouter un User
	{
		couleurSelect(&data->page.select[46], 255, 255, 255); // Select de la zone de text en Blanc
		couleurSelect(&data->page.select[47], 0, 255, 0);	  // Select du bouton Ajout User en Vert
	}
	else // Mutateur
	{
		couleurSelect(&data->page.select[47], 255, 255, 255); // Select du bouton Ajout User en Blanc
		rebond(&data->balleJeu, 5 * Ux, 5 * Uy, 95 * Ux, MAX_Y);
		mouvementBalle(&data->balleJeu);
		selectMutateur(data->page.select, data->option);
	}
	couleurSelect(&data->page.select[id_Rouage], 255, 255, 255);
	selectRouage(&data->page.select[id_Rouage], 9 * Ux, 90 * Uy, r_Rouage);	  // Select du rouage
	selectBouton(&data->page.select[47], 87 * Ux, 95 * Ux, 85 * Uy, 95 * Uy); //Select du bouton Ajout User
	for (int i = 0; i < NB_JOUEUR; i++)
		if (data->joueurs[i].user != NULL)
		{
			// Select correspondant aux joueurs (Bleu si 1er joueur| Rouge si 2eme joueur )
			couleurSelect(data->page.select + data->joueurs[i].user->id, (i) ? teinte : 0, 0, (i) ? 0 : teinte);
			couleurSelect(data->page.select + data->joueurs[i].user->id + NB_USERS, (i) ? teinte : 0, 0, (i) ? 0 : teinte);
		}
}

void TempoJeu(Data *const data)
{
	resetSelect(data->page.select);
	if (!data->page.pause)
		jeu(data);
	else if (data->page.pause == 2) // Mutateur
	{
		rebond(&data->balleJeu, 5 * Ux, 5 * Uy, 95 * Ux, MAX_Y);
		mouvementBalle(&data->balleJeu);
		selectMutateur(data->page.select, data->option);
	}
	else // Pause
		selectPause(data->page.select);
	// Positionne le Select à differents endroits selon le mode ou la pause
	if (data->option.mode == ContreLaMontre || data->option.mode == Entrainement || data->page.pause == 2)
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
	else if (data->page.pause == 2) // Mutateur
	{
		rebond(&data->balleJeu, 5 * Ux, 5 * Uy, 95 * Ux, MAX_Y);
		mouvementBalle(&data->balleJeu);
		selectMutateur(data->page.select, data->option);
	}
	else // Pause
		selectPause(data->page.select);
	selectRouage(&data->page.select[id_Rouage], 88 * Ux, 90 * Uy, r_Rouage); // Select du rouage
}

void TempoResultats(Data *const data)
{
	resetSelect(data->page.select);
	selectBouton(&data->page.select[0], 30 * Ux, 70 * Ux, 20 * Uy, 30 * Uy); // Select du bouton Rejouer
	selectBouton(&data->page.select[1], 30 * Ux, 70 * Ux, 5 * Uy, 15 * Uy);	 // Select du bouton Retour au menu
	enregistreUsersFichier(data->users);
}