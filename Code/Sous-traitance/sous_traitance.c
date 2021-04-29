#include "sous_traitance.h"


// FONCTION AFFICHAGE PAGE MUTATEUR
void afficheMutateur()
{
	// FOND NOIR
    effaceFenetre(0, 0, 0);
    
    // TEXTE MUTATEUR
    couleurCourante(255, 255, 255);
    epaisseurDeTrait(6);
    afficheChaine("MUTATEUR", 60, 4.5 * largeurFenetre() / 14, 10.2* hauteurFenetre() / 12);
    
    // RECTANGLE VITESSE BALLE
    couleurCourante(140, 20, 20);
    rectangle(1.5 * largeurFenetre() / 14, 9 * hauteurFenetre() / 12, 6 * largeurFenetre() / 14, 7.5 * hauteurFenetre() / 12);
    epaisseurDeTrait(3);
    couleurCourante(255, 190, 180);
    afficheChaine("Vitesse balle", 40, 2 * largeurFenetre() / 14, 8 * hauteurFenetre() / 12);
    
    //RECTANGLE TAILLE BALLE
    couleurCourante(140, 20, 20);
    rectangle(8 * largeurFenetre() / 14, 9 * hauteurFenetre() / 12, 12.5 * largeurFenetre() / 14, 7.5 * hauteurFenetre() / 12);
    epaisseurDeTrait(3);
    couleurCourante(255, 190, 180);
    afficheChaine("Taille balle", 40, 8.8 * largeurFenetre() / 14, 8 * hauteurFenetre() / 12);
    
    // RECTANGLE TAILLE RAQUETTE
    couleurCourante(140, 20, 20);
    rectangle(1.5 * largeurFenetre() / 14, 4.1 * hauteurFenetre() / 12, 6.5 * largeurFenetre() / 14, 1.3 * hauteurFenetre() / 6);
    epaisseurDeTrait(3);
    couleurCourante(255, 190, 180);
    afficheChaine("Taille raquette", 40, 2 * largeurFenetre() / 14, 3.1 * hauteurFenetre() / 12);
    
    // RECTANGLE S M L
    couleurCourante(190, 70, 70);
    rectangle(1.5 * largeurFenetre() / 14, 1 * hauteurFenetre() / 12, 7 * largeurFenetre() / 14, 1 * hauteurFenetre() / 6);
    couleurCourante(0, 0, 0);
	epaisseurDeTrait(3);
	ligne(2.83 * largeurFenetre()/12, hauteurFenetre() / 12, 2.83 * largeurFenetre()/12, hauteurFenetre()/6);
	couleurCourante(0, 0, 0);
	epaisseurDeTrait(3);
	ligne(4.425 * largeurFenetre()/12, hauteurFenetre() / 12, 4.425 * largeurFenetre()/12, hauteurFenetre()/6);
	couleurCourante(255, 190, 180);
    afficheChaine("S", 30, 6.5 * largeurFenetre() / 40, 1.08 * hauteurFenetre() / 10);
    couleurCourante(150,56,53);
    couleurCourante(255, 190, 180);
    afficheChaine("M", 30, 11.65 * largeurFenetre() / 40, 1.08 * hauteurFenetre() / 10);
    couleurCourante(150,56,53);
    couleurCourante(255, 190, 180);
    afficheChaine("L", 30, 17.07 * largeurFenetre() / 40, 1.08 * hauteurFenetre() / 10);
    couleurCourante(150,56,53);
    
    // RECTANGLE RETOUR
    couleurCourante(140, 130, 140);
    rectangle(3 * largeurFenetre() / 4, hauteurFenetre() / 12, 15 * largeurFenetre() / 16, hauteurFenetre() / 6);
    epaisseurDeTrait(3);
    couleurCourante(255, 255, 255);
    afficheChaine("Retour", 30, 31.9 * largeurFenetre() / 40, 1.1 * hauteurFenetre() / 10);
    couleurCourante(150,56,53);
}


// FONCTION AFFICHAGE DES SLIDERS
void traceSlider() 
{
	couleurCourante(168,168,168);
	rectangle(absBar1, 6.1 * hauteurFenetre() / 12, 6 * largeurFenetre() / 14, 6 * hauteurFenetre() / 12);
	couleurCourante(255,0,0);
	
	couleurCourante(168,168,168);
	rectangle(absBar2, 6.1 * hauteurFenetre() / 12, 12.5 * largeurFenetre() / 14, 6 * hauteurFenetre() / 12);
	couleurCourante(255,0,0);
}


// FONCTION AFFICHAGE CURSEUR GAUCHE
void TraceTriangle1(int Triangle)
{
	triangle(1.3 * largeurFenetre() / 14+Triangle, 6.5 * hauteurFenetre() / 12, 1.5 * largeurFenetre() / 14+Triangle, 6 * hauteurFenetre() / 12, 1.7 * largeurFenetre() / 14+Triangle, 6.5 * hauteurFenetre() / 12);
}


// FONCTION AFFICHAGE CURSEUR DROITE
void TraceTriangle2(int Triangle)
{
	triangle(7.8 * largeurFenetre() / 14+Triangle, 6.5 * hauteurFenetre() / 12, 8 * largeurFenetre() / 14+Triangle, 6 * hauteurFenetre() / 12, 8.2 * largeurFenetre() / 14+Triangle, 6.5 * hauteurFenetre() / 12);
}


// FONCTION MODIFICATION POSITION CURSEUR GAUCHE
int modifTriangle1(int triangle)
{
	if(abscisseSouris() >= (1.5 * largeurFenetre() / 14)  && abscisseSouris() <= (6 * largeurFenetre() / 14) && ordonneeSouris() >= (6 * hauteurFenetre() / 12) && ordonneeSouris() <= (6.1 * hauteurFenetre() / 12))
		{
			triangle=abscisseSouris()-absBar1;
			printf("|                                      | \n");
			printf("| Vitesse de la balle de 0 à 100 : %d  |\n", triangle*100/318);	
		}
		
		return triangle;
}


// FONCTION MODIFICATION POSITION CURSEUR DROITE
int modifTriangle2(int triangle)
{
	if(abscisseSouris() >= (8 * largeurFenetre() / 14)  && abscisseSouris() <= (12.5 * largeurFenetre() / 14) && ordonneeSouris() >= (6 * hauteurFenetre() / 12) && ordonneeSouris() <= (6.1 * hauteurFenetre() / 12))
		{
			triangle=abscisseSouris()-absBar2;
			printf("|                                      | \n");
			printf("|  Taille de la balle de 0 à 100 : %d  |\n", triangle*100/318);
		}
		return triangle;
}


// FONCTION SELECTION TAILLE RAQUETTE
int clicTailleRaq()
{
	int valTailleRaq;
	valTailleRaq = 0;
	
	if(etatBoutonSouris() == GaucheAppuye) 
	{
		if(abscisseSouris() >= (1.5 * largeurFenetre() / 14)  && abscisseSouris() <= (2.83 * largeurFenetre() / 12) && ordonneeSouris() >= (hauteurFenetre() / 12) && ordonneeSouris() <= (1 * hauteurFenetre() / 6))
		{
			valTailleRaq = 1;
		    printf("|                                      | \n");
			printf("|         Raquette de taille S         |\n");
		}
		else if((abscisseSouris() >= (2.83 * largeurFenetre() / 12)  && abscisseSouris() <= (4.425 * largeurFenetre() / 12) && ordonneeSouris() >= (hauteurFenetre() / 12) && ordonneeSouris() <= (1 * hauteurFenetre() / 6)))
		{
			valTailleRaq = 2;
		    printf("|                                      | \n");
			printf("|         Raquette de taille M         |\n");
		}
		else if((abscisseSouris() >= (4.425 * largeurFenetre() / 12)  && abscisseSouris() <= (7 * largeurFenetre() / 14) && ordonneeSouris() >= (hauteurFenetre() / 12) && ordonneeSouris() <= (1 * hauteurFenetre() / 6)))
		{
			valTailleRaq = 3;     
		    printf("|                                      | \n");
			printf("|         Raquette de taille L         |\n");

		}
	}
	return valTailleRaq;
}


// FONCTION TOUCHE RETOUR
void retour()
{
	if(abscisseSouris() >= (3 * largeurFenetre() / 4)  && abscisseSouris() <= (15 * largeurFenetre() / 16) && ordonneeSouris() >= (hauteurFenetre() / 12) && ordonneeSouris() <= (hauteurFenetre() / 6))
	{
		printf("|                                      | \n");
		printf("|                                      | \n");		
		printf(" ------------oooooOOOooooo------------- \n\n");
		termineBoucleEvenements();
	}
}
