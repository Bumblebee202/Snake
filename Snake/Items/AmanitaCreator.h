#pragma once
#include "ItemCreator.h"
#include "Amanita.h"

class AmanitaCreator : public ItemCreator
{
public:
	virtual ItemBase* Create() override
	{
		return new Amanita();
	}
};

