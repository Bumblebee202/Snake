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
}

//void LevelBase::SetField(wchar_t** field, int row, int col)
//{
//	Delete();
//
//	_row = row;
//	_col = col;
//	
//	_field = new wchar_t* [_row];
//	for (int i = 0; i < _col; i++)
//		*(_field + i) = new wchar_t[_col];
//}

wchar_t** LevelBase::GetField() const
{
	return _field;
}

bool LevelBase::IsRoad(int x, int y)
{
	return *(*(_field + x) + y) == L' ' ? true : false;
}
