#include "RandomGenerator.h"

int RandomGenerator::RandomRange(int min, int max)
{
    // Initialize a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);

    return distrib(gen);
}

std::list<int> RandomGenerator::RandomWithSum(int sum)
{
    std::list<int> numberList;
    for (int i = 0; i < sum; i++)
    {
        numberList.push_back(RandomRange(0, sum));
    }

    return numberList;
}
