#include "Shop.h"
#include <iostream>
#include <limits>

#include "../Character/Player.h"
#include "../Object/FishingPole.h"
#include "../Object/FishingBait.h"

void Shop::OpenShop(Player* buyer)
{
    player = buyer;

    FishingPoleDialogue();
    FishingBaitDialogue();
}

void Shop::FishingPoleDialogue()
{
    system("CLS");
    int answerNumber = 0;
    FishingPole* poleToBuy = nullptr;
    cout << "Choose your Fishing Pole!\n";
    cout << "1. Small Fishing Pole - 5 Gold\n";
    cout << "2. Medium Fishing Pole - 10 Gold\n";
    cout << "3. Big Fishing Pole - 15 Gold\n";
    while (answerNumber < 1 || answerNumber > 3)
    {
        cout << "Choose your pole: ";
        cin >> answerNumber;
        if (answerNumber == 1)
        {
            poleToBuy = new SmallFishingPole();
            break;
        }
        else if (answerNumber == 2)
        {
            poleToBuy = new MediumFishingPole();
            break;
        }
        else if (answerNumber == 3)
        {
            poleToBuy = new BigFishingPole();
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        }
    }

    player->PayFishPole(poleToBuy);
}

void Shop::FishingBaitDialogue()
{
    system("CLS");
    string poleType = player->GetFishPole()->GetType() == 0 ? "Small Pole" : player->GetFishPole()->GetType() == 1 ? "Medium Pole" : "Big Pole";
    cout << "Your Fishing Pole: " << poleType << "\n";
    cout << "Your gold: " << player->GetGold() << "\n";

    int answerBait = 0;
    FishingBait* fishBait = nullptr;
    cout << "Choose your Fishing baits!\n";
    cout << "1. Red bait - 1 Gold\n";
    cout << "2. Blue bait - 2 Gold\n";
    cout << "3. Green bait - 3 Gold\n";
    while (answerBait < 1 || answerBait > 3)
    {
        cout << "Choose your bait: ";
        cin >> answerBait;
        if (answerBait == 1)
        {
            fishBait = new RedFishingBait();
            break;
        }
        else if (answerBait == 2)
        {
            fishBait = new BlueFishingBait();
            break;
        }
        else if (answerBait == 3)
        {
            fishBait = new GreenFishingBait();
            break;
        }
    }

    int answerQt = 0;
    while (answerQt < 1)
    {
        cout << "How many: ";
        cin >> answerQt;
        if (player->GetGold() >= answerBait * answerQt)
        {
            switch (answerBait)
            {
            case 1:
                cout << "You have buy " << answerQt << " Red bait\n";
                break;
            case 2:
                cout << "You have buy " << answerQt << " Blue bait\n";
                break;
            case 3:
                cout << "You have buy " << answerQt << " Green bait\n";
                break;
            }

            player->PayBaits(fishBait, answerQt);
            cout << "Your gold: " << player->GetGold() << "\n";
            if (player->GetGold() == 0)
            {
                cout << "You have no money. Shop closed.";
                return;
            }

            break;
        }
        else if (player->GetGold() < answerBait * answerQt)
        {
            if (player->GetGold() <= 0)
            {
                cout << "You don't have any money.";
                break;
            }
            else
            {
                cout << "You don't have enough money.";
            }
        }
        else
        {
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        }
    }

    char answerBuy = 'n';
    while ((char)tolower(answerBuy) != 'y')
    {
        cout << "Would you like to buy some more (y/n)? ";
        cin >> answerBuy;
        if ((char)tolower(answerBuy) == 'y')
        {
            FishingBaitDialogue();
        }
        else if ((char)tolower(answerBuy) == 'n')
        {
            cout << "\n";
            break;
        }
    }
}