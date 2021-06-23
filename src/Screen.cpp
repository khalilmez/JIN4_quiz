#include "Screen.h"
#include "UpdateStrategy.h"
#include "EventHandler.h"
#include <pugixml.hpp>
#include "Text.h"
#include "Sprite.h"
#include "Rectangle.h"
#include "Circle.h"
#include "WinLoseUpdateStrategy.h"
#include "ImGuiWindow.h"
#include "LevelUpdateStrategy.h"

Screen::Screen(Game* game, pugi::xml_node const &node) :
	game{game}
{

	auto red = node.attribute("r");
	auto green = node.attribute("g");
	auto blue = node.attribute("b");
	if (red && green && blue) {

		backgroundColor = sf::Color(red.as_int(), green.as_int(), blue.as_int());

	}
	else {

		backgroundColor = sf::Color();

	}


	if (!strcmp(node.attribute("update_strategy").as_string(), "win_lose")) {

		updateStrategy = std::move(std::make_unique<WinLoseUpdateStrategy>());

	}
	else if (!strcmp(node.attribute("update_strategy").as_string(), "levelSimple")) {

		updateStrategy = std::move(std::make_unique<LevelUpdateStrategy>());

	}
	else { updateStrategy = nullptr; }

	for (auto& child : node.children()) {

		if(!strcmp(child.name(), "text")) { 
		
			addElement(std::move(std::make_unique<Text>(child)));
		
		}
		else if (!strcmp(child.name(), "sprite")) {

			addElement(std::move(std::make_unique<Sprite>(child)));

		}
		else if (!strcmp(child.name(), "rectangle")) {

			addElement(std::move(std::make_unique<Rectangle>(child)));

		}
		else if (!strcmp(child.name(), "circle")) {

			addElement(std::move(std::make_unique<Circle>(child)));

		}
		else if (!strcmp(child.name(), "imgui")) {

			auto window = ImGuiWindow(child.attribute("title").as_string());

			window.setX(child.attribute("x").as_float());
			window.setY(child.attribute("y").as_float());
			window.setName(child.attribute("name").as_string());
			window.setWidth(child.attribute("width").as_float());
			window.setHeight(child.attribute("height").as_float());

			for (pugi::xml_node tool = child.child("int"); tool; tool = tool.next_sibling("int"))
			{
				window.addInputInt(tool.attribute("title").as_string(), tool.attribute("expected").as_int());
			}
			for (pugi::xml_node tool = child.child("float"); tool; tool = tool.next_sibling("int"))
			{
				window.addInputFloat(tool.attribute("title").as_string(), tool.attribute("expected").as_float());
			}
			addElement(std::move(std::make_unique<ImGuiWindow>(window)));
		}

	}

}

Screen::Screen(Game* game, std::unique_ptr<LevelUpdateStrategy> updateStrategy, sf::Color const &backgroundColor) :
	game{ game },
	backgroundColor{ backgroundColor }
{
	this->updateStrategy = std::move(updateStrategy);

}

void Screen::render(sf::RenderWindow& window) const {

	window.clear(backgroundColor);

	for (auto& element : elements) {

		element->render(window);

	}

	window.display();

}

void Screen::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
	
	for (auto& element : elements) {
		std::vector<std::shared_ptr<EventHandler>> eventHandlers = element->getEventHandlers();
		for (auto& eventHandler : eventHandlers) {
			eventHandler->handle(std::move(element),*this, event, window);

		}
	}

}

Screen* Screen::update() {

	return updateStrategy->update(*this);

}

void Screen::addElement(std::unique_ptr<Element> element) {

	elements.push_back(std::move(element));

}

bool Screen::isCompleted() const {

	return completed;

}

void Screen::setCompleted(const bool c) {

	completed = c;

}

Element* Screen::getElement(const int id) const {

	if (id < 0 || id >= elements.size()) { return nullptr; }

	return elements[id].get();

}

Element* Screen::getElementByName(std::string const& name) const {

	for (auto& element : elements) {

		if (element->getName() == name) { return element.get(); }

	}

	return nullptr;

}

int Screen::getNumberOfElements() const {

	return elements.size();

}

bool Screen::isFailed() const {

	return failed;

}

void Screen::setFailed(const bool c) {

	failed = c;

}

Game* Screen::getGame() const {

	return game;

}
