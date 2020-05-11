#pragma once
#include "../Snakes/Snake.h"

class Snake;

class IEdible
{
public:
	int virtual GetScore() = 0;
	void virtual Effect(Snake* snake) = 0;
};

