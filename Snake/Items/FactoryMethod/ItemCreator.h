#pragma once
#include "../ItemBase.h"

class ItemCreator
{
public:
	virtual ItemBase* Create(int x, int y) = 0;
};

