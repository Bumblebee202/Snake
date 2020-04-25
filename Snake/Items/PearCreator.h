#pragma once
#include "ItemCreator.h"
#include "Pear.h"

class PearCreator : public ItemCreator
{
public:
	virtual ItemBase* Create() override
	{
		return new Pear();
	}
};

