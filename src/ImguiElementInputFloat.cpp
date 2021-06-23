#include "ImguiElementInputFloat.h"


ImguiElementInputFloat::ImguiElementInputFloat(std::string const& newTitle, float expecetedValue) : expected{expecetedValue},
title{ newTitle }
{
}

float& ImguiElementInputFloat::getRefFloat()
{
    return result;
}


float ImguiElementInputFloat::getResult() const {
    return result;
}

std::string ImguiElementInputFloat::getTitle() const {
    return title;
}

bool ImguiElementInputFloat::verify() const
{
    return result==expected;
}

void ImguiElementInputFloat::setTitle(std::string const& newTitle) {
    title = newTitle;
}
