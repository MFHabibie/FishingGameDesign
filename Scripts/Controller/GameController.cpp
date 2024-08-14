#include "GameController.h"
#include <iostream>
#include <thread>
#include <chrono>

#include "../Character/Player.h"
#include "../Object/FishingPond.h"
#include "../Object/Fish.h"


void GameController::Initialize()
{
	Player player;
	SetupPlayer(player);

	FishingPond _pond;
	SetupPond(_pond);
    pond.GeneratePond();
}

void GameController::Fishing()
{
    for (int i = 0; i < localPlayer.FishingBaits.size(); i++)
    {
        localPlayer.UsedBait = static_cast<BaitType>(i);
        for (int j = 0; j < localPlayer.FishingBaits[localPlayer.UsedBait]; j++)
        {
            system("CLS");
            std::cout << "Fishing...\n";

            Fish appearedFish = pond.FishAppear();
            std::string fishColor = appearedFish.Color == 0 ? "Red" : appearedFish.Color == 1 ? "Blue" : "Green";
            std::string fishSize = appearedFish.Size == 0 ? "small" : appearedFish.Size == 1 ? "medium" : "big";

            std::cout << fishColor << " " << fishSize << " fish has appeared\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            if (appearedFish.Color == localPlayer.UsedBait && appearedFish.Size == localPlayer.FishingPoleType)
            {
                localPlayer.CatchFish(appearedFish);
                std::cout << "\nYou have catch " << fishColor << " " << fishSize << " fish\n";

            }
            else
            {
                std::cout << "Failed catching.\n";
            }
        }
    }

    std::cout << "\nYou have catch total " << localPlayer.GetTotalFishCatched() << " fishes\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cin.get();
}

void GameController::SetupPlayer(Player activePlayer)
{
	localPlayer = activePlayer;
}

void GameController::SetupPond(FishingPond _pond)
{
	pond = _pond;
}
