#include "Amanita.h"

Amanita::Amanita()
{
	_symbol = static_cast<wchar_t>(9679);
	_color = Color::LightMagenta;
}

Amanita::Amanita(int x, int y) : ItemBase(x, y)
{
	_symbol = static_cast<wchar_t>(9679);
	//_score = 5;
	_color = Color::LightMagenta;
}

std::wstring Amanita::Description()
{
	return std::wstring(L" - Amanita. Takes 20 points");
}
