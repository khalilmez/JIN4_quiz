#pragma once
#include "EventHandler.h"

class WinLoseEventHandler : public EventHandler {

public:

	void handle(Screen& screen, sf::Event const &event, sf::RenderWindow const &window) override;

};