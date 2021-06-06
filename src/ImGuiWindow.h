#pragma once
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class ImGuiWindow
{
private :
	std::string title;
	std::string content;
public:
	void render(sf::RenderWindow window);
};

