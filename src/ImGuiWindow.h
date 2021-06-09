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

	float width;
	float height;

public:

	explicit ImGuiWindow(std::string const &title, std::string const &content, const bool inputFloat, std::string const &titleFloat, const bool inputInt, std::string const &titleInt, const bool inputText, std::string const &titleText, const bool button, std::string const &buttonTitle, const bool menu);
	void init(sf::RenderWindow &window, std::string const &title, std::string const &content);
	void render(sf::RenderWindow &window) override;
	std::string getTitle() const;
	std::string getContent() const;
	bool hasInt() const;
	std::string getTitleInt() const;
	bool hasFloat() const;
	int getInt() const;

	void setWidth(const float width);

	void setHeight(const float height);

};

