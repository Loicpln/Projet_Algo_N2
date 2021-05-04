#include "gestion.h"

//Ensemble des fonctions d'affichage

void AfficheAccueil(Data *const data)
{
    couleurCourante(255, 0, 0);

    for (int i = 0; i < NB_BALLE; i++) // Balles en arrière plan
        cercle(data->balle[i].x, data->balle[i].y, data->balle[i].r);
    bouton(data->page.select[0], 30 * Ux, 65 * Uy, 70 * Ux, 80 * Uy); // Jouer
    bouton(data->page.select[1], 35 * Ux, 45 * Uy, 65 * Ux, 60 * Uy); // Reglement
    bouton(data->page.select[2], 75 * Ux, 5 * Uy, 95 * Ux, 15 * Uy);  // Retour
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

    for (int i = 0; i < NB_BALLE; i++) // Balles en arrière plan
        cercle(data->balle[i].x, data->balle[i].y, data->balle[i].r);
    bouton(data->page.select[0], 25 * Ux, 67 * Uy, 75 * Ux, 80 * Uy); // Contre la montre
    bouton(data->page.select[1], 25 * Ux, 50 * Uy, 75 * Ux, 63 * Uy); // Battle royal
    bouton(data->page.select[2], 25 * Ux, 33 * Uy, 75 * Ux, 46 * Uy); // Entrainement
    bouton(data->page.select[3], 75 * Ux, 5 * Uy, 95 * Ux, 15 * Uy);  // Retour
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
    bouton(data->page.select[0], 75 * Ux, 5 * Uy, 95 * Ux, 15 * Uy); // Retour
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
    bouton(data->page.select[id_IA], 42 * Ux, 85 * Uy, 58 * Ux, 95 * Uy); // IA
    bouton(data->page.select[48], 30 * Ux, 5 * Uy, 70 * Ux, 15 * Uy);     // Jouer
    bouton(data->page.select[49], 75 * Ux, 5 * Uy, 95 * Ux, 15 * Uy);     // Retour
    // Affichage des joueurs
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
    for (int i = 0; i < NB_JOUEUR; i++)
        if (data->joueurs[i].user != NULL)
            afficheChaine(data->joueurs[i].user->pseudo, 25 - 7 * floor(strlen(data->joueurs[i].user->pseudo) / 5), 3 * Ux + i * 14 * Ux, 9 * Uy);
    EPAISSEUR_3;
    afficheChaine("IA", 35, 48 * Ux, 88 * Uy);
    afficheChaine("Jouer", 30, 45 * Ux, 8 * Uy);
    afficheChaine("Retour", 30, 79 * Ux, 8 * Uy);
    couleurCourante(teinte, teinte, 0);
    epaisseurDeTrait(5);
    afficheChaine("Vs", 25, 12 * Ux, 8 * Uy);
    //Selon l'état de la pause les elements supplémentaires sont affichées
    if (data->page.pause == 2)
        zoneText(data->page.select, data->newPseudo);
    if (data->page.pause == 1)
        AfficheMutateur(data);
    rouage(data->page.select[id_Rouage], 9 * Ux, 90 * Uy, r_Rouage);
    bouton(data->page.select[47], 87 * Ux, 85 * Uy, 95 * Ux, 95 * Uy); // Affichage du bouton de l'ajout d'utilisateur
    CC_BLANC;
    EPAISSEUR_TITRE;
    plus(89 * Ux, 87 * Uy, 93 * Ux, 93 * Uy);
}

void AfficheJeu(Data *const data)
{
    int teinte = (!data->page.pause) ? 255 : 150;
    plateau(teinte);
    for (int i = 0; i < NB_JOUEUR; i++)
        raquette(data->joueurs[i].raquette, teinte);
    EPAISSEUR_2;
    CC_BLANC;
    for (int i = 0; i < NB_JOUEUR; i++) // Affiche le nom des joueurs
        afficheChaine(data->joueurs[i].user->pseudo, 35, 15 * Ux + i * 55 * Ux, 73 * Uy);
    if (data->option.mode == ContreLaMontre)
    {
        rouage(data->page.select[id_Rouage], 88 * Ux, 90 * Uy, r_Rouage);
        timer(data->timer, MID_X, 90 * Uy);
        for (int i = 0; i < NB_JOUEUR; i++) // Affiche le score
            score(data->joueurs[i].score, 43 * Ux + i * 18 * Ux, 76 * Uy);
    }
    else
    {
        rouage(data->page.select[id_Rouage], MID_X, 90 * Uy, r_Rouage);
        for (int i = 0; i < NB_JOUEUR; i++) // Affiche le nombre de coeur restant
            for (int j = 0; j < (data->option.nbButs - data->joueurs[i].score); j++)
                coeur((i) ? (10 * Ux + 7 * (j % 5) * Ux) : (90 * Ux - 7 * (j % 5) * Ux), 89 * Uy + 7 * floor(j / 5) * Uy, 3 * Ux);
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
    int teinte = (data->page.pause) ? 150 : 255;
    CC_BLANC;
    EPAISSEUR_TITRE;
    afficheChaine("Entrainement", 70, 20 * Ux, 88 * Uy);
    rouage(data->page.select[id_Rouage], 88 * Ux, 90 * Uy, r_Rouage);
    plateau(teinte);
    raquette(data->joueurs[0].raquette, teinte);
    balle(data->balleJeu, teinte);
    if (data->page.pause)
        affichePause(data->page.select);
    else if (data->page.pause == 2)
        AfficheMutateur(data);
    rouage(data->page.select[id_Rouage], 88 * Ux, 90 * Uy, r_Rouage);
}

void AfficheResultats(Data *const data)
{
    char Game[10] = "", Win[10] = "", Lose[10] = "";
    bouton(data->page.select[0], 30 * Ux, 20 * Uy, 70 * Ux, 30 * Uy); // Rejouer
    bouton(data->page.select[1], 30 * Ux, 5 * Uy, 70 * Ux, 15 * Uy);  // Retour au menu
    CC_BLANC;
    ligne(MID_X, 80 * Uy, MID_X, 35 * Uy);
    for (int i = 0; i < NB_JOUEUR; i++)
    {
        score(data->joueurs[i].score, 43 * Ux + i * 18 * Ux, 76 * Uy);
        EPAISSEUR_2;
        CC_BLANC;
        afficheChaine(data->joueurs[i].user->pseudo, 30, 15 * Ux + i * 55 * Ux, 73 * Uy);
        (data->joueurs[i].user->nbGame < 2) ? sprintf(Game, "%d Game", data->joueurs[i].user->nbGame)
                                            : sprintf(Game, "%d Games", data->joueurs[i].user->nbGame);
        (data->joueurs[i].user->nbWin < 2) ? sprintf(Win, "%d Win", data->joueurs[i].user->nbWin)
                                           : sprintf(Win, "%d Wins", data->joueurs[i].user->nbWin);
        (data->joueurs[i].user->nbLose < 2) ? sprintf(Lose, "%d Lose", data->joueurs[i].user->nbLose)
                                            : sprintf(Lose, "%d Loses", data->joueurs[i].user->nbLose);
        afficheChaine(Game, 20, 15 * Ux + i * 55 * Ux, 60 * Uy);
        afficheChaine(Win, 20, 15 * Ux + i * 55 * Ux, 50 * Uy);
        afficheChaine(Lose, 20, 15 * Ux + i * 55 * Ux, 40 * Uy);
    }
    EPAISSEUR_3;
    afficheChaine("Rejouer", 30, 43 * Ux, 23 * Uy);
    afficheChaine("Retour au Menu", 30, 33 * Ux, 8 * Uy);
}
