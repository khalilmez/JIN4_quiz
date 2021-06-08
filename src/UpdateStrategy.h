#pragma once

class Screen;

class UpdateStrategy {

public: 

	virtual ~UpdateStrategy() = default;
	virtual Screen* update(Screen &screen) = 0;

};