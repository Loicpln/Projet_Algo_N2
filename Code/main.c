#include "controleur.h"

//page 0 = Ecran d'accueil
//page 1 = Ecran Jouer
//////Sous-page 0 = joueur contre joueur
//////Sous-page 1 = jeu contre IA
//////Sous-page 2 = page entrainement
//page 2 = Reglement

int main(int argc, char **argv)
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	Mix_Music *musique;
	musique = Mix_LoadMUS("Musique/videogame.wav");
	Mix_PlayMusic(musique, -1);
	
	initialiseGfx(argc, argv);
	prepareFenetreGraphique("Pong", LargeurFenetre, HauteurFenetre);
	lanceBoucleEvenements();

	return 0;
}

void gestionEvenement(EvenementGfx evenement)
{
	static Data d;
	Data *data = &d;

	switch (evenement)
	{
	case Initialisation:
		d = init();
		demandeTemporisation(20);
		break;

	case Temporisation:
		gestion(data, fTempo());
		rafraichisFenetre();
		break;

	case Affichage:
		effaceFenetre(0, 0, 0);
		gestion(data, fAffiche());
		break;

	case Clavier:
		gestion(data, fClavier());
		break;

	case ClavierSpecial:
		break;

	case BoutonSouris:
		gestion(data, fClic());
		break;

	case Souris:
		break;

	case Inactivite:
		break;

	case Redimensionnement:
		gestion(data, fRedim());
		break;
	}
}
