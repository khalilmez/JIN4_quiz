#include "CutToWinOnClickHandleEvent.h"
#include <iostream>
#include "Screen.h"

void CutToWinOnClickHandleEvent::handle(std::unique_ptr<Element>& element, Screen &screen, sf::Event const &event, sf::RenderWindow const &window) {
   
    if (element->getX() < 0 || element->getX() > window.getSize().x || element->getY() < 0 || element->getY() > window.getSize().y) {

        screen.setCompleted(true);

    }

}
