#pragma once
#include <string>
class ImguiElementInputFloat {
public:
	explicit ImguiElementInputFloat(std::string const& title, float expected);
	float& getRefFloat();
	float getResult() const;
	std::string getTitle() const;
	bool verify() const;
	void setTitle(std::string const& newTitle);
private:
	float result= 0;
	float expected = -9999;
	std::string title;
};