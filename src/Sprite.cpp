#include "Sprite.h"
#include <iostream>

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