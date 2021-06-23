#pragma once
#include "EventHandler.h"

class MovableHandleEvent : public EventHandler {

public:
	/**Represente les elements qui bougent losrsqu'on clique dessus
	*/
	void handle(std::unique_ptr<Element>& element, Screen &screen, sf::Event const &event, sf::RenderWindow const &window) override;

};