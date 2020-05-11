#include "Apple.h"

Apple::Apple()
{
	_symbol = static_cast<wchar_t>(9679);
	_score = 10;
	_color = Color::LightGreen;
}

Apple::Apple(int x, int y) : ItemBase(x, y)
{
	_symbol = static_cast<wchar_t>(9679);
	_score = 10;
	_color = Color::LightGreen;
}

std::wstring Apple::Description()
{
	return std::wstring(L" - Apple. Gives 10 points");
}

void Apple::Effect(Snake* snake)
{
	snake->AddTail();
}
