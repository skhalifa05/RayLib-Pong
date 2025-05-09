//
// Created by Seif Khalifa on 27/04/2025.
//

#include "BrickManager.h"
#include "Bricks/StandardBrick.h"
#include "Bricks/DurableBrick.h"
#include "Bricks/IndestructibleBrick.h"
#include "Bricks/SpecialBrick.h"
#include "Bricks/PowerUpBrick.h"
#include <raylib.h>

struct FloatingText {
    std::string text;
    float x, y;
    float timer; // how long it stays on screen
};
std::vector<FloatingText> floatingTexts;

BrickManager::BrickManager(PowerUpManager* powerupsystem, Ball* ball) : powerupsystem(powerupsystem), ball(ball) {}

BrickManager::~BrickManager() {
    for (auto& brick : bricks) {
        delete brick;
    }
}

void BrickManager::initBricks() {
    bricks.clear();
    comboTimer = 0.0f;
    comboCount = 0;
    levelTimer = 0.0f;
    //Simple grid of bricks
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            float x = 50 + (j * 90);
            float y = 50 + (i * 30) ;
            if (i == 0)
                bricks.push_back(new IndestructibleBrick(x, y, 80, 20));
            else if (i == 1)
                bricks.push_back(new DurableBrick(x, y, 80, 20));
            else if (i == 2)
                bricks.push_back(new SpecialBrick(x, y, 80, 20));
            else if (i == 3)
                bricks.push_back(new PowerUpBrick(x, y, 80, 20));
            else
                bricks.push_back(new StandardBrick(x, y, 80, 20));
        }
    }
}

void BrickManager::updateBricks(Ball& ball, int& score, float ballRadius, int& level) {
    levelTimer += GetFrameTime();

    if (comboTimer > 0.0f) {
        comboTimer -= GetFrameTime();
        if (comboTimer <= 0.0f) {
            comboCount = 0; // combo expired
        }
    }

    for (auto& brick : bricks) {
        if (!brick->isDestroyed() &&
            CheckCollisionCircleRec({ball.getLocation().first, ball.getLocation().second}, ballRadius, brick->getRect())) {

            bool destroyed = brick->onCollision();

            if (destroyed) {
                comboCount++;
                comboTimer = COMBO_RESET_TIME;

//                int comboMultiplier = (comboCount > 0) ? comboCount : 1;

                if (dynamic_cast<PowerUpBrick*>(brick)) {
                    score += 2;
                    floatingTexts.push_back({"+2", brick->GetX(), brick->GetY(), 1.0f});
                    spawnPowerup(brick->GetX(), brick->GetY());
                } else if (dynamic_cast<SpecialBrick*>(brick)) {
                    score += 3;
                    floatingTexts.push_back({"+3", brick->GetX(), brick->GetY(), 1.0f});
                    powerupsystem->spawnAndExecuteRandomPowerUp();
                } else if (dynamic_cast<IndestructibleBrick*>(brick)) {
                    score += 0;
                } else if (dynamic_cast<DurableBrick*>(brick)) {
                    score += 4;
                    floatingTexts.push_back({"+4", brick->GetX(), brick->GetY(), 1.0f});
                } else if (dynamic_cast<StandardBrick*>(brick)) {
                    score += 1;
                    floatingTexts.push_back({"+1", brick->GetX(), brick->GetY(), 1.0f});
                }

                // Add combo bonus
                if (comboCount *2 != 0 && comboCount != 1){
                    score += comboCount * 2; // Bonus increases with each combo
                    int c = comboCount*2;
                    floatingTexts.push_back({"+" + std::to_string(c) + " Combo", 260, 220, 1.0f});
                }
            }
            ball.ceilingBounce();
            break; // Only one collision per frame
        }
    }

    for (auto it = floatingTexts.begin(); it != floatingTexts.end();) {
        DrawText(it->text.c_str(), it->x, it->y, 20, RED);
        it->timer -= GetFrameTime();
        if (it->timer <= 0.0f) {
            it = floatingTexts.erase(it); // remove expired text
        } else {
            ++it;
        }
    }

    // Level clear bonus
    bool allBricksDestroyed = true;
    for (auto& brick : bricks) {
        if (!brick->isDestroyed() && !dynamic_cast<IndestructibleBrick*>(brick)) {
            allBricksDestroyed = false;
            break;
        }
    }

    if (allBricksDestroyed) {
        if (levelTimer < 30.0f) { // Beat level in under 30 seconds
            score += 50; // Big bonus!
        } else if (levelTimer < 60.0f) {
            score += 20; // Smaller bonus
        }
        // Reset the bricks for the next level
        initBricks();
        ball.completereset(3, 2);
        level++;
    }
}

void BrickManager::spawnPowerup(float x, float y) {
    powerupsystem->spawnPowerUp(x, y);
}

void BrickManager::drawBricks() {
    for (auto& brick : bricks) {
        brick->draw();
    }
}

