//
// Created by Seif Khalifa on 27/04/2025.
//

#include "SpecialBrick.h"

SpecialBrick::SpecialBrick(float x, float y, float width, float height)
        : Brick(x, y, width, height) {}

bool SpecialBrick::onCollision() {
    destroyed = true;
    return true;
}

void SpecialBrick::draw() {
    if (!destroyed)
        DrawRectangle(x, y, width, height, PURPLE);
}
