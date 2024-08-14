// FishingDesignGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>

//local script
#include "Scripts/Utility/EnumData.h"
#include "Scripts/Utility/RandomGenerator.h"
#include "Scripts/Controller/GameController.h"
#include "Scripts/Object/FishingPond.h"
#include "Scripts/Character/Player.h"
#include "Scripts/Object/Fish.h"


void FishingPoleDialogue();
void FishingBaitDialogue();
bool ConfirmFishing();

GameController gameController;
GameState gameState;
Player player;

int main()
{
    player = gameController.GetPlayer();

    if (ConfirmFishing())
    {
        gameController.Initialize();

        FishingPoleDialogue();

        FishingBaitDialogue();

        gameController.Fishing();
    }

    return 0;
}

bool ConfirmFishing()
{
    system("CLS");
    std::cout << "Hello, a good day for fishing!\n";
    std::cout << "Your gold: " << player.GetGold() << "\n";

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
        std::cout << "Today result is: Tie";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        ConfirmFishing();
    }
    
    return false;
}

void FishingPoleDialogue()
{
    int answerNumber = 0;
    std::cout << "Choose your Fishing Pole!\n";
    std::cout << "1. Small Fishing Pole - 5 Gold\n";
    std::cout << "2. Medium Fishing Pole - 10 Gold\n";
    std::cout << "3. Big Fishing Pole - 15 Gold\n";
    std::cout << "Choose your pole: ";
    std::cin >> answerNumber;

    player.FishingPoleType = static_cast<FishingPoleType>(answerNumber - 1);

    switch (answerNumber)
    {
    case 1:
        player.UsingGold(5);
        break;
    case 2:
        player.UsingGold(10);
        break;
    case 3:
        player.UsingGold(15);
        break;
    default:
        FishingPoleDialogue();
        break;
    }
}

void FishingBaitDialogue()
{
    int answerBait = 0;
    int answerQt = 0;
    std::system("CLS");
    std::string poleType = player.FishingPoleType == 0 ? "Small Pole" : player.FishingPoleType == 1 ? "Medium Pole" : "Big Pole";
    std::cout << "Your Fishing Pole: " << poleType << "\n";
    std::cout << "Your gold: " << player.GetGold() << "\n";

    std::cout << "Choose your Fishing baits!\n";
    std::cout << "1. Red bait - 1 Gold\n";
    std::cout << "2. Blue bait - 2 Gold\n";
    std::cout << "3. Green bait - 3 Gold\n";
    std::cout << "Choose your bait: ";
    std::cin >> answerBait;
    std::cout << "How many: ";
    std::cin >> answerQt;

    if (player.GetGold() < answerBait * answerQt)
    {
        if (player.GetGold() <= 0)
        {
            std::cout << "You don't have any money.";
        }
        else
        {
            std::cout << "You don't have enough money.";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            FishingBaitDialogue();
        }

        return;
    }

    player.FishingBaits[static_cast<BaitType>(answerBait - 1)] += answerQt;
    player.UsingGold(answerBait * answerQt);

    switch (answerBait)
    {
    case 1:
        std::cout << "You have buy " << answerQt << " Red bait\n";
        break;
    case 2:
        std::cout << "You have buy " << answerQt << " Blue bait\n";
        break;
    case 3:
        std::cout << "You have buy " << answerQt << " Green bait\n";
        break;
        break;
    default:
        FishingBaitDialogue();
        break;
    }

    std::cout << "Your gold: " << player.GetGold() << "\n";

    char answerBuy = 'n';
    while ((char)tolower(answerBuy) != 'y')
    {
        std::cout << "Would you like to buy some more (y/n)?";
        std::cin >> answerBuy;
        if ((char)tolower(answerBuy) == 'y')
        {
            FishingBaitDialogue();
        }
        else if ((char)tolower(answerBuy) == 'n')
        {
            break;
        }
    }
}
