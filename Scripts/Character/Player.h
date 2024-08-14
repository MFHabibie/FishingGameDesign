#pragma once
#include <map>
#include <list>

#include "../Utility/EnumData.h"

class Fish;

class Player
{
public:
	FishingPoleType FishingPoleType;
	std::map<BaitType, int> FishingBaits;
	BaitType UsedBait;

	void UsingGold(int needToPay);
	void CatchFish(Fish fish);

	int GetGold() { return Gold; }
	int GetTotalFishCatched() { return catchedFishes.size(); }

private:
	int Gold = 100;
	std::list<Fish> catchedFishes;
};

