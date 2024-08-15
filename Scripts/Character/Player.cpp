#include "Player.h"
#include "../Object/FishingBait.h"
#include "../Object/Fish.h"

void Player::PayFishPole(FishingPole* newPole)
{
	fishPole = newPole;
	UsingGold(fishPole->Price);
}

void Player::PayBaits(FishingBait* bait, int qt)
{
	FishingBaits[bait] += qt;
	UsingGold(qt * bait->Price);
}

void Player::Fishing()
{
	FishingBait* baitAvailable = std::find_if(FishingBaits.begin(), FishingBaits.end(), );
	baitUsed = UseBait(baitAvailable) ? baitAvailable : nullptr;
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

void Player::CatchFish(Fish fish)
{
	catchedFishes.push_back(fish);
}
