#include "Circle.h"
#include <iostream>

Circle::Circle(pugi::xml_node &node) :
	Element{ node.attribute("x").as_float(), node.attribute("y").as_float(), node.attribute("name").as_string() },
	color{ node.attribute("r").as_int(), node.attribute("g").as_int(), node.attribute("b").as_int() },
	Radius{ node.attribute("radius").as_float() }
{

	auto temp = node.attribute("nb_sides");

	if (temp) { nb_Points = temp.as_int(); }
	else { nb_Points = 300; }

}

Circle::Circle(float x, float y, std::string name, float Radius, sf::Color color, int Nb) :
	Element{ x, y, name },
	color(color),
	Radius(Radius),
	nb_Points(Nb)
{}

Circle::Circle(float x, float y, std::string name, float Radius, sf::Color color):
Element(x,y,name),
color(color),
Radius(Radius)
{
}

void Circle::render(sf::RenderWindow &window) const {
	if (nb_Points <= 1) {
		sf::CircleShape circle(Radius);
		circle.setFillColor(color);
		circle.setPosition(x, y);
		window.draw(circle);
	}
	else {
		sf::CircleShape circle(Radius, nb_Points);
		circle.setFillColor(color);
		circle.setPosition(x, y);
		window.draw(circle);
	}
}

bool Circle::contains(const float x_mouse, const float y_mouse) const
{
	if (x_mouse >= x && x_mouse <= (x + 2 * Radius) && y_mouse >= y && y_mouse <= (y + 2 * Radius)) {
		return true;
	}
	return false;
}
