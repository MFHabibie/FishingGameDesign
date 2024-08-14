#include "FishingPond.h"
#include <iostream>

#include "../Object/Fish.h"
#include "../Utility/RandomGenerator.h"

void FishingPond::GeneratePond()
{
    RandomGenerator randomGenerator;

    fishesOnPond = randomGenerator.RandomRange(15, 20);
    int smallFishQt = randomGenerator.RandomRange(0, fishesOnPond);
    int mediumFishQt = randomGenerator.RandomRange(0, fishesOnPond - smallFishQt);
    int bigFishQt = fishesOnPond - (smallFishQt + mediumFishQt);

    int redFishValue = randomGenerator.RandomRange(0, 10);
    int blueFishValue = randomGenerator.RandomRange(0, 10 - redFishValue);
    int greenFishValue = 10 - (redFishValue + blueFishValue);
    float redFishPercentage = redFishValue / 10.f;
    float blueFishPercentage = blueFishValue / 10.f;
    float greenFishPercentage = greenFishValue / 10.f;

    int numberRedFish = round(redFishPercentage * fishesOnPond);
    int numberBlueFish = round(blueFishPercentage * fishesOnPond);
    int numberGreenFish = round(greenFishPercentage * fishesOnPond);

    for (int i = 0; i < fishesOnPond; i++)
    {
        Fish newGeneratedFish;

        //Generate fish color based on sequence by red, blue, green
        if (i < numberRedFish)
        {
            newGeneratedFish.Color = FishColor::RedFish;
        }
        else if (i >= numberRedFish && i < numberRedFish + numberBlueFish)
        {
            newGeneratedFish.Color = FishColor::BlueFish;
        }
        else
        {
            newGeneratedFish.Color = FishColor::GreenFish;
        }

        //Generate fish size based on sequence from small to big
        if (i < smallFishQt)
        {
            newGeneratedFish.Size = FishSize::Small;
        }
        else if (i >= smallFishQt && i < smallFishQt + mediumFishQt)
        {
            newGeneratedFish.Size = FishSize::Medium;
        }
        else
        {
            newGeneratedFish.Size = FishSize::Big;
        }

        Fishes.push_back(newGeneratedFish);
    }

    std::cout << "\nToday fish: " << smallFishQt << " small fishes, " << mediumFishQt << " medium fishes, " << bigFishQt << " big fishes.\n";
    std::cout << "With percentage: Red fishes " << redFishValue * 10 << "%, Blue fishes " << blueFishValue * 10 << "%, Green fishes " << greenFishValue * 10 << "%\n\n";
}

Fish FishingPond::FishAppear()
{
    RandomGenerator randomGenerator;

    fishAppearIdx = randomGenerator.RandomRange(0, Fishes.size() - 1);
    return Fishes[fishAppearIdx];
}

void FishingPond::FishCatched(Fish fish)
{
    Fishes.erase(Fishes.begin() + fishAppearIdx);
}
