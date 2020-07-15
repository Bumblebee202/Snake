#include "Rating.h"

Rating::Rating()
{
	_id = -1;
	_name = L"";
	_score = -1;
	_time = Time();
}

Rating::Rating(int id, std::wstring userName, int score, Time time)
{
	_id = id;
	_name = userName;
	_score = score;
	_time = time;
}

void Rating::SetID(int value)
{
	_id = value;
}

int Rating::GetID() const
{
	return _id;
}

void Rating::SetName(std::wstring value)
{
	_name = value;
}

std::wstring Rating::GetName() const
{
	return _name;
}

void Rating::SetScore(int value)
{
	_score = value;
}

int Rating::GetScore() const
{
	return _score;
}

void Rating::SetTime(Time value)
{
	_time = value;
}

Time Rating::GetTime() const
{
	return _time;
}
