#include "Level2EventHandler.h"
#include <iostream>
using namespace std;
void Level2EventHandler::handle(Screen& screen, const sf::Event& event, sf::RenderWindow& window) {

	/* Gestion des événements utilisateur du niveau 1 ici. */
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        screen.getElement(1)->setX(sf::Mouse::getPosition(window).x);
        screen.getElement(1)->setY(sf::Mouse::getPosition(window).y);
        if (screen.getElement(1)->getX() < 0 || screen.getElement(1)->getX() > (window.getSize().x - 95)) {
            screen.setCompleted(true);
            cout << "YES" << endl;
        }
        if (screen.getElement(1)->getY() < 0 || screen.getElement(1)->getY() > (window.getSize().y - 95)) {
            screen.setCompleted(true);
            cout << "YES" << endl;
        }
    }

}
