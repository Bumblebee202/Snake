#pragma once
#include <string>
#include "../Colors.h"
#include "IEdible.h"

class ItemBase : public IEdible
{
protected:
	int _x;
	int _y;
	int _score;
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
	int GetScore() override;
	//void virtual Effect(Snake* snake) override = 0;
};

