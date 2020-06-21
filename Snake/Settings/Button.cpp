#include "Button.h"

Button* Button::_singleton = nullptr;
std::mutex Button::_mutex;

Button::Button()
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

Button* Button::GetInstance()
{
	if (_singleton == nullptr)
	{
		std::lock_guard<std::mutex> lock(_mutex);
		if (_singleton == nullptr)
			_singleton = new Button();
	}
	return _singleton;
}

void Button::SetUp(int value)
{
	_up = value;
}

int Button::GetUp() const
{
	return _up;
}

void Button::SetDown(int value)
{
	_down = value;
}

int Button::GetDown() const
{
	return _down;
}

void Button::SetLeft(int value)
{
	_left = value;
}

int Button::GetLeft() const
{
	return _left;
}

void Button::SetRight(int value)
{
	_right = value;
}

int Button::GetRight() const
{
	return _right;
}

int Button::GetEnter() const
{
	return _enter;
}

int Button::GetEsc() const
{
	return _esc;
}

int Button::GetSpace() const
{
	return _space;
}

int Button::GetBackspace() const
{
	return _backspace;
}

bool Button::IsUp(int key) const
{
	return _up == key ? true : false;
}

bool Button::IsDown(int key) const
{
	return _down == key ? true : false;
}

bool Button::IsLeft(int key) const
{
	return _left == key ? true : false;
}

bool Button::IsRight(int key) const
{
	return _right == key ? true : false;
}

bool Button::IsEnter(int key) const
{
	return _enter == key ? true : false;
}

bool Button::IsEsc(int key) const
{
	return _esc == key ? true : false;
}

bool Button::IsSpace(int key) const
{
	return _space == key ? true : false;
}

bool Button::IsBackspace(int key) const
{
	return _backspace == key ? true : false;
}
