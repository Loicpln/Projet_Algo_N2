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
	for (int i = 0; i < NB_RAQUETTE; i++)
	{
		touches(data->raquette + i);
	}
}

void ClavierJeuIA(Data *data)
{
	touches(data->raquette);
}

void ClavierEntrainement(Data *data)
{
	touches(data->raquette);
}