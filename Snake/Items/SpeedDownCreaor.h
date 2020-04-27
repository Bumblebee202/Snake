#pragma once
#include "ItemCreator.h"
#include "SpeedDown.h"

class SpeedDownCreaor :	public ItemCreator
{
public:
	virtual ItemBase* Create(int x, int y) override
	{
		return new SpeedDown(x, y);
	}
};

