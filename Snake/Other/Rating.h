#pragma once
#include <string>
#include "Time.h"

class Rating
{
private:
	int _id;
	std::wstring _name;
	int _score;
	Time _time;
public:
	Rating();
	Rating(int id, std::wstring userName, int score, Time time);

	void SetID(int value);
	int GetID() const;
	void SetName(std::wstring value);
	std::wstring GetName() const;
	void SetScore(int value);
	int GetScore() const;
	void SetTime(Time value);
	Time GetTime() const;
};

