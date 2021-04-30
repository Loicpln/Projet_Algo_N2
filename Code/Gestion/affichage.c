#include "gestion.h"

void AfficheAccueil(Data *const data)
{
    couleurCourante(255, 0, 0);
    for (int i = 0; i < NB_BALLE; i++)
        cercle(data->balle[i].x, data->balle[i].y, data->balle[i].r);
    bouton(data->page.select[0], 30 * Ux, 65 * Uy, 70 * Ux, 80 * Uy);
    bouton(data->page.select[1], 35 * Ux, 45 * Uy, 65 * Ux, 60 * Uy);
    bouton(data->page.select[2], 75 * Ux, 5 * Uy, 95 * Ux, 15 * Uy);
    CC_BLANC;
    EPAISSEUR_TITRE;
    afficheChaine("PONG", 60, 40 * Ux, 87 * Uy);
    EPAISSEUR_3;
    afficheChaine("Jouer", 60, 40 * Ux, 68 * Uy);
    afficheChaine("Reglement", 40, 38 * Ux, 50 * Uy);
    afficheChaine("Quitter", 30, 79 * Ux, 8 * Uy);
}

void AfficheMenu(Data *const data)
{
    couleurCourante(rand() % 255, rand() % 255, rand() % 255);
    for (int i = 0; i < NB_BALLE; i++)
        cercle(data->balle[i].x, data->balle[i].y, data->balle[i].r);
    bouton(data->page.select[0], 25 * Ux, 67 * Uy, 75 * Ux, 80 * Uy); //JcJ
    bouton(data->page.select[1], 25 * Ux, 50 * Uy, 75 * Ux, 63 * Uy); //contreIA
    bouton(data->page.select[2], 25 * Ux, 33 * Uy, 75 * Ux, 46 * Uy); //entrainement
    bouton(data->page.select[3], 75 * Ux, 5 * Uy, 95 * Ux, 15 * Uy);  //Quitter
    couleurCourante(rand() % 255, rand() % 255, rand() % 255);
    EPAISSEUR_TITRE;
    afficheChaine("PONG", 60, 40 * Ux, 87 * Uy);
    CC_BLANC;
    EPAISSEUR_3;
    afficheChaine("Contre la Montre", 35, 30 * Ux, 71 * Uy);
    afficheChaine("Battle Royal", 35, 30 * Ux, 54 * Uy);
    afficheChaine("Entrainement", 35, 30 * Ux, 37 * Uy);
    afficheChaine("Retour", 30, 79 * Ux, 8 * Uy);
}

void AfficheRegles(Data *const data)
{
    bouton(data->page.select[0], 75 * Ux, 5 * Uy, 95 * Ux, 15 * Uy);
    CC_BLANC;
    EPAISSEUR_TITRE;
    afficheChaine("Reglement", 60, 31 * Ux, 79 * Uy);
    EPAISSEUR_2;
    afficheChaine("Le concept original de pong est une simulation simpliste ", 20, 10 * Ux, 58 * Uy);
    afficheChaine("de tennis de table, les deux joueurs se passent la balle ", 20, 10 * Ux, 50 * Uy);
    afficheChaine("a l'aide de raquettes, le joueur ayant le plus de points", 20, 10 * Ux, 42 * Uy);
    afficheChaine("gagne la partie.", 20, 10 * Ux, 34 * Uy);
    afficheChaine("Retour", 30, 79 * Ux, 8 * Uy);
}

void AfficheSelection(Data *const data)
{
    int teinte = (data->page.pause) ? 150 : 255;
    afficheUsers(data->page.select, data->users, teinte);
    bouton(data->page.select[id_IA], 42 * Ux, 85 * Uy, 58 * Ux, 95 * Uy);
    bouton(data->page.select[47], 87 * Ux, 85 * Uy, 95 * Ux, 95 * Uy);
    bouton(data->page.select[48], 30 * Ux, 5 * Uy, 70 * Ux, 15 * Uy);
    bouton(data->page.select[49], 75 * Ux, 5 * Uy, 95 * Ux, 15 * Uy);
    couleurCourante(0, 0, teinte);
    rectangle(2 * Ux, 6 * Uy, 14 * Ux, 14 * Uy);
    couleurCourante(teinte, 0, 0);
    rectangle(14 * Ux, 6 * Uy, 26 * Ux, 14 * Uy);
    couleurCourante(0, 0, teinte);
    cercle(14 * Ux, 12 * Uy, 2 * Uy);
    couleurCourante(teinte, 0, 0);
    cercle(14 * Ux, 8 * Uy, 2 * Uy);
    couleurCourante(teinte, teinte, teinte);
    EPAISSEUR_2;
    if (data->joueurs[0].user != NULL)
        afficheChaine(data->joueurs[0].user->pseudo, 25 - 7 * floor(strlen(data->joueurs[0].user->pseudo) / 5), 3 * Ux, 9 * Uy);
    if (data->joueurs[1].user != NULL)
        afficheChaine(data->joueurs[1].user->pseudo, 25 - 7 * floor(strlen(data->joueurs[1].user->pseudo) / 5), 17 * Ux, 9 * Uy);
    EPAISSEUR_3;
    afficheChaine("IA", 35, 48 * Ux, 88 * Uy);
    afficheChaine("Jouer", 30, 45 * Ux, 8 * Uy);
    afficheChaine("Retour", 30, 79 * Ux, 8 * Uy);
    CC_BLANC;
    plus(89 * Ux, 87 * Uy, 93 * Ux, 93 * Uy);
    couleurCourante(teinte, teinte, 0);
    epaisseurDeTrait(5);
    afficheChaine("Vs", 25, 12 * Ux, 8 * Uy);
    if (data->page.pause == 2)
        zoneText(data->page.select, data->newPseudo);
    if(data->page.pause==1)
        AfficheMutateur(data);
    rouage(data->page.select[id_Rouage], 9 * Ux, 90 * Uy, r_Rouage);
}

void AfficheJeu(Data *const data)
{
    int teinte = (data->page.pause) ? 150 : 255;
    plateau(teinte);
    for (int i = 0; i < NB_JOUEUR; i++)
        raquette(data->joueurs[i].raquette, teinte);
    EPAISSEUR_2;
    CC_BLANC;
    afficheChaine(data->joueurs[0].user->pseudo, 35, 15 * Ux, 73 * Uy);
    afficheChaine(data->joueurs[1].user->pseudo, 35, 70 * Ux, 73 * Uy);
    if (data->option.mode == ContreLaMontre)
    {
        rouage(data->page.select[id_Rouage], 88 * Ux, 90 * Uy, r_Rouage);
        timer(data->timer, MID_X, 90 * Uy);
        score(data->joueurs[0].score, 43 * Ux, 76 * Uy);
        score(data->joueurs[1].score, 61 * Ux, 76 * Uy);
    }
    else
    {
        rouage(data->page.select[id_Rouage], MID_X, 90 * Uy, r_Rouage);
        for (int i = 0; i < (data->option.nbButs - data->joueurs[1].score); i++)
            coeur(10 * Ux + 40 / data->option.nbButs * i * Ux, 92 * Uy, 3 * Ux);
        for (int i = 0; i < (data->option.nbButs - data->joueurs[0].score); i++)
            coeur(90 * Ux - 40 / data->option.nbButs * i * Ux, 92 * Uy, 3 * Ux);
    }
    balle(data->balleJeu, teinte);
    if (data->page.pause)
        affichePause(data->page.select);
}

void AfficheEntrainement(Data *const data)
{
    CC_BLANC;
    EPAISSEUR_TITRE;
    afficheChaine("Entrainement", 70, 20 * Ux, 88 * Uy);
    rouage(data->page.select[id_Rouage], 88 * Ux, 90 * Uy, r_Rouage);
    int teinte = (data->page.pause) ? 150 : 255;
    plateau(teinte);
    raquette(data->joueurs[0].raquette, teinte);
    balle(data->balleJeu, teinte);
    if (data->page.pause)
        affichePause(data->page.select);
}

void AfficheResultats(Data *const data)
{
    int teinte = (data->page.pause) ? 150 : 255;
    bouton(data->page.select[0], 30 * Ux, 20 * Uy, 70 * Ux, 30 * Uy);
    bouton(data->page.select[1], 30 * Ux, 5 * Uy, 70 * Ux, 15 * Uy);
    rouage(data->page.select[id_Rouage], 12 * Ux, 90 * Uy, r_Rouage);
    couleurCourante(teinte, teinte, teinte);
    EPAISSEUR_3;
    afficheChaine("Rejouer", 30, 43 * Ux, 23 * Uy);
    afficheChaine("Retour au Menu", 30, 33 * Ux, 8 * Uy);
}
// sous traitance
void AfficheMutateur(Data *const data)
{
    
    // TEXTE MUTATEUR
    couleurCourante(0, 0, 0);
    bouton(data->page.select[35],5*Ux,5*Uy,95*Ux,MAX_Y);
    couleurCourante(255, 255, 255);
    epaisseurDeTrait(6);
    afficheChaine("MUTATEUR", 60, 4 * largeurFenetre() / 14, 10.2* hauteurFenetre() / 12);
    
    // RECTANGLE VITESSE BALLE
    couleurCourante(140, 20, 20);
    rectangle(1.5 * largeurFenetre() / 14, 9 * hauteurFenetre() / 12, 6 * largeurFenetre() / 14, 7.5 * hauteurFenetre() / 12);
    epaisseurDeTrait(3);
    couleurCourante(255, 190, 180);
    afficheChaine("Vitesse balle", 40, 1.5 * largeurFenetre() / 14, 8 * hauteurFenetre() / 12);
    
    //RECTANGLE TAILLE BALLE
    couleurCourante(140, 20, 20);
    rectangle(8 * largeurFenetre() / 14, 9 * hauteurFenetre() / 12, 12.5 * largeurFenetre() / 14, 7.5 * hauteurFenetre() / 12);
    epaisseurDeTrait(3);
    couleurCourante(255, 190, 180);
    afficheChaine("Taille balle", 40, 8.8 * largeurFenetre() / 14, 8 * hauteurFenetre() / 12);
    
    // RECTANGLE TAILLE RAQUETTE
    couleurCourante(140, 20, 20);
    rectangle(1.5 * largeurFenetre() / 14, 4.1 * hauteurFenetre() / 12, 6.5 * largeurFenetre() / 14, 1.3 * hauteurFenetre() / 6);
    epaisseurDeTrait(3);
    couleurCourante(255, 190, 180);
    afficheChaine("Taille raquette", 40, 2 * largeurFenetre() / 14, 3.1 * hauteurFenetre() / 12);
    
    // RECTANGLE S M L
    couleurCourante(190, 70, 70);
    rectangle(1.5 * largeurFenetre() / 14, 1 * hauteurFenetre() / 12, 7 * largeurFenetre() / 14, 1 * hauteurFenetre() / 6);
    couleurCourante(0, 0, 0);
	epaisseurDeTrait(3);
	ligne(2.83 * largeurFenetre()/12, hauteurFenetre() / 12, 2.83 * largeurFenetre()/12, hauteurFenetre()/6);
	couleurCourante(0, 0, 0);
	epaisseurDeTrait(3);
	ligne(4.425 * largeurFenetre()/12, hauteurFenetre() / 12, 4.425 * largeurFenetre()/12, hauteurFenetre()/6);
	couleurCourante(255, 190, 180);
    afficheChaine("S", 30, 6.5 * largeurFenetre() / 40, 1.08 * hauteurFenetre() / 10);
    couleurCourante(150,56,53);
    couleurCourante(255, 190, 180);
    afficheChaine("M", 30, 11.65 * largeurFenetre() / 40, 1.08 * hauteurFenetre() / 10);
    couleurCourante(150,56,53);
    couleurCourante(255, 190, 180);
    afficheChaine("L", 30, 17.07 * largeurFenetre() / 40, 1.08 * hauteurFenetre() / 10);
    couleurCourante(150,56,53);

    // FONCTION AFFICHAGE DES SLIDERS

	couleurCourante(168,168,168);
	rectangle(absBar1, 6.1 * hauteurFenetre() / 12, 6 * largeurFenetre() / 14, 6 * hauteurFenetre() / 12);
	couleurCourante(255,0,0);
	
	couleurCourante(168,168,168);
	rectangle(absBar2, 6.1 * hauteurFenetre() / 12, 12.5 * largeurFenetre() / 14, 6 * hauteurFenetre() / 12);
	couleurCourante(255,0,0);

    
    // FONCTION AFFICHAGE CURSEUR GAUCHE

	triangle(1.3 * largeurFenetre() / 14+ data->option.triangle1, 6.5 * hauteurFenetre() / 12, 1.5 * largeurFenetre() / 14+data->option.triangle1, 6 * hauteurFenetre() / 12, 1.7 * largeurFenetre() / 14+data->option.triangle1, 6.5 * hauteurFenetre() / 12);


    // FONCTION AFFICHAGE CURSEUR DROITE


	triangle(7.8 * largeurFenetre() / 14+data->option.triangle2, 6.5 * hauteurFenetre() / 12, 8 * largeurFenetre() / 14+data->option.triangle2, 6 * hauteurFenetre() / 12, 8.2 * largeurFenetre() / 14+data->option.triangle2, 6.5 * hauteurFenetre() / 12);


}









