#include "Pear.h"

Pear::Pear()
{
	_symbol = static_cast<wchar_t>(9679);
	_color = Color::Yellow;
}

Pear::Pear(int x, int y) : ItemBase(x, y)
{
	_symbol = static_cast<wchar_t>(9679);
	//_score = 5;
	_color = Color::Yellow;
}

std::wstring Pear::Description()
{
	return std::wstring(L" - Pear. Gives 10 points");
}
