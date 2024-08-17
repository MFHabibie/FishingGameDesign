#include "FishingPond.h"
#include <iostream>

#include "../Object/Fish.h"
#include "../Utility/RandomGenerator.h"

void FishingPond::GeneratePond()
{
    fishesOnPond = RandomGenerator::RandomRange(15, 20);

    int smallFishQt = 0;
    int mediumFishQt = 0;
    int bigFishQt = 0;
    int redFishValue = 0;
    int blueFishValue = 0;
    int greenFishValue = 0;

    for (int i = 0; i < fishesOnPond; i++)
    {
        Fish* newGeneratedFish;

        int generateFishColor = RandomGenerator::RandomRange(1, 3);
        int generateFishSize = RandomGenerator::RandomRange(0, 2);

        //Generate fish color based on sequence by red, blue, green
        if (generateFishColor == 1)
        {
            newGeneratedFish = new RedFish();
            redFishValue++;
        }
        else if (generateFishColor == 2)
        {
            newGeneratedFish = new BlueFish();
            blueFishValue++;
        }
        else
        {
            newGeneratedFish = new GreenFish();
            greenFishValue++;
        }

        FishSize fishSize = static_cast<FishSize>(generateFishSize);
        newGeneratedFish->GenerateSize(fishSize);
        if (fishSize == FishSize::Small)
        {
            smallFishQt++;
        }
        else if (fishSize == FishSize::Medium)
        {
            mediumFishQt++;
        }
        else if (fishSize == FishSize::Big)
        {
            bigFishQt++;
        }

        Fishes.push_back(newGeneratedFish);
    }

    float redFishPercentage = static_cast<float>(redFishValue) / static_cast<float>(fishesOnPond);
    float blueFishPercentage = static_cast<float>(blueFishValue) / static_cast<float>(fishesOnPond);
    float greenFishPercentage = static_cast<float>(greenFishValue) / static_cast<float>(fishesOnPond);

    cout << "\nToday fish: " << smallFishQt << " small fishes, " << mediumFishQt << " medium fishes, " << bigFishQt << " big fishes.\n";
    cout << "With percentage: Red fishes " << redFishPercentage * 100 << "%, Blue fishes " << blueFishPercentage * 100 << "%, Green fishes " << greenFishPercentage * 100 << "%\n\n";
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
