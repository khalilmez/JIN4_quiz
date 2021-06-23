#include "ImguiElementInputInt.h"


ImguiElementInputInt::ImguiElementInputInt(std::string const& newTitle, int expecetedValue) : expected{expecetedValue},
title{ newTitle }
{
}

int& ImguiElementInputInt::getRefInt()
{
    return result;
}


int ImguiElementInputInt::getResult() const {
    return result;
}

std::string ImguiElementInputInt::getTitle() const {
    return title;
}

bool ImguiElementInputInt::verify() const
{
    return result==expected;
}

void ImguiElementInputInt::setTitle(std::string const& newTitle) {
    title = newTitle;
}
