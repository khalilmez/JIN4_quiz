#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Element.h"
#include "imgui-SFML.h"
#include "ImGuiWindow.h"
#include <string>
#include <iostream>

/* Builder de fenêtres ImGui.
(patron de conception "monteur/builder").
*/
class ImGuiWindowBuilder{

private:

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

	ImGuiWindowBuilder* withTitle(std::string const& title);
	ImGuiWindowBuilder* withContent(std::string const& content);
	ImGuiWindowBuilder* withInputFloat(std::string const& title);
	ImGuiWindowBuilder* withInputInt(std::string const& title);
	ImGuiWindowBuilder* withInputText(std::string const& title_inputText);
	ImGuiWindowBuilder* withButton(std::string const& title);
	ImGuiWindowBuilder* withMenu();
	ImGuiWindow build() const;

};

