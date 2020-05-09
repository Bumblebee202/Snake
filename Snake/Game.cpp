#include "Game.h"

Game::Game(IDisplay<wchar_t>* display) : BaseApp()
{
	//_deltaTime = 0.0f;
	srand(0);
	_pause = false;
	_run = false;
	_time = Time();
	_score = 0;
	_snake = new Snake();
	_lvl = new FirstLevel();
	_display = display;
	_menu = new Pause(display, _lvl->GetCol());
	_items = std::vector<ItemBase*>();

	/*_display->SetWidnowSize(_lvl->GetCol(), _lvl->GetRow());
	_display->ShowObjects(_lvl->GetField(), _lvl->GetRow(), _lvl->GetCol());*/
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
	_display->SetColor();
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
	do
	{
		_display->SetWidnowSize(_lvl->GetCol() + 20, _lvl->GetRow());
		_display->ShowObjects(_lvl->GetField(), _lvl->GetRow(), _lvl->GetCol());
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
			_display->ShowText(L"Score: ", 65, 5);
			_display->ShowNumber(_score, 72, 5);
			ShowSnake();
			SnakePart* head = _snake->GetHead();
			std::thread t1([&]()
				{
					int sleep;
					while (true)
					{
						if (!_pause)
						{
							ClearSnakeTail();
							_snake->Move();
							
							if (!_lvl->IsRoad(head->X, head->Y))
							{
								for (int i = 0; i < _items.size(); i++)
								{
									if (_items[i]->GetX() == head->X && _items[i]->GetY() == head->Y)
									{
										IEdible* item = _items[i];
										_score += _snake->Eat(item);
										_items.erase(_items.begin() + i);
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

			std::thread t2([&]()
				{
					ItemCreator* creator = nullptr;
					int x;
					int y;
					while (true)
					{
						try
						{
							if (!_pause)
							{
								creator = Creator();
								x = rand() % (_lvl->GetCol() - 2) + 1;
								y = rand() % (_lvl->GetRow() - 2) + 1;
								for (int i = 0; i < _items.size(); i++)
								{
									if (_items[i]->GetX() == x && _items[i]->GetY() == y)
									{
										x = rand() % (_lvl->GetCol() - 2) + 1;
										y = rand() % (_lvl->GetRow() - 2) + 1;
										i = 0;
									}
								}
								ItemBase* item = creator->Create(x, y);
								_items.push_back(item);

								_lvl->SetSymbol(item->GetSymbol(), item->GetX(), item->GetY());

								_display->SetColor(Color::Black, item->GetColor());
								_display->ShowObject(item->GetSymbol(), x, y);

								std::wstring str = L"Count: " + std::to_wstring(_items.size());
								_display->ShowText(str, 61, 10);
								Sleep(3000);
							}
						}
						catch (const std::exception&)
						{
							std::wstring str = L"Error";
							_display->ShowText(str, 61, 10);
						}
						

					}

				});

			Run();
		}


	} while (true);
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

void Game::ClearSnakeTail()
{
	_display->SetColor(Color::Black, _snake->GetColor());
	SnakePart* el = _snake->GetTail();
	_display->ShowObject(L' ', el->X, el->Y);
}

ItemCreator* Game::Creator()
{
	int value = rand() % 2;
	if (value == 0)
		return new AppleCreator();
	else if (value == 1)
		return new PearCreator();
	/*int value = rand() % 5;

	if (value == 0)
		return new AppleCreator();
	else if (value == 1)
		return new AmanitaCreator();
	else if (value == 2)
		return new PearCreator();
	else if (value == 3)
		return new SpeedDownCreaor();
	else if (value == 4)
		return new SpeedUpCreator();*/

	return nullptr;
}
