#pragma once

#include <SFML/Graphics.hpp>

class Screen;
class Element;

class EventHandler {

public:
	virtual ~EventHandler() = default;
	virtual void handle(std::unique_ptr<Element>& element, Screen& screen, sf::Event const& event, sf::RenderWindow const& window) = 0;

};
