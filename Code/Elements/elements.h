#include "../lib.h"
#include "../Moteur/moteur.h"

void rouage(const int x, const int y, const int r);
void plateau(const int teinte);
void affichePause(const int * const select);
void raquette(const Raquette * const raquette, const int teinte);
void balle(const Balle * const balleJeu, const int teinte);
void score(const int score, const bool side, const int teinte);
void afficheDigit(const bool * const digit, const bool side, const int i, const int teinte);
void afficheUsers(const User * maUsers);