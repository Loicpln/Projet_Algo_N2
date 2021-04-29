#include <stdlib.h>
#include <stdio.h>
#include "./tpGfx/GfxLib.h"
#include "./tpGfx/BmpLib.h"
#include "sous_traitance.h"

// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 1000
#define HauteurFenetre 800


int main(int argc, char **argv)
{
    initialiseGfx(argc, argv);
    prepareFenetreGraphique("MUTATEUR", LargeurFenetre, HauteurFenetre);
    printf("\n\n ------------oooooOOOooooo------------- \n");
    printf("|                                      | \n");
    lanceBoucleEvenements();

    return 0;
}


void gestionEvenement(EvenementGfx evenement)
{    	
    switch (evenement)
    {
    case Initialisation:
		triangle1=0;
		triangle2=0;
        demandeTemporisation(20);
        break;

    case Temporisation:
       rafraichisFenetre();
        break;

    case Affichage:
      afficheMutateur(); // AFFICHAGE DU MUTATEUR CONTENANT LES OPTIONS
      traceSlider(); // AFFICHAGE DES SLIDERS
      TraceTriangle1(triangle1); // AFFICHAGE CURSEUR GAUCHE
      TraceTriangle2(triangle2); // AFFICHAGE CURSEUR DROITE
      break;

    case Clavier:
        break;

    case ClavierSpecial:
        break;

    case BoutonSouris:
		if (etatBoutonSouris() == GaucheAppuye)
		{
			triangle1=modifTriangle1(triangle1); // CHOIX VITESSE BALLE ET RENVOI % (0 VITESSE MINIMALE, 100 VITESSE MAXIMALE)
			triangle2=modifTriangle2(triangle2); // CHOIX TAILLE BALLE ET RENVOI % (0 TAILLE MINIMALE, 100 TAILLE MAXIMALE)
			valTailleRaq = clicTailleRaq(); // SELECTION TAILLE RAQUETTE ET RENVOI VALEUR (1 = S, 2 = M, 3 = L)
			retour(); // ARRET DU PROGRAMME
		}
        break;

    case Souris:
    case Inactivite:
        break;

    case Redimensionnement:
        break;
    }
}
