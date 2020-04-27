#include "SpeedDown.h"

SpeedDown::SpeedDown(int x, int y) : ItemBase(x, y)
{
	_symbol = static_cast<wchar_t>(9679);
	_color = Color::Brown;
}
