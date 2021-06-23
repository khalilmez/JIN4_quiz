#pragma once
#include "EventHandler.h"

class WinOnClickHandleEvent : public EventHandler {
	/**Cet EventHandle consitue tous les elements que lorsqu'on clique dessus on gagne
	*/
public:

	void handle(std::unique_ptr<Element>& element, Screen &screen, sf::Event const &event, sf::RenderWindow const &window) override;

};