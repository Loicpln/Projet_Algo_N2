#include "moteur.h"

Page initPages() { return (Page){1, false, {1}}; }

void initSelect(int *const select)
{
	for (int i = 0; i < NB_SELECT; i++)
		select[i] = 1;
}

Balle initBallesAccueil() { return (Balle){rand() % largeurFenetre(), rand() % hauteurFenetre(), 10, (rand() % 2) ? 5 : -5, (rand() % 2) ? 5 : -5, 5}; }

Raquette initRaquettes(const int i) { return (Raquette){100, 10, (i % 2) ? RAQUETTE_X_RIGHT : RAQUETTE_X_LEFT, (MAX_Y_PLATEAU + MIN_Y_PLATEAU) / 2, 15, (i % 2) ? 'p' : 'a', (i % 2) ? 'm' : 'q'}; }

Balle initBalleJeu() { return (Balle){MID_X, (MAX_Y_PLATEAU - MIN_Y_PLATEAU) / 2, 7, 5, 0.1, 5}; }

int initScore() { return (int)0; }

User *chargeUsersDepuisFichier()
{
	User *maUsers = NULL;
	FILE *file = fopen("Users.txt", "r");
	char pseudo[30];
	int nbGame, nbWin, nbLose;
	if (file != NULL)
	{
		while (fgetc(file) != EOF)
		{
			fscanf(file, "pseudo=%s |nbGame=%d |nbWin=%d |nbLose=%d]\n", pseudo, &nbGame, &nbWin, &nbLose);
			maUsers = ajouteUsers(maUsers, creeUser(pseudo, nbGame, nbWin, nbLose));
		}
		fclose(file);
	}
	return maUsers;
}