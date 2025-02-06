//
// Created by Seif Khalifa on 06/02/2025.
//

#include "Paddle.h"

#include <raylib.h>

Paddle::Paddle(float center) {
    x = center;
    y = 400;
}

void Paddle::update() {
    if (IsKeyDown(KEY_RIGHT)) x += 5.0f;
    if (IsKeyDown(KEY_LEFT)) x -= 5.0f;

    // Screen wrapping logic
    if (x > GetScreenWidth()) x = 0;  // If the paddle exits the right side, re-enter from the left
    if (x < 0) x = GetScreenWidth();  // If the paddle exits the left side, re-enter from the right
}

void Paddle::draw() {
    DrawRectangle(x, y, 70, 10, RED);
}

pair<float, float> Paddle::getLocation() {
    return {x, y};
}