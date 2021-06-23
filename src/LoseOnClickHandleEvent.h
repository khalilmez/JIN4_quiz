#pragma once
#include "EventHandler.h"

class LoseOnClickHandleEvent : public EventHandler {
	/*Represente le Handle Event de tous les elements qui lorsqu'on
	clique dessus on perd la partie*/
public:

	void handle(std::unique_ptr<Element>& element, Screen &screen, sf::Event const &event, sf::RenderWindow const &window) override;

};