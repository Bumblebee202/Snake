#pragma once
#include "../Header.h"
#include "../Items/ItemBase.h"

class Snake
{
private:
	int _length;
	int _speed;
	Color _color;
	Body* _head;
	Body* _tail;
	Direction _dir;

	void Move(int x, int y);
	void RemoveAllBody();
public:
	Snake();
	~Snake();

	Body* GetHead() const;
	Body* GetTail() const;
	void SetSpeed(int value);
	int GetSpeed() const;
	void SetColor(Color color = Color::LightGray);
	Color GetColor() const;
	void SetDirection(Direction dir);
	Direction GetDirection() const;
	int Length() const;

	void AddTail();
	void Move();
	int Eat(ItemBase* item);
};

