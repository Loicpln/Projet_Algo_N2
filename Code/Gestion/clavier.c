#include "gestion.h"

void ClavierAccueil(Data *data)
{
}

void ClavierMenu(Data *data)
{
}
void ClavierJeu(Data *data)
{
	switch (caractereClavier())
	{
	case 'Z':
	case 'z':

		if (data->raquette[0].centre + data->raquette[0].longueur / 2 <= MAX_Y_PLATEAU)
		{
			data->raquette[0].centre += data->raquette[0].vc;
		}
		else
		{
		}
		break;

	case 'S':
	case 's':
		if (data->raquette[0].centre - data->raquette[0].longueur / 2 >= MIN_Y_PLATEAU)
		{
			data->raquette[0].centre -= data->raquette[0].vc;
		}

		else
		{
		}
		break;

	case 'P':
	case 'p':

		if (data->raquette[1].centre + data->raquette[1].longueur / 2 <= MAX_Y_PLATEAU)
		{
			data->raquette[1].centre += data->raquette[1].vc;
		}

		else
		{
		}
		break;

	case 'M':
	case 'm':
		if (data->raquette[1].centre - data->raquette[1].longueur / 2 >= MIN_Y_PLATEAU)
		{
			data->raquette[1].centre -= data->raquette[1].vc;
		}
		else
		{
		}
		break;
	 }
}
void ClavierRegles(Data *data)
{
}