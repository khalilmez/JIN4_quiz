#include "ImguiElementInputInt.h"


ImguiElementInputInt::ImguiElementInputInt(std::string const& newTitle, int expecetedValue) : expected{expecetedValue},
title{ newTitle }
{
}

int& ImguiElementInputInt::getRefInt()
{
    return input;
}


int ImguiElementInputInt::getInput() const {
    return input;
}

std::string ImguiElementInputInt::getTitle() const {
    return title;
}

bool ImguiElementInputInt::verify() const
{
    return input==expected;
}

void ImguiElementInputInt::setTitle(std::string const& newTitle) {
    title = newTitle;
}
