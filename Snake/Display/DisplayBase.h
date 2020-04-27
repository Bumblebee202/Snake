#pragma once
#include "../Colors.h"
#include "../Time.h"

template <typename T>
class DisplayBase
{
public:
	virtual void SetColor(Color background = Color::Black, Color foreground = Color::LightGray) = 0;
	virtual void ShowObject(T obj, int x = 0, int y = 0) = 0;
	virtual void ShowObjects(T* objs, int len, int startX = 0, int startY = 0) = 0;
	virtual void ShowObjects(T** objs, int row, int col, int startX = 0, int startY = 0) = 0;
	virtual void ShowText(wchar_t* text, int len, int startX = 0, int startY = 0) = 0;
	virtual void ShowText(std::wstring text, int startX = 0, int startY = 0) = 0;
	virtual void ShowTime(Time& time, int x = 0, int y = 0) = 0;
};
