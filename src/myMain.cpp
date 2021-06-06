#include "myMain.h"
#include "Game.h"
#include "Menu.h"
#include "Screen.h"
#include "UpdateStrategy.h"
#include "EventHandler.h"

#define WIDTH 640
#define HEIGHT 480
#define APP_NAME "Quizzz"

// using namespace std;

int myMain() {

    /* Initialisation du jeu.
    */
    Game game;
    game.init();

    /* Initialisation de l'écran 
    courant.
    */
    Screen* screen;

    /* On récupère l'écran d'accueil du jeu.
    */
    screen = game.getMenu(Menu::LAUNCH);

    /* On crée la fenêtre d'affichage.
    */
    sf::RenderWindow window;
    window.create(sf::VideoMode(WIDTH, HEIGHT), APP_NAME);

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

            /* Appel du gestionnaire d'événement de
            l'écran courant sur les événements utilisateurs 
            dépilés.
            */
            screen->handleEvent(event);

        }

        /* Vérification de la condition de transition et 
        mise-à-jour spontanée de l'écran courant.
        */
        screen = screen->update();

    }

    return 0;

}