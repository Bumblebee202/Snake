#include "MainMenu.h"

MainMenu::MainMenu() : MenuBase()
{
	_selectedMenuItem = 0;
	_length = 5;
	_menu = new std::wstring[_length];
	_display = new ConsoleDisplay<wchar_t>();
	_game = new Game(_display);
	_selectedMenu = nullptr;

	GenerateMenu();
}

void MainMenu::GenerateMenu()
{
	*_menu = L"Start";
	*(_menu + 1) = L"Rating";
	*(_menu + 2) = L"Snake Color";
	*(_menu + 3) = L"Help";
	*(_menu + 4) = L"Exit";
}

void MainMenu::SelectMenuItem()
{
	std::wstring menuItem = *(_menu + _selectedMenuItem);
	
	if (menuItem._Equal(L"Start"))
	{
		Clear(60);
		if (_game == nullptr)
			_game = new Game(_display);
		_game->Start();
	}
	else if (menuItem._Equal(L"Rating"))
	{
		Clear(60);
		//_selectedMenu = 
	}
	else if (menuItem._Equal(L"Snake Color"))
	{
		Clear(60);
		//_selectedMenu = 
	}
	else if (menuItem._Equal(L"Help"))
	{
		Clear(60);
		//_selectedMenu =
	}
	else if (menuItem._Equal(L"Exit"))
		exit(0);
}

void MainMenu::Open()
{
	_close = false;
	int btnCode;
	Show(60);
	while (!_close)
	{
		btnCode = _getch();
		if (btnCode == 224)
			btnCode = _getch();

		switch (btnCode)
		{
		case 119:
		case 72:
			Up();
			Show(60);
			break;
		case 115:
		case 80:
			Down();
			Show(60);
			break;
		case 13:
			SelectMenuItem();
			break;
		}
	}
}
