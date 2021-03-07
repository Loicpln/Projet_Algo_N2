#include "../lib.h"
#include "../Sauvegarde/save.h"

Page initPages();
void initSelect(int * const select);
Balle initBallesAccueil();
Raquette initRaquettes(const int i);
Balle initBalleJeu();
int initScore();
User * chargeUsersDepuisFichier();

void mouvementBalle(Balle * const balle);
void rebond(Balle * const balle, const int min_x, const int min_y, const int max_x, const int max_y);
void redimBalle(Balle * constballe);
void accelereBalle(Balle * const balle, const float a);
void selectPause(int * const select);
void redimRaquette(Raquette * const raquette, const int i);
void touchePause(Page * const page);
void touches(Raquette * const raquette);
void up(Raquette * const raquette);
void down(Raquette * const raquette);
void nombre(bool * const digit, const int score);
void hitbox(Balle * const balle, const Raquette * const raquette);
void but(Balle * const balle, int * const score);
void IA(Balle * const balle, Raquette * const raquette);