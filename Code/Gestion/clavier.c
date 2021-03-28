#include "gestion.h"

void ClavierSelect(Data *const data)
{
	if (data->page.pause)
	{
		if (compteUsers(data->users) < NB_USERS && caractereClavier() == 13 && strcmp(data->newPseudo, "") != 0)
		{
			data->page.pause = false;
			data->users = ajouteUsers(data->users, creeUser(0, data->newPseudo, 0, 0, 0));
			strcpy(data->newPseudo, "");
		}
		ecrire(data->newPseudo);
	}
}

void ClavierJeu1J(Data *const data)
{
	touchePause(&data->page);
	if (!data->page.pause)
		touches(&data->joueurs[0].raquette);
}

void ClavierJeu2J(Data *const data)
{
	touchePause(&data->page);
	if (!data->page.pause)
		for (int i = 0; i < NB_JOUEUR; i++)
			touches(&data->joueurs[i].raquette);
}