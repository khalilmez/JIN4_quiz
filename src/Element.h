#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>

class Element
{
protected:
	float x;
	float y;
	std::string name;
	
public:
	Element(float x, float y, std::string name);
	float get_X() const;
	float get_Y() const;
	void set_X(float X);
	void set_Y(float Y);
	virtual void render(sf::RenderWindow& window) = 0;
	virtual ~Element() = default;
};

