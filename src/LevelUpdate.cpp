#include "LevelUpdate.h"
#include "Screen.h"
#include "Game.h"
#include "Menu.h"

Screen* LevelUpdate::update(Screen &screen) {

	/* Vérifier la condition de victoire du niveau 2 ici. */
	if (screen.isCompleted() ) {

		/* Autres choses ici, si besoin  */

		/* On incrémente l'indice du niveau courant.
		Le niveau courant devient le successeur de l'ancien niveau courant.
		*/
		screen.getGame()->nextLevel();

		if (screen.getGame()->hasNextLevel()) {
			return screen.getGame()->getMenu(Menu::WIN);
		}
		return screen.getGame()->getMenu(Menu::BYE);

	}
	else if (screen.isFailed()) {

		screen.setFailed(false);

		return screen.getGame()->getMenu(Menu::LOSE);

	}

	return &screen;

}
