// FishingDesignGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//local script
#include "Scripts/Utility/EnumData.h"
#include "Scripts/Controller/GameController.h"


GameController* gameController;

int main()
{
    gameController = new GameController();

    gameController->Start();

    return 0;
}
