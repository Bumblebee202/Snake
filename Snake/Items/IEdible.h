#pragma once
#include "../Snakes/Snake.h"


class IEdible
{
public:
	int virtual GetScore() = 0;
	virtual void Interaction(Snake* snake) = 0;
};

