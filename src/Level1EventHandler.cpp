#include "Level1EventHandler.h"
#include <iostream>

void Level1EventHandler::handle(Screen &screen, sf::Event const &event, sf::RenderWindow const &window) {

	/* Gestion des événements utilisateur du niveau 1 ici. */
    if (event.type == sf::Event::MouseButtonPressed) {

        int x, y;
        x = sf::Mouse::getPosition(window).x;
        y = sf::Mouse::getPosition(window).y;

        if (screen.getElement(1)->contains(x, y)) {

            std::cout << "BRAVO !\n";
            screen.setCompleted(true);

        }
        else if(screen.getElement(2)->contains(x, y) || screen.getElement(3)->contains(x, y) || screen.getElement(4)->contains(x, y)) {

            std::cout << "Reessayez...\n";
            screen.setFailed(true);

        }

    }

}
