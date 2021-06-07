#include "Sprite.h"
#include <iostream>

Sprite::Sprite(pugi::xml_node& node) :
	Element{ node.attribute("x").as_float(), node.attribute("y").as_float(), node.attribute("name").as_string() }
{

	if (!texture.loadFromFile(node.attribute("file").as_string())) { std::cout << "Error while loading texture.\n"; }

}

Sprite::Sprite(float x, float y, std::string name, std::string textureFile) : 
	Element{x, y, name}
{

	if (!texture.loadFromFile(textureFile)) {

		std::cout << "Cannot find texture.\n";

	}

}

void Sprite::render(sf::RenderWindow& window) const {

	sf::Sprite sprite;

	sprite.setPosition(x, y);

	sprite.setTexture(texture);

	window.draw(sprite);

}

bool Sprite::contains(const float x, const float y) const {

	sf::Sprite sprite;

	sprite.setPosition(x, y);

	sprite.setTexture(texture);

	sf::Rect<float> box = sprite.getGlobalBounds();

	return box.contains(x, y);

}