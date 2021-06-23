#include "Game.h"
#include "Menu.h"
#include "Screen.h"
#include "UpdateStrategy.h"
#include "EventHandler.h"
#include <iostream>
#include <pugixml.hpp>

#define WIDTH 640
#define HEIGHT 480

void Game::init() {

	/* Positionne l'indice du niveau actuel 
	à 0 (premier niveau).
	*/
	currentLevel = 0;

	/* Construction des niveaux et menus en parsant 
	le fichier resources/setup.xml.
	*/
	pugi::xml_document document;
	pugi::xml_parse_result result = document.load_file("resources/setup.xml");
	if (!result) {

		std::cout << "Error while loading XML file.\n";

	}

	pugi::xml_node root = document.child("game");

	for (auto &child : root.children()) {

		if (!strcmp(child.name(), "menu")) {

			auto menu = std::make_unique<Screen>(this, child);
			
			if (!strcmp(child.attribute("type").as_string(), "win")) { menus[Menu::WIN] = std::move(menu); }
			else if (!strcmp(child.attribute("type").as_string(), "lose")) { menus[Menu::LOSE] = std::move(menu); }
			else if (!strcmp(child.attribute("type").as_string(), "launch")) { menus[Menu::LAUNCH] = std::move(menu); }
			else if (!strcmp(child.attribute("type").as_string(), "bye")) { menus[Menu::BYE] = std::move(menu); }
			else { menus[Menu::NOT_FOUND] = std::move(menu); }

		}
		else if (!strcmp(child.name(), "level")) {

			levels.push_back(std::move(std::make_unique<Screen>(this, child)));

		}

	}

}

Screen* Game::getMenu(const int id) const { 

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

bool Game::hasNextLevel() const
{
	return (currentLevel < levels.size());
}


