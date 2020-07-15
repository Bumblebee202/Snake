#include "ThirdLevel.h"

ThirdLevel::ThirdLevel()
{
	_toNextLvl = 300;
	_row = 60;
	_col = 30;

	_field = new wchar_t* [_row];

	for (int i = 0; i < _row; i++)
		_field[i] = new wchar_t[_col];
}

int ThirdLevel::GetLevel() const
{
    return 3;
}

void ThirdLevel::Loading()
{
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			if ((i == 0) || (j == 0) || (i == _row - 1) || (j == _col - 1))
			{
				*(*(_field + i) + j) = static_cast<wchar_t>(9608);
			}
			else if (((j >= 6 && j <= 11) || (j >= _col - 11 && j <= _col - 6)) && (i == 10 || i == _row - 10))
			{
				*(*(_field + i) + j) = static_cast<wchar_t>(9608);
			}
			else if (((i > 10 && i <= 21) || (i >= 39 && i < 50)) && (j == 6 || j == _col - 6))
			{
				*(*(_field + i) + j) = static_cast<wchar_t>(9608);
			}
			else if (i == 30 && (j > 11 && j < 19))
			{
				*(*(_field + i) + j) = static_cast<wchar_t>(9608);
			}
			else if (j == 15 && (i > 21 && i < 39))
			{
				*(*(_field + i) + j) = static_cast<wchar_t>(9608);
			}
			else
				*(*(_field + i) + j) = ' ';
		}
	}
}
