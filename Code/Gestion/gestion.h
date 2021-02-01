#include "../lib.h"
#include "../Moteur/moteur.h"

void AfficheAccueil(Data *data);
void AfficheMenu(Data *data);
void AfficheJeu(Data *data);
void AfficheRegles(Data *data);

void plateau();
void raquette(Raquette raquette);
void balle(Balle *balleJeu);
void score(int score, bool side);
void afficheDigit(bool digit[], bool side, int i);

void ClavierAccueil(Data *data);
void ClavierMenu(Data *data);
void ClavierJeu(Data *data);
void ClavierRegles(Data *data);

void ClicAccueil(Data *data);
void ClicMenu(Data *data);
void ClicJeu(Data *data);
void ClicRegles(Data *data);

void TempoAccueil(Data *data);
void TempoMenu(Data *data);
void TempoJeu(Data *data);
void TempoRegles(Data *data);

void RedimAccueil(Data *data);
void RedimMenu(Data *data);
void RedimJeu(Data *data);
void RedimRegles(Data *data);
