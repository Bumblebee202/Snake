#pragma once
#include "MenuBase.h"
#include "Help.h"
#include "../Game/Game.h"

class MainMenu : public MenuBase
{
private:
	BaseApp* _game;
	MenuBase* _selectedMenu;

protected:
	virtual void GenerateMenu() override;

public:
	MainMenu();
	~MainMenu();

	void virtual SelectMenuItem() override;
	void virtual Open() override;
};

