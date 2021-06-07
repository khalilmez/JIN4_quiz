#pragma once
#include "EventHandler.h"

class Level1EventHandler : public EventHandler {

public:

	void handle(Screen &screen, const sf::Event &event, sf::RenderWindow &window) override;

};