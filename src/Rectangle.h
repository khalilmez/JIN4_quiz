#pragma once
#include "Element.h"
#include <SFML/Graphics.hpp>
#include <pugixml.hpp>

/* Cette classe représente les éléments textuels d'un écran.
*/
class Rectangle : public Element {

public:

	explicit Rectangle(pugi::xml_node const &node);

	explicit Rectangle(float x, float y, std::string const &name, const float width, const float length, sf::Color const &color);

	void render(sf::RenderWindow& window) override;

	bool contains(const float x, const float y) const override;

	float getWidth() const;

	float getHeight() const;

	bool verify() override { return false; };

	sf::Color getColor() const;

private:

	sf::RectangleShape rectangle;

	/* La couleur du cercle.
	*/
	sf::Color color;

	/* Le rayon du cercle.
	*/
	float width;
	
	/* Le nombre d'arêtes. 0 pour un cercle normale (3 triangle ...)
	*/
	float height;

};