#pragma once
#include "MoveBase.h"
#include "NormalMove.h"

class SpeedMove : public MoveBase
{
private:
	int _moves;
	static MoveBase* _singleton;

	SpeedMove(Snake* snake);
public:
	~SpeedMove();
	static MoveBase* GetInstance(Snake* snake);
	void Move() override;
};

