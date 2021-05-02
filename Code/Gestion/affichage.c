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
    couleurCourante(teinte, teinte, 0);
    epaisseurDeTrait(5);
    afficheChaine("Vs", 25, 12 * Ux, 8 * Uy);
    if (data->page.pause == 2)
        zoneText(data->page.select, data->newPseudo);
    if(data->page.pause==1)
        AfficheMutateur(data);
    rouage(data->page.select[id_Rouage], 9 * Ux, 90 * Uy, r_Rouage);
    bouton(data->page.select[47], 87 * Ux, 85 * Uy, 95 * Ux, 95 * Uy);
    CC_BLANC;
    plus(89 * Ux, 87 * Uy, 93 * Ux, 93 * Uy);
}

void AfficheJeu(Data *const data)
{
    int teinte =  (!data->page.pause) ? 255 : 150;
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

    if (data->page.pause == 2)
    {
        AfficheMutateur(data);
        rouage(data->page.select[id_Rouage], 88 * Ux, 90 * Uy, r_Rouage);
    }
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
    if (data->page.pause == 2)
    {
        AfficheMutateur(data);
        rouage(data->page.select[id_Rouage], 88 * Ux, 90 * Uy, r_Rouage);
    }
    else if (data->page.pause)
    {
        affichePause(data->page.select);
        rouage(data->page.select[id_Rouage], 88 * Ux, 90 * Uy, r_Rouage);
    }        
}

void AfficheResultats(Data *const data)
{
    char Game[10] = "", Win[10] = "", Lose[10] = "";
    int teinte = (data->page.pause) ? 150 : 255;
    bouton(data->page.select[0], 30 * Ux, 20 * Uy, 70 * Ux, 30 * Uy);
    bouton(data->page.select[1], 30 * Ux, 5 * Uy, 70 * Ux, 15 * Uy);
   
    EPAISSEUR_2;
    couleurCourante(teinte, teinte, teinte); 

    afficheChaine(data->joueurs[0].user->pseudo, 30, 15 * Ux, 73 * Uy);
    if (data->joueurs[0].user->nbGame < 2)
    {
        sprintf(Game, "%d Game ", data->joueurs[0].user->nbGame);
    }
    else  
    {
        sprintf(Game, "%d Games ", data->joueurs[0].user->nbGame);
    }
    

    if (data->joueurs[0].user->nbWin < 2)
    {
        sprintf(Win, "%d Win ", data->joueurs[0].user->nbWin);
    }
    else  
    {
        sprintf(Win, "%d Wins ", data->joueurs[0].user->nbWin);
    }

    if (data->joueurs[0].user->nbLose < 2)
    {
        sprintf(Lose, "%d Lose ", data->joueurs[0].user->nbLose);
    }
    else 
    {
        sprintf(Lose, "%d Loses ", data->joueurs[0].user->nbLose);
    }

    afficheChaine(Game, 20, 15 * Ux, 60 * Uy );
    afficheChaine(Win, 20, 15 * Ux, 50 * Uy );
    afficheChaine(Lose, 20, 15 * Ux, 40 * Uy ); 
    
    
    
    
    
    afficheChaine(data->joueurs[1].user->pseudo, 30, 70 * Ux, 73 * Uy);
    if (data->joueurs[1].user->nbGame < 2)
    {
        sprintf(Game, "%d Game ", data->joueurs[1].user->nbGame);
    }
    else  
    {
        sprintf(Game, "%d Games ", data->joueurs[1].user->nbGame);
    }

    if (data->joueurs[1].user->nbWin < 2)
    {
        sprintf(Win, "%d Win ", data->joueurs[1].user->nbWin);
    }
    else  
    {
        sprintf(Win, "%d Wins ", data->joueurs[1].user->nbWin);
    }

    if (data->joueurs[1].user->nbLose < 2)
    {
        sprintf(Lose, "%d Lose ", data->joueurs[1].user->nbLose);
    }
    else 
    {
        sprintf(Lose, "%d Loses ", data->joueurs[1].user->nbLose);
    }

    afficheChaine(Game, 20, 70 * Ux, 60 * Uy );
    afficheChaine(Win, 20, 70 * Ux, 50 * Uy );
    afficheChaine(Lose, 20, 70 * Ux, 40 * Uy ); 


    
    EPAISSEUR_3;
    afficheChaine("Rejouer", 30, 43 * Ux, 23 * Uy);
    afficheChaine("Retour au Menu", 30, 33 * Ux, 8 * Uy);
}











