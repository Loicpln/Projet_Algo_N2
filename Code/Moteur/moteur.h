#include "../lib.h"
#include "../Sauvegarde/save.h"

void initPages(Page *page);
void initSelect(int *select);
void initBallesAccueil(Balle *balle);
void initRaquettes(Raquette *raquette);
void initBalleJeu(Balle *balle);
void initScore(int *score);
void initUsers(Users *users);
void mouvementBalle(Balle *balle);
void rebond(Balle *balle, int min_x, int min_y, int max_x, int max_y);
void redimBalle(Balle *balle);
void accelereBalle(Balle *balle, float a);
void redimRaquette(Raquette *raquette, int i);
void touchePause(Page *page);
void touches(Raquette *raquette);
void up(Raquette *raquette);
void down(Raquette *raquette);
void nombre(int score, bool *digit);
void hitbox(Balle *balle, Raquette *raquette);
void but(Balle *balle, int *score);
void IA(Balle *balle, Raquette *raquette);