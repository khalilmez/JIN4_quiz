#include "ImguiElementInputFloat.h"


ImguiElementInputFloat::ImguiElementInputFloat(std::string const& newTitle, float expecetedValue) : expected{expecetedValue},
title{ newTitle }
{
}

float& ImguiElementInputFloat::getRefFloat()
{
    return input;
}


float ImguiElementInputFloat::getInput() const {
    return input;
}

std::string ImguiElementInputFloat::getTitle() const {
    return title;
}

bool ImguiElementInputFloat::verify() const
{
    return input==expected;
}

void ImguiElementInputFloat::setTitle(std::string const& newTitle) {
    title = newTitle;
}
