#pragma once
#include "Element.h"
#include <SFML/Graphics.hpp>

/* Cette classe représente les éléments textuels d'un écran.
*/
class Rectangle : public Element {

public:

	explicit Rectangle(float x, float y, std::string name, float width ,float length, sf::Color color);

	void render(sf::RenderWindow& window) override;

	bool contains(const float x, const float y) const override;

	float get_Width() const {
		return width;
	}

	float get_Length() const {
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
	float length;

};