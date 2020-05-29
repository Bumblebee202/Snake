#pragma once
#include <strsafe.h>
#include <conio.h>
#include "Other/Timer.h"

class BaseApp
{
private:
	int _deltaTime;
	Timer _timer;
protected:
	bool _run;

	virtual void Update(float deltaTime) = 0;
	virtual void KeyPressed(int btnCode) = 0;
	void Run();
public:
	BaseApp();
	virtual ~BaseApp();

	virtual void Start() = 0;
	virtual void Stop();
};

