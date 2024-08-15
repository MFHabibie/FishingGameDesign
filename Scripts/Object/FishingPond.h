#pragma once
#include <vector>

class Fish;

class FishingPond
{
public:
	FishingPond()
	{
		GeneratePond();
	}

	Fish FishAppear();
	void FishCatched(Fish fish);

	int GetTotalFish() { return fishesOnPond; }

private:
	void GeneratePond();

	int fishesOnPond;
	int fishAppearIdx;
	std::vector<Fish> Fishes;
};

