#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(pugi::xml_node const &node) : 
	Element{ node.attribute("x").as_float(), node.attribute("y").as_float(), node.attribute("name").as_string() },
	color{ node.attribute("r").as_int(), node.attribute("g").as_int(), node.attribute("b").as_int() },
	width{ node.attribute("width").as_float() },
	length{ node.attribute("length").as_float() }
{}

Rectangle::Rectangle(const float x, const float y, std::string const &name, const float width, const float length, sf::Color const &color) :
	Element{ x, y, name },
	color{ color },
	width{ width },
	length{ length }
{}

void Rectangle::render(sf::RenderWindow &window) {
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

sf::Color Rectangle::getColor() const
{
	return color;
}

float Rectangle::get_Width() const {
	return width;
}

float Rectangle::get_Length() const {
	return length;
}