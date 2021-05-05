#include "moteur.h"

//Ensemble des fonctions d'initialisation

Data init() { return (Data){{Acceuil, false, {{1, {255}}}}, {initBallesAccueil()}, initBalleJeu(), {{initScore(), NULL, initRaquetteG(LONG_RAQUETTE)}, {initScore(), NULL, initRaquetteD(LONG_RAQUETTE)}}, chargeUsersDepuisFichier(), initOptions(), Deux_Min, ""}; }

Balle initBallesAccueil() { return (Balle){rand() % MAX_X, rand() % MAX_Y, R_ACCEUIL, V_ACCEUIL, V_ACCEUIL, fabsf(V_ACCEUIL)}; }

Raquette initRaquetteG(int longeur) { return (Raquette){longeur, LARG_RAQUETTE, X_RAQUETTE_LEFT, (MAX_Y_PLATEAU + MIN_Y_PLATEAU) / 2, V_RAQUETTE, 'a', 'q'}; }

Raquette initRaquetteD(int longeur) { return (Raquette){longeur, LARG_RAQUETTE, X_RAQUETTE_RIGHT, (MAX_Y_PLATEAU + MIN_Y_PLATEAU) / 2, V_RAQUETTE, 'p', 'm'}; }

Balle initBalleJeu() { return (Balle){MID_X, (MAX_Y_PLATEAU + MIN_Y_PLATEAU) / 2, R_BALLE, V_BALLE, VH_BALLE, fabsf(V_BALLE)}; }

Options initOptions() { return (Options){ContreLaMontre, Deux_Min, NBVIES, (42 * Ux - absBar1) / 2, (90 * Ux - absBar2) / 2, 1}; }

Users *chargeUsersDepuisFichier()
{
	Users *users = NULL;
	FILE *file = fopen("./Sauvegarde/Users.txt", "r");
	char pseudo[30];
	int id, nbGame, nbWin, nbLose;
	users = malloc(sizeof(Users));
	users->premier = NULL;
	if (file != NULL)
	{
		while (fgetc(file) != EOF)
		{
			fscanf(file, "id=%d |pseudo=%s |nbGame=%d |nbWin=%d |nbLose=%d]\n", &id, pseudo, &nbGame, &nbWin, &nbLose);
			users = ajouteUsers(users, creeUser(id, pseudo, nbGame, nbWin, nbLose));
		}
		fclose(file);
	}
	return users;
}

int initScore() { return (int)0; }

void resetSelect(Select *const select)
{
	for (int i = 0; i < NB_SELECT; i++) // Pour tous les Select
	{
		select[i].largeur = L_SELECT_OFF;
		select[i].couleur[0] = 255;
		select[i].couleur[1] = 255;
		select[i].couleur[2] = 255;
	}
}

void resetUsers(Joueur *const joueur)
{
	for (int i = 0; i < NB_JOUEUR; i++) // Pour tous les joueurs
		joueur[i].user = NULL;
}

void resetTimer(int *const timer, const Options options)
{
	timer[0] = options.temps[0];
	timer[1] = options.temps[1];
}

void resetRaquette(Joueur *const joueur, const Options options)
{
	int longueur;
	if (options.raquette == 0)
		longueur = 2 * LONG_RAQUETTE / 3;
	else if (options.raquette == 1)
		longueur = LONG_RAQUETTE;
	else if (options.raquette == 2)
		longueur = 3 * LONG_RAQUETTE / 2;
	for (int i = 0; i < NB_JOUEUR; i++)
		joueur[i].raquette = (i % 2) ? initRaquetteD(longueur) : initRaquetteG(longueur);
}

void resetScore(Joueur *const joueur)
{
	for (int i = 0; i < NB_JOUEUR; i++) // Pour tous les joueurs
		joueur[i].score = initScore();
}

void resetBalle(Balle *const balle, const Options options)
{
	balle->x = MID_X;
	balle->y = (MAX_Y_PLATEAU + MIN_Y_PLATEAU) / 2;
	balle->r = R_BALLE * options.r / (90 * Ux - absBar2) + 8;
	balle->v0 = V_BALLE * options.v0 / (42 * Ux - absBar1) + 4;
	balle->vx = rand() % 2 ? -balle->v0 : balle->v0;
	balle->vy = VH_BALLE;
}