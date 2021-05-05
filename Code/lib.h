#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "./GfxLib/GfxLib.h"
#include "./GfxLib/BmpLib.h"
#include "./GfxLib/ESLib.h"
//#include <Fmod/fmod.h>
//#include <SDL/SDL.h>
//#include <SDL/SDL_mixer.h>

// Taille de la fenêtre
#define LargeurFenetre 800
#define HauteurFenetre 600
#define RafraichissementFenetre 20

// Unitée (Hauteur et Largeur)
#define Ux largeurFenetre() / 100
#define Uy hauteurFenetre() / 100

// Gestion de l'interface de jeu
#define MAX_X 100 * Ux
#define MAX_Y 100 * Uy
#define MID_X 50 * Ux
#define MID_Y 50 * Uy
#define MIN_X_PLATEAU 3 * Ux
#define MAX_X_PLATEAU 97 * Ux
#define MIN_Y_PLATEAU 3 * Uy
#define MAX_Y_PLATEAU 82 * Uy

// Permet de realiser un encadrement direct dans un 'if'
#define X_BALLE balle->x + cosf(i) * balle->r && balle->x + cosf(i) * balle->r
#define Y_BALLE balle->y + sinf(i) * balle->r && balle->y + sinf(i) * balle->r
#define X_SOURIS abscisseSouris() && abscisseSouris()
#define Y_SOURIS ordonneeSouris() && ordonneeSouris()

// Raccourcis pour la couleur et le trait
#define CC_BLANC couleurCourante(255, 255, 255)
#define CC_NOIR couleurCourante(0, 0, 0)
#define EPAISSEUR_1 epaisseurDeTrait(1)
#define EPAISSEUR_2 epaisseurDeTrait(2)
#define EPAISSEUR_3 epaisseurDeTrait(3)
#define EPAISSEUR_TITRE epaisseurDeTrait(8)

#define r_Rouage 3 * Ux

// Raquettes
#define LARG_RAQUETTE Ux
#define LONG_RAQUETTE 17 * Uy
#define V_RAQUETTE 3 * Uy
#define X_RAQUETTE_LEFT MIN_X_PLATEAU + 2 * Ux
#define X_RAQUETTE_RIGHT MAX_X_PLATEAU - 2 * Ux

// Definition de gauche et de droite
#define Gauche false
#define Droite true

#define V_ACCEUIL rand() % 2 ? 5.f : -5.f
#define V_BALLE rand() % 2 ? 10.f : -10.f
#define VH_BALLE 0.00001
#define R_ACCEUIL 10
#define R_BALLE 20
#define NB_BALLE 50

#define NB_JOUEUR 2
#define NB_USERS 10

#define NB_SELECT 50
#define L_SELECT_OFF 1
#define L_SELECT_ON 5

// Outil d'affichage d'une grille pour faciliter les mesures
#define GRILLE                               \
    for (int i = 1; i < 100; i++)            \
    {                                        \
        char a[10] = "";                     \
        CC_BLANC;                            \
        EPAISSEUR_1;                         \
        sprintf(a, "%d", i);                 \
        afficheChaine(a, 5, i *Ux, Uy / 2);  \
        afficheChaine(a, 5, Ux / 2, i * Uy); \
        ligne(i *Ux, 0, i *Ux, 100 * Uy);    \
        ligne(0, i *Uy, 100 * Ux, i * Uy);   \
    }

// Méthode de l'affichage d'un digit (true ou false si le segment doit être affiché)
#define DIGIT_0 \
    (Digit) { true, true, true, false, true, true, true }
#define DIGIT_1 \
    (Digit) { false, false, true, false, false, true, false }
#define DIGIT_2 \
    (Digit) { true, false, true, true, true, false, true }
#define DIGIT_3 \
    (Digit) { true, false, true, true, false, true, true }
#define DIGIT_4 \
    (Digit) { false, true, true, true, false, true, false }
#define DIGIT_5 \
    (Digit) { true, true, false, true, false, true, true }
#define DIGIT_6 \
    (Digit) { true, true, false, true, true, true, true }
#define DIGIT_7 \
    (Digit) { true, false, true, false, false, true, false }
#define DIGIT_8 \
    (Digit) { true, true, true, true, true, true, true }
#define DIGIT_9 \
    (Digit) { true, true, true, true, false, true, true }
#define DIGIT_ERROR \
    (Digit) { true, true, false, true, true, false, true }

// Modes de jeu
#define ContreLaMontre 0
#define BattleRoyal 1

// Tableau pour le temps
#define Deux_Min \
    {            \
        2, 0     \
    }
#define NBVIES 5     // Nombre de vie par défaut
#define id_IA 20     // id de l'IA par défaut
#define id_Rouage 45 // id du rouage par défaut

// Definition de numero pour les pages
#define Acceuil 1
#define Regles 2
#define Menu 3
#define Selection 4
#define Jeu 5
#define Entrainement 6
#define Resultats 7

// sous-traitance
#define absBar1 10 * Ux
#define absBar2 58 * Ux

#ifndef STRUCT
#define STRUCT

// Contient chaques segments du Digit
typedef struct
{
    bool haut;
    bool hautGauche;
    bool hautDroite;
    bool milieu;
    bool basGauche;
    bool basDroite;
    bool bas;
} Digit;

// Contient chaques elements pour dessiner et gérer une balle
typedef struct
{
    float x;
    float y;
    float r;
    float vx;
    float vy;
    float v0;
} Balle;

// Contient chaques elements pour dessiner et gérer une raquette
typedef struct
{
    float longueur;
    float largeur;
    float x;
    float y;
    float vy;
    char up;
    char down;
} Raquette;

// Contient chaques elements pour sauvegarder les données d'un utilisateur
typedef struct User User;
struct User
{
    int id;
    char pseudo[15];
    int nbGame;
    int nbWin;
    int nbLose;
    User *userSuivant;
};

// Contient la racine de la liste
typedef struct
{
    User *premier;
} Users;

// Contient les éléments pour gérer un 'hover' et la couleur des bordures
typedef struct
{
    int largeur;
    int couleur[3];
} Select;

// Contient chaques elements pour gérer l'état de la page actuelle
typedef struct
{
    int numero;
    int pause;
    Select select[NB_SELECT];
} Page;

// Contient chaques joueurs (son Score, le User séléctionné, et sa Raquette)
typedef struct
{
    int score;
    User *user;
    Raquette raquette;
} Joueur;

// Contient chaques elements des Options de jeu
typedef struct
{
    int mode;
    int temps[2];
    int nbButs;
    float v0;
    float r;
    int raquette;
} Options;

// Contient chaques elements racine (Réutilisable dans toute l'application | Structure Global)
typedef struct
{
    Page page;
    Balle balle[NB_BALLE];
    Balle balleJeu;
    Joueur joueurs[NB_JOUEUR];
    Users *users;
    Options option;
    int timer[2];
    char newPseudo[15];
} Data;
#endif