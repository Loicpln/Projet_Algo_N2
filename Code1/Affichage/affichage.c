#include "gestion.h"

void AfficheAccueil(Data *data) //Affichage page d'accueil
{
    couleurCourante(255, 0, 0);
    for (int i = 0; i < MAX_BALLE; i++)
        cercle(data->balle[i].x, data->balle[i].y, data->balle[i].r);

    epaisseurDeTrait(3);
    couleurCourante(255, 255, 255);
    rectangle(3 * largeurFenetre() / 4, hauteurFenetre() / 12, 15 * largeurFenetre() / 16, hauteurFenetre() / 6);              //Quitter
    rectangle(5 * largeurFenetre() / 16, 16 * hauteurFenetre() / 24, 11 * largeurFenetre() / 16, 19 * hauteurFenetre() / 24);  //jouer
    rectangle(11 * largeurFenetre() / 32, 11 * hauteurFenetre() / 24, 21 * largeurFenetre() / 32, 14 * hauteurFenetre() / 24); //reglement

    couleurCourante(0, 0, 0);
    rectangle(3 * largeurFenetre() / 4 + 1, hauteurFenetre() / 12 + 1, 15 * largeurFenetre() / 16 - 1, hauteurFenetre() / 6 - 1);              //Quitter
    rectangle(5 * largeurFenetre() / 16 + 1, 2 * hauteurFenetre() / 3 + 1, 11 * largeurFenetre() / 16 - 1, 19 * hauteurFenetre() / 24 - 1);    //jouer
    rectangle(11 * largeurFenetre() / 32 + 1, 11 * hauteurFenetre() / 24 + 1, 21 * largeurFenetre() / 32 - 1, 14 * hauteurFenetre() / 24 - 1); //reglement

    couleurCourante(255, 255, 255);
    afficheChaine("Jouer", 60, 13 * largeurFenetre() / 32, 83 * hauteurFenetre() / 120);
    afficheChaine("Reglement", 40, 3 * largeurFenetre() / 8, hauteurFenetre() / 2);
    afficheChaine("Quitter", 30, 31 * largeurFenetre() / 40, hauteurFenetre() / 10);
}

void AfficheMenu(Data *data)
{
    couleurCourante(rand() % 255, rand() % 255, rand() % 255);
    for (int i = 0; i < MAX_BALLE; i++)
        cercle(data->balle[i].x, data->balle[i].y, data->balle[i].r);

    epaisseurDeTrait(3);
    couleurCourante(rand() % 255, rand() % 255, rand() % 255);
    rectangle(9 * largeurFenetre() / 32, 16 * hauteurFenetre() / 24, 24 * largeurFenetre() / 32, 19 * hauteurFenetre() / 24); //JcJ
    rectangle(9 * largeurFenetre() / 32, hauteurFenetre() / 2, 24 * largeurFenetre() / 32, 15 * hauteurFenetre() / 24);       //contreIA
    rectangle(9 * largeurFenetre() / 32, hauteurFenetre() / 3, 24 * largeurFenetre() / 32, 11 * hauteurFenetre() / 24);       //entrainement
    rectangle(3 * largeurFenetre() / 4, hauteurFenetre() / 12, 15 * largeurFenetre() / 16, hauteurFenetre() / 6);             //Quitter

    couleurCourante(0, 0, 0);
    rectangle(9 * largeurFenetre() / 32 + 1, 2 * hauteurFenetre() / 3 + 1, 24 * largeurFenetre() / 32 - 1, 19 * hauteurFenetre() / 24 - 1); //JcJ
    rectangle(9 * largeurFenetre() / 32 + 1, hauteurFenetre() / 2 + 1, 24 * largeurFenetre() / 32 - 1, 15 * hauteurFenetre() / 24 - 1);     //contreIA
    rectangle(9 * largeurFenetre() / 32 + 1, hauteurFenetre() / 3 + 1, 24 * largeurFenetre() / 32 - 1, 11 * hauteurFenetre() / 24 - 1);     //entrainement
    rectangle(3 * largeurFenetre() / 4 + 1, hauteurFenetre() / 12 + 1, 15 * largeurFenetre() / 16 - 1, hauteurFenetre() / 6 - 1);           //Quitter

    couleurCourante(255, 255, 255);
    afficheChaine("Joueur contre joueur", 30, 5 * largeurFenetre() / 16, 17 * hauteurFenetre() / 24);
    afficheChaine("Jouer contre IA", 30, 5 * largeurFenetre() / 16, 13 * hauteurFenetre() / 24);
    afficheChaine("Entrainement", 30, 5 * largeurFenetre() / 16, 9 * hauteurFenetre() / 24);
    afficheChaine("Retour", 30, 31 * largeurFenetre() / 40, hauteurFenetre() / 10);

    couleurCourante(rand() % 255, rand() % 255, rand() % 255);
    epaisseurDeTrait(8);
    afficheChaine("PONG", 60, 13 * largeurFenetre() / 32, 21 * hauteurFenetre() / 24);
}

void AfficheRegles(Data *data)
{
    epaisseurDeTrait(3);
    couleurCourante(255, 255, 255);
    rectangle(2 * largeurFenetre() / 8, 9 * hauteurFenetre() / 12, 3 * largeurFenetre() / 4, 11 * hauteurFenetre() / 12); //titre
    rectangle(3 * largeurFenetre() / 4, hauteurFenetre() / 12, 15 * largeurFenetre() / 16, hauteurFenetre() / 6);         //Retour

    couleurCourante(0, 0, 0);
    rectangle(2 * largeurFenetre() / 8 + 1, 9 * hauteurFenetre() / 12 + 1, 3 * largeurFenetre() / 4 - 1, 11 * hauteurFenetre() / 12 - 1); //titre
    rectangle(3 * largeurFenetre() / 4 + 1, hauteurFenetre() / 12 + 1, 15 * largeurFenetre() / 16 - 1, hauteurFenetre() / 6 - 1);         //Retour
    epaisseurDeTrait(2);
    couleurCourante(255, 255, 255);
    afficheChaine("Retour", 30, 31 * largeurFenetre() / 40, hauteurFenetre() / 10);
    afficheChaine("Reglement", 60, 5 * largeurFenetre() / 16, 19 * hauteurFenetre() / 24);
    afficheChaine("Le concept original de pong est une simulation simpliste ", 20, largeurFenetre() / 10, 7 * hauteurFenetre() / 12);
    afficheChaine("de tennis de table, les deux joueurs se passent la balle ", 20, largeurFenetre() / 10, 6 * hauteurFenetre() / 12);
    afficheChaine("a l'aide de raquettes, le joueur ayant le plus de points", 20, largeurFenetre() / 10, 5 * hauteurFenetre() / 12);
    afficheChaine("gagne la partie.", 20, largeurFenetre() / 10, 4 * hauteurFenetre() / 12);
}
void AfficheJeu(Data *data)
{
    epaisseurDeTrait(3);
    couleurCourante(255, 255, 255);
    rectangle(5 * largeurFenetre() / 16, 16 * hauteurFenetre() / 24, 11 * largeurFenetre() / 16, 19 * hauteurFenetre() / 24); //jouer
    rectangle(3 * largeurFenetre() / 4, hauteurFenetre() / 12, 15 * largeurFenetre() / 16, hauteurFenetre() / 6);             //Retour

    couleurCourante(0, 0, 0);
    rectangle(5 * largeurFenetre() / 16 + 1, 2 * hauteurFenetre() / 3 + 1, 11 * largeurFenetre() / 16 - 1, 19 * hauteurFenetre() / 24 - 1); //jouer
    rectangle(3 * largeurFenetre() / 4 + 1, hauteurFenetre() / 12 + 1, 15 * largeurFenetre() / 16 - 1, hauteurFenetre() / 6 - 1);           //Retour

    couleurCourante(255, 255, 255);
    afficheChaine("Jouer", 60, 13 * largeurFenetre() / 32, 83 * hauteurFenetre() / 120);
    afficheChaine("Retour", 30, 31 * largeurFenetre() / 40, hauteurFenetre() / 10);
}

void Plateau(Data *data)
{

    couleurCourante(255, 255, 255);
    rectangle(largeurFenetre() / 40, hauteurFenetre() / 120, 39 * largeurFenetre() / 40, 100 * hauteurFenetre() / 120);
    couleurCourante(0, 0, 0);
    rectangle(largeurFenetre() / 30, hauteurFenetre() / 60, 29 * largeurFenetre() / 30, 99 * hauteurFenetre() / 120);
    couleurCourante(255, 255, 255);
    epaisseurDeTrait(3);

    for (int i = 0; i < 10; i++)
    {
        ligne(largeurFenetre() / 2, 100 * hauteurFenetre() / 120 - i * hauteurFenetre() / 6, largeurFenetre() / 2, 90 * hauteurFenetre() / 120 - i * hauteurFenetre() / 6);
    }
    couleurCourante(255, 255, 255); // Raquette gauche
    rectangle(largeurFenetre() / 30 + 10, data->raquette[0].centre + data->raquette[0].longueur / 2, largeurFenetre() / 30 + 10 + data->raquette[0].largeur, data->raquette[0].centre - data->raquette[0].longueur / 2);
    couleurCourante(255, 255, 255); // Raquette droite
    rectangle(29 * largeurFenetre() / 30 - 10 - data->raquette[1].largeur, data->raquette[1].centre + data->raquette[1].longueur / 2, 29 * largeurFenetre() / 30 -10, data->raquette[1].centre - data->raquette[1].longueur / 2);
    epaisseurDeTrait(8);
    couleurCourante(255, 255, 255);
    afficheChaine("PONG", 95, 5 * largeurFenetre() / 16 + 1, 20.5 * hauteurFenetre() / 24 + 1);
}

void nombre (int score, bool digit[])
{
	switch (score)
	{
	case 0: digit[0] = true; digit[1]= true; digit[2]= true; digit[3]= false; digit[4]= true; digit[5]= true; digit[6]= true; break;
	case 1:digit[0] = false; digit[1]= false; digit[2]= true; digit[3]= false; digit[4]= false; digit[5]= true; digit[6]= false; break;
	case 2:digit[0] = true; digit[1]= false; digit[2]= true; digit[3]= true; digit[4]= true; digit[5]= false; digit[6]= true; break;
	case 3:digit[0] = true; digit[1]= false; digit[2]= true; digit[3]= true; digit[4]= false; digit[5]= true; digit[6]= true; break;
	case 4:digit[0] = false; digit[1]= true; digit[2]= true; digit[3]= true; digit[4]= false; digit[5]= true; digit[6]= false; break;
	case 5:digit[0] = true; digit[1]= true; digit[2]= false; digit[3]= true; digit[4]= false; digit[5]= true; digit[6]= true; break;
	case 6:digit[0] = true; digit[1]= true; digit[2]= false; digit[3]= true; digit[4]= true; digit[5]= true; digit[6]= true; break;
	case 7:digit[0] = true; digit[1]= false; digit[2]= true; digit[3]=false; digit[4]= false; digit[5]= true; digit[6]= false; break;
	case 8:digit[0] = true; digit[1]= true; digit[2]= true; digit[3]= true; digit[4]= true; digit[5]= true; digit[6]= true; break;
	case 9:digit[0] = true; digit[1]= true; digit[2]= true; digit[3]= true; digit[4]= false; digit[5]= true; digit[6]= true; break;
	}
}


void score(int score)
{
	bool dizaine[7];
	bool unite[7];
	nombre(floor(score/10), dizaine);
	nombre(score-10*floor(score/10), unite);
	couleurCourante(255,255,255);
	epaisseurDeTrait(5);
	
	

	//SCORE GAUCHE
	//UNITE
	//digit 1
	(unite[0]==true)? couleurCourante(255,255,255):couleurCourante(0,0,0);
	ligne(
		largeurFenetre() / 4-largeurFenetre()/100, 3*hauteurFenetre() / 4+ largeurFenetre()/50,
		largeurFenetre() / 4+largeurFenetre()/100, 3*hauteurFenetre() / 4+ largeurFenetre()/50);
	
	//digit 2
	(unite[1]==true)? couleurCourante(255,255,255):couleurCourante(0,0,0);
	ligne(
		largeurFenetre() / 4-largeurFenetre()/100, 3*hauteurFenetre() / 4+ largeurFenetre()/50,
		largeurFenetre() / 4-largeurFenetre()/100, 3*hauteurFenetre() / 4);
	
	//digit 3
	(unite[2]==true)? couleurCourante(255,255,255):couleurCourante(0,0,0);
	ligne(
		largeurFenetre() / 4+largeurFenetre()/100, 3*hauteurFenetre() / 4,
		largeurFenetre() / 4+largeurFenetre()/100, 3*hauteurFenetre() / 4+ largeurFenetre()/50);
	
	//digit 4
	(unite[3]==true)? couleurCourante(255,255,255):couleurCourante(0,0,0);
	ligne(
		largeurFenetre() / 4-largeurFenetre()/100, 3*hauteurFenetre() / 4,
		largeurFenetre() / 4+largeurFenetre()/100, 3*hauteurFenetre() / 4);

	//digit 5
	(unite[4]==true)? couleurCourante(255,255,255):couleurCourante(0,0,0);
	ligne(
		largeurFenetre() / 4-largeurFenetre()/100, 3*hauteurFenetre() / 4,
		largeurFenetre() / 4-largeurFenetre()/100, 3*hauteurFenetre() / 4-largeurFenetre()/50);

	//digit 6
	(unite[5]==true)? couleurCourante(255,255,255):couleurCourante(0,0,0);
	ligne(
		largeurFenetre() / 4+largeurFenetre()/100, 3*hauteurFenetre() / 4,
		largeurFenetre() / 4+largeurFenetre()/100, 3*hauteurFenetre() / 4-largeurFenetre()/50);

	//digit 7
	(unite[6]==true)? couleurCourante(255,255,255):couleurCourante(0,0,0);
	ligne(
		largeurFenetre() / 4-largeurFenetre()/100, 3*hauteurFenetre() / 4-largeurFenetre()/50,
		largeurFenetre() / 4+largeurFenetre()/100, 3*hauteurFenetre() / 4-largeurFenetre()/50);
	//DIZAINE
	//digit 1
	(dizaine[0]==true)? couleurCourante(255,255,255):couleurCourante(0,0,0);
	ligne(
		largeurFenetre() / 4- 4*largeurFenetre()/100, 3*hauteurFenetre() / 4+ largeurFenetre()/50,
		largeurFenetre() / 4- 2*largeurFenetre()/100, 3*hauteurFenetre() / 4+ largeurFenetre()/50);
	
	//digit 2
	(dizaine[1]==true)? couleurCourante(255,255,255):couleurCourante(0,0,0);
	ligne(
		largeurFenetre() / 4- 4*largeurFenetre()/100, 3*hauteurFenetre() / 4+ largeurFenetre()/50,
		largeurFenetre() / 4- 4*largeurFenetre()/100, 3*hauteurFenetre() / 4);
	
	//digit 3
	(dizaine[2]==true)? couleurCourante(255,255,255):couleurCourante(0,0,0);
	ligne(
		largeurFenetre() / 4- 2*largeurFenetre()/100, 3*hauteurFenetre() / 4,
		largeurFenetre() / 4- 2*largeurFenetre()/100, 3*hauteurFenetre() / 4+ largeurFenetre()/50);
	
	//digit 4
	(dizaine[3]==true)? couleurCourante(255,255,255):couleurCourante(0,0,0);
	ligne(
		largeurFenetre() / 4- 4*largeurFenetre()/100, 3*hauteurFenetre() / 4,
		largeurFenetre() / 4- 2*largeurFenetre()/100, 3*hauteurFenetre() / 4);

	//digit 5
	(dizaine[4]==true)? couleurCourante(255,255,255):couleurCourante(0,0,0);
	ligne(
		largeurFenetre() / 4- 4*largeurFenetre()/100, 3*hauteurFenetre() / 4,
		largeurFenetre() / 4- 4*largeurFenetre()/100, 3*hauteurFenetre() / 4-largeurFenetre()/50);

	//digit 6
	(dizaine[5]==true)? couleurCourante(255,255,255):couleurCourante(0,0,0);
	ligne(
		largeurFenetre() / 4- 2*largeurFenetre()/100, 3*hauteurFenetre() / 4,
		largeurFenetre() / 4- 2*largeurFenetre()/100, 3*hauteurFenetre() / 4-largeurFenetre()/50);

	//digit 7
	(dizaine[6]==true)? couleurCourante(255,255,255):couleurCourante(0,0,0);
	ligne(
		largeurFenetre() / 4- 4*largeurFenetre()/100, 3*hauteurFenetre() / 4-largeurFenetre()/50,
		largeurFenetre() / 4- 2*largeurFenetre()/100, 3*hauteurFenetre() / 4-largeurFenetre()/50);



	/*couleurCourante(255,255,255);
	//SCORE DROIT
	//digit 1
	ligne(
		3*largeurFenetre() / 4-largeurFenetre()/100, 3*hauteurFenetre() / 4+ largeurFenetre()/50,
		3*largeurFenetre() / 4+largeurFenetre()/100, 3*hauteurFenetre() / 4+ largeurFenetre()/50);
	//digit 2
	ligne(
		3*largeurFenetre() / 4-largeurFenetre()/100, 3*hauteurFenetre() / 4+ largeurFenetre()/50,
		3*largeurFenetre() / 4-largeurFenetre()/100, 3*hauteurFenetre() / 4);
	//digit 3
	ligne(
		3*largeurFenetre() / 4+largeurFenetre()/100, 3*hauteurFenetre() / 4,
		3*largeurFenetre() / 4+largeurFenetre()/100, 3*hauteurFenetre() / 4+ largeurFenetre()/50);
	//digit 4
	ligne(
		3*largeurFenetre() / 4-largeurFenetre()/100, 3*hauteurFenetre() / 4,
		3*largeurFenetre() / 4+largeurFenetre()/100, 3*hauteurFenetre() / 4);
	//digit 5
	ligne(
		3*largeurFenetre() / 4-largeurFenetre()/100, 3*hauteurFenetre() / 4,
		3*largeurFenetre() / 4-largeurFenetre()/100, 3*hauteurFenetre() / 4-largeurFenetre()/50);
	//digit 6
	ligne(
		3*largeurFenetre() / 4+largeurFenetre()/100, 3*hauteurFenetre() / 4,
		3*largeurFenetre() / 4+largeurFenetre()/100, 3*hauteurFenetre() / 4-largeurFenetre()/50);
	//digit 7
	ligne(
		3*largeurFenetre() / 4-largeurFenetre()/100, 3*hauteurFenetre() / 4-largeurFenetre()/50,
		3*largeurFenetre() / 4+largeurFenetre()/100, 3*hauteurFenetre() / 4-largeurFenetre()/50);*/

}