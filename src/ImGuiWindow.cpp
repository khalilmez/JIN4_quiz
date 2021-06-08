#include "ImGuiWindow.h"
#include "imgui-SFML.h"
#include <iostream>
#include "imgui.h"

ImGuiWindow::ImGuiWindow(std::string const& title, std::string const& content, const bool inputFloat, std::string const& titleFloat, const bool inputInt, std::string const& titleInt, const bool inputText, std::string const& titleText, const bool button, std::string const& buttonTitle, const bool menu) :
	Element{ 0,0,"ImGuiWindow" },
	inputFloat{ inputFloat },
	inputInt{ inputInt },
	inputText{ inputText },
	button{ button },
	menu{ menu },
	title{ title },
	content{ content },
	titleFloat{ titleFloat },
	titleInt{ titleInt },
	titleText{ titleText },
	buttonTitle{ buttonTitle }
{}

void ImGuiWindow::init(sf::RenderWindow &window, std::string const& title, std::string const& content) {

	ImGui::SFML::Init(window);

	this->title = title;
	this->content = content;

	sf::Font font;

	if (!font.loadFromFile("resources/Bernadette.ttf")) { std::cout << "Error while loading font.\n"; }

}

void ImGuiWindow::render(sf::RenderWindow &window) {

	ImGui::SFML::Update(window, deltaClock.restart());
	ImGui::Begin(title.c_str());

	ImGui::SetWindowPos(ImVec2(x, y), NULL);

	if (inputFloat) { ImGui::InputFloat(titleFloat.c_str(), &f_input); }
	if (inputInt) { ImGui::InputInt(titleFloat.c_str(), &i_input); }
	if (inputText) { ImGui::InputText(titleText.c_str(), reponseText, IM_ARRAYSIZE(reponseText)); }
	if (button) { ImGui::Button(buttonTitle.c_str()); }
	
	ImGui::Text(content.c_str());

	ImGui::End();
	ImGui::SFML::Render(window);

}