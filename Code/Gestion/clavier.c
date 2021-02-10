#include "gestion.h"

void ClavierAccueil(Data *data)
{
}

void ClavierMenu(Data *data)
{
}
void ClavierRegles(Data *data)
{
}
void ClavierJeu(Data *data)
{
	touchePause(data->page);
	if (!data->page->pause)
	{
		for (int i = 0; i < NB_RAQUETTE; i++)
		{
			touches(data->raquette + i);
		}
	}
}

void ClavierJeuIA(Data *data)
{
	touchePause(data->page);
	if (!data->page->pause)
	{
		touches(data->raquette);
	}
}

void ClavierEntrainement(Data *data)
{
	touchePause(data->page);
	if (!data->page->pause)
	{
		touches(data->raquette);
	}
}