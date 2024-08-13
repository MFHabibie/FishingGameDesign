#pragma once

#include <list>
#include <random>

class RandomGenerator
{
public:
	int RandomRange(int min, int max);
	std::list<int> RandomWithSum(int sum);
};

