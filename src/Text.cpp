#include "Text.h"
#include <iostream>

Text::Text(pugi::xml_node const &node) :
	Element{ node.attribute("x").as_float(), node.attribute("y").as_float(), node.attribute("name").as_string() },
	size{ node.attribute("size").as_int() }
{

	if(!font.loadFromFile(node.attribute("font").as_string())) { std::cout << "Error while loading font.\n"; }

	auto angle = node.attribute("angle");
	if (angle) { this->angle = angle.as_float(); }

	auto red = node.attribute("r");
	auto green = node.attribute("g");
	auto blue = node.attribute("b");
	auto alpha = node.attribute("a");

	if (red && green && blue) {

		color.r = red.as_int();
		color.g = green.as_int();
		color.b = blue.as_int();

	}

	if (alpha) { color.a = alpha.as_int(); }

	if (!strcmp(node.attribute("style").as_string(), "bold")) { style = sf::Text::Bold; }
	else { style = sf::Text::Regular; }

	content = node.text().as_string();

	text.setString(content);
	text.setCharacterSize(size);
	text.setFont(font);
	text.setFillColor(color);
	text.setStyle(style);
	auto boundaries = text.getGlobalBounds();
	text.setOrigin(boundaries.left + boundaries.width / 2, boundaries.top + boundaries.height / 2);
	text.setPosition(x, y);
	text.setRotation(this->angle);

}

Text::Text(const float x, const float y, std::string const& name, std::string const& content, sf::Font const& font, const int characterSize, sf::Color const& color, sf::Text::Style const& style) :
	Element{x, y, name},
	content{content},
	font{font},
	size{characterSize},
	color{color},
	style{style}
{

	text.setString(content);
	text.setCharacterSize(characterSize);
	text.setFont(font);
	text.setFillColor(color);
	text.setStyle(style);
	text.setOrigin(x, y);
	text.setPosition(x, y);

}

void Text::render(sf::RenderWindow &window) {

	text.setString(content);
	text.setCharacterSize(size);
	text.setFont(font);
	text.setFillColor(color);
	text.setStyle(style);
	text.setPosition(x, y);
	text.setRotation(angle);

	window.draw(text);

}

bool Text::contains(const float x, const float y) const
{
	return text.getGlobalBounds().contains(x, y);
}
