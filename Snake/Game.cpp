#include "Game.h"

Game::Game(DisplayBase<wchar_t>* display) : BaseApp()
{
	_run = false;
	_time = Time();
	_score = 0;
	_snake = new Snake();
	_lvl = new FirstLevel();
	_display = display;
	_menu = new Pause(display);

	_display->ShowObjects(_lvl->GetField(), _lvl->GetRow(), _lvl->GetCol());
}

Game::~Game()
{
	delete _snake;
	delete _lvl;
	delete _display;
	delete _menu;
}

void Game::Update(float deltaTime)
{
	_time.AddMillisecond(deltaTime);
	_display->ShowTime(_time, 65, 3);

	//(this->*Show)();
}

void Game::KeyPressed(int btnCode)
{
	if (btnCode == 224)
		btnCode = _getch();

	//(this->*Action)(btnCode);
	Direction dir = _snake->GetDirection();
	switch (btnCode)
	{
	case 97:
	case 75:
		dir = _snake->GetDirection() != Direction::Right ? Direction::Left : dir;
		break;

	case 100:
	case 77:
		dir = _snake->GetDirection() != Direction::Left ? Direction::Right : dir;
		break;

	case 119:
	case 72:
		dir = _snake->GetDirection() != Direction::Down ? Direction::Up : dir;
		break;

	case 115:
	case 80:
		dir = _snake->GetDirection() != Direction::Up ? Direction::Down : dir;
		break;
	case 27:
		_menu->Open();
		ShowSnake();
		break;
	}

	_snake->SetDirection(dir);
}


void Game::Start()
{
	do
	{
		//_display->ShowTime(_time, 65, 3);

		std::wstring str = L"Press space to continue";
		int x = (_lvl->GetCol() - str.length()) / 2;
		int y = _lvl->GetRow() / 3;
		_display->ShowText(str, x, y);

		int sp = _getch();
		if (sp == 32)
		{
			_display->ShowText(_lvl->GetLevel(), 65, 1);
			str = std::wstring(str.length(), L' ');
			_display->ShowText(str, x, y);
			ShowSnake();
			/*std::thread t([&]()
				{
					while (true)
					{
						Sleep(300);

						_mutex.lock();
						ClearSnakeTail();
						_snake->Move();
						ShowSnake();
						_mutex.unlock();
					}
				});*/
			
			Run();
		}


	} while (true);
}

void Game::ShowSnake()
{
	_display->SetColor(Color::Black, _snake->GetColor());
	Element* el = _snake->GetHead();
	while (el != nullptr)
	{
		_display->ShowObject(el->Symbol, el->X, el->Y);
		el = el->Next;
	}
}

void Game::ClearSnakeTail()
{
	_display->SetColor(Color::Black, _snake->GetColor());
	Element* el = _snake->GetTail();
	_display->ShowObject(L' ', el->X, el->Y);
}
