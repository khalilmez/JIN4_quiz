#include "Element.h"

Element::Element(float x, float y, std::string name): x(x),y(y),name(name) {}

float Element::get_X() const {
	return x;
}
float Element::get_Y() const {
	return y;
}
void Element::set_X(float X) {
	x = X;
}
void Element::set_Y(float Y) {
	y = Y;
}
