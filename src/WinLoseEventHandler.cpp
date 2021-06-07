#include "WinLoseEventHandler.h"

void WinLoseEventHandler::handle(Screen& screen, const sf::Event& event, sf::RenderWindow &window) {

	const Element* element;

	if (event.type == sf::Event::MouseButtonPressed) {

		for (int k = 0; k < screen.getNumberOfElements(); k++) {

			element = screen.getElement(k);

			if((element->contains(event.mouseButton.x, event.mouseButton.y)) && (element->getName() == "button")) { screen.setCompleted(true); }

		}

	}

}