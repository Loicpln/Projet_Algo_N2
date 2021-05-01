#include "moteur.h"

Data init() { return (Data){{Acceuil, false, {{1, {255}}}}, {{0, 0, 0, 0, 0, 0}}, initBalleJeu(), {{initScore(), NULL, initRaquetteG()}, {initScore(), NULL, initRaquetteD()}}, chargeUsersDepuisFichier(), initOptions(), Cinq_Min, ""}; }

Balle initBallesAccueil() { return (Balle){rand() % MAX_X, rand() % MAX_Y, R_ACCEUIL, V_ACCEUIL, V_ACCEUIL, fabsf(V_BALLE)}; }

Raquette initRaquetteG() { return (Raquette){LONG_RAQUETTE, LARG_RAQUETTE, X_RAQUETTE_LEFT, (MAX_Y_PLATEAU + MIN_Y_PLATEAU) / 2, V_RAQUETTE, 'a', 'q'}; }

Raquette initRaquetteD() { return (Raquette){LONG_RAQUETTE, LARG_RAQUETTE, X_RAQUETTE_RIGHT, (MAX_Y_PLATEAU + MIN_Y_PLATEAU) / 2, V_RAQUETTE, 'p', 'm'}; }

Balle initBalleJeu() { return (Balle){MID_X, (MAX_Y_PLATEAU + MIN_Y_PLATEAU) / 2, R_BALLE, V_BALLE, VH_BALLE, fabsf(V_BALLE)}; }

Options initOptions() { return (Options){ContreLaMontre, Cinq_Min, NBVIES, (52*Ux)/2 - absBar1, (148*Ux)/2 - absBar2}; }

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
	for (int i = 0; i < NB_SELECT; i++)
	{
		select[i].largeur = 1;
		select[i].couleur[0] = 255;
		select[i].couleur[1] = 255;
		select[i].couleur[2] = 255;
	}
}

void resetUsers(Joueur *const joueur)
{
	for (int i = 0; i < NB_JOUEUR; i++)
		joueur[i].user = NULL;
}

void resetTimer(int *const timer, const Options options)
{
	timer[0] = options.temps[0];
	timer[1] = options.temps[1];
}

void resetRaquette(Joueur *const joueur)
{
	for (int i = 0; i < NB_JOUEUR; i++)
		joueur[i].raquette = (i % 2) ? initRaquetteD() : initRaquetteG();
}

void resetScore(Joueur *const joueur)
{
	for (int i = 0; i < NB_JOUEUR; i++)
		joueur[i].score = initScore();
}

void resetBalle(Balle *const balle, const Options *const options)
{
	balle->x = MID_X;
	balle->y = (MAX_Y_PLATEAU + MIN_Y_PLATEAU) / 2;
	balle->r = R_BALLE * options->triangle2 / (90*Ux - absBar2) + 8;
	balle->v0 = V_BALLE * options->triangle1 / (42*Ux - absBar1);
	balle->vx = rand() % 2 ? -balle->v0 : balle->v0;
	balle->vy = VH_BALLE;
}
