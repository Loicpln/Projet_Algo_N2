#include "save.h"

User * creeUser(const int id, const char pseudo[], const int nbGame, const int nbWin, const int nbLose)
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

User * ajouteUsers(User * maUsers, User * const nouv)
{
    if (maUsers == NULL)
    {
        maUsers = malloc(sizeof(User));
        maUsers = nouv;
    }
    else if (maUsers == NULL)
    {
        maUsers = nouv;
    }
    else
    {
        User *tmp = maUsers;
        while (tmp->userSuivant != NULL)
        {
            tmp = tmp->userSuivant;
        }
        tmp->userSuivant = nouv;
    }
    return maUsers;
}

User * supprimeDansUsers(User *maUsers)
{
    if (maUsers != NULL)
    {
        User *tmp = maUsers;
        User *ptmp = maUsers;
        while (tmp->userSuivant != NULL)
        {
            ptmp = tmp;
            tmp = tmp->userSuivant;
        }
        ptmp->userSuivant = NULL;
        free(tmp);
    }
    return maUsers;
}

User * supprimeUsers(User *maUsers)
{
    while (maUsers != NULL)
    {
        User *tmp = maUsers;
        maUsers = maUsers->userSuivant;
        free(tmp);
    }
    return maUsers;
}

User * rechercheUser(User * maUsers, const int id)
{
    User * tmp = maUsers;
    while (tmp != NULL)
    {
        if (tmp->id == id)
            break;
        tmp = tmp->userSuivant;
    }
    return tmp;
}

void enregistreUsersFichier(User * maUsers)
{
    FILE *file = fopen("./Sauvegarde/Users.txt", "w");
    User *tmp = maUsers;
    if (file != NULL)
    {
        while (tmp != NULL)
        {
            fprintf(file, "[id=%d |pseudo=%s |nbGame=%d |nbWin=%d |nbLose=%d]\n",tmp->id, tmp->pseudo, tmp->nbGame, tmp->nbWin, tmp->nbLose);
            tmp = tmp->userSuivant;
        }
        fclose(file);
    }
}