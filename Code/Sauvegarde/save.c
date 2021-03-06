#include "save.h"

User *creeUser(char pseudo[20], int nbGame, int nbWin, int nbLose)
{
    User *elem = malloc(sizeof(User));
    strcpy(elem->pseudo, pseudo);
    elem->nbGame = nbGame;
    elem->nbWin = nbWin;
    elem->nbLose = nbLose;
    elem->userSuivant = NULL;
    return elem;
}

User *ajouteUsers(User *maUsers, User *nouv)
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

User *supprimeDansUsers(User *maUsers)
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

User *supprimeUsers(User *maUsers)
{
    while (maUsers != NULL)
    {
        User *tmp = maUsers;
        maUsers = maUsers->userSuivant;
        free(tmp);
    }
    return maUsers;
}

User *rechercheUser(User *maUsers, char nom[20])
{
    User *tmp = maUsers;
    while (tmp != NULL)
    {
        if (!strcmp(tmp->pseudo, nom))
            break;
        tmp = tmp->userSuivant;
    }
    return tmp;
}

void enregistreUsersFichier(User *maUsers)
{
    FILE *file = fopen("Users.txt", "w");
    User *tmp = maUsers;
    if (file != NULL)
    {
        while (tmp != NULL)
        {
            fprintf(file, "[pseudo=%s |nbGame=%d |nbWin=%d |nbLose=%d]\n", tmp->pseudo, tmp->nbGame, tmp->nbWin, tmp->nbLose);
            tmp = tmp->userSuivant;
        }
        fclose(file);
    }
}

void chargeUsersDepuisFichier(User * maUsers)
{
    FILE *file = fopen("Users.txt", "r");
    char pseudo[25];
    int nbGame, nbWin, nbLose;
    if (file != NULL)
    {
        while (fgetc(file) != EOF)
        {
            fscanf(file, "pseudo=%s |nbGame=%d |nbWin=%d |nbLose=%d]\n", pseudo, &nbGame, &nbWin, &nbLose);
            maUsers = ajouteUsers(maUsers, creeUser(pseudo, nbGame, nbWin, nbLose));
        }
        fclose(file);
    }
}