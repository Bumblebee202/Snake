#pragma once
#include "MoveBase.h"

class SlowSpeed : public MoveBase
{
private:
	int _moves;
public:
	SlowSpeed(Snake* snake);

	virtual void Move() override;
};

