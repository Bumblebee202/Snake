#pragma once
#include "ItemBase.h"

class Amanita :	public ItemBase
{
public:
	Amanita();
	Amanita(int x, int y);

	virtual std::wstring Description() override;
	virtual void Interaction(Snake* snake) override;
};

