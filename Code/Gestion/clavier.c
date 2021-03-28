#include "gestion.h"

void ClavierSelect(Data *const data)
{
	if (data->page.pause)
	{
		if (caractereClavier() == 13)
		{
			if (compteUsers(data->users) < NB_USERS && strcmp(data->newPseudo, "") != 0)
				data->users = ajouteUsers(data->users, creeUser(0, data->newPseudo, 0, 0, 0));
			data->page.pause = false;
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