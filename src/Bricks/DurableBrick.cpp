//
// Created by Seif Khalifa on 27/04/2025.
//

#include "DurableBrick.h"

DurableBrick::DurableBrick(float x, float y, float width, float height)
        : Brick(x, y, width, height), health(3) {}

bool DurableBrick::onCollision() {
    health--;
    if (health <= 0) {
        destroyed = true;
        return true;
    }
    return false;
}

void DurableBrick::draw() {
    if (!destroyed) {
        Color color = (health == 3) ? RED : (health == 2) ? ORANGE : YELLOW;
        DrawRectangle(x, y, width, height, color);
    }
}
