#include "../lib.h"
#include "../Moteur/moteur.h"
#include "../Elements/elements.h"

//Ensemble des fonctions d'affichage
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

//Ensemble des fonctions de clavier
//Gestion Clavier page Select
void ClavierSelection(Data *const data);
//Gestion Clavier page Jeu
void ClavierJeu(Data *const data);
//Gestion Clavier page Entrainement
void ClavierEntrainement(Data *const data);

//Ensemble des fonctions de clic
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

//Ensemble des fonctions de temporisation
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

//Ensemble des fonctions de redimensionnement
//Gestion Redimensionnement
void Redim(Data *const data);
//Redimensionnement de la balle
void redimBalle(Balle *const balle);
//Redimensionnement de la raquette
void redimRaquette(Raquette *const raquette, const int i);