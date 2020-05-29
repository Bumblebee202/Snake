#pragma once
#include "ItemBase.h"

class SpeedDown : public ItemBase
{
public:
	SpeedDown();
	SpeedDown(int x, int y);

	virtual std::wstring Description() override;
	virtual void Interaction(Snake* snake) override;
};

