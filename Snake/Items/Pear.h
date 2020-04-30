#pragma once
#include "ItemBase.h"

class Pear : public ItemBase
{
public:
	Pear();
	Pear(int x, int y);

	virtual std::wstring Description() override;
};

