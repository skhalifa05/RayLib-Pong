//
// Created by Seif Khalifa on 27/04/2025.
//

#include "StandardBrick.h"

StandardBrick::StandardBrick(float x, float y, float width, float height)
        : Brick(x, y, width, height) {}

void StandardBrick::draw() {
    if (!destroyed)
        DrawRectangle(x, y, width, height, GREEN);
}
