#include "../lib.h"

void mouvementBalle(Balle *balle);
void rebond(Balle *balle, int min_x, int min_y, int max_x, int max_y);
void redimBalle(Balle *balle);
void accelereBalle(Balle *balle, float a);
void redimRaquette(Raquette *raquette);
void touches(Raquette *raquette);
void up(Raquette *raquette);
void down(Raquette *raquette);
void nombre(int score, bool digit[]);
void hitbox();