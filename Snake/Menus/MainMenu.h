#pragma once
#include "MenuBase.h"
#include "../Game.h"

class MainMenu : public MenuBase
{
private:
	BaseApp* _game;
	MenuBase* _selectedMenu;

protected:
	virtual void GenerateMenu() override;

public:
	MainMenu();

	void virtual SelectMenuItem() override;
	void virtual Open() override;
};

