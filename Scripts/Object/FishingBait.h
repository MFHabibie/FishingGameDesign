#pragma once
#include "../Utility/EnumData.h"

class FishingBait
{
public:
	BaitType Type;
	int Price;
};

class RedBait : public FishingBait
{
public:
	RedBait()
	{
		Type = Red;
		Price = 1;
	}
};

class BlueBait : public FishingBait
{
public:
	BlueBait()
	{
		Type = Blue;
		Price = 2;
	}
};

class GreenBait : public FishingBait
{
public:
	GreenBait()
	{
		Type = Green;
		Price = 3;
	}
};

