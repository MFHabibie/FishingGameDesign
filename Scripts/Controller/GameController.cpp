#include "GameController.h"
#include <iostream>
#include <thread>
#include <chrono>

#include "../Object/Shop.h"
#include "../Character/Player.h"
#include "../Object/FishingPond.h"
#include "../Object/Fish.h"
#include "../Object/FishingBait.h"


void GameController::Initialize()
{
	localPlayer = new Player();
    pond = new FishingPond();

    if (ConfirmFishing())
    {
        shop->OpenShop(localPlayer);
    }
}

void GameController::Fishing()
{
    localPlayer->Fishing();
    FishingBait* bait = localPlayer->GetSelectedBait();
    if (bait)
    {
        std::cout << "Fishing...\n";

        Fish appearedFish = pond->FishAppear();
        std::string fishColor = appearedFish.Color == 0 ? "Red" : appearedFish.Color == 1 ? "Blue" : "Green";
        std::string fishSize = appearedFish.Size == 0 ? "small" : appearedFish.Size == 1 ? "medium" : "big";

        std::cout << fishColor << " " << fishSize << " fish has appeared\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (appearedFish.Color == bait->Type && appearedFish.Size == localPlayer->GetFishPole()->Type)
        {
            localPlayer->CatchFish(appearedFish);
            std::cout << "\nYou have catch " << fishColor << " " << fishSize << " fish\n";

        }
        else
        {
            std::cout << "Failed catching.\n";
        }

        Fishing();
    }
    for (int i = 0; i < localPlayer->FishingBaits.size(); i++)
    {
        localPlayer->UsedBait = static_cast<BaitType>(i);
        for (int j = 0; j < localPlayer->GetBaitQt(localPlayer->UsedBait); j++)
        {
            system("CLS");
            std::cout << "Fishing...\n";

            Fish appearedFish = pond->FishAppear();
            std::string fishColor = appearedFish.Color == 0 ? "Red" : appearedFish.Color == 1 ? "Blue" : "Green";
            std::string fishSize = appearedFish.Size == 0 ? "small" : appearedFish.Size == 1 ? "medium" : "big";

            std::cout << fishColor << " " << fishSize << " fish has appeared\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            if (appearedFish.Color == bait->Type && appearedFish.Size == localPlayer->GetFishPoleType())
            {
                localPlayer->CatchFish(appearedFish);
                std::cout << "\nYou have catch " << fishColor << " " << fishSize << " fish\n";

            }
            else
            {
                std::cout << "Failed catching.\n";
            }
        }
    }

    std::cout << "\nYou have catch total " << localPlayer->GetTotalFishCatched() << " fishes\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cin.get();
}

bool GameController::ConfirmFishing()
{
    std::cout << "\nHello, a good day for fishing!\n";
    std::cout << "Your gold: " << localPlayer->GetGold() << "\n";

    char answer;
    std::cout << "Would you like to go fishing (y/n)? ";
    std::cin >> answer;
    if ((char)tolower(answer) == 'y')
    {
        return true;
    }
    else if ((char)tolower(answer) == 'n')
    {
        gameState = GameState::Tie;
        GameResult();
    }

    return false;
}

void GameController::GameResult()
{
    switch (gameState)
    {
    case Win:
        break;
    case Lose:
        break;
    case Tie:
        std::cout << "Today result is: Tie";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        break;
    default:
        break;
    }
}
