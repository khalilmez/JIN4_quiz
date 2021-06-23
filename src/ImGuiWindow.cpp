#include "ImGuiWindow.h"
#include "imgui-SFML.h"
#include <iostream>
#include "imgui.h"
#include "SFML/Graphics.hpp"
#include "ImguiHandleEvent.h"

ImGuiWindow::ImGuiWindow(std::string const& title) : Element(0,0,"ImGuiWindow")
{
	eventHandlers.push_back(std::move(std::make_shared<ImguiHandleEvent>()));
	widgetsTitle.push_back(std::move(std::make_shared<ImguiElementTitle>(title)));
}

void ImGuiWindow::init(sf::RenderWindow &window, std::string const& title, std::string const& content) {

	ImGui::SFML::Init(window);

	this->title = title;

	sf::Font font;

	if (!font.loadFromFile("resources/Bernadette.ttf")) { std::cout << "Error while loading font.\n"; }

}

void ImGuiWindow::render(sf::RenderWindow &window) {

	ImGui::SFML::Update(window, deltaClock.restart());
	if (widgetsTitle.size() > 0) {
		ImGui::Begin(widgetsTitle[0]->getTitle().c_str());
	}
	else {
		ImGui::Begin("Error loading Title");
	}

	ImGui::SetWindowPos(ImVec2(x, y), NULL);
	ImGui::SetWindowSize(ImVec2(width, height), NULL);

	for (auto& widget : widgetsInt) {
		ImGui::InputInt(widget->getTitle().c_str(), &widget->getRefInt());
	}

	for (auto& widget : widgetsFloat) {
		ImGui::InputFloat(widget->getTitle().c_str(), &widget->getRefFloat());
	}

	ImGui::End();
	ImGui::SFML::Render(window);
}

void ImGuiWindow::addInputInt(std::string const& title, int expectedValue)
{
	widgetsInt.push_back(std::move(std::make_shared<ImguiElementInputInt>(title, expectedValue)));
}

void ImGuiWindow::addInputFloat(std::string const& title, float expectedValue)
{
	widgetsFloat.push_back(std::move(std::make_shared<ImguiElementInputFloat>(title, expectedValue)));
}

void ImGuiWindow::setWidth(const float width) {

	this->width = width;

}

void ImGuiWindow::setHeight(const float height) {

	this->height = height;

}

bool ImGuiWindow::verify()
{
	for (auto& widget : widgetsInt) {
		if (!widget->verify()) {
			return false;
		}
	}
	for (auto& widget : widgetsFloat) {
		if (!widget->verify()) {
			return false;
		}
	}
	return true;
}
