#include "myMain.h"
#include "Game.h"
#include "Menu.h"
#include "Screen.h"
#include "UpdateStrategy.h"
#include "EventHandler.h"
#include <SFML/OpenGL.hpp> 

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
    // screen = game.getMenu(Menu::LAUNCH);
    screen = game.getCurrentLevel(); // Modifié temporairement pour afficher le premier niveau directement au lieu de l'écran d'accueil.

    /* On crée la fenêtre d'affichage.
    */
    sf::RenderWindow window;
    window.create(sf::VideoMode(WIDTH, HEIGHT), APP_NAME, sf::Style::Default, sf::ContextSettings(32));

    /* Pour la gestion des événements.
    */
    sf::Event event;

    // activation de la fenêtre
    window.setActive(true);

    bool running = true;

    /* La boucle du jeu.
    */
    while (running) {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
        {
            glVertex3f(0.0, 2.0, -5.0);
            glVertex3f(-2.0, -2.0, -5.0);
            glVertex3f(2.0, -2.0, -5.0);
        }
        glEnd();

        window.pushGLStates();

        /* L'affichage de l'écran courant.
        */
        screen->render(window);

        window.popGLStates();

        /* Dépilage des événements utilisateur.
        */
        while (window.pollEvent(event)) {

            /* Fermeture de la fenêtre du jeu. 
            */
            if (event.type == sf::Event::Closed) {running = false;}

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

    window.setActive(false);

    return 0;

}
