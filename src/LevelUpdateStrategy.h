#pragma once
#include "UpdateStrategy.h"

class LevelUpdateStrategy : public UpdateStrategy {
	/*L'update de presque tout les levels assez "simple" */
public:

	Screen* update(Screen& screen) override;

};