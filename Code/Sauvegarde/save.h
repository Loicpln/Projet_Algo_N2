#include "../lib.h"

User *creeUser(const int id, const char pseudo[], const int nbGame, const int nbWin, const int nbLose);
Users *ajouteUsers(Users *users, User *const nouv);
Users *supprimeDansUsers(Users *users, const int id);
Users *changeId(Users *users);
int compteUsers(Users *users);
User *rechercheUser(Users *users, const int id);
void enregistreUsersFichier(Users *users);
