#include "LoseOnClickHandleEvent.h"
#include <iostream>
#include "Screen.h"

void LoseOnClickHandleEvent::handle(std::unique_ptr<Element>& element, Screen &screen, sf::Event const &event, sf::RenderWindow const &window) {
   
    if (event.type == sf::Event::MouseButtonPressed) {
        if (element->contains(event.mouseButton.x, event.mouseButton.y)) {
            screen.setFailed(true);
        }

    }

}
