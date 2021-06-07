#pragma once
#include "Element.h"
#include <SFML/Graphics.hpp>

class Sprite : public Element {

public:

	explicit Sprite(float x, float y, std::string name, std::string textureFile);

	void render(sf::RenderWindow& window) const override;

private:

	sf::Texture texture;

};