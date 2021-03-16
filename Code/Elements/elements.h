#include "../lib.h"
#include "../Moteur/moteur.h"

//Affiche l'élément rouage
void rouage(const int x, const int y, const int r);
//Affiche le plateau
void plateau(const int teinte);
//Affiche le menu pause
void affichePause(const Select *const select);
//Affiche l'élément raquette
void raquette(const Raquette raquette, const int teinte);
//Affiche l'élément balle
void balle(const Balle balleJeu, const int teinte);
//Affiche l'élément les digit selon le score
void score(const int score, const bool side, const int teinte);
//Affiche l'élément Digit
void afficheDigit(const bool * const digit, const bool side, const int i, const int teinte);
//Affiche tout les Users
void afficheUsers(const User * maUsers);