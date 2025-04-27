//
// Created by Seif Khalifa on 27/04/2025.
//

#include "Brick.h"

Brick::Brick(float x, float y, float width, float height)
        : x(x), y(y), width(width), height(height) {}

void Brick::update() {}

void Brick::draw() {
    if (!destroyed)
        DrawRectangle(x, y, width, height, GRAY);
}

bool Brick::onCollision() {
    destroyed = true;
    return true;
}

float Brick::GetX(){
    return x;
}

float Brick::GetY(){
    return y;
}

bool Brick::isDestroyed() const {
    return destroyed;
}

Rectangle Brick::getRect() const {
    return { x, y, width, height };
}