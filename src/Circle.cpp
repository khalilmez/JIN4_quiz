#include "Circle.h"

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