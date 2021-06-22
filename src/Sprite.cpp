#include "Sprite.h"
#include <iostream>
#include "LoseOnClickHandleEvent.h"
#include "MovableHandleEvent.h"
#include "WinOnClickHandleEvent.h"
#include "CutToWinOnClickHandleEvent.h"

Sprite::Sprite(pugi::xml_node const& node) :
	Element{ node.attribute("x").as_float(), node.attribute("y").as_float(), node.attribute("name").as_string() }
{

	if (!texture.loadFromFile(node.attribute("file").as_string())) { std::cout << "Error while loading texture.\n"; }

	auto angle = node.attribute("angle");
	if (angle) { this->angle = angle.as_float(); }

	auto red = node.attribute("r");
	auto green = node.attribute("g");
	auto blue = node.attribute("b");
	auto alpha = node.attribute("a");
	std::string handle = node.attribute("handle_strategy").as_string();
	std::vector<std::string> handles;
	std::string temp1 = "";
	for (int i = 0; i < handle.length(); ++i) {
		if (handle[i] == ' ') {
			handles.push_back(temp1);
			temp1 = "";
		}
		else {
			temp1.push_back(handle[i]);
		}

	}
	if (temp1 != " ")
		handles.push_back(temp1);

	for (auto& st : handles) {
		if (st == "movable") {
			eventHandler.push_back(std::move(std::make_shared<MovableHandleEvent>()));
		}
		if (st == "WinOnClick") {
			eventHandler.push_back(std::move(std::make_shared<WinOnClickHandleEvent>()));
		}
		if (st == "LoseOnClick") {
			eventHandler.push_back(std::move(std::make_shared<LoseOnClickHandleEvent>()));
		}
		if (st == "CutToWin") {
			eventHandler.push_back(std::move(std::make_shared<CutToWinOnClickHandleEvent>()));
		}
	}
	if (red && green && blue) {

		color.r = red.as_int();
		color.g = green.as_int();
		color.b = blue.as_int();

	}
	else {

		color.r = 255;
		color.g = 255;
		color.b = 255;

	}

	if (alpha) { color.a = alpha.as_int(); }

	sprite.setTexture(texture);
	sprite.setColor(color);
	auto boundaries = sprite.getGlobalBounds();
	sprite.setOrigin(boundaries.left + boundaries.width / 2, boundaries.top + boundaries.height / 2);
	sprite.setPosition(x, y);
	sprite.setRotation(this->angle);

}

Sprite::Sprite(const float x, const float y, std::string const &name, std::string const &textureFile, sf::Color const &color) : 
	Element{x, y, name}
{

	if (!texture.loadFromFile(textureFile)) {

		std::cout << "Cannot find texture.\n";

	}

	if (&color) { this->color = color; }
	else {
	
		this->color.r = 255;
		this->color.g = 255;
		this->color.b = 255;
	
	}

	sprite.setTexture(texture);
	sprite.setColor(color);
	sprite.setOrigin(x, y);
	sprite.setPosition(x, y);

}

void Sprite::render(sf::RenderWindow& window) {

	sprite.setPosition(x, y);
	sprite.setColor(color);
	sprite.setRotation(angle);

	window.draw(sprite);

}

bool Sprite::contains(const float x, const float y) const {

	return sprite.getGlobalBounds().contains(x, y);

}

void Sprite::setColor(sf::Color const &color) {

	this->color = color;

}
