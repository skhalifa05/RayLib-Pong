//
// Created by Seif Khalifa on 08/02/2025.
//
#include "ExtraLife.h"

ExtraLife::ExtraLife(float x, float y, LivesManager* livesManager)
    : x(x), y(y), livesManager(livesManager) {}

std::pair<float, float> ExtraLife::getLocation() {
    return {x, y};
}

void ExtraLife::execute() {
    livesManager->gainLife(1);
}