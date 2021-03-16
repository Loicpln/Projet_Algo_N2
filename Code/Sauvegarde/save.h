#include "../lib.h"

User * creeUser(const int id, const char pseudo[], const int nbGame, const int nbWin, const int nbLose);
User * ajouteUsers(User * maUsers, User * const nouv);
User * supprimeDansUsers(User * maUsers);
User * supprimeUsers(User * maUsers);
User * rechercheUser(User * maUsers, const int id);
void enregistreUsersFichier(User * maUsers);
