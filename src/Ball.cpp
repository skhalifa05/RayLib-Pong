//
// Created by Seif Khalifa on 06/02/2025.
//

#include "Ball.h"
#include <raylib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Paddle.h"
using namespace std;

Ball::Ball(float xSpeed, float ySpeed, float radius, int screenHeight, int screenWidth) {
    srand(std::time(0));  // Seed random number generator
    x = rand() % screenWidth;  // Any horizontal position
    y = rand() % ((screenHeight/2) + 1);  // Generates a number from 0 to x // Ensure it never exceeds half of screen height
    this->xSpeed = xSpeed;
    this->ySpeed = ySpeed;
    this->radius = radius;
}

void Ball::update() {
    x += xSpeed;
    y += ySpeed;
}

void Ball::draw() {
    // Draw the ball with the current color
    DrawCircle(x, y, radius, color ? WHITE : BLACK);
}

pair<float, float> Ball::getLocation() {
    return {x, y};
}

void Ball::reset() {
    srand(std::time(0));  // Seed random number generator

    x = rand() % GetScreenWidth();  // Any horizontal position
//    y = rand() % (GetScreenHeight() / 2);  // Only in the upper half
    int top = 200;
    int bottom = GetScreenHeight() - 100;
    y = top + (rand() % (bottom - top + 1));
}

void Ball::sideWallBounce() {
    xSpeed *= -1;       // Reverse direction
}

void Ball::ceilingBounce() {
    ySpeed *= -1;       // Reverse direction
}

void Ball::paddleBounce(float speedMultiplier, float maxSpeed) {
    color = 1 - color;
    xSpeed *= 1;
    ySpeed *= -1;

    // Cap speed
//    xSpeed = (std::abs(xSpeed) > maxSpeed) ? (maxSpeed * (xSpeed > 0 ? 1 : -1)) : xSpeed;
//    ySpeed = (std::abs(ySpeed) > maxSpeed) ? (maxSpeed * (ySpeed > 0 ? 1 : -1)) : ySpeed;
}

void Ball::completereset(float xSpeed, float ySpeed) {
    this->xSpeed = xSpeed;
    this->ySpeed = ySpeed;
    srand(std::time(0));  // Seed random number generator

    x = rand() % GetScreenWidth();  // Random horizontal position

    int top = 250;
    int bottom = GetScreenHeight() - 100;
    y = top + (rand() % (bottom - top + 1));
}

void Ball::setLocation(float newX, float newY) {
    this->x = newX;
    this->y = newY;
}

float Ball::getSpeedX() const {
    return xSpeed;
}

float Ball::getSpeedY() const {
    return ySpeed;
}

void Ball::setSpeed(float newXSpeed, float newYSpeed) {
    this->xSpeed = newXSpeed;
    this->ySpeed = newYSpeed;
}
