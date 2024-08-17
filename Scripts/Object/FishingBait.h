#pragma once
#include "../Utility/EnumData.h"

class FishingBait
{
public:
	/// <summary>
	/// Get the type of the bait
	/// </summary>
	/// <returns>Type of bait based on BaitType enum</returns>
	BaitType GetType() const { return Type; }

	/// <summary>
	/// Get the price of the bait
	/// </summary>
	/// <returns>Number of bait price</returns>
	int GetPrice() const { return Price; }

protected:
	BaitType Type = BaitType::RedBait;
	int Price = 0;
};

class RedFishingBait : public FishingBait
{
public:
	RedFishingBait()
	{
		Type = BaitType::RedBait;
		Price = 1;
	}
};

class BlueFishingBait : public FishingBait
{
public:
	BlueFishingBait()
	{
		Type = BaitType::BlueBait;
		Price = 2;
	}
};

class GreenFishingBait : public FishingBait
{
public:
	GreenFishingBait()
	{
		Type = BaitType::GreenBait;
		Price = 3;
	}
};

