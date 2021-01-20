#include "./lib.h"

typedef struct {
    void(*f1)(Data*);
    void(*f2)(Data*);
    void(*f3)(Data*);
}Gestion;

void gestion(Data *data, Gestion gestion);

Gestion fTempo();
Gestion fAffiche();
Gestion fClavier();
Gestion fClick();


void TempoAccueil(Data *data);
void TempoJeu(Data *data);
void TempoRegles(Data *data);


void AfficheAccueil(Data *data);
void AfficheJeu(Data *data);
void AfficheRegles(Data *data);


void ClicAccueil(Data *data);
void ClicJeu(Data *data);
void ClicRegles(Data *data);