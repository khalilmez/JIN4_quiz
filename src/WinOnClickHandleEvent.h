#pragma once
#include "EventHandler.h"

class WinOnClickHandleEvent : public EventHandler {

public:

	void handle(std::unique_ptr<Element>& element, Screen &screen, sf::Event const &event, sf::RenderWindow const &window) override;

};