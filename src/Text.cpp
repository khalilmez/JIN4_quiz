#include "Text.h"
#include <iostream>
Text::Text(float x, float y, std::string name, std::string content, sf::Font font, int characterSize, sf::Color color, sf::Text::Style style) :
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
