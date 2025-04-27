//
// Created by Seif Khalifa on 08/02/2025.
//


#include "GameManager.h"
#include "raylib.h"
#include <fstream>
#include <iostream>
#include <ostream>

// Initialize static member
GameManager* GameManager::gameManager = nullptr;

// Private constructor
GameManager::GameManager():
    screenWidth(800), screenHeight(450),
    paddleWidth(70), paddleHeight(10),
    ballRadius(10), xSpeed(3),
    ySpeed(2), radius(10),
    ball(xSpeed, ySpeed, radius, screenHeight, screenWidth),
    ballAttached(true),
    paddle((screenWidth / 2) - (paddleWidth / 2), paddleY, paddleSpeed, paddleWidth, paddleHeight),
    livesManager(livesCount),
    powerUpManager(&paddle, &ball, &livesManager),
    brickManager(&powerUpManager, &ball){}

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
    brickManager.initBricks();
}

//collision check + score tracker
void GameManager::collider() {
    auto [paddleX, paddleY] = paddle.getLocation();
    auto [ballX, ballY] = ball.getLocation();
    bool paddleCollision = (ballX + ballRadius >= paddleX) &&  // Ball's right edge past paddle's left edge
             (ballX - ballRadius <= paddleX + paddle.getWidth()) &&  // Ball's left edge before paddle's right edge
             (ballY + ballRadius >= paddleY) &&  // Ball's bottom edge past paddle's top edge
             (ballY - ballRadius <= paddleY + paddleHeight);  // Ball's top edge before paddle's bottom edge

    if (paddleCollision) {
        ball.paddleBounce(speedMultiplier, maxSpeed);
        color = 1 - color;
        // --- Random power-up spawn with 10% probability ---
        int chance = rand() % 100;  // Generates a number between 0-99
//        if (chance < 30) {  // 30% chance
//            spawnRandomPowerUp();
//        }
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
        if (livesManager.dead()) return;
        livesManager.loseLife();
        ball.reset();
    }
}
void GameManager::powerUpCollision() {
    for (size_t i = 0; i < powerUpManager.getActivePowerUps().size(); i++) {
        auto [px, py] = paddle.getLocation();
        auto [puX, puY] = powerUpManager.getActivePowerUps()[i]->getLocation();

        if (px <= puX && puX <= px + paddle.getWidth() &&
            py <= puY && puY <= py + paddleHeight) {
            powerUpManager.executePowerUp(i);
            break;
            }
    }
}

//update
void GameManager::updateFrame() {
    if (ballAttached) {
        auto [paddleX, paddleY] = paddle.getLocation();
        ball.setLocation(paddleX + paddle.getWidth() / 2, paddleY - ballRadius);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_SPACE)) {
            ballAttached = false;
            ball.setSpeed(ball.getSpeedX(), -abs(ball.getSpeedY()));
        }
        paddle.update();
        return;
    }


    ball.update();
    paddle.update();
    if (livesManager.dead()) {
        int highScore = loadHighScore();
        if (score > highScore) {
            saveHighScore(score);
        }
        this->score = 0;
        powerUpManager.reset();
        ball.completereset(xSpeed, ySpeed);
        brickManager.initBricks();
    }
    livesManager.update();
    brickManager.updateBricks(ball, score, ballRadius, level);
    collider();
    powerUpCollision();
}

void GameManager::spawnRandomPowerUp() {
//    powerUpManager.spawnPowerUp();
    return;
}

//timer
void GameManager::drawTimer() {
    if (paddle.isPoweredUp()) {
        DrawText(std::to_string(paddle.getRemainingPowerUpTime()).c_str(), (screenWidth/2) - 20, screenHeight - 30, 30, RED);
    }
}

//draw
void GameManager::drawGame() {
    ClearBackground(color ? RAYWHITE : BLACK);
    DrawText(title.c_str(), 260, 200, 20, LIGHTGRAY);
    if (livesManager.dead()) {DrawText(reset.c_str(), 180, 230, 20, RED);}
    if (!livesManager.dead()) ball.draw();
    paddle.draw();
    livesManager.draw();
    powerUpManager.drawPowerUps();
    brickManager.drawBricks();
    drawTimer();
    DrawText(std::to_string(score).c_str(), 15, 20, 30, GRAY);
    std::string levelText = "Level: " + std::to_string(level);
    DrawText(levelText.c_str(), 360, 10, 30, GRAY);
    std::string highScoreText = "High Score: " + std::to_string(loadHighScore());
    DrawText(highScoreText.c_str(), 15, 400, 30, GRAY);
}

int GameManager::loadHighScore() {
    std::ifstream file("highscore.dat");
    int highScore = 0;
    if (file.is_open()) {
        file >> highScore;
        file.close();
    }
    return highScore;
}

void GameManager::saveHighScore(float score) {
    std::ofstream file("highscore.dat");
    if (file.is_open()) {
        file << score;
        file.close();
    }
}