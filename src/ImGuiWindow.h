#pragma once
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Element.h"
#include "imgui-SFML.h"

class ImGuiWindow : public Element {
private :
	std::string title;
	std::string content;
	sf::Clock deltaClock;
	bool inputFloat = false;
	std::string titleFloat;
	float f_input;
	bool inputInt = false;
	std::string titleInt;
	int i_input;
	bool inputText = false;
	std::string titleText;
	char reponseText[50];
	bool button = false;
	std::string buttonTitle;
	bool menu = false;

public:
	explicit ImGuiWindow();
	explicit ImGuiWindow(std::string title, std::string content, bool inputFloat, std::string titleFloat, bool inputInt, std::string titleInt, bool inputText, std::string titleText, bool button, std::string  buttonTitle, bool menu);
	void init(sf::RenderWindow window, std::string title, std::string content_f);
	void render(sf::RenderWindow &window) override;
	bool contains(const float x, const float y) const override;
};

