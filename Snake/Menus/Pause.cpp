#include "Pause.h"

Pause::Pause(DisplayBase<wchar_t>* display) : MenuBase(display)
{
	_selectedMenuItem = 0;
	_length = 2;
	_menu = new std::wstring[2];
	GenerateMenu();
}

void Pause::SelectMenuItem()
{
	std::wstring menuItem = *(_menu + _selectedMenuItem);

	if (menuItem._Equal(L"Continue"))
	{
		Clear(60);
		_selectedMenuItem = 0;
		_close = true;
	}
	else if (menuItem._Equal(L"Exit"))
	{

	}
}

void Pause::GenerateMenu()
{
	*_menu = L"Continue";
	*(_menu + 1) = L"Exit";
}