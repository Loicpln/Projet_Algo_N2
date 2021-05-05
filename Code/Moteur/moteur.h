#include "../lib.h"

//Ensemble des fonctions d'initialisation
//Initialisation des data
Data init();
//Initialisation des balles de l'acceuil
Balle initBallesAccueil();
//Initialisation de la raquette de gauche
Raquette initRaquetteG(int longeur);
//Initialisation de la raquette de droite
Raquette initRaquetteD(int longeur);
//Initialisation de balle de jeu
Balle initBalleJeu();
//Initialisation des Users depuis un fichier txt
Users *chargeUsersDepuisFichier();
//Initialisation des Options
Options initOptions();
//Initialisation du score
int initScore();

//Ensemble des fonctions de reset
//Reinitialisation des Select
void resetSelect(Select *const select);
//Reinitialisation des Users
void resetUsers(Joueur *const joueur);
//Reinitialisation des Raquettes
void resetRaquette(Joueur *const joueur, const Options options);
//Reinitialisation des Scores
void resetScore(Joueur *const joueur);
//Reinitialisation des Timer
void resetTimer(int *const timer, const Options options);
//Reinitialisation de la Balle
void resetBalle(Balle *const balle, const Options options);

//Ensemble des fonctions de select
//Select du Bouton
void selectBouton(Select *const select, const int x1, const int x2, const int y1, const int y2);
//Select du Rouage
void selectRouage(Select *const select, const int x, const int y, const int r);
//Select de la Pause
void selectPause(Select *const select);
//Select des Users
void selectUsers(Select *const select);
//Select du Mutateur
void selectMutateur(Select *const select, const Options option);

//Ensemble des fonctions de clic
//Clic pour le rouage
void clicRouage(Page *const page, const int x, const int y, const int r);
//Clic pour la pause
void clicPause(Data *const data);
//Clic pour les Users
void clicUsers(Joueur *const joueur, const Joueur autre, Users *const users);
//Clic pour la suppression des Users
void clicSupprUsers(Joueur *const joueur, Users *users);
//Clic pour l'ajout des Users
void clicAddUsers(Page *const page);

//Ensemble des fonctions qui gèrent les Users
//Cree un element User
User *creeUser(const int id, const char *const pseudo, const int nbGame, const int nbWin, const int nbLose);
//Ajoute à la liste Users un element User
Users *ajouteUsers(Users *users, User *const nouv);
//Supprime un element User dans la liste Users selon l'id
Users *supprimeDansUsers(Users *users, const int id);
//Reajuste les id de la liste [0,1,2,4,5,7]->[0,1,2,3,4,5]
Users *changeId(Users *users);
//Recherche un element User selon id
User *rechercheUser(Users *users, const int id);
//Compte le nombre d'utilisateur dans la liste
int compteUsers(Users *users);
//Enregistre la liste dans un fichier txt
void enregistreUsersFichier(Users *users);

//Ensemble des fonctions de calcul
//Change la couleur du select selon R V B
void couleurSelect(Select *const select, const int R, const int V, const int B);
//Fait bouger x et y de la balle selon vx et vy
void mouvementBalle(Balle *const balle);
//Gère le rebond de la balle
void rebond(Balle *const balle, const float min_x, const float min_y, const float max_x, const float max_y);
//Accelere la vitesse de la balle
void accelereBalle(Balle *const balle, const float facteur);
//Si la touche 'g' et appuyée la pause se déclanche
void touchePause(Page *const page);
//Ecrit dans text les caractères tapés
void ecrire(char *text);
//Gère les touches pour le deplacement de la raquette
void touches(Raquette *const raquette);
//Si la touche pour up est séléctionne la raquette monte
void up(Raquette *const raquette);
//Si la touche pour down est séléctionne la raquette descend
void down(Raquette *const raquette);
//Change un nombre 'int' en 'Digit'
Digit nombre(const int score);
//Recupère le signe de la variable
int signe(const float val);
//Gère la hitbox entre la balle et la raquette
void hitbox(Balle *const balle, const Raquette *const raquette);
//Gère si il y a un but selon le joueur
void but(Balle *const balle, Joueur *const joueur);
//Gère l'évènement de jeu
void jeu(Data *const data);
//Fait le décompte chaque seconde du temps
void decompte(int *temps);
//Gère les calculs de l'IA pour déplacer la raquette
void IA(Raquette *const raquette, const Balle *const balle, const bool side);

//Sous traitance
//mutateur
void ClicMutateur(Data *const data);
//taille raquette
float modifTriangle1(float triangle);
float modifTriangle2(float triangle);