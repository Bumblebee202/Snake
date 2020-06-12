#pragma once
#include "../Snake.h"
#include <mutex>

class Snake;

class MoveBase
{
protected:
	int _speed;
	Snake* _snake;
	static std::mutex _mutex;

	MoveBase(Snake* snake);
private:
	void Move(int x, int y);
public:
	virtual ~MoveBase();

	virtual void Move();

	void SetSpeed(int value);
	int GetSpeed() const;
	void SetSnake(Snake* snake);
	Snake* GetSnake() const;
};

