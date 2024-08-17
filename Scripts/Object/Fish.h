#pragma once
#include "../Utility/EnumData.h"

class Fish
{
public:
	/// <summary>
	/// Generate the size of the  fish
	/// </summary>
	/// <param name="size">: Size of the fish based on FishSize enum</param>
	virtual void GenerateSize(FishSize size);

	/// <summary>
	/// Get color of the fish
	/// </summary>
	/// <returns>Color of the fish based on FishColor enum</returns>
	FishColor GetColor() const { return Color; }

	/// <summary>
	/// Get size of the fish
	/// </summary>
	/// <returns>Size of the fish based on FishSize enum</returns>
	FishSize GetSize() const { return Size; }

	/// <summary>
	/// Get price of the fish
	/// </summary>
	/// <returns>Number of fish price</returns>
	int GetPrice() const { return price; }

	/// <summary>
	/// Generate the price based on minimum price and maximum price
	/// </summary>
	/// <returns>Number of generated price</returns>
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