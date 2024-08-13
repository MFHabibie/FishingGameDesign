// FishingDesignGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>

enum FishingType
{
    SmallPole,
    MediumPole,
    BigPole
};

enum BaitType
{
    Red,
    Blue,
    Green
};

enum FishColor
{
    RedFish,
    BlueFish,
    GreenFish
};

enum FishSize
{
    Small,
    Medium,
    Big
};

FishingType fishingPoleType;
std::map<BaitType, int> baitFishings;

void FishingPoleDialogue();

int Gold = 100;

int main()
{
    std::cout << "Hello, a good day for fishing!\n";
    std::cout << "Your gold: " << Gold << "\n";

    FishingPoleDialogue();

    return 0;
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

    if (answerNumber <= 3)
    {
        fishingPoleType = static_cast<FishingType>(answerNumber);
    }

    switch (answerNumber)
    {
    case 1:
        Gold -= 5;
        std::cout << "You have choose Small Fishing Pole\n";
        break;
    case 2:
        Gold -= 10;
        std::cout << "You have choose Medium Fishing Pole\n";
        break;
    case 3:
        Gold -= 15;
        std::cout << "You have choose Big Fishing Pole\n";
        break;
    default:
        FishingPoleDialogue();
        break;
    }

    std::cout << "Your gold: " << Gold << "\n";
}

void FishingBaitDialogue()
{
    int answerBait = 0;
    int answerQt = 0;
    std::cout << "Choose your Fishing Pole!\n";
    std::cout << "1. Red bait - 1 Gold\n";
    std::cout << "2. Blue bait - 2 Gold\n";
    std::cout << "3. Green bait - 3 Gold\n";
    std::cout << "Choose your bait: ";
    std::cin >> answerBait;
    std::cout << "How many: ";
    std::cin >> answerQt;

    if (Gold < answerBait * answerQt)
    {
        if (Gold <= 0)
        {
            std::cout << "You don't have any money.";
        }
        else
        {
            std::cout << "You don't have enough money.";
        }

        return;
    }

    switch (answerBait)
    {
    case 1:
        baitFishings[static_cast<BaitType>(answerBait - 1)] += answerQt;
        Gold -= answerBait * answerQt;
        std::cout << "You have buy " << answerQt << " Red bait\n";
        std::cout << "Your gold: " << Gold << "\n";
        break;
    case 2:
        baitFishings[static_cast<BaitType>(answerBait - 1)] += answerQt;
        Gold -= answerBait * answerQt;
        std::cout << "You have buy " << answerQt << " Blue bait\n";
        std::cout << "Your gold: " << Gold << "\n";
        break;
    case 3:
        baitFishings[static_cast<BaitType>(answerBait - 1)] += answerQt;
        Gold -= answerBait * answerQt;
        std::cout << "You have buy " << answerQt << " Green bait\n";
        std::cout << "Your gold: " << Gold << "\n";
        break;
        break;
    default:
        FishingBaitDialogue();
        break;
    }

    int answerBuy = 0;
    while (answerBuy != 1)
    {
        std::cout << "Would you like to buy some more?";
        std::cin >> answerBuy;
        if (answerBuy == 1)
        {
            FishingBaitDialogue();
        }
        else
        {
            break;
        }
    }
}

