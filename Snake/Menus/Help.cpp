#include "Help.h"

Help::Help(IDisplay<wchar_t>* display, int width) : MenuBase(display, width)
{
	_selectedMenuItem = -1;
	_length = -1;
	_menu = nullptr;
	_items = std::vector<ItemBase*>();
	GenerateMenu();
}

Help::~Help()
{
	for (auto item : _items)
		delete item;
}

void Help::GenerateMenu()
{
	_items.push_back(new Apple());
	_items.push_back(new Pear());
	_items.push_back(new Amanita());
	_items.push_back(new SpeedDown());
	_items.push_back(new SpeedUp());
}

void Help::SelectMenuItem()
{
	return;
}

void Help::Open()
{
	_close = false;
	int btnCode;
	Show();
	while (!_close)
	{
		btnCode = _getch();
		if (btnCode == 224)
			btnCode = _getch();

		if (_button->IsEsc(btnCode))
		{
			_close = true;
			Clear();
		}
	}
}

void Help::Show()
{
	std::wstring str;
	int i = 0;
	int x = _width / 4;
	for (; i < _items.size(); i++)
	{
		_display->SetColor(Color::Black, _items[i]->GetColor());
		str = _items[i]->Description();
		_display->ShowObject(_items[i]->GetSymbol(), x, 10 + i);
		_display->SetColor();
		_display->ShowText(str, x + 1, 10 + i);
	}
	str = L"Press Esc to go back";
	x = (_width - str.length() + 1) / 2;
	i++;
	_display->ShowText(str, x, 10 + i);
}

void Help::Clear()
{
	int i = 0;
	int x = _width / 4;
	_display->SetColor();
	for (; i < _items.size(); i++)
	{
		int len = _items[i]->Description().length() + 1;
		std::wstring empty(len, L' ');
		_display->ShowText(empty, x, 10 + i);
	}
	std::wstring str = L"press Esc to go back";
	std::wstring empty(str.length(), L' ');
	x = (_width - empty.length() + 1) / 2;
	i++;
	_display->ShowText(empty, x, 10 + i);
}