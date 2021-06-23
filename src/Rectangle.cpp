#include "Rectangle.h"
#include <iostream>
#include "LoseOnClickHandleEvent.h"
#include "MovableHandleEvent.h"
#include "WinOnClickHandleEvent.h"
#include "CutToWinOnClickHandleEvent.h"

Rectangle::Rectangle(pugi::xml_node const &node) : 
	Element{ node.attribute("x").as_float(), node.attribute("y").as_float(), node.attribute("name").as_string() },
	width{ node.attribute("width").as_float() },
	height{ node.attribute("height").as_float() }
{

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
			eventHandlers.push_back(std::move(std::make_shared<MovableHandleEvent>()));
		}
		if (st == "WinOnClick") {
			eventHandlers.push_back(std::move(std::make_shared<WinOnClickHandleEvent>()));
		}
		if (st == "LoseOnClick") {
			eventHandlers.push_back(std::move(std::make_shared<LoseOnClickHandleEvent>()));
		}
		if (st == "CutToWin") {
			eventHandlers.push_back(std::move(std::make_shared<CutToWinOnClickHandleEvent>()));
		}
	}
	if (red && green && blue) {

		color.r = red.as_int();
		color.g = green.as_int();
		color.b = blue.as_int();

	}

	if (alpha) { color.a = alpha.as_int(); }

	rectangle.setSize(sf::Vector2f(width, height));
	auto boundaries = rectangle.getGlobalBounds();
	rectangle.setOrigin(boundaries.left + boundaries.width / 2, boundaries.top + boundaries.height / 2);
	rectangle.setPosition(x, y);
	rectangle.setFillColor(color);
	rectangle.setRotation(this->angle);

}

Rectangle::Rectangle(const float x, const float y, std::string const &name, const float width, const float height, sf::Color const &color) :
	Element{ x, y, name },
	color{ color },
	width{ width },
	height{ height }
{

	rectangle.setSize(sf::Vector2f(width, height));
	rectangle.setOrigin(x, y);
	rectangle.setPosition(x, y);
	rectangle.setFillColor(color);

}

void Rectangle::render(sf::RenderWindow &window) {

	rectangle.setSize(sf::Vector2f(width, height));
	rectangle.setPosition(x, y);
	rectangle.setFillColor(color);
	rectangle.setRotation(angle);

	window.draw(rectangle);

}

bool Rectangle::contains(const float x, const float y) const
{
	if (this->x - x <= width / 2 && x - this->x <= width / 2 && this->y - y <= height / 2 && y - this->y <= height / 2) {

		return true;

	}

	return false;

}

sf::Color Rectangle::getColor() const
{
	return color;
}

float Rectangle::getWidth() const {
	return width;
}

float Rectangle::getHeight() const {
	return height;
}