#pragma once
// #include "Screen.h"

class Screen;

class UpdateStrategy {

public: 

	virtual ~UpdateStrategy() = default;
	virtual Screen* update(Screen &screen) = 0;

};