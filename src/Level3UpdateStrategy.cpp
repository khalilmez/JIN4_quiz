#include "Level3UpdateStrategy.h"
#include "Screen.h"
#include "Game.h"
#include "Menu.h"
#include "imgui.h"
#include "ImGuiWindow.h"
#include <iostream>

Screen* Level3UpdateStrategy::update(Screen &screen) {


	/* Vérifier la condition de victoire du niveau 3 ici. */
	if (screen.isCompleted() ) {

		/* Autres choses ici, si besoin  */

		/* On incrémente l'indice du niveau courant.
		Le niveau courant devient le successeur de l'ancien niveau courant.
		*/
		screen.getGame()->nextLevel();

		std::cout << "Vous etes magnifiques !" << std::endl;

		/* On retourne un poiteur vers l'ecran d'adieu :'( */
		return screen.getGame()->getMenu(Menu::BYE);

	}

	if (screen.isFailed()) {

		/* Autres choses ici, si besoin  */

		screen.setFailed(false);
		/* On retourne un poiteur vers le nouveau niveau courant (le niveau suivant). */
		return screen.getGame()->getMenu(Menu::LOSE);

	}

	/* Mises-à-jour spontanées du niveau 3 ici. */

	/* Après les modifications, on retourne un poiteur vers l'écran courant. */
	return &screen;

}
