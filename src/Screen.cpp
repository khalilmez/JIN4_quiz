#include "Screen.h"

void Screen::render(sf::RenderWindow &window) const {

	window.clear(backgroundColor);

	for (auto &element : elements) {

		element.render(window);

	}

	window.display();

}

void Screen::handleEvent(sf::Event event) {

	eventHandler.handle(this, event);

}

Screen* Screen::update() {

	updateStrategy.update(this);

}