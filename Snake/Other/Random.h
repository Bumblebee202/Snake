#pragma once
#include <random>

class Random
{
private:
	std::mt19937 _mt;
public:
	Random();

	short Next(short min = 0, short max = 1);
	int Next(int min = 0, int max = 1);
	long Next(long min = 0L, long max = 1L);
	long long Next(long long min = 0LL, long long max = 1LL);
	float Next(float min = 0.0f, float max = 1.0f);
	double Next(double min = 0.0, double max = 1.0);
	long double Next(long double min = 0.0L, long double max = 1.0L);
};

