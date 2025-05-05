//
// Created by Seif Khalifa on 08/02/2025.
//

#include "PowerUpsManager.h"
#include <raylib.h>

PowerUpManager::PowerUpManager(Paddle* paddle, Ball* ball, LivesManager* livesManager)
    : paddle(paddle), ball(ball), livesManager(livesManager) {
    srand(static_cast<unsigned>(time(0)));  // Seed randomness
}

void PowerUpManager::spawnPowerUp(float startX, float startY) {
    int type = rand() % 3;
    std::unique_ptr<PowerUp> powerUp;

    switch (type) {
        case 0: powerUp = std::make_unique<LargerPaddle>(startX, startY, paddle); break;
        case 1: powerUp = std::make_unique<ExtraLife>(startX, startY, livesManager); break;
        case 2: powerUp = std::make_unique<SmallPaddle>(startX, startY, paddle); break;
    }

    activePowerUps.push_back(std::move(powerUp));
}

void PowerUpManager::executePowerUp(int index) {
    if (index >= 0 && index < activePowerUps.size()) {
        activePowerUps[index]->execute();
        activePowerUps.erase(activePowerUps.begin() + index);
    }
}

void PowerUpManager::drawPowerUps() {
    for (int i = 0; i < activePowerUps.size();) {
        auto& powerUp = activePowerUps[i];
        auto [x, y] = powerUp->getLocation();

        y += 2.0f; // Fall speed
        powerUp->setLocation(x, y);

        DrawCircle(x, y, 10, GREEN);

        if (y > GetScreenHeight()) {
            activePowerUps.erase(activePowerUps.begin() + i);
        } else {
            ++i;
        }
    }
}

std::vector<std::unique_ptr<PowerUp>>& PowerUpManager::getActivePowerUps() {
    return activePowerUps;
}

void PowerUpManager::reset() {
    activePowerUps.clear();
}

void PowerUpManager::spawnAndExecuteRandomPowerUp() {
    float x = rand() % GetScreenWidth();
    float y = 400;

    int type = rand() % 3;
    std::unique_ptr<PowerUp> powerUp;

    switch (type) {
        case 0: powerUp = std::make_unique<LargerPaddle>(x, y, paddle); break;
        case 1: powerUp = std::make_unique<ExtraLife>(x, y, livesManager); break;
        case 2: powerUp = std::make_unique<SmallPaddle>(x, y, paddle); break;
    }

    if (powerUp) {
        powerUp->execute();
    }
}
