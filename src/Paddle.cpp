//
// Created by Seif Khalifa on 06/02/2025.
//

#include "Paddle.h"

#include <iostream>
#include <ostream>
#include <thread>
#include <../include/raylib.h>

Paddle::Paddle(float center, float yCoordinates, float paddleSpeed, float width, float height) {
    x = center;
    y = yCoordinates;
    this->paddleSpeed = paddleSpeed;
    this->width = width;
    this->height = height;
}

void Paddle::update() {
    if (IsKeyDown(KEY_RIGHT)) x += paddleSpeed;
    if (IsKeyDown(KEY_LEFT)) x -= paddleSpeed;
    // Screen wrapping logic
    if (x < 0) x = 0;
    if (x + width > GetScreenWidth()) x = GetScreenWidth() - width;
}

void Paddle::draw() {
    DrawRectangle(x, y, width, height, BLUE);
}

pair<float, float> Paddle::getLocation() {
    return {x, y};
}

void Paddle::increaseSize() {
    if (!powerUp) {
        this->width += 40;
        powerUp = true;
        running = true;
        startTime = std::chrono::steady_clock::now();

        // Start a single background timer if not running
        powerUpThread = std::thread([this]() {
            while (running) {
                std::this_thread::sleep_for(std::chrono::seconds(1));

                if (--timeRemaining <= 0) {
                    width -= 40;
                    powerUp = false;
                    running = false;
                }
            }
        });
        powerUpThread.detach(); // Allow independent execution
    }
    // Extend power-up duration
    timeRemaining += 10;
}

void Paddle::decreaseSize() {
    if (!powerUp) {
        this->width -= 40;
        powerUp = true;
        running = true;
        startTime = std::chrono::steady_clock::now();

        // Start a single background timer if not running
        powerUpThread = std::thread([this]() {
            while (running) {
                std::this_thread::sleep_for(std::chrono::seconds(1));

                if (--timeRemaining <= 0) {
                    width += 40;
                    powerUp = false;
                    running = false;
                }
            }
        });
        powerUpThread.detach(); // Allow independent execution
    }
    // Extend power-up duration
    timeRemaining += 10;
}

float Paddle::getWidth() {
    return this->width;
}

bool Paddle::isPoweredUp() {
    return this->powerUp;
}

int Paddle::getRemainingPowerUpTime() const {
    return (powerUp) ? timeRemaining.load() : 0;
}