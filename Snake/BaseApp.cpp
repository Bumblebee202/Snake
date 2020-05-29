#include "BaseApp.h"

BaseApp::BaseApp()
{
	_run = false;
	_deltaTime = 0;
	_timer = Timer();
}

BaseApp::~BaseApp()
{
}

void BaseApp::Run()
{
	while (_run)
	{
		_timer.Start();

		if (_kbhit())
			KeyPressed(_getch());

		float deltaTime = (float)_deltaTime / 1000.0f;
		if (deltaTime < 0.3f)
			Update(deltaTime);
		else
			_deltaTime = 0;
		

		while (true)
		{
			_deltaTime = _timer.Now();
			if (_deltaTime > 20)
				break;
		}
	}
}

void BaseApp::Stop()
{
	_run = false;
}
