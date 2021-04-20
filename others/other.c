
gestion(&data, fRedim());

//renvoie toutes les fonctions pour le case Redimensionnement
const Gestion fRedim() { return (const Gestion){RedimAccueil, RedimRegles, RedimMenu, RedimSelection, RedimJeu, RedimSelection, RedimJeuIA, RedimEntrainement}; }

void redimBalle(Balle *const balle)
{
	if (balle->x >= largeurFenetre())
		balle->x = largeurFenetre() - 1;
	if (balle->y >= hauteurFenetre())
		balle->y = hauteurFenetre() - 1;
}

void redimRaquette(Raquette *const raquette, const int i)
{
    if (raquette->y + raquette->longueur / 2 >= MAX_Y_PLATEAU)
        raquette->y = MAX_Y_PLATEAU - raquette->longueur / 2;
    if (raquette->y - raquette->longueur / 2 <= MIN_Y_PLATEAU)
        raquette->y = MIN_Y_PLATEAU + raquette->longueur / 2;
    raquette->x = (i % 2) ? RAQUETTE_X_RIGHT : RAQUETTE_X_LEFT;
}

//Gestion Redim page d'Accueil
void RedimAccueil(Data *const data) //Affichage page d'accueil
{
    for (int i = 0; i < MAX_BALLE; i++)
        redimBalle(data->balle + i);
}

//Gestion Redim page Menu
void RedimMenu(Data *const data)
{
    for (int i = 0; i < MAX_BALLE; i++)
        redimBalle(data->balle + i);
}

//Gestion Redim page Règles
void RedimRegles(Data *const data) {}

//Gestion Redim page Selection
void RedimSelection(Data *const data) {}

//Gestion Redim page Jeu 1v1
void RedimJeu(Data *const data)
{
    for (int i = 0; i < NB_JOUEUR; i++)
        redimRaquette(&data->joueurs[i].raquette, i);
}

//Gestion Redim page Jeu 1vIA
void RedimJeuIA(Data *const data)
{
    for (int i = 0; i < NB_JOUEUR; i++)
        redimRaquette(&data->joueurs[i].raquette, i);
}

//Gestion Redim page d'Entrainement
void RedimEntrainement(Data *const data)
{
    redimRaquette(&data->joueurs[0].raquette, 0);
}

void rouage(const Select select, const int x, const int y, const int r)
{
    EPAISSEUR_TITRE;
    couleurCourante(100, 100, 100);
    cercle(x, y, r);
    couleurCourante(select.couleur[0], select.couleur[1], select.couleur[2]);
    ligne(x - r + 5, y, x + r - 5, y);
    ligne(x - sqrt(2) * (r - 5) / 2, y - sqrt(2) * (r - 5) / 2, x + sqrt(2) * (r - 5) / 2, y + sqrt(2) * (r - 5) / 2);
    ligne(x, y - r + 5, x, y + r - 5);
    ligne(x - sqrt(2) * (r - 5) / 2, y + sqrt(2) * (r - 5) / 2, x + sqrt(2) * (r - 5) / 2, y - sqrt(2) * (r - 5) / 2);
    cercle(x, y, 11 * r / 16 - select.largeur);
    couleurCourante(100, 100, 100);
    cercle(x, y, r / 4);
    couleurCourante(select.couleur[0], select.couleur[1], select.couleur[2]);
    cercle(x, y, r / 6);
}