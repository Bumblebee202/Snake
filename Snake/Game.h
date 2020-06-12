#pragma once
#include <cmath>
#include <Windows.h>
#include <thread>
#include "Other/ThreadSafeVector.h"
#include "Other/Random.h"
#include "BaseApp.h"
#include "Header.h"
#include "Menus.h"
#include "Levels.h"
#include "Snakes.h"
#include "Display/ConsoleDisplay.h"
#include "Creators.h"

class Game : public BaseApp
{
private:
    std::atomic<bool> _threadsRun;
	std::atomic<bool> _pause;
	std::atomic<bool> _exit;
	int _totalScore;
	//int _score;
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
	void ShowScore(int score);
	void ClearField();
	ItemCreator* Creator();
public:
	Game(IDisplay<wchar_t>* display);
	~Game();
	virtual void Start() override;
	virtual void Stop() override;
};