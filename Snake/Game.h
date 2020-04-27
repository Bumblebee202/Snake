#pragma once
#include <atomic>
#include <cmath>
#include <Windows.h>
#include <vector>
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
#include "Creators.h"

class Game : public BaseApp
{
private:
	//std::atomic<float> _deltaTime;
	bool _pause;
	int _score;
	Time _time;
	Snake* _snake;
	LevelBase* _lvl;
	IDisplay<wchar_t>* _display;
	MenuBase* _menu;
	std::vector<ItemBase*> _items;

	/*void (Game::*Show)();
	void (Game::*Action)(int btnCode);*/
protected:
	virtual void Update(float deltaTime) override;
	virtual void KeyPressed(int btnCode) override;

	void ShowSnake();
	void ClearSnakeTail();
	ItemCreator* Creator();
public:
	Game(IDisplay<wchar_t>* display);
	~Game();
	virtual void Start() override;
};

