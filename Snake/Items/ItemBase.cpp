#include "ItemBase.h"

ItemBase::~ItemBase()
{
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
