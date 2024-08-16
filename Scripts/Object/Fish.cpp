#include "Fish.h"
#include "../Utility/RandomGenerator.h"

void Fish::GenerateSize(FishSize size)
{
    Size = size;
}

int Fish::GeneratePrice()
{
    if (minPrice == 0)
    {
        return price = maxPrice;
    }

    return price = RandomGenerator::RandomRange(minPrice, maxPrice);
}

void RedFish::GenerateSize(FishSize size)
{
    Fish::GenerateSize(size);
    if (size == FishSize::Small)
    {
        minPrice = 1;
        maxPrice = 5;
    }
    else if (size == FishSize::Medium)
    {
        minPrice = 5;
        maxPrice = 10;
    }
    else
    {
        minPrice = 10;
        maxPrice = 15;
    }
}

void BlueFish::GenerateSize(FishSize size)
{
    Fish::GenerateSize(size);
    if (size == FishSize::Small)
    {
        minPrice = 3;
        maxPrice = 5;
    }
    else if (size == FishSize::Medium)
    {
        minPrice = 8;
        maxPrice = 10;
    }
    else
    {
        minPrice = 13;
        maxPrice = 15;
    }
}

void GreenFish::GenerateSize(FishSize size)
{
    Fish::GenerateSize(size);
    if (size == FishSize::Small)
    {
        maxPrice = 5;
    }
    else if (size == FishSize::Medium)
    {
        maxPrice = 10;
    }
    else
    {
        maxPrice = 15;
    }
}
