#pragma once
#include <atomic>
#include <cmath>
#include <Windows.h>
#include <thread>
#include "Other/ThreadSafeVector.h"
#include "Other/Random.h"
#include "BaseApp.h"
#include "Header.h"
#include "Menus/MenuBase.h"
#include "Menus/MainMenu.h"
#include "Menus/Pause.h"
#include "Snakes/Snake.h"
#include "Levels/LevelBase.h"
#include "Levels/FirstLevel.h"
#include "Levels/SecondLevel.h"
#include "Display/ConsoleDisplay.h"
#include "Creators.h"
#include "Snakes/State/NormalMove.h"

class Game : public BaseApp
{
private:
	bool _threadsRun;
	bool _pause;
	bool _exit;
	int _totalScore;
	int _score;
	Time _time;
	Time _totalTime;
	Random _random;
	Snake* _snake;
	LevelBase* _lvl;
	IDisplay<wchar_t>* _display;
	MenuBase* _menu;
	ThreadSafeVector<ItemBase*> _items;

	void SnakeMovement();
	void ItemMaker();
protected:
	virtual void Update(float deltaTime) override;
	virtual void KeyPressed(int btnCode) override;

	void NewLvl();
	void Lose();
	void ShowSnake();
	void ShowScore();
	void ClearField();
	ItemCreator* Creator();
public:
	Game(IDisplay<wchar_t>* display);
	~Game();
	virtual void Start() override;
	virtual void Stop() override;
};

