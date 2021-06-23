#pragma once
#include "EventHandler.h"

class ImguiHandleEvent : public EventHandler {
	/*Le handleEvent de l'element ImGui*/
public:

	void handle(std::unique_ptr<Element>& element, Screen &screen, sf::Event const &event, sf::RenderWindow const &window) override;

};