#include "Sprite.h"
#include <iostream>

Sprite::Sprite(pugi::xml_node const& node) :
	Element{ node.attribute("x").as_float(), node.attribute("y").as_float(), node.attribute("name").as_string() }
{

	if (!texture.loadFromFile(node.attribute("file").as_string())) { std::cout << "Error while loading texture.\n"; }

	sprite.setTexture(texture);

	auto red = node.attribute("r");
	auto green = node.attribute("g");
	auto blue = node.attribute("b");
	auto alpha = node.attribute("a");

	if (red && green && blue) {

		color = sf::Color(red.as_int(), green.as_int(), blue.as_int());

	}
	else {

		color = sf::Color(255, 255, 255);

	}

	if (alpha) { color.a = alpha.as_int(); }

	sprite.setColor(color);

}

Sprite::Sprite(const float x, const float y, std::string const &name, std::string const &textureFile, sf::Color const &color) : 
	Element{x, y, name}
{

	if (!texture.loadFromFile(textureFile)) {

		std::cout << "Cannot find texture.\n";

	}

	sprite.setTexture(texture);

	if (&color) { this->color = color; }
	else { this->color = sf::Color(255, 255, 255); }

	sprite.setColor(color);

}

void Sprite::render(sf::RenderWindow& window) {

	sprite.setPosition(x, y);

	window.draw(sprite);

}

bool Sprite::contains(const float x, const float y) const {

	return sprite.getGlobalBounds().contains(x, y);

}
