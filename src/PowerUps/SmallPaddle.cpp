//
// Created by Seif Khalifa on 27/04/2025.
//

#include "SmallPaddle.h"
SmallPaddle::SmallPaddle(float x, float y, Paddle *paddle)  : x(x), y(y), paddle(paddle) {}

std::pair<float, float> SmallPaddle::getLocation() {
    return {x, y};
}

void SmallPaddle::setLocation(float newX, float newY) {
    x = newX;
    y = newY;
}

void SmallPaddle::execute() {
    paddle->decreaseSize();  // Expands the paddle
}