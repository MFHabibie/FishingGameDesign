#pragma once
#include <map>
#include <list>

#include "../Utility/EnumData.h"
#include "../Object/FishingPole.h"

class FishingPole;
class FishingBait;
class Fish;

class Player
{
public:
	void PayFishPole(FishingPole* newPole);
	void PayBaits(FishingBait* bait, int qt);
	void Fishing();
	void CatchFish(Fish fish);

	FishingBait* GetSelectedBait() { return baitUsed; }
	FishingPole* GetFishPole() { return fishPole; }
	int GetGold() { return Gold; }
	int GetTotalFishCatched() { return catchedFishes.size(); }

private:
	void UsingGold(int needToPay);
	bool UseBait(FishingBait* bait);

	int Gold = 100;
	FishingPole* fishPole;
	FishingBait* baitUsed;
	std::map<FishingBait*, int> FishingBaits;
	std::list<Fish> catchedFishes;
};

