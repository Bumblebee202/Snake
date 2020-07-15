#pragma once
#include <strsafe.h>
#include <conio.h>
#include <atomic>
#include "../Other/Timer.h"
#include "../Settings/Buttons.h"

class BaseApp
{
private:
	int _deltaTime;
	Timer _timer;
protected:
	std::atomic<bool> _run;
	Buttons* _buttons;

	virtual void Update(float deltaTime) = 0;
	virtual void KeyPressed(int btnCode) = 0;
	void Run();
public:
	BaseApp();
	virtual ~BaseApp();

	virtual void Start() = 0;
	virtual void Stop();
};

