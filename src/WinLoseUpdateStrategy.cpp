#include "WinLoseUpdateStrategy.h"
#include "Screen.h"
#include "Game.h"

Screen* WinLoseUpdateStrategy::update(Screen& screen) {

	clock++;

	if(screen.isCompleted()) {

		screen.setCompleted(false);

		clock = 0;
	
		return screen.getGame()->getCurrentLevel();
	
	}

	return &screen;

}