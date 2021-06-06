#include "Text.h"

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