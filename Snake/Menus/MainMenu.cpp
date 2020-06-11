#include "MainMenu.h"

MainMenu::MainMenu() : MenuBase()
{
	_width = 60;
	_selectedMenuItem = 0;
	_length = 5;
	_menu = new std::wstring[_length];
	_display = new ConsoleDisplay<wchar_t>();
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
	
	Clear();

	if (menuItem._Equal(L"Start"))
	{
		_game = new Game(_display);
		_game->Start();

		_display->SetWidnowSize(60, 30);

		delete _game;
		_game = nullptr;
	}
	else if (menuItem._Equal(L"Rating"))
	{
		//_selectedMenu = 
	}
	else if (menuItem._Equal(L"Snake Color"))
	{
		//_selectedMenu = 
	}
	else if (menuItem._Equal(L"Help"))
	{
		Help help = Help(_display, _width);
		help.Open();
		//_selectedMenu =
	}
	else if (menuItem._Equal(L"Exit"))
		exit(0);

	Show();
}

void MainMenu::Open()
{
	_close = false;
	int btnCode;
	Show();
	while (!_close)
	{
		btnCode = _getch();
		if (btnCode == 224)
			btnCode = _getch();

		if (btnCode == _button->GetUp())
		{
			Up();
			Show();
		}
		else if (btnCode == _button->GetDown())
		{
			Down();
			Show();
		}
		else if (btnCode == _button->GetEnter())
			SelectMenuItem();
	}
}
