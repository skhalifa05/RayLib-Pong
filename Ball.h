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
        Ball(float xSpeed, float ySpeed, float radius);
        void update();
        void draw();
        pair<float, float> getLocation();
        void paddleBounce(float speedMultiplier, float maxSpeed);
        void sideWallBounce();
        void ceilingBounce();
        void reset();

    private:
        float x,y, xSpeed, ySpeed, radius;
        bool color = 0;
};



#endif //BALL_H
