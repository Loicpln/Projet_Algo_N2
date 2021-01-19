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
	int *page = &p;

	static int xBalle[MAX];
	static int yBalle[MAX];

	static int vxBalle[MAX];
	static int vyBalle[MAX];

	switch (evenement)
	{
	case Initialisation:
		for (int i = 0; i < MAX; ++i)
		{
			xBalle[i] = largeurFenetre() * valeurAleatoire();
			yBalle[i] = hauteurFenetre() * valeurAleatoire();
			vxBalle[i] = 5;
			vyBalle[i] = 5;
		}
		demandeTemporisation(20);
		break;

	case Temporisation:
		for (int i = 0; i < MAX; ++i)
		{
			xBalle[i] += vxBalle[i];
			yBalle[i] += vyBalle[i];

			if (xBalle[i] < 0 || xBalle[i] >= largeurFenetre())
				vxBalle[i] = -vxBalle[i];
			if (yBalle[i] < 0 || yBalle[i] >= hauteurFenetre())
				vyBalle[i] = -vyBalle[i];
		}
		rafraichisFenetre();
		break;

	case Affichage:
		effaceFenetre(0, 0, 0);
		gestion(page, xBalle, yBalle, vxBalle, vyBalle, fAffiche());
		break;

	case Clavier:
		gestion(page, xBalle, yBalle, vxBalle, vyBalle, fClavier());
		break;

	case ClavierSpecial:
		break;

	case BoutonSouris:
		gestion(page, xBalle, yBalle, vxBalle, vyBalle, fClick());
		break;

	case Souris:
		break;

	case Inactivite:
		break;

	case Redimensionnement:
		for (int i = 0; i < MAX; ++i)
		{
			if (xBalle[i] >= largeurFenetre())
				xBalle[i] = largeurFenetre() - 1;
			if (yBalle[i] >= hauteurFenetre())
				yBalle[i] = hauteurFenetre() - 1;
		}
		// printf("Largeur : %d\t", largeurFenetre());
		// printf("Hauteur : %d\n", hauteurFenetre());
		break;
	}
}
