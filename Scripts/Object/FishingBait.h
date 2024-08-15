#pragma once
#include "../Utility/EnumData.h"

class FishingBait
{
public:
	BaitType GetType() const { return Type; }
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

