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

Users *ajouteUsers(Users *maUsers, User *nouv)
{
    if (maUsers == NULL)
    {
        maUsers = malloc(sizeof(Users));
        maUsers->premier = nouv;
    }
    else if (maUsers->premier == NULL)
    {
        maUsers->premier = nouv;
    }
    else
    {
        User *tmp = maUsers->premier;
        while (tmp->userSuivant != NULL)
        {
            tmp = tmp->userSuivant;
        }
        tmp->userSuivant = nouv;
    }
    return maUsers;
}

Users *supprimeDansUsers(Users *maUsers)
{
    if (maUsers->premier != NULL)
    {
        User *tmp = maUsers->premier;
        User *ptmp = maUsers->premier;
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

Users *supprimeUsers(Users *maUsers)
{
    while (maUsers->premier != NULL)
    {
        User *tmp = maUsers->premier;
        maUsers->premier = maUsers->premier->userSuivant;
        free(tmp);
    }
    return maUsers;
}

User *rechercheUser(Users *maUsers, char nom[20])
{
    User *tmp = maUsers->premier;
    while (tmp != NULL)
    {
        if (!strcmp(tmp->pseudo, nom))
            break;
        tmp = tmp->userSuivant;
    }
    return tmp;
}

void enregistreUsersFichier(Users *maUsers)
{
    FILE *file = fopen("Users.txt", "w");
    User *tmp = maUsers->premier;
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

Users chargeUsersDepuisFichier()
{
    Users *maUsers = NULL;
    FILE *file = fopen("Users.txt", "r");
    char pseudo[25];
    int nbGame, nbWin, nbLose;
    if (file != NULL)
    {
        fseek(file, 0, SEEK_END);
        if (ftell(file) != 0)
        {
            fseek(file, 0, SEEK_SET);
            while (!feof(file))
            {
                fscanf(file, "[pseudo=%s |nbGame=%d |nbWin=%d |nbLose=%d]\n", pseudo, &nbGame, &nbWin, &nbLose);
                maUsers = ajouteUsers(maUsers, creeUser(pseudo, nbGame, nbWin, nbLose));
            }
        }
        else
        {
            maUsers = malloc(sizeof(Users));
        }
        fclose(file);
    }
    return *maUsers;
}