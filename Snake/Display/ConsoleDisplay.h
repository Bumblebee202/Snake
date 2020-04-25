#pragma once
#include <iostream>
//#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include "DisplayBase.h"

template<typename T>
class ConsoleDisplay : public DisplayBase<T>
{
private:
	HANDLE _handle;
	COORD _cursorCoord;
	CONSOLE_CURSOR_INFO _cursorInfo;
public:
	ConsoleDisplay();
	~ConsoleDisplay();

	void SetColor(Color background = Color::Black, Color foreground = Color::DarkGray) override;
	void ShowObject(T obj, int x = 0, int y = 0) override;
	void ShowObjects(T* objs, int len, int startX = 0, int startY = 0) override;
	void ShowObjects(T** objs, int row, int col, int startX = 0, int startY = 0) override;
	void ShowText(wchar_t* text, int len, int startX = 0, int startY = 0) override;
	void ShowText(std::wstring text, int startX = 0, int startY = 0) override;
	void ShowTime(Time& time, int x = 0, int y = 0) override;
};

template<typename T>
ConsoleDisplay<T>::ConsoleDisplay() : DisplayBase<T>()
{
	_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	_cursorCoord.X = 25;
	_cursorCoord.Y = 40;
	
	_cursorInfo.bVisible = false;
	_cursorInfo.dwSize = 100;
	SetConsoleCursorInfo(_handle, &_cursorInfo);
}

template<typename T>
ConsoleDisplay<T>::~ConsoleDisplay()
{
	delete _handle;
}

template<typename T>
inline void ConsoleDisplay<T>::SetColor(Color background, Color foreground)
{
	int b = static_cast<int>(background);
	int f = static_cast<int>(foreground);
	SetConsoleTextAttribute(_handle, f | (b << 4));
}

template<typename T>
inline void ConsoleDisplay<T>::ShowObject(T obj, int x, int y)
{
	_cursorCoord.X = x;
	_cursorCoord.Y = y;
	SetConsoleCursorPosition(_handle, _cursorCoord);
	std::wcout << obj;
}

template<typename T>
inline void ConsoleDisplay<T>::ShowObjects(T* objs, int len, int startX, int startY)
{
	_cursorCoord.X = startX;
	_cursorCoord.Y = startY;

	for (int i = 0; i < len; i++)
	{
		SetConsoleCursorPosition(_handle, _cursorCoord);
		std::wcout << *(objs + i);
		_cursorCoord.X++;
	}
}

template<typename T>
inline void ConsoleDisplay<T>::ShowObjects(T** objs, int row, int col, int startX, int startY)
{
	_cursorCoord.X = startX;
	_cursorCoord.Y = startY;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			SetConsoleCursorPosition(_handle, _cursorCoord);
			std::wcout << *(*(objs + i) + j);
			_cursorCoord.X++;
		}
		_cursorCoord.Y++;
		_cursorCoord.X = startX;
	}
}

template<typename T>
inline void ConsoleDisplay<T>::ShowText(wchar_t* text, int len, int startX, int startY)
{
	_cursorCoord.X = startX;
	_cursorCoord.Y = startY;
	SetConsoleCursorPosition(_handle, _cursorCoord);
	std::wcout << text;
}

template<typename T>
inline void ConsoleDisplay<T>::ShowText(std::wstring text, int startX, int startY)
{
	_cursorCoord.X = startX;
	_cursorCoord.Y = startY;
	SetConsoleCursorPosition(_handle, _cursorCoord);
	std::wcout << text;
}

template<typename T>
inline void ConsoleDisplay<T>::ShowTime(Time& time, int x, int y)
{
	_cursorCoord.X = x;
	_cursorCoord.Y = y;
	SetConsoleCursorPosition(_handle, _cursorCoord);
	std::wcout << L"Time: ";
	if (time.Hour() > 0)
		std::wcout << time.Hour() << L":";
	std::wcout << time.Minute() << L":" << time.Second();
}
