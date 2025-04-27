//
// Created by Seif Khalifa on 27/04/2025.
//

#include "IndestructibleBrick.h"

IndestructibleBrick::IndestructibleBrick(float x, float y, float width, float height)
        : Brick(x, y, width, height) {}

bool IndestructibleBrick::onCollision() {
    // Cannot be destroyed
    return false;
}

void IndestructibleBrick::draw() {
    DrawRectangleLines(x, y, width, height, DARKGRAY);
}
