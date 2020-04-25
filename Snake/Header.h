#pragma once
#include "Colors.h"
#include "Time.h"

enum class Direction
{
	Right,
	Left,
	Up,
	Down
};

struct Element
{
	wchar_t Symbol;
	int X;
	int Y;
	Element* Next;
	Element* Prev;
};

