#include "moteur.h"

Data init() { return (Data){{Acceuil, false, {{1,{255}}}}, {{0, 0, 0, 0, 0, 0}}, initBalleJeu(), {{initScore(), NULL, initRaquetteG()}, {initScore(), NULL, initRaquetteD()}}, chargeUsersDepuisFichier()}; }

Balle initBallesAccueil() { return (Balle){rand() % largeurFenetre(), rand() % hauteurFenetre(), R_BALLE, V_BALLE, V_BALLE, fabsf(V_BALLE)}; }

Raquette initRaquetteG() { return (Raquette){LONG_RAQUETTE, LARG_RAQUETTE, X_RAQUETTE_LEFT, (MAX_Y_PLATEAU + MIN_Y_PLATEAU) / 2, V_RAQUETTE, 'a', 'q'}; }

Raquette initRaquetteD() { return (Raquette){LONG_RAQUETTE, LARG_RAQUETTE, X_RAQUETTE_RIGHT, (MAX_Y_PLATEAU + MIN_Y_PLATEAU) / 2, V_RAQUETTE, 'p', 'm'}; }

Balle initBalleJeu() { return (Balle){MID_X, (MAX_Y_PLATEAU - MIN_Y_PLATEAU) / 2, R_BALLE, V_BALLE, VH_BALLE, fabsf(V_BALLE)}; }

User *chargeUsersDepuisFichier()
{
	User *maUsers = NULL;
	FILE *file = fopen("./Sauvegarde/Users.txt", "r");
	char pseudo[30];
	int id, nbGame, nbWin, nbLose;
	if (file != NULL)
	{
		while (fgetc(file) != EOF)
		{
			fscanf(file, "id=%d |pseudo=%s |nbGame=%d |nbWin=%d |nbLose=%d]\n", &id, pseudo, &nbGame, &nbWin, &nbLose);
			maUsers = ajouteUsers(maUsers, creeUser(id, pseudo, nbGame, nbWin, nbLose));
		}
		fclose(file);
	}
	return maUsers;
}

int initScore() { return (int)0; }

void resetSelect(Select *const select)
{
	for (int i = 0; i < NB_SELECT; i++){
		select[i].largeur = 1;
		select[i].couleur[0] = 255;
		select[i].couleur[1] = 255;
		select[i].couleur[2] = 255;
	}
}
