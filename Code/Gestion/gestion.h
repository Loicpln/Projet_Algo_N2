#include "../lib.h"
#include "../Moteur/moteur.h"
#include "../Elements/elements.h"

//Gestion Affichage page d'Accueil
void AfficheAccueil(Data *const data);
//Gestion Affichage page Menu
void AfficheMenu(Data *const data);
//Gestion Affichage page Règles
void AfficheRegles(Data *const data);
//Gestion Affichage page Selection
void AfficheSelection(Data *const data);
//Gestion Affichage page Jeu
void AfficheJeu(Data *const data);
//Gestion Affichage page Entrainement
void AfficheEntrainement(Data *const data);
//Gestion Affichage page de Resultats
void AfficheResultats(Data *const data);
//Sous traitance mutateur
void AfficheMutateur(Data *const data);

//Gestion Clavier page Select
void ClavierSelect(Data *const data);
//Gestion Clavier page Jeu
void ClavierJeu(Data *const data);
//Gestion Clavier page Entrainement
void ClavierEntrainement(Data *const data);

//Gestion Clic page d'Accueil
void ClicAccueil(Data *const data);
//Gestion Clic page Menu
void ClicMenu(Data *const data);
//Gestion Clic page Règles
void ClicRegles(Data *const data);
//Gestion Clic page Selection
void ClicSelection(Data *const data);
//Gestion Clic page Jeu
void ClicJeu(Data *const data);
//Gestion Clic page Resultats
void ClicResultats(Data *const data);

//Sous traitance 
//mutateur
void ClicMutateur(Data *const data);
//taille raquette
int clicTailleRaq();

//Gestion Tempo page d'Accueil
void TempoAccueil(Data *const data);
//Gestion Tempo page Menu
void TempoMenu(Data *const data);
//Gestion Tempo page Règles
void TempoRegles(Data *const data);
//Gestion Tempo page Selection
void TempoSelection(Data *const data);
//Gestion Tempo page Jeu
void TempoJeu(Data *const data);
//Gestion Tempo page Entrainement
void TempoEntrainement(Data *const data);
//Gestion Tempo page Resultats
void TempoResultats(Data *const data);

//Gestion Redim page d'Accueil
void Redim(Data *const data);
void redimBalle(Balle *const balle);
void redimRaquette(Raquette *const raquette, const int i);