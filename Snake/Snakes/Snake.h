#pragma once
#include "../Header.h"

class Snake
{
private:
	int _speed;
	int _length;
	Color _color;
	Element* _head;
	Element* _tail;
	Direction _dir;

	void Move(int x, int y);
	void RemoveAllBody();
public:
	Snake();
	~Snake();

	Element* GetHead() const;
	Element* GetTail() const;
	void SetSpeed(int value);
	int GetSpeed() const;
	void SetColor(Color color = Color::LightGray);
	Color GetColor() const;
	void SetDirection(Direction dir);
	Direction GetDirection() const;
	int Length() const;

	void AddTail();
	void Move();
};

