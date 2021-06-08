#include "Sprite.h"
#include <iostream>

Sprite::Sprite(pugi::xml_node const& node) :
	Element{ node.attribute("x").as_float(), node.attribute("y").as_float(), node.attribute("name").as_string() }
{

	if (!texture.loadFromFile(node.attribute("file").as_string())) { std::cout << "Error while loading texture.\n"; }

	sprite.setTexture(texture);

}

Sprite::Sprite(const float x, const float y, std::string const &name, std::string const &textureFile) : 
	Element{x, y, name}
{

	if (!texture.loadFromFile(textureFile)) {

		std::cout << "Cannot find texture.\n";

	}

	sprite.setTexture(texture);

}

void Sprite::render(sf::RenderWindow& window) {

	sprite.setPosition(x, y);

	window.draw(sprite);

}

bool Sprite::contains(const float x, const float y) const {

	return sprite.getGlobalBounds().contains(x, y);

}
