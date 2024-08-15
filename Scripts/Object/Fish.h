#pragma once
#include "../Utility/EnumData.h"

class Fish
{
public:
	virtual void GenerateSize(FishSize size) = 0;

	FishColor GetColor() const { return Color; }
	FishSize GetSize() const { return Size; }
	int GetPrice() const { return price; }
	int GeneratePrice();

protected:
	FishColor Color = FishColor::Red;
	FishSize Size = FishSize::Small;
	int minPrice = 0;
	int maxPrice = 0;
	int price = 0;
};

class RedFish : public Fish
{
public:
	RedFish()
	{
		Color = FishColor::Red;
	}

	void GenerateSize(FishSize size) override;
};

class BlueFish : public Fish
{
public:
	BlueFish()
	{
		Color = FishColor::Blue;
	}

	void GenerateSize(FishSize size) override;
};

class GreenFish : public Fish
{
public:
	GreenFish()
	{
		Color = FishColor::Green;
	}

	void GenerateSize(FishSize size) override;
};