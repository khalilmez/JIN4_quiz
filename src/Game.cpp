#include "Game.h"
#include "Menu.h"
#include "Screen.h"
#include "UpdateStrategy.h"
#include "EventHandler.h"

void Game::init() {

	/* Créer les niveaux, les menus, et les ajouter au jeu ici. */

	/* Ne pas oublier d'ajouter l'écran qui s'affiche (écran d'erreur) quand un écran particulier n'est pas trouvé. */
	/* Cet écran doit être associé à Menu::NOT_FOUND dans Game::menus.                                              */

	auto errorScreen = std::make_unique<Screen>();
	// Ajouter les éléments de l'écran d'erreur ici.
	menus[Menu::NOT_FOUND] = std::move(errorScreen);

	/* Premier niveau */
	auto level1 = std::make_unique<Screen>();

	//level1->addElement(std::move(std::make))

	levels.push_back(std::move(level1));

}

Screen* Game::getMenu(int id) const { 

	auto entry = menus.find(id);

	if (entry != menus.end()) {

		return entry->second.get();

	}

	return menus.find(Menu::NOT_FOUND)->second.get();

}

Screen* Game::getLevel(int id) const {

	if (id < 0 || id >= menus.size()) {

		return menus.find(Menu::NOT_FOUND)->second.get();

	}

	return levels[id].get();

}

void Game::addMenu(std::unique_ptr<Screen> menu) {

	levels.push_back(std::move(menu));

}

void Game::addLevel(std::unique_ptr<Screen> level) {

	levels.push_back(std::move(level));

}