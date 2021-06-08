#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Element.h"
#include "imgui-SFML.h"
#include "ImGuiWindow.h"
#include <string>
#include <iostream>

class ImGuiWindowBuilder{
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
	ImGuiWindowBuilder();
	ImGuiWindowBuilder& withTitle(std::string title);
	ImGuiWindowBuilder& withContent(std::string content);
	ImGuiWindowBuilder& withInputFloat(std::string title);
	ImGuiWindowBuilder& withInputInt(std::string title);
	ImGuiWindowBuilder& withInputText(std::string title_inputText);
	ImGuiWindowBuilder& withButton(std::string title);
	ImGuiWindowBuilder& withMenu();
	ImGuiWindow& build();


};

