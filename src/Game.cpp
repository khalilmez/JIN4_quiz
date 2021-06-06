#include "Game.h"

void Game::init() {

	/* Créer les niveaux, les menus, et les ajouter au jeu ici. */

}

Screen* Game::getMenu(int id) const { 

	auto entry = menus.find(id);

	if (entry != menus.end()) {

		// TODO

	}

}