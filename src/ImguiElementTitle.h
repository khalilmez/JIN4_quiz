#pragma once
#include <string>
class ImguiElementTitle{
	/*Cette classe gère le titre de la fenêtre ImGui*/
public:
	explicit ImguiElementTitle(std::string const & title);
	std::string getTitle();
	void setTitle(std::string const& newTitle);
private:
	std::string title;
};