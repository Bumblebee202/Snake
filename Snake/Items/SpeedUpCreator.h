#pragma once
#include "ItemCreator.h"
#include "SpeedUp.h"

class SpeedUpCreator : public ItemCreator
{
public:
	virtual ItemBase* Create(int x, int y) override
	{
		return new SpeedUp(x, y);
	}
};

