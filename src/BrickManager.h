//
// Created by Seif Khalifa on 27/04/2025.
//

#ifndef PONG_BRICKMANAGER_H
#define PONG_BRICKMANAGER_H
#include <vector>
#include "Bricks/Brick.h"
#include "Ball.h"
#include "PowerUpsManager.h"

class BrickManager {
private:
    std::vector<Brick*> bricks;
    PowerUpManager* powerupsystem;
    Ball* ball;
    void spawnPowerup(float x, float y);
    // Combo system
    float comboTimer = 0.0f;
    int comboCount = 0;
    const float COMBO_RESET_TIME = 5.0f; // seconds

    // Level clear timer
    float levelTimer = 0.0f;
public:
    BrickManager(PowerUpManager* powerupsystem, Ball* ball);
    ~BrickManager();

    void initBricks();
    void updateBricks(Ball& ball, int& score, float ballRadius, int& level);
    void drawBricks();

    // Getter functions
    float getComboTimer() const { return comboTimer; }
    int getComboCount() const { return comboCount; }
    float getLevelTimer() const { return levelTimer; }
};


#endif //PONG_BRICKMANAGER_H
