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
        cout << "Fishing...\n";

        Fish* appearedFish = pond->FishAppear();
        string fishColor = appearedFish->GetColor() == 0 ? "Red" : appearedFish->GetColor() == 1 ? "Blue" : "Green";
        string fishSize = appearedFish->GetSize() == 0 ? "small" : appearedFish->GetSize() == 1 ? "medium" : "big";

        cout << fishColor << " " << fishSize << " fish has appeared\n";
        this_thread::sleep_for(chrono::seconds(1));
        if (appearedFish->GetColor() == bait->GetType() && appearedFish->GetSize() == localPlayer->GetFishPole()->GetType())
        {
            appearedFish->GeneratePrice();
            localPlayer->CatchFish(appearedFish);
            pond->FishCatched();
            cout << "\nYou have catch " << fishColor << " " << fishSize << " fish\n";

        }
        else
        {
            cout << "Failed catching.\n";
        }

        Fishing();
    }
    /*for (int i = 0; i < localPlayer->FishingBaits.size(); i++)
    {
        localPlayer->UsedBait = static_cast<BaitType>(i);
        for (int j = 0; j < localPlayer->GetBaitQt(localPlayer->UsedBait); j++)
        {
            system("CLS");
            cout << "Fishing...\n";

            Fish appearedFish = pond->FishAppear();
            string fishColor = appearedFish->Color == 0 ? "Red" : appearedFish->Color == 1 ? "Blue" : "Green";
            string fishSize = appearedFish->Size == 0 ? "small" : appearedFish->Size == 1 ? "medium" : "big";

            cout << fishColor << " " << fishSize << " fish has appeared\n";
            this_thread::sleep_for(chrono::seconds(1));
            if (appearedFish->Color == bait->Type && appearedFish->Size == localPlayer->GetFishPoleType())
            {
                localPlayer->CatchFish(appearedFish);
                cout << "\nYou have catch " << fishColor << " " << fishSize << " fish\n";

            }
            else
            {
                cout << "Failed catching.\n";
            }
        }
    }*/

    cout << "\nYou have catch total " << localPlayer->GetTotalFishCatched() << " fishes\n";
    cout << "Your income from fish: " << localPlayer->GetFishIncome() << "\n";
    if (localPlayer->GetFishIncome() > 100)
    {
        gameState = GameState::Win;
    }
    else
    {
        gameState = GameState::Lose;
    }

    GameResult();

    this_thread::sleep_for(chrono::seconds(1));
    cin.get();
}

bool GameController::ConfirmFishing()
{
    cout << "\nHello, a good day for fishing!\n";
    cout << "Your gold: " << localPlayer->GetGold() << "\n";

    char answer;
    cout << "Would you like to go fishing (y/n)? ";
    cin >> answer;
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
        cout << "Today result is: Win";
        break;
    case Lose:
        cout << "Today result is: Lose";
        break;
    case Tie:
        cout << "Today result is: Tie";
        break;
    default:
        break;
    }

    this_thread::sleep_for(chrono::seconds(2));
}
