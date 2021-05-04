#include "../lib.h"
#include "../Moteur/moteur.h"

//Affiche l'élément bouton
void bouton(const Select select, const float xBasGauche, const float yBasGauche, const float xHautDroite, const float yHautDroite);
//Affiche l'élément rouage
void rouage(const Select select, const float x, const float y, const float r);
//Affiche le plateau
void plateau(const float teinte);
//Affiche un plus (+)
void plus(const float xBasGauche, const float yBasGauche, const float xHautDroite, const float yHautDroite);
//Affiche un coeur
void coeur(const float x, const float y, const float r);
//Affiche le menu pause
void affichePause(const Select *const select);
//Affiche la zone de texte
void zoneText(const Select *const select, const char chaine[]);
//Affiche l'élément raquette
void raquette(const Raquette raquette, const int teinte);
//Affiche l'élément balle
void balle(const Balle balleJeu, const int teinte);
//Affiche l'élément les digit selon le score
void score(const int score, const float x, const float y);

//Affiche le timer (type int)
void timer(const int temps[], const float x, const float y);
//Affiche un digit (type Digit)
void afficheDigit(const Digit digit, const float x, const float y);
//Affiche tout les Users
void afficheUsers(const Select *const select, const Users *const maUsers, const int teinte);

//Sous traitance mutateur
void AfficheMutateur(Data *const data);