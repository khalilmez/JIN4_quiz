#pragma once
#include <SFML/Graphics.hpp>
#include "Element.h"
#include <pugixml.hpp>

class Game;
class UpdateStrategy;
class EventHandler;

class Screen {

public:

	explicit Screen(Game* game, pugi::xml_node const &node);

	Screen(Game* game, std::unique_ptr<EventHandler> eventHandler, std::unique_ptr<UpdateStrategy> updateStrategy, sf::Color const &backgroundColor);

	/* Affiche l'écran.
	Cette méthode appelle successivement les méthodes
	Element::render(...) de tous les éléments constituant
	l'écran.
	*/
	void render(sf::RenderWindow& window) const;

	/* Gère les événements utilisateur sur l'écran
	courant.
	Comme chaque écran doit gérer ces événements différemment,
	cette méthode utilise une stratégie héritant de
	l'interface EventHandler.
	Cette stratégie est contenue dans Screen::eventHandler.
	*/
	void handleEvent(const sf::Event& event, sf::RenderWindow& window);

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

	/* Permet d'ajouter des éléments à
	l'écran.
	*/
	void addElement(std::unique_ptr<Element> element);

	Element* getElement(const int id) const;

	Element* getElementByName(std::string const& name) const;

	int getNumberOfElements() const;

	bool isCompleted() const;

	void setCompleted(const bool c);

	bool isFailed() const;

	void setFailed(const bool c);

	Game* getGame() const;

private:

	/* Booléen indiquant si on peut passer à l'écran/niveau
	suivant.
	*/
	bool completed = false;

	/* Vaut true quand le joueur a épuisé toutes ses tentatives
	pour le niveau courant.
	Permet de savoir quand afficher l'écran de défaite.
	*/
	bool failed = false;

	/* Le jeu auquel appartient le niveau.
	*/
	Game* game;

	/* Les éléments constituant l'écran.
	*/
	std::vector<std::unique_ptr<Element>> elements;

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

	/* La couleur de fond de l'écran.
	*/
	sf::Color backgroundColor;

};

