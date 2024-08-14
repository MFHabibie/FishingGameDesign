#pragma once


class Player;
class FishingPond;

class GameController : public IGameController
{
public:
	void Initialize();
	void Fishing();

	Player GetPlayer() { return localPlayer; }

private:
	void SetupPlayer(Player activePlayer);
	void SetupPond(FishingPond _pond);

	Player localPlayer;
	FishingPond pond;
};

__interface IGameController
{
	void Fishing();
};

