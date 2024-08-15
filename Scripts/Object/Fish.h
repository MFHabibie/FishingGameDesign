#pragma once
#include "../Utility/EnumData.h"

class Fish
{
public:
	FishColor Color;
	FishSize Size;
	int minPrice;
	int maxPrice;
};

class RedFish : public Fish
{
public:
	RedFish()
	{
		Color = FishColor::RedFish;
		minPrice = 1;
		maxPrice = 5;
	}
};

class BlueFish : public Fish
{
public:
	BlueFish()
	{
		Color = FishColor::BlueFish;
		minPrice = 5;
		maxPrice = 10;
	}
};

class GreenFish : public Fish
{
public:
	GreenFish()
	{
		Color = FishColor::GreenFish;
		minPrice = 10;
		maxPrice = 15;
	}
};