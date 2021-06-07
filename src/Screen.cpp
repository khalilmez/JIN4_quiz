#include "Screen.h"
#include "UpdateStrategy.h"
#include "EventHandler.h"

Screen::Screen(Game* game, std::unique_ptr<EventHandler> eventHandler, std::unique_ptr<UpdateStrategy> updateStrategy, sf::Color backgroundColor) :
	game{game},
	backgroundColor{backgroundColor}
{

	this->eventHandler = std::move(eventHandler);
	this->updateStrategy = std::move(updateStrategy);

}

void Screen::render(sf::RenderWindow &window) const {

	window.clear(backgroundColor);

	for (auto &element : elements) {

		element->render(window);

	}

	window.display();

}

void Screen::handleEvent(const sf::Event &event, sf::RenderWindow &window) {

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

void Screen::setCompleted(bool c) {
	completed = c;
}
