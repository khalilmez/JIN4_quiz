#include "myMain.h"
#include "Game.h"
#include "Menu.h"
#include "Screen.h"
#include "UpdateStrategy.h"
#include "EventHandler.h"
#include "ImGuiWindow.h"
#include "ImGuiWindowBuilder.h"
#define WIDTH 640
#define HEIGHT 480
#define APP_NAME "Quizzz"

// using namespace std;

int myMain() {
    ImGuiWindowBuilder builder;

    /* Initialisation du jeu.
    */
    Game game;
    game.init();

    ImGuiWindow imgui = builder.withTitle("Hellloooo").withInputText("Textt").build();

    /* Initialisation de l'écran 
    courant.
    */
    Screen* screen;

    /* On récupère l'écran d'accueil du jeu.
    */
    // screen = game.getMenu(Menu::LAUNCH);
    screen = game.getCurrentLevel(); // Modifié temporairement pour afficher le premier niveau directement au lieu de l'écran d'accueil.

    /* On crée la fenêtre d'affichage.
    */
    sf::RenderWindow window;
    window.create(sf::VideoMode(WIDTH, HEIGHT), APP_NAME);
    ImGui::SFML::Init(window);
    /* Pour la gestion des événements.
    */
    sf::Event event;

    /* La boucle du jeu.
    */
    while (window.isOpen()) {

        /* L'affichage de l'écran courant.
        */
        screen->render(window);
        /* Dépilage des événements utilisateur.
        */
        while (window.pollEvent(event)) {

            /* Fermeture de la fenêtre du jeu. 
            */
            if (event.type == sf::Event::Closed) {window.close();}

            /* Appel du gestionnaire d'événement de
            l'écran courant sur les événements utilisateurs 
            dépilés.
            */
            screen->handleEvent(event, window);

        }
        
        /* Vérification de la condition de transition et 
        mise-à-jour spontanée de l'écran courant.
        */
        screen = screen->update();

    }
    ImGui::SFML::Shutdown();

    return 0;

}
