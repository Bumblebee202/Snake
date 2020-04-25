#pragma once
#include "LevelBase.h"


class FirstLevel : public LevelBase
{
protected:
	virtual void GenerateField() override;
public:
	FirstLevel();
	virtual std::wstring GetLevel() const override;
};