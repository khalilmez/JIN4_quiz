#pragma once
#include <string>
class ImguiElementInputInt {
public:
	explicit ImguiElementInputInt(std::string const& title, int expected);
	int& getRefInt();
	int getResult() const;
	std::string getTitle() const;
	bool verify() const;
	void setTitle(std::string const& newTitle);
private:
	int result= 0;
	int expected = -9999;
	std::string title;
};