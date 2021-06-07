#include "Level1EventHandler.h"
#include <iostream>
using namespace std;
void Level1EventHandler::handle(Screen& screen, const sf::Event& event, sf::RenderWindow& window) {

	/* Gestion des événements utilisateur du niveau 1 ici. */
    if (event.type == sf::Event::MouseButtonPressed) {
        int x, y;
        x = sf::Mouse::getPosition(window).x;
        y = sf::Mouse::getPosition(window).y;

        if (screen.getElement(1)->contains(x, y)) {
            cout << "BRAVO !" << endl;
            screen.setCompleted(true);
        }
        else if(screen.getElement(2)->contains(x, y)){
            cout << "Reessayez ! " << endl;
        }
        else if (screen.getElement(3)->contains(x, y)) {
            cout << "Reessayez ! " << endl;
        }
        else if (screen.getElement(4)->contains(x, y)) {
            cout << "Reessayez !" << endl;
        }
    }

}
