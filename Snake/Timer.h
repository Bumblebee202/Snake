#pragma once
#include <windows.h>

class Timer
{
private:
	LARGE_INTEGER _liPerfFreq;
	LARGE_INTEGER _liPerfStart;
public:
	Timer();
	void Start();
	int Now();
	int Time();
};

