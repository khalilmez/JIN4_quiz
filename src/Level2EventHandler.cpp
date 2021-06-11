#include "Level2EventHandler.h"
#include <iostream>

void Level2EventHandler::handle(Screen& screen, sf::Event const &event, sf::RenderWindow const &window) {

	/* Gestion des événements utilisateur du niveau 2 ici. */
    Element* element;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        for (int k = 0; k < screen.getNumberOfElements(); k++) {

            element = screen.getElement(k);

            if (element->contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && element->getName() != "background") {

                element->setX(sf::Mouse::getPosition(window).x);
                element->setY(sf::Mouse::getPosition(window).y);

                if (element->getName() == "Rectangle" && (element->getX() < 0 || element->getX() > window.getSize().x || element->getY() < 0 || element->getY() > window.getSize().y)) {

                    screen.setCompleted(true);

                }

            }

        }

    }

}
