#include "Game.h"
#include "Menu.h"
#include "Screen.h"
#include "UpdateStrategy.h"
#include "EventHandler.h"
#include "Text.h"
#include <iostream>
#include "Level1EventHandler.h"
#include "Level1UpdateStrategy.h"
#include "Circle.h"
#include "Rectangle.h"


#define WIDTH 640
#define HEIGHT 480
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

	/* Niveau 1 */
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

	level1->addElement(std::move(std::make_unique<Text>(10, 10, "goal", "Trouvez la forme avec le plus de faces.", font, 53, sf::Color(200, 200, 200), sf::Text::Bold)));
	level1->addElement(std::move(std::make_unique<Circle>(30,80,"Circle",50,sf::Color::Magenta)));
	level1->addElement(std::move(std::make_unique<Rectangle>(WIDTH - 100, 100, "Rectangle", 50,100, sf::Color::Yellow)));
	level1->addElement(std::move(std::make_unique<Circle>(WIDTH - 100, 280, "Triangle", 50, sf::Color::Red,3)));
	level1->addElement(std::move(std::make_unique<Circle>(30, 280, "octogone", 50, sf::Color::Red, 8)));
	levels.push_back(std::move(level1));

	/* Niveau 2 */

	/* Niveau 3 */

	/* ... */

}

Screen* Game::getMenu(int id) const { 

	auto entry = menus.find(id);

	if (entry != menus.end()) {

		return entry->second.get();

	}

	return menus.find(Menu::NOT_FOUND)->second.get();
}

Screen* Game::getCurrentLevel() const {

	return levels[currentLevel].get();

}

void Game::addMenu(std::unique_ptr<Screen> menu) {

	levels.push_back(std::move(menu));

}

void Game::addLevel(std::unique_ptr<Screen> level) {

	levels.push_back(std::move(level));

}

void Game::nextLevel() {

	currentLevel++;

}