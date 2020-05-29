#pragma once
#include "ItemBase.h"

class SpeedUp :	public ItemBase
{
public:
	SpeedUp();
	SpeedUp(int x, int y);

	std::wstring virtual Description() override;
	virtual void Interaction(Snake* snake) override;
};

