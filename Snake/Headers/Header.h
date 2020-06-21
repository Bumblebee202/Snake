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

struct SnakePart
{
	int X;
	int Y;
	SnakePart* Next;
	SnakePart* Prev;
};

