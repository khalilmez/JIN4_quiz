#pragma once
#include "UpdateStrategy.h"

class Level3UpdateStrategy : public UpdateStrategy {

public:

	Screen* update(Screen& screen) override;

};