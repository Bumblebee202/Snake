#include "Pear.h"

Pear::Pear()
{
	_symbol = static_cast<wchar_t>(9830);
	_score = 10;
	_color = Color::Yellow;
}

Pear::Pear(int x, int y) : ItemBase(x, y)
{
	_symbol = static_cast<wchar_t>(9830);
	_score = 10;
	_color = Color::Yellow;
}

std::wstring Pear::Description()
{
	return std::wstring(L" - Pear. Gives 10 points");
}

void Pear::Interaction(Snake* snake)
{
	snake->AddTail();
}
