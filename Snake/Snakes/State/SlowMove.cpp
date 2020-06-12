#include "SlowMove.h"

MoveBase* SlowMove::_singleton = nullptr;

SlowMove::SlowMove(Snake* snake) : MoveBase(snake)
{
	SetSpeed(2);
	_moves = 20;
}

SlowMove::~SlowMove()
{
	_singleton = nullptr;
}

MoveBase* SlowMove::GetInstance(Snake* snake)
{
	if (_singleton == nullptr)
	{
		std::lock_guard<std::mutex> lock(_mutex);
		if (_singleton == nullptr)
			_singleton = new SlowMove(snake);
	}
	return _singleton;
}

void SlowMove::Move()
{
	MoveBase::Move();
	_moves--;
	if (_moves == 0)
	{
		MoveBase* moveState = NormalMove::GetInstance(_snake);
		_snake->SetMoveState(moveState);
	}
}
