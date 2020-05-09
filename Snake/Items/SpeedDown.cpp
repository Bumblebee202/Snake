#include "SpeedDown.h"

SpeedDown::SpeedDown()
{
	_symbol = static_cast<wchar_t>(9679);
	_score = 0;
	_color = Color::Brown;
}

SpeedDown::SpeedDown(int x, int y) : ItemBase(x, y)
{
	_symbol = static_cast<wchar_t>(9679);
	_score = 0;
	_color = Color::Brown;
}

std::wstring SpeedDown::Description()
{
	return std::wstring(L" - Speed down.");
}

//void SpeedDown::Effect(Snake* snake)
//{
//}
