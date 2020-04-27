#pragma once
#include <string>

class Time
{
private:
	float _millisecond;
	int _second;
	int _minute;
	int _hour;
public:
	Time();
	Time(int hour, int minute, int second, int millisecond);

	float Millisecond() const;
	int Second() const;
	int Minute() const;
	int Hour() const;

	void AddMillisecond(float value);
	void AddSeconds(int value);
	void AddMinutes(int value);
	void AddHours(int value);
	std::wstring ToString();
};

