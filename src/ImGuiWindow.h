#pragma once
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Element.h"
#include "imgui-SFML.h"
#include <map>
#include "ImguiElementTitle.h"
#include "ImguiElementInputInt.h"
#include "ImguiElementInputFloat.h"

class ImGuiWindow : public Element {

private :
	std::vector<std::shared_ptr<ImguiElementInputInt>> widgetsInt;
	std::vector<std::shared_ptr<ImguiElementInputFloat>> widgetsFloat;
	std::vector<std::shared_ptr<ImguiElementTitle>> widgetsTitle;

	sf::Clock deltaClock;
	std::string title;
	float width;
	float height;

public:

	explicit ImGuiWindow(std::string const& title);
	void init(sf::RenderWindow &window, std::string const &title, std::string const &content);
	void render(sf::RenderWindow &window) override;
	void addInputInt(std::string const& title, int expectedValue);
	void addInputFloat(std::string const& title, float expectedValue);
	std::string getTitle() const;
	bool verify() override;

	void setWidth(const float width);

	void setHeight(const float height);

};

