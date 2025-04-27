//
// Created by Seif Khalifa on 06/02/2025.
//

#ifndef PADDLE_H
#define PADDLE_H
#include <chrono>
#include <ctime>
#include <thread>
#include <utility>

using namespace std;

class Paddle {
    public:
        Paddle(float center, float yCoordinates, float paddleSpeed,  float width, float height);
        void update();
        void draw();
        pair<float, float> getLocation();
        void increaseSize();
        void decreaseSize();
        float getWidth();
        bool isPoweredUp();
        int getRemainingPowerUpTime() const;

    private:
        float x, y, paddleSpeed, width, height;
        std::atomic<bool> powerUp{false}; // Ensures thread safety
        std::atomic<int> timeRemaining{0};
        std::chrono::steady_clock::time_point startTime;
        std::thread powerUpThread;
        std::atomic<bool> running{false}; // Track if the timer is running

};



#endif //PADDLE_H
