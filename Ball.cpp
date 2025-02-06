//
// Created by Seif Khalifa on 06/02/2025.
//

#include "Ball.h"
#include <raylib.h>

#include "Paddle.h"

Ball::Ball(float x, float y, float xSpeed, float ySpeed, float radius)
    : x(x), y(y), xSpeed(xSpeed), ySpeed(ySpeed), radius(radius) {}


void Ball::update() {
    x += xSpeed;
    y += ySpeed;
}

void Ball::draw(Paddle paddle) {
    int width = GetScreenWidth();
    int height = GetScreenHeight();
    float paddleWidth = 70.0f;
    float paddleHeight = 10.0f;
    auto [paddleX, paddleY] = paddle.getLocation();

    bool collision = (x + radius >= paddleX) &&  // Ball's right edge past paddle's left edge
                 (x - radius <= paddleX + paddleWidth) &&  // Ball's left edge before paddle's right edge
                 (y + radius >= paddleY) &&  // Ball's bottom edge past paddle's top edge
                 (y - radius <= paddleY + paddleHeight);  // Ball's top edge before paddle's bottom edge

    // Check horizontal boundaries
    if (x >= width || x <= 0) {
        xSpeed *= -1;       // Reverse direction
    }

    // Check vertical boundaries
    if (y <= 0) {
        ySpeed *= -1;
    }

    if (y >= height) {
        lives--;
        if (lives <= 0) return;
        x = GetScreenWidth() / 2;
        y = GetScreenHeight()/3;
    }

    if (collision) {
        color = 1 - color;
        xSpeed *= -1;
        ySpeed *= -1;
        bounces++;
    }



    // Draw the ball with the current color
    DrawCircle(x, y, radius, color ? WHITE : BLACK);
}

string Ball::getCounter() {
    return std::to_string(bounces);
}

bool Ball::getColor() {
    return color;
}

int Ball::getLives() {
    return lives;
}
