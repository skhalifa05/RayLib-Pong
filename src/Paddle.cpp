//
// Created by Seif Khalifa on 06/02/2025.
//

#include "Paddle.h"

#include <iostream>
#include <ostream>
#include <../include/raylib.h>

Paddle::Paddle(float center, float yCoordinates, float paddleSpeed, float width, float height) {
    x = center;
    y = yCoordinates;
    this->paddleSpeed = paddleSpeed;
    this->width = 70;
    this->height = 10;
}

void Paddle::update() {
    if (IsKeyDown(KEY_RIGHT)) x += paddleSpeed;
    if (IsKeyDown(KEY_LEFT)) x -= paddleSpeed;
    // Debug: Increase size when pressing SPACE
    if (IsKeyPressed(KEY_SPACE)) {
        increaseSize();
    }
    // Screen wrapping logic
    if (x > GetScreenWidth()) x = 0;  // If the paddle exits the right side, re-enter from the left
    if (x < 0) x = GetScreenWidth();  // If the paddle exits the left side, re-enter from the right
}

void Paddle::draw() {
    DrawRectangle(x, y, width, height, BLUE);
}

pair<float, float> Paddle::getLocation() {
    return {x, y};
}

void Paddle::increaseSize() {
    this->width += 20;
}

float Paddle::getWidth() {
    return this->width;
}