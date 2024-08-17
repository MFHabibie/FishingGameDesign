#pragma once
#include "../Utility/EnumData.h"

class Player;

using namespace std;

class Shop
{
public:
	/// <summary>
	/// Open the shop to run buy system
	/// </summary>
	/// <param name="buyer">: Player that access the shop</param>
	void OpenShop(Player* buyer);

private:
	/// <summary>
	/// Start Dialogue for choosing fishing pole
	/// </summary>
	void FishingPoleDialogue();

	/// <summary>
	/// Start Dialogue for choosing fishing baits
	/// </summary>
	void FishingBaitDialogue();

	Player* player = nullptr;
};

