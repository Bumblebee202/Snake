#include "Timer.h"

Timer::Timer()
{
	QueryPerformanceFrequency(&_liPerfFreq);
	Start();
}

void Timer::Start()
{
	QueryPerformanceCounter(&_liPerfStart);
}

int Timer::Now()
{
	// возвращает число миллисекунд после вызова Start
	LARGE_INTEGER liPerfNow;
	QueryPerformanceCounter(&liPerfNow);
	return (((liPerfNow.QuadPart - _liPerfStart.QuadPart) * 1000) / _liPerfFreq.QuadPart);
}

int Timer::Time()
{
	LARGE_INTEGER liPerfNow;
	QueryPerformanceCounter(&liPerfNow);
	return ((liPerfNow.QuadPart * 1000) / _liPerfFreq.QuadPart);
}
