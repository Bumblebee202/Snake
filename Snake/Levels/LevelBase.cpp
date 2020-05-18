#include "LevelBase.h"

LevelBase::LevelBase()
{
	_field = nullptr;
	_col = 0;
	_row = 0;
}

LevelBase::LevelBase(wchar_t** field, int row, int col)
{
	_field = field;
	_row = row;
	_col = col;
}

LevelBase::~LevelBase()
{
	Delete();
}

void LevelBase::Delete()
{
	if (_field != nullptr)
	{
		for (int i = 0; i < _row; i++)
			delete[] *(_field + i);
		delete[] _field;
	}
}

int LevelBase::GetRow() const
{
	return _row;
}

int LevelBase::GetCol() const
{
	return _col;
}

void LevelBase::SetSymbol(wchar_t symbol, int x, int y)
{
	*(*(_field + x) + y) = symbol;
}

wchar_t LevelBase::GetSymbol(int x, int y)
{
	return *(*(_field + x) + y);
}

wchar_t** LevelBase::GetField() const
{
	return _field;
}

int LevelBase::GetToNextLvl() const
{
	return _toNextLvl;
}

void LevelBase::SetToNextLvl(int value)
{
	_toNextLvl = value;
}

bool LevelBase::IsRoad(int x, int y)
{
	return *(*(_field + x) + y) == L' ' ? true : false;
}

bool LevelBase::IsWall(int x, int y)
{
	return *(*(_field + x) + y) == static_cast<wchar_t>(9608) ? true : false;
}
