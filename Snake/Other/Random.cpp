#include "Random.h"

Random::Random()
{
	std::random_device rd;
	_mt = std::mt19937(rd());
}

short Random::Next(short min, short max)
{
	if (min > max)
		std::swap(min, max);

	std::uniform_int_distribution<short> dist(min, max);
	return dist(_mt);
}

int Random::Next(int min, int max)
{
	if (min > max)
		std::swap(min, max);

	std::uniform_int_distribution<int> dist(min, max);
	return dist(_mt);
}

long Random::Next(long min, long max)
{
	if (min > max)
		std::swap(min, max);

	std::uniform_int_distribution<long> dist(min, max);
	return dist(_mt);
}

long long Random::Next(long long min, long long max)
{
	if (min > max)
		std::swap(min, max);

	std::uniform_int_distribution<long long> dist(min, max);
	return dist(_mt);
}

float Random::Next(float min, float max)
{
	if (min > max)
		std::swap(min, max);

	std::uniform_real_distribution<float> dist(min, max);
	return dist(_mt);
}

double Random::Next(double min, double max)
{
	if (min > max)
		std::swap(min, max);

	std::uniform_real_distribution<double> dist(min, max);
	return dist(_mt);
}

long double Random::Next(long double min, long double max)
{
	if (min > max)
		std::swap(min, max);

	std::uniform_real_distribution<long double> dist(min, max);
	return dist(_mt);
}
