#pragma once
#include "../Headers/Header.h"
#include "State/MoveBase.h"

class MoveBase;

class Snake
{
private:
	wchar_t _symbol;
	int _length;
	Color _color;
	SnakePart* _head;
	SnakePart* _tail;
	Direction _dir;
	MoveBase* _move;

protected:
	void RemoveAllBody();
public:
	Snake();
	virtual ~Snake();

	SnakePart* GetHead() const;
	SnakePart* GetTail() const;
	void SetSymbol(wchar_t value);
	wchar_t GetSymbol() const;
	int GetSpeed() const;
	void SetColor(Color color = Color::LightGray);
	Color GetColor() const;
	void SetDirection(Direction dir);
	Direction GetDirection() const;
	void SetMoveState(MoveBase* moveState);
	MoveBase* GetMoveState() const;
	int Length() const;

	void AddTail();
	void AddTail(SnakePart* part);
	void Move();
};
