#pragma once
#include "EventHandler.h"

class CutToWinOnClickHandleEvent : public EventHandler {
	/*Cette strategie concerne les éléments qui doivent être coupé de l'écran pour gagner
	* Comme le niveau ou on doit déplacer le carré en dehors de l'écran.
	*/
public:

	void handle(std::unique_ptr<Element>& element, Screen &screen, sf::Event const &event, sf::RenderWindow const &window) override;

};