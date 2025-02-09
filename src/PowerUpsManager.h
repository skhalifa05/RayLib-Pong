//
// Created by Seif Khalifa on 08/02/2025.
//

#ifndef POWERUPMANAGER_H
#define POWERUPMANAGER_H

#include <vector>
#include <memory>  // Smart pointers
#include <cstdlib> // Random
#include <ctime>   // Random seeding

#include "PowerUps/PowerUp.h"
#include "PowerUps/LargerPaddle.h"
#include "PowerUps/ExtraLife.h"
#include "Paddle.h"
#include "Ball.h"
#include "LivesManager.h"

class PowerUpManager {
private:
    std::vector<std::unique_ptr<PowerUp>> activePowerUps;
    Paddle* paddle;
    Ball* ball;
    LivesManager* livesManager;

public:
    PowerUpManager(Paddle* paddle, Ball* ball, LivesManager* livesManager);

    void spawnPowerUp();
    void executePowerUp(int index);
    void drawPowerUps();  // To display them on the screen
    void reset();
    std::vector<std::unique_ptr<PowerUp>>& getActivePowerUps();
};

#endif // POWERUPMANAGER_H