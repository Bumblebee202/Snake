#pragma once
#include "ItemBase.h"
class SpeedUp :	public ItemBase
{
public:
	SpeedUp();
	SpeedUp(int x, int y);

	virtual std::wstring Description() override;
};

