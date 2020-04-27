#pragma once
#include <atomic>
#include <Windows.h>
#include <thread>
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
	//std::atomic<float> _deltaTime;
	bool _pause;
	int _score;
	Time _time;
	Snake* _snake;
	LevelBase* _lvl;
	DisplayBase<wchar_t>* _display;
	MenuBase* _menu;

	/*void (Game::*Show)();
	void (Game::*Action)(int btnCode);*/
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

