#include "SpeedDown.h"

SpeedDown::SpeedDown()
{
	_symbol = static_cast<wchar_t>(9660);
	_score = 0;
	_color = Color::LightMagenta;
}

SpeedDown::SpeedDown(int x, int y) : ItemBase(x, y)
{
	_symbol = static_cast<wchar_t>(9660);
	_score = 0;
	_color = Color::LightMagenta;
}

std::wstring SpeedDown::Description()
{
	return std::wstring(L" - Speed down.");
}

void SpeedDown::Effect(Snake* snake)
{
	snake->SetSpeed(2);
}
