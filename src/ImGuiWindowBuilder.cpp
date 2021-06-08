#include "ImGuiWindowBuilder.h"
#include "imgui-SFML.h"
#include "imgui.h"
#include "ImGuiWindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

ImGuiWindowBuilder* ImGuiWindowBuilder::withTitle(std::string const& title) {
	this->title = title;
	return this;
}

ImGuiWindowBuilder* ImGuiWindowBuilder::withContent(std::string const& content) {
	this->content = content;
	return this;
}

ImGuiWindowBuilder* ImGuiWindowBuilder::withInputFloat(std::string const& titleFloat) {
	inputFloat = true;
	this->titleFloat = titleFloat;
	return this;
}

ImGuiWindowBuilder* ImGuiWindowBuilder::withInputInt(std::string const& titleInt) {
	inputInt = true;
	this->titleInt = titleInt;
	return this;
}

ImGuiWindowBuilder* ImGuiWindowBuilder::withInputText(std::string const& title_inputText) {
	inputText = true;
	titleText = title_inputText;
	return this;
}
ImGuiWindowBuilder* ImGuiWindowBuilder::withButton(std::string const& titleButton) {
	button = true;
	buttonTitle = titleButton;
	return this;
}
ImGuiWindowBuilder* ImGuiWindowBuilder::withMenu() {
	menu = true;
	return this;
}

ImGuiWindow ImGuiWindowBuilder::build() const {
	auto imgui = ImGuiWindow(title, content, inputFloat, titleFloat, inputInt, titleInt, inputText, titleText, button, buttonTitle, menu);
	return imgui;
}