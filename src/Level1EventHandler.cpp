#include "Level1EventHandler.h"
#include <iostream>
using namespace std;
void Level1EventHandler::handle(Screen& screen, const sf::Event& event, sf::RenderWindow& window) {

	/* Gestion des événements utilisateur du niveau 1 ici. */
    if (event.type == sf::Event::MouseButtonPressed) {
        int x, y;
        x = sf::Mouse::getPosition(window).x;
        y = sf::Mouse::getPosition(window).y;
        std::cout << "x = " << x << " y = " << y << std::endl;

        float X_element = screen.get_Elements()[0].get()->getX();
        float Y_element = screen.get_Elements()[0].get()->getY();

        if (x >= X_element && x <= (X_element + 100)
            && y >= Y_element && y <= (Y_element + 100)) {
            cout << "BRAVO !" << endl;
            screen.setCompleted(true);
        }
        else {
            cout << "Reessayez ! " << endl;
        }
    }

}