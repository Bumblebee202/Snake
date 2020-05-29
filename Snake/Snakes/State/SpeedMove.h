#pragma once
#include "MoveBase.h"

class SpeedMove : public MoveBase
{
private:
	int _moves;
public:
	SpeedMove(Snake* snake);

	void Move() override;
};

