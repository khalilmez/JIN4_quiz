#include "Screen.h"
#include "EventHandler.h"
#include "UpdateStrategy.h"

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

	updateStrategy->update(*this);

	Screen* screen;
	return screen;
}