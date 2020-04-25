#pragma once
#include "../Colors.h"

class ItemBase
{
protected:
	int _x;
	int _y;
	wchar_t _symbol;
	Color _color;
public:
	virtual ~ItemBase();


	void SetSymbol(wchar_t symbol);
	wchar_t GetSymbol() const;
	void SetColor(Color color = Color::LightGray);
	Color GetColor() const;
};

