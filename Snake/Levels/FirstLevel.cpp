#include "FirstLevel.h"

FirstLevel::FirstLevel() : LevelBase()
{
	_row = 60;
	_col = 30;
	_field = new wchar_t* [_row];

	for (int i = 0; i < _row; i++)
		_field[i] = new wchar_t[_col];

	GenerateField();
}

std::wstring FirstLevel::GetLevel() const
{
	return std::wstring(L"Level: 1");
}

void FirstLevel::GenerateField()
{
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			if ((i == 0) || (j == 0) || (i == _row - 1) || (j == _col - 1))
				*(*(_field + i) + j) = static_cast<wchar_t>(9608);
			else
				*(*(_field + i) + j) = ' ';
		}
	}
}