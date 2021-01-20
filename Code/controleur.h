#include "./lib.h"

typedef struct
{
    void (*f1)(Data *);
    void (*f2)(Data *);
    void (*f3)(Data *);
    void (*f4)(Data *);
    void (*f5)(Data *);
    void (*f6)(Data *);

} Gestion;

void gestion(Data *data, Gestion gestion);

Gestion fTempo();
Gestion fAffiche();
Gestion fClavier();
Gestion fClic();
Gestion fRedim();

void init(Data *data);

void TempoAccueil(Data *data);
void TempoMenu(Data *data);
void TempoJeu(Data *data);
void TempoRegles(Data *data);

void AfficheAccueil(Data *data);
void AfficheMenu(Data *data);
void AfficheJeu(Data *data);
void AfficheRegles(Data *data);
void Plateau (Data *data);

void ClavierAccueil(Data *data);
void ClavierMenu(Data *data);
void ClavierJeu(Data *data);
void ClavierRegles(Data *data);

void ClicAccueil(Data *data);
void ClicMenu(Data *data);
void ClicJeu(Data *data);
void ClicRegles(Data *data);

void RedimAccueil(Data *data);
void RedimMenu(Data *data);
void RedimJeu(Data *data);
void RedimRegles(Data *data);
