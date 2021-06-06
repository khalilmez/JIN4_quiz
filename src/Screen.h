#pragma once
#include <SFML/Graphics.hpp>
// #include "Game.h"
#include "Element.h"
// #include "EventHandler.h"
// #include "UpdateStrategy.h"

class Game;
class UpdateStrategy;
class EventHandler;

class Screen {

public:

	/* Affiche l'écran.
	Cette méthode appelle successivement les méthodes 
	Element::render(...) de tous les éléments constituant 
	l'écran.
	*/
	void render(sf::RenderWindow &window) const;

	/* Gère les événements utilisateur sur l'écran 
	courant.
	Comme chaque écran doit gérer ces événements différemment,
	cette méthode utilise une stratégie héritant de 
	l'interface EventHandler.
	Cette stratégie est contenue dans Screen::eventHandler.
	*/
	void handleEvent(const sf::Event &event);

	/* Gère les mises-à-jour "spontanées" (ne dépendant 
	pas d'événements utilisateurs) de l'écran.
	Comme chaque écran possède des processus de mise-à-jour différents,
	cette méthode utilise une stratégie héritant de
	l'interface UpdateStrategy.
	Cette stratégie est contenue dans Screen::updateStrategy.
	Cette méthode teste également la condition de transition de 
	l'écran courant vers son successeur ("condition de victoire"
	pour les niveaux).
	Dans le cas où cette condition est vérifiée, cette méthode 
	renvoie un pointeur vers l'écran suivant.
	Dans le cas contraire, elle renvoie un pointeur vers l'écran
	sur laquelle elle est appelée.
	*/
	Screen* update();

private:

	/* Le jeu auquel appartient le niveau.
	*/
	//Game* game;

	/* Le gestionnaire d'événements utilisateur à 
	utiliser pour l'écran
	(cf. Screen::handleEvent(...)).
	*/
	std::unique_ptr<EventHandler> eventHandler;

	/* La stratégie de mise-à-jour spontanée de 
	l'écran 
	(cf. Screen::update()).
	*/
	std::unique_ptr<UpdateStrategy> updateStrategy;

	/* Les éléments constituant l'écran.
	*/
	std::vector<Element> elements;

	/* La couleur de fond de l'écran.
	*/
	sf::Color backgroundColor;

};

