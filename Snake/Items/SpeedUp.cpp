#include "SpeedUp.h"

SpeedUp::SpeedUp()
{
	_symbol = static_cast<wchar_t>(9650);
	_score = 0;
	_color = Color::LightBlue;
}

SpeedUp::SpeedUp(int x, int y) : ItemBase(x, y)
{
	_symbol = static_cast<wchar_t>(9650);
	_score = 0;
	_color = Color::LightBlue;
}

std::wstring SpeedUp::Description()
{
	return std::wstring(L" - Speed up.");
}

void SpeedUp::Effect(Snake* snake)
{
	snake->SetSpeed(10);
}
