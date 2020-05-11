#pragma once
#include "../Header.h"
#include "../Items/IEdible.h"
#include "../Items/ItemBase.h"

class IEdible;

class Snake
{
private:
	int _length;
	int _speed;
	Color _color;
	SnakePart* _head;
	SnakePart* _tail;
	Direction _dir;

	void Move(int x, int y);
	void RemoveAllBody();
public:
	Snake();
	~Snake();

	SnakePart* GetHead() const;
	SnakePart* GetTail() const;
	void SetSpeed(int value);
	int GetSpeed() const;
	void SetColor(Color color = Color::LightGray);
	Color GetColor() const;
	void SetDirection(Direction dir);
	Direction GetDirection() const;
	int Length() const;

	void AddTail();
	void Move();
	void Eat(IEdible* item);
};

