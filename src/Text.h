#pragma once
#include "Element.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

/* Cette classe représente les éléments textuels d'un écran.
*/
class Text : public Element {

public:

	explicit Text(float x, float y, std::string name, std::string content, sf::Font font, int characterSize, sf::Color color, sf::Text::Style style);

	void render(sf::RenderWindow& window) override;

	bool contains(const float x, const float y) const override;

private:

	/* Le contenu textuel de l'élément.
	*/
	std::string content;

	/* La police d'écriture.
	*/
	sf::Font font;

	/* La taille d'écriture.
	*/
	int size;

	/* La couleur d'écriture.
	*/
	sf::Color color;

	/* La décoration textuelle (gras, souligné...)
	*/
	sf::Text::Style style;

};