#include "../lib.h"
#include "../Sauvegarde/save.h"

Data init();
Balle initBallesAccueil();
Raquette initRaquetteG();
Raquette initRaquetteD();
Balle initBalleJeu();
int initScore();
void resetSelect(Select *const select);
Users *chargeUsersDepuisFichier();

void couleurSelect(Select *const select, const int R, const int V, const int B);
void mouvementBalle(Balle *const balle);
void rebond(Balle *const balle, const int min_x, const int min_y, const int max_x, const int max_y);
void accelereBalle(Balle *const balle, const float facteur);
void selectAcceuil(Select *const select);
void selectMenu(Select *const select);
void selectRegles(Select *const select);
void selectPause(Select *const select);
void clicPause(Data *const data);
void selectSelection(Select *const select);
void clicUsers(Joueur *const joueur, Users *const users);
void clicRouage(Page *const page);
void resetJoueurs(Joueur *const joueur);
void resetRaquette(Joueur *const joueur);
void resetScore(Joueur *const joueur);
void touchePause(Page *const page);
void ecrire(char text[]);
void touches(Raquette *const raquette);
void up(Raquette *const raquette);
void down(Raquette *const raquette);
Digit nombre(const int score);
int signe(const float val);
void hitbox(Balle *const balle, const Raquette *const raquette);
void but(Balle *const balle, Joueur *const joueur);
void IA(Raquette *const raquette, const Balle *const balle);