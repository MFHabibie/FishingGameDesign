#pragma once
#include "../Utility/EnumData.h"

class FishingPole
{
public:
	/// <summary>
	/// Get type of the fishing pole
	/// </summary>
	/// <returns>Fishing pole type based on FishingPoleType enum</returns>
	FishingPoleType GetType() const { return Type; }

	/// <summary>
	/// Get price of the fishing pole
	/// </summary>
	/// <returns>Number of fishing pole price</returns>
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

