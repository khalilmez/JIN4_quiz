#pragma once
#include "UpdateStrategy.h"


class Level1UpdateStrategy : public UpdateStrategy {

public:

	Screen* update(Screen& screen) override;

};