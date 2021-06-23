#pragma once
#include "UpdateStrategy.h"

class LevelUpdate : public UpdateStrategy {

public:

	Screen* update(Screen& screen) override;

};