#pragma once
#include "Screen.h"

class EventHandler {

public:

	virtual ~EventHandler() = default;
	virtual void handle(Screen &screen, const sf::Event &event, sf::RenderWindow &window) = 0;

};