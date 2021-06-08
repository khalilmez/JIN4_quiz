#include "Level1EventHandler.h"
#include <iostream>

void Level1EventHandler::handle(Screen &screen, sf::Event const &event, sf::RenderWindow const &window) {

	/* Gestion des événements utilisateur du niveau 1 ici. */
    const Element* element;

    if (event.type == sf::Event::MouseButtonPressed) {

        for (int k = 0; k < screen.getNumberOfElements(); k++) {

            element = screen.getElement(k);

            if ((element->contains(event.mouseButton.x, event.mouseButton.y))) { 
            
                if(element->getName() == "Circle") { screen.setCompleted(true); }
                else { screen.setFailed(true); }
            
            }

        }

    }

}
