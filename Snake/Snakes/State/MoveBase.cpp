#include "MoveBase.h"

MoveBase::MoveBase(Snake* snake)
{
	_snake = snake;
}

void MoveBase::Move(int x, int y)
{
	int elementX;
	int elementY;

	SnakePart* el = _snake->GetTail();
	while (true)
	{
		if (el->Prev == nullptr)
			break;

		el->X = el->Prev->X;
		el->Y = el->Prev->Y;

		el = el->Prev;
	}

	SnakePart* head = _snake->GetHead();

	head->X += x;
	head->Y += y;
}

void MoveBase::Move()
{
	Direction dir = _snake->GetDirection();

	switch (dir)
	{
	case Direction::Left:
		Move(-1, 0);
		break;

	case Direction::Right:
		Move(1, 0);
		break;

	case Direction::Up:
		Move(0, -1);
		break;

	case Direction::Down:
		Move(0, 1);
		break;
	}
}

void MoveBase::SetSpeed(int value)
{
	_speed = value;
}

int MoveBase::GetSpeed() const
{
	return _speed;
}

void MoveBase::SetSnake(Snake* snake)
{
	_snake = snake;
}

Snake* MoveBase::GetSnake() const
{
	return _snake;
}
