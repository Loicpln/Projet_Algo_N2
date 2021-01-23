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
	case 'Q': /* Pour sortir quelque peu proprement du programme */
	case 'q':
		termineBoucleEvenements();
		break;

	case 'Z':
	case 'z':

		if (data->raquette[0].centre + data->raquette[0].longueur / 2 >= 99 * hauteurFenetre() / 120)
		{
			data->raquette[0].haut = 0;
		}

		else if (data->raquette[0].haut = (1))
		{
			data->raquette[0].centre += data->raquette[0].vc;
		}

		else if (data->raquette[0].bas = (0))
		{
			data->raquette[0].bas = 1;
		}
		else
		{
		}
		break;

	case 'S':
	case 's':
		if (data->raquette[0].centre - data->raquette[0].longueur / 2 <= hauteurFenetre() / 60)
		{
			data->raquette[0].bas = 0;
		}

		else if (data->raquette[0].bas = (1))
		{
			data->raquette[0].centre -= data->raquette[0].vc;
		}

		else if (data->raquette[0].haut = (0))
		{
			data->raquette[0].haut = 1;
		}

		else
		{
		}
		break;

	case 'P':
	case 'p':

		if (data->raquette[1].centre + data->raquette[1].longueur / 2 >= 99 * hauteurFenetre() / 120)
		{
			data->raquette[1].haut = 0;
		}

		else if (data->raquette[1].haut = (1))
		{
			data->raquette[1].centre += data->raquette[1].vc;
		}

		else if (data->raquette[1].bas = (0))
		{
			data->raquette[1].bas = 1;
		}
		else
		{
		}
		break;

	case 'M':
	case 'm':
		if (data->raquette[1].centre - data->raquette[1].longueur / 2 <= hauteurFenetre() / 60)
		{
			data->raquette[1].bas = 0;
		}

		else if (data->raquette[1].bas = (1))
		{
			data->raquette[1].centre -= data->raquette[1].vc;
		}

		else if (data->raquette[1].haut = (0))
		{
			data->raquette[1].haut = 1;
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
