#include "Rectangle.h"

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