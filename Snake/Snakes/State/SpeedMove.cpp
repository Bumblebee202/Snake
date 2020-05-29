#include "SpeedMove.h"
#include "NormalMove.h"

SpeedMove::SpeedMove(Snake* snake) : MoveBase(snake)
{
	SetSpeed(10);
	_moves = 100;
}

void SpeedMove::Move()
{
	MoveBase::Move();
	_moves--;
	if (_moves == 0)
	{
		MoveBase* moveState = new NormalMove(_snake);
		_snake->SetMoveState(moveState);
		delete this;
	}
}
