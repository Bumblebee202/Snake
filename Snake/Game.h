#pragma once
#include <Windows.h>
#include <thread>
#include <mutex>
#include "BaseApp.h"
#include "Header.h"
#include "Menus/MenuBase.h"
#include "Menus/MainMenu.h"
#include "Menus/Pause.h"
#include "Snakes/Snake.h"
#include "Levels/LevelBase.h"
#include "Levels/FirstLevel.h"
#include "Display/ConsoleDisplay.h"

class Game : public BaseApp
{
private:
	int _score;
	Time _time;
	Snake* _snake;
	LevelBase* _lvl;
	DisplayBase<wchar_t>* _display;
	MenuBase* _menu;
	std::mutex _mutex;

	void (Game::*Show)();
	void (Game::*Action)(int btnCode);
protected:
	virtual void Update(float deltaTime) override;
	virtual void KeyPressed(int btnCode) override;

	void ShowSnake();
	void ClearSnakeTail();
public:
	Game(DisplayBase<wchar_t>* display);
	~Game();
	virtual void Start() override;
};

