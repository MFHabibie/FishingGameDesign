#pragma once
#include <vector>

class Fish;

using namespace std;

class FishingPond
{
public:
	/// <summary>
	/// Default constructor
	/// </summary>
	FishingPond()
	{
		GeneratePond();
	}

	/// <summary>
	/// Generate the fish that appear when fishing
	/// </summary>
	/// <returns>Fish object to be catched</returns>
	Fish* FishAppear();

	/// <summary>
	/// Remove fish from the pond when catched
	/// </summary>
	void FishCatched();

private:
	void GeneratePond();

	int fishesOnPond = 0;
	int fishAppearIdx = 0;
	std::vector<Fish*> Fishes;
};

