#pragma once
#include <string>
#include "../Colors.h"

class ItemBase
{
protected:
	int _x;
	int _y;
	wchar_t _symbol;
	Color _color;
public:
	ItemBase();
	ItemBase(int x, int y);
	virtual ~ItemBase();

	int GetX() const;
	void SetX(int x);
	int GetY() const;
	void SetY(int y);
	void SetSymbol(wchar_t symbol);
	wchar_t GetSymbol() const;
	void SetColor(Color color = Color::LightGray);
	Color GetColor() const;
	std::wstring virtual Description() = 0;
};

