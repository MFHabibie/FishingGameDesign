#include "GameController.h"
#include <iostream>
#include <thread>
#include <chrono>

#include "../Object/Shop.h"
#include "../Character/Player.h"
#include "../Object/FishingPond.h"
#include "../Object/Fish.h"
#include "../Object/FishingBait.h"


void GameController::Start()
{
    system("CLS");

	localPlayer = new Player();
    pond = new FishingPond();
    shop = new Shop();

    if (ConfirmFishing())
    {
        shop->OpenShop(localPlayer);
            
        Fishing();
    }
}

void GameController::Fishing()
{
    FishingBait* bait = nullptr;
    while (bait == nullptr)
    {
        localPlayer->Fishing();
        bait = localPlayer->GetSelectedBait();
        if (bait == nullptr)
        {
            break;
        }

        system("CLS");
        string baitColor = bait->GetType() == 0 ? "Red" : bait->GetType() == 1 ? "Blue" : "Green";
        cout << "Use " << baitColor << " bait: " << localPlayer->GetBaitQt(bait) + 1 << "\n";
        cout << "Fishing...\n";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(500));

        Fish* appearedFish = pond->FishAppear();
        string fishColor = appearedFish->GetColor() == 0 ? "Red" : appearedFish->GetColor() == 1 ? "Blue" : "Green";
        string fishSize = appearedFish->GetSize() == 0 ? "small" : appearedFish->GetSize() == 1 ? "medium" : "big";
        cout << fishColor << " " << fishSize << " fish has appeared\n";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(500));

        if (appearedFish->GetColor() == bait->GetType() && appearedFish->GetSize() == localPlayer->GetFishPole()->GetType())
        {
            appearedFish->GeneratePrice();
            localPlayer->CatchFish(appearedFish);
            pond->FishCatched();
            cout << "You have catch " << fishColor << " " << fishSize << " fish\n\n";
        }
        else
        {
            cout << "Failed catching\n\n";
        }

        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(500));
        bait = nullptr;
    }

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
}

bool GameController::ConfirmFishing()
{
    cout << "\nHello, a good day for fishing!\n";
    cout << "Your gold: " << localPlayer->GetGold() << "\n";

    char answer = 'n';
    while (answer != 'y')
    {
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
            break;
        }
    }
    
    return false;
}

void GameController::GameResult()
{
    switch (gameState)
    {
    case Win:
        cout << "Today result is: Win\n";
        break;
    case Lose:
        cout << "Today result is: Lose\n";
        break;
    case Tie:
        cout << "Today result is: Tie\n";
        break;
    default:
        break;
    }

    if (RestartConfirmation())
    {
        Start();
    }
}

bool GameController::RestartConfirmation()
{
    char answer = 'n';
    while (answer != 'y')
    {
        cout << "\nWould you like to go for another day (y/n)? ";
        cin >> answer;
        if ((char)tolower(answer) == 'y')
        {
            return true;
        }
        else if ((char)tolower(answer) == 'n')
        {
            break;
        }
    }

    return false;
}
