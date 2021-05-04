#include "gestion.h"

//Ensemble des fonctions de clavier

void ClavierSelection(Data *const data)
{
	if (data->page.pause == 2)
	{
		if (caractereClavier() == 13) // Si on appuie sur la touche Entrer
		{
			if (compteUsers(data->users) < NB_USERS && strcmp(data->newPseudo, "") != 0)	   // Si il reste de la place et que le nouveau pseudo n'est pas vide
				data->users = ajouteUsers(data->users, creeUser(0, data->newPseudo, 0, 0, 0)); // On ajoute un utilisateur
			data->page.pause = false;
		}
		ecrire(data->newPseudo);
	}
}

void ClavierEntrainement(Data *const data)
{
	touchePause(&data->page);
	if (!data->page.pause)
		for (int i = 0; i < NB_JOUEUR; i++)
			touches(&data->joueurs[i].raquette);
}

void ClavierJeu(Data *const data)
{
	touchePause(&data->page);
	if (!data->page.pause)
		for (int i = 0; i < NB_JOUEUR; i++)
			if (data->joueurs[i].user->id != id_IA) // On peut faire bouger la raquette si le joueur n'est pas l'IA
				touches(&data->joueurs[i].raquette);
}