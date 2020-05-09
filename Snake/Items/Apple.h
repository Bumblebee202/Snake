#pragma once
#include "ItemBase.h"

class Apple : public ItemBase
{
public:
	Apple();
	Apple(int x, int y);

	virtual std::wstring Description() override;
	//virtual void Effect(Snake* snake) override;
};

