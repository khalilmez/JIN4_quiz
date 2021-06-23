#include "ImguiElementTitle.h"

std::string ImguiElementTitle::getTitle() {
	return title;
}

void ImguiElementTitle::setTitle(std::string const& newTitle) {
	title = newTitle;
}

ImguiElementTitle::ImguiElementTitle(std::string const&  newTitle) 
{
	title = newTitle;
}
