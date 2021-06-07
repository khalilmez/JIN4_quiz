#pragma once
#include "UpdateStrategy.h"


class Level2UpdateStrategy : public UpdateStrategy {
public:
	Screen* update(Screen& screen) override;

};