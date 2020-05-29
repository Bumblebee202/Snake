#include "SlowSpeed.h"
#include "NormalMove.h"

SlowSpeed::SlowSpeed(Snake* snake) : MoveBase(snake)
{
	SetSpeed(2);
	_moves = 20;
}

void SlowSpeed::Move()
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
