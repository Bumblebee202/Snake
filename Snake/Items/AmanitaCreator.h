#pragma once
#include "ItemCreator.h"
#include "Amanita.h"

class AmanitaCreator : public ItemCreator
{
public:
	virtual ItemBase* Create(int x, int y) override
	{
		return new Amanita(x, y);
	}
};

