#include"fonction.h"

	
int main(int argc, char **argv)
{
	initialiseGfx(argc, argv);
	prepareFenetreGraphique("GfxLib", LargeurFenetre, HauteurFenetre);
	lanceBoucleEvenements();
	
	return 0;
}

void gestionEvenement(EvenementGfx evenement)
{
	static int page=0, zone=0, tmp=-250, *ptt=&tmp;
	static int i=0;
	static char Nom[12]="", Prenom[12]="", read[250]="";
	static info Users[4];
	FILE *save;
	
	static int jeume[20], j=-1, *ptj=&j, h=0, *pth=&h, a=0, *pta=&a, bouton=0, *ptb=&bouton, niveau=1, *ptn=&niveau;//Test1Me
	static int jeul=0, *ptjeu=&jeul , etat=-1, *pte=&etat, breponse=0, *ptbr=&breponse, fin=0, *ptf=&fin;//Test1L
	static int x=0, *ptx=&x, y=0, *pty=&y;
	static char lettre, *ptl=&lettre;

	char text[10]="";
	static int lang=1, *ptlang=&lang;
	static char Q[15], C[15], Ret[15], N[15], P[15], S[15], Res[15], M[15], Rap[15], L[15], E1[15], E2[15], F[15], Clav[15], Sour[16], Go[15];
	
	switch (evenement)
	{
		case Initialisation:
			save=fopen("Sauvegarde/save.txt","r");
			fgets(read,250,save);
			fclose(save);
			chargement(read,Users,ptlang);
			
	
			demandeTemporisation(20);
			
			break;
		
		case Temporisation:
			rafraichisFenetre();
			break;
			
		case Affichage:
			effaceFenetre (255, 255, 255);
			if(page<10 || page>15)
			{
				couleurCourante(0,0,0);
				cercle(largeurFenetre()-20, 5*hauteurFenetre()/80+4,10);
				cercle(largeurFenetre()-20, hauteurFenetre()/80+4,10);
				afficheChaine("English",10, 9*largeurFenetre()/10, 5*hauteurFenetre()/80);
				afficheChaine("Francais",10, 9*largeurFenetre()/10, hauteurFenetre()/80);	
				couleurCourante(255,255,255);
				cercle(largeurFenetre()-20, 5*hauteurFenetre()/80+4,9);
				cercle(largeurFenetre()-20, hauteurFenetre()/80+4,9);
				couleurCourante(0,0,0);
				if(lang==1)
				{
					cercle(largeurFenetre()-20, hauteurFenetre()/80+4,7);
					strcpy(Q,"Quitter");
					strcpy(C,"Connexion");
					strcpy(Ret,"Retour");
					strcpy(N,"Nom:");
					strcpy(P,"Prenom:");
					strcpy(S,"Sauve");
					strcpy(Res,"Resultats");
					strcpy(M,"Memoire");
					strcpy(Rap,"Rapidite");
					strcpy(L,"Lateralite");
					strcpy(E1,"Exo 1");
					strcpy(E2,"Exo 2");
					strcpy(F,"Fin");
					strcpy(Clav,"Jeu au clavier");
					strcpy(Sour,"Jeu a la souris");
					strcpy(Go,"Attendez");
				}
				else
				{
					cercle(largeurFenetre()-20, 5*hauteurFenetre()/80+4,7);
					strcpy(Q,"Quit");
					strcpy(C,"Connection");
					strcpy(Ret,"Back");
					strcpy(N,"Name:");
					strcpy(P,"Surname:");
					strcpy(S,"Save");
					strcpy(Res,"Results");
					strcpy(M,"Memory");
					strcpy(Rap,"Speed");
					strcpy(L,"Laterality");
					strcpy(E1,"Test 1");
					strcpy(E2,"Test 2");
					strcpy(F,"End");
					strcpy(Clav,"Keyboard game");
					strcpy(Sour,"Mouse game");
					strcpy(Go,"Wait");
				} 
			}
			
			
			switch(page)
			{
				case 0:
					pagededemarrage();
					afficheChaine(Q,25, largeurFenetre()/72, hauteurFenetre()/2);
					afficheChaine("Inscription",40, 7*largeurFenetre()/20, 21*hauteurFenetre()/36);
					afficheChaine(C,40, 7*largeurFenetre()/20, 13*hauteurFenetre()/36);	
					break;
					
				case 1:
					if(zone==1)
						rectangle(3*largeurFenetre()/9-1, 5*hauteurFenetre()/9-1, 6*largeurFenetre()/9+1, 6*hauteurFenetre()/9+1);
					else if(zone==2)
						rectangle(3*largeurFenetre()/9-1, 3*hauteurFenetre()/9-1, 6*largeurFenetre()/9+1, 4*hauteurFenetre()/9+1);
					else if(zone==3)
						rectangle(4*largeurFenetre()/9-1, hauteurFenetre()/9-1, 5*largeurFenetre()/9+1, 2*hauteurFenetre()/9+1);
					pagedinscription();
					afficheChaine(Ret,25, largeurFenetre()/144, hauteurFenetre()/72);
					afficheChaine(N,40, largeurFenetre()/9, 21*hauteurFenetre()/36);
					afficheChaine(P,40, largeurFenetre()/9-10, 13*hauteurFenetre()/36);
					afficheChaine(S,30, 9*largeurFenetre()/20-4, 5*hauteurFenetre()/36);
					afficheChaine(Nom, 40, 13*largeurFenetre()/36, 21*hauteurFenetre()/36);
					afficheChaine(Prenom, 40, 13*largeurFenetre()/36, 13*hauteurFenetre()/36);
					break;
					
				case 2:
					pagedeconnection();
					for(int j=0;j<4;j++)
					{
						afficheChaine(Users[j].Nom, 20, 9*largeurFenetre()/36, 29*hauteurFenetre()/36-j*2*hauteurFenetre()/9);
						afficheChaine(Users[j].Prenom, 20, 17*largeurFenetre()/36, 29*hauteurFenetre()/36-j*2*hauteurFenetre()/9);
					}
					afficheChaine(Ret,25, largeurFenetre()/144, hauteurFenetre()/72);
					break;
					
				case 3:
					pagedacceuil();
					afficheChaine(Ret,25, largeurFenetre()/144, hauteurFenetre()/72);
					afficheChaine(Res,15, 65*largeurFenetre()/72, 69*hauteurFenetre()/72);
					afficheChaine(M,30, 5*largeurFenetre()/40, hauteurFenetre()/2);
					afficheChaine(Rap,30, 17*largeurFenetre()/40, hauteurFenetre()/2);
					afficheChaine(L,30, 29*largeurFenetre()/40, hauteurFenetre()/2);
					afficheChaine(Users[i].Nom, 20, largeurFenetre()/36, 33*hauteurFenetre()/36);
					afficheChaine(Users[i].Prenom, 20, 8*largeurFenetre()/36, 33*hauteurFenetre()/36);
					break;
					
				case 4:
					memoire();
					afficheChaine(Ret,25, largeurFenetre()/144, hauteurFenetre()/72);
					afficheChaine(Res,15, 65*largeurFenetre()/72, 69*hauteurFenetre()/72);
					afficheChaine(E1,30, 9*largeurFenetre()/40, hauteurFenetre()/2);
					afficheChaine(E2,30, 25*largeurFenetre()/40, hauteurFenetre()/2);
					afficheChaine(Users[i].Nom, 20, largeurFenetre()/36, 33*hauteurFenetre()/36);
					afficheChaine(Users[i].Prenom, 20, 8*largeurFenetre()/36, 33*hauteurFenetre()/36);
					break;
					
				case 5:
					rapidite();
					afficheChaine(Ret,25, largeurFenetre()/144, hauteurFenetre()/72);
					afficheChaine(Res,15, 65*largeurFenetre()/72, 69*hauteurFenetre()/72);
					afficheChaine(E1,30, 9*largeurFenetre()/40, hauteurFenetre()/2);
					afficheChaine(E2,30, 25*largeurFenetre()/40, hauteurFenetre()/2);
					afficheChaine(Users[i].Nom, 20, largeurFenetre()/36, 33*hauteurFenetre()/36);
					afficheChaine(Users[i].Prenom, 20, 8*largeurFenetre()/36, 33*hauteurFenetre()/36);
					break;
					
				case 6:
					lateralite();
					afficheChaine(Ret,25, largeurFenetre()/144, hauteurFenetre()/72);
					afficheChaine(Res,15, 65*largeurFenetre()/72, 69*hauteurFenetre()/72);
					afficheChaine(E1,30, 9*largeurFenetre()/40, hauteurFenetre()/2);
					afficheChaine(E2,30, 25*largeurFenetre()/40, hauteurFenetre()/2);
					afficheChaine(Users[i].Nom, 20, largeurFenetre()/36, 33*hauteurFenetre()/36);
					afficheChaine(Users[i].Prenom, 20, 8*largeurFenetre()/36, 33*hauteurFenetre()/36);
					break;
					
				case 7:
					resultatspe();
					afficheChaine(Ret,25, largeurFenetre()/144, hauteurFenetre()/72);
					afficheChaine(E1,30, largeurFenetre()/10, 17*hauteurFenetre()/32);
					afficheChaine(E2,30, largeurFenetre()/10, 13*hauteurFenetre()/32);
					afficheChaine(Users[i].Nom, 20, largeurFenetre()/36, 33*hauteurFenetre()/36);
					afficheChaine(Users[i].Prenom, 20, 8*largeurFenetre()/36, 33*hauteurFenetre()/36);
					couleurCourante(15, 157, 232);
					rectangle(3*largeurFenetre()/10+1, 3*hauteurFenetre()/8+1, 3*largeurFenetre()/10+(Users[i].Memoire[2]/100.0)*(5*largeurFenetre()/10)-1, hauteurFenetre()/2-1);
					rectangle(3*largeurFenetre()/10+1, hauteurFenetre()/2+1, 3*largeurFenetre()/10+(Users[i].Memoire[1]/100.0)*(5*largeurFenetre()/10)-1, 5*hauteurFenetre()/8-1);
					break;
					
				case 8:
					resultatspe();
					afficheChaine(Ret,25, largeurFenetre()/144, hauteurFenetre()/72);
					afficheChaine(E1,30, largeurFenetre()/10, 17*hauteurFenetre()/32);
					afficheChaine(E2,30, largeurFenetre()/10, 13*hauteurFenetre()/32);
					afficheChaine(Users[i].Nom, 20, largeurFenetre()/36, 33*hauteurFenetre()/36);
					afficheChaine(Users[i].Prenom, 20, 8*largeurFenetre()/36, 33*hauteurFenetre()/36);
					couleurCourante(15, 157, 232);
					rectangle(3*largeurFenetre()/10+1, 3*hauteurFenetre()/8+1, 3*largeurFenetre()/10+(Users[i].Rapidite[2]/100.0)*(5*largeurFenetre()/10)-1, hauteurFenetre()/2-1);
					rectangle(3*largeurFenetre()/10+1, hauteurFenetre()/2+1, 3*largeurFenetre()/10+(Users[i].Rapidite[1]/100.0)*(5*largeurFenetre()/10)-1, 5*hauteurFenetre()/8-1);
					break;
					
				case 9:
					resultatspe();
					afficheChaine(Ret,25, largeurFenetre()/144, hauteurFenetre()/72);
					afficheChaine(E1,30, largeurFenetre()/10, 17*hauteurFenetre()/32);
					afficheChaine(E2,30, largeurFenetre()/10, 13*hauteurFenetre()/32);
					afficheChaine(Users[i].Nom, 20, largeurFenetre()/36, 33*hauteurFenetre()/36);
					afficheChaine(Users[i].Prenom, 20, 8*largeurFenetre()/36, 33*hauteurFenetre()/36);
					couleurCourante(15, 157, 232);
					rectangle(3*largeurFenetre()/10+1, 3*hauteurFenetre()/8+1, 3*largeurFenetre()/10+(Users[i].Lateralite[2]/100.0)*(5*largeurFenetre()/10)-1, hauteurFenetre()/2-1);
					rectangle(3*largeurFenetre()/10+1, hauteurFenetre()/2+1, 3*largeurFenetre()/10+(Users[i].Lateralite[1]/100.0)*(5*largeurFenetre()/10)-1, 5*hauteurFenetre()/8-1);
					break;
				
				case 10:
					if(bouton!=5)
					{
						test1memoire(jeume,ptj,pth,pta,ptb,ptn,ptt);
						if(tmp<-10)
						{
							couleurCourante(0, 0, 0);
							afficheChaine(Sour,40, 6*largeurFenetre()/20, 19*hauteurFenetre()/40);
						}
						else if(tmp<0)
						{
							couleurCourante(0, 0, 0);
							afficheChaine(Go,80, 7*largeurFenetre()/20, hauteurFenetre()/10);
						}
					}
					else
					{
						Users[i].Memoire[1]=(niveau-1)*5;
						save = fopen("Sauvegarde/save.txt","w");
						sauvegarde(save,Users,ptlang);
						sprintf(text,"%d/20",niveau-1);
						couleurCourante(0, 0, 0);
						rectangle(0, 0, largeurFenetre()/9, hauteurFenetre()/18);
						couleurCourante(255, 255, 255);
						rectangle(1, 1, largeurFenetre()/9-1, hauteurFenetre()/18-1);
						couleurCourante(0, 0, 0);
						afficheChaine(F,40, largeurFenetre()/2-10, 9*hauteurFenetre()/10);
						afficheChaine(text,80, 4*largeurFenetre()/10, hauteurFenetre()/2);
						afficheChaine(Ret,25, largeurFenetre()/144, hauteurFenetre()/72);
					}
					break;
				
				case 11:
					if(bouton!=21)
					{
						test2memoire(jeume,ptj,pte,pta,ptb,ptn,ptt);
						if(tmp<-10)
						{
							afficheChaine(Sour,40, 6*largeurFenetre()/20, 19*hauteurFenetre()/40);
						}
					}
					else
					{
						demandeTemporisation(20);
						if(40-niveau > 25)
							Users[i].Memoire[2]=100;
						else if(40-niveau < 0)
							Users[i].Memoire[2]=0;
						else
							Users[i].Memoire[2]=(40-niveau)*4;
						save = fopen("Sauvegarde/save.txt","w");
						sauvegarde(save,Users,ptlang);
						if(40-niveau > 25)
							sprintf(text,"%d/25",25);
						else if(40-niveau < 0)
							sprintf(text,"%d/25",0);
						else
							sprintf(text,"%d/25",40-niveau);
						couleurCourante(0, 0, 0);
						rectangle(0, 0, largeurFenetre()/9, hauteurFenetre()/18);
						couleurCourante(255, 255, 255);
						rectangle(1, 1, largeurFenetre()/9-1, hauteurFenetre()/18-1);
						couleurCourante(0, 0, 0);
						afficheChaine(F,40, largeurFenetre()/2-10, 9*hauteurFenetre()/10);
						afficheChaine(text,80, 4*largeurFenetre()/10, hauteurFenetre()/2);
						afficheChaine(Ret,25, largeurFenetre()/144, hauteurFenetre()/72);
					}
					break;

				case 12:
					if(tmp!=1000)
					{	
						test1Rapidite(ptx,pty,pte,ptbr,pth,ptt);
						if(tmp<-10)
						{
							afficheChaine(Sour,40, 6*largeurFenetre()/20, 19*hauteurFenetre()/40);
						}
					}
					else
					{
						Users[i].Rapidite[1]=(breponse)*5;
						save = fopen("Sauvegarde/save.txt","w");
						sauvegarde(save,Users,ptlang);
						sprintf(text,"%d/20",breponse);
						couleurCourante(0, 0, 0);
						rectangle(0, 0, largeurFenetre()/9, hauteurFenetre()/18);
						couleurCourante(255, 255, 255);
						rectangle(1, 1, largeurFenetre()/9-1, hauteurFenetre()/18-1);
						couleurCourante(0, 0, 0);
						afficheChaine(F,40, largeurFenetre()/2-10, 9*hauteurFenetre()/10);
						afficheChaine(text,80, 4*largeurFenetre()/10, hauteurFenetre()/2);
						afficheChaine(Ret,25, largeurFenetre()/144, hauteurFenetre()/72);
					}
					break;
				
				case 13:
					if(tmp!=1000)
					{	
						test2Rapidite(ptl,pte,ptbr,pth,ptt);
						if(tmp<-10)
						{
							afficheChaine(Clav,40, 6*largeurFenetre()/20, 19*hauteurFenetre()/40);
						}
					}
					else
					{
						Users[i].Rapidite[2]=(breponse)*5;
						save = fopen("Sauvegarde/save.txt","w");
						sauvegarde(save,Users,ptlang);
						sprintf(text,"%d/20",breponse);
						couleurCourante(0, 0, 0);
						rectangle(0, 0, largeurFenetre()/9, hauteurFenetre()/18);
						couleurCourante(255, 255, 255);
						rectangle(1, 1, largeurFenetre()/9-1, hauteurFenetre()/18-1);
						couleurCourante(0, 0, 0);
						afficheChaine(F,40, largeurFenetre()/2-10, 9*hauteurFenetre()/10);
						afficheChaine(text,80, 4*largeurFenetre()/10, hauteurFenetre()/2);
						afficheChaine(Ret,25, largeurFenetre()/144, hauteurFenetre()/72);
					}
					break;
					
				case 14:
					if(etat!=3)
					{
						test1Lateralite(ptjeu,pte,ptbr,ptf,ptt);
						if(tmp<-10)
						{
							afficheChaine(Clav,40, 6*largeurFenetre()/20, 19*hauteurFenetre()/40);
						}
					}
					else
					{
						Users[i].Lateralite[1]=(breponse)*2;
						save = fopen("Sauvegarde/save.txt","w");
						sauvegarde(save,Users,ptlang);
						sprintf(text,"%d/50",breponse);
						couleurCourante(0, 0, 0);
						rectangle(0, 0, largeurFenetre()/9, hauteurFenetre()/18);
						couleurCourante(255, 255, 255);
						rectangle(1, 1, largeurFenetre()/9-1, hauteurFenetre()/18-1);
						couleurCourante(0, 0, 0);
						afficheChaine(F,40, largeurFenetre()/2-10, 17*hauteurFenetre()/20);
						afficheChaine(text,80, 7*largeurFenetre()/20, hauteurFenetre()/2);
						afficheChaine(Ret,25, largeurFenetre()/144, hauteurFenetre()/72);
					}	
					break;

				case 15:
                 		  	test2lateralite(Users, i, ptt,pte,ptbr,ptlang);
                  			break;

				case 16:
					resultat();
					couleurCourante(255, 0, 0);
					afficheChaine(M,30, largeurFenetre()/10, hauteurFenetre()/2+(hauteurFenetre()/3)/2);
					ligne(largeurFenetre()/2, hauteurFenetre()/2, largeurFenetre()/2-(sqrt(3)/2)*(hauteurFenetre()/3), hauteurFenetre()/2+(hauteurFenetre()/3)/2);
					couleurCourante(0, 255, 0);
					afficheChaine(Rap,30, 15*largeurFenetre()/20, hauteurFenetre()/2+(hauteurFenetre()/3)/2);
					ligne(largeurFenetre()/2, hauteurFenetre()/2, largeurFenetre()/2+(sqrt(3)/2)*(hauteurFenetre()/3), hauteurFenetre()/2+(hauteurFenetre()/3)/2);
					couleurCourante(0, 0, 255);
					afficheChaine(L,30, 17*largeurFenetre()/40, hauteurFenetre()/10);
					ligne(largeurFenetre()/2, hauteurFenetre()/2, largeurFenetre()/2, hauteurFenetre()/2-(hauteurFenetre()/3));
					couleurCourante(0, 0, 0);
					afficheChaine(Ret,25, largeurFenetre()/144, hauteurFenetre()/72);
					couleurCourante(0, 0, 0);
					afficheChaine(Users[i].Nom, 20, largeurFenetre()/36, 33*hauteurFenetre()/36);
					afficheChaine(Users[i].Prenom, 20, 8*largeurFenetre()/36, 33*hauteurFenetre()/36);
					ligne(largeurFenetre()/2-(sqrt(3)*(Users[i].Memoire[0]/100.0)/2)*(hauteurFenetre()/3), hauteurFenetre()/2+(Users[i].Memoire[0]/100.0)/2*(hauteurFenetre()/3), largeurFenetre()/2+(sqrt(3)*(Users[i].Rapidite[0]/100.0)/2)*(hauteurFenetre()/3), hauteurFenetre()/2+(Users[i].Rapidite[0]/100.0)/2*(hauteurFenetre()/3));
					ligne(largeurFenetre()/2+(sqrt(3)*(Users[i].Rapidite[0]/100.0)/2)*(hauteurFenetre()/3), hauteurFenetre()/2+(Users[i].Rapidite[0]/100.0)/2*(hauteurFenetre()/3), largeurFenetre()/2, hauteurFenetre()/2-(Users[i].Lateralite[0]/100.0)*(hauteurFenetre()/3));
					ligne(largeurFenetre()/2, hauteurFenetre()/2-(Users[i].Lateralite[0]/100.0)*(hauteurFenetre()/3), largeurFenetre()/2-(sqrt(3)*(Users[i].Memoire[0]/100.0)/2)*(hauteurFenetre()/3), hauteurFenetre()/2+(Users[i].Memoire[0]/100.0)/2*(hauteurFenetre()/3));
					break;
			}
		
			break;
			
		case Clavier:
			switch(page)
			{
				case 1:
					if(zone==1)
						ecrire(Nom);
					if(zone==2)
						ecrire(Prenom);
					break;
				case 14:
					if(etat!=3)
					{
						if(caractereClavier()=='a')
							etat=1;
						if(caractereClavier()=='p')
							etat=2;
					}
					break;
			}
			break;
			
		case ClavierSpecial:
			break;

		case BoutonSouris:
			if (etatBoutonSouris() == GaucheAppuye)
			{
				if(page<10 || page>15)
				{
					if(abs(abscisseSouris()-largeurFenetre()+20)<10 && abs(ordonneeSouris()-5*hauteurFenetre()/80-4)<10)
					{
						lang=0;
						save = fopen("Sauvegarde/save.txt","w");
						sauvegarde(save,Users,ptlang);
					}
					if(abs(abscisseSouris()-largeurFenetre()+20)<10 && abs(ordonneeSouris()-hauteurFenetre()/80-4)<10)
					{
						lang=1;
						save = fopen("Sauvegarde/save.txt","w");
						sauvegarde(save,Users,ptlang);
					}		
				}
				switch(page)
				{
					case 0:
						if (2*largeurFenetre()/9 <= abscisseSouris() && abscisseSouris() <= 7*largeurFenetre()/9 && 5*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 6*hauteurFenetre()/9)	
							page=1;
						if (2*largeurFenetre()/9 <= abscisseSouris() && abscisseSouris() <= 7*largeurFenetre()/9 && 3*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 4*hauteurFenetre()/9)	
							page=2;
						if (0 <= abscisseSouris() && abscisseSouris() <= largeurFenetre()/9 && 0 <= ordonneeSouris() && ordonneeSouris() <= hauteurFenetre())	
							termineBoucleEvenements();
						break;
				
					case 1:
						if (0 <= abscisseSouris() && abscisseSouris() <= largeurFenetre()/9 && 0 <= ordonneeSouris() && ordonneeSouris() <= hauteurFenetre()/18)
						{	
							page=0;
							strcpy(Nom,"");
							strcpy(Prenom,"");
						}
						if (3*largeurFenetre()/9 <= abscisseSouris() && abscisseSouris() <= 6*largeurFenetre()/9 && 5*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 6*hauteurFenetre()/9)	
							zone=1;	
						else if (3*largeurFenetre()/9 <= abscisseSouris() && abscisseSouris() <= 6*largeurFenetre()/9 && 3*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 4 *hauteurFenetre()/9)
							zone=2;
						else
							zone=0;
						if (4*largeurFenetre()/9 <= abscisseSouris() && abscisseSouris() <= 5*largeurFenetre()/9 && hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 2*hauteurFenetre()/9)	
						{	
							zone=3;
							if(strcmp(Nom," ")!=0 && strcmp(Prenom," ")!=0 && strcmp(Nom,"")!=0 && strcmp(Prenom,"")!=0)
							{
								for(int j=0;j<4;j++)
								{
									if(strcmp(Users[j].Nom," ")==0)
									{
										strcpy(Users[j].Nom,Nom);
										strcpy(Users[j].Prenom,Prenom);
										save = fopen("Sauvegarde/save.txt","w");
										sauvegarde(save,Users,ptlang);
										break;
									}
								}
								strcpy(Nom,"");
								strcpy(Prenom,"");
							}
						}
						break;
						
					case 2:
						if (0 <= abscisseSouris() && abscisseSouris() <= largeurFenetre()/9 && 0 <= ordonneeSouris() && ordonneeSouris() <= hauteurFenetre()/18)	
							page=0;
						if (2*largeurFenetre()/18 <= abscisseSouris() && abscisseSouris() <= 3*largeurFenetre()/18 && 7*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 8*hauteurFenetre()/9)	
						{
							strcpy(Users[0].Nom," ");
							strcpy(Users[0].Prenom," ");
							for(int j=0;j<3;j++)
							{
								Users[0].Memoire[j]=0;
								Users[0].Rapidite[j]=0;
								Users[0].Lateralite[j]=0;
							}
							save = fopen("Sauvegarde/save.txt","w");
							sauvegarde(save,Users,ptlang);
						}
						if (2*largeurFenetre()/18 <= abscisseSouris() && abscisseSouris() <= 3*largeurFenetre()/18 && 5*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 6*hauteurFenetre()/9)	
						{
							strcpy(Users[1].Nom," ");
							strcpy(Users[1].Prenom," ");
							for(int j=0;j<3;j++)
							{
								Users[1].Memoire[j]=0;
								Users[1].Rapidite[j]=0;
								Users[1].Lateralite[j]=0;
							}
							save = fopen("Sauvegarde/save.txt","w");
							sauvegarde(save,Users,ptlang);
						}
						if (2*largeurFenetre()/18 <= abscisseSouris() && abscisseSouris() <= 3*largeurFenetre()/18 && 3*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 4*hauteurFenetre()/9)	
						{
							strcpy(Users[2].Nom," ");
							strcpy(Users[2].Prenom," ");
							for(int j=0;j<3;j++)
							{
								Users[2].Memoire[j]=0;
								Users[2].Rapidite[j]=0;
								Users[2].Lateralite[j]=0;
							}
							save = fopen("Sauvegarde/save.txt","w");
							sauvegarde(save,Users,ptlang);
						}
						if (2*largeurFenetre()/18 <= abscisseSouris() && abscisseSouris() <= 3*largeurFenetre()/18 && hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 2*hauteurFenetre()/9)			
						{
							strcpy(Users[3].Nom," ");
							strcpy(Users[3].Prenom," ");
							for(int j=0;j<3;j++)
							{
								Users[3].Memoire[j]=0;
								Users[3].Rapidite[j]=0;
								Users[3].Lateralite[j]=0;
							}
							save = fopen("Sauvegarde/save.txt","w");
							sauvegarde(save,Users,ptlang);
						}
						if (15*largeurFenetre()/18 <= abscisseSouris() && abscisseSouris() <= 16*largeurFenetre()/18 && 7*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 8*hauteurFenetre()/9 && strcmp(Users[0].Nom," ")!=0 && strcmp(Users[0].Prenom," ")!=0)	
						{
							i=0;
							page=3;
						}
						if (15*largeurFenetre()/18 <= abscisseSouris() && abscisseSouris() <= 16*largeurFenetre()/18 && 5*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 6*hauteurFenetre()/9 && strcmp(Users[1].Nom," ")!=0 && strcmp(Users[1].Prenom," ")!=0)	
						{
							i=1;
							page=3;
						}
						if (15*largeurFenetre()/18 <= abscisseSouris() && abscisseSouris() <= 16*largeurFenetre()/18 && 3*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 4*hauteurFenetre()/9 && strcmp(Users[2].Nom," ")!=0 && strcmp(Users[2].Prenom," ")!=0)
						{
							i=2;
							page=3;
						}	
						if (15*largeurFenetre()/18 <= abscisseSouris() && abscisseSouris() <= 16*largeurFenetre()/18 && hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 2*hauteurFenetre()/9 && strcmp(Users[3].Nom," ")!=0 && strcmp(Users[3].Prenom," ")!=0)	
						{
							i=3;
							page=3;
						}	
						break;
						
					case 3:
						if (0 <= abscisseSouris() && abscisseSouris() <= largeurFenetre()/9 && 0 <= ordonneeSouris() && ordonneeSouris() <= hauteurFenetre()/18)	
							page=2;
						if (largeurFenetre()/10 <= abscisseSouris() && abscisseSouris() <= 3*largeurFenetre()/10 && 4*hauteurFenetre()/10 <= ordonneeSouris() && ordonneeSouris() <= 6*hauteurFenetre()/10)	
							page=4;
						if (4*largeurFenetre()/10 <= abscisseSouris() && abscisseSouris() <= 6*largeurFenetre()/10 && 4*hauteurFenetre()/10 <= ordonneeSouris() && ordonneeSouris() <= 6*hauteurFenetre()/10)	
							page=5;
						if (7*largeurFenetre()/10 <= abscisseSouris() && abscisseSouris() <= 9*largeurFenetre()/10 && 4*hauteurFenetre()/10 <= ordonneeSouris() && ordonneeSouris() <= 6*hauteurFenetre()/10)	
							page=6;
						if (8*largeurFenetre()/9 <= abscisseSouris() && abscisseSouris() <= largeurFenetre() && 17*hauteurFenetre()/18 <= ordonneeSouris() && ordonneeSouris() <= hauteurFenetre())
						{	
							page=16;
							Users[i].Memoire[0]=(Users[i].Memoire[1]+Users[i].Memoire[2])/2;
							Users[i].Rapidite[0]=(Users[i].Rapidite[1]+Users[i].Rapidite[2])/2;
							Users[i].Lateralite[0]=(Users[i].Lateralite[1]+Users[i].Lateralite[2])/2;
							save = fopen("Sauvegarde/save.txt","w");
							sauvegarde(save,Users,ptlang);
						}
						break;
					
					case 4:
						if (0 <= abscisseSouris() && abscisseSouris() <= largeurFenetre()/9 && 0 <= ordonneeSouris() && ordonneeSouris() <= hauteurFenetre()/18)	
							page=3;
						if (8*largeurFenetre()/9 <= abscisseSouris() && abscisseSouris() <= largeurFenetre() && 17*hauteurFenetre()/18 <= ordonneeSouris() && ordonneeSouris() <= hauteurFenetre())
							page=7;
						if (2*largeurFenetre()/10 <= abscisseSouris() && abscisseSouris() <= 4*largeurFenetre()/10 && 4*hauteurFenetre()/10 <= ordonneeSouris() && ordonneeSouris() <= 6*hauteurFenetre()/10)	
							page=10;
						if (6*largeurFenetre()/10 <= abscisseSouris() && abscisseSouris() <= 8*largeurFenetre()/10 && 4*hauteurFenetre()/10 <= ordonneeSouris() && ordonneeSouris() <= 6*hauteurFenetre()/10)	
							page=11;
						break;
						
					case 5:
						if (0 <= abscisseSouris() && abscisseSouris() <= largeurFenetre()/9 && 0 <= ordonneeSouris() && ordonneeSouris() <= hauteurFenetre()/18)	
							page=3;
						if (8*largeurFenetre()/9 <= abscisseSouris() && abscisseSouris() <= largeurFenetre() && 17*hauteurFenetre()/18 <= ordonneeSouris() && ordonneeSouris() <= hauteurFenetre())
							page=8;
						if (2*largeurFenetre()/10 <= abscisseSouris() && abscisseSouris() <= 4*largeurFenetre()/10 && 4*hauteurFenetre()/10 <= ordonneeSouris() && ordonneeSouris() <= 6*hauteurFenetre()/10)	
							page=12;
						if (6*largeurFenetre()/10 <= abscisseSouris() && abscisseSouris() <= 8*largeurFenetre()/10 && 4*hauteurFenetre()/10 <= ordonneeSouris() && ordonneeSouris() <= 6*hauteurFenetre()/10)	
							page=13;
						break;
						
					case 6:
						if (0 <= abscisseSouris() && abscisseSouris() <= largeurFenetre()/9 && 0 <= ordonneeSouris() && ordonneeSouris() <= hauteurFenetre()/18)	
							page=3;
						if (8*largeurFenetre()/9 <= abscisseSouris() && abscisseSouris() <= largeurFenetre() && 17*hauteurFenetre()/18 <= ordonneeSouris() && ordonneeSouris() <= hauteurFenetre())
							page=9;
						if (2*largeurFenetre()/10 <= abscisseSouris() && abscisseSouris() <= 4*largeurFenetre()/10 && 4*hauteurFenetre()/10 <= ordonneeSouris() && ordonneeSouris() <= 6*hauteurFenetre()/10)	
							page=14;
						if (6*largeurFenetre()/10 <= abscisseSouris() && abscisseSouris() <= 8*largeurFenetre()/10 && 4*hauteurFenetre()/10 <= ordonneeSouris() && ordonneeSouris() <= 6*hauteurFenetre()/10)	
							page=15;
						break;
						
					case 7:
						if (0 <= abscisseSouris() && abscisseSouris() <= largeurFenetre()/9 && 0 <= ordonneeSouris() && ordonneeSouris() <= hauteurFenetre()/18)	
							page=4;
						break;
						
					case 8:
						if (0 <= abscisseSouris() && abscisseSouris() <= largeurFenetre()/9 && 0 <= ordonneeSouris() && ordonneeSouris() <= hauteurFenetre()/18)	
							page=5;
						break;
						
					case 9:
						if (0 <= abscisseSouris() && abscisseSouris() <= largeurFenetre()/9 && 0 <= ordonneeSouris() && ordonneeSouris() <= hauteurFenetre()/18)	
							page=6;
						break;
						
					case 10:	
						if(j>niveau-1 && bouton!=5)
						{
							if(abs(abscisseSouris()-4*largeurFenetre()/10)<hauteurFenetre()/10 && abs(ordonneeSouris()-13*hauteurFenetre()/20)<hauteurFenetre()/10)
								bouton=1;
							else if(abs(abscisseSouris()-6*largeurFenetre()/10)<hauteurFenetre()/10 && abs(ordonneeSouris()-13*hauteurFenetre()/20)<hauteurFenetre()/10)
								bouton=2;
							else if(abs(abscisseSouris()-4*largeurFenetre()/10)<hauteurFenetre()/10 && abs(ordonneeSouris()-7*hauteurFenetre()/20)<hauteurFenetre()/10)
								bouton=3;
							else if(abs(abscisseSouris()-6*largeurFenetre()/10)<hauteurFenetre()/10 && abs(ordonneeSouris()-7*hauteurFenetre()/20)<hauteurFenetre()/10)
								bouton=4;
							else 
								bouton=0;
						}
						else if(bouton==5)
						{
							if (0 <= abscisseSouris() && abscisseSouris() <= largeurFenetre()/9 && 0 <= ordonneeSouris() && ordonneeSouris() <= hauteurFenetre()/18)
							{	
								tmp=-250;
								page=4;
								j=-1;
								h=0;
								a=0;
								bouton=0;
								niveau=1;
								demandeTemporisation(20);
							}
						}
						break;

					case 11:	
						if(bouton!=21)
						{
							if(largeurFenetre()/11 <= abscisseSouris() && abscisseSouris() <= 2*largeurFenetre()/11 && hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 2*hauteurFenetre()/9)
								bouton=1;
							if(3*largeurFenetre()/11 <= abscisseSouris() && abscisseSouris() <= 4*largeurFenetre()/11 && hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 2*hauteurFenetre()/9)
								bouton=2;
							if(5*largeurFenetre()/11 <= abscisseSouris() && abscisseSouris() <= 6*largeurFenetre()/11 && hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 2*hauteurFenetre()/9)
								bouton=3;
							if(7*largeurFenetre()/11 <= abscisseSouris() && abscisseSouris() <= 8*largeurFenetre()/11 && hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 2*hauteurFenetre()/9)
								bouton=4;
							if(9*largeurFenetre()/11 <= abscisseSouris() && abscisseSouris() <= 10*largeurFenetre()/11 && hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 2*hauteurFenetre()/9)
								bouton=5;
							if(largeurFenetre()/11 <= abscisseSouris() && abscisseSouris() <= 2*largeurFenetre()/11 && 3*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 4*hauteurFenetre()/9)
								bouton=6;
							if(3*largeurFenetre()/11 <= abscisseSouris() && abscisseSouris() <= 4*largeurFenetre()/11 && 3*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 4*hauteurFenetre()/9)
								bouton=7;
							if(5*largeurFenetre()/11 <= abscisseSouris() && abscisseSouris() <= 6*largeurFenetre()/11 && 3*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 4*hauteurFenetre()/9)
								bouton=8;
							if(7*largeurFenetre()/11 <= abscisseSouris() && abscisseSouris() <= 8*largeurFenetre()/11 && 3*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 4*hauteurFenetre()/9)
								bouton=9;
							if(9*largeurFenetre()/11 <= abscisseSouris() && abscisseSouris() <= 10*largeurFenetre()/11 && 3*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 4*hauteurFenetre()/9)
								bouton=10;
							if(largeurFenetre()/11 <= abscisseSouris() && abscisseSouris() <= 2*largeurFenetre()/11 && 5*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 6*hauteurFenetre()/9)
								bouton=11;
							if(3*largeurFenetre()/11 <= abscisseSouris() && abscisseSouris() <= 4*largeurFenetre()/11 && 5*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 6*hauteurFenetre()/9)
								bouton=12;
							if(5*largeurFenetre()/11 <= abscisseSouris() && abscisseSouris() <= 6*largeurFenetre()/11 && 5*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 6*hauteurFenetre()/9)
								bouton=13;
							if(7*largeurFenetre()/11 <= abscisseSouris() && abscisseSouris() <= 8*largeurFenetre()/11 && 5*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 6*hauteurFenetre()/9)
								bouton=14;
							if(9*largeurFenetre()/11 <= abscisseSouris() && abscisseSouris() <= 10*largeurFenetre()/11 && 5*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 6*hauteurFenetre()/9)
								bouton=15;
							if(largeurFenetre()/11 <= abscisseSouris() && abscisseSouris() <= 2*largeurFenetre()/11 && 7*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 8*hauteurFenetre()/9)
								bouton=16;
							if(3*largeurFenetre()/11 <= abscisseSouris() && abscisseSouris() <= 4*largeurFenetre()/11 && 7*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 8*hauteurFenetre()/9)
								bouton=17;
							if(5*largeurFenetre()/11 <= abscisseSouris() && abscisseSouris() <= 6*largeurFenetre()/11 && 7*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 8*hauteurFenetre()/9)
								bouton=18;
							if(7*largeurFenetre()/11 <= abscisseSouris() && abscisseSouris() <= 8*largeurFenetre()/11 && 7*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 8*hauteurFenetre()/9)
								bouton=19;
							if(9*largeurFenetre()/11 <= abscisseSouris() && abscisseSouris() <= 10*largeurFenetre()/11 && 7*hauteurFenetre()/9 <= ordonneeSouris() && ordonneeSouris() <= 8*hauteurFenetre()/9)
								bouton=20;
							
						}
						else if(bouton==21)
						{
							if (0 <= abscisseSouris() && abscisseSouris() <= largeurFenetre()/9 && 0 <= ordonneeSouris() && ordonneeSouris() <= hauteurFenetre()/18)
							{	
								page=4;
								j=-1;
								etat=-1;
								a=0;
								bouton=0;
								niveau=1;
								tmp=-250;
							}
						}
						break;
					
					case 12:
						if(*ptt==1000)
						{
							if (0 <= abscisseSouris() && abscisseSouris() <= largeurFenetre()/9 && 0 <= ordonneeSouris() && ordonneeSouris() <= hauteurFenetre()/18)
							{	
								tmp=-250;
								h=0;
								page=5;
								breponse=0;
								etat=-1;
							}
						}
						break;
					
					case 13:
						if(*ptt==1000)
						{
							if (0 <= abscisseSouris() && abscisseSouris() <= largeurFenetre()/9 && 0 <= ordonneeSouris() && ordonneeSouris() <= hauteurFenetre()/18)
							{	
								tmp=-250;
								h=0;
								page=5;
								breponse=0;
								etat=-1;
							}
						}
						break;
					
					case 14:
						if(etat==3)
						{
							if (0 <= abscisseSouris() && abscisseSouris() <= largeurFenetre()/9 && 0 <= ordonneeSouris() && ordonneeSouris() <= hauteurFenetre()/18)
							{	
								tmp=-250;
								page=6;
								etat=-1;
								breponse=0;
								fin=0;
							}
						}
						break;
						
					case 15:
                    if (tmp>=600)
                    {


                        if(0 <= abscisseSouris() && abscisseSouris() <= largeurFenetre()/9 && 0 <= ordonneeSouris() && ordonneeSouris() <= hauteurFenetre()/18)
                        {
                            page=6;
                            tmp=-250;
                            etat=0;
                            breponse=0;



                        }
                    }
                        if (tmp<600)
                        {



                        if (13*largeurFenetre()/40<= abscisseSouris() && abscisseSouris() <= 18*largeurFenetre()/40 && 10.5*hauteurFenetre()/40 <= ordonneeSouris() && ordonneeSouris() <= 14*hauteurFenetre()/40)
                        {
                            etat=1;
                        }
                        if (22*largeurFenetre()/40 <= abscisseSouris() && abscisseSouris() <= 27*largeurFenetre()/40 && 10.5*hauteurFenetre()/40 <= ordonneeSouris() && ordonneeSouris() <= 14*hauteurFenetre()/40)
                        {
                            etat=2;
                        }
                        }


                        break;
						
					case 16:
						if (0 <= abscisseSouris() && abscisseSouris() <= largeurFenetre()/9 && 0 <= ordonneeSouris() && ordonneeSouris() <= hauteurFenetre()/18)	
							page=3;
						break;
				}
			}
			break;
		
		case Souris:
			break;
		
		case Inactivite: 
			break;
		
		case Redimensionnement: 
			printf("Largeur : %d\t", largeurFenetre());
			printf("Hauteur : %d\n", hauteurFenetre());
			break;
	}
}

