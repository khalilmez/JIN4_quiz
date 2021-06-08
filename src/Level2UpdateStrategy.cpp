#include "Level2UpdateStrategy.h"
#include "Screen.h"
#include "Game.h"

Screen* Level2UpdateStrategy::update(Screen &screen) {

	/* Vérifier la condition de victoire du niveau 1 ici. */
	if (screen.isCompleted() ) {

		/* Autres choses ici, si besoin  */

		/* On incrémente l'indice du niveau courant.
		Le niveau courant devient le successeur de l'ancien niveau courant.
		*/
		screen.getGame()->nextLevel();

		/* On retourne un poiteur vers le nouveau niveau courant (le niveau suivant). */
		return screen.getGame()->getCurrentLevel();

	}

	/* Mises-à-jour spontanées du niveau 1 ici. */

	/* Après les modifications, on retourne un poiteur vers l'écran courant. */
	return &screen;

}
