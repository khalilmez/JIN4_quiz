#include "ImguiHandleEvent.h"
#include <iostream>
#include "Screen.h"

void ImguiHandleEvent::handle(std::unique_ptr<Element>& element, Screen &screen, sf::Event const &event, sf::RenderWindow const &window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        if (element->verify() == true) {
            screen.setCompleted(true);
        }
        else {
            screen.setFailed(true);
        }
    }
}
