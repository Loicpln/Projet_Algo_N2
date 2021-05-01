#include "gestion.h"

void ClavierSelect(Data *const data)
{
	if (data->page.pause==2)
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
	{
		if(data->joueurs[0].user->id != id_IA)
			touches(&data->joueurs[0].raquette);
		if(data->joueurs[1].user->id != id_IA)
			touches(&data->joueurs[1].raquette);
	}
}