#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include "./GfxLib/GfxLib.h"
#include "./GfxLib/BmpLib.h"
#include "./GfxLib/ESLib.h" 

#define LargeurFenetre 800
#define HauteurFenetre 600

typedef struct informations
{
	char Nom[12];
	char Prenom[12];
	int Memoire[3];
	int Rapidite[3];
	int Lateralite[3];
}info;

void cercle(float centreX, float centreY, float rayon);

void gestionEvenement(EvenementGfx evenement);
void chargement(char read[250], info Users[4], int *ptlang);
void sauvegarde(FILE *save, info Users[4], int *ptlang);
void ecrire(char text[12]);
void pagededemarrage();
void pagedinscription();
void pagedeconnection();
void pagedacceuil();
void memoire();
void test1memoire(int jeu[20], int *ptj, int *pth, int *pta, int *ptb, int *ptn, int *ptt);
void test2memoire(int jeu[20], int *ptj, int *pte, int *pta, int *ptb, int *ptn, int *ptt);
int verifie(int jeu[20],int *pth, int bouton);
void rapidite();
void test1Rapidite(int *ptx, int *pty, int *pte, int *ptbr, int *pth, int *ptt);
void test2Rapidite(char *ptl, int *pte, int *ptbr, int *pth, int *ptt);
void lateralite();
void test1Lateralite(int *ptjeu, int *pte, int *ptbr, int *pth, int *ptt);
void test2lateralite(info Users[4], int i, int *ptt, int *pte,int *ptbr,int *ptlang);




void resultatspe();
void resultat();
