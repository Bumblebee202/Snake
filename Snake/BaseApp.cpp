#include "BaseApp.h"

BaseApp::BaseApp()
{
	_run = false;
	_sum = 0;
	_fps = 0;
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

		//_sum += _deltaTime;
		/*_fps++;
		if (_sum >= 1000)
		{
			wchar_t buffer[256];
			StringCchPrintf(buffer, 256, L"FPS: %d", _deltaTime);
			SetConsoleTitle(buffer);

			_fps = 0;
			_sum = 0;
		}*/
	}
}
