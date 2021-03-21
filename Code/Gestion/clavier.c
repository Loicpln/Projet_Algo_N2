#include "gestion.h"

void ClavierJeu(Data *const data)
{
	touchePause(&data->page);
	if (!data->page.pause)
		for (int i = 0; i < NB_JOUEUR; i++)
			touches(&data->joueurs[i].raquette);
}

void ClavierJeuIA(Data *const data)
{
	touchePause(&data->page);
	if (!data->page.pause)
		touches(&data->joueurs[0].raquette);
}

void ClavierEntrainement(Data *const data)
{
	touchePause(&data->page);
	if (!data->page.pause)
		touches(&data->joueurs[0].raquette);
}