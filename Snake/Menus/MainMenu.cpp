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

MainMenu::~MainMenu()
{
	delete _button;
}

void MainMenu::GenerateMenu()
{
	*_menu = L"Start";
	*(_menu + 1) = L"Rating";
	*(_menu + 2) = L"Help";
	*(_menu + 3) = L"Exit";
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
		RatingMenu menu = RatingMenu(_display, _width);
		menu.Open();
	}
	else if (menuItem._Equal(L"Help"))
	{
		Help help = Help(_display, _width);
		help.Open();
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

		if (_button->IsUp(btnCode))
		{
			Up();
			Show();
		}
		else if (_button->IsDown(btnCode))
		{
			Down();
			Show();
		}
		else if (_button->IsEnter(btnCode))
			SelectMenuItem();
	}
}
