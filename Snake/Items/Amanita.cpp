#include "Amanita.h"

Amanita::Amanita()
{
	_symbol = static_cast<wchar_t>(9788);
	_score = -20;
	_color = Color::LightRed;
}

Amanita::Amanita(int x, int y) : ItemBase(x, y)
{
	_symbol = static_cast<wchar_t>(9788);
	_score = -20;
	_color = Color::LightRed;
}

std::wstring Amanita::Description()
{
	return std::wstring(L" - Amanita. Takes 20 points");
}

void Amanita::Interaction(Snake* snake)
{
	snake->AddTail();
}
