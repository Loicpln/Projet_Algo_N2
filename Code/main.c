#include "controleur.h"

//page 0 = Ecran d'accueil
//page 1 = Ecran Jouer
//////case 1 = joueur contre joueur
//////case 2 = jeu contre IA
//////case 3 = page entrainement
//page 2 = Reglement

int main(int argc, char **argv)
{
	/*SDL_Init(SDL_INIT_AUDIO);
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	Mix_Music *musique;
	musique = Mix_LoadMUS("Musique/videogame.mp3");
	Mix_PlayMusic(musique, -1);*/

	initialiseGfx(argc, argv);
	prepareFenetreGraphique("Pong", LargeurFenetre, HauteurFenetre);
	lanceBoucleEvenements();

	return 0;
}

void gestionEvenement(EvenementGfx evenement)
{
	static Data data;

	switch (evenement)
	{
	case Initialisation:
		data = init();
		for (int i = 0; i < MAX_BALLE; i++)
			data.balle[i] = initBallesAccueil();
		activeGestionDeplacementPassifSouris();
		demandeTemporisation(20);
		break;

	case Temporisation:
		gestion(&data, fTempo());
		rafraichisFenetre();
		break;

	case Affichage:
		effaceFenetre(0, 0, 0);
		gestion(&data, fAffiche());
		//GRILLE;
		break;

	case Clavier:
		gestion(&data, fClavier());
		break;

	case ClavierSpecial:
		break;

	case BoutonSouris:
		gestion(&data, fClic());
		break;

	case Souris:
		break;

	case Inactivite:
		break;

	case Redimensionnement:
		break;
	}
}
