#pragma once
#include "Screen.h"

class UpdateStrategy {

public: 

	virtual ~UpdateStrategy() = default;
	virtual void update(Screen &screen) = 0;

};