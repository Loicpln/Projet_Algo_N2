#include "../lib.h"
#include "../Moteur/moteur.h"

void AfficheAccueil(Data *data);
void AfficheMenu(Data *data);
void AfficheRegles(Data *data);
void AfficheJeu(Data *data);
void AfficheJeuIA(Data *data);
void AfficheEntrainement(Data *data);

void plateau(int teinte);
void affichePause(int *select);
void selectPause(int *select);
void raquette(Raquette raquette, int teinte);
void balle(Balle *balleJeu, int teinte);
void score(int score, bool side, int teinte);
void afficheDigit(bool *digit, bool side, int i, int teinte);

void ClavierAccueil(Data *data);
void ClavierMenu(Data *data);
void ClavierRegles(Data *data);
void ClavierJeu(Data *data);
void ClavierJeuIA(Data *data);
void ClavierEntrainement(Data * data);

void ClicAccueil(Data *data);
void ClicMenu(Data *data);
void ClicRegles(Data *data);
void ClicJeu(Data *data);
void ClicJeuIA(Data *data);
void ClicEntrainement(Data *data);

void TempoAccueil(Data *data);
void TempoMenu(Data *data);
void TempoRegles(Data *data);
void TempoJeu(Data *data);
void TempoJeuIA(Data *data);
void TempoEntrainement(Data *data);

void RedimAccueil(Data *data);
void RedimMenu(Data *data);
void RedimRegles(Data *data);
void RedimJeu(Data *data);
void RedimJeuIA(Data *data);
void RedimEntrainement(Data *data);
