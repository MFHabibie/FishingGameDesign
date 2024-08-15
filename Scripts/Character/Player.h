#pragma once
#include <map>
#include <list>

#include "../Utility/EnumData.h"
#include "../Object/FishingPole.h"

class FishingPole;
class FishingBait;
class Fish;

using namespace std;

class Player
{
public:
	Player()
	{
		Gold = 100;
	}

	void PayFishPole(FishingPole* newPole);
	void PayBaits(FishingBait* bait, int qt);
	void Fishing();
	void CatchFish(Fish* fish);

	int GetFishIncome();
	FishingBait* GetSelectedBait() { return baitUsed; }
	FishingPole* GetFishPole() { return fishPole; }
	int GetGold() { return Gold; }
	int GetTotalFishCatched() { return static_cast<int>(catchedFishes.size()); }

private:
	void UsingGold(int needToPay);
	bool UseBait(FishingBait* bait);

	int Gold;
	FishingPole* fishPole;
	FishingBait* baitUsed;
	map<FishingBait*, int> FishingBaits;
	list<Fish*> catchedFishes;
};

