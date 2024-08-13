// FishingDesignGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <list>
#include <random>
#include <thread>
#include <chrono>

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
int totalBaitPurchased = 0;

void FishingPondSituation();
int RandomRange(int min, int max);
std::list<int> RandomWithSum(int sum);

void FishingPoleDialogue();
void FishingSimulation();

int Gold = 100;

int main()
{
    std::cout << "Hello, a good day for fishing!\n";
    std::cout << "Your gold: " << Gold << "\n";

    FishingPondSituation();

    FishingPoleDialogue();

    FishingBaitDialogue();

    FishingSimulation();

    return 0;
}

void FishingPondSituation()
{
    int maxFishOnPond = RandomRange(15, 20);
    int smallFishQt = RandomRange(0, maxFishOnPond);
    int mediumFishQt = RandomRange(0, maxFishOnPond - smallFishQt);
    int bigFishQt = maxFishOnPond - (smallFishQt + mediumFishQt);

    int redFishValue = RandomRange(0, 100);
    int blueFishValue = RandomRange(0, 100 - redFishValue);
    int greenFishValue = 100 - (redFishValue + blueFishValue);
    float redFishPercentage = redFishValue / 100.f;
    float blueFishPercentage = blueFishValue / 100.f;
    float greenFishPercentage = greenFishValue / 100.f;
    
    std::cout << "Today fish: " << smallFishQt << " small fishes, " << mediumFishQt << " medium fishes, " << bigFishQt << " big fishes.\n";
    std::cout << "With percentage: Red fishes " << redFishValue << "%, Blue fishes " << blueFishValue << "%, Green fishes " << greenFishValue << "%\n";
}

int RandomRange(int min, int max)
{
    // Initialize a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);

    return distrib(gen);
}

std::list<int> RandomWithSum(int sum)
{
    std::list<int> numberList;
    for (int i = 0; i < sum; i++)
    {
        numberList.push_back(RandomRange(0, sum));
    }

    return numberList;
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

    baitFishings[static_cast<BaitType>(answerBait - 1)] += answerQt;
    Gold -= answerBait * answerQt;

    switch (answerBait)
    {
    case 1:
        std::cout << "You have buy " << answerQt << " Red bait\n";
        std::cout << "Your gold: " << Gold << "\n";
        break;
    case 2:
        std::cout << "You have buy " << answerQt << " Blue bait\n";
        std::cout << "Your gold: " << Gold << "\n";
        break;
    case 3:
        std::cout << "You have buy " << answerQt << " Green bait\n";
        std::cout << "Your gold: " << Gold << "\n";
        break;
        break;
    default:
        FishingBaitDialogue();
        break;
    }

    totalBaitPurchased += answerQt;
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

void FishingSimulation()
{
    for (int i = 0; i < totalBaitPurchased; i++)
    {
        std::system("CLS");
        std::cout << "Fishing.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Fishing..\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Fishing...\n";
    }
}

