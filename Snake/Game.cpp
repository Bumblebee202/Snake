#include "Game.h"

Game::Game(IDisplay<wchar_t>* display) : BaseApp()
{
	_pause = false;
	_lose = false;
	_run = true;
	_time = Time();
	_score = 0;
	_snake = new Snake();
	_lvl = new FirstLevel();
	_display = display;
	_menu = new Pause(this, display, _lvl->GetRow());

	/*_display->SetWidnowSize(_lvl->GetCol(), _lvl->GetRow());
	_display->ShowObjects(_lvl->GetField(), _lvl->GetRow(), _lvl->GetCol());*/
}

Game::~Game()
{
	delete _snake;
	delete _lvl;
	delete _display;
	delete _menu;

	for (int i = 0; i < _items.Count(); i++)
		delete _items[i];

	_items.Clear();
}

void Game::Update(float deltaTime)
{
	_display->SetColor();
	_time.AddMillisecond(deltaTime);
	_display->ShowTime(_time, 65, 3);
	if (_lose)
		Lose();

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
		_pause = true;
		_menu->Open();
		ShowSnake();
		_pause = false;
		break;
	}

	_snake->SetDirection(dir);
}


void Game::Start()
{
	_display->SetWidnowSize(_lvl->GetRow() + 20, _lvl->GetCol());
	_display->ShowObjects(_lvl->GetField(), _lvl->GetRow(), _lvl->GetCol());

	std::wstring str = L"Press space to continue";
	int x = (_lvl->GetRow() - str.length()) / 2;
	int y = _lvl->GetCol() / 3;
	_display->ShowText(str, x, y);
	do
	{
		int sp = _getch();
		if (sp == 32)
		{
			_display->ShowText(_lvl->GetLevel(), 65, 1);
			str = std::wstring(str.length(), L' ');
			_display->ShowText(str, x, y);

			ShowScore();
			ShowSnake();

			SnakePart* head = _snake->GetHead();
			std::thread snakeMovement([&]()
				{
					int sleep;
					while (_run)
					{
						if (!_pause)
						{
							ClearSnakeTail();
							_snake->Move();
							
							if (!_lvl->IsRoad(head->X, head->Y))
							{
								if (_lvl->IsWall(head->X, head->Y))
								{
									_lose = true;
									return;
								}

								for (int i = 0; i < _items.Count(); i++)
								{
									if (_items[i]->GetX() == head->X && _items[i]->GetY() == head->Y)
									{
										IEdible* item = _items[i];
										_snake->Eat(item);
										_score += item->GetScore();
										ShowScore();
										_items.RemoveAt(i);
										delete[] item;
										break;
									}
								}
							}
							ShowSnake();
							sleep = 1000 / _snake->GetSpeed();
							Sleep(sleep);
						}
					}
				});

			std::thread itemCreator([&]()
				{
					ItemCreator* creator = nullptr;
					int x;
					int y;
					while (_run)
					{
						if (!_pause)
						{
							creator = Creator();
							x = rand() % (_lvl->GetRow() - 2) + 1;
							y = rand() % (_lvl->GetCol() - 2) + 1;
							while (true)
							{
								if (!_lvl->IsRoad(x, y))
								{
									x = rand() % (_lvl->GetRow() - 2) + 1;
									y = rand() % (_lvl->GetCol() - 2) + 1;
									continue;
								}
								break;
							}

							ItemBase* item = creator->Create(x, y);
							_items.Add(item);

							_lvl->SetSymbol(item->GetSymbol(), item->GetX(), item->GetY());

							_display->SetColor(Color::Black, item->GetColor());
							_display->ShowObject(item->GetSymbol(), x, y);

							Sleep(3000);
						}


					}
					delete creator;
				});

			Run();
			snakeMovement.detach();
			itemCreator.detach();
			ClearField();
		}


	} while (_run);
}

void Game::Lose()
{
	_totalScore = _score;
	_run = false;
	std::wstring str = L"You lose";
	int x = (_lvl->GetRow() - str.length()) / 2;
	int y = _lvl->GetCol() / 3;
	_display->ShowText(str, x, y);

	str = L"Press space to continue";
	x = (_lvl->GetRow() - str.length()) / 2;
	y++;
	_display->ShowText(str, x, y);

	int sp;
	do
	{
		sp = _getch();
		if (sp == 224)
			sp = _getch();
	} while (sp == 32);
}

void Game::ShowSnake()
{
	_display->SetColor(Color::Black, _snake->GetColor());
	SnakePart* el = _snake->GetHead();
	while (el != nullptr)
	{
		_display->ShowObject(el->Symbol, el->X, el->Y);
		el = el->Next;
	}
}

void Game::ShowScore()
{
	_display->ShowText(L"Score:    ", 65, 5);
	_display->ShowNumber(_score, 72, 5);
}

void Game::ClearSnakeTail()
{
	_display->SetColor(Color::Black, _snake->GetColor());
	SnakePart* el = _snake->GetTail();
	_display->ShowObject(L' ', el->X, el->Y);
}

void Game::ClearField()
{
	for (int i = 0; i < _lvl->GetRow(); i++)
	{
		for (int j = 0; j < _lvl->GetCol(); j++)
			_display->ShowObject(L' ', i, j);
	}
}

ItemCreator* Game::Creator()
{
	int value = rand() % 5;

	if (value == 0)
		return new AppleCreator();
	else if (value == 1)
		return new PearCreator();
	else if (value == 2)
		return new AmanitaCreator();
	else if (value == 3)
		return new SpeedDownCreaor();
	else if (value == 4)
		return new SpeedUpCreator();

	return nullptr;
}
