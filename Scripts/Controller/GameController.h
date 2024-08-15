#pragma once
#include "../Utility/EnumData.h"

class Shop;
class Player;
class FishingPond;

using namespace std;

class GameController
{
public:
	void Initialize();
	void Fishing();
	bool ConfirmFishing();
	void GameResult();

	Player* GetPlayer() const { return localPlayer; }

private:
	GameState gameState = GameState::Default;
	Shop* shop;
	Player* localPlayer;
	FishingPond* pond;
};

