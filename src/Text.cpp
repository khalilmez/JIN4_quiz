#include "Text.h"
#include <iostream>

Text::Text(pugi::xml_node const &node) :
	Element{ node.attribute("x").as_float(), node.attribute("y").as_float(), node.attribute("name").as_string() },
	size{ node.attribute("size").as_int() }
{

	if(!font.loadFromFile(node.attribute("font").as_string())) { std::cout << "Error while loading font.\n"; }

	auto red = node.attribute("r");
	auto green = node.attribute("g");
	auto blue = node.attribute("b");
	auto alpha = node.attribute("a");

	if (red && green && blue) {

		color = sf::Color(red.as_int(), green.as_int(), blue.as_int());

	}
	else {

		color = sf::Color();

	}

	if (alpha) { color.a = alpha.as_int(); }

	if (!strcmp(node.attribute("style").as_string(), "bold")) { style = sf::Text::Bold; }
	else { style = sf::Text::Regular; }

	content = node.text().as_string();

}

Text::Text(const float x, const float y, std::string const& name, std::string const& content, sf::Font const& font, const int characterSize, sf::Color const& color, sf::Text::Style const& style) :
	Element{x, y, name},
	content{content},
	font{font},
	size{characterSize},
	color{color},
	style{style}
{}

void Text::render(sf::RenderWindow &window) {

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
