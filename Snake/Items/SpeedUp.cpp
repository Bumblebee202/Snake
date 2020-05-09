#include "SpeedUp.h"

SpeedUp::SpeedUp()
{
	_symbol = static_cast<wchar_t>(9679);
	_score = 0;
	_color = Color::Blue;
}

SpeedUp::SpeedUp(int x, int y) : ItemBase(x, y)
{
	_symbol = static_cast<wchar_t>(9679);
	_score = 0;
	_color = Color::Blue;
}

std::wstring SpeedUp::Description()
{
	return std::wstring(L" - Speed up.");
}

//void SpeedUp::Effect(Snake* snake)
//{
//}
