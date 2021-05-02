#include "moteur.h"
//Initialisation
Data init() { return (Data){{Acceuil, false, {{1, {255}}}}, {{0, 0, 0, 0, 0, 0}}, initBalleJeu(), {{initScore(), NULL, initRaquetteG(LONG_RAQUETTE)}, {initScore(), NULL, initRaquetteD(LONG_RAQUETTE)}}, chargeUsersDepuisFichier(), initOptions(), Deux_Min, ""}; }
//Initialisation des balles de décoration de l'accueil
Balle initBallesAccueil() { return (Balle){rand() % MAX_X, rand() % MAX_Y, R_ACCEUIL, V_ACCEUIL, V_ACCEUIL, fabsf(V_BALLE)}; }
//Initialisation de la raquette de gauche
Raquette initRaquetteG(int longeur) { return (Raquette){longeur, LARG_RAQUETTE, X_RAQUETTE_LEFT, (MAX_Y_PLATEAU + MIN_Y_PLATEAU) / 2, V_RAQUETTE, 'a', 'q'}; }
//Initialisation de la raquette de droite
Raquette initRaquetteD(int longeur) { return (Raquette){longeur, LARG_RAQUETTE, X_RAQUETTE_RIGHT, (MAX_Y_PLATEAU + MIN_Y_PLATEAU) / 2, V_RAQUETTE, 'p', 'm'}; }
//Initialisation de la balle de jeu
Balle initBalleJeu() { return (Balle){MID_X, (MAX_Y_PLATEAU + MIN_Y_PLATEAU) / 2, R_BALLE, V_BALLE, VH_BALLE, fabsf(V_BALLE)}; }
//Initialisation du menu des modes de jeu
Options initOptions() { return (Options){ContreLaMontre, Deux_Min, NBVIES, (42 * Ux - absBar1) / 2, (90 * Ux - absBar2) / 2, 1}; }
//Fonction de chargement depuis un fichier texte
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
//Initialisation du score
int initScore() { return (int)0; }
//Reinitialisation des selects
void resetSelect(Select *const select)
{
	for (int i = 0; i < NB_SELECT; i++)
	{
		select[i].largeur = L_SELECT_OFF;
		select[i].couleur[0] = 255;
		select[i].couleur[1] = 255;
		select[i].couleur[2] = 255;
	}
}
//Réinitialisation des joueurs
void resetUsers(Joueur *const joueur)
{
	for (int i = 0; i < NB_JOUEUR; i++)
		joueur[i].user = NULL;
}
//Réinitialisation du timer
void resetTimer(int *const timer, const Options options)
{
	timer[0] = options.temps[0];
	timer[1] = options.temps[1];
}
//Réinitialisation des raquettes
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
//Réinitialisation du score
void resetScore(Joueur *const joueur)
{
	for (int i = 0; i < NB_JOUEUR; i++)
		joueur[i].score = initScore();
}
//Réinitialisation de la balle
void resetBalle(Balle *const balle, const Options options)
{
	balle->x = MID_X;
	balle->y = (MAX_Y_PLATEAU + MIN_Y_PLATEAU) / 2;
	balle->r = R_BALLE * options.triangle2 / (90 * Ux - absBar2) + 8;
	balle->v0 = V_BALLE * options.triangle1 / (42 * Ux - absBar1) + 4;
	balle->vx = rand() % 2 ? -balle->v0 : balle->v0;
	balle->vy = VH_BALLE;
}
