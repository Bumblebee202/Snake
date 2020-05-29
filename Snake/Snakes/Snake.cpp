#include "Snake.h"

Snake::Snake()
{
	_symbol = static_cast<wchar_t>(164);

	_color = Color::LightGray;

	_head = new SnakePart();
	_head->Next = nullptr;
	_head->Prev = nullptr;
	_head->X = 5;
	_head->Y = 2;

	_tail = new SnakePart();
	_tail->Next = nullptr;
	_tail->Prev = nullptr;
	_tail->X = 3;
	_tail->Y = 2;

	SnakePart* body = new SnakePart();
	body->Next = _tail;
	body->Prev = _head;
	body->X = 4;
	body->Y = 2;

	_head->Next = body;
	_tail->Prev = body;

	_length = 3;

	_dir = Direction::Right;
}

Snake::~Snake()
{
	RemoveAllBody();
}

void Snake::RemoveAllBody()
{
	while (_head != nullptr)
	{
		SnakePart* temp = _head;
		_head = _head->Next;
		if (_head != nullptr)
			_head->Prev = nullptr;
		else
			_tail = nullptr;
		delete temp;
		_length--;
	}
}

SnakePart* Snake::GetHead() const
{
	return _head;
}

SnakePart* Snake::GetTail() const
{
	return _tail;
}

void Snake::SetSymbol(wchar_t value)
{
	_symbol = value;
}

wchar_t Snake::GetSymbol() const
{
	return _symbol;
}

int Snake::GetSpeed() const
{
	return _move->GetSpeed();
}

void Snake::SetColor(Color color)
{
	_color = color;
}

Color Snake::GetColor() const
{
	return _color;
}

void Snake::SetDirection(Direction dir)
{
	_dir = dir;
}

Direction Snake::GetDirection() const
{
	return _dir;
}

void Snake::SetMoveState(MoveBase* moveState)
{
	_move = moveState;
}

MoveBase* Snake::GetMoveState() const
{
	return _move;
}

int Snake::Length() const
{
	return _length;
}

void Snake::AddTail()
{
	SnakePart* part = new SnakePart();
	part->X = _tail->X;
	part->Y = _tail->Y;
	
	switch (_dir)
	{
	case Direction::Right:
		part->X--;
		break;
	case Direction::Left:
		part->X++;
		break;
	case Direction::Up:
		part->Y++;
		break;
	case Direction::Down:
		part->Y--;
		break;
	default:
		break;
	}

	part->Prev = _tail;
	part->Next = nullptr;
	_tail->Next = part;
	_tail = part;

	_length++;
}

void Snake::AddTail(SnakePart* part)
{
	if (_tail == nullptr)
	{
		_head = part;
		_tail = _head;
		_head->Next = nullptr;
		_head->Prev = nullptr;
	}
	else if (_tail != nullptr)
	{
		part->Prev = _tail;
		part->Next = nullptr;

		_tail->Next = part;
		_tail = part;
	}

	_length++;
}

void Snake::Move()
{
	_move->Move();
}
