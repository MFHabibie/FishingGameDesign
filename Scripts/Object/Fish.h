#pragma once
#include "../Utility//EnumData.h"

class Fish
{
public:
	FishColor Color;
	FishSize Size;
	int minPrice;
	int maxPrice;
};

class RedSmallFish : Fish
{
public:
	RedSmallFish()
	{
		Color = FishColor::RedFish;
		Size = FishSize::Small;
		minPrice = 1;
		maxPrice = 5;
	}
};

class RedMediumFish : Fish
{
public:
	RedMediumFish()
	{
		Color = FishColor::RedFish;
		Size = FishSize::Medium;
		minPrice = 5;
		maxPrice = 10;
	}
};

class RedBigFish : Fish
{
public:
	RedBigFish()
	{
		Color = FishColor::RedFish;
		Size = FishSize::Big;
		minPrice = 10;
		maxPrice = 15;
	}
};