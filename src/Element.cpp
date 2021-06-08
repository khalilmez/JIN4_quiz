#include "Element.h"

Element::Element(const float x, const float y, const std::string &name) :
	x{ x },
	y{ y },
	name{ name }
{}

float Element::getX() const {
	return x;
}
float Element::getY() const {
	return y;
}
void Element::setX(float X) {
	x = X;
}
void Element::setY(float Y) {
	y = Y;
}

bool Element::contains(const float x, const float y) const {
	/* Ne fait rien */
	return false;
}

void Element::setName(std::string const& name) {

	this->name = name;

}

std::string Element::getName() const {

	return name;

}
