#include "Level2EventHandler.h"
#include <iostream>
using namespace std;
void Level2EventHandler::handle(Screen& screen, const sf::Event& event, sf::RenderWindow& window) {

	/* Gestion des événements utilisateur du niveau 1 ici. */
    if (event.type == sf::Event::KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            cout << "YOUPI" << endl;
        }
    }

}
