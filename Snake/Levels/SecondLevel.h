#pragma once
#include "LevelBase.h"

class SecondLevel :	public LevelBase
{
public:
	SecondLevel();
	int virtual GetLevel() const override;
	void virtual Loading() override;
};

