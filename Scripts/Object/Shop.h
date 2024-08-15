#pragma once
#include "../Utility/EnumData.h"

class Player;

using namespace std;

class Shop
{
public:
	void OpenShop(Player* buyer);

private:
	void FishingPoleDialogue();
	void FishingBaitDialogue();

	Player* player;
};

