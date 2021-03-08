#include "../lib.h"
#include "../Sauvegarde/save.h"

Data init();
Page initPages();
Balle initBallesAccueil();
Raquette initRaquetteG();
Raquette initRaquetteD();
Balle initBalleJeu();
int initScore();
void initSelect(int * const select);
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
void but(Balle * const balle, Joueur * const joueur);
void IA(Balle * const balle, Raquette * const raquette);