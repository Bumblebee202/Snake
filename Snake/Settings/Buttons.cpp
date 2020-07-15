#include "Buttons.h"

Buttons* Buttons::_singleton = nullptr;
std::mutex Buttons::_mutex;

Buttons::Buttons()
{
	_up = 72;
	_down = 80;
	_left = 75;
	_right = 77;
	_esc = 27;
	_enter = 13;
	_space = 32;
	_backspace = 8;
}

Buttons* Buttons::GetInstance()
{
	if (_singleton == nullptr)
	{
		std::lock_guard<std::mutex> lock(_mutex);
		if (_singleton == nullptr)
			_singleton = new Buttons();
	}
	return _singleton;
}

Buttons::~Buttons()
{
	_singleton = nullptr;
}

void Buttons::SetUp(int value)
{
	_up = value;
}

int Buttons::GetUp() const
{
	return _up;
}

void Buttons::SetDown(int value)
{
	_down = value;
}

int Buttons::GetDown() const
{
	return _down;
}

void Buttons::SetLeft(int value)
{
	_left = value;
}

int Buttons::GetLeft() const
{
	return _left;
}

void Buttons::SetRight(int value)
{
	_right = value;
}

int Buttons::GetRight() const
{
	return _right;
}

int Buttons::GetEnter() const
{
	return _enter;
}

int Buttons::GetEsc() const
{
	return _esc;
}

int Buttons::GetSpace() const
{
	return _space;
}

int Buttons::GetBackspace() const
{
	return _backspace;
}

bool Buttons::IsUp(int key) const
{
	return _up == key ? true : false;
}

bool Buttons::IsDown(int key) const
{
	return _down == key ? true : false;
}

bool Buttons::IsLeft(int key) const
{
	return _left == key ? true : false;
}

bool Buttons::IsRight(int key) const
{
	return _right == key ? true : false;
}

bool Buttons::IsEnter(int key) const
{
	return _enter == key ? true : false;
}

bool Buttons::IsEsc(int key) const
{
	return _esc == key ? true : false;
}

bool Buttons::IsSpace(int key) const
{
	return _space == key ? true : false;
}

bool Buttons::IsBackspace(int key) const
{
	return _backspace == key ? true : false;
}
