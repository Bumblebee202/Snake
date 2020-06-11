#pragma once
#include <conio.h>
#include <stdexcept>
#include <string>
#include "../Display/ConsoleDisplay.h"
#include "../Settings/Button.h"

class MenuBase
{
protected:
	bool _close;
	std::wstring* _menu;
	int _width;
	int _length;
	int _selectedMenuItem;
	IDisplay<wchar_t>* _display;
	Button* _button;

	void virtual GenerateMenu() = 0;
public:
	MenuBase();
	MenuBase(IDisplay<wchar_t>* display, int width);
	MenuBase(std::wstring* menu, int lenght, int width);
	MenuBase(std::wstring* menu, int lenght, int selectedMenuItem, int width);
	MenuBase(std::wstring* menu, int lenght, IDisplay<wchar_t>* display, int width);
	MenuBase(std::wstring* menu, int lenght, int selectedMenuItem, IDisplay<wchar_t>* display, int width);
	virtual ~MenuBase();

	std::wstring* GetMenu() const;
	std::wstring GetMenuItem(int index) const;
	int Length() const;
	int GetSelectedMenuItem() const;
	void SetSelectedMenuItem(int value);
	void SetRowWidth(int value);
	void Up();
	void Down();
	void virtual SelectMenuItem() = 0;
	void virtual Open();
	void virtual Show();
	void virtual Clear();
};

