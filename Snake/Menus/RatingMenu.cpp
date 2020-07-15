#include "RatingMenu.h"

RatingMenu::RatingMenu(IDisplay<wchar_t>* display, int width) : MenuBase(display, width)
{
	_sqlite = SQLite::GetInstance();

	GenerateMenu();
}

void RatingMenu::GenerateMenu()
{
	_ratings = _sqlite->SelectRating();
}

void RatingMenu::SelectMenuItem()
{
	return;
}

void RatingMenu::Open()
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

void RatingMenu::Show()
{
	std::wstring str;
	int x;
	str = L"The result table is empty";
	int i = 0;
	if (_ratings.size() == 0)
	{
		x = (_width - str.length() + 1) / 2;
		_display->ShowText(str, x, 4 + i);
	}
	else
	{
		_display->ShowText(L"Name", 12, 2);
		_display->ShowText(L"Score", 27, 2);
		_display->ShowText(L"Time", 42, 2);

		for (; i < _ratings.size(); i++)
		{
			_display->ShowText(_ratings[i].GetName(), 12, 4 + i);
			_display->ShowNumber(_ratings[i].GetScore(), 27, 4 + i);
			_display->ShowText(_ratings[i].GetTime().ToString(), 42, 4 + i);
		}
	}

	str = L"Press Esc to go back";
	x = (_width - str.length() + 1) / 2;
	++++i;
	_display->ShowText(str, x, 4 + i);
}

void RatingMenu::Clear()
{
	_display->ClearDisplay();
}
