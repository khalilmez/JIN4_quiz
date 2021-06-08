#include "ImGuiWindow.h"
#include "imgui-SFML.h"
#include <iostream>
#include "imgui.h"

ImGuiWindow::ImGuiWindow(std::string title, std::string content, bool inputFloat, std::string titleFloat, bool inputInt, std::string titleInt, bool inputText, std::string titleText, bool button, std::string  buttonTitle, bool menu) :
Element(0,0,"ImGuiWindow"),inputFloat(inputFloat),
inputInt(inputInt),
inputText(inputText),
button(button),
menu(menu),
title(title),
content(content),
titleFloat(titleFloat),
titleInt(titleInt),
titleText(titleText),
buttonTitle(buttonTitle)
{
}

void ImGuiWindow::init(sf::RenderWindow window, std::string titleInit, std::string contentInit) {
	ImGui::SFML::Init(window);
	title = titleInit;
	content = contentInit;
	sf::Font font;
	if (!font.loadFromFile("resources/Bernadette.ttf")) {
		std::cout << "Error" << std::endl;
	}
}

void ImGuiWindow::render(sf::RenderWindow& window) {
	ImGui::SFML::Update(window, deltaClock.restart());
	ImGui::Begin(title.c_str());
	if (inputFloat) {
		ImGui::InputFloat(titleFloat.c_str(), &f_input);
	}
	if (inputInt) {
		ImGui::InputInt(titleFloat.c_str(), &i_input);
	}
	if (inputText) {
		ImGui::InputText(titleText.c_str(), reponseText, IM_ARRAYSIZE(reponseText));
	}
	if (button) {
		ImGui::Button(buttonTitle.c_str());
	}
	ImGui::Text(content.c_str());

	ImGui::End();
	ImGui::SFML::Render(window);
}