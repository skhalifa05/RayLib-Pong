//
// Created by Seif Khalifa on 08/02/2025.
//

#include "GameManager.h"

// Initialize static member
GameManager* GameManager::gameManager = nullptr;

// Private constructor
GameManager::GameManager():
    screenWidth(800), screenHeight(450),
    paddleWidth(70), paddleHeight(10),
    ballRadius(10), xSpeed(3),
    ySpeed(2), radius(10),
    ball(xSpeed, ySpeed, radius),
    paddle((screenWidth / 2) - (paddleWidth / 2), paddleY, paddleSpeed, paddleWidth, paddleHeight){}

// Singleton instance method
GameManager* GameManager::getInstance() {
    if (gameManager == nullptr) {
        gameManager = new GameManager();
    }
    return gameManager;
}

//init game
void GameManager::initGame() {
    InitWindow(screenWidth, screenHeight, title.c_str());
    SetTargetFPS(FPS);               // Set our game to run at 60 frames-per-second
}

//collision check + score tracker
void GameManager::collider() {
    auto [paddleX, paddleY] = paddle.getLocation();
    auto [ballX, ballY] = ball.getLocation();
    bool paddleCollision = (ballX + ballRadius >= paddleX) &&  // Ball's right edge past paddle's left edge
             (ballX - ballRadius <= paddleX + paddleWidth) &&  // Ball's left edge before paddle's right edge
             (ballY + ballRadius >= paddleY) &&  // Ball's bottom edge past paddle's top edge
             (ballY - ballRadius <= paddleY + paddleHeight);  // Ball's top edge before paddle's bottom edge

    if (paddleCollision) {
        score++;
        ball.paddleBounce(speedMultiplier, maxSpeed);
        color = 1 - color;
        return;
    }

    // Check horizontal boundaries
    if (ballX >= screenWidth || ballX <= 0) {
        ball.sideWallBounce();
    }

    // Check vertical boundaries
    if (ballY <= 0) {
        ball.ceilingBounce();
    }
    if (ballY >= screenHeight) {
        lives--;
        if (lives <= 0) return;
        ball.reset();
    }
}

//update
void GameManager::updateFrame() {
    ball.update();
    paddle.update();
    collider();
}

//draw
void GameManager::drawGame() {
    ClearBackground(color ? RAYWHITE : BLACK);
    DrawText(title.c_str(), 220, 200, 20, LIGHTGRAY);
    ball.draw();
    paddle.draw();
    //Draw Lives
    for (int i = 1; i<= lives; i++) {
        DrawCircle(800 - (20*i), 20,5,RED);
    }
    DrawText(std::to_string(score).c_str(), 15, 20, 30, GRAY);
}
