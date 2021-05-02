#include "moteur.h"
//Création des utilisateurs
User *creeUser(const int id, const char *const pseudo, const int nbGame, const int nbWin, const int nbLose)
{
    User *elem = malloc(sizeof(User));
    elem->id = id;
    strcpy(elem->pseudo, pseudo);
    elem->nbGame = nbGame;
    elem->nbWin = nbWin;
    elem->nbLose = nbLose;
    elem->userSuivant = NULL;
    return elem;
}
//Ajout des utilisateurs
Users *ajouteUsers(Users *users, User *const nouv)
{
    if (users->premier == NULL)
        users->premier = nouv;
    else
    {
        User *tmp = users->premier;
        while (tmp->userSuivant != NULL)
            tmp = tmp->userSuivant;
        tmp->userSuivant = nouv;
    }
    users = changeId(users);
    return users;
}
//Suppression des utilisateurs
Users *supprimeDansUsers(Users *users, const int id)
{
    User *tmp = users->premier;
    User *ptmp = users->premier;
    if (users->premier->id == id)
        users->premier = users->premier->userSuivant;
    else
    {
        for (; tmp != NULL && tmp->id != id; ptmp = tmp, tmp = tmp->userSuivant)
        {
        }
        ptmp->userSuivant = tmp->userSuivant;
    }
    users = changeId(users);
    return users;
}
//Changement de l'ID des utilisateurs lors de la suppression
Users *changeId(Users *users)
{
    User *tmp = users->premier;
    int i = 0;
    for (; tmp != NULL; tmp = tmp->userSuivant)
        tmp->id = i++;
    return users;
}
//Recherche des joueurs
User *rechercheUser(Users *users, const int id)
{
    User *tmp = users->premier;
    for (; tmp != NULL && tmp->id != id; tmp = tmp->userSuivant)
    {
    }
    return tmp;
}
//Compte le nombre d'utilisateurs
int compteUsers(Users *users)
{
    User *tmp = users->premier;
    int i = 0;
    for (; tmp != NULL; tmp = tmp->userSuivant)
        i++;
    return i;
}
//Enregistre les utilisateurs dans le fichier texte
void enregistreUsersFichier(Users *users)
{
    FILE *file = fopen("./Sauvegarde/Users.txt", "w");
    User *tmp = users->premier;
    if (file != NULL)
    {
        for (; tmp != NULL; tmp = tmp->userSuivant)
            fprintf(file, "[id=%d |pseudo=%s |nbGame=%d |nbWin=%d |nbLose=%d]\n", tmp->id, tmp->pseudo, tmp->nbGame, tmp->nbWin, tmp->nbLose);
        fclose(file);
    }
}