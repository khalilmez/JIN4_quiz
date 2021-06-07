#pragma once
#include "Element.h"
#include <SFML/Graphics.hpp>
#include <pugixml.hpp>

class Sprite : public Element {

public:

	explicit Sprite(pugi::xml_node &node);

	explicit Sprite(float x, float y, std::string name, std::string textureFile);

	void render(sf::RenderWindow& window) const override;

	bool contains(const float x, const float y) const override;

private:

	sf::Texture texture;

};