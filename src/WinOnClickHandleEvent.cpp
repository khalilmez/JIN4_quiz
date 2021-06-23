#include "WinOnClickHandleEvent.h"
#include <iostream>
#include "Screen.h"

void WinOnClickHandleEvent::handle(std::unique_ptr<Element>& element, Screen &screen, sf::Event const &event, sf::RenderWindow const &window) {
   
    if (event.type == sf::Event::MouseButtonPressed) {
        /*On a cliqué sur le l'element */
        if ((element->contains(event.mouseButton.x, event.mouseButton.y))) {
            screen.setCompleted(true);
        }

    }

}
