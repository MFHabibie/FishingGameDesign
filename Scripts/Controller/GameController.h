#pragma once
#include "../Utility/EnumData.h"

class Shop;
class Player;
class FishingPond;

using namespace std;

class GameController
{
public:
	void Start();
	void GameResult();

	Player* GetPlayer() const { return localPlayer; }

private:
	bool ConfirmFishing();
	void Fishing();
	bool RestartConfirmation();

	GameState gameState = GameState::Default;
	Shop* shop;
	Player* localPlayer;
	FishingPond* pond;
};

