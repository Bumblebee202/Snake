#pragma once
#include "MoveBase.h"
#include "NormalMove.h"

class SlowMove : public MoveBase
{
private:
	int _moves;
	static MoveBase* _singleton;

	SlowMove(Snake* snake);
public:
	~SlowMove();
	static MoveBase* GetInstance(Snake* snake);
	virtual void Move() override;
};

