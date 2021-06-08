#include "Level3EventHandler.h"
#include <iostream>
#include "imgui.h"
#include "ImGuiWindow.h"
void Level3EventHandler::handle(Screen& screen, sf::Event const &event, sf::RenderWindow const &window) {

	/* Gestion des événements utilisateur du niveau 3 ici. */
    ImGuiWindow* imgui =(ImGuiWindow*)(screen.getElement(3));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        if (imgui->getInt() == 9) {
            screen.setCompleted(true);
        }
        else {
            screen.setFailed(true);
            std::cout << "Vous pouvez attendre 3 heures, les aiguilles ne vont pas bouger puisqu'il sagit d'une image fixe ..." << std::endl;
        }
    }
}
