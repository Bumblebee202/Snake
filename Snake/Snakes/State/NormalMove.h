#pragma once
#include "MoveBase.h"

class MoveBase;

class NormalMove : public MoveBase
{
private:
	static MoveBase* _singleton;

	NormalMove(Snake* snake);
public:
	~NormalMove();
	static MoveBase* GetInstance(Snake* snake);
};

