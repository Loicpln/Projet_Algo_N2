#include "../lib.h"

User * creeUser(const char pseudo[], const int nbGame, const int nbWin, const int nbLose);
User * ajouteUsers(User * maUsers, User * const nouv);
User * supprimeDansUsers(User * maUsers);
User * supprimeUsers(User * maUsers);
User * rechercheUser(User * maUsers, const char pseudo[]);
void enregistreUsersFichier(User * maUsers);
