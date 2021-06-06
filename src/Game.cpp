#include "Game.h"
#include "Menu.h"
#include "Screen.h"
#include "UpdateStrategy.h"
#include "EventHandler.h"
#include "Text.h"
#include <iostream>
#include "Level1EventHandler.h"
#include "Level1UpdateStrategy.h"

void Game::init() {

	/* Positionne l'indice du niveau actuel 
	à 0 (premier niveau).
	*/
	currentLevel = 0;

	/* Créer les niveaux, les menus, et les ajouter au jeu ici. */

	/* Ne pas oublier d'ajouter l'écran qui s'affiche (écran d'erreur) quand un écran particulier n'est pas trouvé. */
	/* Cet écran doit être associé à Menu::NOT_FOUND dans Game::menus.                                              */

	auto errorScreen = std::make_unique<Screen>(
		this,
		nullptr,
		nullptr,
		sf::Color()
		);
	// Ajouter les éléments de l'écran d'erreur ici.
	menus[Menu::NOT_FOUND] = std::move(errorScreen);

	/* Premier niveau */
	auto level1 = std::make_unique<Screen>(
		this, 
		std::move(std::make_unique<Level1EventHandler>()),
		std::move(std::make_unique<Level1UpdateStrategy>()),
		sf::Color()
		);

	sf::Font font;
	if (!font.loadFromFile("resources/Bernadette.ttf")) {

		std::cout << "Impossible de charger la police d'écriture." << std::endl;

	}

	level1->addElement(std::move(std::make_unique<Text>(10, 10, "goal", "Trouvez la forme avec le plus de côtés.", font, 32, sf::Color(200, 200, 200), sf::Text::Bold)));

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