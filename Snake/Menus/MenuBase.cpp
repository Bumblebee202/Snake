#include "MenuBase.h"

MenuBase::MenuBase()
{
	_close = false;
	_selectedMenuItem = -1;
	_length = 0;
	_menu = nullptr;
	_display = nullptr;
	_width = -1;
}

MenuBase::MenuBase(IDisplay<wchar_t>* display, int width)
{
	_close = false;
	_width = width;
	_display = display;
	_selectedMenuItem = -1;
	_length = 0;
	_menu = nullptr;
}

MenuBase::MenuBase(std::wstring* menu, int lenght, int width)
{
	_close = false;
	_width = width;
	_menu = menu;
	_length = lenght;
	_selectedMenuItem = 0;
	_display = nullptr;
}

MenuBase::MenuBase(std::wstring* menu, int lenght, int selectedMenuItem, int width)
{
	_close = false;
	_width = width;
	_menu = menu;
	_length = lenght;
	_selectedMenuItem = selectedMenuItem;
	_display = nullptr;
}

MenuBase::MenuBase(std::wstring* menu, int lenght, IDisplay<wchar_t>* display, int width)
{
	_close = false;
	_width = width;
	_menu = menu;
	_length = lenght;
	_selectedMenuItem = 0;
	_display = display;
}

MenuBase::MenuBase(std::wstring* menu, int lenght, int selectedMenuItem, IDisplay<wchar_t>* display, int width)
{
	_close = false;
	_width = width;
	_menu = menu;
	_length = lenght;
	_selectedMenuItem = selectedMenuItem;
	_display = display;
}

MenuBase::~MenuBase()
{
	delete[] _menu;
}

std::wstring* MenuBase::GetMenu() const
{
	return _menu;
}

std::wstring MenuBase::GetMenuItem(int index) const
{
	if (index < 0 || index >= _length)
		throw std::out_of_range("Going beyond the bounds of an array");

	return *(_menu + index);
}

int MenuBase::Length() const
{
	return _length;
}

int MenuBase::GetSelectedMenuItem() const
{
	return _selectedMenuItem;
}

void MenuBase::SetSelectedMenuItem(int value)
{
	if (value >= 0 && value < _length)
		_selectedMenuItem = value;
}

void MenuBase::SetRowWidth(int value)
{
	_width = value;
}

void MenuBase::Up()
{
	if (_selectedMenuItem > 0)
		_selectedMenuItem--;
}

void MenuBase::Down()
{
	if (_selectedMenuItem < _length - 1)
		_selectedMenuItem++;
}

void MenuBase::Open()
{
	_close = false;
	int btnCode;
	Show();
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
			Show();
			break;
		case 115:
		case 80:
			Down();
			Show();
			break;
		case 13:
			SelectMenuItem();
			break;
		case 27: //esc
			_selectedMenuItem = 0;
			_close = true;
			Clear();
			break;
		}
	}
}

void MenuBase::Show()
{
	for (int i = 0; i < _length; i++)
	{
		if (i == _selectedMenuItem)
			_display->SetColor(Color::DarkGray, Color::Black);
		else
			_display->SetColor();

		std::wstring menuItem = *(_menu + i);
		int x = (_width - menuItem.length()) / 2;
		_display->ShowText(menuItem, x, 10 + i);
	}
}

void MenuBase::Clear()
{
	_display->SetColor();
	for (int i = 0; i < _length; i++)
	{
		std::wstring menuItem = *(_menu + i);
		std::wstring empty(menuItem.length(), L' ');
		int x = (_width - menuItem.length()) / 2;
		_display->ShowText(empty, x, 10 + i);
	}
}
