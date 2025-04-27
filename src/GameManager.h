//
// Created by Seif Khalifa on 08/02/2025.
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H



#include "../include/raylib.h"
#include "Ball.h"
#include "LivesManager.h"
#include "Paddle.h"
#include "PowerUpsManager.h"
#include "BrickManager.h"

class GameManager {
    private:
        static GameManager* gameManager;
        //game env - screen
        const int screenWidth;
        const int screenHeight;
        const int livesCount = 3;
        bool color = 1;
        int score = 0;
        int level = 1;
        LivesManager livesManager;
        PowerUpManager powerUpManager;
        const string title = "Simple Pong - Seif Khalifa";
        const string reset = "Game Over! Press space bar to play again.";
        void drawTimer();

        //game env - paddle
        const int paddleWidth;
        const int paddleHeight;
        const float paddleY = 400;
        const float paddleSpeed = 8;
        Paddle paddle;

        //game env - ball
        const int ballRadius;
        const float xSpeed;
        const float ySpeed;
        const float radius;
        const int FPS = 60;
        const float speedMultiplier = 1.15f; // Increase speed by 5% each bounce
        const float maxSpeed = 10.0f; // Prevent excessive speed
        bool ballAttached = true;
        Ball ball;

        //game env - bricks
        BrickManager brickManager;

        //game env - data
        int loadHighScore();
        void saveHighScore(float score);

        GameManager();
        void collider();
        void spawnRandomPowerUp();
        void powerUpCollision();

    public:
        // Delete copy constructor and assignment operator
        GameManager(const GameManager&) = delete;
        GameManager& operator=(const GameManager&) = delete;
        static GameManager* getInstance();
        void initGame();
        void updateFrame();
        void drawGame();

};

#endif //GAMEMANAGER_H
