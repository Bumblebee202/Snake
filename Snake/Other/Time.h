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
	Time(int hour, int minute, int second, float millisecond);

	float Millisecond() const;
	int Second() const;
	int Minute() const;
	int Hour() const;

	void Add(Time& value);
	void Add(int hour, int minute, int second, float millisecond);
	void AddMillisecond(float value);
	void AddSeconds(int value);
	void AddMinutes(int value);
	void AddHours(int value);
	void SetTime(Time& value);
	void SetTime(int hour, int minute, int second, float millisecond);
	std::wstring ToString();
};

