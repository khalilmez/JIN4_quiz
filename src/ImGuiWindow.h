#pragma once
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Element.h"

class ImGuiWindow : public Element{
private :
	std::string title;
	std::string content;
public:
	void render(sf::RenderWindow window);
};

