#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(pugi::xml_node const &node) : 
	Element{ node.attribute("x").as_float(), node.attribute("y").as_float(), node.attribute("name").as_string() },
	width{ node.attribute("width").as_float() },
	height{ node.attribute("height").as_float() }
{

	auto red = node.attribute("r");
	auto green = node.attribute("g");
	auto blue = node.attribute("b");
	auto alpha = node.attribute("a");

	if (red && green && blue) {

		color = sf::Color(red.as_int(), green.as_int(), blue.as_int());

	}
	else {

		color = sf::Color();

	}

	if (alpha) { color.a = alpha.as_int(); }

}

Rectangle::Rectangle(const float x, const float y, std::string const &name, const float width, const float height, sf::Color const &color) :
	Element{ x, y, name },
	color{ color },
	width{ width },
	height{ height }
{}

void Rectangle::render(sf::RenderWindow &window) {
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(width, height));
	rectangle.setFillColor(color);
	rectangle.setPosition(x, y);
	window.draw(rectangle);
}

bool Rectangle::contains(const float x_mouse, const float y_mouse) const
{
	if (x_mouse >= x && x_mouse <= (x + width) && y_mouse >= y && y_mouse <= (y + height)) {
		return true;
	}
	return false;
}

sf::Color Rectangle::getColor() const
{
	return color;
}

float Rectangle::getWidth() const {
	return width;
}

float Rectangle::getHeight() const {
	return height;
}