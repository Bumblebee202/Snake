#include "Pear.h"

Pear::Pear(int x, int y) : ItemBase(x, y)
{
	_symbol = static_cast<wchar_t>(9679);
	//_score = 5;
	_color = Color::Yellow;
}
