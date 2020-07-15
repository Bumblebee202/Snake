#pragma once
#include <iostream>
#include <mutex>
//#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include "IDisplay.h"
#include "../Settings//Buttons.h"

template<typename T = wchar_t>
class ConsoleDisplay : public IDisplay<T>
{
private:
	Buttons* _buttons;
	std::mutex _mutex;
	HANDLE _handle;
	COORD _cursorCoord;
	CONSOLE_CURSOR_INFO _cursorInfo;

	void SetCursorPosition(int x, int y);
	void VisibleCursor(bool value = true);
public:
	ConsoleDisplay();
	~ConsoleDisplay();

	void SetWidnowSize(int x, int y) override;
	void SetColor(Color background = Color::Black, Color foreground = Color::DarkGray) override;
	void ShowObject(T obj, int x = 0, int y = 0) override;
	void ShowObjects(T* objs, int len, int startX = 0, int startY = 0) override;
	void ShowObjects(T** objs, int row, int col, int startX = 0, int startY = 0) override;
	void ShowText(wchar_t* text, int startX = 0, int startY = 0) override;
	void ShowText(std::wstring text, int startX = 0, int startY = 0) override;
	void ShowTime(Time& time, int x = 0, int y = 0) override;
	void ShowNumber(int value, int x = 0, int y = 0) override;
	void ShowNumber(float value, int x = 0, int y = 0) override;
	void ShowSymbol(wchar_t value, int x = 0, int y = 0) override;
	std::wstring EnterText(int x = 0, int y = 0, int maxLen = 10) override;
	void ClearDisplay() override;
};

template<typename T>
ConsoleDisplay<T>::ConsoleDisplay() : IDisplay<T>()
{
	_buttons = Buttons::GetInstance();

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
inline void ConsoleDisplay<T>::SetCursorPosition(int x, int y)
{
	_cursorCoord.X = x;
	_cursorCoord.Y = y;
	SetConsoleCursorPosition(_handle, _cursorCoord);
}

template<typename T>
inline void ConsoleDisplay<T>::VisibleCursor(bool value)
{
	_cursorInfo.bVisible = value;
	SetConsoleCursorInfo(_handle, &_cursorInfo);
}

template<typename T>
inline void ConsoleDisplay<T>::SetWidnowSize(int x, int y)
{
	_mutex.lock();
	std::string str = std::string("mode con: lines=")
		.append(std::to_string(y))
		.append(" cols=")
		.append(std::to_string(x));
	system(str.c_str());
	_mutex.unlock();
}

template<typename T>
inline void ConsoleDisplay<T>::SetColor(Color background, Color foreground)
{
	_mutex.lock();
	int b = static_cast<int>(background);
	int f = static_cast<int>(foreground);
	SetConsoleTextAttribute(_handle, f | (b << 4));
	_mutex.unlock();
}

template<typename T>
inline void ConsoleDisplay<T>::ShowObject(T obj, int x, int y)
{
	_mutex.lock();
	SetCursorPosition(x, y);
	std::wcout << obj;
	_mutex.unlock();
}

template<typename T>
inline void ConsoleDisplay<T>::ShowObjects(T* objs, int len, int startX, int startY)
{
	_mutex.lock();
	SetCursorPosition(startX, startY);

	for (int i = 0; i < len; i++)
	{
		SetConsoleCursorPosition(_handle, _cursorCoord);
		std::wcout << *(objs + i);
		_cursorCoord.X++;
	}

	_mutex.unlock();
}

template<typename T>
inline void ConsoleDisplay<T>::ShowObjects(T** objs, int row, int col, int startX, int startY)
{
	_mutex.lock();
	SetCursorPosition(startX, startY);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			SetConsoleCursorPosition(_handle, _cursorCoord);
			std::wcout << *(*(objs + i) + j);
			_cursorCoord.Y++;
		}
		_cursorCoord.X++;
		_cursorCoord.Y = startY;
	}

	_mutex.unlock();
}

template<typename T>
inline void ConsoleDisplay<T>::ShowText(wchar_t* text, int startX, int startY)
{
	_mutex.lock();
	SetCursorPosition(startX, startY);
	std::wcout << text;
	_mutex.unlock();
}

template<typename T>
inline void ConsoleDisplay<T>::ShowText(std::wstring text, int startX, int startY)
{
	_mutex.lock();
	SetCursorPosition(startX, startY);
	std::wcout << text;
	_mutex.unlock();
}

template<typename T>
inline void ConsoleDisplay<T>::ShowTime(Time& time, int x, int y)
{
	_mutex.lock();
	SetCursorPosition(x, y);
	std::wcout << L"Time: ";
	if (time.Hour() > 0)
		std::wcout << time.Hour() << L":";
	std::wcout << time.Minute() << L":" << time.Second();
	_mutex.unlock();
}

template<typename T>
inline void ConsoleDisplay<T>::ShowNumber(int value, int x, int y)
{
	_mutex.lock();
	SetCursorPosition(x, y);
	std::wcout << value;
	_mutex.unlock();
}

template<typename T>
inline void ConsoleDisplay<T>::ShowNumber(float value, int x, int y)
{
	_mutex.lock();
	SetCursorPosition(x, y);
	std::wcout << value;
	_mutex.unlock();
}

template<typename T>
inline void ConsoleDisplay<T>::ShowSymbol(wchar_t value, int x, int y)
{
	_mutex.lock();
	SetCursorPosition(x, y);
	std::wcout << value;
	_mutex.unlock();
}

template<typename T>
inline std::wstring ConsoleDisplay<T>::EnterText(int x, int y, int maxLen)
{
	_mutex.lock();
	VisibleCursor();
	SetCursorPosition(x, y);

	int newX = x;
	std::wstring str = std::wstring();
	std::wstring empty;

	int index = 0;
	while (true)
	{
		wchar_t symbol = _getwch();

		if (_buttons->IsEnter(symbol) && str.length() > 0)
			break;
		else if (_buttons->IsEnter(symbol))
			continue;
		else if (_buttons->IsEsc(symbol))
			continue;

		if (symbol == 224)
		{
			symbol = _getwch();

			if (_buttons->IsLeft(symbol))
			{
				if (x + index > x)
				{
					newX--;
					index--;
					SetCursorPosition(newX, y);
				}
				continue;
			}
			else if (_buttons->IsRight(symbol))
			{
				if (index < str.length() && index < maxLen - 1)
				{
					newX++;
					index++;
					SetCursorPosition(newX, y);
				}
				continue;
			}
			else if (_buttons->IsUp(symbol) || _buttons->IsDown(symbol))
				continue;
		}

		if (_buttons->IsBackspace(symbol))
		{
			if (str.length() > 0)
			{
				empty = std::wstring(str.length(), L' ');
				SetCursorPosition(x, y);
				std::wcout << empty;

				str.erase(str.begin() + index);
				newX = x < newX ? --newX : newX;
				index = index > 0 ? --index : index;
			}
		}
		else if (index == str.length() && str.length() < maxLen)
		{
			str.insert(str.begin() + index, symbol);
			index = index < maxLen - 1 ? ++index : index;
			newX = str.length() < maxLen ? ++newX : newX;
		}
		else if (str.length() == maxLen)
		{
			str[index] = symbol;
		}
		else
		{
			str[index] = symbol;
			index = index < maxLen ? ++index : index;
			newX = str.length() < maxLen ? ++newX : newX;
		}

		VisibleCursor(false);
		SetCursorPosition(x, y);
		std::wcout << str;
		SetCursorPosition(newX, y);
		VisibleCursor();
	}

	VisibleCursor(false);

	_mutex.unlock();
	return str;
}

template<typename T>
inline void ConsoleDisplay<T>::ClearDisplay()
{
	system("cls");
}
