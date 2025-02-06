//
// Created by Seif Khalifa on 06/02/2025.
//

#ifndef BALL_H
#define BALL_H
#include <string>

#include "Paddle.h"

using namespace std;
class Ball {
    public:
        Ball(float x, float y, float xSpeed, float ySpeed, float radius);
        void update();
        void draw(Paddle paddle);
        string getCounter();
        bool getColor();
        int getLives();

    private:
        float x,y;
        float xSpeed, ySpeed;
        float radius;
        int bounces = 0;
        bool color = 0;
        int lives = 3;
};



#endif //BALL_H
