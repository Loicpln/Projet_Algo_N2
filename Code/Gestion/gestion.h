#include "../lib.h"
#include "../Moteur/moteur.h"
#include "../Elements/elements.h"

//Gestion Affichage page d'Accueil
void AfficheAccueil(Data * const data);
//Gestion Affichage page Menu
void AfficheMenu(Data * const data);
//Gestion Affichage page Règles
void AfficheRegles(Data * const data);
//Gestion Affichage page Selection
void AfficheSelection(Data *const data);
//Gestion Affichage page Jeu 
void AfficheJeu(Data * const data);
//Gestion Affichage page d'Entrainement
void AfficheEntrainement(Data * const data);

//Gestion Clavier page Jeu 1 joueurs
void ClavierJeu1J(Data * const data);
//Gestion Clavier page Jeu 2 joueurs
void ClavierJeu2J(Data * const data);

//Gestion Clic page d'Accueil
void ClicAccueil(Data * const data);
//Gestion Clic page Menu
void ClicMenu(Data * const data);
//Gestion Clic page Règles
void ClicRegles(Data * const data);
//Gestion Clic page Selection
void ClicSelection(Data * const data);
//Gestion Clic page Jeu
void ClicJeu(Data * const data);
//Gestion Clic page Selection vs IA
void ClicSelectionIA(Data * const data);
//Gestion Clic page d'Entrainement
void ClicEntrainement(Data * const data);

//Gestion Tempo page d'Accueil
void TempoAccueil(Data * const data);
//Gestion Tempo page Menu
void TempoMenu(Data * const data);
//Gestion Tempo page Règles
void TempoRegles(Data * const data);
//Gestion Tempo page Selection
void TempoSelection(Data * const data);
//Gestion Tempo page Jeu 1v1
void TempoJeu(Data * const data);
//Gestion Tempo page Jeu 1vIA
void TempoJeuIA(Data * const data);
//Gestion Tempo page d'Entrainement
void TempoEntrainement(Data * const data);