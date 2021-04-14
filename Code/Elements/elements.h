#include "../lib.h"
#include "../Moteur/moteur.h"

void bouton(const Select select, const int xBasGauche, const int yBasGauche, const int xHautDroite, const int yHautDroite);
//Affiche l'élément rouage
void rouage(const Select select, const int x, const int y, const int r);
//Affiche le plateau
void plateau(const int teinte);
void plus(const int xBasGauche, const int yBasGauche, const int xHautDroite, const int yHautDroite);
void coeur(const int x, const int y, const float r);
//Affiche le menu pause
void affichePause(const Select *const select);
//Affiche la zone de texte
void zoneText(const Select *const select, const char chaine[]);
//Affiche l'élément raquette
void raquette(const Raquette raquette, const int teinte);
//Affiche l'élément balle
void balle(const Balle balleJeu, const int teinte);
//Affiche l'élément les digit selon le score
void score(const int score, const int x, const int y);

void timer(const int temps[], const int x, const int y);
//Affiche l'élément Digit
void afficheDigit(const Digit digit, const int x, const int y);
//Affiche tout les Users
void afficheUsers(const Select *const select, const Users *const maUsers, const int teinte);