#pragma once
#include "../Utility/EnumData.h"

class Player;

class Shop
{
public:
	void OpenShop(Player* buyer);

private:
	void FishingPoleDialogue();
	void FishingBaitDialogue();

	Player* player;
};

