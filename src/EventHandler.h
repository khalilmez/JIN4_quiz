#pragma once
#include "Screen.h"

class EventHandler {

public:

	virtual void handle(Screen &screen, sf::Event &event) = 0;

};