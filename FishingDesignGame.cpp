// FishingDesignGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>

//local script
#include "Scripts/Utility/EnumData.h"
#include "Scripts/Controller/GameController.h"


GameController* gameController;

int main()
{
    gameController = new GameController();
    gameController->Initialize();

    if (!gameController->ConfirmFishing())
    {
        gameController->GameResult();
    }

    return 0;
}
