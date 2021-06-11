#include "WinLoseUpdateStrategy.h"
#include "Screen.h"
#include "Game.h"
#include "Sprite.h"
#include <math.h>

Screen* WinLoseUpdateStrategy::update(Screen& screen) {

	auto stripes = screen.getElementByName("stripes");
	auto button = screen.getElementByName("button");

	if (button) {
	
		if (360 * ( 1 - 0.001 * clock) >= 0) { button->setAngle(360 * (1 - 0.001 * clock)); }
		else { button->setAngle(0); }
	
	}
	if (stripes) {

		if(255 * 0.001 * clock <= 255) { ((Sprite*)stripes)->setColor(sf::Color(255, 255, 255, 255 * 0.001 * clock)); }
		else { ((Sprite*)stripes)->setColor(sf::Color(255, 255, 255)); }
	
	}

	clock++;

	if(screen.isCompleted()) {

		screen.setCompleted(false);

		clock = 0;
	
		return screen.getGame()->getCurrentLevel();
	
	}

	return &screen;

}