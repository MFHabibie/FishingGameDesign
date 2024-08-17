#pragma once

#include <list>
#include <random>

class RandomGenerator
{
public:
	/// <summary>
	/// Random number generator
	/// </summary>
	/// <param name="min">: Inclusive number</param>
	/// <param name="max">: Inclusive number</param>
	/// <returns>Random number between min and max</returns>
	int RandomRange(int min, int max);
};

