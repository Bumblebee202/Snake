#pragma once
#include <strsafe.h>
#include <conio.h>
#include "Timer.h"

class BaseApp
{
protected:
	bool _run;
	int _sum;
	int _fps;
	int _deltaTime;
	Timer _timer;

	virtual void Update(float deltaTime) = 0;
	virtual void KeyPressed(int btnCode) = 0;
	void Run();
public:
	BaseApp();

	virtual void Start() = 0;
};

