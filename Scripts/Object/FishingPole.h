#pragma once
#include "../Utility/EnumData.h"

class FishingPole
{
public:
	FishingPoleType GetType() const { return Type; }
	int GetPrice() const { return Price; }

protected:
	FishingPoleType Type = FishingPoleType::SmallPole;
	int Price = 0;
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

