#include "Circle.h"
#include <iostream>

Circle::Circle(pugi::xml_node const &node) :
	Element{ node.attribute("x").as_float(), node.attribute("y").as_float(), node.attribute("name").as_string() },
	radius{ node.attribute("radius").as_float() }
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

	auto temp = node.attribute("nb_sides");

	if (temp) { sides = temp.as_int(); }
	else { sides = 300; }

}

Circle::Circle(const float x, const float y, std::string const &name, const float radius, sf::Color const &color, const int numberOfSides) :
	Element{ x, y, name },
	color(color),
	radius(radius),
	sides(numberOfSides)
{}

Circle::Circle(const float x, const float y, std::string const &name, const float radius, sf::Color const &color) :
	Element(x, y, name),
	color(color),
	radius(radius)
{}

void Circle::render(sf::RenderWindow& window) {

	if(sides <= 1) {

		sf::CircleShape circle(radius);
		circle.setFillColor(color);
		circle.setPosition(x, y);
		window.draw(circle);
	}
	else {

		sf::CircleShape circle(radius, sides);
		circle.setFillColor(color);
		circle.setPosition(x, y);
		window.draw(circle);

	}

}

bool Circle::contains(const float x_mouse, const float y_mouse) const {

	if (x_mouse >= x && x_mouse <= (x + 2 * radius) && y_mouse >= y && y_mouse <= (y + 2 * radius)) {

		return true;

	}

	return false;

}

float Circle::getRadius() const {

	return radius;

}

int Circle::getNumberOfSides() const {

	return sides;

}

void Circle::setRadius(float radius) {

	this->radius = radius;

}

void Circle::setNumberOfSides(int nb) {

	sides = nb;

}

sf::Color Circle::getColor() const
{
	return color;
}
