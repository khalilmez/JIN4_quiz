#pragma once
#include "EventHandler.h"

class Level2EventHandler : public EventHandler {

public:

	void handle(Screen &screen, const sf::Event &event, sf::RenderWindow &window) override;

};