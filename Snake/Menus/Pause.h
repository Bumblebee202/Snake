#pragma once
#include "MenuBase.h"

class Pause : public MenuBase
{
protected:
	virtual void GenerateMenu() override;

public:
	Pause(IDisplay<wchar_t>* display, int width);

	void virtual SelectMenuItem() override;
};

