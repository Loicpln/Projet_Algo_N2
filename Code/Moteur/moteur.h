#include "../lib.h"
#include "../Sauvegarde/save.h"

Data init();
Balle initBallesAccueil();
Raquette initRaquetteG();
Raquette initRaquetteD();
Balle initBalleJeu();
int initScore();
void resetSelect(Select *const select);
void resetAllSelect(Select *const select);
User * chargeUsersDepuisFichier();

void couleurSelect(Select *const select,int id, int R, int V, int B);
void mouvementBalle(Balle * const balle);
void rebond(Balle * const balle, const int min_x, const int min_y, const int max_x, const int max_y);
void accelereBalle(Balle * const balle, const float facteur);
void selectPause(Select * const select);
void clicUsers(Joueur *const joueur, User *const users);
void resetJoueurs(Joueur * const joueur);
void resetRaquette(Joueur * const joueur);
void resetScore(Joueur * const joueur);
void touchePause(Page * const page);
void touches(Raquette * const raquette);
void up(Raquette * const raquette);
void down(Raquette * const raquette);
void nombre(bool * const digit, const int score);
void hitbox(Balle * const balle, const Raquette * const raquette);
void but(Balle * const balle, Joueur * const joueur);
void IA(Balle * const balle, Raquette * const raquette);