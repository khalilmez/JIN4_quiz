#pragma once
#include "EventHandler.h"

class WinLoseMenuEventHandler : public EventHandler {

public:

	void handle(Screen& screen, const sf::Event& event, sf::RenderWindow &window) override;

};