#include "Shop.h"
#include <iostream>
#include <thread>
#include <chrono>

#include "../Character/Player.h"
#include "../Object/FishingPole.h"
#include "../Object/FishingBait.h"

void Shop::OpenShop(Player* buyer)
{
    player = buyer;
}

void Shop::FishingPoleDialogue()
{
    int answerNumber = 0;
    std::cout << "Choose your Fishing Pole!\n";
    std::cout << "1. Small Fishing Pole - 5 Gold\n";
    std::cout << "2. Medium Fishing Pole - 10 Gold\n";
    std::cout << "3. Big Fishing Pole - 15 Gold\n";
    std::cout << "Choose your pole: ";
    std::cin >> answerNumber;

    FishingPole* poleToBuy;
    switch (answerNumber)
    {
    case 1:
        poleToBuy = new SmallFishingPole();
        break;
    case 2:
        poleToBuy = new MediumFishingPole();
        break;
    case 3:
        poleToBuy = new BigFishingPole();
        break;
    default:
        FishingPoleDialogue();
        break;
    }

    player->PayFishPole(poleToBuy);
}

void Shop::FishingBaitDialogue()
{
    int answerBait = 0;
    int answerQt = 0;
    std::system("CLS");
    std::string poleType = player->GetFishPoleType() == 0 ? "Small Pole" : player->GetFishPoleType() == 1 ? "Medium Pole" : "Big Pole";
    std::cout << "Your Fishing Pole: " << poleType << "\n";
    std::cout << "Your gold: " << player->GetGold() << "\n";

    std::cout << "Choose your Fishing baits!\n";
    std::cout << "1. Red bait - 1 Gold\n";
    std::cout << "2. Blue bait - 2 Gold\n";
    std::cout << "3. Green bait - 3 Gold\n";
    std::cout << "Choose your bait: ";
    std::cin >> answerBait;
    std::cout << "How many: ";
    std::cin >> answerQt;

    if (player->GetGold() < answerBait * answerQt)
    {
        if (player->GetGold() <= 0)
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

    FishingBait* fishBait;
    switch (answerBait)
    {
    case 1:
        fishBait = new RedBait();
        std::cout << "You have buy " << answerQt << " Red bait\n";
        break;
    case 2:
        fishBait = new BlueBait();
        std::cout << "You have buy " << answerQt << " Blue bait\n";
        break;
    case 3:
        fishBait = new GreenBait();
        std::cout << "You have buy " << answerQt << " Green bait\n";
        break;
        break;
    default:
        FishingBaitDialogue();
        break;
    }

    player->PayBaits(fishBait, answerQt);
    std::cout << "Your gold: " << player->GetGold() << "\n";

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