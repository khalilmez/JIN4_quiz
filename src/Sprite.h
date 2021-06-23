#pragma once
#include "Element.h"
#include <SFML/Graphics.hpp>
#include <pugixml.hpp>

class Sprite : public Element {

public:

	explicit Sprite(pugi::xml_node const &node);

	explicit Sprite(const float x, const float y, std::string const &name, std::string const &textureFile, sf::Color const& color);

	void render(sf::RenderWindow& window) override;

	bool contains(const float x, const float y) const override;

	void Sprite::setColor(sf::Color const &color);

	bool verify() override { return false; };

	sf::Sprite sprite;

	sf::Color color;

private:

	sf::Texture texture;

};
