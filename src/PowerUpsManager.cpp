//
// Created by Seif Khalifa on 08/02/2025.
//

#include "PowerUpsManager.h"
#include <raylib.h>

PowerUpManager::PowerUpManager(Paddle* paddle, Ball* ball, LivesManager* livesManager)
    : paddle(paddle), ball(ball), livesManager(livesManager) {
    srand(static_cast<unsigned>(time(0)));  // Seed randomness
}

void PowerUpManager::spawnPowerUp() {
    float x = rand() % GetScreenWidth();
    float y = 400;

    int type = rand() % 2;
    std::unique_ptr<PowerUp> powerUp;

    switch (type) {
        case 0: powerUp = std::make_unique<LargerPaddle>(x, y, paddle); break;
        case 1: powerUp = std::make_unique<ExtraLife>(x, y, livesManager); break;
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
    for (const auto& powerUp : activePowerUps) {
        auto [x, y] = powerUp->getLocation();
        DrawCircle(x, y, 10, GREEN);  // Power-ups appear as green circles
    }
}

std::vector<std::unique_ptr<PowerUp>>& PowerUpManager::getActivePowerUps() {
    return activePowerUps;
}