#include "Level1UpdateStrategy.h"
#include "Screen.h"
Screen* Level1UpdateStrategy::update(Screen &screen) {

	/* Vérifier la condition de victoire du niveau 1 ici. */
	if (screen.isCompleted() ) {

	}
	return &screen;

	/* Mises-à-jour spontanées du niveau 1 ici. */

}