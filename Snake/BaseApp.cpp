#include "BaseApp.h"

BaseApp::BaseApp()
{
	_run = false;
	_deltaTime = 0;
	_timer = Timer();
}

void BaseApp::Run()
{
	while (true)
	{
		_timer.Start();

		if (_kbhit())
			KeyPressed(_getch());

		Update((float)_deltaTime / 1000.0f);

		while (true)
		{
			_deltaTime = _timer.Now();
			if (_deltaTime > 20)
				break;
		}
	}
}
