#include "controleur.h"

//page 0 = Ecran d'accueil
//page 1 = Ecran Jouer
//page 2 = Reglement

int main(int argc, char **argv)
{
	initialiseGfx(argc, argv);
	prepareFenetreGraphique("Pong", LargeurFenetre, HauteurFenetre);
	lanceBoucleEvenements();

	return 0;
}

void gestionEvenement(EvenementGfx evenement)
{
	static int p = 0;
	static Data d;
	Data *data = &d;

	switch (evenement)
	{
	case Initialisation:
		data->page = &p;
		for (int i = 0; i < MAX_BALLE; i++)
		{
			data->balle[i].x = largeurFenetre() * valeurAleatoire();
			data->balle[i].y = hauteurFenetre() * valeurAleatoire();
			data->balle[i].r = 10;
			data->balle[i].vx = -5;
			data->balle[i].vy = -5;
			if (rand() % 2)
				data->balle[i].vx = fabsf(data->balle[i].vx);

			if (rand() % 2)
				data->balle[i].vy = fabsf(data->balle[i].vy);
		}
		demandeTemporisation(20);
		break;

	case Temporisation:
		gestion(data, fTempo());
		rafraichisFenetre();
		break;

	case Affichage:
		effaceFenetre(0, 0, 0);
		gestion(data, fAffiche());
		break;

	case Clavier:
		gestion(data, fClavier());
		break;

	case ClavierSpecial:
		break;

	case BoutonSouris:
		gestion(data, fClick());
		break;

	case Souris:
		break;

	case Inactivite:
		break;

	case Redimensionnement:
		for (int i = 0; i < MAX_BALLE; i++)
		{
			if (data->balle[i].x >= largeurFenetre())
				data->balle[i].x = largeurFenetre() - 1;
			if (data->balle[i].y >= hauteurFenetre())
				data->balle[i].y = hauteurFenetre() - 1;
		}
		break;
	}
}
