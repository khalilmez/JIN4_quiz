#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>

class Element
{
private:
	std::string name;
	float x;
	float y;

public:
	void render(sf::RenderWindow window);
};

