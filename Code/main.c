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
	static Data d;
	Data *data = &d;

	switch (evenement)
	{
	case Initialisation:
		init(data);
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
		gestion(data, fClic());
		break;

	case Souris:
		break;

	case Inactivite:
		break;

	case Redimensionnement:
		gestion(data, fRedim());
		break;
	}
}
