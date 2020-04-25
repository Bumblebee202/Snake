#include "Time.h"
#include "Time.h"

Time::Time()
{
	_millisecond = 0.0f;
	_second = 0;
	_minute = 0;
	_hour = 0;
}

Time::Time(int hour, int minute, int second, int millisecond)
{
	_millisecond = static_cast<float>(millisecond);
	_second = second;
	_minute = minute;
	_hour = hour;
}

int Time::Millisecond() const
{
	return static_cast<int>(_millisecond);
}

int Time::Second() const
{
	return static_cast<int>(_second);
}

int Time::Minute() const
{
	return static_cast<int>(_minute);
}

int Time::Hour() const
{
	return static_cast<int>(_hour);
}

void Time::AddMillisecond(float value)
{
	_millisecond += value;
	if (_millisecond >= 1.0f)
	{
		AddSeconds(1);
		_millisecond -= 1.0f;
	}
}

void Time::AddSeconds(int value)
{
	_second += value;
	if (_second >= 60)
	{
		AddMinutes(1);
		_second -= 60;
	}
}

void Time::AddMinutes(int value)
{
	_minute += value;
	if (_minute >= 60)
	{
		AddHours(1);
		_minute -= 60;
	}
}

void Time::AddHours(int value)
{
	_hour += value;
}

std::wstring Time::ToString()
{
	std::wstring minute = std::to_wstring(_minute);
	std::wstring second = std::to_wstring(_second);
	std::wstring time = L"Time: ";
	if (_hour > 0)
	{
		std::wstring hour = std::to_wstring(_hour);
		time.append(hour).append(L":");
	}
	time.append(minute).append(L":").append(second);
	return time;
}
