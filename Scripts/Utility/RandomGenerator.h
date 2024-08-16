#pragma once

#include <list>
#include <random>

class RandomGenerator
{
public:
	static int RandomRange(int min, int max);
	static std::list<int> RandomWithSum(int sum);
};

