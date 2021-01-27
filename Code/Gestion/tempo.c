#include "gestion.h"

void TempoAccueil(Data *data)
{
	for (int i = 0; i < MAX_BALLE; i++)
	{
		mouvementBalle(data->balle + i);
		rebond(data->balle + i, 0, 0, largeurFenetre(), hauteurFenetre());
	}
}

void TempoMenu(Data *data)
{
	for (int i = 0; i < MAX_BALLE; i++)
	{
		mouvementBalle(data->balle + i);
		rebond(data->balle + i, 0, 0, largeurFenetre(), hauteurFenetre());
	}
}

void TempoRegles(Data *data)
{
}
void TempoJeu(Data *data)
{
	mouvementBalle(data->balleJeu);
	for (int i = 0; i < NB_RAQUETTE; i++)
		hitbox(data->balleJeu, data->raquette + i);
	rebond(data->balleJeu, MIN_X_PLATEAU, MIN_Y_PLATEAU, MAX_X_PLATEAU, MAX_Y_PLATEAU);
}
