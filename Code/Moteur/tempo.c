#include "../controleur.h"

void TempoAccueil(Data *data) //Affichage page d'accueil
{
    for (int i = 0; i < MAX_BALLE; i++)
		{
			data->balle[i].x += data->balle[i].vx;
			data->balle[i].y += data->balle[i].vy;

			if (data->balle[i].x < 0 || data->balle[i].x >= largeurFenetre())
				data->balle[i].vx = -data->balle[i].vx;
			if (data->balle[i].y < 0 || data->balle[i].y >= hauteurFenetre())
				data->balle[i].vy = -data->balle[i].vy;
		}
}

void TempoJeu(Data *data)
{
    for (int i = 0; i < MAX_BALLE; i++)
		{
			data->balle[i].x += data->balle[i].vx;
			data->balle[i].y += data->balle[i].vy;

			if (data->balle[i].x < 0 || data->balle[i].x >= largeurFenetre())
				data->balle[i].vx = -data->balle[i].vx;
			if (data->balle[i].y < 0 || data->balle[i].y >= hauteurFenetre())
				data->balle[i].vy = -data->balle[i].vy;
		}
}

void TempoRegles(Data *data)
{
    
}
