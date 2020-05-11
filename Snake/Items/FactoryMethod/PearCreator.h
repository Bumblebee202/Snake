#pragma once
#include "ItemCreator.h"
#include "../Pear.h"

class PearCreator : public ItemCreator
{
public:
	virtual ItemBase* Create(int x, int y) override
	{
		return new Pear(x, y);
	}
};

