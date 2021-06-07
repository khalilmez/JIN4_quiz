#pragma once
#include "Element.h"
#include <SFML/Graphics.hpp>
#include <pugixml.hpp>

/* Cette classe représente les éléments textuels d'un écran.
*/
class Rectangle : public Element {

public:

	explicit Rectangle(pugi::xml_node &node);

	explicit Rectangle(float x, float y, std::string name, float width ,float length, sf::Color color);

	void render(sf::RenderWindow& window) const override;

	bool contains(const float x, const float y) const override;

	float get_Width() {
		return width;
	}

	float get_Length() {
		return length;
	}

private:
	/* La couleur du cercle.
	*/
	sf::Color color;

	/* Le rayon du cercle.
	*/
	float width;
	
	/* Le nombre d'arêtes. 0 pour un cercle normale (3 triangle ...)
	*/
	int length;

};