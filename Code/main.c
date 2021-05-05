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
	static Data data; // Variable Global

	switch (evenement)
	{
	case Initialisation:
		data = init();
		for (int i = 0; i < NB_BALLE; i++) // Initialisation des balles de l'acceuil
			data.balle[i] = initBallesAccueil();
		activeGestionDeplacementPassifSouris(); // Active le survol de la souris
		demandeTemporisation(RafraichissementFenetre);
		break;

	case Temporisation:
		gestion(&data, fTempo()); // Fonction de gestion appelée avec la liste de fonctions Tempo
		rafraichisFenetre();
		break;

	case Affichage:
		effaceFenetre(0, 0, 0);
		gestion(&data, fAffiche()); // Fonction de gestion appelée avec la liste de fonctions Affiche
		//GRILLE;
		break;

	case Clavier:
		gestion(&data, fClavier()); // Fonction de gestion appelée avec la liste de fonctions Clavier
		break;

	case ClavierSpecial:
		break;

	case BoutonSouris:
		gestion(&data, fClic()); // Fonction de gestion appelée avec la liste de fonctions Clic
		break;

	case Souris:
		break;

	case Inactivite:
		break;

	case Redimensionnement:
		Redim(&data); // Fonction de Redimensinnement
		break;
	}
}