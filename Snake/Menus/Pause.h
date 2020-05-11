#pragma once
#include "MenuBase.h"
#include "../BaseApp.h"

class Pause : public MenuBase
{
private:
	BaseApp* _game;
protected:
	virtual void GenerateMenu() override;

public:
	Pause(BaseApp* game, IDisplay<wchar_t>* display, int width);

	void virtual SelectMenuItem() override;
};

