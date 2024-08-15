#include "Player.h"
#include "../Object/FishingBait.h"
#include "../Object/Fish.h"

void Player::PayFishPole(FishingPole* newPole)
{
	fishPole = newPole;
	UsingGold(fishPole->GetPrice());
}

void Player::PayBaits(FishingBait* bait, int qt)
{
	FishingBaits[bait] += qt;
	UsingGold(qt * bait->GetPrice());
}

void Player::Fishing()
{
	for (const auto fishingBait : FishingBaits)
	{
		FishingBait* activeBait = fishingBait.first;
		int baitQt = fishingBait.second;

		if (baitQt > 0)
		{
			baitUsed = UseBait(activeBait) ? activeBait : nullptr;
			return;
		}
	}
}

bool Player::UseBait(FishingBait* bait)
{
	if (FishingBaits[bait] > 0)
	{
		FishingBaits[bait]--;
		return true;
	}
	
	return false;
}

void Player::UsingGold(int needToPay)
{
	Gold -= needToPay;
}

void Player::CatchFish(Fish* fish)
{
	catchedFishes.push_back(fish);
}

int Player::GetFishIncome()
{
	int totalIncome;
	for (Fish * fish : catchedFishes)
	{
		totalIncome += fish->GetPrice();
	}
	return totalIncome;
}
