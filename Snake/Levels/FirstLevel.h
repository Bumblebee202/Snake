#pragma once
#include "LevelBase.h"

class FirstLevel : public LevelBase
{
public:
	FirstLevel();
	int virtual GetLevel() const override;
	void virtual Loading() override;
};