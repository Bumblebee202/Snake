#pragma once
#include <conio.h>
#include <stdexcept>
#include <string>
#include "../Display/ConsoleDisplay.h"

class MenuBase
{
protected:
	bool _close;
	std::wstring* _menu;
	int _length;
	int _selectedMenuItem;
	IDisplay<wchar_t>* _display;

	void virtual GenerateMenu() = 0;
public:
	MenuBase();
	MenuBase(IDisplay<wchar_t>* display);
	MenuBase(std::wstring* menu, int lenght);
	MenuBase(std::wstring* menu, int lenght, int selectedMenuItem);
	MenuBase(std::wstring* menu, int lenght, IDisplay<wchar_t>* display);
	MenuBase(std::wstring* menu, int lenght, int selectedMenuItem, IDisplay<wchar_t>* display);
	virtual ~MenuBase();

	std::wstring* GetMenu() const;
	std::wstring GetMenuItem(int index) const;
	int Length() const;
	int GetSelectedMenuItem() const;
	void SetSelectedMenuItem(int value);
	void Up();
	void Down();
	void virtual SelectMenuItem() = 0;
	void virtual Open();
	void Show(int width);
	void Clear(int width);
};

