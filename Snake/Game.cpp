#include "Game.h"

Game::Game(IDisplay<wchar_t>* display) : BaseApp()
{
	_lvl = new FirstLevel();
	_threadsRun = true;
	_pause = false;
	_exit = false;
	_run = true;
	_time = Time();
	_totalTime = Time();
	_random = Random();
	_totalScore = 0;
	_snake = nullptr;
	_display = display;
	_menu = new Pause(this, display, _lvl->GetRow());
	_button = Button::GetInstance();
}

Game::~Game()
{
	delete NormalMove::GetInstance(_snake);
	delete SlowMove::GetInstance(_snake);
	delete SpeedMove::GetInstance(_snake);

	if (_snake != nullptr)
		delete _snake;
	delete _lvl;
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
}

void Game::KeyPressed(int btnCode)
{
	if (btnCode == 224)
		btnCode = _getch();

	Direction dir = _snake->GetDirection();
	if (btnCode == _button->GetLeft())
		dir = _snake->GetDirection() != Direction::Right ? Direction::Left : dir;
	else if (btnCode == _button->GetRight())
		dir = _snake->GetDirection() != Direction::Left ? Direction::Right : dir;
	else if (btnCode == _button->GetUp())
		dir = _snake->GetDirection() != Direction::Down ? Direction::Up : dir;
	else if (btnCode == _button->GetDown())
		dir = _snake->GetDirection() != Direction::Up ? Direction::Down : dir;
	else if (btnCode == _button->GetEsc())
	{
		_pause = true;
		_menu->Open();
		ShowSnake();
		_pause = false;
	}

	_snake->SetDirection(dir);
}

void Game::Start()
{
	int sp;
	int x;
	int y;
	do
	{
		std::wstring space = L"Press Space to continue";
		x = (_lvl->GetRow() - space.length()) / 2;
		y = _lvl->GetCol() / 3;
		_display->ShowText(space, x, y);

		std::wstring esc = L"Press Esc to go back";
		x = (_lvl->GetRow() - esc.length()) / 2;
		y++;
		_display->ShowText(esc, x, y);

		do
		{
			sp = _getch();
			if (sp == 224)
				sp = _getch();
			if (sp == _button->GetEsc())
				return;
		} while (sp != _button->GetSpace());

		_run = true;
		_threadsRun = true;

		_snake = new Snake();
		MoveBase* moveState = NormalMove::GetInstance(_snake);
		_snake->SetMoveState(moveState);

		_display->SetWidnowSize(_lvl->GetRow() + 25, _lvl->GetCol());

		_lvl->Loading();
		_display->ShowObjects(_lvl->GetField(), _lvl->GetRow(), _lvl->GetCol());

		_display->ShowText(L"Level", 65, 1);
		_display->ShowNumber(_lvl->GetLevel(), 71, 1);
		esc = std::wstring(esc.length(), L' ');
		_display->ShowText(esc, x, y);

		x = (_lvl->GetRow() - space.length()) / 2;
		y--;
		space = std::wstring(space.length(), L' ');
		_display->ShowText(space, x, y);

		ShowScore(0);
		ShowSnake();

		std::thread snakeMovement = std::thread(&Game::SnakeMovement, this);
		std::thread itemMaker = std::thread(&Game::ItemMaker, this);

		Run();
		snakeMovement.detach();
		itemMaker.detach();
		ClearField();
		delete _snake;
		_snake = nullptr;

		_totalTime.Add(_time);
		_time.SetTime(0, 0, 0, 0.0f);

	} while (!_exit);
}

void Game::Stop()
{
	_threadsRun = false;
	_run = false;
	_exit = true;
}

void Game::NewLvl()
{
	if (_lvl->GetLevel() == 1)
	{
		_run = false;
		_threadsRun = false;
		delete _lvl;
		_lvl = new SecondLevel();
	}
}

void Game::Lose()
{
	_exit = true;

	_threadsRun = false;
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
	} while (sp != _button->GetSpace());
	_run = false;
}

void Game::ShowSnake()
{
	_display->SetColor(Color::Black, _snake->GetColor());
	SnakePart* el = _snake->GetHead();
	while (el != nullptr)
	{
		_display->ShowSymbol(_snake->GetSymbol(), el->X, el->Y);
		_lvl->SetSymbol(_snake->GetSymbol(), el->X, el->Y);
		el = el->Next;
	}
}

void Game::ShowScore(int score)
{
	_display->ShowText(L"Score:    ", 65, 5);
	_display->ShowNumber(score, 72, 5);

	_display->ShowText(L"To next lvl:    ", 65, 7);
	_display->ShowNumber(_lvl->GetToNextLvl(), 78, 7);
}

void Game::ClearField()
{
	for (int i = 0; i < _lvl->GetRow(); i++)
	{
		for (int j = 0; j < _lvl->GetCol(); j++)
			_display->ShowSymbol(L' ', i, j);
	}
}

ItemCreator* Game::Creator()
{
	float value = _random.Next(0.0f, 1.0f);

	if (value <= 0.25f)
		return new AppleCreator();
	else if (value > 0.25f && value <= 0.5f)
		return new PearCreator();
	else if (value > 0.5f && value <= 0.7f)
		return new AmanitaCreator();
	else if (value > 0.7f && value <= 0.85f)
		return new SpeedDownCreator();
	else if (value > 0.85f && value <= 1.0f)
		return new SpeedUpCreator();

	return nullptr;
}

void Game::SnakeMovement()
{
	int sleep;
	int oldX;
	int oldY;
	int score = 0;
	SnakePart* head = _snake->GetHead();
	SnakePart* tail = _snake->GetTail();
	while (_threadsRun)
	{
		if (!_pause)
		{
			head = _snake->GetHead();
			tail = _snake->GetTail();

			oldX = tail->X;
			oldY = tail->Y;
			_snake->Move();

			if (!_lvl->IsRoad(head->X, head->Y))
			{
				if (_lvl->IsWall(head->X, head->Y))
				{
					Lose();
					return;
				}

				for (int i = 0; i < _items.Count(); i++)
				{
					if (_items[i]->GetX() == head->X && _items[i]->GetY() == head->Y)
					{

						IEdible* item = _items[i];
						item->Interaction(_snake);
						if (_snake->GetSpeed() == 5)
						{
							tail = _snake->GetTail();
							tail->X = oldX;
							tail->Y = oldY;
						}
						
						score += item->GetScore();

						int newToNextLvl = _lvl->GetToNextLvl() - item->GetScore();
						_lvl->SetToNextLvl(newToNextLvl);
						ShowScore(score);

						_items.RemoveAt(i);
						delete[] item;
						break;
					}
				}
			}
			_display->ShowSymbol(L' ', oldX, oldY);
			_lvl->SetSymbol(L' ', oldX, oldY);
			ShowSnake();
			sleep = 1000 / _snake->GetSpeed();

			if (_lvl->GetToNextLvl() == 0)
				NewLvl();

			Sleep(sleep);
		}
	}
}

void Game::ItemMaker()
{
	Sleep(1500);
	ItemCreator* creator = nullptr;
	int x;
	int y;
	while (_threadsRun)
	{
		if (!_pause)
		{
			creator = Creator();
			x = _random.Next(1, _lvl->GetRow() - 2);
			y = _random.Next(1, _lvl->GetCol() - 2);
			while (true)
			{
				if (!_lvl->IsRoad(x, y))
				{
					x = _random.Next(1, _lvl->GetRow() - 2);
					y = _random.Next(1, _lvl->GetCol() - 2);
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
}