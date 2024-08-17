#pragma once
#include "../Utility/EnumData.h"

class Shop;
class Player;
class FishingPond;

using namespace std;

class GameController
{
public:
	/// <summary>
	/// Start the game
	/// </summary>
	void Start();

	/// <summary>
	/// Display the game result based on condition
	/// </summary>
	void GameResult();

	/// <summary>
	/// Get player object
	/// </summary>
	/// <returns>Player: Active player that available</returns>
	Player* GetPlayer() const { return localPlayer; }

private:
	/// <summary>
	/// Input for confirmation to start fishing
	/// </summary>
	/// <returns>True: Start fishing; False: Skip the day</returns>
	bool ConfirmFishing();

	/// <summary>
	/// Simulate fishing based on bait that player have
	/// </summary>
	void Fishing();

	/// <summary>
	/// 
	/// </summary>
	/// <returns>True: Start game again; False: Game stopped</returns>
	bool RestartConfirmation();

	GameState gameState = GameState::Default;
	Shop* shop;
	Player* localPlayer;
	FishingPond* pond;
};

