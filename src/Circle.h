#pragma once
#include "Element.h"
#include <SFML/Graphics.hpp>
#include <pugixml.hpp>

/* Cette classe représente les éléments textuels d'un écran.
*/
class Circle : public Element {

public:

	explicit Circle(pugi::xml_node const &node);

	explicit Circle(const float x, const float y, std::string const &name, const float radius, sf::Color const &color, const int numberOfSides);

	explicit Circle(const float x, const float y, std::string const &name, const float radius, const sf::Color &color);

	void render(sf::RenderWindow& window) override;

	bool contains(const float x, const float y) const override;

	float getRadius() const;

	int getNumberOfSides() const;

	void setRadius(float radius);

	void setNumberOfSides(int nb);

	sf::Color getColor() const;

private:

	/* La couleur du cercle.
	*/
	sf::Color color;

	/* Le rayon du cercle.
	*/
	float radius;
	
	/* Le nombre d'arêtes. 0 pour un cercle normale (3 triangle ...)
	*/
	int sides = 300;

};
