#pragma once
#include "../Utility/EnumData.h"

class FishingPole
{
public:
	FishingPoleType Type;
	int Price;
};

class SmallFishingPole : public FishingPole
{
public:
	SmallFishingPole()
	{
		Type = FishingPoleType::SmallPole;
		Price = 5;
	}
};

class MediumFishingPole : public FishingPole
{
public:
	MediumFishingPole()
	{
		Type = FishingPoleType::MediumPole;
		Price = 10;
	}
};

class BigFishingPole : public FishingPole
{
public:
	BigFishingPole()
	{
		Type = FishingPoleType::BigPole;
		Price = 15;
	}
};

