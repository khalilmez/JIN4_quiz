#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>

class Element {

public:

	Element(float x, float y, std::string name);
	virtual ~Element() = default;

	float getX() const;
	float getY() const;
	void setX(float X);
	void setY(float Y);

	/* Affiche l'élément.
	*/
	virtual void render(sf::RenderWindow& window) = 0;

	/* Permet de savoir si le point de coordonnées
	(x, y, z) se trouve dans l'élément.
	Pour les éléments 2D, la coordonnée z est inutile.
	*/
	virtual bool contains(const float x, const float y) const = 0;

protected:

	/* Les coordonnées de l'élément.
	*/
	float x;
	float y;

	/* Le nom de l'élément.
	*/
	std::string name;

};

