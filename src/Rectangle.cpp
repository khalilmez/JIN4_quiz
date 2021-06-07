#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(float x, float y, std::string name, float width, float length, sf::Color color) :
	Element{ x, y, name },
	color(color),
	width(width),
	length(length)
{}

void Rectangle::render(sf::RenderWindow &window) const {
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(width, length));
	rectangle.setFillColor(color);
	rectangle.setPosition(x, y);
	window.draw(rectangle);
}

bool Rectangle::contains(const float x_mouse, const float y_mouse) const
{
	if (x_mouse >= x && x_mouse <= (x + width) && y_mouse >= y && y_mouse <= (y + length)) {
		return true;
	}
	return false;
}
