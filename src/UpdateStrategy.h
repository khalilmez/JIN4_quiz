#pragma once
#include "Screen.h"

class UpdateStrategy {

public: 

	virtual void update(Screen &screen) = 0;

};