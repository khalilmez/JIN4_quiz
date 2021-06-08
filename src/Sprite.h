#pragma once
#include "Element.h"
#include <SFML/Graphics.hpp>
#include <pugixml.hpp>

class Sprite : public Element {

public:

	explicit Sprite(pugi::xml_node const &node);

	explicit Sprite(const float x, const float y, std::string const &name, std::string const &textureFile);

	void render(sf::RenderWindow& window) override;

	bool contains(const float x, const float y) const override;

private:

	sf::Texture texture;

	sf::Sprite sprite;

};
