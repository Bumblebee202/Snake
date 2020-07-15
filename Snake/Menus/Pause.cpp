#include "Pause.h"

Pause::Pause(BaseApp* game, IDisplay<wchar_t>* display, int rowWidth) : MenuBase(display, rowWidth)
{
	_game = game;
	_selectedMenuItem = 0;
	_length = 2;
	_menu = new std::wstring[2];

	GenerateMenu();
}

void Pause::SelectMenuItem()
{
	std::wstring menuItem = *(_menu + _selectedMenuItem);
	Clear();

	if (menuItem._Equal(L"Continue"))
		_selectedMenuItem = 0;
	else if (menuItem._Equal(L"Exit"))
		_game->Stop();

	_close = true;
}

void Pause::GenerateMenu()
{
	*_menu = L"Continue";
	*(_menu + 1) = L"Exit";
}