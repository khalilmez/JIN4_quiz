#pragma once
#include "Screen.h"

class EventHandler {

public:

	virtual ~EventHandler() = default;
	virtual void handle(Screen &screen, sf::Event const &event, sf::RenderWindow const &window) = 0;

};
