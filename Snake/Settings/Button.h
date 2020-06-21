#pragma once
#include <mutex>

class Button
{
private:
	int _up;
	int _down;
	int _left;
	int _right;
	int _enter;
	int _esc;
	int _space;
	int _backspace;

	static std::mutex _mutex;
	static Button* _singleton;

	Button();
public:
	static Button* GetInstance();

	void SetUp(int value);
	int GetUp() const;
	void SetDown(int value);
	int GetDown() const;
	void SetLeft(int value);
	int GetLeft() const;
	void SetRight(int value);
	int GetRight() const;
	int GetEnter() const;
	int GetEsc() const;
	int GetSpace() const;
	int GetBackspace() const;

	bool IsUp(int key) const;
	bool IsDown(int key) const;
	bool IsLeft(int key) const;
	bool IsRight(int key) const;
	bool IsEnter(int key) const;
	bool IsEsc(int key) const;
	bool IsSpace(int key) const;
	bool IsBackspace(int key) const;

	Button(Button& s) = delete;
	void operator=(const Button& s) = delete;
};
