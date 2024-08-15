#pragma once
#include "../Utility/EnumData.h"

class Shop;
class Player;
class FishingPond;

class GameController : public IGameController
{
public:
	void Initialize();
	void Fishing();
	bool ConfirmFishing();
	void GameResult();

	Player* GetPlayer() { return localPlayer; }

private:
	GameState gameState;
	Shop* shop;
	Player* localPlayer;
	FishingPond* pond;
};

__interface IGameController
{
	virtual void Fishing() = 0;
};

