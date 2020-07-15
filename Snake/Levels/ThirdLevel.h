#pragma once
#include "LevelBase.h"

class ThirdLevel : public LevelBase
{
public:
	ThirdLevel();
	int virtual GetLevel() const override;
	void virtual Loading() override;
};