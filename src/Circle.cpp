#include "Circle.h"
#include <iostream>

Circle::Circle(pugi::xml_node const &node) :
	Element{ node.attribute("x").as_float(), node.attribute("y").as_float(), node.attribute("name").as_string() },
	radius{ node.attribute("radius").as_float() }
{

	auto angle = node.attribute("angle");
	if (angle) { this->angle = angle.as_float(); }

	auto red = node.attribute("r");
	auto green = node.attribute("g");
	auto blue = node.attribute("b");
	auto alpha = node.attribute("a");

	if (red && green && blue) {

		color.r = red.as_int();
		color.g = green.as_int();
		color.b = blue.as_int();

	}

	if (alpha) { color.a = alpha.as_int(); }

	auto temp = node.attribute("nb_sides");

	if (temp && temp.as_int() > 0) { sides = temp.as_int(); }
	else { sides = 300; }

	circle.setRadius(radius);
	circle.setPointCount(sides);
	circle.setFillColor(color);
	auto boundaries = circle.getGlobalBounds();
	circle.setOrigin(boundaries.left + boundaries.width / 2, boundaries.top + boundaries.height / 2);
	circle.setPosition(x, y);
	circle.setRotation(this->angle);

}

Circle::Circle(const float x, const float y, std::string const &name, const float radius, sf::Color const &color, const int numberOfSides) :
	Element{ x, y, name },
	color(color),
	radius(radius),
	sides(numberOfSides)
{

	circle.setRadius(radius);
	circle.setPointCount(numberOfSides);
	circle.setFillColor(color);
	circle.setOrigin(x, y);
	circle.setPosition(x, y);

}

Circle::Circle(const float x, const float y, std::string const &name, const float radius, sf::Color const &color) :
	Element(x, y, name),
	color(color),
	radius(radius)
{

	circle.setRadius(radius);
	circle.setFillColor(color);
	circle.setOrigin(x, y);
	circle.setPosition(x, y);

}

void Circle::render(sf::RenderWindow& window) {

	circle.setRadius(radius);
	circle.setPointCount(sides);
	circle.setFillColor(color);
	circle.setPosition(x, y);
	circle.setRotation(angle);

	window.draw(circle);

}

bool Circle::contains(const float x, const float y) const {

	if ((this->x - x) * (this->x - x) + (this->y - y) * (this->y - y) <= radius * radius) {

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
