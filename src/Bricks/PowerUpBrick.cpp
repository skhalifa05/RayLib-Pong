//
// Created by Seif Khalifa on 27/04/2025.
//

#include "PowerUpBrick.h"

PowerUpBrick::PowerUpBrick(float x, float y, float width, float height)
        : Brick(x, y, width, height) {}

bool PowerUpBrick::onCollision() {
    destroyed = true;
    return true;
}

void PowerUpBrick::draw() {
    if (!destroyed)
        DrawRectangle(x, y, width, height, SKYBLUE);
}