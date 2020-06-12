#include "SpeedDown.h"
#include "../Snakes/State/SlowMove.h"

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

void SpeedDown::Interaction(Snake* snake)
{
	MoveBase* slowSnake = SlowMove::GetInstance(snake);
	snake->SetMoveState(slowSnake);
}
