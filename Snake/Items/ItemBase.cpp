#include "ItemBase.h"



ItemBase::ItemBase()
{
}

ItemBase::ItemBase(int x, int y)
{
	_x = x;
	_y = y;
	_symbol = L'!';
	_color = Color::LightGray;
}

ItemBase::~ItemBase()
{
}

int ItemBase::GetX() const
{
	return _x;
}

void ItemBase::SetX(int x)
{
	_x = x;
}

int ItemBase::GetY() const
{
	return _y;
}

void ItemBase::SetY(int y)
{
	_y = y;
}

void ItemBase::SetSymbol(wchar_t symbol)
{
	_symbol = symbol;
}

wchar_t ItemBase::GetSymbol() const
{
	return _symbol;
}

void ItemBase::SetColor(Color color)
{
	_color = color;
}

Color ItemBase::GetColor() const
{
	return _color;
}
