#pragma once
#include "Element.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <pugixml.hpp>

/* Cette classe représente les éléments textuels d'un écran.
*/
class Text : public Element {

public:

	explicit Text(pugi::xml_node const &node);

	explicit Text(const float x, const float y, std::string const &name, std::string const &content, sf::Font const &font, const int characterSize, sf::Color const &color, sf::Text::Style const &style);

	void render(sf::RenderWindow& window) override;

	bool verify() override { return false; };

	bool contains(const float x, const float y) const override;

private:

	sf::Text text;

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