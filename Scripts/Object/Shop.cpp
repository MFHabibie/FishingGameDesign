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
    cout << "Choose your Fishing Pole!\n";
    cout << "1. Small Fishing Pole - 5 Gold\n";
    cout << "2. Medium Fishing Pole - 10 Gold\n";
    cout << "3. Big Fishing Pole - 15 Gold\n";
    cout << "Choose your pole: ";
    cin >> answerNumber;

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
    system("CLS");
    string poleType = player->GetFishPole()->GetType() == 0 ? "Small Pole" : player->GetFishPole()->GetType() == 1 ? "Medium Pole" : "Big Pole";
    cout << "Your Fishing Pole: " << poleType << "\n";
    cout << "Your gold: " << player->GetGold() << "\n";

    cout << "Choose your Fishing baits!\n";
    cout << "1. Red bait - 1 Gold\n";
    cout << "2. Blue bait - 2 Gold\n";
    cout << "3. Green bait - 3 Gold\n";
    cout << "Choose your bait: ";
    cin >> answerBait;
    cout << "How many: ";
    cin >> answerQt;

    if (player->GetGold() < answerBait * answerQt)
    {
        if (player->GetGold() <= 0)
        {
            cout << "You don't have any money.";
        }
        else
        {
            cout << "You don't have enough money.";
            this_thread::sleep_for(chrono::seconds(1));
            FishingBaitDialogue();
        }

        return;
    }

    FishingBait* fishBait = new FishingBait();
    switch (answerBait)
    {
    case 1:
        fishBait = new RedFishingBait();
        cout << "You have buy " << answerQt << " Red bait\n";
        break;
    case 2:
        fishBait = new BlueFishingBait();
        cout << "You have buy " << answerQt << " Blue bait\n";
        break;
    case 3:
        fishBait = new GreenFishingBait();
        cout << "You have buy " << answerQt << " Green bait\n";
        break;
        break;
    default:
        FishingBaitDialogue();
        break;
    }

    player->PayBaits(fishBait, answerQt);
    cout << "Your gold: " << player->GetGold() << "\n";

    char answerBuy = 'n';
    while ((char)tolower(answerBuy) != 'y')
    {
        cout << "Would you like to buy some more (y/n)?";
        cin >> answerBuy;
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