#include "WinLoseUpdateStrategy.h"
#include "Screen.h"
#include "Game.h"

Screen* WinLoseUpdateStrategy::update(Screen& screen) {

	if(screen.isCompleted()) {
	
		return screen.getGame()->getCurrentLevel();
	
	}

	return &screen;

}