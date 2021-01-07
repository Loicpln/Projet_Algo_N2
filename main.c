#include"fonction.h"

	
int main(int argc, char **argv)
{
	initialiseGfx(argc, argv);
	prepareFenetreGraphique("GfxLib", LargeurFenetre, HauteurFenetre);
	lanceBoucleEvenements();
	
	return 0;
}

void gestionEvenement(EvenementGfx evenement)
{
	
	switch (evenement)
	{
		case Initialisation:
			demandeTemporisation(20);
			break;
		
		case Temporisation:
			rafraichisFenetre();
			break;
			
		case Affichage:
			effaceFenetre (255, 255, 255);
			break;
			
		case Clavier:
			break;
			
		case ClavierSpecial:
			break;

		case BoutonSouris:
			if (etatBoutonSouris() == GaucheAppuye)
			{
				
			}
			break;
		
		case Souris:
			break;
		
		case Inactivite: 
			break;
		
		case Redimensionnement: 
			//printf("Largeur : %d\t", largeurFenetre());
			//printf("Hauteur : %d\n", hauteurFenetre());
			break;
	}
}

