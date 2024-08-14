#pragma once
#include <vector>

class Fish;

class FishingPond
{
public:

	void GeneratePond();
	Fish FishAppear();
	void FishCatched(Fish fish);

	int GetTotalFish() { return fishesOnPond; }

private:
	int fishesOnPond;
	int fishAppearIdx;
	std::vector<Fish> Fishes;
};

