//
// Created by Seif Khalifa on 08/02/2025.
//
#include "LargerPaddle.h"

LargerPaddle::LargerPaddle(float x, float y, Paddle* paddle) : x(x), y(y), paddle(paddle) {}

std::pair<float, float> LargerPaddle::getLocation() {
    return {x, y};
}

void LargerPaddle::execute() {
    paddle->increaseSize();  // Expands the paddle
}
