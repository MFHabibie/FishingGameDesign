#include "FishingPond.h"
#include <iostream>

#include "../Object/Fish.h"
#include "../Utility/RandomGenerator.h"

void FishingPond::GeneratePond()
{

    fishesOnPond = RandomGenerator::RandomRange(15, 20);
    int smallFishQt = RandomGenerator::RandomRange(0, fishesOnPond);
    int mediumFishQt = RandomGenerator::RandomRange(0, fishesOnPond - smallFishQt);
    int bigFishQt = fishesOnPond - (smallFishQt + mediumFishQt);

    int redFishValue = RandomGenerator::RandomRange(0, 10);
    int blueFishValue = RandomGenerator::RandomRange(0, 10 - redFishValue);
    int greenFishValue = 10 - (redFishValue + blueFishValue);
    float redFishPercentage = redFishValue / 10.f;
    float blueFishPercentage = blueFishValue / 10.f;
    float greenFishPercentage = greenFishValue / 10.f;

    int numberRedFish = static_cast<int>(round(redFishPercentage * fishesOnPond));
    int numberBlueFish = static_cast<int>(round(blueFishPercentage * fishesOnPond));
    int numberGreenFish = static_cast<int>(round(greenFishPercentage * fishesOnPond));

    for (int i = 0; i < fishesOnPond; i++)
    {
        Fish* newGeneratedFish;

        //Generate fish color based on sequence by red, blue, green
        if (i < numberRedFish)
        {
            newGeneratedFish = new RedFish();
        }
        else if (i >= numberRedFish && i < numberRedFish + numberBlueFish)
        {
            newGeneratedFish = new BlueFish();
        }
        else
        {
            newGeneratedFish = new GreenFish();
        }

        //Generate fish size based on sequence from small to big
        if (i < smallFishQt)
        {
            newGeneratedFish->GenerateSize(FishSize::Small);
        }
        else if (i >= smallFishQt && i < smallFishQt + mediumFishQt)
        {
            newGeneratedFish->GenerateSize(FishSize::Medium);
        }
        else
        {
            newGeneratedFish->GenerateSize(FishSize::Big);
        }

        Fishes.push_back(newGeneratedFish);
    }

    cout << "\nToday fish: " << smallFishQt << " small fishes, " << mediumFishQt << " medium fishes, " << bigFishQt << " big fishes.\n";
    cout << "With percentage: Red fishes " << redFishValue * 10 << "%, Blue fishes " << blueFishValue * 10 << "%, Green fishes " << greenFishValue * 10 << "%\n\n";
}

Fish* FishingPond::FishAppear()
{
    fishAppearIdx = RandomGenerator::RandomRange(0, static_cast<int>(Fishes.size()) - 1);
    return Fishes[fishAppearIdx];
}

void FishingPond::FishCatched()
{
    Fishes.erase(Fishes.begin() + fishAppearIdx);
}
