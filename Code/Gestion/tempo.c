#include "gestion.h"

void TempoAccueil(Data *data)
{
	for (int i = 0; i < MAX_BALLE; i++)
	{
		mouvementBalle(data->balle+i);
		rebond(data->balle+i);
	}
}

void TempoMenu(Data *data)
{
	for (int i = 0; i < MAX_BALLE; i++)
	{
		mouvementBalle(data->balle+i);
		rebond(data->balle+i);
	}
}

void TempoRegles(Data *data)
{
	
}
void TempoJeu(Data *data)
{

}

