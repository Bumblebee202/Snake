#pragma once
#include "ItemCreator.h"
#include "Apple.h"

class AppleCreator : public ItemCreator
{
public:
	virtual ItemBase* Create(int x, int y) override
	{
		return new Apple(x, y);
	}
};

