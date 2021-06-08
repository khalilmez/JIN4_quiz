#include "Text.h"
#include <iostream>
#include <pugixml.hpp>

Text::Text(pugi::xml_node &node) :
	Element{ node.attribute("x").as_float(), node.attribute("y").as_float(), node.attribute("name").as_string() },
	color{node.attribute("r").as_int(), node.attribute("g").as_int(), node.attribute("b").as_int() },
	size{ node.attribute("size").as_int() }
{

	if(!font.loadFromFile(node.attribute("font").as_string())) { std::cout << "Error while loading font.\n"; }

	if (!strcmp(node.attribute("style").as_string(), "bold")) { style = sf::Text::Bold; }

	else { style = sf::Text::Regular; }

	content = node.text().as_string();

}

Text::Text(float x, float y, std::string name, std::string content, sf::Font font, int characterSize, sf::Color color, sf::Text::Style style) :
	Element{x, y, name},
	content{content},
	font{font},
	size{characterSize},
	color{color},
	style{style}
{}

void Text::render(sf::RenderWindow &window) const {

	sf::Text text;

	text.setPosition(x, y);

	text.setString(content);
	text.setFont(font);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setStyle(style);

	window.draw(text);

}

bool Text::contains(const float x, const float y) const
{
	return false;
}
