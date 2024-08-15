#pragma once
#include <vector>

class Fish;

using namespace std;

class FishingPond
{
public:
	FishingPond()
	{
		GeneratePond();
	}

	Fish* FishAppear();
	void FishCatched();

	int GetTotalFish() const { return fishesOnPond; }

private:
	void GeneratePond();

	int fishesOnPond = 0;
	int fishAppearIdx = 0;
	std::vector<Fish*> Fishes;
};

