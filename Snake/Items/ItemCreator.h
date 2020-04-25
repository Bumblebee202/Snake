#pragma once
#include "ItemBase.h"

class ItemCreator
{
public:
	virtual ItemBase* Create() = 0;
};

