#pragma once
#include "MenuBase.h"

class Pause : public MenuBase
{
protected:
	virtual void GenerateMenu() override;

public:
	Pause(DisplayBase<wchar_t>* display);

	void virtual SelectMenuItem() override;
};

