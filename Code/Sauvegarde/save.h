#include "../lib.h"

User * creeUser(char pseudo[20],int nbGame, int nbWin, int nbLose);
User * ajouteUsers(User * maUsers, User * nouv);
User * supprimeDansUsers(User * maUsers);
User * supprimeUsers(User * maUsers);
User *rechercheUser(User *maUsers, char nom[20]);
void enregistreUsersFichier(User * maUsers);
void chargeUsersDepuisFichier(User * maUsers);
