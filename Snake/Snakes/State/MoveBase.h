#pragma once
#include "../Snake.h"

class Snake;

class MoveBase
{
protected:
	int _speed;
	Snake* _snake;
private:
	void Move(int x, int y);
public:
	MoveBase(Snake* snake);

	virtual void Move();

	void SetSpeed(int value);
	int GetSpeed() const;
	void SetSnake(Snake* snake);
	Snake* GetSnake() const;
};

