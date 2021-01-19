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

	static Balle tab[MAX_BALLE];

	switch (evenement)
	{
	case Initialisation:
		for (int i = 0; i < MAX_BALLE; i++)
		{
			tab[i].x = largeurFenetre() * valeurAleatoire();
			tab[i].y = hauteurFenetre() * valeurAleatoire();
			tab[i].r = 10;
			tab[i].vx = -5;
			tab[i].vy = -5;
			if(rand()%2)
				tab[i].vx = fabsf(tab[i].vx);
			
			if(rand()%2)
				tab[i].vy = fabsf(tab[i].vy);
			
		}
		demandeTemporisation(20);
		break;

	case Temporisation:
		for (int i = 0; i < MAX_BALLE; i++)
		{
			tab[i].x += tab[i].vx;
			tab[i].y += tab[i].vy;

			if (tab[i].x < 0 || tab[i].x >= largeurFenetre())
				tab[i].vx = -tab[i].vx;
			if (tab[i].y < 0 || tab[i].y >= hauteurFenetre())
				tab[i].vy = -tab[i].vy;
		}
		rafraichisFenetre();
		break;

	case Affichage:
		effaceFenetre(0, 0, 0);
		gestion(page, tab, fAffiche());
		break;

	case Clavier:
		gestion(page, tab, fClavier());
		break;

	case ClavierSpecial:
		break;

	case BoutonSouris:
		gestion(page, tab, fClick());
		break;

	case Souris:
		break;

	case Inactivite:
		break;

	case Redimensionnement:
		for (int i = 0; i < MAX_BALLE; i++)
		{
			if (tab[i].x >= largeurFenetre())
				tab[i].x = largeurFenetre() - 1;
			if (tab[i].y >= hauteurFenetre())
				tab[i].y = hauteurFenetre() - 1;
		}
		break;
	}
}
