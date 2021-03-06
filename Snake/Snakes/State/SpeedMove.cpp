#include "SpeedMove.h"

MoveBase* SpeedMove::_singleton = nullptr;

SpeedMove::SpeedMove(Snake* snake) : MoveBase(snake)
{
	SetSpeed(10);
	_moves = 100;
}

SpeedMove::~SpeedMove()
{
	_singleton = nullptr;
}

MoveBase* SpeedMove::GetInstance(Snake* snake)
{
	if (_singleton == nullptr)
	{
		std::lock_guard<std::mutex> lock(_mutex);
		if (_singleton == nullptr)
			_singleton = new SpeedMove(snake);
	}
	return _singleton;
}

void SpeedMove::Move()
{
	MoveBase::Move();
	_moves--;
	if (_moves == 0)
	{
		MoveBase* moveState = NormalMove::GetInstance(_snake);
		_snake->SetMoveState(moveState);
	}
}
