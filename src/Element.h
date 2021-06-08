#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>

class Element {

public:

	explicit Element(const float x, const float y, std::string const &name);
	virtual ~Element() = default;

	float getX() const;
	float getY() const;
	void setX(float X);
	void setY(float Y);

	void setName(std::string const& name);

	std::string getName() const;

	/* Affiche l'élément.
	*/
	virtual void render(sf::RenderWindow& window) = 0;

	/* Permet de savoir si le point de coordonnées
	(x, y, z) se trouve dans l'élément.
	Pour les éléments 2D, la coordonnée z est inutile.
	*/
	virtual bool contains(const float x, const float y) const;

protected:

	/* Les coordonnées de l'élément.
	*/
	float x;
	float y;

	/* Le nom de l'élément.
	*/
	std::string name;

};

