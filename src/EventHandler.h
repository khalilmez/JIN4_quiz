#pragma once
#include "Screen.h"

class EventHandler {

public:

	virtual void handle(Screen &screen, const sf::Event &event) = 0;

};