#include "fonction.h"

void cercle(float centreX, float centreY, float rayon)
{
	const int Pas = 20; // Nombre de secteurs pour tracer le cercle
	const double PasAngulaire = 2. * M_PI / Pas;
	int index;

	for (index = 0; index < Pas; ++index) // Pour chaque secteur
	{
		const double angle = 2. * M_PI * index / Pas; // on calcule l'angle de depart du secteur
		triangle(centreX, centreY,
				 centreX + rayon * cos(angle), centreY + rayon * sin(angle),
				 centreX + rayon * cos(angle + PasAngulaire), centreY + rayon * sin(angle + PasAngulaire));
		// On trace le secteur a l'aide d'un triangle => approximation d'un cercle
	}
}

void chargement(char read[250], info Users[4], int *ptlang)
{
	strcpy(Users[0].Nom, strtok(read, "|"));
	strcpy(Users[0].Prenom, strtok(NULL, "|"));
	for (int i = 0; i < 3; i++)
	{
		Users[0].Memoire[i] = (int)strtol(strtok(NULL, "|"), NULL, 10);
		Users[0].Rapidite[i] = (int)strtol(strtok(NULL, "|"), NULL, 10);
		Users[0].Lateralite[i] = (int)strtol(strtok(NULL, "|"), NULL, 10);
	}
	for (int i = 1; i < 4; i++)
	{
		strcpy(Users[i].Nom, strtok(NULL, "|"));
		strcpy(Users[i].Prenom, strtok(NULL, "|"));
		for (int j = 0; j < 3; j++)
		{
			Users[i].Memoire[j] = (int)strtol(strtok(NULL, "|"), NULL, 10);
			Users[i].Rapidite[j] = (int)strtol(strtok(NULL, "|"), NULL, 10);
			Users[i].Lateralite[j] = (int)strtol(strtok(NULL, "|"), NULL, 10);
		}
	}
	*ptlang = (int)strtol(strtok(NULL, "|"), NULL, 10);
}

void sauvegarde(FILE *save, info Users[4], int *ptlang)
{
	for (int i = 0; i < 4; i++)
	{
		fprintf(save, "%s|%s|", Users[i].Nom, Users[i].Prenom);
		for (int j = 0; j < 3; j++)
			fprintf(save, "%d|%d|%d|", Users[i].Memoire[j], Users[i].Rapidite[j], Users[i].Lateralite[j]);
	}
	fprintf(save, "%d|", *ptlang);
	fclose(save);
}

void ecrire(char text[12])
{
	char a[12] = "";
	if ((caractereClavier() == 8) && (strcmp(text, "") != 0))
	{
		strncpy(a, text, strlen(text) - 1);
		strcat(a, "\0");
		strcpy(text, a);
	}
	else
	{
		for (int i = 0; i < 11; i++)
		{
			if (text[i] == '\0')
			{
				text[i] = caractereClavier();
				text[i + 1] = '\0';
				break;
			}
		}
	}
}

void pagededemarrage()
{
	couleurCourante(0, 0, 0);
	rectangle(0, 0, largeurFenetre() / 9 + 10, hauteurFenetre());
	rectangle(2 * largeurFenetre() / 9, 5 * hauteurFenetre() / 9, 7 * largeurFenetre() / 9, 6 * hauteurFenetre() / 9);
	rectangle(2 * largeurFenetre() / 9, 3 * hauteurFenetre() / 9, 7 * largeurFenetre() / 9, 4 * hauteurFenetre() / 9);
	couleurCourante(255, 255, 255);
	rectangle(1, 1, largeurFenetre() / 9 + 9, hauteurFenetre() - 1);
	rectangle(2 * largeurFenetre() / 9 + 1, 5 * hauteurFenetre() / 9 + 1, 7 * largeurFenetre() / 9 - 1, 6 * hauteurFenetre() / 9 - 1);
	rectangle(2 * largeurFenetre() / 9 + 1, 3 * hauteurFenetre() / 9 + 1, 7 * largeurFenetre() / 9 - 1, 4 * hauteurFenetre() / 9 - 1);
	couleurCourante(0, 0, 0);
}

void pagedinscription()
{
	couleurCourante(0, 0, 0);
	rectangle(0, 0, largeurFenetre() / 9, hauteurFenetre() / 18);
	rectangle(3 * largeurFenetre() / 9, 5 * hauteurFenetre() / 9, 6 * largeurFenetre() / 9, 6 * hauteurFenetre() / 9);
	rectangle(3 * largeurFenetre() / 9, 3 * hauteurFenetre() / 9, 6 * largeurFenetre() / 9, 4 * hauteurFenetre() / 9);
	rectangle(4 * largeurFenetre() / 9, hauteurFenetre() / 9, 5 * largeurFenetre() / 9, 2 * hauteurFenetre() / 9);
	couleurCourante(255, 255, 255);
	rectangle(1, 1, largeurFenetre() / 9 - 1, hauteurFenetre() / 18 - 1);
	rectangle(3 * largeurFenetre() / 9 + 1, 5 * hauteurFenetre() / 9 + 1, 6 * largeurFenetre() / 9 - 1, 6 * hauteurFenetre() / 9 - 1);
	rectangle(3 * largeurFenetre() / 9 + 1, 3 * hauteurFenetre() / 9 + 1, 6 * largeurFenetre() / 9 - 1, 4 * hauteurFenetre() / 9 - 1);
	rectangle(4 * largeurFenetre() / 9 + 1, hauteurFenetre() / 9 + 1, 5 * largeurFenetre() / 9 - 1, 2 * hauteurFenetre() / 9 - 1);
	couleurCourante(0, 0, 0);
}

void pagedeconnection()
{
	couleurCourante(255, 0, 0);
	for (int i = 0; i < 4; i++)
	{
		ligne(2 * largeurFenetre() / 18, 7 * hauteurFenetre() / 9 - i * 2 * hauteurFenetre() / 9, 3 * largeurFenetre() / 18, 8 * hauteurFenetre() / 9 - i * 2 * hauteurFenetre() / 9);
		ligne(2 * largeurFenetre() / 18, 8 * hauteurFenetre() / 9 - i * 2 * hauteurFenetre() / 9, 3 * largeurFenetre() / 18, 7 * hauteurFenetre() / 9 - i * 2 * hauteurFenetre() / 9);
	}
	couleurCourante(0, 255, 0);
	for (int i = 0; i < 4; i++)
	{
		ligne(15 * largeurFenetre() / 18, 15 * hauteurFenetre() / 18 - i * 2 * hauteurFenetre() / 9, 31 * largeurFenetre() / 36, 7 * hauteurFenetre() / 9 - i * 2 * hauteurFenetre() / 9);
		ligne(31 * largeurFenetre() / 36, 7 * hauteurFenetre() / 9 - i * 2 * hauteurFenetre() / 9, 16 * largeurFenetre() / 18, 8 * hauteurFenetre() / 9 - i * 2 * hauteurFenetre() / 9);
	}
	couleurCourante(0, 0, 0);
	rectangle(0, 0, largeurFenetre() / 9, hauteurFenetre() / 18);
	for (int i = 0; i < 4; i++)
		rectangle(2 * largeurFenetre() / 9, 7 * hauteurFenetre() / 9 - i * 2 * hauteurFenetre() / 9, 7 * largeurFenetre() / 9, 8 * hauteurFenetre() / 9 - i * 2 * hauteurFenetre() / 9);
	couleurCourante(255, 255, 255);
	rectangle(1, 1, largeurFenetre() / 9 - 1, hauteurFenetre() / 18 - 1);
	for (int i = 0; i < 4; i++)
		rectangle(2 * largeurFenetre() / 9 + 1, 7 * hauteurFenetre() / 9 - i * 2 * hauteurFenetre() / 9 + 1, 7 * largeurFenetre() / 9 - 1, 8 * hauteurFenetre() / 9 - i * 2 * hauteurFenetre() / 9 - 1);
	couleurCourante(0, 0, 0);
}

void pagedacceuil()
{
	couleurCourante(0, 0, 0);
	rectangle(0, 0, largeurFenetre() / 9, hauteurFenetre() / 18);
	rectangle(8 * largeurFenetre() / 9, 17 * hauteurFenetre() / 18, largeurFenetre(), hauteurFenetre());
	rectangle(largeurFenetre() / 10, 4 * hauteurFenetre() / 10, 3 * largeurFenetre() / 10, 6 * hauteurFenetre() / 10);
	rectangle(4 * largeurFenetre() / 10, 4 * hauteurFenetre() / 10, 6 * largeurFenetre() / 10, 6 * hauteurFenetre() / 10);
	rectangle(7 * largeurFenetre() / 10, 4 * hauteurFenetre() / 10, 9 * largeurFenetre() / 10, 6 * hauteurFenetre() / 10);
	couleurCourante(255, 255, 255);
	rectangle(1, 1, largeurFenetre() / 9 - 1, hauteurFenetre() / 18 - 1);
	rectangle(8 * largeurFenetre() / 9 + 1, 17 * hauteurFenetre() / 18 + 1, largeurFenetre() - 1, hauteurFenetre() - 1);
	rectangle(largeurFenetre() / 10 + 1, 4 * hauteurFenetre() / 10 + 1, 3 * largeurFenetre() / 10 - 1, 6 * hauteurFenetre() / 10 - 1);
	rectangle(4 * largeurFenetre() / 10 + 1, 4 * hauteurFenetre() / 10 + 1, 6 * largeurFenetre() / 10 - 1, 6 * hauteurFenetre() / 10 - 1);
	rectangle(7 * largeurFenetre() / 10 + 1, 4 * hauteurFenetre() / 10 + 1, 9 * largeurFenetre() / 10 - 1, 6 * hauteurFenetre() / 10 - 1);
	couleurCourante(0, 0, 0);
}

void memoire()
{
	couleurCourante(0, 0, 0);
	rectangle(0, 0, largeurFenetre() / 9, hauteurFenetre() / 18);
	rectangle(8 * largeurFenetre() / 9, 17 * hauteurFenetre() / 18, largeurFenetre(), hauteurFenetre());
	rectangle(2 * largeurFenetre() / 10, 4 * hauteurFenetre() / 10, 4 * largeurFenetre() / 10, 6 * hauteurFenetre() / 10);
	rectangle(6 * largeurFenetre() / 10, 4 * hauteurFenetre() / 10, 8 * largeurFenetre() / 10, 6 * hauteurFenetre() / 10);
	couleurCourante(255, 255, 255);
	rectangle(1, 1, largeurFenetre() / 9 - 1, hauteurFenetre() / 18 - 1);
	rectangle(8 * largeurFenetre() / 9 + 1, 17 * hauteurFenetre() / 18 + 1, largeurFenetre() - 1, hauteurFenetre() - 1);
	rectangle(2 * largeurFenetre() / 10 + 1, 4 * hauteurFenetre() / 10 + 1, 4 * largeurFenetre() / 10 - 1, 6 * hauteurFenetre() / 10 - 1);
	rectangle(6 * largeurFenetre() / 10 + 1, 4 * hauteurFenetre() / 10 + 1, 8 * largeurFenetre() / 10 - 1, 6 * hauteurFenetre() / 10 - 1);
	couleurCourante(0, 0, 0);
}

void test1memoire(int jeu[20], int *ptj, int *pth, int *pta, int *ptb, int *ptn, int *ptt)
{
	int res;
	char text[10] = "";
	srand(time(NULL));
	if (*ptt < -10)
	{
		*ptt = *ptt + 1;
		sprintf(text, "%d", -(*ptt) / 50 + 1);
		couleurCourante(0, 0, 0);
		afficheChaine(text, 80, 37 * largeurFenetre() / 80, hauteurFenetre() / 10);
	}
	else
		*ptt = *ptt + 1;
	couleurCourante(0, 0, 255);
	cercle(4 * largeurFenetre() / 10, 13 * hauteurFenetre() / 20, hauteurFenetre() / 10);
	couleurCourante(0, 255, 0);
	cercle(6 * largeurFenetre() / 10, 13 * hauteurFenetre() / 20, hauteurFenetre() / 10);
	couleurCourante(255, 0, 0);
	cercle(4 * largeurFenetre() / 10, 7 * hauteurFenetre() / 20, hauteurFenetre() / 10);
	couleurCourante(255, 255, 0);
	cercle(6 * largeurFenetre() / 10, 7 * hauteurFenetre() / 20, hauteurFenetre() / 10);
	if (*ptt > -1)
	{
		if (*ptj == -1)
			for (int i = 0; i < 20; i++)
				jeu[i] = (rand() % 4) + 1;
		if (*ptj < *ptn && (*pta) % 2 == 0)
		{
			demandeTemporisation(200);
			if (jeu[*ptj] == 1)
			{
				couleurCourante(115, 194, 251);
				cercle(4 * largeurFenetre() / 10, 13 * hauteurFenetre() / 20, hauteurFenetre() / 10 - 10);
			}
			else if (jeu[*ptj] == 2)
			{
				couleurCourante(176, 242, 182);
				cercle(6 * largeurFenetre() / 10, 13 * hauteurFenetre() / 20, hauteurFenetre() / 10 - 10);
			}
			else if (jeu[*ptj] == 3)
			{
				couleurCourante(254, 150, 160);
				cercle(4 * largeurFenetre() / 10, 7 * hauteurFenetre() / 20, hauteurFenetre() / 10 - 10);
			}
			else if (jeu[*ptj] == 4)
			{
				couleurCourante(255, 240, 188);
				cercle(6 * largeurFenetre() / 10, 7 * hauteurFenetre() / 20, hauteurFenetre() / 10 - 10);
			}
			*ptj = *ptj + 1;
		}
		*pta = *pta + 1;
		if (*ptb == 1)
		{
			couleurCourante(115, 194, 251);
			cercle(4 * largeurFenetre() / 10, 13 * hauteurFenetre() / 20, hauteurFenetre() / 10 - 10);
			res = verifie(jeu, pth, 1);
			if (res == 0 && *pth == *ptn)
			{
				*ptj = 0;
				*pth = 0;
				*ptn = *ptn + 1;
				*ptt = -5;
			}
			*ptb = 0;
			if (res == 1 || *ptn == 21)
				*ptb = 5;
		}
		if (*ptb == 2)
		{
			couleurCourante(176, 242, 182);
			cercle(6 * largeurFenetre() / 10, 13 * hauteurFenetre() / 20, hauteurFenetre() / 10 - 10);
			res = verifie(jeu, pth, 2);
			if (res == 0 && *pth == *ptn)
			{
				*ptj = 0;
				*pth = 0;
				*ptn = *ptn + 1;
				*ptt = -5;
			}
			*ptb = 0;
			if (res == 1 || *ptn == 21)
				*ptb = 5;
		}
		if (*ptb == 3)
		{
			couleurCourante(254, 150, 160);
			cercle(4 * largeurFenetre() / 10, 7 * hauteurFenetre() / 20, hauteurFenetre() / 10 - 10);
			res = verifie(jeu, pth, 3);
			if (res == 0 && *pth == *ptn)
			{
				*ptj = 0;
				*pth = 0;
				*ptn = *ptn + 1;
				*ptt = -5;
			}
			*ptb = 0;
			if (res == 1 || *ptn == 21)
				*ptb = 5;
		}
		if (*ptb == 4)
		{
			couleurCourante(255, 240, 188);
			cercle(6 * largeurFenetre() / 10, 7 * hauteurFenetre() / 20, hauteurFenetre() / 10 - 10);
			res = verifie(jeu, pth, 4);
			if (res == 0 && *pth == *ptn)
			{
				*ptj = 0;
				*pth = 0;
				*ptn = *ptn + 1;
				*ptt = -5;
			}
			*ptb = 0;
			if (res == 1 || *ptn == 21)
				*ptb = 5;
		}
	}
}
void test2memoire(int jeu[20], int *ptj, int *pte, int *pta, int *ptb, int *ptn, int *ptt)
{
	char text[10] = "";
	int c = 0;
	int l = 0;
	static int ver[20];
	int verif = 1;
	srand(time(NULL));
	if (*ptt < -10)
	{
		*ptt = *ptt + 1;
		sprintf(text, "%d", -(*ptt) / 50 + 1);
		couleurCourante(0, 0, 0);
		afficheChaine(text, 80, 37 * largeurFenetre() / 80, hauteurFenetre() / 10);
	}
	else if (*ptt < 0)
	{
		*ptt = *ptt + 1;
		couleurCourante(0, 0, 0);
		afficheChaine("Go", 80, 9 * largeurFenetre() / 20, hauteurFenetre() / 10);
	}
	else
		*ptt = *ptt + 1;

	if (*ptt > -1)
	{
		demandeTemporisation(500);
		couleurCourante(200, 200, 200);
		rectangle(largeurFenetre() / 11, hauteurFenetre() / 9, 2 * largeurFenetre() / 11, 2 * hauteurFenetre() / 9);
		rectangle(3 * largeurFenetre() / 11, hauteurFenetre() / 9, 4 * largeurFenetre() / 11, 2 * hauteurFenetre() / 9);
		rectangle(5 * largeurFenetre() / 11, hauteurFenetre() / 9, 6 * largeurFenetre() / 11, 2 * hauteurFenetre() / 9);
		rectangle(7 * largeurFenetre() / 11, hauteurFenetre() / 9, 8 * largeurFenetre() / 11, 2 * hauteurFenetre() / 9);
		rectangle(9 * largeurFenetre() / 11, hauteurFenetre() / 9, 10 * largeurFenetre() / 11, 2 * hauteurFenetre() / 9);
		rectangle(largeurFenetre() / 11, 3 * hauteurFenetre() / 9, 2 * largeurFenetre() / 11, 4 * hauteurFenetre() / 9);
		rectangle(3 * largeurFenetre() / 11, 3 * hauteurFenetre() / 9, 4 * largeurFenetre() / 11, 4 * hauteurFenetre() / 9);
		rectangle(5 * largeurFenetre() / 11, 3 * hauteurFenetre() / 9, 6 * largeurFenetre() / 11, 4 * hauteurFenetre() / 9);
		rectangle(7 * largeurFenetre() / 11, 3 * hauteurFenetre() / 9, 8 * largeurFenetre() / 11, 4 * hauteurFenetre() / 9);
		rectangle(9 * largeurFenetre() / 11, 3 * hauteurFenetre() / 9, 10 * largeurFenetre() / 11, 4 * hauteurFenetre() / 9);
		rectangle(largeurFenetre() / 11, 5 * hauteurFenetre() / 9, 2 * largeurFenetre() / 11, 6 * hauteurFenetre() / 9);
		rectangle(3 * largeurFenetre() / 11, 5 * hauteurFenetre() / 9, 4 * largeurFenetre() / 11, 6 * hauteurFenetre() / 9);
		rectangle(5 * largeurFenetre() / 11, 5 * hauteurFenetre() / 9, 6 * largeurFenetre() / 11, 6 * hauteurFenetre() / 9);
		rectangle(7 * largeurFenetre() / 11, 5 * hauteurFenetre() / 9, 8 * largeurFenetre() / 11, 6 * hauteurFenetre() / 9);
		rectangle(9 * largeurFenetre() / 11, 5 * hauteurFenetre() / 9, 10 * largeurFenetre() / 11, 6 * hauteurFenetre() / 9);
		rectangle(largeurFenetre() / 11, 7 * hauteurFenetre() / 9, 2 * largeurFenetre() / 11, 8 * hauteurFenetre() / 9);
		rectangle(3 * largeurFenetre() / 11, 7 * hauteurFenetre() / 9, 4 * largeurFenetre() / 11, 8 * hauteurFenetre() / 9);
		rectangle(5 * largeurFenetre() / 11, 7 * hauteurFenetre() / 9, 6 * largeurFenetre() / 11, 8 * hauteurFenetre() / 9);
		rectangle(7 * largeurFenetre() / 11, 7 * hauteurFenetre() / 9, 8 * largeurFenetre() / 11, 8 * hauteurFenetre() / 9);
		rectangle(9 * largeurFenetre() / 11, 7 * hauteurFenetre() / 9, 10 * largeurFenetre() / 11, 8 * hauteurFenetre() / 9);
		if (*ptj == -1)
		{
			for (c = 0; c < 20; c++)
				jeu[c] = 0;
			for (int val = 1; val < 21; val++)
			{
			re:
				c = rand() % 20;
				if (jeu[c] == 0)
					jeu[c] = (val % 10) + 1;
				else
					goto re;
			}
		}
		*ptj = 0;
		if (*pta == 0)
		{
			*pta = *ptb;
		}
		for (c = 0; c < 20; c++)
		{
			switch (jeu[c])
			{
			case 1:
				couleurCourante(255, 0, 0);
				break;
			case 2:
				couleurCourante(0, 255, 0);
				break;
			case 3:
				couleurCourante(0, 0, 255);
				break;
			case 4:
				couleurCourante(255, 255, 0);
				break;
			case 5:
				couleurCourante(255, 0, 255);
				break;
			case 6:
				couleurCourante(0, 255, 255);
				break;
			case 7:
				couleurCourante(100, 0, 0);
				break;
			case 8:
				couleurCourante(0, 100, 0);
				break;
			case 9:
				couleurCourante(0, 0, 100);
				break;
			case 10:
				couleurCourante(0, 0, 0);
				break;
			}
			if (c > 4)
				l = 1;
			if (c > 9)
				l = 2;
			if (c > 14)
				l = 3;
			if (*pta == c + 1 || *ptb == c + 1 || ver[c] == 1)
				rectangle(largeurFenetre() / 11 + (c % 5) * 2 * largeurFenetre() / 11, hauteurFenetre() / 9 + 2 * l * hauteurFenetre() / 9, 2 * largeurFenetre() / 11 + (c % 5) * 2 * largeurFenetre() / 11, 2 * hauteurFenetre() / 9 + 2 * l * hauteurFenetre() / 9);
		}
		if (jeu[*pta - 1] == jeu[*ptb - 1] && *pta != *ptb)
		{
			ver[*pta - 1] = 1;
			ver[*ptb - 1] = 1;
			*pta = 0;
			*ptb = 0;
		}
		else if (jeu[*pta - 1] != jeu[*ptb - 1])
		{
			*pta = 0;
			*ptb = 0;
			*ptn = *ptn + 1;
		}

		for (int i = 0; i < 20; i++)
		{
			verif = verif + ver[i];
		}
		if (verif == 21)
		{
			*ptb = 21;
			verif = 1;
			for (int i = 0; i < 20; i++)
			{
				ver[i] = 0;
			}
		}
	}
}
int verifie(int jeu[20], int *pth, int bouton)
{
	if (jeu[*pth] == bouton)
	{
		*pth = *pth + 1;
		return 0;
	}
	else
		return 1;
}

void rapidite()
{
	couleurCourante(0, 0, 0);
	rectangle(0, 0, largeurFenetre() / 9, hauteurFenetre() / 18);
	rectangle(8 * largeurFenetre() / 9, 17 * hauteurFenetre() / 18, largeurFenetre(), hauteurFenetre());
	rectangle(2 * largeurFenetre() / 10, 4 * hauteurFenetre() / 10, 4 * largeurFenetre() / 10, 6 * hauteurFenetre() / 10);
	rectangle(6 * largeurFenetre() / 10, 4 * hauteurFenetre() / 10, 8 * largeurFenetre() / 10, 6 * hauteurFenetre() / 10);
	couleurCourante(255, 255, 255);
	rectangle(1, 1, largeurFenetre() / 9 - 1, hauteurFenetre() / 18 - 1);
	rectangle(8 * largeurFenetre() / 9 + 1, 17 * hauteurFenetre() / 18 + 1, largeurFenetre() - 1, hauteurFenetre() - 1);
	rectangle(2 * largeurFenetre() / 10 + 1, 4 * hauteurFenetre() / 10 + 1, 4 * largeurFenetre() / 10 - 1, 6 * hauteurFenetre() / 10 - 1);
	rectangle(6 * largeurFenetre() / 10 + 1, 4 * hauteurFenetre() / 10 + 1, 8 * largeurFenetre() / 10 - 1, 6 * hauteurFenetre() / 10 - 1);
	couleurCourante(0, 0, 0);
}

void test1Rapidite(int *ptx, int *pty, int *pte, int *ptbr, int *pth, int *ptt)
{
	char text[10] = "";
	srand(time(NULL));
	if (*ptt < -10)
	{
		*ptt = *ptt + 1;
		sprintf(text, "%d", -(*ptt) / 50 + 1);
		couleurCourante(0, 0, 0);
		afficheChaine(text, 80, 37 * largeurFenetre() / 80, hauteurFenetre() / 10);
	}
	else if (*ptt < 0)
	{
		*ptt = *ptt + 1;
		couleurCourante(0, 0, 0);
		afficheChaine("Go", 80, 9 * largeurFenetre() / 20, hauteurFenetre() / 10);
	}
	else
		*ptt = *ptt + 1;

	if (*ptt > -1)
	{
		if (*ptt % 50 == 0)
		{
			*ptx = rand() % largeurFenetre();
			if (*ptx < hauteurFenetre() / 10)
				*ptx = *ptx + hauteurFenetre() / 10;
			else if (*ptx > largeurFenetre() - hauteurFenetre() / 10)
				*ptx = *ptx - hauteurFenetre() / 10;
			*pty = rand() % hauteurFenetre();
			if (*pty < hauteurFenetre() / 10)
				*pty = *pty + hauteurFenetre() / 10;
			else if (*pty > 9 * hauteurFenetre() / 10)
				*pty = *pty - hauteurFenetre() / 10;
			*pte = 1;
			*pth = 0;
		}
		couleurCourante(0, 0, 0);
		cercle(*ptx, *pty, hauteurFenetre() / 20);
		if (etatBoutonSouris() == GaucheAppuye && *pte == 1)
		{
			if (abs(abscisseSouris() - *ptx) < hauteurFenetre() / 20 && abs(ordonneeSouris() - *pty) < hauteurFenetre() / 20)
			{
				*ptbr = *ptbr + 1;
				*pth = 1;
			}
			*pte = 0;
		}
		if (*pte == 0 && *pth == 1)
		{
			sprintf(text, "%d", *ptbr);
			couleurCourante(255, 255, 255);
			cercle(*ptx, *pty, hauteurFenetre() / 20 - 10);
			couleurCourante(0, 0, 0);
			afficheChaine(text, 20, *ptx - 10, *pty - 6);
		}
		else if (*pte == 0 && *pth != 1)
		{
			couleurCourante(255, 0, 0);
			ligne(*ptx - sqrt(2) * hauteurFenetre() / 40, *pty - sqrt(2) * hauteurFenetre() / 40, *ptx + sqrt(2) * hauteurFenetre() / 40, *pty + sqrt(2) * hauteurFenetre() / 40);
			ligne(*ptx - sqrt(2) * hauteurFenetre() / 40, *pty + sqrt(2) * hauteurFenetre() / 40, *ptx + sqrt(2) * hauteurFenetre() / 40, *pty - sqrt(2) * hauteurFenetre() / 40);
		}
	}
}

void test2Rapidite(char *ptl, int *pte, int *ptbr, int *pth, int *ptt)
{
	char text[10] = "";
	srand(time(NULL));

	if (*ptt < -10)
	{
		*ptt = *ptt + 1;
		sprintf(text, "%d", -(*ptt) / 50 + 1);
		couleurCourante(0, 0, 0);
		afficheChaine(text, 80, 37 * largeurFenetre() / 80, hauteurFenetre() / 10);
	}
	else if (*ptt < 0)
	{
		*ptt = *ptt + 1;
		couleurCourante(0, 0, 0);
		afficheChaine("Go", 80, 9 * largeurFenetre() / 20, hauteurFenetre() / 10);
	}
	else
		*ptt = *ptt + 1;

	if (*ptt > -1)
	{
		if (*ptt % 50 == 0)
		{
			*ptl = (rand() % 25) + 97;
			*pte = 1;
			*pth = 0;
		}
		if (caractereClavier() == *ptl && *pte == 1)
		{
			*ptbr = *ptbr + 1;
			*pth = 1;
			*pte = 0;
		}
		if (*pte == 0 && *pth == 1)
		{
			couleurCourante(0, 255, 0);
			rectangle(4 * largeurFenetre() / 10, hauteurFenetre() / 2 - largeurFenetre() / 10, 6 * largeurFenetre() / 10, hauteurFenetre() / 2 + largeurFenetre() / 10);
			couleurCourante(255, 255, 255);
			rectangle(4 * largeurFenetre() / 10 + 1, hauteurFenetre() / 2 - largeurFenetre() / 10 + 1, 6 * largeurFenetre() / 10 - 1, hauteurFenetre() / 2 + largeurFenetre() / 10 - 1);
		}
		couleurCourante(0, 0, 0);
		sprintf(text, "%c", *ptl);
		afficheChaine(text, 80, 19 * largeurFenetre() / 40, hauteurFenetre() / 2 - 5);
		sprintf(text, "%d", *ptbr);
		couleurCourante(0, 0, 0);
		afficheChaine(text, 80, 19 * largeurFenetre() / 40, 3 * hauteurFenetre() / 4);
	}
}

void lateralite()
{
	couleurCourante(0, 0, 0);
	rectangle(0, 0, largeurFenetre() / 9, hauteurFenetre() / 18);
	rectangle(8 * largeurFenetre() / 9, 17 * hauteurFenetre() / 18, largeurFenetre(), hauteurFenetre());
	rectangle(2 * largeurFenetre() / 10, 4 * hauteurFenetre() / 10, 4 * largeurFenetre() / 10, 6 * hauteurFenetre() / 10);
	rectangle(6 * largeurFenetre() / 10, 4 * hauteurFenetre() / 10, 8 * largeurFenetre() / 10, 6 * hauteurFenetre() / 10);
	couleurCourante(255, 255, 255);
	rectangle(1, 1, largeurFenetre() / 9 - 1, hauteurFenetre() / 18 - 1);
	rectangle(8 * largeurFenetre() / 9 + 1, 17 * hauteurFenetre() / 18 + 1, largeurFenetre() - 1, hauteurFenetre() - 1);
	rectangle(2 * largeurFenetre() / 10 + 1, 4 * hauteurFenetre() / 10 + 1, 4 * largeurFenetre() / 10 - 1, 6 * hauteurFenetre() / 10 - 1);
	rectangle(6 * largeurFenetre() / 10 + 1, 4 * hauteurFenetre() / 10 + 1, 8 * largeurFenetre() / 10 - 1, 6 * hauteurFenetre() / 10 - 1);
	couleurCourante(0, 0, 0);
}

void test1Lateralite(int *ptjeu, int *pte, int *ptbr, int *ptf, int *ptt)
{
	char text[10] = "";
	srand(time(NULL));
	if (*ptt < -10)
	{
		*ptt = *ptt + 1;
		sprintf(text, "%d", -(*ptt) / 50 + 1);
		couleurCourante(0, 0, 0);
		afficheChaine(text, 80, 37 * largeurFenetre() / 80, hauteurFenetre() / 10);
	}
	else if (*ptt < 0)
	{
		*ptt = *ptt + 1;
		couleurCourante(0, 0, 0);
		afficheChaine("Go", 80, 9 * largeurFenetre() / 20, hauteurFenetre() / 10);
	}
	else
		*ptt = *ptt + 1;
	if (*pte == -1)
	{
		*ptjeu = (rand() % 2) + 1;
		*pte = 0;
	}
	sprintf(text, "%d", *ptbr);
	couleurCourante(0, 0, 0);
	afficheChaine(text, 80, 37 * largeurFenetre() / 80, 8 * hauteurFenetre() / 10);
	rectangle(largeurFenetre() / 10, 4 * hauteurFenetre() / 10, 2 * largeurFenetre() / 10, 6 * hauteurFenetre() / 10);
	rectangle(8 * largeurFenetre() / 10, 4 * hauteurFenetre() / 10, 9 * largeurFenetre() / 10, 6 * hauteurFenetre() / 10);
	couleurCourante(255, 0, 0);
	rectangle(largeurFenetre() / 10 + 1, 4 * hauteurFenetre() / 10 + 1, 2 * largeurFenetre() / 10 - 1, 6 * hauteurFenetre() / 10 - 1);
	couleurCourante(0, 0, 255);
	rectangle(8 * largeurFenetre() / 10 + 1, 4 * hauteurFenetre() / 10 + 1, 9 * largeurFenetre() / 10 - 1, 6 * hauteurFenetre() / 10 - 1);
	if (*ptt > -1)
	{
		if (*ptt < 25)
		{
			if (*ptjeu == 1)
				couleurCourante(255, 0, 0);
			else if (*ptjeu == 2)
				couleurCourante(0, 0, 255);
			cercle(largeurFenetre() / 2, hauteurFenetre() / 2, hauteurFenetre() / 10);
			if (*pte == *ptjeu)
			{
				*ptbr = *ptbr + 1;
				*ptt = 25;
			}
			else if (*pte == 1 || *pte == 2)
				*ptt = 25;
		}
		else if (*ptt < 32)
		{
			if (*pte == 1)
			{
				if (*ptjeu == 1)
					couleurCourante(255, 0, 0);
				else if (*ptjeu == 2)
					couleurCourante(0, 0, 255);
				cercle(largeurFenetre() / 2 - (*ptt - 25) * largeurFenetre() / 20, hauteurFenetre() / 2, hauteurFenetre() / 10);
				couleurCourante(254, 150, 160);
				rectangle(largeurFenetre() / 10 + 10, 4 * hauteurFenetre() / 10 + 10, 2 * largeurFenetre() / 10 - 10, 6 * hauteurFenetre() / 10 - 10);
			}
			if (*pte == 2)
			{
				if (*ptjeu == 1)
					couleurCourante(255, 0, 0);
				else if (*ptjeu == 2)
					couleurCourante(0, 0, 255);
				cercle(largeurFenetre() / 2 + (*ptt - 25) * largeurFenetre() / 20, hauteurFenetre() / 2, hauteurFenetre() / 10);
				couleurCourante(115, 194, 251);
				rectangle(8 * largeurFenetre() / 10 + 10, 4 * hauteurFenetre() / 10 + 10, 9 * largeurFenetre() / 10 - 10, 6 * hauteurFenetre() / 10 - 10);
			}
		}
		else if (*ptt == 32)
		{
			*ptf = *ptf + 1;
			*pte = -1;
			*ptt = 0;
		}
	}
	if (*ptf == 50)
		*pte = 3;
	couleurCourante(0, 0, 0);
	afficheChaine("A", 80, largeurFenetre() / 8 - 8, 9 * hauteurFenetre() / 20);
	afficheChaine("P", 80, 6 * largeurFenetre() / 8 + 50, 9 * hauteurFenetre() / 20);
}

void test2lateralite(info Users[4], int i, int *ptt, int *pte, int *ptbr, int *ptlang)
{
	char text[10] = "";
	FILE *save;
	srand(time(NULL));
	if (*ptt < -10)
	{
		*ptt = *ptt + 1;
		sprintf(text, "%d", -(*ptt) / 50 + 1);
		couleurCourante(0, 0, 0);
		afficheChaine(text, 80, 37 * largeurFenetre() / 80, hauteurFenetre() / 10);
		if (*ptlang == 1)
			afficheChaine("Jeu a la souris", 40, 6 * largeurFenetre() / 20, 19 * hauteurFenetre() / 40);
		else
			afficheChaine("Mouse game", 40, 6 * largeurFenetre() / 20, 19 * hauteurFenetre() / 40);
	}
	else if (*ptt < 0)
	{
		*ptt = *ptt + 1;
		couleurCourante(0, 0, 0);
		afficheChaine("Go", 80, 9 * largeurFenetre() / 20, hauteurFenetre() / 10);
	}
	else
		*ptt = *ptt + 1;
	if (*ptt >= 0 && *ptt < 200) // timer 1s =50
	{

		couleurCourante(0, 0, 255);
		rectangle(2 * largeurFenetre() / 40, 38 * hauteurFenetre() / 40, 18 * largeurFenetre() / 40, 20 * hauteurFenetre() / 40);

		couleurCourante(255, 0, 0);
		rectangle(22 * largeurFenetre() / 40, 38 * hauteurFenetre() / 40, 38 * largeurFenetre() / 40, 20 * hauteurFenetre() / 40);

		couleurCourante(169, 169, 169);
		rectangle(13 * largeurFenetre() / 40, 14 * hauteurFenetre() / 40, 18 * largeurFenetre() / 40, 10.5 * hauteurFenetre() / 40);
		rectangle(22 * largeurFenetre() / 40, 14 * hauteurFenetre() / 40, 27 * largeurFenetre() / 40, 10.5 * hauteurFenetre() / 40);

		couleurCourante(0, 0, 0);

		if (*ptlang == 1)
		{

			afficheChaine("De quel cote est la case bleue?", 18, 13 * largeurFenetre() / 40, 16.5 * hauteurFenetre() / 40);

			afficheChaine("Gauche", 18, 14 * largeurFenetre() / 40, 6 * hauteurFenetre() / 20);
			afficheChaine("Droite", 18, 23 * largeurFenetre() / 40, 6 * hauteurFenetre() / 20);

			couleurCourante(255, 0, 0);
			afficheChaine("Rouge", 25, 9 * largeurFenetre() / 40, 28 * hauteurFenetre() / 40);

			couleurCourante(0, 0, 255);
			afficheChaine("Bleu", 25, 29 * largeurFenetre() / 40, 28 * hauteurFenetre() / 40);
		}
		else
		{
			afficheChaine("Which side is the blue box?", 18, 13 * largeurFenetre() / 40, 16.5 * hauteurFenetre() / 40);

			afficheChaine("Left", 18, 14 * largeurFenetre() / 40, 6 * hauteurFenetre() / 20);
			afficheChaine("Right", 18, 23 * largeurFenetre() / 40, 6 * hauteurFenetre() / 20);

			couleurCourante(255, 0, 0);
			afficheChaine("Red", 25, 9 * largeurFenetre() / 40, 28 * hauteurFenetre() / 40);

			couleurCourante(0, 0, 255);
			afficheChaine("Blue", 25, 29 * largeurFenetre() / 40, 28 * hauteurFenetre() / 40);
		}

		if (*pte == 1)
		{
			*pte = 0;
			*ptbr = *ptbr + 1;
			*ptt = 200;
		}
		else if (*pte == 2)
		{
			*pte = 0;
			*ptt = 200;
		}
	}
	else if (*ptt >= 200 && *ptt < 400)
	{

		couleurCourante(0, 255, 0);
		rectangle(2 * largeurFenetre() / 40, 38 * hauteurFenetre() / 40, 18 * largeurFenetre() / 40, 20 * hauteurFenetre() / 40);

		couleurCourante(255, 255, 0);
		rectangle(22 * largeurFenetre() / 40, 38 * hauteurFenetre() / 40, 38 * largeurFenetre() / 40, 20 * hauteurFenetre() / 40);

		couleurCourante(169, 169, 169);
		rectangle(13 * largeurFenetre() / 40, 14 * hauteurFenetre() / 40, 18 * largeurFenetre() / 40, 10.5 * hauteurFenetre() / 40);
		rectangle(22 * largeurFenetre() / 40, 14 * hauteurFenetre() / 40, 27 * largeurFenetre() / 40, 10.5 * hauteurFenetre() / 40);

		couleurCourante(0, 0, 0);
		if (*ptlang == 1)
		{
			afficheChaine("De quel cote est la case jaune ?", 18, 13 * largeurFenetre() / 40, 16.5 * hauteurFenetre() / 40);

			afficheChaine("Gauche", 18, 14 * largeurFenetre() / 40, 6 * hauteurFenetre() / 20);
			afficheChaine("Droite", 18, 23 * largeurFenetre() / 40, 6 * hauteurFenetre() / 20);

			couleurCourante(255, 255, 0);
			afficheChaine("Jaune", 25, 9 * largeurFenetre() / 40, 28 * hauteurFenetre() / 40);

			couleurCourante(0, 255, 0);
			afficheChaine("Vert", 25, 29 * largeurFenetre() / 40, 28 * hauteurFenetre() / 40);
		}
		else
		{
			afficheChaine("Which side is the yellow box ?", 18, 13 * largeurFenetre() / 40, 16.5 * hauteurFenetre() / 40);

			afficheChaine("Left", 18, 14 * largeurFenetre() / 40, 6 * hauteurFenetre() / 20);
			afficheChaine("Right", 18, 23 * largeurFenetre() / 40, 6 * hauteurFenetre() / 20);

			couleurCourante(255, 255, 0);
			afficheChaine("Yellow", 25, 9 * largeurFenetre() / 40, 28 * hauteurFenetre() / 40);

			couleurCourante(0, 255, 0);
			afficheChaine("Green", 25, 29 * largeurFenetre() / 40, 28 * hauteurFenetre() / 40);
		}

		if (*pte == 1)
		{
			*pte = 0;
			*ptt = 400;
		}
		else if (*pte == 2)
		{
			*pte = 0;
			*ptt = 400;
			*ptbr = *ptbr + 1;
		}
	}

	else if (*ptt >= 400 && *ptt < 600)
	{
		couleurCourante(88, 41, 0);
		rectangle(2 * largeurFenetre() / 40, 38 * hauteurFenetre() / 40, 18 * largeurFenetre() / 40, 20 * hauteurFenetre() / 40);

		couleurCourante(0, 0, 0);
		rectangle(22 * largeurFenetre() / 40, 38 * hauteurFenetre() / 40, 38 * largeurFenetre() / 40, 20 * hauteurFenetre() / 40);

		couleurCourante(169, 169, 169);
		rectangle(13 * largeurFenetre() / 40, 14 * hauteurFenetre() / 40, 18 * largeurFenetre() / 40, 10.5 * hauteurFenetre() / 40);
		rectangle(22 * largeurFenetre() / 40, 14 * hauteurFenetre() / 40, 27 * largeurFenetre() / 40, 10.5 * hauteurFenetre() / 40);

		couleurCourante(0, 0, 0);
		if (*ptlang == 1)
		{
			afficheChaine("De quel cote est la case marron?", 18, 13 * largeurFenetre() / 40, 16.5 * hauteurFenetre() / 40);

			afficheChaine("Droite", 18, 14 * largeurFenetre() / 40, 6 * hauteurFenetre() / 20);
			afficheChaine("Gauche", 18, 23 * largeurFenetre() / 40, 6 * hauteurFenetre() / 20);

			couleurCourante(255, 255, 255);
			afficheChaine("Noir", 25, 9 * largeurFenetre() / 40, 28 * hauteurFenetre() / 40);

			couleurCourante(255, 255, 255);
			afficheChaine("ICI", 25, 29 * largeurFenetre() / 40, 28 * hauteurFenetre() / 40);
		}
		else
		{
			afficheChaine("Which side is the brown box?", 18, 13 * largeurFenetre() / 40, 16.5 * hauteurFenetre() / 40);

			afficheChaine("Right", 18, 14 * largeurFenetre() / 40, 6 * hauteurFenetre() / 20);
			afficheChaine("Left", 18, 23 * largeurFenetre() / 40, 6 * hauteurFenetre() / 20);

			couleurCourante(255, 255, 255);
			afficheChaine("Black", 25, 9 * largeurFenetre() / 40, 28 * hauteurFenetre() / 40);

			couleurCourante(255, 255, 255);
			afficheChaine("HERE", 25, 29 * largeurFenetre() / 40, 28 * hauteurFenetre() / 40);
		}

		if (*pte == 1)
		{
			*pte = 0;
			*ptt = 600;
		}
		else if (*pte == 2)
		{
			*pte = 0;
			*ptt = 600;
			*ptbr = *ptbr + 1;
		}
	}
	else if (*ptt >= 600)
	{
		Users[i].Lateralite[2] = (*ptbr) * 100 / 3.0;
		save = fopen("Sauvegarde/save.txt", "w");
		sauvegarde(save, Users, ptlang);
		sprintf(text, "%d/3", *ptbr);
		couleurCourante(0, 0, 0);
		rectangle(0, 0, largeurFenetre() / 9, hauteurFenetre() / 18);
		couleurCourante(255, 255, 255);
		rectangle(1, 1, largeurFenetre() / 9 - 1, hauteurFenetre() / 18 - 1);
		couleurCourante(0, 0, 0);
		afficheChaine("Fin", 40, largeurFenetre() / 2 - 10, 17 * hauteurFenetre() / 20);
		afficheChaine(text, 80, largeurFenetre() / 2 - 10, hauteurFenetre() / 2);
		afficheChaine("Back", 25, largeurFenetre() / 144, hauteurFenetre() / 72);
	}
}

void resultatspe()
{
	couleurCourante(0, 0, 0);
	rectangle(0, 0, largeurFenetre() / 9, hauteurFenetre() / 18);
	couleurCourante(190, 190, 190);
	rectangle(3 * largeurFenetre() / 10, 3 * hauteurFenetre() / 8, 8 * largeurFenetre() / 10, hauteurFenetre() / 2);
	rectangle(3 * largeurFenetre() / 10, hauteurFenetre() / 2, 8 * largeurFenetre() / 10, 5 * hauteurFenetre() / 8);
	couleurCourante(255, 255, 255);
	rectangle(1, 1, largeurFenetre() / 9 - 1, hauteurFenetre() / 18 - 1);
	rectangle(3 * largeurFenetre() / 10 + 1, 3 * hauteurFenetre() / 8 + 1, 8 * largeurFenetre() / 10 - 1, hauteurFenetre() / 2 - 1);
	rectangle(3 * largeurFenetre() / 10 + 1, hauteurFenetre() / 2 + 1, 8 * largeurFenetre() / 10 - 1, 5 * hauteurFenetre() / 8 - 1);
	couleurCourante(0, 0, 0);
}

void resultat()
{
	couleurCourante(0, 0, 0);
	rectangle(0, 0, largeurFenetre() / 9, hauteurFenetre() / 18);
	couleurCourante(255, 255, 255);
	rectangle(1, 1, largeurFenetre() / 9 - 1, hauteurFenetre() / 18 - 1);
	couleurCourante(190, 190, 190);
	cercle(largeurFenetre() / 2, hauteurFenetre() / 2, hauteurFenetre() / 3);
	couleurCourante(255, 255, 255);
	cercle(largeurFenetre() / 2, hauteurFenetre() / 2, hauteurFenetre() / 3 - 1);
	couleurCourante(190, 190, 190);
	cercle(largeurFenetre() / 2, hauteurFenetre() / 2, 3 * hauteurFenetre() / 12);
	couleurCourante(255, 255, 255);
	cercle(largeurFenetre() / 2, hauteurFenetre() / 2, 3 * hauteurFenetre() / 12 - 1);
	couleurCourante(190, 190, 190);
	cercle(largeurFenetre() / 2, hauteurFenetre() / 2, hauteurFenetre() / 6);
	couleurCourante(255, 255, 255);
	cercle(largeurFenetre() / 2, hauteurFenetre() / 2, hauteurFenetre() / 6 - 1);
	couleurCourante(190, 190, 190);
	cercle(largeurFenetre() / 2, hauteurFenetre() / 2, hauteurFenetre() / 12);
	couleurCourante(255, 255, 255);
	cercle(largeurFenetre() / 2, hauteurFenetre() / 2, hauteurFenetre() / 12 - 1);
	couleurCourante(190, 190, 190);
	point(largeurFenetre() / 2, hauteurFenetre() / 2);
}