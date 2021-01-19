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

	switch (evenement)
	{
	case Initialisation:
		demandeTemporisation(20);
		break;

	case Temporisation:
		rafraichisFenetre();
		break;

	case Affichage:
		effaceFenetre(0, 0, 0);
		gestion(page,newAffiche());
		break;

	case Clavier:
		gestion(page,newClavier());
		break;

	case ClavierSpecial:
		break;

	case BoutonSouris:
		gestion(page,newClick());
		break;

	case Souris:
		break;

	case Inactivite:
		break;

	case Redimensionnement:
		// printf("Largeur : %d\t", largeurFenetre());
		// printf("Hauteur : %d\n", hauteurFenetre());
		break;
	}
}
