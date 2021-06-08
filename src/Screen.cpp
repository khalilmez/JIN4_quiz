#include "Screen.h"
#include "UpdateStrategy.h"
#include "EventHandler.h"
#include <pugixml.hpp>
#include "Text.h"
#include "Sprite.h"
#include "Rectangle.h"
#include "Circle.h"
#include "WinLoseEventHandler.h"
#include "WinLoseUpdateStrategy.h"
#include "Level1EventHandler.h"
#include "Level1UpdateStrategy.h"
#include "Level2EventHandler.h"
#include "Level2UpdateStrategy.h"

Screen::Screen(Game* game, pugi::xml_node const &node) :
	game{game},
	backgroundColor{ node.attribute("r").as_int(), node.attribute("g").as_int(), node.attribute("b").as_int() }
{

	if (!strcmp(node.attribute("event_handler").as_string(), "win_lose")) {

		eventHandler = std::move(std::make_unique<WinLoseEventHandler>());

	}
	else if (!strcmp(node.attribute("event_handler").as_string(), "level1")) {

		eventHandler = std::move(std::make_unique<Level1EventHandler>());

	}
	else if (!strcmp(node.attribute("event_handler").as_string(), "level2")) {

		eventHandler = std::move(std::make_unique<Level2EventHandler>());

	}
	else { eventHandler = nullptr; }

	if (!strcmp(node.attribute("update_strategy").as_string(), "win_lose")) {

		updateStrategy = std::move(std::make_unique<WinLoseUpdateStrategy>());

	}
	else if (!strcmp(node.attribute("update_strategy").as_string(), "level1")) {

		updateStrategy = std::move(std::make_unique<Level1UpdateStrategy>());

	}
	else if (!strcmp(node.attribute("update_strategy").as_string(), "level2")) {

		updateStrategy = std::move(std::make_unique<Level2UpdateStrategy>());

	}
	else { eventHandler = nullptr; }

	for (auto& child : node.children()) {

		if(!strcmp(child.name(), "text")) { 
		
			addElement(std::move(std::make_unique<Text>(child)));
		
		}
		else if (!strcmp(child.name(), "sprite")) {

			addElement(std::move(std::make_unique<Sprite>(child)));

		}
		else if (!strcmp(child.name(), "rectangle")) {

			addElement(std::move(std::make_unique<Rectangle>(child)));

		}
		else if (!strcmp(child.name(), "circle")) {

			addElement(std::move(std::make_unique<Circle>(child)));

		}

	}

}

Screen::Screen(Game* game, std::unique_ptr<EventHandler> eventHandler, std::unique_ptr<UpdateStrategy> updateStrategy, sf::Color const &backgroundColor) :
	game{ game },
	backgroundColor{ backgroundColor }
{

	this->eventHandler = std::move(eventHandler);
	this->updateStrategy = std::move(updateStrategy);

}

void Screen::render(sf::RenderWindow& window) const {

	window.clear(backgroundColor);

	for (auto& element : elements) {

		element->render(window);

	}

	window.display();

}

void Screen::handleEvent(const sf::Event& event, sf::RenderWindow& window) {

	eventHandler->handle(*this, event, window);

}

Screen* Screen::update() {

	return updateStrategy->update(*this);

}

void Screen::addElement(std::unique_ptr<Element> element) {

	elements.push_back(std::move(element));

}

bool Screen::isCompleted() const {

	return completed;

}

void Screen::setCompleted(const bool c) {

	completed = c;

}

Element* Screen::getElement(const int id) const {

	if (id < 0 || id >= elements.size()) { return nullptr; }

	return elements[id].get();

}

int Screen::getNumberOfElements() const {

	return elements.size();

}

bool Screen::isFailed() const {

	return failed;

}

void Screen::setFailed(const bool c) {

	failed = c;

}

Game* Screen::getGame() const {

	return game;

}
