#include "MovableHandleEvent.h"
#include <iostream>
#include "Screen.h"

void MovableHandleEvent::handle(std::unique_ptr<Element>& element, Screen &screen, sf::Event const &event, sf::RenderWindow const &window) {
   
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        for (int k = 0; k < screen.getNumberOfElements(); k++) {

            if (element->contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {

                element->setX(sf::Mouse::getPosition(window).x);
                element->setY(sf::Mouse::getPosition(window).y);
            }

        }

    }

}
