#include "controleur.h"

int main(int argc, char **argv)
{
	initialiseGfx(argc, argv);
	prepareFenetreGraphique("Pong", LargeurFenetre, HauteurFenetre);
	lanceBoucleEvenements();

	return 0;
}

void gestionEvenement(EvenementGfx evenement)
{
	static Data data;

	switch (evenement)
	{
	case Initialisation:
		data = init();
		for (int i = 0; i < NB_BALLE; i++)
			data.balle[i] = initBallesAccueil();
		activeGestionDeplacementPassifSouris();
		demandeTemporisation(20);
		break;

	case Temporisation:
		gestion(&data, fTempo());
		rafraichisFenetre();
		break;

	case Affichage:
		effaceFenetre(0, 0, 0);
		gestion(&data, fAffiche());
		//GRILLE;
		break;

	case Clavier:
		gestion(&data, fClavier());
		break;

	case ClavierSpecial:
		break;

	case BoutonSouris:
		gestion(&data, fClic());
		break;

	case Souris:
		break;

	case Inactivite:
		break;

	case Redimensionnement:
		Redim(&data);
		break;
	}
}