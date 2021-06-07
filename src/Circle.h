#pragma once
#include "Element.h"
#include <SFML/Graphics.hpp>
#include <pugixml.hpp>

/* Cette classe représente les éléments textuels d'un écran.
*/
class Circle : public Element {

public:

	explicit Circle(pugi::xml_node &node);

	explicit Circle(float x, float y, std::string name, float Radius , sf::Color color, int Nb);

	explicit Circle(float x, float y, std::string name, float Radius, sf::Color color);

	void render(sf::RenderWindow& window) const override;

	bool contains(const float x, const float y) const override;

	float get_Radius() {
		return Radius;
	}

	int get_Nb() {
		return nb_Points;
	}

	void set_Radius(float radius) {
		Radius = radius;
	}

	void set_Nb(int nb) {
		nb_Points = nb;
	}

private:
	/* La couleur du cercle.
	*/
	sf::Color color;

	/* Le rayon du cercle.
	*/
	float Radius;
	
	/* Le nombre d'arêtes. 0 pour un cercle normale (3 triangle ...)
	*/
	int nb_Points = 0;

};