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
	static int xBalle;
	static int yBalle;
	static int vxBalle = 5;
	static int vyBalle = -5;

	switch (evenement)
	{
	case Initialisation:
		xBalle = largeurFenetre()*valeurAleatoire();
		yBalle = hauteurFenetre()*valeurAleatoire();
		demandeTemporisation(20);
		break;

	case Temporisation:
		xBalle += vxBalle;
		yBalle += vyBalle;

		if (xBalle < 0 || xBalle >= largeurFenetre())
			vxBalle = -vxBalle;
		if (yBalle < 0 || yBalle >= hauteurFenetre())
			vyBalle = -vyBalle;
		rafraichisFenetre();
		break;

	case Affichage:
		effaceFenetre(0,0, 0);
		gestion(page,fAffiche());
		break;

	case Clavier:
		gestion(page,fClavier());
		break;

	case ClavierSpecial:
		break;

	case BoutonSouris:
		gestion(page,fClick());
		break;

	case Souris:
		break;

	case Inactivite:
		break;

	case Redimensionnement:
		if (xBalle >= largeurFenetre())
			xBalle = largeurFenetre()-1;
		if (yBalle >= hauteurFenetre())
			yBalle = hauteurFenetre()-1;
		// printf("Largeur : %d\t", largeurFenetre());
		// printf("Hauteur : %d\n", hauteurFenetre());
		break;
	}
}
