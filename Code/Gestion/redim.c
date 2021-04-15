#include "gestion.h"

void Redim(Data *const data)
{
    for (int i = 0; i < NB_BALLE; i++)
        redimBalle(data->balle + i);
    for (int i = 0; i < NB_JOUEUR; i++)
        redimRaquette(&data->joueurs[i].raquette, i);
}

void redimBalle(Balle *const balle)
{
	if (balle->x >= largeurFenetre())
		balle->x = largeurFenetre() - 1;
	if (balle->y >= hauteurFenetre())
		balle->y = hauteurFenetre() - 1;
}

void redimRaquette(Raquette *const raquette, const int i)
{
    if (raquette->y + raquette->longueur / 2 > MAX_Y_PLATEAU)
        raquette->y = MAX_Y_PLATEAU - raquette->longueur / 2;
    if (raquette->y - raquette->longueur / 2 < MIN_Y_PLATEAU)
        raquette->y = MIN_Y_PLATEAU + raquette->longueur / 2;
    raquette->x = (i % 2) ? X_RAQUETTE_RIGHT : X_RAQUETTE_LEFT;
}