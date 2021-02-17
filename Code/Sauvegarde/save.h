#include "../lib.h"

User * creeUser(char nom[20]);
Users * ajouteUsers(Users * maUsers, User * nouv);
Users * supprimeDansUsers(Users * maUsers);
Users * supprimeUsers(Users * maUsers);
User *rechercheUser(Users *maUsers, char nom[20]);
void enregistreUsersFichier(Users * maUsers);
Users * chargeUsersDepuisFichier();
