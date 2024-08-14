#include "Player.h"
#include "../Object/Fish.h"

void Player::UsingGold(int needToPay)
{
	Gold -= needToPay;
}

void Player::CatchFish(Fish fish)
{
	catchedFishes.push_back(fish);
}
