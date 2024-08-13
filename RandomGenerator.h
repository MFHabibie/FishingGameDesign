#pragma once

#include <list>
#include <random>

class RandomGenerator
{
	RandomGenerator() { }
	~RandomGenerator() { }

public:
	int RandomRange(int min, int max);
	std::list<int> RandomWithSum(int sum);
};

