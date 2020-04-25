#pragma once
#include "ItemCreator.h"
#include "Apple.h"

class AppleCreator : public ItemCreator
{
public:
	virtual ItemBase* Create() override
	{
		return new Apple();
	}
};

