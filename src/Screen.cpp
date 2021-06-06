#include "Screen.h"
#include "UpdateStrategy.h"
#include "EventHandler.h"

void Screen::render(sf::RenderWindow &window) const {

	window.clear(backgroundColor);

	for (auto &element : elements) {

		element.render(window);
		//((Element&)element).render(window);

	}

	window.display();

}

void Screen::handleEvent(const sf::Event &event) {

	eventHandler->handle(*this, event);

}

Screen* Screen::update() {

	return updateStrategy->update(*this);

}

void Screen::addElement(std::unique_ptr<Element> element) {

	elements.push_back(move(element));

}
