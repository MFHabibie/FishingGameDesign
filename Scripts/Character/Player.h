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
	/// <summary>
	/// Default constructor
	/// </summary>
	Player()
	{
		Gold = 100;
		fishPole = nullptr;
		baitUsed = nullptr;
	}

	/// <summary>
	/// Paying for the fishing pole when buy on shop
	/// </summary>
	/// <param name="newPole">Fishing pole to be paid of</param>
	void PayFishPole(FishingPole* newPole);

	/// <summary>
	/// Paying for the baits when buy on shop
	/// </summary>
	/// <param name="bait">: Type of the bait</param>
	/// <param name="qt">: Quantity of the baits</param>
	void PayBaits(FishingBait* bait, int qt);

	/// <summary>
	/// Start fishing on player
	/// </summary>
	void Fishing();

	/// <summary>
	/// Catch the fish when the given condition met
	/// </summary>
	/// <param name="fish">: Type of fish</param>
	void CatchFish(Fish* fish);

	/// <summary>
	/// Return the sum of the fish price that already catch
	/// </summary>
	/// <returns>Value: Total of catched fish price</returns>
	int GetFishIncome();

	/// <summary>
	/// Get quantity of the bait
	/// </summary>
	/// <param name="bait">: Bait type</param>
	/// <returns>Total of the baits</returns>
	int GetBaitQt(FishingBait* bait) { return FishingBaits[bait]; }

	/// <summary>
	/// Get active bait that used
	/// </summary>
	/// <returns>Null if there is no baits left</returns>
	FishingBait* GetSelectedBait() { return baitUsed; }

	/// <summary>
	/// Get fishing pole object of the player
	/// </summary>
	/// <returns>Object fishing pole</returns>
	FishingPole* GetFishPole() { return fishPole; }

	/// <summary>
	/// Get total of player's gold
	/// </summary>
	/// <returns>Number of the gold</returns>
	int GetGold() { return Gold; }

	/// <summary>
	/// Get total of the catched fish
	/// </summary>
	/// <returns>Number total of catched fish</returns>
	int GetTotalFishCatched() { return static_cast<int>(catchedFishes.size()); }

private:
	/// <summary>
	/// Using gold for paying item
	/// </summary>
	/// <param name="needToPay">: Total money to paid</param>
	void UsingGold(int needToPay);
	
	/// <summary>
	/// Use bait for fishing
	/// </summary>
	/// <param name="bait">: Bait type that used</param>
	/// <returns>True if there is remaining bait</returns>
	bool UseBait(FishingBait* bait);

	int Gold;
	FishingPole* fishPole;
	FishingBait* baitUsed;
	map<FishingBait*, int> FishingBaits;
	list<Fish*> catchedFishes;
};

