#include "save.h"

User *creeUser(char nom[20])
{
    User *elem = malloc(sizeof(User));
    strcpy(elem->pseudo, nom);
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
    Users *Users = fopen("Users.txt", "w");
    User *tmp = maUsers->premier;
    if (Users != NULL)
    {
        while (tmp != NULL)
        {
            fprintf(Users, "[pseudo=%s]\n", tmp->pseudo);
            tmp = tmp->userSuivant;
        }
        fclose(Users);
    }
}

Users *chargeUsersDepuisFichier()
{
    Users *maUsers = NULL;
    Users *Users = fopen("Users.txt", "r");
    char nom[20];
    int id;
    if (Users != NULL)
    {
        fseek(Users, 0, SEEK_END);
        unsigned long int taille = ftell(Users);
        if (taille != 0)
        {
            fseek(Users, 0, SEEK_SET);
            while (!feof(Users))
            {
                fscanf(Users, "[pseudo=%s]\n", nom);
                maUsers = ajouteUsers(maUsers, creeUser(nom));
            }
        }
        else
        {
            return NULL;
        }
        fclose(Users);
    }
    return maUsers;
}